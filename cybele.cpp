#include "config.h"
#include "cybele.h"
#include <CGAL/IO/OFF_reader.h>
#include <vector>
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

struct myobjectX {
	bool operator() (Kernel::Point_3 pt1, Kernel::Point_3 pt2) { return (pt1.x() < pt2.x()); }
}myobjectX;
struct myobjectY {
	bool operator() (Kernel::Point_3 pt1, Kernel::Point_3 pt2) { return (pt1.y() < pt2.y()); }
}myobjectY;
struct myobjectZ {
	bool operator() (Kernel::Point_3 pt1, Kernel::Point_3 pt2) { return (pt1.z() < pt2.z()); }
}myobjectZ;

void Cybele::setAddKeyFrameKeyboardModifiers(::Qt::KeyboardModifiers m)
{
	viewer->setAddKeyFrameKeyboardModifiers(m);
}

void Cybele::enableScriptDebugger(bool b /* = true */)
{
	Q_UNUSED(b);
#ifdef QT_SCRIPT_LIB
#  ifdef QT_SCRIPTTOOLS_LIB
	QScriptEngineDebugger* debugger =
		findChild<QScriptEngineDebugger*>("qt script debugger");
	if (debugger) {
		if (b) {
			debugger->action(QScriptEngineDebugger::InterruptAction)->trigger();
		}
	}
	return;
#  endif
#endif
	// If we are here, then the debugger is not available
	this->error(tr("Your version of Qt is too old, and for that reason "
		"the Qt Script Debugger is not available."));
}
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
void Cybele::closeEvent(QCloseEvent *event)
{
	writeSettings();
	event->accept();
}
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
	Cybele* mw = qobject_cast<Cybele*>(engine->parent());
	QString result;
	for (int i = 0; i < context->argumentCount(); ++i) {
		if (i > 0)
			result.append(" ");
		result.append(context->argument(i).toString());
	}

	if (mw) mw->message(QString("QtScript: ") + result, "");

	return engine->undefinedValue();
}

Cybele::Cybele(QWidget *parent) :
	CGAL::Qt::DemosMainWindow(parent),
	edges_item(0),
	outside_edges_item(0),
    inside_edges_item(0)
{
		ui = new Ui::Cybele;
        ui->setupUi(this);
	
	// remove the Load Script menu entry, when the demo has not been compiled with QT_SCRIPT_LIB
#if !defined(QT_SCRIPT_LIB)
	ui->menuBar->removeAction(ui->actionLoad_Script);
#endif
	
	// Save some pointers from ui, for latter use.
	sceneView = ui->sceneView;
	viewer = ui->viewer;
	
	// do not save the state of the viewer (anoying)
	viewer->setStateFileName(QString::null);

	// setup scene
	scene = new Scene(this);
	viewer->setScene(scene);

	proxyModel = new QSortFilterProxyModel(this);
	proxyModel->setSourceModel(scene);

	sceneView->setModel(proxyModel);
	// setup the sceneview: delegation and columns sizing...
	sceneView->setItemDelegate(new SceneDelegate(this));
	sceneView->header()->setStretchLastSection(false);
	sceneView->header()->setSectionResizeMode(Scene::NameColumn, QHeaderView::Stretch);
	sceneView->header()->setSectionResizeMode(Scene::NameColumn, QHeaderView::Stretch);
	sceneView->header()->setSectionResizeMode(Scene::ColorColumn, QHeaderView::ResizeToContents);
	sceneView->header()->setSectionResizeMode(Scene::RenderingModeColumn, QHeaderView::Fixed);
	sceneView->header()->setSectionResizeMode(Scene::ABColumn, QHeaderView::Fixed);
	sceneView->header()->setSectionResizeMode(Scene::VisibleColumn, QHeaderView::Fixed);
	sceneView->resizeColumnToContents(Scene::ColorColumn);
	sceneView->resizeColumnToContents(Scene::RenderingModeColumn);
	sceneView->resizeColumnToContents(Scene::ABColumn);
	sceneView->resizeColumnToContents(Scene::VisibleColumn);

	// setup connections
	connect(scene, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),
		this, SLOT(updateInfo()));

	connect(scene, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),
		this, SLOT(updateDisplayInfo()));

	connect(scene, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),
		viewer, SLOT(updateGL()));

	connect(scene, SIGNAL(updated()),
		viewer, SLOT(updateGL()));

	connect(scene, SIGNAL(updated()),
		this, SLOT(selectionChanged()));

	connect(scene, SIGNAL(itemAboutToBeDestroyed(Scene_item*)),
		this, SLOT(removeManipulatedFrame(Scene_item*)));

	connect(scene, SIGNAL(updated_bbox()),
		this, SLOT(updateViewerBBox()));

	connect(scene, SIGNAL(selectionChanged(int)),
		this, SLOT(selectSceneItem(int)));

	connect(sceneView->selectionModel(),
		SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(updateInfo()));

	connect(sceneView->selectionModel(),
		SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(updateDisplayInfo()));

	connect(sceneView->selectionModel(),
		SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(selectionChanged()));

	sceneView->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(sceneView, SIGNAL(customContextMenuRequested(const QPoint &)),
		this, SLOT(showSceneContextMenu(const QPoint &)));

	connect(viewer, SIGNAL(selected(int)),
		this, SLOT(selectSceneItem(int)));
	connect(viewer, SIGNAL(selectedPoint(double, double, double)),
		this, SLOT(showSelectedPoint(double, double, double)));

	connect(viewer, SIGNAL(selectionRay(double, double, double,
		double, double, double)),
		scene, SIGNAL(selectionRay(double, double, double,
		double, double, double)));

	connect(viewer, SIGNAL(requestContextMenu(QPoint)),
		this, SLOT(contextMenuRequested(QPoint)));

	// The contextMenuPolicy of infoLabel is now the default one, so that one
	// can easily copy-paste its text.
	// connect(ui->infoLabel, SIGNAL(customContextMenuRequested(const QPoint & )),
	//         this, SLOT(showSceneContextMenu(const QPoint &)));

	connect(ui->actionRecenterScene, SIGNAL(triggered()),
		viewer, SLOT(update()));

	connect(ui->actionAntiAliasing, SIGNAL(toggled(bool)),
		viewer, SLOT(setAntiAliasing(bool)));

	connect(ui->actionDraw_two_sides, SIGNAL(toggled(bool)),
		viewer, SLOT(setTwoSides(bool)));

	// add the "About CGAL..." and "About demo..." entries
	this->addAboutCGAL();
	this->addAboutDemo(":/cgal/Polyhedron_3/about.html");

	// Connect the button "addButton" with actionLoad
	ui->addButton->setDefaultAction(ui->actionLoad);
	// Same with "removeButton" and "duplicateButton"
	ui->removeButton->setDefaultAction(ui->actionErase);
	ui->duplicateButton->setDefaultAction(ui->actionDuplicate);

	// Connect actionQuit (Ctrl+Q) and qApp->quit()
	connect(ui->actionQuit, SIGNAL(triggered()),
		this, SLOT(quit()));

	// Connect "Select all items"
	connect(ui->actionSelect_all_items, SIGNAL(triggered()),
		this, SLOT(selectAll()));

	// Recent files menu
	this->addRecentFiles(ui->menuFile, ui->actionQuit);
	connect(this, SIGNAL(openRecentFile(QString)),
		this, SLOT(open(QString)));

	// Reset the "Operation menu"
	clearMenu(ui->menuOperations);


#ifdef QT_SCRIPT_LIB
	std::cerr << "Enable scripts.\n";
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
	for (unsigned int i = 0; i < 9; ++i)
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

	readSettings(); // Among other things, the column widths are stored.

	// Load plugins, and re-enable actions that need it.
	loadPlugins();

	// Setup the submenu of the View menu that can toggle the dockwidgets
	Q_FOREACH(QDockWidget* widget, findChildren<QDockWidget*>()) {
		ui->menuDockWindows->addAction(widget->toggleViewAction());
	}
	ui->menuDockWindows->removeAction(ui->dummyAction);


#ifdef QT_SCRIPT_LIB
	// evaluate_script("print(plugins);");
	Q_FOREACH(QAction* action, findChildren<QAction*>()) {
		if (action->objectName() != "") {
			QScriptValue objectValue = script_engine->newQObject(action);
			script_engine->globalObject().setProperty(action->objectName(),
				objectValue);
		}
	}
	// debugger->action(QScriptEngineDebugger::InterruptAction)->trigger();
#endif
	// setup menu filtering
	connect(ui->menuOperations, SIGNAL(aboutToShow())
		, this, SLOT(filterOperations()));

}

Cybele::~Cybele()
{
	delete ui;
}

void Cybele::selectionChanged()
{
	scene->setSelectedItemIndex(getSelectedSceneItemIndex());
	scene->setSelectedItemsList(getSelectedSceneItemIndices());
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	if (item != NULL && item->manipulatable()) {
		viewer->setManipulatedFrame(item->manipulatedFrame());
	}
	else {
		viewer->setManipulatedFrame(0);
	}
	if (viewer->manipulatedFrame() == 0) {
		Q_FOREACH(Scene_item* item, scene->entries()) {
			if (item->manipulatable() && item->manipulatedFrame() != 0) {
				if (viewer->manipulatedFrame() != 0) {
					// there are at least two possible frames
					viewer->setManipulatedFrame(0);
					break;
				}
				else {
					viewer->setManipulatedFrame(item->manipulatedFrame());
				}
			}
		}
	}
	if (viewer->manipulatedFrame() != 0) {
		connect(viewer->manipulatedFrame(), SIGNAL(modified()),
			this, SLOT(updateInfo()));
	}
	viewer->updateGL();
} 

