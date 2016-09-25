/********************************************************************************
** Form generated from reading UI file 'cybele.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYBELE_H
#define UI_CYBELE_H

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

class Ui_Cybele
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
    QMenu *menuAntropometria;
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

    void setupUi(QMainWindow *Cybele)
    {
        if (Cybele->objectName().isEmpty())
            Cybele->setObjectName(QStringLiteral("Cybele"));
        Cybele->setWindowModality(Qt::ApplicationModal);
        Cybele->resize(1280, 960);
        actionQuit = new QAction(Cybele);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSimplify = new QAction(Cybele);
        actionSimplify->setObjectName(QStringLiteral("actionSimplify"));
        actionCatmullClark = new QAction(Cybele);
        actionCatmullClark->setObjectName(QStringLiteral("actionCatmullClark"));
        actionKernel = new QAction(Cybele);
        actionKernel->setObjectName(QStringLiteral("actionKernel"));
        actionUnion = new QAction(Cybele);
        actionUnion->setObjectName(QStringLiteral("actionUnion"));
        actionIntersection = new QAction(Cybele);
        actionIntersection->setObjectName(QStringLiteral("actionIntersection"));
        actionDifference = new QAction(Cybele);
        actionDifference->setObjectName(QStringLiteral("actionDifference"));
        actionFitPlane = new QAction(Cybele);
        actionFitPlane->setObjectName(QStringLiteral("actionFitPlane"));
        actionFitLine = new QAction(Cybele);
        actionFitLine->setObjectName(QStringLiteral("actionFitLine"));
        actionEstimateCurvature = new QAction(Cybele);
        actionEstimateCurvature->setObjectName(QStringLiteral("actionEstimateCurvature"));
        actionLoad = new QAction(Cybele);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/cgal/icons/plus"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon);
        actionErase = new QAction(Cybele);
        actionErase->setObjectName(QStringLiteral("actionErase"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cgal/icons/minus"), QSize(), QIcon::Normal, QIcon::Off);
        actionErase->setIcon(icon1);
        actionDuplicate = new QAction(Cybele);
        actionDuplicate->setObjectName(QStringLiteral("actionDuplicate"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cgal/icons/duplicate"), QSize(), QIcon::Normal, QIcon::Off);
        actionDuplicate->setIcon(icon2);
        actionSqrt3 = new QAction(Cybele);
        actionSqrt3->setObjectName(QStringLiteral("actionSqrt3"));
        actionAntiAliasing = new QAction(Cybele);
        actionAntiAliasing->setObjectName(QStringLiteral("actionAntiAliasing"));
        actionAntiAliasing->setCheckable(true);
        dummyAction = new QAction(Cybele);
        dummyAction->setObjectName(QStringLiteral("dummyAction"));
        actionConvexHull = new QAction(Cybele);
        actionConvexHull->setObjectName(QStringLiteral("actionConvexHull"));
        actionEraseAll = new QAction(Cybele);
        actionEraseAll->setObjectName(QStringLiteral("actionEraseAll"));
        actionOptions = new QAction(Cybele);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionLoop = new QAction(Cybele);
        actionLoop->setObjectName(QStringLiteral("actionLoop"));
        actionSaveAs = new QAction(Cybele);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSave = new QAction(Cybele);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAll = new QAction(Cybele);
        actionSaveAll->setObjectName(QStringLiteral("actionSaveAll"));
        actionMergeAll = new QAction(Cybele);
        actionMergeAll->setObjectName(QStringLiteral("actionMergeAll"));
        actionMerge = new QAction(Cybele);
        actionMerge->setObjectName(QStringLiteral("actionMerge"));
        actionSelfIntersection = new QAction(Cybele);
        actionSelfIntersection->setObjectName(QStringLiteral("actionSelfIntersection"));
        actionSelectAll = new QAction(Cybele);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionSelectNone = new QAction(Cybele);
        actionSelectNone->setObjectName(QStringLiteral("actionSelectNone"));
        actionSelectInvert = new QAction(Cybele);
        actionSelectInvert->setObjectName(QStringLiteral("actionSelectInvert"));
        actionShowHide = new QAction(Cybele);
        actionShowHide->setObjectName(QStringLiteral("actionShowHide"));
        actionSetPolyhedronA = new QAction(Cybele);
        actionSetPolyhedronA->setObjectName(QStringLiteral("actionSetPolyhedronA"));
        actionSetPolyhedronB = new QAction(Cybele);
        actionSetPolyhedronB->setObjectName(QStringLiteral("actionSetPolyhedronB"));
        actionInsideOut = new QAction(Cybele);
        actionInsideOut->setObjectName(QStringLiteral("actionInsideOut"));
        actionRemeshing = new QAction(Cybele);
        actionRemeshing->setObjectName(QStringLiteral("actionRemeshing"));
        actionConvexDecomposition = new QAction(Cybele);
        actionConvexDecomposition->setObjectName(QStringLiteral("actionConvexDecomposition"));
        actionMVC = new QAction(Cybele);
        actionMVC->setObjectName(QStringLiteral("actionMVC"));
        actionDCP = new QAction(Cybele);
        actionDCP->setObjectName(QStringLiteral("actionDCP"));
        actionExplode = new QAction(Cybele);
        actionExplode->setObjectName(QStringLiteral("actionExplode"));
        actionToNef = new QAction(Cybele);
        actionToNef->setObjectName(QStringLiteral("actionToNef"));
        actionToPoly = new QAction(Cybele);
        actionToPoly->setObjectName(QStringLiteral("actionToPoly"));
        actionDraw_two_sides = new QAction(Cybele);
        actionDraw_two_sides->setObjectName(QStringLiteral("actionDraw_two_sides"));
        actionDraw_two_sides->setCheckable(true);
        actionRecenterScene = new QAction(Cybele);
        actionRecenterScene->setObjectName(QStringLiteral("actionRecenterScene"));
        actionSetBackgroundColor = new QAction(Cybele);
        actionSetBackgroundColor->setObjectName(QStringLiteral("actionSetBackgroundColor"));
        actionMinkowskiSum = new QAction(Cybele);
        actionMinkowskiSum->setObjectName(QStringLiteral("actionMinkowskiSum"));
        action_Look_at = new QAction(Cybele);
        action_Look_at->setObjectName(QStringLiteral("action_Look_at"));
        actionSaveSnapshot = new QAction(Cybele);
        actionSaveSnapshot->setObjectName(QStringLiteral("actionSaveSnapshot"));
        actionDumpCamera = new QAction(Cybele);
        actionDumpCamera->setObjectName(QStringLiteral("actionDumpCamera"));
        action_Copy_camera = new QAction(Cybele);
        action_Copy_camera->setObjectName(QStringLiteral("action_Copy_camera"));
        action_Paste_camera = new QAction(Cybele);
        action_Paste_camera->setObjectName(QStringLiteral("action_Paste_camera"));
        actionSelect_all_items = new QAction(Cybele);
        actionSelect_all_items->setObjectName(QStringLiteral("actionSelect_all_items"));
        actionLoad_Script = new QAction(Cybele);
        actionLoad_Script->setObjectName(QStringLiteral("actionLoad_Script"));
        actionPreferences = new QAction(Cybele);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        centralwidget = new QWidget(Cybele);
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

        Cybele->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Cybele);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
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
        menuAntropometria = new QMenu(menubar);
        menuAntropometria->setObjectName(QStringLiteral("menuAntropometria"));
        Cybele->setMenuBar(menubar);
        statusbar = new QStatusBar(Cybele);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Cybele->setStatusBar(statusbar);
        sceneDockWidget = new QDockWidget(Cybele);
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
        addButton->setIcon(icon);

        horizontalLayout->addWidget(addButton);

        removeButton = new QToolButton(dockWidgetContent);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setIcon(icon1);

        horizontalLayout->addWidget(removeButton);

        duplicateButton = new QToolButton(dockWidgetContent);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
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
        Cybele->addDockWidget(static_cast<Qt::DockWidgetArea>(1), sceneDockWidget);
        consoleDockWidget = new QDockWidget(Cybele);
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
        Cybele->addDockWidget(static_cast<Qt::DockWidgetArea>(8), consoleDockWidget);
        infoDockWidget = new QDockWidget(Cybele);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 712, 174));
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
        Cybele->addDockWidget(static_cast<Qt::DockWidgetArea>(8), infoDockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuOperations->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuAntropometria->menuAction());
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

        retranslateUi(Cybele);

        QMetaObject::connectSlotsByName(Cybele);
    } // setupUi

    void retranslateUi(QMainWindow *Cybele)
    {
        Cybele->setWindowTitle(QApplication::translate("Cybele", "Cybele", 0));
        actionQuit->setText(QApplication::translate("Cybele", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("Cybele", "Ctrl+Q", 0));
        actionSimplify->setText(QApplication::translate("Cybele", "&Simplification", 0));
        actionCatmullClark->setText(QApplication::translate("Cybele", "&Catmull-Clark", 0));
        actionKernel->setText(QApplication::translate("Cybele", "&Kernel", 0));
        actionUnion->setText(QApplication::translate("Cybele", "&Union (A/B)", 0));
        actionUnion->setShortcut(QApplication::translate("Cybele", "Ctrl+O, U", 0));
        actionIntersection->setText(QApplication::translate("Cybele", "&Intersection (A/B)", 0));
        actionIntersection->setShortcut(QApplication::translate("Cybele", "Ctrl+O, I", 0));
        actionDifference->setText(QApplication::translate("Cybele", "&Difference (A/B)", 0));
        actionDifference->setShortcut(QApplication::translate("Cybele", "Ctrl+O, D", 0));
        actionFitPlane->setText(QApplication::translate("Cybele", "Fit &plane", 0));
        actionFitLine->setText(QApplication::translate("Cybele", "Fit &line", 0));
        actionEstimateCurvature->setText(QApplication::translate("Cybele", "&Curvature estimation", 0));
        actionLoad->setText(QApplication::translate("Cybele", "&Load...", 0));
        actionLoad->setShortcut(QApplication::translate("Cybele", "Ctrl+L", 0));
        actionErase->setText(QApplication::translate("Cybele", "&Erase", 0));
        actionErase->setShortcut(QApplication::translate("Cybele", "Del", 0));
        actionDuplicate->setText(QApplication::translate("Cybele", "&Duplicate", 0));
        actionDuplicate->setShortcut(QApplication::translate("Cybele", "Ctrl+D", 0));
        actionSqrt3->setText(QApplication::translate("Cybele", "&Sqrt3", 0));
        actionAntiAliasing->setText(QApplication::translate("Cybele", "&Antialiasing", 0));
        dummyAction->setText(QApplication::translate("Cybele", "n/a", 0));
        actionConvexHull->setText(QApplication::translate("Cybele", "&Convex hull", 0));
        actionEraseAll->setText(QApplication::translate("Cybele", "&Erase all", 0));
        actionOptions->setText(QApplication::translate("Cybele", "&Options...", 0));
        actionLoop->setText(QApplication::translate("Cybele", "&Loop", 0));
        actionSaveAs->setText(QApplication::translate("Cybele", "Save &as...", 0));
        actionSave->setText(QApplication::translate("Cybele", "&Save", 0));
        actionSaveAll->setText(QApplication::translate("Cybele", "Save a&ll", 0));
        actionMergeAll->setText(QApplication::translate("Cybele", "Mer&ge all", 0));
        actionMerge->setText(QApplication::translate("Cybele", "&Merge", 0));
        actionSelfIntersection->setText(QApplication::translate("Cybele", "Self-&intersection", 0));
        actionSelectAll->setText(QApplication::translate("Cybele", "Select &all", 0));
        actionSelectNone->setText(QApplication::translate("Cybele", "Select &none", 0));
        actionSelectInvert->setText(QApplication::translate("Cybele", "&Invert selection", 0));
        actionShowHide->setText(QApplication::translate("Cybele", "Show/Hide", 0));
        actionShowHide->setShortcut(QApplication::translate("Cybele", "Ctrl+Space", 0));
        actionSetPolyhedronA->setText(QApplication::translate("Cybele", "Set polyhedron A", 0));
        actionSetPolyhedronB->setText(QApplication::translate("Cybele", "Set polyhedron B", 0));
        actionInsideOut->setText(QApplication::translate("Cybele", "&Inside-out", 0));
        actionRemeshing->setText(QApplication::translate("Cybele", "&Remeshing", 0));
        actionConvexDecomposition->setText(QApplication::translate("Cybele", "Convex Decomposition", 0));
        actionMVC->setText(QApplication::translate("Cybele", "Mean &value coordinates", 0));
        actionDCP->setText(QApplication::translate("Cybele", "Discrete &conformal maps", 0));
        actionExplode->setText(QApplication::translate("Cybele", "Explode", 0));
        actionToNef->setText(QApplication::translate("Cybele", "Convert to nef polyhedron", 0));
        actionToPoly->setText(QApplication::translate("Cybele", "Convert to normal polyhedron", 0));
        actionDraw_two_sides->setText(QApplication::translate("Cybele", "Draw &two sides", 0));
        actionDraw_two_sides->setShortcut(QApplication::translate("Cybele", "Ctrl+T", 0));
        actionRecenterScene->setText(QApplication::translate("Cybele", "Re&center scene", 0));
        actionRecenterScene->setShortcut(QApplication::translate("Cybele", "Ctrl+C", 0));
        actionSetBackgroundColor->setText(QApplication::translate("Cybele", "Change &background color...", 0));
        actionMinkowskiSum->setText(QApplication::translate("Cybele", "&Minkowski sum (A/B)", 0));
        actionMinkowskiSum->setShortcut(QApplication::translate("Cybele", "Ctrl+O, M", 0));
        action_Look_at->setText(QApplication::translate("Cybele", "&Look at...", 0));
        actionSaveSnapshot->setText(QApplication::translate("Cybele", "Save snapshot", 0));
        actionDumpCamera->setText(QApplication::translate("Cybele", "&Dump camera coordinates", 0));
        action_Copy_camera->setText(QApplication::translate("Cybele", "&Copy camera", 0));
        action_Paste_camera->setText(QApplication::translate("Cybele", "&Paste camera", 0));
        actionSelect_all_items->setText(QApplication::translate("Cybele", "Select all items", 0));
        actionSelect_all_items->setShortcut(QApplication::translate("Cybele", "Ctrl+A", 0));
        actionLoad_Script->setText(QApplication::translate("Cybele", "Load &script", 0));
        actionPreferences->setText(QApplication::translate("Cybele", "&Preferences", 0));
        menuFile->setTitle(QApplication::translate("Cybele", "&File", 0));
        menuEdit->setTitle(QApplication::translate("Cybele", "&Edit", 0));
        menuOperations->setTitle(QApplication::translate("Cybele", "&Operations", 0));
        menuSubdivision->setTitle(QApplication::translate("Cybele", "&Subdivision", 0));
        menu_Boolean_operations->setTitle(QApplication::translate("Cybele", "&Boolean operations", 0));
        menuParameterization->setTitle(QApplication::translate("Cybele", "Parameterization", 0));
        menuPCA->setTitle(QApplication::translate("Cybele", "PCA", 0));
        menuView->setTitle(QApplication::translate("Cybele", "&View", 0));
        menuDockWindows->setTitle(QApplication::translate("Cybele", "&Dock windows", 0));
        menuCamera->setTitle(QApplication::translate("Cybele", "Ca&mera", 0));
        menuAntropometria->setTitle(QApplication::translate("Cybele", "Antropometria", 0));
        sceneDockWidget->setWindowTitle(QApplication::translate("Cybele", "Geometric Objects", 0));
        addButton->setText(QApplication::translate("Cybele", "+", 0));
        removeButton->setText(QApplication::translate("Cybele", "-", 0));
        duplicateButton->setText(QApplication::translate("Cybele", "...", 0));
        searchEdit->setPlaceholderText(QApplication::translate("Cybele", "Quick filter... <Alt+Q>", 0));
        consoleDockWidget->setWindowTitle(QApplication::translate("Cybele", "Console", 0));
        infoDockWidget->setWindowTitle(QApplication::translate("Cybele", "Infos", 0));
        displayLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cybele: public Ui_Cybele {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYBELE_H
