/********************************************************************************
** Form generated from reading UI file 'cybele.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYBELE_H
#define UI_CYBELE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"
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
    QWidget *mainWidget;
    QFrame *repair_frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *left_frame;
    QVBoxLayout *verticalLayout_7;
    QCommandLinkButton *open_file_btn;
    QFrame *line_3;
    QGroupBox *gb_CropBoxDials;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_4;
    QDial *dial_x_n;
    QDial *dial_x;
    QLabel *label1_3;
    QLabel *label1_2;
    QDial *dial_z_n;
    QDial *dial_y;
    QLabel *label1;
    QDial *dial_y_n;
    QDial *dial_z;
    QLabel *label1_5;
    QLabel *label1_4;
    QLabel *label1_6;
    QCommandLinkButton *crop_box;
    QFrame *line_4;
    QCommandLinkButton *btnExtraerMedidas;
    QSpacerItem *verticalSpacer;
    QFrame *frame_progress;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_processing;
    QProgressBar *progressBar;
    QVTKWidget *qvtkWidget;
    QFrame *frame_right;
    QVBoxLayout *verticalLayout_5;
    Viewer *viewer_right;
    QFrame *frame_left;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btn_selection;
    QPushButton *btn_CircunBrazoIzq;
    QPushButton *btn_CircunCadera;
    QPushButton *btn_DiamFemur;
    QPushButton *btn_CircunCintura;
    QFrame *line_2;
    QPushButton *cmd_buscarmodelo_1;
    QPushButton *compare_btn;
    QPushButton *historial_btn;
    QPushButton *cmd_savemodel;
    Viewer *viewer;
    QFrame *frame_viewer;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFrame *line_5;
    QFrame *frame_medidas;
    QVBoxLayout *verticalLayout_8;
    QTreeView *sceneView;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_comparacion;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QFrame *line;
    QComboBox *cbo_modelos;
    QTreeView *sceneView_right;
    QLabel *label;
    QFrame *line_6;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *dif_cintura;
    QLabel *dif_wrist;
    QLabel *dif_cadera;
    QLabel *label_7;
    QLabel *fecha_captura_r;
    QLabel *dif_brazo;
    QLabel *lbl_fecha_captura_r;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_datos_paciente;
    QLabel *lblDatosPaciente;
    QFrame *line_7;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *lbl_cedula;
    QLabel *lbl_nombre;
    QLabel *label_6;
    QLabel *lbl_apellido;
    QLabel *lbl_fecha_nacimiento;
    QLabel *lbl_fecha_captura;
    QLabel *label_12;
    QFrame *frame_progress2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_processing2;
    QProgressBar *progressBar_2;
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

    void setupUi(QMainWindow *Cybele)
    {
        if (Cybele->objectName().isEmpty())
            Cybele->setObjectName(QStringLiteral("Cybele"));
        Cybele->setWindowModality(Qt::ApplicationModal);
        Cybele->resize(1751, 1051);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cybele->sizePolicy().hasHeightForWidth());
        Cybele->setSizePolicy(sizePolicy);
        Cybele->setMaximumSize(QSize(16777215, 16777215));
        Cybele->setContextMenuPolicy(Qt::ActionsContextMenu);
        Cybele->setAutoFillBackground(false);
        Cybele->setStyleSheet(QLatin1String("font: 75 8pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);\n"
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
        mainWidget = new QWidget(Cybele);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMaximumSize(QSize(1754, 1016));
        repair_frame = new QFrame(mainWidget);
        repair_frame->setObjectName(QStringLiteral("repair_frame"));
        repair_frame->setGeometry(QRect(0, 0, 1750, 1021));
        repair_frame->setFrameShape(QFrame::StyledPanel);
        repair_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(repair_frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        left_frame = new QFrame(repair_frame);
        left_frame->setObjectName(QStringLiteral("left_frame"));
        left_frame->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(left_frame->sizePolicy().hasHeightForWidth());
        left_frame->setSizePolicy(sizePolicy1);
        left_frame->setMinimumSize(QSize(0, 0));
        left_frame->setMaximumSize(QSize(16777215, 16777215));
        left_frame->setFrameShape(QFrame::NoFrame);
        left_frame->setFrameShadow(QFrame::Plain);
        left_frame->setLineWidth(0);
        verticalLayout_7 = new QVBoxLayout(left_frame);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        open_file_btn = new QCommandLinkButton(left_frame);
        open_file_btn->setObjectName(QStringLiteral("open_file_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(open_file_btn->sizePolicy().hasHeightForWidth());
        open_file_btn->setSizePolicy(sizePolicy2);
        open_file_btn->setMinimumSize(QSize(0, 0));
        open_file_btn->setStyleSheet(QLatin1String("font: 87 10pt \"Segoe UI\";\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/cgal/icons/resources/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        open_file_btn->setIcon(icon3);
        open_file_btn->setIconSize(QSize(27, 20));

        verticalLayout_7->addWidget(open_file_btn);

        line_3 = new QFrame(left_frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        gb_CropBoxDials = new QGroupBox(left_frame);
        gb_CropBoxDials->setObjectName(QStringLiteral("gb_CropBoxDials"));
        sizePolicy1.setHeightForWidth(gb_CropBoxDials->sizePolicy().hasHeightForWidth());
        gb_CropBoxDials->setSizePolicy(sizePolicy1);
        verticalLayout_6 = new QVBoxLayout(gb_CropBoxDials);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        dial_x_n = new QDial(gb_CropBoxDials);
        dial_x_n->setObjectName(QStringLiteral("dial_x_n"));
        dial_x_n->setMinimumSize(QSize(60, 60));
        dial_x_n->setMaximumSize(QSize(60, 60));
        dial_x_n->setMinimum(-400);
        dial_x_n->setMaximum(0);
        dial_x_n->setPageStep(1);
        dial_x_n->setValue(0);

        gridLayout_4->addWidget(dial_x_n, 1, 1, 1, 1);

        dial_x = new QDial(gb_CropBoxDials);
        dial_x->setObjectName(QStringLiteral("dial_x"));
        dial_x->setMinimumSize(QSize(60, 60));
        dial_x->setMaximumSize(QSize(60, 60));
        dial_x->setMinimum(0);
        dial_x->setMaximum(400);
        dial_x->setSingleStep(1);
        dial_x->setPageStep(1);
        dial_x->setOrientation(Qt::Horizontal);
        dial_x->setInvertedAppearance(false);
        dial_x->setInvertedControls(false);

        gridLayout_4->addWidget(dial_x, 1, 0, 1, 1);

        label1_3 = new QLabel(gb_CropBoxDials);
        label1_3->setObjectName(QStringLiteral("label1_3"));
        label1_3->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";\n"
""));

        gridLayout_4->addWidget(label1_3, 4, 0, 1, 1);

        label1_2 = new QLabel(gb_CropBoxDials);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";\n"
""));

        gridLayout_4->addWidget(label1_2, 2, 0, 1, 1);

        dial_z_n = new QDial(gb_CropBoxDials);
        dial_z_n->setObjectName(QStringLiteral("dial_z_n"));
        dial_z_n->setMinimumSize(QSize(60, 60));
        dial_z_n->setMaximumSize(QSize(60, 60));
        dial_z_n->setMinimum(-400);
        dial_z_n->setMaximum(0);
        dial_z_n->setPageStep(1);
        dial_z_n->setValue(0);

        gridLayout_4->addWidget(dial_z_n, 5, 1, 1, 1);

        dial_y = new QDial(gb_CropBoxDials);
        dial_y->setObjectName(QStringLiteral("dial_y"));
        dial_y->setMinimumSize(QSize(60, 60));
        dial_y->setMaximumSize(QSize(60, 60));
        dial_y->setMaximum(400);
        dial_y->setPageStep(1);

        gridLayout_4->addWidget(dial_y, 3, 0, 1, 1);

        label1 = new QLabel(gb_CropBoxDials);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";\n"
""));

        gridLayout_4->addWidget(label1, 0, 0, 1, 1);

        dial_y_n = new QDial(gb_CropBoxDials);
        dial_y_n->setObjectName(QStringLiteral("dial_y_n"));
        dial_y_n->setMinimumSize(QSize(60, 60));
        dial_y_n->setMaximumSize(QSize(60, 60));
        dial_y_n->setMinimum(-400);
        dial_y_n->setMaximum(0);
        dial_y_n->setPageStep(1);
        dial_y_n->setValue(0);

        gridLayout_4->addWidget(dial_y_n, 3, 1, 1, 1);

        dial_z = new QDial(gb_CropBoxDials);
        dial_z->setObjectName(QStringLiteral("dial_z"));
        dial_z->setMinimumSize(QSize(60, 60));
        dial_z->setMaximumSize(QSize(60, 60));
        dial_z->setMaximum(400);
        dial_z->setPageStep(1);

        gridLayout_4->addWidget(dial_z, 5, 0, 1, 1);

        label1_5 = new QLabel(gb_CropBoxDials);
        label1_5->setObjectName(QStringLiteral("label1_5"));
        label1_5->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";\n"
""));

        gridLayout_4->addWidget(label1_5, 0, 1, 1, 1);

        label1_4 = new QLabel(gb_CropBoxDials);
        label1_4->setObjectName(QStringLiteral("label1_4"));
        label1_4->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";\n"
""));

        gridLayout_4->addWidget(label1_4, 2, 1, 1, 1);

        label1_6 = new QLabel(gb_CropBoxDials);
        label1_6->setObjectName(QStringLiteral("label1_6"));
        label1_6->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";\n"
""));

        gridLayout_4->addWidget(label1_6, 4, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);

        crop_box = new QCommandLinkButton(gb_CropBoxDials);
        crop_box->setObjectName(QStringLiteral("crop_box"));
        sizePolicy2.setHeightForWidth(crop_box->sizePolicy().hasHeightForWidth());
        crop_box->setSizePolicy(sizePolicy2);
        crop_box->setLayoutDirection(Qt::LeftToRight);
        crop_box->setStyleSheet(QLatin1String("font: 87 10pt \"Segoe UI\";\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/cgal/icons/icons/Pictures/Icons/_BoundingBox.png"), QSize(), QIcon::Normal, QIcon::Off);
        crop_box->setIcon(icon4);

        verticalLayout_6->addWidget(crop_box);


        verticalLayout_7->addWidget(gb_CropBoxDials);

        line_4 = new QFrame(left_frame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_4);

        btnExtraerMedidas = new QCommandLinkButton(left_frame);
        btnExtraerMedidas->setObjectName(QStringLiteral("btnExtraerMedidas"));
        sizePolicy2.setHeightForWidth(btnExtraerMedidas->sizePolicy().hasHeightForWidth());
        btnExtraerMedidas->setSizePolicy(sizePolicy2);
        btnExtraerMedidas->setLayoutDirection(Qt::LeftToRight);
        btnExtraerMedidas->setAutoFillBackground(false);
        btnExtraerMedidas->setStyleSheet(QLatin1String("font: 87 10pt \"Segoe UI\";\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/cgal/icons/icons/Pictures/Icons/_SuperimposeSpheres.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExtraerMedidas->setIcon(icon5);

        verticalLayout_7->addWidget(btnExtraerMedidas);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        frame_progress = new QFrame(left_frame);
        frame_progress->setObjectName(QStringLiteral("frame_progress"));
        frame_progress->setFrameShape(QFrame::StyledPanel);
        frame_progress->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_progress);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_processing = new QLabel(frame_progress);
        lbl_processing->setObjectName(QStringLiteral("lbl_processing"));
        lbl_processing->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        horizontalLayout_3->addWidget(lbl_processing);

        progressBar = new QProgressBar(frame_progress);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setValue(24);

        horizontalLayout_3->addWidget(progressBar);


        verticalLayout_7->addWidget(frame_progress);


        horizontalLayout_2->addWidget(left_frame);

        qvtkWidget = new QVTKWidget(repair_frame);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy3);
        qvtkWidget->setBaseSize(QSize(0, 0));
        qvtkWidget->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(qvtkWidget);

        frame_right = new QFrame(mainWidget);
        frame_right->setObjectName(QStringLiteral("frame_right"));
        frame_right->setGeometry(QRect(1050, 0, 700, 1000));
        frame_right->setStyleSheet(QStringLiteral("font: 87 10pt \"Segoe UI\";"));
        frame_right->setFrameShape(QFrame::StyledPanel);
        frame_right->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_right);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        viewer_right = new Viewer(frame_right);
        viewer_right->setObjectName(QStringLiteral("viewer_right"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(viewer_right->sizePolicy().hasHeightForWidth());
        viewer_right->setSizePolicy(sizePolicy4);
        viewer_right->setMinimumSize(QSize(0, 0));
        viewer_right->setAutoFillBackground(false);
        viewer_right->setStyleSheet(QStringLiteral(""));

        verticalLayout_5->addWidget(viewer_right);

        frame_left = new QFrame(mainWidget);
        frame_left->setObjectName(QStringLiteral("frame_left"));
        frame_left->setGeometry(QRect(0, 0, 1750, 1024));
        frame_left->setMinimumSize(QSize(0, 0));
        frame_left->setFrameShape(QFrame::StyledPanel);
        frame_left->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_left);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(frame_left);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(100, 0));
        frame->setMaximumSize(QSize(100, 16777215));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btn_selection = new QPushButton(frame);
        btn_selection->setObjectName(QStringLiteral("btn_selection"));
        btn_selection->setMinimumSize(QSize(72, 72));
        btn_selection->setAutoFillBackground(false);
        btn_selection->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));
        btn_selection->setFlat(false);

        verticalLayout_4->addWidget(btn_selection);

        btn_CircunBrazoIzq = new QPushButton(frame);
        btn_CircunBrazoIzq->setObjectName(QStringLiteral("btn_CircunBrazoIzq"));
        btn_CircunBrazoIzq->setMinimumSize(QSize(72, 72));
        btn_CircunBrazoIzq->setAutoFillBackground(false);
        btn_CircunBrazoIzq->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));
        btn_CircunBrazoIzq->setFlat(false);

        verticalLayout_4->addWidget(btn_CircunBrazoIzq);

        btn_CircunCadera = new QPushButton(frame);
        btn_CircunCadera->setObjectName(QStringLiteral("btn_CircunCadera"));
        btn_CircunCadera->setMinimumSize(QSize(72, 72));
        btn_CircunCadera->setAutoFillBackground(false);
        btn_CircunCadera->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));
        btn_CircunCadera->setFlat(false);

        verticalLayout_4->addWidget(btn_CircunCadera);

        btn_DiamFemur = new QPushButton(frame);
        btn_DiamFemur->setObjectName(QStringLiteral("btn_DiamFemur"));
        btn_DiamFemur->setMinimumSize(QSize(72, 72));
        btn_DiamFemur->setAutoFillBackground(false);
        btn_DiamFemur->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));
        btn_DiamFemur->setFlat(false);

        verticalLayout_4->addWidget(btn_DiamFemur);

        btn_CircunCintura = new QPushButton(frame);
        btn_CircunCintura->setObjectName(QStringLiteral("btn_CircunCintura"));
        btn_CircunCintura->setMinimumSize(QSize(72, 72));
        btn_CircunCintura->setAutoFillBackground(false);
        btn_CircunCintura->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));
        btn_CircunCintura->setCheckable(false);
        btn_CircunCintura->setFlat(false);

        verticalLayout_4->addWidget(btn_CircunCintura);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        cmd_buscarmodelo_1 = new QPushButton(frame);
        cmd_buscarmodelo_1->setObjectName(QStringLiteral("cmd_buscarmodelo_1"));
        cmd_buscarmodelo_1->setMaximumSize(QSize(72, 72));
        cmd_buscarmodelo_1->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));

        verticalLayout_4->addWidget(cmd_buscarmodelo_1);

        compare_btn = new QPushButton(frame);
        compare_btn->setObjectName(QStringLiteral("compare_btn"));
        compare_btn->setMaximumSize(QSize(72, 72));
        compare_btn->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));

        verticalLayout_4->addWidget(compare_btn);

        historial_btn = new QPushButton(frame);
        historial_btn->setObjectName(QStringLiteral("historial_btn"));
        historial_btn->setMaximumSize(QSize(72, 72));
        historial_btn->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));

        verticalLayout_4->addWidget(historial_btn);

        cmd_savemodel = new QPushButton(frame);
        cmd_savemodel->setObjectName(QStringLiteral("cmd_savemodel"));
        cmd_savemodel->setMaximumSize(QSize(72, 72));
        cmd_savemodel->setFocusPolicy(Qt::StrongFocus);
        cmd_savemodel->setStyleSheet(QLatin1String("background-color: rgb(192, 57, 43);\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
"color: rgb(255, 255, 255);\n"
"font: 63 8pt \"Segoe UI Semibold\";\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: red;\n"
" max-width:70px;\n"
" max-height:70px;\n"
" min-width:70px;\n"
" min-height:70px;"));

        verticalLayout_4->addWidget(cmd_savemodel);


        verticalLayout_2->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(frame);

        viewer = new Viewer(frame_left);
        viewer->setObjectName(QStringLiteral("viewer"));
        sizePolicy3.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy3);
        viewer->setMinimumSize(QSize(725, 1000));
        viewer->setAutoFillBackground(false);
        viewer->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(viewer);

        frame_viewer = new QFrame(frame_left);
        frame_viewer->setObjectName(QStringLiteral("frame_viewer"));
        frame_viewer->setMinimumSize(QSize(250, 0));
        frame_viewer->setMaximumSize(QSize(250, 1000));
        frame_viewer->setStyleSheet(QLatin1String("background-color: rgb(236, 240, 241);\n"
"color: rgb(40, 40, 40);"));
        frame_viewer->setFrameShape(QFrame::NoFrame);
        frame_viewer->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame_viewer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(frame_viewer);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        verticalLayout->addWidget(label_3);

        line_5 = new QFrame(frame_viewer);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        frame_medidas = new QFrame(frame_viewer);
        frame_medidas->setObjectName(QStringLiteral("frame_medidas"));
        frame_medidas->setFrameShape(QFrame::StyledPanel);
        frame_medidas->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_medidas);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        sceneView = new QTreeView(frame_medidas);
        sceneView->setObjectName(QStringLiteral("sceneView"));
        sceneView->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(sceneView->sizePolicy().hasHeightForWidth());
        sceneView->setSizePolicy(sizePolicy5);
        sceneView->setFrameShape(QFrame::Panel);
        sceneView->setFrameShadow(QFrame::Plain);
        sceneView->setLineWidth(0);
        sceneView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        sceneView->setAlternatingRowColors(false);
        sceneView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        sceneView->setIndentation(0);

        verticalLayout_8->addWidget(sceneView);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);


        verticalLayout->addWidget(frame_medidas);

        frame_comparacion = new QFrame(frame_viewer);
        frame_comparacion->setObjectName(QStringLiteral("frame_comparacion"));
        frame_comparacion->setFrameShape(QFrame::NoFrame);
        frame_comparacion->setFrameShadow(QFrame::Plain);
        verticalLayout_3 = new QVBoxLayout(frame_comparacion);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(frame_comparacion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_2);

        line = new QFrame(frame_comparacion);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        cbo_modelos = new QComboBox(frame_comparacion);
        cbo_modelos->setObjectName(QStringLiteral("cbo_modelos"));
        cbo_modelos->setEnabled(false);

        verticalLayout_3->addWidget(cbo_modelos);

        sceneView_right = new QTreeView(frame_comparacion);
        sceneView_right->setObjectName(QStringLiteral("sceneView_right"));
        sceneView_right->setEnabled(true);
        sizePolicy5.setHeightForWidth(sceneView_right->sizePolicy().hasHeightForWidth());
        sceneView_right->setSizePolicy(sizePolicy5);
        sceneView_right->setFrameShape(QFrame::Panel);
        sceneView_right->setFrameShadow(QFrame::Plain);
        sceneView_right->setLineWidth(0);
        sceneView_right->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        sceneView_right->setAlternatingRowColors(false);
        sceneView_right->setSelectionMode(QAbstractItemView::ExtendedSelection);
        sceneView_right->setIndentation(0);

        verticalLayout_3->addWidget(sceneView_right);

        label = new QLabel(frame_comparacion);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        verticalLayout_3->addWidget(label);

        line_6 = new QFrame(frame_comparacion);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_6);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(frame_comparacion);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_9 = new QLabel(frame_comparacion);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        dif_cintura = new QLabel(frame_comparacion);
        dif_cintura->setObjectName(QStringLiteral("dif_cintura"));
        dif_cintura->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        dif_cintura->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dif_cintura, 2, 1, 1, 1);

        dif_wrist = new QLabel(frame_comparacion);
        dif_wrist->setObjectName(QStringLiteral("dif_wrist"));
        dif_wrist->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        dif_wrist->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dif_wrist, 5, 1, 1, 1);

        dif_cadera = new QLabel(frame_comparacion);
        dif_cadera->setObjectName(QStringLiteral("dif_cadera"));
        dif_cadera->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        dif_cadera->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dif_cadera, 3, 1, 1, 1);

        label_7 = new QLabel(frame_comparacion);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        fecha_captura_r = new QLabel(frame_comparacion);
        fecha_captura_r->setObjectName(QStringLiteral("fecha_captura_r"));

        gridLayout->addWidget(fecha_captura_r, 1, 1, 1, 1);

        dif_brazo = new QLabel(frame_comparacion);
        dif_brazo->setObjectName(QStringLiteral("dif_brazo"));
        dif_brazo->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        dif_brazo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dif_brazo, 4, 1, 1, 1);

        lbl_fecha_captura_r = new QLabel(frame_comparacion);
        lbl_fecha_captura_r->setObjectName(QStringLiteral("lbl_fecha_captura_r"));
        lbl_fecha_captura_r->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        gridLayout->addWidget(lbl_fecha_captura_r, 1, 0, 1, 1);

        label_5 = new QLabel(frame_comparacion);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        verticalLayout->addWidget(frame_comparacion);

        frame_datos_paciente = new QFrame(frame_viewer);
        frame_datos_paciente->setObjectName(QStringLiteral("frame_datos_paciente"));
        frame_datos_paciente->setFrameShape(QFrame::StyledPanel);
        frame_datos_paciente->setFrameShadow(QFrame::Raised);
        lblDatosPaciente = new QLabel(frame_datos_paciente);
        lblDatosPaciente->setObjectName(QStringLiteral("lblDatosPaciente"));
        lblDatosPaciente->setGeometry(QRect(12, 12, 94, 17));
        sizePolicy2.setHeightForWidth(lblDatosPaciente->sizePolicy().hasHeightForWidth());
        lblDatosPaciente->setSizePolicy(sizePolicy2);
        lblDatosPaciente->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        line_7 = new QFrame(frame_datos_paciente);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(12, 36, 202, 16));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget = new QWidget(frame_datos_paciente);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 201, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 75 8pt \"Segoe UI Black\";"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("font: 75 8pt \"Segoe UI Black\";"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QStringLiteral("font: 75 8pt \"Segoe UI Black\";"));

        gridLayout_2->addWidget(label_11, 7, 0, 1, 1);

        lbl_cedula = new QLabel(gridLayoutWidget);
        lbl_cedula->setObjectName(QStringLiteral("lbl_cedula"));

        gridLayout_2->addWidget(lbl_cedula, 3, 1, 1, 1);

        lbl_nombre = new QLabel(gridLayoutWidget);
        lbl_nombre->setObjectName(QStringLiteral("lbl_nombre"));

        gridLayout_2->addWidget(lbl_nombre, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("font: 75 8pt \"Segoe UI Black\";"));

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        lbl_apellido = new QLabel(gridLayoutWidget);
        lbl_apellido->setObjectName(QStringLiteral("lbl_apellido"));

        gridLayout_2->addWidget(lbl_apellido, 1, 1, 1, 1);

        lbl_fecha_nacimiento = new QLabel(gridLayoutWidget);
        lbl_fecha_nacimiento->setObjectName(QStringLiteral("lbl_fecha_nacimiento"));

        gridLayout_2->addWidget(lbl_fecha_nacimiento, 7, 1, 1, 1);

        lbl_fecha_captura = new QLabel(gridLayoutWidget);
        lbl_fecha_captura->setObjectName(QStringLiteral("lbl_fecha_captura"));
        lbl_fecha_captura->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(lbl_fecha_captura, 8, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QStringLiteral("font: 75 8pt \"Segoe UI Black\";"));

        gridLayout_2->addWidget(label_12, 8, 0, 1, 1);


        verticalLayout->addWidget(frame_datos_paciente);

        frame_progress2 = new QFrame(frame_viewer);
        frame_progress2->setObjectName(QStringLiteral("frame_progress2"));
        frame_progress2->setFrameShape(QFrame::StyledPanel);
        frame_progress2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_progress2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbl_processing2 = new QLabel(frame_progress2);
        lbl_processing2->setObjectName(QStringLiteral("lbl_processing2"));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Black"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(10);
        lbl_processing2->setFont(font);
        lbl_processing2->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));

        horizontalLayout_4->addWidget(lbl_processing2);

        progressBar_2 = new QProgressBar(frame_progress2);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setValue(24);

        horizontalLayout_4->addWidget(progressBar_2);


        verticalLayout->addWidget(frame_progress2);


        horizontalLayout->addWidget(frame_viewer);

        Cybele->setCentralWidget(mainWidget);
        frame_right->raise();
        frame_left->raise();
        repair_frame->raise();
        menubar = new QMenuBar(Cybele);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1751, 23));
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        menubar->setLayoutDirection(Qt::LeftToRight);
        menubar->setAutoFillBackground(false);
        menubar->setStyleSheet(QStringLiteral("selection-color: rgb(0, 85, 0);"));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(false);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(menuFile->sizePolicy().hasHeightForWidth());
        menuFile->setSizePolicy(sizePolicy6);
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        menuFile->setFont(font1);
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
        Cybele->setWindowTitle(QApplication::translate("Cybele", "Cybele", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("Cybele", "&Quit", Q_NULLPTR));
        actionQuit->setShortcut(QApplication::translate("Cybele", "Ctrl+Q", Q_NULLPTR));
        actionSimplify->setText(QApplication::translate("Cybele", "&Simplification", Q_NULLPTR));
        actionCatmullClark->setText(QApplication::translate("Cybele", "&Catmull-Clark", Q_NULLPTR));
        actionKernel->setText(QApplication::translate("Cybele", "&Kernel", Q_NULLPTR));
        actionUnion->setText(QApplication::translate("Cybele", "&Union (A/B)", Q_NULLPTR));
        actionUnion->setShortcut(QApplication::translate("Cybele", "Ctrl+O, U", Q_NULLPTR));
        actionIntersection->setText(QApplication::translate("Cybele", "&Intersection (A/B)", Q_NULLPTR));
        actionIntersection->setShortcut(QApplication::translate("Cybele", "Ctrl+O, I", Q_NULLPTR));
        actionDifference->setText(QApplication::translate("Cybele", "&Difference (A/B)", Q_NULLPTR));
        actionDifference->setShortcut(QApplication::translate("Cybele", "Ctrl+O, D", Q_NULLPTR));
        actionFitPlane->setText(QApplication::translate("Cybele", "Fit &plane", Q_NULLPTR));
        actionFitLine->setText(QApplication::translate("Cybele", "Fit &line", Q_NULLPTR));
        actionEstimateCurvature->setText(QApplication::translate("Cybele", "&Curvature estimation", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("Cybele", "&Load...", Q_NULLPTR));
        actionLoad->setShortcut(QApplication::translate("Cybele", "Ctrl+L", Q_NULLPTR));
        actionErase->setText(QApplication::translate("Cybele", "&Erase", Q_NULLPTR));
        actionErase->setShortcut(QApplication::translate("Cybele", "Del", Q_NULLPTR));
        actionDuplicate->setText(QApplication::translate("Cybele", "&Duplicate", Q_NULLPTR));
        actionDuplicate->setShortcut(QApplication::translate("Cybele", "Ctrl+D", Q_NULLPTR));
        actionSqrt3->setText(QApplication::translate("Cybele", "&Sqrt3", Q_NULLPTR));
        actionAntiAliasing->setText(QApplication::translate("Cybele", "&Antialiasing", Q_NULLPTR));
        dummyAction->setText(QApplication::translate("Cybele", "n/a", Q_NULLPTR));
        actionConvexHull->setText(QApplication::translate("Cybele", "&Convex hull", Q_NULLPTR));
        actionEraseAll->setText(QApplication::translate("Cybele", "&Erase all", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("Cybele", "&Options...", Q_NULLPTR));
        actionLoop->setText(QApplication::translate("Cybele", "&Loop", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("Cybele", "Save &as...", Q_NULLPTR));
        actionSave->setText(QApplication::translate("Cybele", "&Save", Q_NULLPTR));
        actionSaveAll->setText(QApplication::translate("Cybele", "Save a&ll", Q_NULLPTR));
        actionMergeAll->setText(QApplication::translate("Cybele", "Mer&ge all", Q_NULLPTR));
        actionMerge->setText(QApplication::translate("Cybele", "&Merge", Q_NULLPTR));
        actionSelfIntersection->setText(QApplication::translate("Cybele", "Self-&intersection", Q_NULLPTR));
        actionSelectAll->setText(QApplication::translate("Cybele", "Select &all", Q_NULLPTR));
        actionSelectNone->setText(QApplication::translate("Cybele", "Select &none", Q_NULLPTR));
        actionSelectInvert->setText(QApplication::translate("Cybele", "&Invert selection", Q_NULLPTR));
        actionShowHide->setText(QApplication::translate("Cybele", "Show/Hide", Q_NULLPTR));
        actionShowHide->setShortcut(QApplication::translate("Cybele", "Ctrl+Space", Q_NULLPTR));
        actionSetPolyhedronA->setText(QApplication::translate("Cybele", "Set polyhedron A", Q_NULLPTR));
        actionSetPolyhedronB->setText(QApplication::translate("Cybele", "Set polyhedron B", Q_NULLPTR));
        actionInsideOut->setText(QApplication::translate("Cybele", "&Inside-out", Q_NULLPTR));
        actionRemeshing->setText(QApplication::translate("Cybele", "&Remeshing", Q_NULLPTR));
        actionConvexDecomposition->setText(QApplication::translate("Cybele", "Convex Decomposition", Q_NULLPTR));
        actionMVC->setText(QApplication::translate("Cybele", "Mean &value coordinates", Q_NULLPTR));
        actionDCP->setText(QApplication::translate("Cybele", "Discrete &conformal maps", Q_NULLPTR));
        actionExplode->setText(QApplication::translate("Cybele", "Explode", Q_NULLPTR));
        actionToNef->setText(QApplication::translate("Cybele", "Convert to nef polyhedron", Q_NULLPTR));
        actionToPoly->setText(QApplication::translate("Cybele", "Convert to normal polyhedron", Q_NULLPTR));
        actionDraw_two_sides->setText(QApplication::translate("Cybele", "Draw &two sides", Q_NULLPTR));
        actionDraw_two_sides->setShortcut(QApplication::translate("Cybele", "Ctrl+T", Q_NULLPTR));
        actionRecenterScene->setText(QApplication::translate("Cybele", "Re&center scene", Q_NULLPTR));
        actionRecenterScene->setShortcut(QApplication::translate("Cybele", "Ctrl+C", Q_NULLPTR));
        actionSetBackgroundColor->setText(QApplication::translate("Cybele", "Change &background color...", Q_NULLPTR));
        actionMinkowskiSum->setText(QApplication::translate("Cybele", "&Minkowski sum (A/B)", Q_NULLPTR));
        actionMinkowskiSum->setShortcut(QApplication::translate("Cybele", "Ctrl+O, M", Q_NULLPTR));
        action_Look_at->setText(QApplication::translate("Cybele", "&Look at...", Q_NULLPTR));
        actionSaveSnapshot->setText(QApplication::translate("Cybele", "Save snapshot", Q_NULLPTR));
        actionDumpCamera->setText(QApplication::translate("Cybele", "&Dump camera coordinates", Q_NULLPTR));
        action_Copy_camera->setText(QApplication::translate("Cybele", "&Copy camera", Q_NULLPTR));
        action_Paste_camera->setText(QApplication::translate("Cybele", "&Paste camera", Q_NULLPTR));
        actionSelect_all_items->setText(QApplication::translate("Cybele", "Select all items", Q_NULLPTR));
        actionSelect_all_items->setShortcut(QApplication::translate("Cybele", "Ctrl+A", Q_NULLPTR));
        actionLoad_Script->setText(QApplication::translate("Cybele", "Load &script", Q_NULLPTR));
        actionPreferences->setText(QApplication::translate("Cybele", "&Preferences", Q_NULLPTR));
        open_file_btn->setText(QApplication::translate("Cybele", "Abrir Scan", Q_NULLPTR));
        gb_CropBoxDials->setTitle(QApplication::translate("Cybele", "Ajustar ", Q_NULLPTR));
        label1_3->setText(QApplication::translate("Cybele", "Z+", Q_NULLPTR));
        label1_2->setText(QApplication::translate("Cybele", "Y+", Q_NULLPTR));
        label1->setText(QApplication::translate("Cybele", "X+", Q_NULLPTR));
        label1_5->setText(QApplication::translate("Cybele", "X-", Q_NULLPTR));
        label1_4->setText(QApplication::translate("Cybele", "Y-", Q_NULLPTR));
        label1_6->setText(QApplication::translate("Cybele", "Z-", Q_NULLPTR));
        crop_box->setText(QApplication::translate("Cybele", "Aplicar Selecci\303\263n", Q_NULLPTR));
        btnExtraerMedidas->setText(QApplication::translate("Cybele", "Reconstruir", Q_NULLPTR));
        lbl_processing->setText(QApplication::translate("Cybele", "Procesando...", Q_NULLPTR));
        btn_selection->setText(QApplication::translate("Cybele", "Seleccionar\n"
"Puntos", Q_NULLPTR));
        btn_CircunBrazoIzq->setText(QApplication::translate("Cybele", "Circunf.\n"
"Brazo", Q_NULLPTR));
        btn_CircunCadera->setText(QApplication::translate("Cybele", "Circunf.\n"
"Cadera", Q_NULLPTR));
        btn_DiamFemur->setText(QApplication::translate("Cybele", "Circunf.\n"
"Mu\303\261eca", Q_NULLPTR));
        btn_CircunCintura->setText(QApplication::translate("Cybele", "Circunf.\n"
"Cintura", Q_NULLPTR));
        cmd_buscarmodelo_1->setText(QApplication::translate("Cybele", "Buscar\n"
"Paciente", Q_NULLPTR));
        compare_btn->setText(QApplication::translate("Cybele", "Comparar\n"
"Medidas", Q_NULLPTR));
        historial_btn->setText(QApplication::translate("Cybele", "Historial", Q_NULLPTR));
        cmd_savemodel->setText(QApplication::translate("Cybele", "Guardar", Q_NULLPTR));
        label_3->setText(QApplication::translate("Cybele", "Visor Izquierdo", Q_NULLPTR));
        label_2->setText(QApplication::translate("Cybele", "Visor Derecho", Q_NULLPTR));
        label->setText(QApplication::translate("Cybele", "Comparaci\303\263n de Medidas", Q_NULLPTR));
        label_8->setText(QApplication::translate("Cybele", "Brazo", Q_NULLPTR));
        label_9->setText(QApplication::translate("Cybele", "Mu\303\261eca", Q_NULLPTR));
        dif_cintura->setText(QString());
        dif_wrist->setText(QString());
        dif_cadera->setText(QString());
        label_7->setText(QApplication::translate("Cybele", "Cadera", Q_NULLPTR));
        fecha_captura_r->setText(QString());
        dif_brazo->setText(QString());
        lbl_fecha_captura_r->setText(QApplication::translate("Cybele", "Fecha de Captura", Q_NULLPTR));
        label_5->setText(QApplication::translate("Cybele", "Cintura", Q_NULLPTR));
        lblDatosPaciente->setText(QApplication::translate("Cybele", "Datos Paciente", Q_NULLPTR));
        label_4->setText(QApplication::translate("Cybele", "Nombre", Q_NULLPTR));
        label_10->setText(QApplication::translate("Cybele", "Apellido", Q_NULLPTR));
        label_11->setText(QApplication::translate("Cybele", "Fecha Nac.:", Q_NULLPTR));
        lbl_cedula->setText(QString());
        lbl_nombre->setText(QString());
        label_6->setText(QApplication::translate("Cybele", "C\303\251dula", Q_NULLPTR));
        lbl_apellido->setText(QString());
        lbl_fecha_nacimiento->setText(QString());
        lbl_fecha_captura->setText(QString());
        label_12->setText(QApplication::translate("Cybele", "Fecha Scan:", Q_NULLPTR));
        lbl_processing2->setText(QApplication::translate("Cybele", "Procesando...", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("Cybele", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("Cybele", "&Edit", Q_NULLPTR));
        menuOperations->setTitle(QApplication::translate("Cybele", "&Operations", Q_NULLPTR));
        menuSubdivision->setTitle(QApplication::translate("Cybele", "&Subdivision", Q_NULLPTR));
        menu_Boolean_operations->setTitle(QApplication::translate("Cybele", "&Boolean operations", Q_NULLPTR));
        menuParameterization->setTitle(QApplication::translate("Cybele", "Parameterization", Q_NULLPTR));
        menuPCA->setTitle(QApplication::translate("Cybele", "PCA", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("Cybele", "&View", Q_NULLPTR));
        menuDockWindows->setTitle(QApplication::translate("Cybele", "&Dock windows", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("Cybele", "Ca&mera", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cybele: public Ui_Cybele {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYBELE_H