QList<int> Cybele::getSelectedSceneItemIndices() const
{
	QModelIndexList selectedRows = sceneView->selectionModel()->selectedRows();
	QList<int> result;
	Q_FOREACH(QModelIndex index, selectedRows) {
		result << proxyModel->mapToSource(index).row();
	}
	return result;
}

void Cybele::clearMenu(QMenu* menu)
{
	Q_FOREACH(QAction* action, menu->actions())
	{
		QMenu* menu = action->menu();
		if (menu) {
			clearMenu(menu);
		}
		action->setVisible(false);
	}
	menu->menuAction()->setEnabled(false);
}

void Cybele::contextMenuRequested(const QPoint& global_pos) {
	int index = scene->mainSelectionIndex();
	showSceneContextMenu(index, global_pos);
}
void Cybele::on_actionSetPolyhedronA_triggered()
{
	int i = getSelectedSceneItemIndex();
	scene->setItemA(i);
}
void Cybele::on_actionSaveAs_triggered()
{
	int index = -1;
	QAction* sender_action = qobject_cast<QAction*>(sender());
	if (sender_action && !sender_action->data().isNull()) {
		index = sender_action->data().toInt();
	}

	if (index < 0) {
		QModelIndexList selectedRows = sceneView->selectionModel()->selectedRows();
		if (selectedRows.size() != 1)
			return;
		index = getSelectedSceneItemIndex();
	}
	Scene_item* item = scene->item(index);

	if (!item)
		return;

	QVector<Polyhedron_demo_io_plugin_interface*> canSavePlugins;
	QStringList filters;
	Q_FOREACH(Polyhedron_demo_io_plugin_interface* plugin, io_plugins) {
		if (plugin->canSave(item)) {
			canSavePlugins << plugin;
			filters += plugin->nameFilters();
		}
	}
	filters << tr("All files (*)");

	if (canSavePlugins.isEmpty()) {
		QMessageBox::warning(this,
			tr("Cannot save"),
			tr("The selected object %1 cannot be saved.")
			.arg(item->name()));
		return;
	}

	QString caption = tr("Save %1 to File...").arg(item->name());
	QString filename =
		QFileDialog::getSaveFileName(this,
		caption,
		QString(),
		filters.join(";;"));
	save(filename, item);
}

void Cybele::on_actionPreferences_triggered()
{
	QDialog dialog(this);
	Ui::PreferencesDialog prefdiag;
	prefdiag.setupUi(&dialog);


	QStandardItemModel* iStandardModel = new QStandardItemModel(this);
	//add blacklisted plugins
	Q_FOREACH(QString name, plugin_blacklist)
	{
		QStandardItem* item = new QStandardItem(name);
		item->setCheckable(true);
		item->setCheckState(Qt::Checked);
		iStandardModel->appendRow(item);
	}

	//add operations plugins
	Q_FOREACH(PluginNamePair pair, plugins){
		QStandardItem* item = new QStandardItem(pair.second);
		item->setCheckable(true);
		iStandardModel->appendRow(item);
	}

	//add io-plugins
	Q_FOREACH(Polyhedron_demo_io_plugin_interface* plugin, io_plugins)
	{
		QStandardItem* item = new QStandardItem(plugin->name());
		item->setCheckable(true);
		if (plugin_blacklist.contains(plugin->name())) item->setCheckState(Qt::Checked);
		iStandardModel->appendRow(item);
	}

	//Setting the model
	prefdiag.listView->setModel(iStandardModel);

	dialog.exec();

	if (dialog.result())
	{
		plugin_blacklist.clear();
		for (int k = 0, k_end = iStandardModel->rowCount(); k<k_end; ++k)
		{
			QStandardItem* item = iStandardModel->item(k);
			if (item->checkState() == Qt::Checked )
				plugin_blacklist.insert(item->text());
		}
	}

	for (int k = 0, k_end = iStandardModel->rowCount(); k<k_end; ++k) delete iStandardModel->item(k);
	delete iStandardModel;
}
void Cybele::on_actionSetPolyhedronB_triggered()
{
	int i = getSelectedSceneItemIndex();
	scene->setItemB(i);
}
void Cybele::save(QString filename, Scene_item* item) {
	QFileInfo fileinfo(filename);

	Q_FOREACH(Polyhedron_demo_io_plugin_interface* plugin, io_plugins) {
		if (plugin->canSave(item) &&
			file_matches_filter(plugin->nameFilters(), filename))
		{
			if (plugin->save(item, fileinfo))
				break;
		}
	}
}

void Cybele::on_actionSaveSnapshot_triggered()
{
	viewer->saveSnapshot(false);
}

void Cybele::removeSceneItemFromSelection(int i)
{
	QItemSelection s =
		proxyModel->mapSelectionFromSource(scene->createSelection(i));
	sceneView->selectionModel()->select(s,
		QItemSelectionModel::Deselect);
	scene->itemChanged(i);
}
void Cybele::addSceneItemInSelection(int i)
{
	QItemSelection s =
		proxyModel->mapSelectionFromSource(scene->createSelection(i));
	sceneView->selectionModel()->select(s, QItemSelectionModel::Select);
	scene->itemChanged(i);
}
void Cybele::unSelectSceneItem(int i)
{
	removeSceneItemFromSelection(i);
}
void Cybele::showSceneContextMenu(int selectedItemIndex,
	const QPoint& global_pos)
{
	Scene_item* item = scene->item(selectedItemIndex);
	if (!item) return;

	const char* prop_name = "Menu modified by MainWindow.";

	QMenu* menu = item->contextMenu();
	if (menu) {
		bool menuChanged = menu->property(prop_name).toBool();
		if (!menuChanged) {
			menu->addSeparator();
			if (!item->property("source filename").toString().isEmpty()) {
				QAction* reload = menu->addAction(tr("&Reload item from file"));
				reload->setData(qVariantFromValue(selectedItemIndex));
				connect(reload, SIGNAL(triggered()),
					this, SLOT(reload_item()));
			}
			QAction* saveas = menu->addAction(tr("&Save as..."));
			saveas->setData(qVariantFromValue(selectedItemIndex));
			connect(saveas, SIGNAL(triggered()),
				this, SLOT(on_actionSaveAs_triggered()));

			QAction* showobject = menu->addAction(tr("&Zoom to this object"));
			showobject->setData(qVariantFromValue(selectedItemIndex));
			connect(showobject, SIGNAL(triggered()),
				this, SLOT(viewerShowObject()));

			QAction* objectLenght = menu->addAction(tr("&Measure this object"));
			objectLenght->setData(qVariantFromValue(selectedItemIndex));
			connect(objectLenght, SIGNAL(triggered()),
				this, SLOT(getCircumference()));

			menu->setProperty(prop_name, true);
		}
	}
	if (menu)
		menu->exec(global_pos);
}
double Cybele::getDistanceBetweenPoints(CGAL::Point_3<CGAL::Cartesian<double>> q, CGAL::Point_3<CGAL::Cartesian<double>> p){
	double x1, x2, y1, y2, z1, z2, dx, dy, dz, distance;
	// First point
	x1 = q.x();
	y1 = q.y();
	z1 = q.z();
	// Second Point
	x2 = p.x();
	y2 = p.y();
	z2 = p.z();

	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;

	distance = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
	return sqrt(distance);

} 

