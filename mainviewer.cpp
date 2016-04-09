#include "mainviewer.h"
#include "ui_mainviewer.h"
//#include "Scene.h"
//#include "Scene_item.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>
#include "polyhedron.h"

MainViewer::MainViewer(QWidget *parent)
	: CGAL::Qt::DemosMainWindow(parent)
{
	ui = new Ui::MainViewer;
    ui->setupUi(this);

	// Save some pointers from ui, for latter use.
	sceneView = ui->sceneView;
	viewer = ui->viewer;

	// do not save the state of the viewer (anoying)
	viewer->setStateFileName(QString::null);

	// setup scene
	//scene = new Scene(this);
	//viewer->setScene(scene);
}

MainViewer::~MainViewer()
{
    delete ui;
}


void MainViewer::message(QString message, QString colorName, QString font) {
	if (message.endsWith('\n')) {
		message.remove(message.length() - 1, 1);
	}
	std::cerr << qPrintable(message) << std::endl;
	statusBar()->showMessage(message, 5000);
	message = "<font color=\"" + colorName + "\" style=\"font-style: " + font + ";\" >" +
		message + "</font><br>";
	message = "[" + QTime::currentTime().toString() + "] " + message;
	ui->consoleTextEdit->insertHtml(message);
	//ui->consoleTextEdit->verticalScrollBar()->setValue(ui->consoleTextEdit->verticalScrollBar()->maximum());
}

void MainViewer::information(QString text) {
	this->message("INFO: " + text, "");
}

void MainViewer::warning(QString text) {
	this->message("WARNING: " + text, "blue");
}

void MainViewer::error(QString text) {
	this->message("ERROR: " + text, "red");
}

void MainViewer::on_actionOpen_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.ply)"));
	//Scene_item* item;

	if (fileName != "")
	{
		std::string fileOutput = "C:\\Users\\kaptain eesikord\\Documents\\Meshes\\bunny_poisson.off";
		PolyhedronPtr polyhedron_ptr(new Polyhedron());
		int res = polyhedron_ptr->load_mesh_ply(fileName.toStdString());
		if (!res){
			polyhedron_ptr->compute_bounding_box();
			polyhedron_ptr->compute_normals();
			polyhedron_ptr->compute_type();
			polyhedron_ptr->calc_nb_components();
			polyhedron_ptr->calc_nb_boundaries();
			
			//ui->viewer->draw();
			//polyhedron_ptr->write_off(fileOutput, false, true);
			
			QMessageBox::StandardButton reply;
			reply = QMessageBox::information(this, tr("QMessageBox::information()"), "PLY Load Success");
			if (reply == QMessageBox::Ok){
			}
		}
		
		//Scene_polyhedron_item* item = new Scene_polyhedron_item();

		//*item = *polyhedron_ptr;
		/*
		PolyhedronPtr polyhedron_ptr(new Polyhedron());

		//Scene_item* item = NULL;
		// Try to read .off in a polyhedron
		Scene_polyhedron_item* item = new Scene_polyhedron_item();
		int res = polyhedron_ptr->load_mesh_ply(files);
		if (!res){
		if (polyhedron_ptr->empty()){

		}*/
	}
}

