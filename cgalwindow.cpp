#include "cgalwindow.h"
#include "ui_cgalwindow.h"
#include <CGAL/Qt/debug.h>
#include <QtDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>
#include <QHeaderView>
#include <QMenu>
#include <QMenuBar>
#include <QChar>
#include <QAction>
#include <QShortcut>
#include <QKeySequence>
#include <QLibrary>
#include <QPluginLoader>
#include <QMessageBox>
#include <QScrollBar>
#include <QColor>
#include <QColorDialog>
#include <QClipboard>
#include <QCloseEvent>
#include <QInputDialog>
#include <QTreeView>
#include <QSortFilterProxyModel>
#include <QMap>
#include <QStandardItemModel>
#include <QStandardItem>
#include <stdexcept>
//#include "Scene_polyhedron_item.h"

#ifdef QT_SCRIPT_LIB
#  include <QScriptValue>
#  ifdef QT_SCRIPTTOOLS_LIB
#    include <QScriptEngineDebugger>
#  endif
#endif


#ifdef QT_SCRIPT_LIB
#  include <QScriptEngine>
#  include <QScriptValue>

QScriptValue
myScene_itemToScriptValue(QScriptEngine *engine,
                          Scene_item* const &in)
{
  return engine->newQObject(in);
}

void myScene_itemFromScriptValue(const QScriptValue &object,
                                 Scene_item* &out)
{
  out = qobject_cast<Scene_item*>(object.toQObject());
}
#endif // QT_SCRIPT_LIB

#ifdef QT_SCRIPT_LIB
#  ifdef QT_SCRIPTTOOLS_LIB

const QScriptEngineDebugger::DebuggerWidget debug_widgets[9] = {
  QScriptEngineDebugger::ConsoleWidget,
  QScriptEngineDebugger::StackWidget,
  QScriptEngineDebugger::ScriptsWidget,
  QScriptEngineDebugger::LocalsWidget,
  QScriptEngineDebugger::CodeWidget,
  QScriptEngineDebugger::CodeFinderWidget,
  QScriptEngineDebugger::BreakpointsWidget,
  QScriptEngineDebugger::DebugOutputWidget,
  QScriptEngineDebugger::ErrorLogWidget
};
const QString debug_widgets_names[9] = {
  "Script console",
  "Stack",
  "Scripts",
  "Locals",
  "Code",
  "CodeFinder",
  "Breakpoints",
  "DebugOutput",
  "ErrorLog"
};

#  endif
#endif

QScriptValue myPrintFunction(QScriptContext *context, QScriptEngine *engine)
{
  CGALWindow* mw = qobject_cast<CGALWindow*>(engine->parent());
  QString result;
  for (int i = 0; i < context->argumentCount(); ++i) {
    if (i > 0)
      result.append(" ");
    result.append(context->argument(i).toString());
  }

  if(mw) mw->message(QString("QtScript: ") + result, "");

  return engine->undefinedValue();
}

CGALWindow::CGALWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGALWindow),
    maxNumRecentFiles(10)
{
    ui->setupUi(this);

    sceneView = ui->sceneView;
    viewer = ui->viewer;

    // do not save the state of the viewer (anoying)
    viewer->setStateFileName(QString::null);

     // setup scene
    scene = new Scene(this);
    viewer->setScene(scene);

#ifdef QT_SCRIPT_LIB
  //std::cerr << "Enable scripts.\n";
  script_engine = new QScriptEngine(this);
  qScriptRegisterMetaType<Scene_item*>(script_engine,
                                       myScene_itemToScriptValue,
                                       myScene_itemFromScriptValue);
#  ifdef QT_SCRIPTTOOLS_LIB
  QScriptEngineDebugger* debugger = new QScriptEngineDebugger(this);
  debugger->setObjectName("qt script debugger");
  QAction* debuggerMenuAction =
    menuBar()->addMenu(debugger->createStandardMenu());
  debuggerMenuAction->setText(tr("Qt Script &debug"));
  for(unsigned int i = 0; i < 9; ++i)
  {
    QDockWidget* dock = new QDockWidget(debug_widgets_names[i], this);
    dock->setObjectName(debug_widgets_names[i]);
    dock->setWidget(debugger->widget(debug_widgets[i]));
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);
    dock->hide();
  }
  debugger->setAutoShowStandardWindow(false);
  debugger->attachTo(script_engine);