double Cybele::getCircumference(){
	int index = getSelectedSceneItemIndex();
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	Scene_polyhedron_item* pPtr = dynamic_cast<Scene_polyhedron_item*>(item);

	float total_squared = 0;
	float total_squared_3 = 0;
	float total_squared_scaled = 0;
	float total_squared_x_voxel_size = 0;
	float squared_distance = 0;
	float squared_distance_scaled = 0;
	float squared_distance_3 = 0;
	float voxel_size = 7.8;
	float perimeter = 0;
	int n = 0;
	CGAL::Point_3<CGAL::Cartesian<double>> p, q;
	if (pPtr != nullptr)
	{
		Polyhedron* pMesh = dynamic_cast<Polyhedron*>(pPtr->polyhedron());
		std::vector<CGAL::Point_3<CGAL::Cartesian<double>>> vec;

		std::size_t size = pMesh->size_of_vertices();
		vec.reserve(size);

		Polyhedron::Point_iterator i = pMesh->points_begin();

		for (Polyhedron::Point_iterator v = pMesh->points_begin(); v != pMesh->points_end(); ++v){
			q = CGAL::Point_3<CGAL::Cartesian<double>>(i->x(), i->y(), i->z());
			p = CGAL::Point_3<CGAL::Cartesian<double>>(v->x(), v->y(), v->z());

			// distancia entre puntos
			squared_distance = getDistanceBetweenPoints(q, p); //CGAL::squared_distance(q, p);

			// sumatoria de las distancias
			total_squared += squared_distance;

			perimeter = total_squared / 10;
			// distancia entre puntos multiplicado por el tama�o del voxel en mm
			squared_distance_scaled = squared_distance * voxel_size;

			// distancia total escalada
			total_squared_scaled += squared_distance_scaled;

			vec.push_back(p);

			i = v;

			std::cout << q << " <-> " << p << " = " << squared_distance << std::endl;
		}
		total_squared_x_voxel_size = total_squared * voxel_size;

		std::cout << "Total Perimeter (cm): " << perimeter << std::endl;
	
		information(QString("Total Perimeter (Unsorted): %1").arg(perimeter, 0, 'g', 10));
		
		// Point Sorting
		CGAL::spatial_sort(vec.begin(), vec.end());

		squared_distance = 0;
		squared_distance_scaled = 0;
		total_squared_scaled = 0;
		total_squared = 0;
		total_squared_x_voxel_size = 0;


		q = CGAL::Point_3<CGAL::Cartesian<double>>(vec[0]);

		for (std::size_t i = 0; i < size; ++i){
			// distancia entre puntos
			p = CGAL::Point_3<CGAL::Cartesian<double>>(vec[i]);
			squared_distance = getDistanceBetweenPoints(q, p); //CGAL::squared_distance(q, vec[i]);

			// sumatoria de las distancias
			total_squared += squared_distance;

			// distancia entre puntos multiplicado por el tama�o del voxel en mm
			squared_distance_scaled = squared_distance * voxel_size;

			// distancia total escalada
			total_squared_scaled += squared_distance_scaled;

			//std::cout << n << ". " << q << " + " << vec[i] << " = " << squared_distance << std::endl;

			q = vec[i];

			n++;
		}

		total_squared_x_voxel_size = total_squared * voxel_size;

		//std::cout << "Total Perimeter (Sorted): " << total_squared << std::endl;
		//std::cout << "Total Perimeter Scaled (Sorted): " << total_squared_scaled << std::endl;
		//std::cout << "Total Perimeter * Voxel Size (Sorted): " << total_squared_x_voxel_size << std::endl;

		//information(QString("Total Perimeter (Sorted): %1").arg(total_squared, 0, 'g', 10));
		//information(QString("Total Perimeter Scaled (Sorted): %1").arg(total_squared_scaled, 0, 'g', 10));
		//information(QString("Total Perimeter * Voxel Size (	Sorted): %1").arg(total_squared_x_voxel_size, 0, 'g', 10));
	}

	Scene_polylines_item* lPtr = dynamic_cast<Scene_polylines_item*>(item);
	if (lPtr != nullptr)
	{
		typedef std::vector<Point_3> Polyline;
		typedef std::list<Polyline> Polylines_container;

		Polylines_container polylines = lPtr->polylines;
		Polylines_container::iterator bbb = polylines.begin();
		std::size_t poly_size = polylines.size();
	
		Polylines_container::iterator it;

		Point_3 a, b;
		a = bbb->back();
		while (!bbb->empty())
		{
			b = bbb->back();
			std::cout << a << std::endl;
			q = CGAL::Point_3<CGAL::Cartesian<double>>(a.x(), a.y(), a.z());
			p = CGAL::Point_3<CGAL::Cartesian<double>>(b.x(), b.y(), b.z());
			// distancia entre puntos
			squared_distance = getDistanceBetweenPoints(p, q);
			// sumatoria de las distancias
			total_squared += squared_distance;
			// avanza el puntero
			a = b;
			bbb->pop_back();
		}
		perimeter = total_squared / 10;
		std::cout << "Total Perimeter (cm): " << perimeter << std::endl;
		information(QString("Total Perimeter (cm): %1").arg(perimeter, 0, 'g', 10));
	}
	Scene_points_with_normal_item* dPtr = dynamic_cast<Scene_points_with_normal_item*>(item);
	if (dPtr != nullptr)
	{
		typedef Point_set_3<Kernel> Point_set;
		typedef Point_set::UI_point UI_point;

		Point_set* points = dPtr->point_set();
		Point_set::iterator i = points->begin();

		std::vector<CGAL::Point_3<CGAL::Cartesian<double>>> vec;
		std::size_t size = points->size();

		vec.reserve(size);

		for (Point_set::iterator v = points->begin(); v != points->end(); ++v){
			q = CGAL::Point_3<CGAL::Cartesian<double>>(i->x(), i->y(), i->z());
			p = CGAL::Point_3<CGAL::Cartesian<double>>(v->x(), v->y(), v->z());

			// distancia entre puntos
			squared_distance = getDistanceBetweenPoints(q, p); //CGAL::squared_distance(q, p);

			// sumatoria de las distancias
			total_squared += squared_distance;

			perimeter += squared_distance;
			// distancia entre puntos multiplicado por el tama�o del voxel en mm
			squared_distance_scaled = squared_distance * voxel_size;

			// distancia total escalada
			total_squared_scaled += squared_distance_scaled;

			vec.push_back(p);

			i = v;

			std::cout << q << " <-> " << p << " = " << squared_distance << std::endl;
		}
		std::cout << "Total Perimeter (cm): " << perimeter << std::endl;

		information(QString("Total Perimeter (Unsorted): %1").arg(perimeter, 0, 'g', 10));
	}

	Scene_edges_item* edges_item = dynamic_cast<Scene_edges_item*>(item);
	if (edges_item != nullptr){
		for (std::vector<Epic_kernel::Segment_3>::iterator vi = edges_item->edges.begin(); vi != edges_item->edges.end(); ++vi){
			total_squared += vi->squared_length();
		}
	}

	Scene_bbox_item* height = dynamic_cast<Scene_bbox_item*>(item);

	if (height != nullptr){
		total_squared = height->bbox().width();
		total_squared = height->box_3().dimension();
		q = CGAL::Point_3<CGAL::Cartesian<double>>(height->bbox().xmin, height->bbox().ymin, height->bbox().zmin);
		p = CGAL::Point_3<CGAL::Cartesian<double>>(height->bbox().xmax, height->bbox().ymax, height->bbox().zmax);
		total_squared = CGAL::squared_distance(q, p);
	}
	return total_squared;
}
void Cybele::on_actionSetBackgroundColor_triggered()
{
	QColor c = QColorDialog::getColor();
	if (c.isValid()) {
		viewer->setBackgroundColor(c);
	}
}
void Cybele::showSceneContextMenu(const QPoint& p) {
	QWidget* sender = qobject_cast<QWidget*>(this->sender());
	if (!sender) return;

	int index = -1;
	if (sender == sceneView) {
		QModelIndex modelIndex = sceneView->indexAt(p);
		if (!modelIndex.isValid()) return;

		index = proxyModel->mapToSource(modelIndex).row();
	}else{
		index = scene->mainSelectionIndex();
	}

	showSceneContextMenu(index, sender->mapToGlobal(p));
}

void Cybele::reload_item() {
	QAction* sender_action = qobject_cast<QAction*>(sender());
	if (!sender_action) return;

	bool ok;
	int item_index = sender_action->data().toInt(&ok);
	QObject* item_object = scene->item(item_index);
	if (!ok || !item_object || sender_action->data().type() != QVariant::Int) {
		std::cerr << "Cannot reload item: "
			<< "the reload action has not item attached\n";
		return;
	}
	Scene_item* item = qobject_cast<Scene_item*>(item_object);
	if (!item) {
		std::cerr << "Cannot reload item: "
			<< "the reload action has a QObject* pointer attached\n"
			<< "that is not a Scene_item*\n";
		return;
	}
	QString filename = item->property("source filename").toString();
	QString loader_name = item->property("loader_name").toString();
	if (filename.isEmpty() || loader_name.isEmpty()) {
		std::cerr << "Cannot reload item: "
			<< "the item has no \"source filename\" or no \"loader_name\" attached attached\n";
		return;
	}

	Polyhedron_demo_io_plugin_interface* fileloader = find_loader(loader_name);
	QFileInfo fileinfo(filename);

	Scene_item* new_item = load_item(fileinfo, fileloader);

	new_item->setName(item->name());
	new_item->setColor(item->color());
	new_item->setRenderingMode(item->renderingMode());
	new_item->setVisible(item->visible());
	new_item->invalidate_buffers();
	scene->replaceItem(item_index, new_item, true);
	item->deleteLater();
}

void Cybele::removeManipulatedFrame(Scene_item* item)
{
	if (item->manipulatable() &&
		item->manipulatedFrame() == viewer->manipulatedFrame()) {
		viewer->setManipulatedFrame(0);
	}
}
void Cybele::readSettings()
{
	{
		QSettings settings;
		// enable anti-aliasing 
		ui->actionAntiAliasing->setChecked(settings.value("antialiasing", false).toBool());
		// read plugin blacklist
		QStringList blacklist = settings.value("plugin_blacklist", QStringList()).toStringList();
		Q_FOREACH(QString name, blacklist){ plugin_blacklist.insert(name); }

		// Added to avoid camera widget to load
		plugin_blacklist.insert("camera_positions_plugin");
	}
	this->readState("MainWindow", Size | State);
}
void Cybele::on_actionShowHide_triggered()
{
	Q_FOREACH(QModelIndex index, sceneView->selectionModel()->selectedRows())
	{
		int i = proxyModel->mapToSource(index).row();
		Scene_item* item = scene->item(i);
		item->setVisible(!item->visible());
		scene->itemChanged(i);
	}
}
void Cybele::selectAll()
{
	QItemSelection s =
		proxyModel->mapSelectionFromSource(scene->createSelectionAll());
	sceneView->selectionModel()->select(s,
		QItemSelectionModel::ClearAndSelect);
}
void Cybele::showSelectedPoint(double x, double y, double z)
{
	static double x_prev = 0;
	static double y_prev = 0;
	static double z_prev = 0;
	double dist = std::sqrt((x - x_prev)*(x - x_prev) + (y - y_prev)*(y - y_prev) + (z - z_prev)*(z - z_prev));
	information(QString("Selected point: (%1, %2, %3) distance to previous: %4").
		arg(x, 0, 'g', 10).
		arg(y, 0, 'g', 10).
		arg(z, 0, 'g', 10).
		arg(dist, 0, 'g', 10));
	x_prev = x;
	y_prev = y;
	z_prev = z;
}

