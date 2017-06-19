/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include "Viewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionSimplify;
    QAction *actionCatmullClark;
    QAction *actionKernel;
    QAction *actionUnion;
    QAction *actionIntersection;
    QAction *actionDifference;
    QAction *actionFitPlane;
    QAction *actionFitLine;
    QAction *actionEstimateCurvature;
    QAction *actionLoad;
    QAction *actionErase;
    QAction *actionDuplicate;
    QAction *actionSqrt3;
    QAction *actionAntiAliasing;
    QAction *dummyAction;
    QAction *actionConvexHull;
    QAction *actionEraseAll;
    QAction *actionOptions;
    QAction *actionLoop;
    QAction *actionSaveAs;
    QAction *actionSave;
    QAction *actionSaveAll;
    QAction *actionMergeAll;
    QAction *actionMerge;
    QAction *actionSelfIntersection;
    QAction *actionSelectAll;
    QAction *actionSelectNone;
    QAction *actionSelectInvert;
    QAction *actionShowHide;
    QAction *actionSetPolyhedronA;
    QAction *actionSetPolyhedronB;
    QAction *actionInsideOut;
    QAction *actionRemeshing;
    QAction *actionConvexDecomposition;
    QAction *actionMVC;
    QAction *actionDCP;
    QAction *actionExplode;
    QAction *actionToNef;
    QAction *actionToPoly;
    QAction *actionDraw_two_sides;
    QAction *actionRecenterScene;
    QAction *actionSetBackgroundColor;
    QAction *actionMinkowskiSum;
    QAction *action_Look_at;
    QAction *actionSaveSnapshot;
    QAction *actionDumpCamera;
    QAction *action_Copy_camera;
    QAction *action_Paste_camera;
    QAction *actionSelect_all_items;
    QAction *actionLoad_Script;
    QAction *actionPreferences;
    QAction *actionCircumference;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    Viewer *viewer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuOperations;
    QMenu *menuSubdivision;
    QMenu *menu_Boolean_operations;
    QMenu *menuParameterization;
    QMenu *menuPCA;
    QMenu *menuView;
    QMenu *menuDockWindows;
    QMenu *menuCamera;
    QStatusBar *statusbar;
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
    QDockWidget *infoDockWidget;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *infoLabel;
    QLabel *displayLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(978, 594);
        QIcon icon;
        icon.addFile(QStringLiteral(":/cgal/icons/resources/cgal_logo.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSimplify = new QAction(MainWindow);
        actionSimplify->setObjectName(QStringLiteral("actionSimplify"));
        actionCatmullClark = new QAction(MainWindow);
        actionCatmullClark->setObjectName(QStringLiteral("actionCatmullClark"));
        actionKernel = new QAction(MainWindow);
        actionKernel->setObjectName(QStringLiteral("actionKernel"));
        actionUnion = new QAction(MainWindow);
        actionUnion->setObjectName(QStringLiteral("actionUnion"));
        actionIntersection = new QAction(MainWindow);
        actionIntersection->setObjectName(QStringLiteral("actionIntersection"));
        actionDifference = new QAction(MainWindow);
        actionDifference->setObjectName(QStringLiteral("actionDifference"));
        actionFitPlane = new QAction(MainWindow);
        actionFitPlane->setObjectName(QStringLiteral("actionFitPlane"));
        actionFitLine = new QAction(MainWindow);
        actionFitLine->setObjectName(QStringLiteral("actionFitLine"));
        actionEstimateCurvature = new QAction(MainWindow);
        actionEstimateCurvature->setObjectName(QStringLiteral("actionEstimateCurvature"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cgal/icons/plus"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon1);
        actionErase = new QAction(MainWindow);
        actionErase->setObjectName(QStringLiteral("actionErase"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cgal/icons/minus"), QSize(), QIcon::Normal, QIcon::Off);
        actionErase->setIcon(icon2);
        actionDuplicate = new QAction(MainWindow);
        actionDuplicate->setObjectName(QStringLiteral("actionDuplicate"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/cgal/icons/duplicate"), QSize(), QIcon::Normal, QIcon::Off);
        actionDuplicate->setIcon(icon3);
        actionSqrt3 = new QAction(MainWindow);
        actionSqrt3->setObjectName(QStringLiteral("actionSqrt3"));
        actionAntiAliasing = new QAction(MainWindow);
        actionAntiAliasing->setObjectName(QStringLiteral("actionAntiAliasing"));
        actionAntiAliasing->setCheckable(true);
        dummyAction = new QAction(MainWindow);
        dummyAction->setObjectName(QStringLiteral("dummyAction"));
        actionConvexHull = new QAction(MainWindow);
        actionConvexHull->setObjectName(QStringLiteral("actionConvexHull"));
        actionEraseAll = new QAction(MainWindow);
        actionEraseAll->setObjectName(QStringLiteral("actionEraseAll"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionLoop = new QAction(MainWindow);
        actionLoop->setObjectName(QStringLiteral("actionLoop"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAll = new QAction(MainWindow);
        actionSaveAll->setObjectName(QStringLiteral("actionSaveAll"));
        actionMergeAll = new QAction(MainWindow);
        actionMergeAll->setObjectName(QStringLiteral("actionMergeAll"));
        actionMerge = new QAction(MainWindow);
        actionMerge->setObjectName(QStringLiteral("actionMerge"));
        actionSelfIntersection = new QAction(MainWindow);
        actionSelfIntersection->setObjectName(QStringLiteral("actionSelfIntersection"));
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionSelectNone = new QAction(MainWindow);
        actionSelectNone->setObjectName(QStringLiteral("actionSelectNone"));
        actionSelectInvert = new QAction(MainWindow);
        actionSelectInvert->setObjectName(QStringLiteral("actionSelectInvert"));
        actionShowHide = new QAction(MainWindow);
        actionShowHide->setObjectName(QStringLiteral("actionShowHide"));
        actionSetPolyhedronA = new QAction(MainWindow);
        actionSetPolyhedronA->setObjectName(QStringLiteral("actionSetPolyhedronA"));
        actionSetPolyhedronB = new QAction(MainWindow);
        actionSetPolyhedronB->setObjectName(QStringLiteral("actionSetPolyhedronB"));
        actionInsideOut = new QAction(MainWindow);
        actionInsideOut->setObjectName(QStringLiteral("actionInsideOut"));
        actionRemeshing = new QAction(MainWindow);
        actionRemeshing->setObjectName(QStringLiteral("actionRemeshing"));
        actionConvexDecomposition = new QAction(MainWindow);
        actionConvexDecomposition->setObjectName(QStringLiteral("actionConvexDecomposition"));
        actionMVC = new QAction(MainWindow);
        actionMVC->setObjectName(QStringLiteral("actionMVC"));
        actionDCP = new QAction(MainWindow);
        actionDCP->setObjectName(QStringLiteral("actionDCP"));
        actionExplode = new QAction(MainWindow);
        actionExplode->setObjectName(QStringLiteral("actionExplode"));
        actionToNef = new QAction(MainWindow);
        actionToNef->setObjectName(QStringLiteral("actionToNef"));
        actionToPoly = new QAction(MainWindow);
        actionToPoly->setObjectName(QStringLiteral("actionToPoly"));
        actionDraw_two_sides = new QAction(MainWindow);
        actionDraw_two_sides->setObjectName(QStringLiteral("actionDraw_two_sides"));
        actionDraw_two_sides->setCheckable(true);
        actionRecenterScene = new QAction(MainWindow);
        actionRecenterScene->setObjectName(QStringLiteral("actionRecenterScene"));
        actionSetBackgroundColor = new QAction(MainWindow);
        actionSetBackgroundColor->setObjectName(QStringLiteral("actionSetBackgroundColor"));
        actionMinkowskiSum = new QAction(MainWindow);
        actionMinkowskiSum->setObjectName(QStringLiteral("actionMinkowskiSum"));
        action_Look_at = new QAction(MainWindow);
        action_Look_at->setObjectName(QStringLiteral("action_Look_at"));
        actionSaveSnapshot = new QAction(MainWindow);
        actionSaveSnapshot->setObjectName(QStringLiteral("actionSaveSnapshot"));
        actionDumpCamera = new QAction(MainWindow);
        actionDumpCamera->setObjectName(QStringLiteral("actionDumpCamera"));
        action_Copy_camera = new QAction(MainWindow);
        action_Copy_camera->setObjectName(QStringLiteral("action_Copy_camera"));
        action_Paste_camera = new QAction(MainWindow);
        action_Paste_camera->setObjectName(QStringLiteral("action_Paste_camera"));
        actionSelect_all_items = new QAction(MainWindow);
        actionSelect_all_items->setObjectName(QStringLiteral("actionSelect_all_items"));
        actionLoad_Script = new QAction(MainWindow);
        actionLoad_Script->setObjectName(QStringLiteral("actionLoad_Script"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionCircumference = new QAction(MainWindow);
        actionCircumference->setObjectName(QStringLiteral("actionCircumference"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        viewer = new Viewer(centralwidget);
        viewer->setObjectName(QStringLiteral("viewer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(viewer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 978, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuOperations = new QMenu(menubar);
        menuOperations->setObjectName(QStringLiteral("menuOperations"));
        menuSubdivision = new QMenu(menuOperations);
        menuSubdivision->setObjectName(QStringLiteral("menuSubdivision"));
        menu_Boolean_operations = new QMenu(menuOperations);
        menu_Boolean_operations->setObjectName(QStringLiteral("menu_Boolean_operations"));
        menuParameterization = new QMenu(menuOperations);
        menuParameterization->setObjectName(QStringLiteral("menuParameterization"));
        menuPCA = new QMenu(menuOperations);
        menuPCA->setObjectName(QStringLiteral("menuPCA"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuDockWindows = new QMenu(menuView);
        menuDockWindows->setObjectName(QStringLiteral("menuDockWindows"));
        menuCamera = new QMenu(menuView);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        sceneDockWidget = new QDockWidget(MainWindow);
        sceneDockWidget->setObjectName(QStringLiteral("sceneDockWidget"));
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
        addButton->setIcon(icon1);

        horizontalLayout->addWidget(addButton);

        removeButton = new QToolButton(dockWidgetContent);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setIcon(icon2);

        horizontalLayout->addWidget(removeButton);

        duplicateButton = new QToolButton(dockWidgetContent);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
        duplicateButton->setIcon(icon3);

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
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), sceneDockWidget);
        consoleDockWidget = new QDockWidget(MainWindow);
        consoleDockWidget->setObjectName(QStringLiteral("consoleDockWidget"));
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
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), consoleDockWidget);
        infoDockWidget = new QDockWidget(MainWindow);
        infoDockWidget->setObjectName(QStringLiteral("infoDockWidget"));
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
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), infoDockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuOperations->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionErase);
        menuFile->addAction(actionEraseAll);
        menuFile->addAction(actionDuplicate);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionSaveSnapshot);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad_Script);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionShowHide);
        menuEdit->addAction(actionSetPolyhedronA);
        menuEdit->addAction(actionSetPolyhedronB);
        menuEdit->addAction(actionSelect_all_items);
        menuEdit->addAction(actionPreferences);
        menuOperations->addAction(menuPCA->menuAction());
        menuOperations->addAction(actionEstimateCurvature);
        menuOperations->addAction(actionSelfIntersection);
        menuOperations->addAction(actionConvexHull);
        menuOperations->addAction(actionKernel);
        menuOperations->addAction(menuSubdivision->menuAction());
        menuOperations->addAction(actionSimplify);
        menuOperations->addAction(actionRemeshing);
        menuOperations->addAction(actionConvexDecomposition);
        menuOperations->addAction(menu_Boolean_operations->menuAction());
        menuOperations->addAction(menuParameterization->menuAction());
        menuOperations->addAction(actionInsideOut);
        menuSubdivision->addAction(actionLoop);
        menuSubdivision->addAction(actionCatmullClark);
        menuSubdivision->addAction(actionSqrt3);
        menu_Boolean_operations->addAction(actionToNef);
        menu_Boolean_operations->addAction(actionToPoly);
        menu_Boolean_operations->addAction(actionUnion);
        menu_Boolean_operations->addAction(actionIntersection);
        menu_Boolean_operations->addAction(actionDifference);
        menu_Boolean_operations->addSeparator();
        menu_Boolean_operations->addAction(actionMinkowskiSum);
        menuParameterization->addAction(actionMVC);
        menuParameterization->addAction(actionDCP);
        menuPCA->addAction(actionFitLine);
        menuPCA->addAction(actionFitPlane);
        menuView->addAction(actionRecenterScene);
        menuView->addAction(action_Look_at);
        menuView->addAction(actionAntiAliasing);
        menuView->addAction(actionDraw_two_sides);
        menuView->addAction(actionSetBackgroundColor);
        menuView->addAction(menuDockWindows->menuAction());
        menuView->addAction(menuCamera->menuAction());
        menuDockWindows->addAction(dummyAction);
        menuCamera->addAction(actionDumpCamera);
        menuCamera->addAction(action_Copy_camera);
        menuCamera->addAction(action_Paste_camera);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CGAL Polyhedron demo", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionSimplify->setText(QApplication::translate("MainWindow", "&Simplification", Q_NULLPTR));
        actionCatmullClark->setText(QApplication::translate("MainWindow", "&Catmull-Clark", Q_NULLPTR));
        actionKernel->setText(QApplication::translate("MainWindow", "&Kernel", Q_NULLPTR));
        actionUnion->setText(QApplication::translate("MainWindow", "&Union (A/B)", Q_NULLPTR));
        actionUnion->setShortcut(QApplication::translate("MainWindow", "Ctrl+O, U", Q_NULLPTR));
        actionIntersection->setText(QApplication::translate("MainWindow", "&Intersection (A/B)", Q_NULLPTR));
        actionIntersection->setShortcut(QApplication::translate("MainWindow", "Ctrl+O, I", Q_NULLPTR));
        actionDifference->setText(QApplication::translate("MainWindow", "&Difference (A/B)", Q_NULLPTR));
        actionDifference->setShortcut(QApplication::translate("MainWindow", "Ctrl+O, D", Q_NULLPTR));
        actionFitPlane->setText(QApplication::translate("MainWindow", "Fit &plane", Q_NULLPTR));
        actionFitLine->setText(QApplication::translate("MainWindow", "Fit &line", Q_NULLPTR));
        actionEstimateCurvature->setText(QApplication::translate("MainWindow", "&Curvature estimation", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "&Load...", Q_NULLPTR));
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
        actionErase->setText(QApplication::translate("MainWindow", "&Erase", Q_NULLPTR));
        actionErase->setShortcut(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        actionDuplicate->setText(QApplication::translate("MainWindow", "&Duplicate", Q_NULLPTR));
        actionDuplicate->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
        actionSqrt3->setText(QApplication::translate("MainWindow", "&Sqrt3", Q_NULLPTR));
        actionAntiAliasing->setText(QApplication::translate("MainWindow", "&Antialiasing", Q_NULLPTR));
        dummyAction->setText(QApplication::translate("MainWindow", "n/a", Q_NULLPTR));
        actionConvexHull->setText(QApplication::translate("MainWindow", "&Convex hull", Q_NULLPTR));
        actionEraseAll->setText(QApplication::translate("MainWindow", "&Erase all", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("MainWindow", "&Options...", Q_NULLPTR));
        actionLoop->setText(QApplication::translate("MainWindow", "&Loop", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save &as...", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
        actionSaveAll->setText(QApplication::translate("MainWindow", "Save a&ll", Q_NULLPTR));
        actionMergeAll->setText(QApplication::translate("MainWindow", "Mer&ge all", Q_NULLPTR));
        actionMerge->setText(QApplication::translate("MainWindow", "&Merge", Q_NULLPTR));
        actionSelfIntersection->setText(QApplication::translate("MainWindow", "Self-&intersection", Q_NULLPTR));
        actionSelectAll->setText(QApplication::translate("MainWindow", "Select &all", Q_NULLPTR));
        actionSelectNone->setText(QApplication::translate("MainWindow", "Select &none", Q_NULLPTR));
        actionSelectInvert->setText(QApplication::translate("MainWindow", "&Invert selection", Q_NULLPTR));
        actionShowHide->setText(QApplication::translate("MainWindow", "Show/Hide", Q_NULLPTR));
        actionShowHide->setShortcut(QApplication::translate("MainWindow", "Ctrl+Space", Q_NULLPTR));
        actionSetPolyhedronA->setText(QApplication::translate("MainWindow", "Set polyhedron A", Q_NULLPTR));
        actionSetPolyhedronB->setText(QApplication::translate("MainWindow", "Set polyhedron B", Q_NULLPTR));
        actionInsideOut->setText(QApplication::translate("MainWindow", "&Inside-out", Q_NULLPTR));
        actionRemeshing->setText(QApplication::translate("MainWindow", "&Remeshing", Q_NULLPTR));
        actionConvexDecomposition->setText(QApplication::translate("MainWindow", "Convex Decomposition", Q_NULLPTR));
        actionMVC->setText(QApplication::translate("MainWindow", "Mean &value coordinates", Q_NULLPTR));
        actionDCP->setText(QApplication::translate("MainWindow", "Discrete &conformal maps", Q_NULLPTR));
        actionExplode->setText(QApplication::translate("MainWindow", "Explode", Q_NULLPTR));
        actionToNef->setText(QApplication::translate("MainWindow", "Convert to nef polyhedron", Q_NULLPTR));
        actionToPoly->setText(QApplication::translate("MainWindow", "Convert to normal polyhedron", Q_NULLPTR));
        actionDraw_two_sides->setText(QApplication::translate("MainWindow", "Draw &two sides", Q_NULLPTR));
        actionDraw_two_sides->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
        actionRecenterScene->setText(QApplication::translate("MainWindow", "Re&center scene", Q_NULLPTR));
        actionRecenterScene->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        actionSetBackgroundColor->setText(QApplication::translate("MainWindow", "Change &background color...", Q_NULLPTR));
        actionMinkowskiSum->setText(QApplication::translate("MainWindow", "&Minkowski sum (A/B)", Q_NULLPTR));
        actionMinkowskiSum->setShortcut(QApplication::translate("MainWindow", "Ctrl+O, M", Q_NULLPTR));
        action_Look_at->setText(QApplication::translate("MainWindow", "&Look at...", Q_NULLPTR));
        actionSaveSnapshot->setText(QApplication::translate("MainWindow", "Save snapshot", Q_NULLPTR));
        actionDumpCamera->setText(QApplication::translate("MainWindow", "&Dump camera coordinates", Q_NULLPTR));
        action_Copy_camera->setText(QApplication::translate("MainWindow", "&Copy camera", Q_NULLPTR));
        action_Paste_camera->setText(QApplication::translate("MainWindow", "&Paste camera", Q_NULLPTR));
        actionSelect_all_items->setText(QApplication::translate("MainWindow", "Select all items", Q_NULLPTR));
        actionSelect_all_items->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
        actionLoad_Script->setText(QApplication::translate("MainWindow", "Load &script", Q_NULLPTR));
        actionPreferences->setText(QApplication::translate("MainWindow", "&Preferences", Q_NULLPTR));
        actionCircumference->setText(QApplication::translate("MainWindow", "Circumference", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menuOperations->setTitle(QApplication::translate("MainWindow", "&Operations", Q_NULLPTR));
        menuSubdivision->setTitle(QApplication::translate("MainWindow", "&Subdivision", Q_NULLPTR));
        menu_Boolean_operations->setTitle(QApplication::translate("MainWindow", "&Boolean operations", Q_NULLPTR));
        menuParameterization->setTitle(QApplication::translate("MainWindow", "Parameterization", Q_NULLPTR));
        menuPCA->setTitle(QApplication::translate("MainWindow", "PCA", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", Q_NULLPTR));
        menuDockWindows->setTitle(QApplication::translate("MainWindow", "&Dock windows", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("MainWindow", "Ca&mera", Q_NULLPTR));
        sceneDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Geometric Objects", Q_NULLPTR));
        addButton->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        removeButton->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        duplicateButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        searchEdit->setPlaceholderText(QApplication::translate("MainWindow", "Quick filter... <Alt+Q>", Q_NULLPTR));
        consoleDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Console", Q_NULLPTR));
        infoDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Infos", Q_NULLPTR));
        displayLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
