#include "mainviewer.h"
#include "ui_mainviewer.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>
#include "polyhedron.h"

MainViewer::MainViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainViewer)
{
    ui->setupUi(this);
}

MainViewer::~MainViewer()
{
    delete ui;
}

void MainViewer::on_actionOpen_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.ply)"));

	if (fileName != "")
	{
		std::string fileOutput = "C:\\Users\\kaptain eesikord\\Documents\\Meshes\\bunny_poisson.off";
		PolyhedronPtr polyhedron_ptr(new Polyhedron());
		int res = polyhedron_ptr->load_mesh_ply(fileName.toStdString());
		if (!res){
			polyhedron_ptr->write_off(fileOutput, false, true);
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
		polyhedron_ptr->compute_bounding_box();
		polyhedron_ptr->compute_normals();
		polyhedron_ptr->compute_type();
		polyhedron_ptr->calc_nb_components();
		polyhedron_ptr->calc_nb_boundaries();
		}*/
	}
}
