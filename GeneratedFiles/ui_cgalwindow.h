/********************************************************************************
** Form generated from reading UI file 'cgalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGALWINDOW_H
#define UI_CGALWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "viewer.h"

QT_BEGIN_NAMESPACE

class Ui_CGALWindow
{
public:
    QAction *actionLoad;
    QWidget *centralwidget;
    QDockWidget *infoDockWidget;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *infoLabel;
    QLabel *displayLabel;
    QDockWidget *sceneDockWidget;
    QWidget *dockWidgetContent;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *addButton;
    QToolButton *removeButton;
    QToolButton *duplicateButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QTreeView *sceneView;
    QDockWidget *consoleDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *consoleTextEdit;
    Viewer *viewer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuMesh;
    QMenu *menuModel_Geometry;
    QMenu *menuPCL;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CGALWindow)
    {
        if (CGALWindow->objectName().isEmpty())
            CGALWindow->setObjectName(QStringLiteral("CGALWindow"));
        CGALWindow->resize(1532, 990);
        actionLoad = new QAction(CGALWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralwidget = new QWidget(CGALWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        infoDockWidget = new QDockWidget(centralwidget);
        infoDockWidget->setObjectName(QStringLiteral("infoDockWidget"));
        infoDockWidget->setGeometry(QRect(770, 370, 560, 240));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        scrollArea = new QScrollArea(dockWidgetContents_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(350, 0));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 536, 174));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        infoLabel = new QLabel(scrollAreaWidgetContents);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy);
        infoLabel->setContextMenuPolicy(Qt::DefaultContextMenu);
        infoLabel->setLineWidth(0);
        infoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        infoLabel->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(infoLabel, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        displayLabel = new QLabel(dockWidgetContents_2);
        displayLabel->setObjectName(QStringLiteral("displayLabel"));

        verticalLayout_4->addWidget(displayLabel);


        horizontalLayout_2->addLayout(verticalLayout_4);

        infoDockWidget->setWidget(dockWidgetContents_2);
        sceneDockWidget = new QDockWidget(centralwidget);
        sceneDockWidget->setObjectName(QStringLiteral("sceneDockWidget"));
        sceneDockWidget->setGeometry(QRect(10, 20, 312, 302));
        sceneDockWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dockWidgetContent = new QWidget();
        dockWidgetContent->setObjectName(QStringLiteral("dockWidgetContent"));
        gridLayout_2 = new QGridLayout(dockWidgetContent);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QToolButton(dockWidgetContent);
        addButton->setObjectName(QStringLiteral("addButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/cgal/icons/plus"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);

        horizontalLayout->addWidget(addButton);

        removeButton = new QToolButton(dockWidgetContent);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cgal/icons/minus"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon1);

        horizontalLayout->addWidget(removeButton);

        duplicateButton = new QToolButton(dockWidgetContent);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cgal/icons/duplicate"), QSize(), QIcon::Normal, QIcon::Off);
        duplicateButton->setIcon(icon2);

        horizontalLayout->addWidget(duplicateButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchEdit = new QLineEdit(dockWidgetContent);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        horizontalLayout->addWidget(searchEdit);


        verticalLayout->addLayout(horizontalLayout);

        sceneView = new QTreeView(dockWidgetContent);
        sceneView->setObjectName(QStringLiteral("sceneView"));
        sceneView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        sceneView->setAlternatingRowColors(true);
        sceneView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        sceneView->setIndentation(0);

        verticalLayout->addWidget(sceneView);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        sceneDockWidget->setWidget(dockWidgetContent);
        consoleDockWidget = new QDockWidget(centralwidget);
        consoleDockWidget->setObjectName(QStringLiteral("consoleDockWidget"));
        consoleDockWidget->setGeometry(QRect(30, 370, 417, 240));
        consoleDockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        consoleTextEdit = new QTextEdit(dockWidgetContents);
        consoleTextEdit->setObjectName(QStringLiteral("consoleTextEdit"));
        consoleTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(consoleTextEdit);

        consoleDockWidget->setWidget(dockWidgetContents);
        viewer = new Viewer(centralwidget);
        viewer->setObjectName(QStringLiteral("viewer"));
        viewer->setGeometry(QRect(460, 40, 639, 276));
        sizePolicy.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy);
        CGALWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CGALWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1532, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuMesh = new QMenu(menubar);
        menuMesh->setObjectName(QStringLiteral("menuMesh"));
        menuModel_Geometry = new QMenu(menubar);
        menuModel_Geometry->setObjectName(QStringLiteral("menuModel_Geometry"));
        menuPCL = new QMenu(menubar);
        menuPCL->setObjectName(QStringLiteral("menuPCL"));
        CGALWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CGALWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CGALWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMesh->menuAction());
        menubar->addAction(menuModel_Geometry->menuAction());
        menubar->addAction(menuPCL->menuAction());
        menuFile->addAction(actionLoad);

        retranslateUi(CGALWindow);

        QMetaObject::connectSlotsByName(CGALWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CGALWindow)
    {
        CGALWindow->setWindowTitle(QApplication::translate("CGALWindow", "MainWindow", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("CGALWindow", "Load", Q_NULLPTR));
        infoDockWidget->setWindowTitle(QApplication::translate("CGALWindow", "Infos", Q_NULLPTR));
        displayLabel->setText(QString());
        sceneDockWidget->setWindowTitle(QApplication::translate("CGALWindow", "Geometric Objects", Q_NULLPTR));
        addButton->setText(QApplication::translate("CGALWindow", "+", Q_NULLPTR));
        removeButton->setText(QApplication::translate("CGALWindow", "-", Q_NULLPTR));
        duplicateButton->setText(QApplication::translate("CGALWindow", "...", Q_NULLPTR));
        searchEdit->setPlaceholderText(QApplication::translate("CGALWindow", "Quick filter... <Alt+Q>", Q_NULLPTR));
        consoleDockWidget->setWindowTitle(QApplication::translate("CGALWindow", "Console", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("CGALWindow", "File", Q_NULLPTR));
        menuMesh->setTitle(QApplication::translate("CGALWindow", "Mesh", Q_NULLPTR));
        menuModel_Geometry->setTitle(QApplication::translate("CGALWindow", "Model Geometry", Q_NULLPTR));
        menuPCL->setTitle(QApplication::translate("CGALWindow", "PCL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CGALWindow: public Ui_CGALWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGALWINDOW_H
