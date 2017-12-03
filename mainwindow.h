#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cybele.h"	
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_kinect_clicked();

    void on_btn_daphne_clicked();

    void on_btn_cybele_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
