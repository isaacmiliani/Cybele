/********************************************************************************
** Form generated from reading UI file 'cybele.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYBELE_H
#define UI_CYBELE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "viewer.h"

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
    QLabel *infoLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *addButton;
    QToolButton *removeButton;
    QToolButton *duplicateButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QTreeView *sceneView;
    Viewer *viewer;
    QTreeView *sceneView_2;
    QWidget *gridLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    Viewer *viewer_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *addButtonRight;
    QToolButton *removeButtonRight;
    QToolButton *duplicateButtonRight;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *searchEditRight;
    QWidget *gridLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_selection;
    QPushButton *btn_CircunCintura;
    QPushButton *btn_CircunCadera;
    QPushButton *btn_DiamFemur;
    QPushButton *btn_CircunBrazoIzq;
    QPushButton *btn_CircunCefalica;
    QPushButton *btn_Talla;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_selection_2;
    QPushButton *btn_CircunCadera_2;
    QPushButton *btn_CircunBrazoIzq_2;
    QPushButton *btn_DiamFemur_2;
    QPushButton *btn_CircunCintura_2;
    QPushButton *btn_CircunCefalica_2;
    QPushButton *btn_Talla_2;
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
    QDockWidget *consoleDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_3;
    QLineEdit *lineEdit;
    QFrame *line_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *lbl_talla;
    QLabel *lbl_CircunCefalica;
    QLabel *lbl_CircunBrazoIzq;
    QLabel *lbl_CircunCintura;
    QLabel *lbl_CircunCadera;
    QLabel *lbl_MusloIzq;
    QLabel *lbl_DiamMuneca;
    QLabel *lbl_DiamFemur;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *displayLabel;
    QFrame *line_3;
    QTextEdit *consoleTextEdit;

    void setupUi(QMainWindow *Cybele)
    {
        if (Cybele->objectName().isEmpty())
            Cybele->setObjectName(QStringLiteral("Cybele"));
        Cybele->setWindowModality(Qt::ApplicationModal);
        Cybele->resize(1730, 940);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cybele->sizePolicy().hasHeightForWidth());
        Cybele->setSizePolicy(sizePolicy);
        Cybele->setMaximumSize(QSize(16777215, 16777215));
        Cybele->setContextMenuPolicy(Qt::ActionsContextMenu);
        Cybele->setAutoFillBackground(false);
        Cybele->setStyleSheet(QLatin1String("font: 75 8pt \"Segoe UI\";\n"
"background-color: rgb(239, 244, 255);\n"
""));
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
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QStringLiteral(""));
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(10, 830, 1511, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy1);
        infoLabel->setContextMenuPolicy(Qt::DefaultContextMenu);
        infoLabel->setLineWidth(0);
        infoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        infoLabel->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 700, 176, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QToolButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setStyleSheet(QStringLiteral("border:0px;"));
        addButton->setIcon(icon);

        horizontalLayout->addWidget(addButton);

        removeButton = new QToolButton(layoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setStyleSheet(QStringLiteral("border:0px;"));
        removeButton->setIcon(icon1);

        horizontalLayout->addWidget(removeButton);

        duplicateButton = new QToolButton(layoutWidget);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
        duplicateButton->setStyleSheet(QStringLiteral("border:0px;"));
        duplicateButton->setIcon(icon2);

        horizontalLayout->addWidget(duplicateButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchEdit = new QLineEdit(layoutWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        horizontalLayout->addWidget(searchEdit);

        sceneView = new QTreeView(centralwidget);
        sceneView->setObjectName(QStringLiteral("sceneView"));
        sceneView->setEnabled(true);
        sceneView->setGeometry(QRect(10, 730, 581, 81));
        sceneView->setFrameShape(QFrame::Panel);
        sceneView->setFrameShadow(QFrame::Plain);
        sceneView->setLineWidth(0);
        sceneView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        sceneView->setAlternatingRowColors(false);
        sceneView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        sceneView->setIndentation(0);
        viewer = new Viewer(centralwidget);
        viewer->setObjectName(QStringLiteral("viewer"));
        viewer->setGeometry(QRect(10, 0, 731, 691));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy2);
        viewer->setAutoFillBackground(false);
        viewer->setStyleSheet(QLatin1String("background-color: rgb(239, 244, 255,0);\n"
""));
        sceneView_2 = new QTreeView(centralwidget);
        sceneView_2->setObjectName(QStringLiteral("sceneView_2"));
        sceneView_2->setEnabled(true);
        sceneView_2->setGeometry(QRect(780, 730, 741, 71));
        sceneView_2->setFrameShape(QFrame::Panel);
        sceneView_2->setFrameShadow(QFrame::Plain);
        sceneView_2->setLineWidth(0);
        sceneView_2->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        sceneView_2->setAlternatingRowColors(false);
        sceneView_2->setSelectionMode(QAbstractItemView::ExtendedSelection);
        sceneView_2->setIndentation(0);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(250, 0, 337, 52));
        horizontalLayout_2 = new QHBoxLayout(gridLayoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy3);
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(185, 29, 71);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(185, 29, 71);"));
        pushButton_3->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(50, 50));
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(185, 29, 71);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_2->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QLatin1String("background-color: rgb(185, 29, 71);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_4->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(50, 50));
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(159, 0, 167);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_7->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_7);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(50, 50));
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QLatin1String("background-color: rgb(159, 0, 167);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_5->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(50, 50));
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setStyleSheet(QLatin1String("background-color: rgb(159, 0, 167);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_6->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_6);

        viewer_2 = new Viewer(centralwidget);
        viewer_2->setObjectName(QStringLiteral("viewer_2"));
        viewer_2->setGeometry(QRect(780, 0, 741, 691));
        sizePolicy2.setHeightForWidth(viewer_2->sizePolicy().hasHeightForWidth());
        viewer_2->setSizePolicy(sizePolicy2);
        viewer_2->setAutoFillBackground(false);
        viewer_2->setStyleSheet(QStringLiteral(""));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(780, 700, 176, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        addButtonRight = new QToolButton(layoutWidget_2);
        addButtonRight->setObjectName(QStringLiteral("addButtonRight"));
        addButtonRight->setStyleSheet(QStringLiteral("border:0px;"));
        addButtonRight->setIcon(icon);

        horizontalLayout_3->addWidget(addButtonRight);

        removeButtonRight = new QToolButton(layoutWidget_2);
        removeButtonRight->setObjectName(QStringLiteral("removeButtonRight"));
        removeButtonRight->setStyleSheet(QStringLiteral("border:0px;"));
        removeButtonRight->setIcon(icon1);

        horizontalLayout_3->addWidget(removeButtonRight);

        duplicateButtonRight = new QToolButton(layoutWidget_2);
        duplicateButtonRight->setObjectName(QStringLiteral("duplicateButtonRight"));
        duplicateButtonRight->setStyleSheet(QStringLiteral("border:0px;"));
        duplicateButtonRight->setIcon(icon2);

        horizontalLayout_3->addWidget(duplicateButtonRight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        searchEditRight = new QLineEdit(layoutWidget_2);
        searchEditRight->setObjectName(QStringLiteral("searchEditRight"));

        horizontalLayout_3->addWidget(searchEditRight);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(970, 0, 337, 52));
        horizontalLayout_4 = new QHBoxLayout(gridLayoutWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(gridLayoutWidget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy3.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy3);
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(50, 50));
        pushButton_8->setAutoFillBackground(false);
        pushButton_8->setStyleSheet(QLatin1String("background-color: rgb(185, 29, 71);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(185, 29, 71);"));
        pushButton_8->setFlat(false);

        horizontalLayout_4->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(gridLayoutWidget_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy3.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy3);
        pushButton_9->setMinimumSize(QSize(50, 50));
        pushButton_9->setMaximumSize(QSize(50, 50));
        pushButton_9->setAutoFillBackground(false);
        pushButton_9->setStyleSheet(QLatin1String("background-color: rgb(185, 29, 71);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_9->setFlat(false);

        horizontalLayout_4->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(gridLayoutWidget_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(50, 50));
        pushButton_10->setMaximumSize(QSize(50, 50));
        pushButton_10->setAutoFillBackground(false);
        pushButton_10->setStyleSheet(QLatin1String("background-color: rgb(185, 29, 71);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_10->setFlat(false);

        horizontalLayout_4->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(gridLayoutWidget_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(50, 50));
        pushButton_11->setMaximumSize(QSize(50, 50));
        pushButton_11->setAutoFillBackground(false);
        pushButton_11->setStyleSheet(QLatin1String("background-color: rgb(159, 0, 167);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_11->setFlat(false);

        horizontalLayout_4->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(gridLayoutWidget_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(50, 50));
        pushButton_12->setMaximumSize(QSize(50, 50));
        pushButton_12->setAutoFillBackground(false);
        pushButton_12->setStyleSheet(QLatin1String("background-color: rgb(159, 0, 167);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_12->setFlat(false);

        horizontalLayout_4->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(gridLayoutWidget_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(50, 50));
        pushButton_13->setMaximumSize(QSize(50, 50));
        pushButton_13->setAutoFillBackground(false);
        pushButton_13->setStyleSheet(QLatin1String("background-color: rgb(159, 0, 167);\n"
"font: 87 12pt \"Segoe UI Black\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_13->setFlat(false);

        horizontalLayout_4->addWidget(pushButton_13);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 160, 464));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_selection = new QPushButton(verticalLayoutWidget);
        btn_selection->setObjectName(QStringLiteral("btn_selection"));
        btn_selection->setMinimumSize(QSize(0, 60));
        btn_selection->setAutoFillBackground(false);
        btn_selection->setStyleSheet(QLatin1String("background-color: rgb(227, 162, 26);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_selection->setFlat(false);

        verticalLayout->addWidget(btn_selection);

        btn_CircunCintura = new QPushButton(verticalLayoutWidget);
        btn_CircunCintura->setObjectName(QStringLiteral("btn_CircunCintura"));
        btn_CircunCintura->setMinimumSize(QSize(0, 60));
        btn_CircunCintura->setAutoFillBackground(false);
        btn_CircunCintura->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_CircunCintura->setCheckable(false);
        btn_CircunCintura->setFlat(false);

        verticalLayout->addWidget(btn_CircunCintura);

        btn_CircunCadera = new QPushButton(verticalLayoutWidget);
        btn_CircunCadera->setObjectName(QStringLiteral("btn_CircunCadera"));
        btn_CircunCadera->setMinimumSize(QSize(0, 60));
        btn_CircunCadera->setAutoFillBackground(false);
        btn_CircunCadera->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_CircunCadera->setFlat(false);

        verticalLayout->addWidget(btn_CircunCadera);

        btn_DiamFemur = new QPushButton(verticalLayoutWidget);
        btn_DiamFemur->setObjectName(QStringLiteral("btn_DiamFemur"));
        btn_DiamFemur->setMinimumSize(QSize(0, 60));
        btn_DiamFemur->setAutoFillBackground(false);
        btn_DiamFemur->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_DiamFemur->setFlat(false);

        verticalLayout->addWidget(btn_DiamFemur);

        btn_CircunBrazoIzq = new QPushButton(verticalLayoutWidget);
        btn_CircunBrazoIzq->setObjectName(QStringLiteral("btn_CircunBrazoIzq"));
        btn_CircunBrazoIzq->setMinimumSize(QSize(0, 60));
        btn_CircunBrazoIzq->setAutoFillBackground(false);
        btn_CircunBrazoIzq->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 8pt \"Segoe UI\";"));
        btn_CircunBrazoIzq->setFlat(false);

        verticalLayout->addWidget(btn_CircunBrazoIzq);

        btn_CircunCefalica = new QPushButton(verticalLayoutWidget);
        btn_CircunCefalica->setObjectName(QStringLiteral("btn_CircunCefalica"));
        btn_CircunCefalica->setMinimumSize(QSize(0, 60));
        btn_CircunCefalica->setAutoFillBackground(false);
        btn_CircunCefalica->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 8pt \"Segoe UI\";"));
        btn_CircunCefalica->setFlat(false);

        verticalLayout->addWidget(btn_CircunCefalica);

        btn_Talla = new QPushButton(verticalLayoutWidget);
        btn_Talla->setObjectName(QStringLiteral("btn_Talla"));
        btn_Talla->setMinimumSize(QSize(0, 60));
        btn_Talla->setAutoFillBackground(false);
        btn_Talla->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 8pt \"Segoe UI\";"));
        btn_Talla->setFlat(false);

        verticalLayout->addWidget(btn_Talla);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1360, 0, 160, 464));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_selection_2 = new QPushButton(verticalLayoutWidget_2);
        btn_selection_2->setObjectName(QStringLiteral("btn_selection_2"));
        btn_selection_2->setMinimumSize(QSize(0, 60));
        btn_selection_2->setAutoFillBackground(false);
        btn_selection_2->setStyleSheet(QLatin1String("background-color: rgb(227, 162, 26);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_selection_2->setFlat(false);

        verticalLayout_3->addWidget(btn_selection_2);

        btn_CircunCadera_2 = new QPushButton(verticalLayoutWidget_2);
        btn_CircunCadera_2->setObjectName(QStringLiteral("btn_CircunCadera_2"));
        btn_CircunCadera_2->setMinimumSize(QSize(0, 60));
        btn_CircunCadera_2->setAutoFillBackground(false);
        btn_CircunCadera_2->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_CircunCadera_2->setFlat(false);

        verticalLayout_3->addWidget(btn_CircunCadera_2);

        btn_CircunBrazoIzq_2 = new QPushButton(verticalLayoutWidget_2);
        btn_CircunBrazoIzq_2->setObjectName(QStringLiteral("btn_CircunBrazoIzq_2"));
        btn_CircunBrazoIzq_2->setMinimumSize(QSize(0, 60));
        btn_CircunBrazoIzq_2->setAutoFillBackground(false);
        btn_CircunBrazoIzq_2->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 8pt \"Segoe UI\";"));
        btn_CircunBrazoIzq_2->setFlat(false);

        verticalLayout_3->addWidget(btn_CircunBrazoIzq_2);

        btn_DiamFemur_2 = new QPushButton(verticalLayoutWidget_2);
        btn_DiamFemur_2->setObjectName(QStringLiteral("btn_DiamFemur_2"));
        btn_DiamFemur_2->setMinimumSize(QSize(0, 60));
        btn_DiamFemur_2->setAutoFillBackground(false);
        btn_DiamFemur_2->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_DiamFemur_2->setFlat(false);

        verticalLayout_3->addWidget(btn_DiamFemur_2);

        btn_CircunCintura_2 = new QPushButton(verticalLayoutWidget_2);
        btn_CircunCintura_2->setObjectName(QStringLiteral("btn_CircunCintura_2"));
        btn_CircunCintura_2->setMinimumSize(QSize(0, 60));
        btn_CircunCintura_2->setAutoFillBackground(false);
        btn_CircunCintura_2->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        btn_CircunCintura_2->setCheckable(false);
        btn_CircunCintura_2->setFlat(false);

        verticalLayout_3->addWidget(btn_CircunCintura_2);

        btn_CircunCefalica_2 = new QPushButton(verticalLayoutWidget_2);
        btn_CircunCefalica_2->setObjectName(QStringLiteral("btn_CircunCefalica_2"));
        btn_CircunCefalica_2->setMinimumSize(QSize(0, 60));
        btn_CircunCefalica_2->setAutoFillBackground(false);
        btn_CircunCefalica_2->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 8pt \"Segoe UI\";"));
        btn_CircunCefalica_2->setFlat(false);

        verticalLayout_3->addWidget(btn_CircunCefalica_2);

        btn_Talla_2 = new QPushButton(verticalLayoutWidget_2);
        btn_Talla_2->setObjectName(QStringLiteral("btn_Talla_2"));
        btn_Talla_2->setMinimumSize(QSize(0, 60));
        btn_Talla_2->setAutoFillBackground(false);
        btn_Talla_2->setStyleSheet(QLatin1String("background-color: rgb(0, 171, 169);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 8pt \"Segoe UI\";"));
        btn_Talla_2->setFlat(false);

        verticalLayout_3->addWidget(btn_Talla_2);

        Cybele->setCentralWidget(centralwidget);
        viewer->raise();
        viewer_2->raise();
        infoLabel->raise();
        layoutWidget->raise();
        sceneView->raise();
        sceneView_2->raise();
        gridLayoutWidget->raise();
        layoutWidget_2->raise();
        gridLayoutWidget_2->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        menubar = new QMenuBar(Cybele);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1730, 23));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy4);
        menubar->setAutoFillBackground(false);
        menubar->setStyleSheet(QStringLiteral("selection-color: rgb(0, 85, 0);"));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(false);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(menuFile->sizePolicy().hasHeightForWidth());
        menuFile->setSizePolicy(sizePolicy5);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        menuFile->setFont(font);
        menuFile->setContextMenuPolicy(Qt::ActionsContextMenu);
        menuFile->setAutoFillBackground(false);
        menuFile->setStyleSheet(QStringLiteral(""));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setStyleSheet(QStringLiteral(""));
        menuOperations = new QMenu(menubar);
        menuOperations->setObjectName(QStringLiteral("menuOperations"));
        menuOperations->setContextMenuPolicy(Qt::ActionsContextMenu);
        menuOperations->setStyleSheet(QStringLiteral(""));
        menuSubdivision = new QMenu(menuOperations);
        menuSubdivision->setObjectName(QStringLiteral("menuSubdivision"));
        menuSubdivision->setStyleSheet(QStringLiteral(""));
        menu_Boolean_operations = new QMenu(menuOperations);
        menu_Boolean_operations->setObjectName(QStringLiteral("menu_Boolean_operations"));
        menu_Boolean_operations->setStyleSheet(QStringLiteral(""));
        menuParameterization = new QMenu(menuOperations);
        menuParameterization->setObjectName(QStringLiteral("menuParameterization"));
        menuPCA = new QMenu(menuOperations);
        menuPCA->setObjectName(QStringLiteral("menuPCA"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuView->setStyleSheet(QStringLiteral(""));
        menuDockWindows = new QMenu(menuView);
        menuDockWindows->setObjectName(QStringLiteral("menuDockWindows"));
        menuCamera = new QMenu(menuView);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        Cybele->setMenuBar(menubar);
        statusbar = new QStatusBar(Cybele);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Cybele->setStatusBar(statusbar);
        consoleDockWidget = new QDockWidget(Cybele);
        consoleDockWidget->setObjectName(QStringLiteral("consoleDockWidget"));
        consoleDockWidget->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(consoleDockWidget->sizePolicy().hasHeightForWidth());
        consoleDockWidget->setSizePolicy(sizePolicy6);
        consoleDockWidget->setMinimumSize(QSize(200, 787));
        consoleDockWidget->setMaximumSize(QSize(200, 524287));
        consoleDockWidget->setContextMenuPolicy(Qt::NoContextMenu);
        consoleDockWidget->setStyleSheet(QStringLiteral(""));
        consoleDockWidget->setFloating(false);
        consoleDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetContents->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        lineEdit = new QLineEdit(dockWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, lineEdit);

        line_2 = new QFrame(dockWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, line_2);

        lineEdit_2 = new QLineEdit(dockWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(dockWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(dockWidgetContents);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, lineEdit_4);

        lineEdit_5 = new QLineEdit(dockWidgetContents);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, lineEdit_5);

        lbl_talla = new QLabel(dockWidgetContents);
        lbl_talla->setObjectName(QStringLiteral("lbl_talla"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, lbl_talla);

        lbl_CircunCefalica = new QLabel(dockWidgetContents);
        lbl_CircunCefalica->setObjectName(QStringLiteral("lbl_CircunCefalica"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, lbl_CircunCefalica);

        lbl_CircunBrazoIzq = new QLabel(dockWidgetContents);
        lbl_CircunBrazoIzq->setObjectName(QStringLiteral("lbl_CircunBrazoIzq"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, lbl_CircunBrazoIzq);

        lbl_CircunCintura = new QLabel(dockWidgetContents);
        lbl_CircunCintura->setObjectName(QStringLiteral("lbl_CircunCintura"));

        formLayout_3->setWidget(9, QFormLayout::LabelRole, lbl_CircunCintura);

        lbl_CircunCadera = new QLabel(dockWidgetContents);
        lbl_CircunCadera->setObjectName(QStringLiteral("lbl_CircunCadera"));

        formLayout_3->setWidget(10, QFormLayout::LabelRole, lbl_CircunCadera);

        lbl_MusloIzq = new QLabel(dockWidgetContents);
        lbl_MusloIzq->setObjectName(QStringLiteral("lbl_MusloIzq"));

        formLayout_3->setWidget(11, QFormLayout::LabelRole, lbl_MusloIzq);

        lbl_DiamMuneca = new QLabel(dockWidgetContents);
        lbl_DiamMuneca->setObjectName(QStringLiteral("lbl_DiamMuneca"));

        formLayout_3->setWidget(12, QFormLayout::LabelRole, lbl_DiamMuneca);

        lbl_DiamFemur = new QLabel(dockWidgetContents);
        lbl_DiamFemur->setObjectName(QStringLiteral("lbl_DiamFemur"));

        formLayout_3->setWidget(13, QFormLayout::LabelRole, lbl_DiamFemur);

        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(227, 162, 26);\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";"));
        pushButton->setFlat(false);

        formLayout_3->setWidget(14, QFormLayout::LabelRole, pushButton);

        line = new QFrame(dockWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_3->setWidget(16, QFormLayout::LabelRole, line);


        verticalLayout_2->addLayout(formLayout_3);

        displayLabel = new QLabel(dockWidgetContents);
        displayLabel->setObjectName(QStringLiteral("displayLabel"));

        verticalLayout_2->addWidget(displayLabel);

        line_3 = new QFrame(dockWidgetContents);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        consoleTextEdit = new QTextEdit(dockWidgetContents);
        consoleTextEdit->setObjectName(QStringLiteral("consoleTextEdit"));
        consoleTextEdit->setFrameShape(QFrame::Panel);
        consoleTextEdit->setFrameShadow(QFrame::Plain);
        consoleTextEdit->setLineWidth(0);
        consoleTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(consoleTextEdit);

        consoleDockWidget->setWidget(dockWidgetContents);
        Cybele->addDockWidget(static_cast<Qt::DockWidgetArea>(1), consoleDockWidget);
        consoleDockWidget->raise();

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuOperations->menuAction());
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
        addButton->setText(QApplication::translate("Cybele", "+", 0));
        removeButton->setText(QApplication::translate("Cybele", "-", 0));
        duplicateButton->setText(QApplication::translate("Cybele", "...", 0));
        searchEdit->setPlaceholderText(QApplication::translate("Cybele", "Quick filter... <Alt+Q>", 0));
        pushButton_3->setText(QApplication::translate("Cybele", "W", 0));
        pushButton_2->setText(QApplication::translate("Cybele", "P", 0));
        pushButton_4->setText(QApplication::translate("Cybele", "S", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("Cybele", "Light", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("Cybele", "A", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Cybele", "Light", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Cybele", "L", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("Cybele", "Light", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("Cybele", "G", 0));
        addButtonRight->setText(QApplication::translate("Cybele", "+", 0));
        removeButtonRight->setText(QApplication::translate("Cybele", "-", 0));
        duplicateButtonRight->setText(QApplication::translate("Cybele", "...", 0));
        searchEditRight->setPlaceholderText(QApplication::translate("Cybele", "Quick filter... <Alt+Q>", 0));
        pushButton_8->setText(QApplication::translate("Cybele", "W", 0));
        pushButton_9->setText(QApplication::translate("Cybele", "P", 0));
        pushButton_10->setText(QApplication::translate("Cybele", "S", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("Cybele", "Light", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("Cybele", "A", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("Cybele", "Light", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("Cybele", "L", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("Cybele", "Light", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("Cybele", "G", 0));
        btn_selection->setText(QApplication::translate("Cybele", "SELECCIONAR \n"
"PUNTOS", 0));
        btn_CircunCintura->setText(QApplication::translate("Cybele", "CIRCUNFERENCIA \n"
"CINTURA", 0));
        btn_CircunCadera->setText(QApplication::translate("Cybele", "CADERA", 0));
        btn_DiamFemur->setText(QApplication::translate("Cybele", " FEMUR", 0));
        btn_CircunBrazoIzq->setText(QApplication::translate("Cybele", "CIRCUNFERENCIA \n"
"BRAZO", 0));
        btn_CircunCefalica->setText(QApplication::translate("Cybele", "CIRCUNFERENCIA \n"
"CEFALICA", 0));
        btn_Talla->setText(QApplication::translate("Cybele", "TALLA", 0));
        btn_selection_2->setText(QApplication::translate("Cybele", "SELECCIONAR \n"
"PUNTOS", 0));
        btn_CircunCadera_2->setText(QApplication::translate("Cybele", "CADERA", 0));
        btn_CircunBrazoIzq_2->setText(QApplication::translate("Cybele", "CIRCUNFERENCIA \n"
"BRAZO", 0));
        btn_DiamFemur_2->setText(QApplication::translate("Cybele", " FEMUR", 0));
        btn_CircunCintura_2->setText(QApplication::translate("Cybele", "CIRCUNFERENCIA \n"
"CINTURA", 0));
        btn_CircunCefalica_2->setText(QApplication::translate("Cybele", "CIRCUNFERENCIA \n"
"CEFALICA", 0));
        btn_Talla_2->setText(QApplication::translate("Cybele", "TALLA", 0));
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
        consoleDockWidget->setWindowTitle(QString());
        lineEdit->setPlaceholderText(QApplication::translate("Cybele", "Buscar...", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("Cybele", "Nombre", 0));
        lineEdit_3->setPlaceholderText(QApplication::translate("Cybele", "Apellido", 0));
        lineEdit_4->setPlaceholderText(QApplication::translate("Cybele", "Edad", 0));
        lineEdit_5->setPlaceholderText(QApplication::translate("Cybele", "C.I", 0));
        lbl_talla->setText(QApplication::translate("Cybele", "Talla", 0));
        lbl_CircunCefalica->setText(QApplication::translate("Cybele", "Circunferencia Cefalica", 0));
        lbl_CircunBrazoIzq->setText(QApplication::translate("Cybele", "Circunferencia Brazo Izquierdo", 0));
        lbl_CircunCintura->setText(QApplication::translate("Cybele", "Circunferencia Cintura", 0));
        lbl_CircunCadera->setText(QApplication::translate("Cybele", "Circunferencia Cadera", 0));
        lbl_MusloIzq->setText(QApplication::translate("Cybele", "Circunferencia Muslo Izquierdo", 0));
        lbl_DiamMuneca->setText(QApplication::translate("Cybele", "Circunferencia Mu\303\261eca", 0));
        lbl_DiamFemur->setText(QApplication::translate("Cybele", "Femur", 0));
        pushButton->setText(QApplication::translate("Cybele", "Guardar", 0));
        displayLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cybele: public Ui_Cybele {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYBELE_H
