#ifndef DIALOGCOMPARE_H
#define DIALOGCOMPARE_H

#include <QDialog>

namespace Ui {
class DialogCompare;
}

class DialogCompare : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCompare(QWidget *parent = 0);
    ~DialogCompare();

private:
    Ui::DialogCompare *ui;
};

#endif // DIALOGCOMPARE_H
