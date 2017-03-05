#ifndef CGALWINDOW_H
#define CGALWINDOW_H
#ifdef QT_SCRIPT_LIB
#include  <QScriptEngine>
#endif
#include <CGAL/Qt/DemosMainWindow.h>
#include <QMainWindow>
//QT
#include <QTreeView>
#include <QSortFilterProxyModel>
//CGAL
#include "Messages_interface.h"
#include <File_loader_dialog.h>
#include <Scene.h>
#include <Polyhedron_demo_io_plugin_interface.h>
#include <Polyhedron_demo_plugin_interface.h>

class Scene;
class Viewer;
class QTreeView;
class QMenu;
class Polyhedron_demo_io_plugin_interface;
class Polyhedron_demo_plugin_interface;
class Scene_item;
class QSortFilterProxyModel;

#include <QGLViewer/manipulatedCameraFrame.h>
#include <QGLViewer/manipulatedFrame.h>

namespace Ui {
class CGALWindow;
}

class CGALWindow:
	public CGAL::Qt::DemosMainWindow,
	public Messages_interface
{
    Q_OBJECT
	Q_INTERFACES(Messages_interface)

public:
    explicit CGALWindow(QWidget *parent = 0);
    ~CGALWindow();
	/// Find an IO plugin.
	/// @throws `std::invalid_argument` if no loader with that argument can be found
	/// @returns the IO plugin associated with `loader_name`
	Polyhedron_demo_io_plugin_interface* find_loader(const QString& loader_name) const;

	/// Load an item with a given loader.
	///
	/// @throws `std::logic_error` if loading does not succeed or
	/// `std::invalid_argument` if `fileinfo` specifies an invalid file
	Scene_item* load_item(QFileInfo fileinfo, Polyhedron_demo_io_plugin_interface*);
    unsigned int maxNumberOfRecentFiles() const ;
protected:
    QVector<QAction*> recentFileActs;
    QAction* recentFilesSeparator;
    int getSelectedSceneItemIndex() const;
	void loadPlugins();
	bool initPlugin(QObject*);
	bool initIOPlugin(QObject*);
private:
    Ui::CGALWindow *ui;
    QMap<QString,QString> default_plugin_selection;
    Scene* scene;
    Viewer* viewer;
    QSortFilterProxyModel* proxyModel;
    QTreeView* sceneView;
    QVector<Polyhedron_demo_io_plugin_interface*> io_plugins;
    unsigned int maxNumRecentFiles;
	/// plugin black-list
	QSet<QString> plugin_blacklist;
	// typedef to make Q_FOREACH work
	typedef QPair<Polyhedron_demo_plugin_interface*, QString> PluginNamePair;
	QVector<PluginNamePair > plugins;

#ifdef QT_SCRIPT_LIB
  QScriptEngine* script_engine;
public:
  void evaluate_script(QString script,const QString & fileName = QString(),
                       const bool quiet = false);
  void evaluate_script_quiet(QString script, const QString & fileName = QString());
#endif
public slots:
  /// given a file extension file, returns true if `filename` matches the filter
  bool file_matches_filter(const QString& filters, const QString& filename);
  void selectSceneItem(int i);
  bool hasPlugin(const QString&) const;
  void information(QString);
  void warning(QString);
  void error(QString);
  void message(QString, QString, QString = QString("normal"));
protected slots:
  void addToRecentFiles(QString fileName);
  void updateRecentFileActions();
  void updateInfo();
  void updateDisplayInfo();
private slots:
    void open(QString filename);
    bool load_script(QString filename);
    bool load_script(QFileInfo);
    void setMaxNumberOfRecentFiles(const unsigned int);
    void on_actionLoad_triggered();
};

#endif // CGALWINDOW_H
