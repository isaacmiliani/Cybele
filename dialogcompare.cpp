#include "dialogcompare.h"
#include "ui_dialogcompare.h"

DialogCompare::DialogCompare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCompare)
{
    ui->setupUi(this);
}

DialogCompare::~DialogCompare()
{
    delete ui;
}