void Cybele::information(QString text) {
	this->message("INFO: " + text, "");
}

void Cybele::warning(QString text) {
	this->message("WARNING: " + text, "blue");
}

void Cybele::error(QString text) {
	this->message("ERROR: " + text, "red");
}


void Cybele::viewerShow(float xmin,
	float ymin,
	float zmin,
	float xmax,
	float ymax,
	float zmax)
{
	qglviewer::Vec
		min_(xmin, ymin, zmin),
		max_(xmax, ymax, zmax);
#if QGLVIEWER_VERSION >= 0x020502
	viewer->camera()->setPivotPoint((min_ + max_)*0.5);
#else
	viewer->camera()->setRevolveAroundPoint((min_ + max_)*0.5);
#endif

	qglviewer::ManipulatedCameraFrame backup_frame(*viewer->camera()->frame());
	viewer->camera()->fitBoundingBox(min_, max_);
	qglviewer::ManipulatedCameraFrame new_frame(*viewer->camera()->frame());
	*viewer->camera()->frame() = backup_frame;
	viewer->camera()->interpolateTo(new_frame, 1.f);
	viewer->setVisualHintsMask(1);
	
}

void Cybele::viewerShow(float x, float y, float z) {
#if QGLVIEWER_VERSION >= 0x020502
	viewer->camera()->setPivotPoint(qglviewer::Vec(x, y, z));
#else
	viewer->camera()->setRevolveAroundPoint(qglviewer::Vec(x, y, z));
#endif
	// viewer->camera()->lookAt(qglviewer::Vec(x, y, z));

	qglviewer::ManipulatedCameraFrame backup_frame(*viewer->camera()->frame());
	viewer->camera()->fitSphere(qglviewer::Vec(x, y, z),
		viewer->camera()->sceneRadius() / 100);
	qglviewer::ManipulatedCameraFrame new_frame(*viewer->camera()->frame());
	*viewer->camera()->frame() = backup_frame;
	viewer->camera()->interpolateTo(new_frame, 1.f);
	viewer->setVisualHintsMask(1);
	
}

void Cybele::viewerShowObject()
{
	int index = -1;
	QAction* sender_action = qobject_cast<QAction*>(sender());
	if (sender_action && !sender_action->data().isNull()) {
		index = sender_action->data().toInt();
	}
	if (index >= 0) {
		const Scene::Bbox bbox = scene->item(index)->bbox();
		viewerShow((float)bbox.xmin, (float)bbox.ymin, (float)bbox.zmin,
			(float)bbox.xmax, (float)bbox.ymax, (float)bbox.zmax);
	}
}

void Cybele::message(QString message, QString colorName, QString font) {
	if (message.endsWith('\n')) {
		message.remove(message.length() - 1, 1);
	}
	std::cerr << qPrintable(message) << std::endl;
	statusBar()->showMessage(message, 5000);
	message = "<font color=\"" + colorName + "\" style=\"font-style: " + font + ";\" >" +
		message + "</font><br>";
	message = "[" + QTime::currentTime().toString() + "] " + message;
	//ui->consoleTextEdit->insertHtml(message);
	//ui->consoleTextEdit->verticalScrollBar()->setValue(ui->consoleTextEdit->verticalScrollBar()->maximum());
}



void Cybele::load_off(QString absoluteFilePath){

	PolyMesh mesh;
	// CONVERT FROM QSTRING TO *CONST CHAR
	QByteArray ba = absoluteFilePath.toLatin1();
	const char* filename = ba.data();

	std::ifstream input(filename);

	if (!input)
	{
		std::cerr << "Cannot open file " << std::endl;
	}
	std::vector<Epic_kernel::Point_3> points;
	std::vector< std::vector<std::size_t> > polygons;

	if (!CGAL::read_OFF(input, points, polygons))
	{
		std::cerr << "Error parsing the OFF file " << std::endl;
	}

	std::vector<Facet_handle>  patch_facets;
	std::vector<Vertex_handle> patch_vertices;

	CGAL::Polygon_mesh_processing::orient_polygon_soup(points, polygons);

	if (CGAL::Polygon_mesh_processing::is_polygon_soup_a_polygon_mesh(polygons))
		CGAL::Polygon_mesh_processing::polygon_soup_to_polygon_mesh(points, polygons, mesh);

	CGAL::Polygon_mesh_processing::triangulate_faces(mesh);

	// SAVE MESH
	std::ofstream out("filled.off");
	out.precision(17);
	out << mesh << std::endl;

}

void Cybele::calculatePointSetNormals(const char* filename_in, const char* filename_out){
	// Reads a .xyz point set file in points[].
	std::list<PointVectorPair> points;
	
	std::ifstream stream(filename_in);

	if (!stream || !CGAL::read_off_points(stream,std::back_inserter(points),CGAL::First_of_pair_property_map<PointVectorPair>()))
		std::cerr << "Error: cannot read file " << filename_in << std::endl;
	
	// Estimates normals direction.
	// Note: pca_estimate_normals() requires an iterator over points
	// as well as property maps to access each point's position and normal.
	const int nb_neighbors = 18; // K-nearest neighbors = 3 rings
	CGAL::pca_estimate_normals(points.begin(), points.end(),
		CGAL::First_of_pair_property_map<PointVectorPair>(),
		CGAL::Second_of_pair_property_map<PointVectorPair>(),
		nb_neighbors);
	// Orients normals.
	// Note: mst_orient_normals() requires an iterator over points
	// as well as property maps to access each point's position and normal.
	std::list<PointVectorPair>::iterator unoriented_points_begin =
		CGAL::mst_orient_normals(points.begin(), points.end(),CGAL::First_of_pair_property_map<PointVectorPair>(),CGAL::Second_of_pair_property_map<PointVectorPair>(),	nb_neighbors);
	// Optional: delete points with an unoriented normal
	// if you plan to call a reconstruction algorithm that expects oriented normals.
	points.erase(unoriented_points_begin, points.end());

	// Saves point set.
	// Note: write_xyz_points_and_normals() requires an output iterator
	// over points as well as property maps to access each
	// point position and normal.

	//SAVE FILE WITH NORMALS
	
	std::ofstream out(filename_out);
	if (!out || !CGAL::write_off_points_and_normals(out, points.begin(), points.end(), CGAL::First_of_pair_property_map<PointVectorPair>(), CGAL::Second_of_pair_property_map<PointVectorPair>()))
		std::cerr << "Error: cannot write .off file" << std::endl;

	

}
void Cybele::PoissonReconstruction(const char* filename_in, const char* filename_out){
	PointList points;
	std::ifstream stream(filename_in);
	if (!stream || !CGAL::read_off_points_and_normals(stream, std::back_inserter(points), CGAL::make_normal_of_point_with_normal_pmap(PointList::value_type())))
		std::cerr << "Error: cannot read file " << filename_in << std::endl;

	// Poisson options
	FT sm_angle = 20.0; // Min triangle angle in degrees.
	FT sm_radius = 30; // Max triangle size w.r.t. point set average spacing.
	FT sm_distance = 0.375; // Surface Approximation error w.r.t. point set average spacing.

	// Creates implicit function from the read points using the default solver.
	// Note: this method requires an iterator over points
	// + property maps to access each point's position and normal.
	// The position property map can be omitted here as we use iterators over Point_3 elements.
	Poisson_reconstruction_function function(points.begin(), points.end(), CGAL::make_normal_of_point_with_normal_pmap(PointList::value_type()));

	// Computes the Poisson indicator function f()
	// at each vertex of the triangulation.
	if (!function.compute_implicit_function())
		std::cerr << "compute_implicit_function - Failed" << std::endl;
	// Computes average spacing
	FT average_spacing = CGAL::compute_average_spacing(points.begin(), points.end(), 6 /* knn = 1 ring */);
	// Gets one point inside the implicit surface and computes implicit function bounding sphere radius.
	Point inner_point = function.get_inner_point();
	Sphere bsphere = function.bounding_sphere();
	FT radius = std::sqrt(bsphere.squared_radius());

	// Defines the implicit surface: requires defining a conservative bounding sphere centered at inner point.
	FT sm_sphere_radius = 5.0 * radius;
	FT sm_dichotomy_error = sm_distance*average_spacing / 1000.0; // Dichotomy error must be << sm_distance
	Surface_3 surface(function,Sphere(inner_point, sm_sphere_radius*sm_sphere_radius), sm_dichotomy_error / sm_sphere_radius);
	// Defines surface mesh generation criteria
	CGAL::Surface_mesh_default_criteria_3<STr> criteria(sm_angle,  // Min triangle angle (degrees)
		sm_radius*average_spacing,  // Max triangle size
		sm_distance*average_spacing); // Approximation error
	// Generates surface mesh with manifold option
	STr tr; // 3D Delaunay triangulation for surface mesh generation
	C2t3 c2t3(tr); // 2D complex in 3D Delaunay triangulation
	CGAL::make_surface_mesh(c2t3,                                 // reconstructed mesh
		surface,                              // implicit surface
		criteria,                             // meshing criteria
		CGAL::Manifold_with_boundary_tag());  // require manifold mesh
	if (tr.number_of_vertices() == 0)
		std::cerr << "ERROR - Number of vertices equals zero " << std::endl;
	
	// saves reconstructed surface mesh
	std::ofstream out(filename_out);
	Polyhedron_K output_mesh;
	CGAL::output_surface_facets_to_polyhedron(c2t3, output_mesh);
	out << output_mesh;
}

