

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
	QApplication a(argc, argv);

	//CGAL
	Cybele w;

	
	// PLY to OFF
	//MainViewer w;
	
	//MEPP 
	//MainWindow w;

	//CGALWindow w;
	w.show();

	
	//QGuiApplication app(argc, argv);

	////QQmlApplicationEngine engine;
	///engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	//return app.exec();

	//QGuiApplication app(argc, argv);

	//qmlRegisterType<PieChart>("Charts", 1, 0, "PieChart");

	//QQuickView view;
	//view.setResizeMode(QQuickView::SizeRootObjectToView);
	//view.setSource(QUrl("qrc:/chart.qml"));
	//view.show();

	//QCoreApplication app(argc, argv);

	//QQmlEngine engine;
	//Message msg;
	//engine.rootContext()->setContextProperty("msg", &msg);
	//QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
	//component.create();

	//return app.exec();
	return a.exec();
}