#  endif // QT_SCRIPTTOOLS_LIB
  QScriptValue fun = script_engine->newFunction(myPrintFunction);
  script_engine->globalObject().setProperty("print", fun);

  //  evaluate_script("print('hello', 'world', 'from QtScript!')");
  QScriptValue mainWindowObjectValue = script_engine->newQObject(this);
  script_engine->globalObject().setProperty("main_window", mainWindowObjectValue);

  QScriptValue sceneObjectValue = script_engine->newQObject(scene);
  mainWindowObjectValue.setProperty("scene", sceneObjectValue);
  script_engine->globalObject().setProperty("scene", sceneObjectValue);

  QScriptValue viewerObjectValue = script_engine->newQObject(viewer);
  mainWindowObjectValue.setProperty("viewer", viewerObjectValue);
  script_engine->globalObject().setProperty("viewer", viewerObjectValue);

  QScriptValue cameraObjectValue = script_engine->newQObject(viewer->camera());
  viewerObjectValue.setProperty("camera", cameraObjectValue);
  script_engine->globalObject().setProperty("camera", cameraObjectValue);

  evaluate_script("var plugins = new Array();");
#  ifdef QT_SCRIPTTOOLS_LIB
  QScriptValue debuggerObjectValue = script_engine->newQObject(debugger);
  script_engine->globalObject().setProperty("debugger", debuggerObjectValue);
#  endif
#endif

  // Load plugins, and re-enable actions that need it.
  loadPlugins();
}

CGALWindow::~CGALWindow()
{
    delete ui;
}



Scene_item* CGALWindow::load_item(QFileInfo fileinfo, Polyhedron_demo_io_plugin_interface* loader) {
  Scene_item* item = NULL;
  if(!fileinfo.isFile() || !fileinfo.isReadable()) {
    throw std::invalid_argument(QString("File %1 is not a readable file.")
                                .arg(fileinfo.absoluteFilePath()).toStdString());
  }

  QApplication::setOverrideCursor(Qt::WaitCursor);
  item = loader->load(fileinfo);
  QApplication::restoreOverrideCursor();
  if(!item) {
    throw std::logic_error(QString("Could not load item from file %1 using plugin %2")
                           .arg(fileinfo.absoluteFilePath()).arg(loader->name()).toStdString());
  }

  item->setProperty("source filename", fileinfo.absoluteFilePath());
  item->setProperty("loader_name", loader->name());
  return item;
}
Polyhedron_demo_io_plugin_interface* CGALWindow::find_loader(const QString& loader_name) const {
  Q_FOREACH(Polyhedron_demo_io_plugin_interface* io_plugin,
            io_plugins) {
    if(io_plugin->name() == loader_name) {
      return io_plugin;
    }
  }
  throw std::invalid_argument(QString("No loader found with the name %1 available")
                              .arg(loader_name).toStdString()) ;
}

void CGALWindow::open(QString filename)
{
  QFileInfo fileinfo(filename);

#ifdef QT_SCRIPT_LIB
  // Handles the loading of script file from the command line arguments,
  // and the special command line arguments that start with "javascript:"
  // or "qtscript:"
  QString program;
  if(filename.startsWith("javascript:")) {
    program=filename.right(filename.size() - 11);
  }
  if(filename.startsWith("qtscript:")) {
    program=filename.right(filename.size() - 9);
  }
  if(filename.endsWith(".js")) {
    load_script(fileinfo);
    return;
  }
  if(!program.isEmpty())
  {
    {
      QTextStream(stderr) << "Execution of script \""
                          << filename << "\"\n";
                          // << filename << "\", with following content:\n"
                          // << program;
    }
        evaluate_script(program, filename);
    return;
  }
#endif

  if ( !fileinfo.exists() ){
    QMessageBox::warning(this,
                         tr("Cannot open file"),
                         tr("File %1 does not exist.")
                         .arg(filename));
    return;
  }


  QStringList selected_items;
  QStringList all_items;

  QMap<QString,QString>::iterator dfs_it =
    default_plugin_selection.find( fileinfo.completeSuffix() );

  if ( dfs_it==default_plugin_selection.end() )
  {
    // collect all io_plugins and offer them to load if the file extension match one name filter
    // also collect all available plugin in case of a no extension match
    Q_FOREACH(Polyhedron_demo_io_plugin_interface* io_plugin, io_plugins) {
      if ( !io_plugin->canLoad() ) continue;
      all_items << io_plugin->name();
      if ( file_matches_filter(io_plugin->nameFilters(), filename) )
        selected_items << io_plugin->name();
    }
  }
  else
    selected_items << *dfs_it;

  bool ok;
  std::pair<QString, bool> load_pair;

  switch( selected_items.size() )
  {
    case 1:
      load_pair = std::make_pair(selected_items.first(), false);
      ok=true;
      break;
    case 0:
      //load_pair = File_loader_dialog::getItem(fileinfo.fileName(), all_items, &ok);
      break;
    default:
      //load_pair = File_loader_dialog::getItem(fileinfo.fileName(), selected_items, &ok);
		break;
  }

  if(!ok || load_pair.first.isEmpty()) { return; }

  if (load_pair.second)
     default_plugin_selection[fileinfo.completeSuffix()]=load_pair.first;


  QSettings settings;
  settings.setValue("OFF open directory",
                    fileinfo.absoluteDir().absolutePath());

  Scene_item* scene_item = load_item(fileinfo, find_loader(load_pair.first));
  if(scene_item != 0) {
    this->addToRecentFiles(fileinfo.absoluteFilePath());
  }
  selectSceneItem(scene->addItem(scene_item));
}


