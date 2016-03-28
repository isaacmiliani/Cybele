#ifndef CGALWINDOW_H
#define CGALWINDOW_H
#ifdef QT_SCRIPT_LIB
#  include  <QScriptEngine>
#endif

#include <QMainWindow>
//QT
#include <QTreeView>
#include <QSortFilterProxyModel>
//CGAL
#include <Messages_interface.h>
#include <Scene.h>
#include <Viewer.h>
#include <Scene_item.h>
#include <File_loader_dialog.h>
#include <Polyhedron_demo_io_plugin_interface.h>
#include <Polyhedron_demo_plugin_interface.h>


#include <QGLViewer/manipulatedCameraFrame.h>
#include <QGLViewer/manipulatedFrame.h>

namespace Ui {
class CGALWindow;
}

class CGALWindow : public QMainWindow,
	public Messages_interface
{
    Q_OBJECT
	Q_INTERFACES(Messages_interface)

public:
    explicit CGALWindow(QWidget *parent = 0);
    ~CGALWindow();
    Scene_item* load_item(QFileInfo fileinfo, Polyhedron_demo_io_plugin_interface* loader);
    Polyhedron_demo_io_plugin_interface* find_loader(const QString& loader_name) const;
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
