/********************************************************************************
** Form generated from reading UI file 'mainviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEWER_H
#define UI_MAINVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "openglviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainViewer
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    OpenGLViewer *widget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainViewer)
    {
        if (MainViewer->objectName().isEmpty())
            MainViewer->setObjectName(QStringLiteral("MainViewer"));
        MainViewer->resize(1022, 801);
        actionOpen = new QAction(MainViewer);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralwidget = new QWidget(MainViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new OpenGLViewer(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 30, 720, 576));
        MainViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainViewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1022, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(MainViewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainViewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainViewer);

        QMetaObject::connectSlotsByName(MainViewer);
    } // setupUi

    void retranslateUi(QMainWindow *MainViewer)
    {
        MainViewer->setWindowTitle(QApplication::translate("MainViewer", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainViewer", "Open", 0));
        menuFile->setTitle(QApplication::translate("MainViewer", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainViewer: public Ui_MainViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEWER_H
