#ifndef CYBELE_H
#define CYBELE_H
#include "config.h"

#include <QtOpenGL/qgl.h>
#include <CGAL/Qt/DemosMainWindow.h>

#ifdef QT_SCRIPT_LIB
#  include  <QScriptEngine>
#endif

#include <QMainWindow>

#include <QVector>
#include <QList>
#include <QFileInfo>
#include <QStringList>
#include <QSet>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <iostream>
#include <CGAL/IO/io.h>
#include <CGAL/Cartesian.h>

class Scene;
class Viewer;
class QTreeView;
class QMenu;
class Polyhedron_demo_io_plugin_interface;
class Polyhedron_demo_plugin_interface;
class Scene_item;
class QSortFilterProxyModel;

namespace Ui {
class Cybele;
}

#include "Messages_interface.h"

class Cybele : 
	public CGAL::Qt::DemosMainWindow,
	public Messages_interface
{
	Q_OBJECT
	Q_INTERFACES(Messages_interface)

public:
    explicit Cybele(QWidget *parent = 0);
    ~Cybele();

	/// Find an IO plugin.
	/// @throws `std::invalid_argument` if no loader with that argument can be found
	/// @returns the IO plugin associated with `loader_name`
	Polyhedron_demo_io_plugin_interface* find_loader(const QString& loader_name) const;

	/// Load an item with a given loader.
	///
	/// @throws `std::logic_error` if loading does not succeed or
	/// `std::invalid_argument` if `fileinfo` specifies an invalid file
	Scene_item* load_item(QFileInfo fileinfo, Polyhedron_demo_io_plugin_interface*);

public Q_SLOTS:
	bool hasPlugin(const QString&) const;
	void information(QString);
	void warning(QString);
	void error(QString);
	void message(QString, QString, QString = QString("normal"));
	void selectSceneItem(int i);
	void updateViewerBBox();

	void showSelectedPoint(double, double, double);
	void selectAll();
	int getSelectedSceneItemIndex() const;
	void open(QString);
	bool load_script(QString filename);
	bool load_script(QFileInfo);
	/// given a file extension file, returns true if `filename` matches the filter
	bool file_matches_filter(const QString& filters, const QString& filename);
	void clearMenu(QMenu*);
	void addAction(QAction*);
	void addAction(QString actionName,
		QString actionText,
		QString menuName);
	void viewerShow(float, float, float);
	void viewerShow(float, float, float, float, float, float);
	void viewerShowObject();

protected:
	void loadPlugins();
	bool initPlugin(QObject*);
	bool initIOPlugin(QObject*);
	
protected Q_SLOTS:
	void selectionChanged();

	void contextMenuRequested(const QPoint& global_pos);
	void showSceneContextMenu(int selectedItemIndex,
		const QPoint& global_pos);
	void showSceneContextMenu(const QPoint& local_pos_of_treeview);
	QList<int> getSelectedSceneItemIndices() const;
	void updateInfo();
	void updateDisplayInfo();
	void removeManipulatedFrame(Scene_item*);

	// settings
	void quit();
	void readSettings();
	void writeSettings();

	// Show/Hide
	void on_actionShowHide_triggered();

	// Select A/B
	void on_actionSetPolyhedronA_triggered();
	void on_actionSetPolyhedronB_triggered();

	//Preferences edition
	void on_actionPreferences_triggered();
	// save as...
	void on_actionSaveAs_triggered();
	void save(QString filename, Scene_item* item);
	void on_actionSaveSnapshot_triggered();

	void on_actionSetBackgroundColor_triggered();

	void on_action_Look_at_triggered();

	QString camera_string() const;
	void on_actionDumpCamera_triggered();
	void on_action_Copy_camera_triggered();
	void on_action_Paste_camera_triggered();

	void filterOperations();

	void on_actionRecenterScene_triggered();
private slots:
    void on_actionLoad_triggered();

private:
    Ui::Cybele *ui;
	Viewer* viewer;
	QTreeView* sceneView;
	Scene* scene;	
	/// plugin black-list
	QSet<QString> plugin_blacklist;
	// typedef to make Q_FOREACH work
	typedef QPair<Polyhedron_demo_plugin_interface*, QString> PluginNamePair;
	QVector<PluginNamePair > plugins;
	QVector<Polyhedron_demo_io_plugin_interface*> io_plugins;
	QSortFilterProxyModel* proxyModel;
	QMap<QString, QString> default_plugin_selection;
#ifdef QT_SCRIPT_LIB
	QScriptEngine* script_engine;
public:
	void evaluate_script(QString script,
		const QString & fileName = QString(),
		const bool quiet = false);
	void evaluate_script_quiet(QString script,
		const QString & fileName = QString());
#endif
};

#endif // CYBELE_H
