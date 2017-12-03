#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_kinect_clicked()
{

}

void MainWindow::on_btn_daphne_clicked()
{
	
}

void MainWindow::on_btn_cybele_clicked()
{
	Cybele *w = new Cybele(this);
	w->showMaximized();
}