Scene_item* Cybele::load_item(QFileInfo fileinfo, Polyhedron_demo_io_plugin_interface* loader) {
	Scene_item* item = NULL;
	if (!fileinfo.isFile() || !fileinfo.isReadable()) {
		throw std::invalid_argument(QString("File %1 is not a readable file.")
			.arg(fileinfo.absoluteFilePath()).toStdString());
	}
	//SAVE FILE WITH NORMALS
	QString str_file = fileinfo.absoluteFilePath().section(".", 0, 0);
	QByteArray ba_file, ba_normal_file, ba_poisson_file;
	ba_file = str_file.toLatin1()+".off";
	ba_normal_file = str_file.toLatin1() + "-normals.off";
	ba_poisson_file = str_file.toLatin1() + "-poisson.off";

	calculatePointSetNormals(ba_file, ba_normal_file);
	PoissonReconstruction(ba_normal_file.data(), ba_poisson_file.data());
	fileinfo.setFile(ba_poisson_file.data());
	item = loader->load(fileinfo);

	QApplication::restoreOverrideCursor();
	if (!item) {
		throw std::logic_error(QString("Could not load item from file %1 using plugin %2")
			.arg(fileinfo.absoluteFilePath()).arg(loader->name()).toStdString());
	}

	item->setProperty("source filename", fileinfo.absoluteFilePath());
	item->setProperty("loader_name", loader->name());
	//QColor c(45, 137, 239);
	//item->setColor(c);
	return item;
}
void Cybele::selectSceneItem(int i)
{
	if (i < 0 || i >= scene->numberOfEntries()) {
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
void Cybele::updateInfo() {
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	if (item) {

		QString item_text = item->toolTip();
		QString item_filename = item->property("source filename").toString();
		if (!item_filename.isEmpty()) {
			item_text += QString("<br /><i>File: %1").arg(item_filename);
		}
		ui->infoLabel->setText(item_text);
	}
	else
		ui->infoLabel->clear();
}
void Cybele::updateDisplayInfo() {
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	if (item)
		ui->displayLabel->setPixmap(item->graphicalToolTip());
	else
		ui->displayLabel->clear();
}

int Cybele::getSelectedSceneItemIndex() const
{
	QModelIndexList selectedRows = sceneView->selectionModel()->selectedRows();
	if (selectedRows.size() != 1)
		return -1;
	else {
		QModelIndex i = proxyModel->mapToSource(selectedRows.first());
		return i.row();
	}
}
namespace {
	bool actionsByName(QAction* x, QAction* y) {
		return x->text() < y->text();
	}
}
void Cybele::loadPlugins()
{
	Q_FOREACH(QObject *obj, QPluginLoader::staticInstances())
	{
		initPlugin(obj);
		initIOPlugin(obj);
	}

	QList<QDir> plugins_directories;
	static QString plugins_folder = "C://Program Files//CGAL-4.7//build//demo//Polyhedron//Release";
	plugins_directories << plugins_folder; //qApp->applicationDirPath();
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
					qdebug << "error: " << qPrintable(loader.errorString());
				}
			}
		}
	}

	//test
	// sort the operations menu by name
	QList<QAction*> actions = ui->menuOperations->actions();
	qSort(actions.begin(), actions.end(), actionsByName);
	ui->menuOperations->clear();
	ui->menuOperations->addActions(actions);
}


bool Cybele::hasPlugin(const QString& pluginName) const
{
	Q_FOREACH(const PluginNamePair& p, plugins) {
		if (p.second == pluginName) return true;
	}
	return false;
}

bool Cybele::initPlugin(QObject* obj)
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
				ui->menuOperations->addAction(action);
			}
			// Show and enable menu item
			addAction(action);
		}
		return true;
	}
	else
		return false;
}

bool Cybele::initIOPlugin(QObject* obj)
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

#ifdef QT_SCRIPT_LIB
void Cybele::evaluate_script(QString script,
	const QString& filename,
	const bool quiet) {
	QScriptValue value = script_engine->evaluate(script, filename);
	if (script_engine->hasUncaughtException()) {
		QTextStream err(stderr);
		err << "Qt Script exception:\n"
			<< script_engine->uncaughtException().toString()
			<< "\nBacktrace:\n";
		Q_FOREACH(QString line, script_engine->uncaughtExceptionBacktrace()) {
			err << "  " << line << "\n";
		}
	}
	else if (!quiet && !value.isNull() && !value.isUndefined()) {
		QTextStream(stderr) << "Qt Script evaluated to \""
			<< value.toString() << "\"\n";
	}
}

void Cybele::evaluate_script_quiet(QString script,
	const QString& filename)
{
	evaluate_script(script, filename, true);
}
#endif

void Cybele::on_actionLoad_triggered()
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


void Cybele::open(QString filename)
{
	QFileInfo fileinfo(filename);

	//centralWidget = new FormExtractor();
	//setCentralWidget(centralWidget);
	//setUnifiedTitleAndToolBarOnMac(true);

	//centralWidget->show();
#ifdef QT_SCRIPT_LIB
	// Handles the loading of script file from the command line arguments,
	// and the special command line arguments that start with "javascript:"
	// or "qtscript:"
	QString program;
	if (filename.startsWith("javascript:")) {
		program = filename.right(filename.size() - 11);
	}
	if (filename.startsWith("qtscript:")) {
		program = filename.right(filename.size() - 9);
	}
	if (filename.endsWith(".js")) {
		load_script(fileinfo);
		return;
	}
	if (!program.isEmpty())
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

	if (!fileinfo.exists()){
		QMessageBox::warning(this,
			tr("Cannot open file"),
			tr("File %1 does not exist.")
			.arg(filename));
		return;
	}

	QStringList selected_items;
	QStringList all_items;

	QMap<QString, QString>::iterator dfs_it =
		default_plugin_selection.find(fileinfo.completeSuffix());

	if (dfs_it == default_plugin_selection.end())
	{
		// collect all io_plugins and offer them to load if the file extension match one name filter
		// also collect all available plugin in case of a no extension match
		Q_FOREACH(Polyhedron_demo_io_plugin_interface* io_plugin, io_plugins) {
			if (!io_plugin->canLoad()) continue;
			all_items << io_plugin->name();
			if (file_matches_filter(io_plugin->nameFilters(), filename))
				selected_items << io_plugin->name();
		}
	}
	else
		selected_items << *dfs_it;

	bool ok;
	std::pair<QString, bool> load_pair;

	switch (selected_items.size())
	{
	case 1:
		load_pair = std::make_pair(selected_items.first(), false);
		ok = true;
		break;
	case 0:
		load_pair = File_loader_dialog::getItem(fileinfo.fileName(), all_items, &ok);
		break;
	default:
		load_pair = File_loader_dialog::getItem(fileinfo.fileName(), selected_items, &ok);
	}

	if (!ok || load_pair.first.isEmpty()) { return; }

	if (load_pair.second)
		default_plugin_selection[fileinfo.completeSuffix()] = load_pair.first;


	QSettings settings;
	settings.setValue("OFF open directory",
		fileinfo.absoluteDir().absolutePath());

	Scene_item* scene_item = 0;

	scene_item = load_item(fileinfo, find_loader(load_pair.first));

	if (scene_item != 0) {
		this->addToRecentFiles(fileinfo.absoluteFilePath());
	}
	selectSceneItem(scene->addItem(scene_item));
}
bool Cybele::load_script(QString filename)
{
	QFileInfo fileinfo(filename);
	return load_script(fileinfo);
}

