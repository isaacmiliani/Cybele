#ifndef DIALOGPATIENT_H
#define DIALOGPATIENT_H

#include <QDialog>

namespace Ui {
class DialogPatient;
}

class DialogPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPatient(QWidget *parent = 0);
	int id_paciente;
    ~DialogPatient();
	QString nombre_p, apellido_p, cedula_p, fecha_nacimiento_p, fecha_captura_p;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_cedula_returnPressed();

    void on_cedula_editingFinished();

private:
    Ui::DialogPatient *ui;
};

#endif // DIALOGPATIENT_H
