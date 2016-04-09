
//#include "mainwindow.h"
//#include <QtWidgets\qapplication.h>
#include <QApplication>
//#include "MainWindow.h"
//#include "cgalwindow.h"
#include <mainwindow.hxx>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//CGAL
	//MainWindow w;

	// PLY to OFF
	//MainViewer w;
	
	//MEPP 
	mainwindow w;
	w.show();

	return a.exec();
}