bool CGALWindow::load_script(QString filename)
{
  QFileInfo fileinfo(filename);
  return load_script(fileinfo);
}

bool CGALWindow::load_script(QFileInfo info)
{
#if defined(QT_SCRIPT_LIB)
  QString program;
  QString filename = info.absoluteFilePath();
  QFile script_file(filename);
  script_file.open(QIODevice::ReadOnly);
  program = script_file.readAll();
  if(!program.isEmpty())
  {
    QTextStream(stderr)
      << "Execution of script \""
      << filename << "\"\n";
    evaluate_script(program, filename);
    return true;
  }
#endif
  return false;
}
#ifdef QT_SCRIPT_LIB
void CGALWindow::evaluate_script(QString script,
                                 const QString& filename,
                                 const bool quiet) {
  QScriptValue value = script_engine->evaluate(script, filename);
  if(script_engine->hasUncaughtException()) {
    QTextStream err(stderr);
    err << "Qt Script exception:\n"
        << script_engine->uncaughtException().toString()
        << "\nBacktrace:\n";
    Q_FOREACH(QString line, script_engine->uncaughtExceptionBacktrace()) {
      err << "  " << line << "\n";
    }
  }
  else if(!quiet && !value.isNull() && !value.isUndefined()) {
    QTextStream(stderr) << "Qt Script evaluated to \""
                        << value.toString() << "\"\n";
  }
}

void CGALWindow::evaluate_script_quiet(QString script,
                                       const QString& filename)
{
  evaluate_script(script, filename, true);
}
#endif

bool CGALWindow::file_matches_filter(const QString& filters,
                                     const QString& filename )
{
  QFileInfo fileinfo(filename);
  QString filename_striped=fileinfo.fileName();

  //match all filters between ()
  QRegExp all_filters_rx("\\((.*)\\)");

  QStringList split_filters = filters.split(";;");
  Q_FOREACH(const QString& filter, split_filters) {
    //extract filters
    if ( all_filters_rx.indexIn(filter)!=-1 ){
      Q_FOREACH(const QString& pattern,all_filters_rx.cap(1).split(' ')){
        QRegExp rx(pattern);
        rx.setPatternSyntax(QRegExp::Wildcard);
        if ( rx.exactMatch(filename_striped) ){
          return true;
        }
      }
    }
  }
  return false;
}
void CGALWindow::setMaxNumberOfRecentFiles(const unsigned int i)
{
  maxNumRecentFiles = i;
  recentFileActs.resize(maxNumRecentFiles);
}

unsigned int CGALWindow::maxNumberOfRecentFiles() const
{
  return maxNumRecentFiles;
}

void CGALWindow::addToRecentFiles(QString fileName)
{
  QSettings settings;
  QStringList files = settings.value("recentFileList").toStringList();
  files.removeAll(fileName);
  files.prepend(fileName);
  while (files.size() > (int)maxNumberOfRecentFiles())
    files.removeLast();

  settings.setValue("recentFileList", files);

  updateRecentFileActions();
}
void CGALWindow::selectSceneItem(int i)
{
  if(i < 0 || i >= scene->numberOfEntries()) {
    sceneView->selectionModel()->clearSelection();
    updateInfo();
    updateDisplayInfo();
  }
  else {
    QItemSelection s =
      proxyModel->mapSelectionFromSource(scene->createSelection(i));
    sceneView->selectionModel()->select(s,
                                        QItemSelectionModel::ClearAndSelect);
  }
}
void CGALWindow::updateRecentFileActions()
{
  QSettings settings;
  QStringList files = settings.value("recentFileList").toStringList();

  int numRecentFiles = qMin(files.size(), (int)this->maxNumberOfRecentFiles());

  for (int i = 0; i < numRecentFiles; ++i) {
    QString strippedName = QFileInfo(files[i]).fileName();
    QString text = tr("&%1 %2").arg(i).arg(strippedName);
    recentFileActs[i]->setText(text);
    recentFileActs[i]->setData(files[i]);
    recentFileActs[i]->setVisible(true);
  }
  for (unsigned int j = numRecentFiles; j < maxNumberOfRecentFiles(); ++j)
    recentFileActs[j]->setVisible(false);

  recentFilesSeparator->setVisible(numRecentFiles > 0);
}