bool Cybele::load_script(QFileInfo info)
{
#if defined(QT_SCRIPT_LIB)
	QString program;
	QString filename = info.absoluteFilePath();
	QFile script_file(filename);
	script_file.open(QIODevice::ReadOnly);
	program = script_file.readAll();
	if (!program.isEmpty())
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

bool Cybele::file_matches_filter(const QString& filters,
	const QString& filename)
{
	QFileInfo fileinfo(filename);
	QString filename_striped = fileinfo.fileName();

	//match all filters between ()
	QRegExp all_filters_rx("\\((.*)\\)");

	QStringList split_filters = filters.split(";;");
	Q_FOREACH(const QString& filter, split_filters) {
		//extract filters
		if (all_filters_rx.indexIn(filter) != -1){
			Q_FOREACH(const QString& pattern, all_filters_rx.cap(1).split(' ')){
				QRegExp rx(pattern);
				rx.setPatternSyntax(QRegExp::Wildcard);
				if (rx.exactMatch(filename_striped)){
					return true;
				}
			}
		}
	}
	return false;
}
Polyhedron_demo_io_plugin_interface* Cybele::find_loader(const QString& loader_name) const {
	Q_FOREACH(Polyhedron_demo_io_plugin_interface* io_plugin,
		io_plugins) {
		if (io_plugin->name() == loader_name) {
			return io_plugin;
		}
	}
	throw std::invalid_argument(QString("No loader found with the name %1 available")
		.arg(loader_name).toStdString());
}
void Cybele::addAction(QAction* action)
{
  if(!action) return;

  action->setVisible(true);
  action->setEnabled(true);
  Q_FOREACH(QWidget* widget, action->associatedWidgets())
  {
     qDebug() << QString("%1 (%2)\n")
       .arg(widget->objectName())
     .arg(widget->metaObject()->className());
    QMenu* menu = qobject_cast<QMenu*>(widget);
    if(menu)
    {
      addAction(menu->menuAction());
    }
  }
}

void Cybele::addAction(QString actionName,
                           QString actionText,
                           QString menuName) {
  QMenu* menu = 0;
  Q_FOREACH(QAction* action, findChildren<QAction*>()) {
    if(!action->menu()) continue;
    QString menuText = action->menu()->title();
    if(menuText != menuName) continue;
    menu = action->menu();
  }
  if(menu == 0) {
    menu = new QMenu(menuName, this);
    menuBar()->insertMenu(ui->menuView->menuAction(), menu);
  }
  QAction* action = new QAction(actionText, this);
  action->setObjectName(actionName);
  menu->addAction(action);
#ifdef QT_SCRIPT_LIB
  QScriptValue objectValue = script_engine->newQObject(action);
  script_engine->globalObject().setProperty(action->objectName(),
                                            objectValue);
#endif
}
bool Cybele::on_actionErase_triggered()
{
	int next_index = scene->erase(scene->selectionIndices());
	selectSceneItem(next_index);
	return next_index >= 0;
}

void Cybele::on_actionEraseAll_triggered()
{
	while (on_actionErase_triggered()) {
	}
}
void Cybele::on_actionLoad_Script_triggered()
{
#if defined(QT_SCRIPT_LIB)
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Select a script to run..."),
		".",
		"QTScripts (*.js);;All Files (*)");

	load_script(QFileInfo(filename));
#endif
}
void Cybele::on_actionDuplicate_triggered()
{
	int index = scene->duplicate(getSelectedSceneItemIndex());
	selectSceneItem(index);
}

void Cybele::updateViewerBBox()
{
	const Scene::Bbox bbox = scene->bbox();
	const double xmin = bbox.xmin;
	const double ymin = bbox.ymin;
	const double zmin = bbox.zmin;
	const double xmax = bbox.xmax;
	const double ymax = bbox.ymax;
	const double zmax = bbox.zmax;
	// qDebug() << QString("Bounding box: (%1, %2, %3) - (%4, %5, %6)\n")
	// .arg(xmin).arg(ymin).arg(zmin).arg(xmax).arg(ymax).arg(zmax);
	qglviewer::Vec
		vec_min(xmin, ymin, zmin),
		vec_max(xmax, ymax, zmax);
	viewer->setSceneBoundingBox(vec_min,
		vec_max);
	viewer->camera()->showEntireScene();
}

QString Cybele::camera_string() const
{
	return viewer->dumpCameraCoordinates();
}

void Cybele::on_actionDumpCamera_triggered()
{
	information(QString("Camera: %1")
		.arg(camera_string()));
}

void Cybele::on_action_Copy_camera_triggered()
{
	qApp->clipboard()->setText(this->camera_string());
}

void Cybele::on_action_Paste_camera_triggered()
{
	QString s = qApp->clipboard()->text();
	viewer->moveCameraToCoordinates(s, 0.5f);
}

void Cybele::writeSettings()
{
	this->writeState("MainWindow");
	{
		QSettings settings;
		settings.setValue("antialiasing",
			ui->actionAntiAliasing->isChecked());
		//setting plugin blacklist
		QStringList blacklist;
		Q_FOREACH(QString name, plugin_blacklist){ blacklist << name; }
		if (!blacklist.isEmpty()) settings.setValue("plugin_blacklist", blacklist);
		else settings.remove("plugin_blacklist");
	}
	std::cerr << "Write setting... done.\n";
}
void Cybele::on_actionRecenterScene_triggered()
{
	updateViewerBBox();
	viewer->camera()->interpolateToFitScene();
}

void Cybele::filterOperations()
{
	Q_FOREACH(const PluginNamePair& p, plugins) {
		Q_FOREACH(QAction* action, p.first->actions()) {
			action->setVisible(p.first->applicable(action));
		}
	}

	// do a pass over all menus in Operations and hide them when they are empty
	Q_FOREACH(QAction* action, ui->menuOperations->actions()) {
		if (QMenu* menu = action->menu()) {
			action->setVisible(!(menu->isEmpty()));
		}
	}
}

void Cybele::on_action_Look_at_triggered()
{
	Show_point_dialog dialog(this);
	int i = dialog.exec();
	if (i == QDialog::Accepted &&
		dialog.has_correct_coordinates())
	{
		viewerShow((float)dialog.get_x(),
			(float)dialog.get_y(),
			(float)dialog.get_z());
	}
}
void Cybele::quit()
{
	close();
}

Scene_points_with_normal_item* Cybele::createMeasureItem(QString measure){

	int index = getSelectedSceneItemIndex();
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	
	Scene_polyhedron_selection_item* selection_item = dynamic_cast<Scene_polyhedron_selection_item*>(item);

	if (!selection_item) {
		information("Error: there is no selected polyhedron selection item!");
		return 0;
	}
	if (selection_item->selected_vertices.empty()) {
		information("Error: there is no selected vertex in polyhedron selection item!");
		return 0;
	}
	Scene_points_with_normal_item* point_item = new Scene_points_with_normal_item();
	point_item->setName(QString("%1-points").arg(measure));

	std::vector<Kernel::Point_3> selectedPoints;
	selectedPoints.reserve(selection_item->selected_vertices.size());

	int count = 0;
	for (Scene_polyhedron_selection_item::Selection_set_vertex::iterator begin = selection_item->selected_vertices.begin();
		begin != selection_item->selected_vertices.end(); ++begin) {
		point_item->point_set()->push_back((*begin)->point());
			selectedPoints.push_back((*begin)->point());
	}
	scene->setSelectedItem(scene->addItem(point_item));
	scene->itemChanged(point_item);
	scene->erase(index);

	return point_item;
}

Scene_plane_item* Cybele::createCutPlane(QString measure, Scene_points_with_normal_item* points) {
	Scene_plane_item* plane_item = new Scene_plane_item(scene);
	qglviewer::ManipulatedFrame* mf = plane_item->manipulatedFrame();

	// set center
	bool oldState = mf->blockSignals(true); // dont let it signal, it will invoke plane_manipulated_frame_modified otherwise
	const CGAL::Bbox_3 box_3 = createBBox(points);
	plane_item->setPosition((box_3.xmin() + box_3.xmax()) / 2.f, (box_3.ymin() + box_3.ymax()) / 2.f, (box_3.zmin() + box_3.zmax()) / 2.f);
	mf->blockSignals(oldState);

	// get base 1 and base 2
	Epic_kernel::Vector_3 b_1(0, 0, -1);
	Epic_kernel::Vector_3 b_2(-1, 0, 0);

	// compute other axis
	qglviewer::Vec base_1(b_1[0], b_1[1], b_1[2]);
	qglviewer::Vec base_2(b_2[0], b_2[1], b_2[2]);
	qglviewer::Vec other = cross(base_1, base_2);
	if (other.norm() == 0.0) { information("Error: collinear base vectors are not accepted!"); }

	// set orientation
	qglviewer::Quaternion orientation_from_bases;
	orientation_from_bases.setFromRotatedBasis(base_1, base_2, other);

	//NORMAL DEL PLANO
	oldState = mf->blockSignals(true); // dont let it signal, it will invoke plane_manipulated_frame_modified otherwise
	mf->setOrientation(orientation_from_bases);
	//mf->setOrientation(0, 0, 0, 1);
	mf->blockSignals(oldState);
	/*
	const Epic_kernel::Vector_3 normal = CGAL::cross_product(b_1, b_1);
	plane_item->setNormal(normal.x(), normal.y(), normal.z());
	*/
	QColor c(153, 180, 51,128);
	connect(plane_item, SIGNAL(destroyed()),this, SLOT(enableAction()));
	plane_item->setManipulatable(true);
	plane_item->setClonable(false);
	plane_item->setColor(c);
	plane_item->setWireframe();
	
	plane_item->setName(QString("%1-plane").arg(measure));
	//plane_item->setVisible(false);
	connect(plane_item->manipulatedFrame(), SIGNAL(modified()),
		this, SLOT(cut()));

	//actionCreateCutPlane->setEnabled(false);

	// Hide polyhedrons and call cut() (avoid that nothing shows up until user
	// decides to move the plane item)
	for (int i = 0, end = scene->numberOfEntries(); i < end; ++i) {
		Scene_item* item = scene->item(i);
		Scene_polyhedron_item* poly_item = qobject_cast<Scene_polyhedron_item*>(item);
		if (NULL != poly_item)
			poly_item->setVisible(false);
	}

	return plane_item;
	
}

