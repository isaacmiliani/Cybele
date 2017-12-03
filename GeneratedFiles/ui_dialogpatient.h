/********************************************************************************
** Form generated from reading UI file 'dialogpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPATIENT_H
#define UI_DIALOGPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogPatient
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *cedula;
    QLineEdit *nombre;
    QLineEdit *apellido;
    QDateEdit *fecha_nacimiento;
    QDateEdit *fecha_captura;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QDialog *DialogPatient)
    {
        if (DialogPatient->objectName().isEmpty())
            DialogPatient->setObjectName(QStringLiteral("DialogPatient"));
        DialogPatient->resize(357, 330);
        DialogPatient->setStyleSheet(QLatin1String("font: 87 10pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);\n"
""));
        buttonBox = new QDialogButtonBox(DialogPatient);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 240, 281, 51));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(DialogPatient);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 291, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cedula = new QLineEdit(layoutWidget);
        cedula->setObjectName(QStringLiteral("cedula"));

        gridLayout->addWidget(cedula, 0, 1, 1, 1);

        nombre = new QLineEdit(layoutWidget);
        nombre->setObjectName(QStringLiteral("nombre"));

        gridLayout->addWidget(nombre, 1, 1, 1, 1);

        apellido = new QLineEdit(layoutWidget);
        apellido->setObjectName(QStringLiteral("apellido"));

        gridLayout->addWidget(apellido, 2, 1, 1, 1);

        fecha_nacimiento = new QDateEdit(layoutWidget);
        fecha_nacimiento->setObjectName(QStringLiteral("fecha_nacimiento"));

        gridLayout->addWidget(fecha_nacimiento, 3, 1, 1, 1);

        fecha_captura = new QDateEdit(layoutWidget);
        fecha_captura->setObjectName(QStringLiteral("fecha_captura"));

        gridLayout->addWidget(fecha_captura, 5, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 87 9pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label, 5, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 87 9pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 87 9pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 87 9pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 87 9pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);


        retranslateUi(DialogPatient);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPatient, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPatient, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPatient);
    } // setupUi

    void retranslateUi(QDialog *DialogPatient)
    {
        DialogPatient->setWindowTitle(QApplication::translate("DialogPatient", "Datos Paciente", Q_NULLPTR));
        cedula->setPlaceholderText(QApplication::translate("DialogPatient", "Ingresar CI", Q_NULLPTR));
        nombre->setPlaceholderText(QApplication::translate("DialogPatient", "Nombre", Q_NULLPTR));
        apellido->setPlaceholderText(QApplication::translate("DialogPatient", "Apellido", Q_NULLPTR));
        label->setText(QApplication::translate("DialogPatient", "Fecha de Captura", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogPatient", "Fecha Nacimiento", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogPatient", "Apellido", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogPatient", "Nombre", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogPatient", "C\303\251dula", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogPatient: public Ui_DialogPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPATIENT_H