void CGALWindow::updateInfo() {
  Scene_item* item = scene->item(getSelectedSceneItemIndex());
  if(item) {
    QString item_text = item->toolTip();
    QString item_filename = item->property("source filename").toString();
    if(!item_filename.isEmpty()) {
      item_text += QString("<br /><i>File: %1").arg(item_filename);
    }
    ui->infoLabel->setText(item_text);
  }
  else
    ui->infoLabel->clear();
}
void CGALWindow::updateDisplayInfo() {
  Scene_item* item = scene->item(getSelectedSceneItemIndex());
  if(item)
    ui->displayLabel->setPixmap(item->graphicalToolTip());
  else
    ui->displayLabel->clear();
}
int CGALWindow::getSelectedSceneItemIndex() const
{
  QModelIndexList selectedRows = sceneView->selectionModel()->selectedRows();
  if(selectedRows.size() != 1)
    return -1;
  else {
    QModelIndex i = proxyModel->mapToSource(selectedRows.first());
    return i.row();
  }
}



void CGALWindow::on_actionLoad_triggered()
{
	QStringList filters;
	// we need to special case our way out of this
	filters << "All Files (*)";

	QStringList extensions;

	typedef QMap<QString, Polyhedron_demo_io_plugin_interface*> FilterPluginMap;
	FilterPluginMap filterPluginMap;

	Q_FOREACH(Polyhedron_demo_io_plugin_interface* plugin, io_plugins) {
		QStringList split_filters = plugin->nameFilters().split(";;");
		Q_FOREACH(const QString& filter, split_filters) {
			FilterPluginMap::iterator it = filterPluginMap.find(filter);
			if (it != filterPluginMap.end()) {
				qDebug() << "Duplicate Filter: " << it.value();
				qDebug() << "This filter will not be available.";
			}
			else {
				filterPluginMap[filter] = plugin;
			}
			filters << filter;
		}
	}

	QSettings settings;
	QString directory = settings.value("OFF open directory",
		QDir::current().dirName()).toString();

	QFileDialog dialog(this);
	dialog.setDirectory(directory);
	dialog.setNameFilters(filters);
	dialog.setFileMode(QFileDialog::ExistingFiles);

	if (dialog.exec() != QDialog::Accepted) { return; }

	FilterPluginMap::iterator it =
		filterPluginMap.find(dialog.selectedNameFilter());

	Polyhedron_demo_io_plugin_interface* selectedPlugin = NULL;

	if (it != filterPluginMap.end()) {
		selectedPlugin = it.value();
	}

	Q_FOREACH(const QString& filename, dialog.selectedFiles()) {
		Scene_item* item = NULL;
		if (selectedPlugin) {
			QFileInfo info(filename);
			item = load_item(info, selectedPlugin);
			Scene::Item_id index = scene->addItem(item);
			selectSceneItem(index);
			this->addToRecentFiles(filename);
		}
		else {
			open(filename);
		}
	}
}
namespace {
	bool actionsByName(QAction* x, QAction* y) {
		return x->text() < y->text();
	}
}
void CGALWindow::loadPlugins()
{
	Q_FOREACH(QObject *obj, QPluginLoader::staticInstances())
	{
		initPlugin(obj);
		initIOPlugin(obj);
	}

	QList<QDir> plugins_directories;
	QString asdf = "C:\\Program Files\\CGAL-4.7\\build\\demo\\Polyhedron\\Debug";

	QString asd = qApp->applicationDirPath();
	plugins_directories << asdf; //qApp->applicationDirPath();
	QString env_path = qgetenv("POLYHEDRON_DEMO_PLUGINS_PATH");
	if (!env_path.isEmpty()) {
		Q_FOREACH(QString pluginsDir,
			env_path.split(":", QString::SkipEmptyParts)) {
			QDir dir(pluginsDir);
			if (dir.isReadable())
				plugins_directories << dir;
		}
	}
	Q_FOREACH(QDir pluginsDir, plugins_directories) {
		qDebug("# Looking for plugins in directory \"%s\"...",
			qPrintable(pluginsDir.absolutePath()));
		Q_FOREACH(QString fileName, pluginsDir.entryList(QDir::Files)) {
			if (fileName.contains("plugin") && QLibrary::isLibrary(fileName)) {
				//set plugin name
				QString name = fileName;
				name.remove(QRegExp("^lib"));
				name.remove(QRegExp("\\..*"));
				//do not load it if it is in the blacklist
				if (plugin_blacklist.contains(name)){
					qDebug("### Ignoring plugin \"%s\".", qPrintable(fileName));
					continue;
				}
				QDebug qdebug = qDebug();
				qdebug << "### Loading \"" << fileName.toUtf8().data() << "\"... ";
				QPluginLoader loader;
				qDebug("# Looking for plugins in directory \"%s\"...",
					qPrintable(pluginsDir.absoluteFilePath(fileName)));
			
				loader.setFileName(pluginsDir.absoluteFilePath(fileName));
				QObject *obj = loader.instance();
				if (obj) {
					obj->setObjectName(name);
					bool init1 = initPlugin(obj);
					bool init2 = initIOPlugin(obj);
					if (!init1 && !init2)
						qdebug << "not for this program";
					else
						qdebug << "success";
				}
				else {
					qDebug("error:", qPrintable(loader.errorString()));
					qdebug << "error: " << qPrintable(loader.errorString());
				}
			}
		}
	}

	// sort the operations menu by name
	QList<QAction*> actions = ui->menuModel_Geometry->actions();
	qSort(actions.begin(), actions.end(), actionsByName);
	ui->menuModel_Geometry->clear();
	ui->menuModel_Geometry->addActions(actions);
}