Scene_edges_item* Cybele::cut(QString measure, Scene_plane_item* plane_item, Scene_points_with_normal_item* points) {
	
	QApplication::setOverrideCursor(Qt::WaitCursor);
	QColor c(227, 162, 26);
	if (!edges_item) {
		edges_item = new Scene_edges_item;
		edges_item->setName(QString("%1-edges").arg(measure));
		edges_item->setColor(c);
		edges_item->startTimer(0);

		c.setRgb(238, 17, 17);
		outside_edges_item = new Scene_edges_item;
		outside_edges_item->setName("Outside Edges of the cut");
		outside_edges_item->setColor(c);
		outside_edges_item->startTimer(0);

		c.setRgb(126, 56, 120);
		inside_edges_item = new Scene_edges_item;
		inside_edges_item->setName("Inside Edges of the cut");
		inside_edges_item->setColor(c);
		inside_edges_item->startTimer(0);

		connect(edges_item, SIGNAL(destroyed()),
			this, SLOT(reset_edges()));
		

		connect(outside_edges_item, SIGNAL(destroyed()),
			this, SLOT(reset_edges()));
		//scene->addItem(outside_edges_item);

		connect(inside_edges_item, SIGNAL(destroyed()),
			this, SLOT(reset_edges()));
		//scene->addItem(inside_edges_item);

	}
	if (edges_item->top)
	{
		//const qglviewer::Vec& pos = plane_item->manipulatedFrame()->position();
		//const qglviewer::Vec& n = plane_item->manipulatedFrame()->inverseTransformOf(qglviewer::Vec(2.f, 1.f, 1.f));

		const CGAL::Bbox_3 box_3 = createBBox(points);
		const Epic_kernel::Plane_3 plane = plane_item->plane();
		//std::cerr << plane << std::endl;
		edges_item->edges.clear();
		outside_edges_item->edges.clear();
		inside_edges_item->edges.clear();

		QTime time;
		time.start();
		for (int i = 0, end = scene->numberOfEntries(); i < end; ++i) {
			Scene_item* item = scene->item(i);

			Scene_polyhedron_item* poly_item = qobject_cast<Scene_polyhedron_item*>(item);
			if (!poly_item) continue;
			Trees::iterator it = trees.find(poly_item);
			if (it == trees.end()) {
				it = trees.insert(trees.begin(),
					std::make_pair(poly_item,
					new AABB_tree(faces(*(poly_item->polyhedron())).first,
					faces(*(poly_item->polyhedron())).second,
					*poly_item->polyhedron())));
				Scene_aabb_item* aabb_item = new Scene_aabb_item(*it->second);
				aabb_item->setName(tr("AABB tree of %1").arg(poly_item->name()));
				aabb_item->setRenderingMode(Wireframe);
				aabb_item->setVisible(false);
				scene->addItem(aabb_item);
				//std::cerr << "size: " << it->second->size() << std::endl;
			}

			if (!CGAL::do_intersect(plane, it->second->bbox()))
				continue;


			std::vector<AABB_tree::Object_and_primitive_id> intersections;
			it->second->all_intersections(plane, std::back_inserter(intersections));

			//CGAL::spatial_sort(intersections.begin(), intersections.end());
			//std::sort(intersections.begin(), intersections.end());
			int count = 0;
			int count_inside = 0;
			int count_outside = 0;
			for (std::vector<AABB_tree::Object_and_primitive_id>::iterator it = intersections.begin(),
				end = intersections.end(); it != end; ++it)
			{
				const Epic_kernel::Segment_3* inter_seg =
					CGAL::object_cast<Epic_kernel::Segment_3>(&(it->first));
				const Epic_kernel::Segment_3 last_seg;

				if (NULL != inter_seg){
					if (CGAL::do_intersect(box_3, *inter_seg)){
						inside_edges_item->edges.push_back(*inter_seg);
						edges_item->edges.push_back(*inter_seg);
						count++;
					}
					else{
						outside_edges_item->edges.push_back(*inter_seg);
					}
				}
			}
			std::cout << "**** Total Inside Segments: " << inside_edges_item->edges.size() << std::endl;
			std::cout << "---- Total Outside Segments: " << outside_edges_item->edges.size() << std::endl;
			count = 0;
			bool segmentFound = false;
			Epic_kernel::Point_3 source;
			Epic_kernel::Point_3 target;
			//source = inside_edges_item->edges.begin()->source();
			//target = inside_edges_item->edges.begin()->target();
			// RECORRE LOS SEGMENTOS DENTRO DEL BOUNDING BOX DE LOS PUNTOS SELECCIONADOS
			for (std::vector<Epic_kernel::Segment_3>::iterator i_inside = inside_edges_item->edges.begin(); i_inside != inside_edges_item->edges.end(); ++i_inside){
				if (!segmentFound){
					source = i_inside->target();
					target = i_inside->source();
				}

				//std::cout << "** looking for source: " << source.x() << ", " << source.y() << ", " << source.z() << std::endl;
				//std::cout << "++ looking for target: " << target.x() << ", " << target.y() << ", " << target.z() << std::endl;
				// RECORRE LOS SEGMENTOS QUE INTERSECTAN EL PLANO PERO QUE NO ESTAN DENTRO DEL BOUNDING BOX
				for (std::vector<Epic_kernel::Segment_3>::iterator i_outside = outside_edges_item->edges.begin(); i_outside != outside_edges_item->edges.end(); ++i_outside){
					if (i_outside == outside_edges_item->edges.begin()){
					std::cout << "@@ First OUTSIDE Segment: " << i_outside->source().x() << ", " << i_outside->source().y() << ", " << i_outside->source().z() << std::endl;
					}
					// VERIFICA QUE PREVIAMENTE NO SE HAYA AGREGADO EL SEGMENTO 
					if (!findSegment(*i_outside)){
						//std::cout << "@@ checking if: " << target << std::endl;
						//std::cout << "     @@ equals: " << i_outside->source() << std::endl;

						if (checkSources(source, i_outside->target(), i_outside->source()) || checkTargets(target, i_outside->source(), i_outside->target())){
							std::cout << "@@ Source: " << i_outside->source() << std::endl;
							std::cout << "@@ Target: " << i_outside->target() << std::endl;
							// AGREGA EL SEGMENTO A LA LISTA 
							edges_item->edges.push_back(*i_outside);
							//inside_edges_item->edges.push_back(*i_outside);

							// ACTUALIZA LA NUEVA PUNTA DEL PROXIMO PUNTO
							target = i_outside->target();
							source = i_outside->source();
			
							//searchSegment(source,target);
							//std::cout << "** new target: " << target.x() << ", " << target.y() << ", " << target.z() << std::endl;
							// PARA DEBUG
							count++;
							segmentFound = true;
							// REINICIA EL ITERADOR DE LOS SEGMENTOS FUERA DEL BOUNDING BOX
							for (int i = 0; i < count_outside; i++){
								if (i_outside != outside_edges_item->edges.begin())
									--i_outside;
							}
							count_outside = 0;
						}else
							segmentFound = false;
					}
					std::cout << "Outside i =: " << count_outside << std::endl;
					count_outside++;
				}
				std::cout << "Total outside segments iterated: " << count_outside << std::endl;
				count_outside = 0;

				std::cout << "Inside i =: " << count_inside << std::endl;
				count_inside++;
			}
			std::cout << "Total inside segments iterated: " << count_inside << std::endl;
			count_inside = 0;
			std::cout << "Total segments found: " << count << std::endl;
		}
		
		Scene_bbox_item* item = new Scene_bbox_item(scene);
		
		setBboxLines(item, box_3);
		connect(item, SIGNAL(destroyed()),
			this, SLOT(enableAction()));

		item->setName(QString("%1-bbox").arg(measure));
		item->setColor(Qt::black);
		item->setRenderingMode(Wireframe);
		scene->addItem(item);
		
		//actionBbox->setEnabled(false);
		
		information(QString("cut (%1 ms). %2 edges. (new edges)").arg(time.elapsed()).arg(edges_item->edges.size()));
		edges_item->invalidate_buffers();
		scene->itemChanged(edges_item);

		information(QString("cut (%1 ms). %2 edges. (outside)").arg(time.elapsed()).arg(outside_edges_item->edges.size()));
		outside_edges_item->invalidate_buffers();
		//scene->itemChanged(outside_edges_item);

		information(QString("cut (%1 ms). %2 edges. (inside)").arg(time.elapsed()).arg(inside_edges_item->edges.size()));
		inside_edges_item->invalidate_buffers();
		//scene->itemChanged(inside_edges_item);
	}
	
	QApplication::restoreOverrideCursor();
	outside_edges_item->top = false;
	edges_item->top = false;
	inside_edges_item->top = false;
	
	return edges_item;
}

void Cybele::setBboxLines(Scene_bbox_item* item, CGAL::Bbox_3 box_3){
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmax());

	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmax());

	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmin());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmax());

	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmax());

	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmin()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymin()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmax());
	item->lines.push_back(box_3.xmax()); item->lines.push_back(box_3.ymax()); item->lines.push_back(box_3.zmin());
}
bool Cybele::findSegment(Epic_kernel::Segment_3 inter_seg){
	
	for (std::vector<Epic_kernel::Segment_3>::iterator vi = edges_item->edges.begin(); vi != edges_item->edges.end(); ++vi){
		if (inter_seg == *vi)
			return true;
	}
	
	return false;
}

void Cybele::searchSegment(Scene_edges_item* edges_item, Scene_edges_item* outside_edges_item, Epic_kernel::Point_3 source, Epic_kernel::Point_3 target){
	Epic_kernel::Point_3 s;
	Epic_kernel::Point_3 t;
	
	for (std::vector<Epic_kernel::Segment_3>::iterator vi = outside_edges_item->edges.begin(); vi != outside_edges_item->edges.end(); ++vi){
		s = vi->source();
		t = vi->target();
		if (!findSegment(*vi)){
			//if (checkSources(target, t, s) || checkTargets(source, s, t))
			//	edges_item->edges.push_back(*vi);
		}
	}
}

