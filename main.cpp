

#include <QtWidgets\qapplication.h>
#include <QApplication>
#include "cybele.h"
//#include "cgalwindow.h"
#include "piechart.h"
//#include "MainWindow.h"
#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QCoreApplication>
#include <QQmlApplicationEngine>


#define NO_ENTERPRISE

int main(int argc, char *argv[])
{
	//QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
	QApplication a(argc, argv);
	Cybele w;

	w.showMaximized();
	return a.exec();
}