bool CGALWindow::hasPlugin(const QString& pluginName) const
{
	Q_FOREACH(const PluginNamePair& p, plugins) {
		if (p.second == pluginName) return true;
	}
	return false;
}

bool CGALWindow::initPlugin(QObject* obj)
{
	QObjectList childs = this->children();
	Polyhedron_demo_plugin_interface* plugin =
		qobject_cast<Polyhedron_demo_plugin_interface*>(obj);
	if (plugin) {
		// Call plugin's init() method
		obj->setParent(this);
		plugin->init(this, this->scene, this);
		plugins << qMakePair(plugin, obj->objectName());
#ifdef QT_SCRIPT_LIB
		QScriptValue objectValue =
			script_engine->newQObject(obj);
		script_engine->globalObject().setProperty(obj->objectName(), objectValue);
		evaluate_script_quiet(QString("plugins.push(%1);").arg(obj->objectName()));
#endif

		Q_FOREACH(QAction* action, plugin->actions()) {
			// If action does not belong to the menus, add it to "Operations" menu
			if (!childs.contains(action)) {
				ui->menuModel_Geometry->addAction(action);
			}
			// Show and enable menu item
			addAction(action);
		}
		return true;
	}
	else
		return false;
}

bool CGALWindow::initIOPlugin(QObject* obj)
{
	Polyhedron_demo_io_plugin_interface* plugin =
		qobject_cast<Polyhedron_demo_io_plugin_interface*>(obj);
	if (plugin) {
		io_plugins << plugin;
		return true;
	}
	else
		return false;
}

void CGALWindow::message(QString message, QString colorName, QString font) {
	if (message.endsWith('\n')) {
		message.remove(message.length() - 1, 1);
	}
	std::cerr << qPrintable(message) << std::endl;
	statusBar()->showMessage(message, 5000);
	message = "<font color=\"" + colorName + "\" style=\"font-style: " + font + ";\" >" +
		message + "</font><br>";
	message = "[" + QTime::currentTime().toString() + "] " + message;
	ui->consoleTextEdit->insertHtml(message);
	ui->consoleTextEdit->verticalScrollBar()->setValue(ui->consoleTextEdit->verticalScrollBar()->maximum());
}

void CGALWindow::information(QString text) {
	this->message("INFO: " + text, "");
}

void CGALWindow::warning(QString text) {
	this->message("WARNING: " + text, "blue");
}

void CGALWindow::error(QString text) {
	this->message("ERROR: " + text, "red");
}