CGAL::Bbox_3 Cybele::createBBox(Scene_points_with_normal_item* points){
	/*
	const Epic_kernel::Point_3 p = points->point_set[0];
	const Epic_kernel::Point_3 q = points->point_set[1];
	const Epic_kernel::Point_3 r = points->point_set[2];
	const Epic_kernel::Point_3 s = points->point_set[3];
	
	std::size_t size = 4;
	std::vector<Kernel::Point_3> vec;
	double minX, minY, minZ, maxX, maxY, maxZ;
	vec.reserve(size);
	vec.push_back(p);
	vec.push_back(q);
	vec.push_back(r);
	vec.push_back(s);

	// Point Sorting
	std::sort(vec.begin(), vec.end(), myobjectX);
	minX = vec[0].x();
	maxX = vec[3].x();

	std::sort(vec.begin(), vec.end(), myobjectY);
	minY = vec[0].y();
	maxY = vec[3].y();

	std::sort(vec.begin(), vec.end(), myobjectZ);
	minZ = vec[0].z();
	maxZ = vec[3].z();
	
	Kernel::Point_3 maxPoint(maxX, maxY, maxZ);
	Kernel::Point_3 minPoint(minX, minY, minZ);
	*/
	const CGAL::Bbox_3 box_3(points->point_set()->bounding_box().xmin(), points->point_set()->bounding_box().ymin(), points->point_set()->bounding_box().zmin(), points->point_set()->bounding_box().xmax(), points->point_set()->bounding_box().ymax(), points->point_set()->bounding_box().zmax());
	return box_3;
}

bool Cybele::checkTargets(Epic_kernel::Point_3 target, Epic_kernel::Point_3 t, Epic_kernel::Point_3 s){
	return ((target.cartesian(0) == t.cartesian(0)) || target.cartesian(2) == t.cartesian(2)) || (target.cartesian(0) == s.cartesian(0) || target.cartesian(2) == s.cartesian(2));
	//return (target == segment.vertex(0) || target == segment.vertex(1));
}
bool Cybele::checkSources(Epic_kernel::Point_3 source, Epic_kernel::Point_3 s, Epic_kernel::Point_3 t){
	return ((source.cartesian(0) == s.cartesian(0)) || source.cartesian(2) == s.cartesian(2)) || (source.cartesian(0) == t.cartesian(0) || source.cartesian(2) == t.cartesian(2));
	//return (source == segment.vertex(0) || source == segment.vertex(1));
}

void Cybele::on_btn_CircunCefalica_clicked()
{
	QString measureName = "CircunCefalica";
	points_CircunCefalica = createMeasureItem(measureName);
	plane_CircunCefalica = createCutPlane(measureName, points_CircunCefalica);
	edges_CircunCefalica = cut(measureName, plane_CircunCefalica, points_CircunCefalica);
	double value = computeMeasure(edges_CircunCefalica);

	scene->addItem(plane_CircunCefalica);
	scene->addItem(edges_CircunCefalica);
	QString valueAsString = QString::number(value);
	QString measure = "Circunferencia Cefálica: " + valueAsString + " cm.";
	ui->lbl_CircunCefalica->setText(measure);

}

void Cybele::on_btn_CircunBrazoIzq_clicked()
{
	QString measureName = "CircunBrazoIzq";
	points_CircunBrazoIzq = createMeasureItem(measureName);
	plane_CircunBrazoIzq = createCutPlane(measureName, points_CircunBrazoIzq);
	edges_CircunBrazoIzq = cut(measureName, plane_CircunBrazoIzq, points_CircunBrazoIzq);
	double value = computeMeasure(edges_CircunBrazoIzq);

	scene->addItem(plane_CircunBrazoIzq);
	scene->addItem(edges_CircunBrazoIzq);
	QString valueAsString = QString::number(value);
	QString measure = "Circunferencia Brazo Izquierdo: " + valueAsString + " cm.";
	ui->lbl_CircunBrazoIzq->setText(measure);
}

void Cybele::on_btn_CircunCintura_clicked()
{
	QString measureName = "CircunCintura";
	points_CircunCintura = createMeasureItem(measureName);
	plane_CircunCintura = createCutPlane(measureName, points_CircunCintura);
	edges_CircunCintura = cut(measureName, plane_CircunCintura, points_CircunCintura);

	scene->addItem(plane_CircunCintura);
	scene->addItem(edges_CircunCintura);
	double value = computeMeasure(edges_CircunCintura);
	QString valueAsString = QString::number(value);
	QString measure = "Circunferencia Cintura: " + valueAsString + " cm.";
	ui->lbl_CircunCintura->setText(measure);
}

void Cybele::on_btn_CircunCadera_clicked()
{
	QString measureName = "CircunCadera";
	points_CircunCadera = createMeasureItem(measureName);
	plane_CircunCadera = createCutPlane(measureName, points_CircunCadera);
	edges_CircunCadera = cut(measureName, plane_CircunCadera, points_CircunCadera);
	double value = computeMeasure(edges_CircunCadera);
	QString valueAsString = QString::number(value);
	QString measure = "Circunferencia Cadera: " + valueAsString + " cm.";
	ui->lbl_CircunCadera->setText(measure);
}

void Cybele::on_btn_CircunMusloIzq_clicked()
{
	QString measureName = "CircunMusloIzq";
	points_CircunMusloIzq = createMeasureItem(measureName);
	plane_CircunMusloIzq = createCutPlane(measureName, points_CircunMusloIzq);
	edges_CircunMusloIzq = cut(measureName, plane_CircunMusloIzq, points_CircunMusloIzq);
	double value = computeMeasure(edges_CircunMusloIzq);
	QString valueAsString = QString::number(value);
	QString measure = "Circunferencia Muslo Izquierdo: " + valueAsString + " cm.";
	ui->lbl_MusloIzq->setText(measure);
}

void Cybele::on_btn_DiamMuneca_clicked()
{
	QString measureName = "DiamMuneca";
	points_DiamMuneca = createMeasureItem(measureName);
	plane_DiamMuneca = createCutPlane(measureName, points_DiamMuneca);
	edges_DiamMuneca = cut(measureName, plane_DiamMuneca, points_DiamMuneca);
	double value = computeMeasure(edges_DiamMuneca);
	QString valueAsString = QString::number(value);
	QString measure = "Diametro Muñeca: " + valueAsString + " cm.";
	ui->lbl_DiamMuneca->setText(measure);
}

void Cybele::on_btn_DiamFemur_clicked()
{
	QString measureName = "DiamFemur";
	points_DiamFemur = createMeasureItem(measureName);
	plane_DiamFemur = createCutPlane(measureName, points_DiamFemur);
	edges_DiamFemur = cut(measureName, plane_DiamFemur, points_DiamFemur);
	double value = computeMeasure(edges_DiamFemur);
	QString valueAsString = QString::number(value);
	QString measure = "Diametro Femur: " + valueAsString + " cm.";
	ui->lbl_DiamFemur->setText(measure);
}

void Cybele::on_btn_Talla_clicked()
{
	int index = getSelectedSceneItemIndex();
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	Scene_polyhedron_item* height = dynamic_cast<Scene_polyhedron_item*>(item);
	CGAL::Point_3<CGAL::Cartesian<double>> p, q;
	float total_squared;
	//q = CGAL::Point_3<CGAL::Cartesian<double>>(height->bbox().xmin, height->bbox().ymin, height->bbox().zmin);
	//p = CGAL::Point_3<CGAL::Cartesian<double>>(height->bbox().xmax, height->bbox().ymax, height->bbox().zmax);
	
	total_squared = height->bbox().height();
	QString valueAsString = QString::number(total_squared/10);
	QString measure = "Talla: " + valueAsString + " cm.";
	ui->lbl_talla->setText(measure);
}

void Cybele::on_btn_selection_clicked()
{
	int index = getSelectedSceneItemIndex();
	Scene_item* item = scene->item(getSelectedSceneItemIndex());
	Scene_polyhedron_item* poly_item = dynamic_cast<Scene_polyhedron_item*>(item);

	if (!poly_item) {
		information("Error: there is no selected polyhedron item!");
		//print_message("Error: there is no selected polyhedron item!");
		return;
	}
	
	// all other arrangements (putting inside selection_item_map), setting names etc,
	// other params (e.g. k_ring) will be set inside new_item_created
	Scene_polyhedron_selection_item* new_item = new Scene_polyhedron_selection_item(poly_item, this);
	int item_id = scene->addItem(new_item);
	QObject* scene_ptr = dynamic_cast<QObject*>(scene);
	if (scene_ptr)
		connect(new_item, SIGNAL(simplicesSelected(Scene_item*)), scene_ptr, SLOT(setSelectedItem(Scene_item*)));
	scene->setSelectedItem(item_id);
}

double Cybele::computeMeasure(Scene_edges_item* cut){
	double total_squared = 0;
		for (std::vector<Epic_kernel::Segment_3>::iterator vi = cut->edges.begin(); vi != cut->edges.end(); ++vi){
			total_squared += vi->squared_length();
		}

	return total_squared / 100;
}