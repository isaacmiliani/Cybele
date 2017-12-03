#include "dialogpatient.h"
#include "ui_dialogpatient.h"
#include "QSQLDbHelper.h"

DialogPatient::DialogPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPatient)
{
    ui->setupUi(this);
}

DialogPatient::~DialogPatient()
{
    delete ui;
}

void DialogPatient::on_buttonBox_accepted()
{
	nombre_p = ui->nombre->text();
	apellido_p = ui->apellido->text();
	fecha_nacimiento_p = ui->fecha_nacimiento->text();
	cedula_p = ui->cedula->text();
	fecha_captura_p = ui->fecha_captura->text();

	const char* driverName = "QPSQL";
	QSQLDbHelper* qSQLDbHelper = new QSQLDbHelper(driverName);
	QSqlDatabase* db = qSQLDbHelper->connect("localhost", "cybele", "postgres", "p4ssw0rd");
	if (id_paciente == 0){
		if (db->open()) {

			QSqlQuery* query = new QSqlQuery(*db);
			query->setForwardOnly(true);

			if (!query->prepare(
				QString("INSERT INTO pacientes(nombre, apellido, fecha_nacimiento, cedula) VALUES ( ?, ?, ?, ?)")))
			{
				qDebug() << "Error = " << db->lastError().text();
				exit;
			}
			else
			{
				query->addBindValue(ui->nombre->text());
				query->addBindValue(ui->apellido->text());
				query->addBindValue(ui->fecha_nacimiento->text());
				query->addBindValue(ui->cedula->text());
			}

			bool result = qSQLDbHelper->executeInsert(query);
			id_paciente = qSQLDbHelper->lastInsertID;
			if (result)
				qDebug() << "Successful insert in Modelos";
			else
				qDebug() << "Insert failed in Modelos";

		}
	}
}

void DialogPatient::on_buttonBox_rejected()
{

}

void DialogPatient::on_cedula_returnPressed()
{

}

void DialogPatient::on_cedula_editingFinished()
{
    id_paciente = 0;
    const char* driverName = "QPSQL";
    QSQLDbHelper* qSQLDbHelper = new QSQLDbHelper(driverName);
    QSqlDatabase* db = qSQLDbHelper->connect("localhost", "cybele", "postgres", "p4ssw0rd");
    if (db->open()) {

            QSqlQuery* query = new QSqlQuery(*db);
            query->setForwardOnly(true);

            if (!query->prepare(
                    QString("SELECT id, nombre, apellido, fecha_nacimiento, cedula FROM public.pacientes where cedula = ? ")))
            {
                    qDebug() << "Error = " << db->lastError().text();
                    exit;
            }
            else
            {
                    query->addBindValue(ui->cedula->text());
            }

            bool queryRes = query->exec();

            if (queryRes)
                    while (query->next())
                    {
                            id_paciente = query->value(0).toInt();
                            ui->nombre->setText(query->value(1).toString());
                            ui->apellido->setText(query->value(2).toString());
                            ui->fecha_nacimiento->setDate(query->value(3).toDate());
                            ui->cedula->setText(query->value(4).toString());
                    }
    }
    //return id_paciente;
}
