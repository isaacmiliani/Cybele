#include <QApplication>
#include "Cybele.h"
#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets\qapplication.h>


#define NO_ENTERPRISE

int main(int argc, char *argv[])
{
	//QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
	QApplication a(argc, argv);
	Cybele w;

	w.showMaximized();
	return a.exec();
}
