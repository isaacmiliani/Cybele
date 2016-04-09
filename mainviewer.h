#ifndef MAINVIEWER_H
#define MAINVIEWER_H

#include <QMainWindow>
#include <QtOpenGL/qgl.h>
#include <CGAL/Qt/DemosMainWindow.h>

class Scene;
class ViewerQGL;
class QTreeView;
namespace Ui {
class MainViewer;
}
//#include "Messages_interface.h"

class MainViewer : public CGAL::Qt::DemosMainWindow
	//public Messages_interface
{
	Q_OBJECT
	//Q_INTERFACES(Messages_interface)

public:
    explicit MainViewer(QWidget *parent = 0);
    ~MainViewer();

private slots:
    void on_actionOpen_triggered();
	void information(QString);
	void warning(QString);
	void error(QString);
	void message(QString, QString, QString = QString("normal"));

private:
    Ui::MainViewer *ui;
	Scene* scene;
	ViewerQGL* viewer;
	QTreeView* sceneView;
};

#endif // MAINVIEWER_H
