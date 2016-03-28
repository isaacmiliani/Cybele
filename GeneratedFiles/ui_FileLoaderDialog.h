/********************************************************************************
** Form generated from reading UI file 'FileLoaderDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILELOADERDIALOG_H
#define UI_FILELOADERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileLoaderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *pluginBox;
    QDialogButtonBox *buttonBox;
    QCheckBox *alwaysUse;

    void setupUi(QDialog *FileLoaderDialog)
    {
        if (FileLoaderDialog->objectName().isEmpty())
            FileLoaderDialog->setObjectName(QStringLiteral("FileLoaderDialog"));
        FileLoaderDialog->resize(339, 105);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileLoaderDialog->sizePolicy().hasHeightForWidth());
        FileLoaderDialog->setSizePolicy(sizePolicy);
        FileLoaderDialog->setLayoutDirection(Qt::LeftToRight);
        FileLoaderDialog->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(FileLoaderDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(FileLoaderDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        pluginBox = new QComboBox(FileLoaderDialog);
        pluginBox->setObjectName(QStringLiteral("pluginBox"));

        verticalLayout->addWidget(pluginBox);

        buttonBox = new QDialogButtonBox(FileLoaderDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        alwaysUse = new QCheckBox(FileLoaderDialog);
        alwaysUse->setObjectName(QStringLiteral("alwaysUse"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(alwaysUse->sizePolicy().hasHeightForWidth());
        alwaysUse->setSizePolicy(sizePolicy2);
        alwaysUse->setChecked(true);

        verticalLayout->addWidget(alwaysUse);


        retranslateUi(FileLoaderDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileLoaderDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileLoaderDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileLoaderDialog);
    } // setupUi

    void retranslateUi(QDialog *FileLoaderDialog)
    {
        FileLoaderDialog->setWindowTitle(QApplication::translate("FileLoaderDialog", "Select a loader", 0));
        label->setText(QApplication::translate("FileLoaderDialog", "TextLabel", 0));
#ifndef QT_NO_STATUSTIP
        pluginBox->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pluginBox->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pluginBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        alwaysUse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileLoaderDialog: public Ui_FileLoaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILELOADERDIALOG_H
