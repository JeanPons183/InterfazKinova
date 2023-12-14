/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QLabel *label_KinovaGen3Lite;
    QPushButton *ConectarPB;
    QWidget *formLayoutWidget;
    QFormLayout *ScreenEstadoRobot;
    QLabel *label_Estado;
    QLabel *label_EstadoActual;
    QLabel *label_Robot;
    QLabel *label_IP;
    QGroupBox *Ejecucion;
    QFrame *PlayFrame;
    QTextBrowser *MostrarErrores;
    QLabel *label_138;
    QStackedWidget *ScreenRunStop;
    QWidget *Iniciar;
    QPushButton *IniciarPB;
    QPushButton *moverAltoNivelPB;
    QWidget *Playing;
    QPushButton *StopPB;
    QWidget *Detenido;
    QPushButton *FinalizarPB;
    QPushButton *CancelarGravedadPB;
    QPushButton *moverAltoNivelPB_2;
    QWidget *Final;
    QPushButton *FinalizarPB_2;
    QPushButton *GuardarTrayectoriaPB;
    QRadioButton *AccionTerminadaRB;
    QWidget *AltoNivel;
    QPushButton *goToHomePB;
    QPushButton *goToZeroPB;
    QPushButton *goToPackPB;
    QPushButton *regresarMenuPB;
    QLabel *label_142;
    QGroupBox *RobotSetting;
    QFrame *SettingFrame;
    QPushButton *CambiarTiempoPB;
    QPushButton *CambiarControlPB;
    QWidget *gridLayoutWidget_12;
    QGridLayout *gridLayout_8;
    QStackedWidget *ScreenTiempo;
    QWidget *Label_2;
    QWidget *gridLayoutWidget_15;
    QGridLayout *gridLayout_9;
    QLabel *label_Segundos;
    QLabel *label_101;
    QLabel *label_9;
    QWidget *Input_5;
    QWidget *gridLayoutWidget_16;
    QGridLayout *gridLayout_10;
    QLabel *label_104;
    QLabel *label_105;
    QSpinBox *TiempoSB;
    QWidget *gridLayoutWidget_17;
    QGridLayout *gridLayout_11;
    QComboBox *ControlSelectCB;
    QLabel *label_15;
    QFrame *GainsFrame;
    QStackedWidget *ScreenvirtualGains;
    QWidget *Labels_GainsVirtual;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_GainsVirtual;
    QLabel *label_86;
    QLabel *label_87;
    QLabel *kc5Label;
    QLabel *kc4Label;
    QLabel *label_88;
    QLabel *label_89;
    QLabel *kc1Label;
    QLabel *kc6Label;
    QLabel *kc2Label;
    QLabel *kc3Label;
    QLabel *label_90;
    QLabel *label_91;
    QLabel *label_93;
    QLabel *label_107;
    QLabel *label_95;
    QWidget *Input_GainsVirtual;
    QWidget *gridLayoutWidget_18;
    QGridLayout *gridLayout;
    QDoubleSpinBox *kc3SB;
    QLabel *label_37;
    QLabel *label_38;
    QDoubleSpinBox *kc5SB;
    QDoubleSpinBox *kc1SB;
    QDoubleSpinBox *kc4SB;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QDoubleSpinBox *kc2SB;
    QLabel *label_16;
    QDoubleSpinBox *kc6SB;
    QLabel *label_42;
    QLabel *label_109;
    QLabel *label_20;
    QStackedWidget *ScreenGains;
    QWidget *Labels_3;
    QWidget *gridLayoutWidget_19;
    QGridLayout *GridGainsSB;
    QLabel *label_43;
    QLabel *label_Kp_2;
    QLabel *kd5Label;
    QLabel *label_24;
    QLabel *kp2Label;
    QLabel *kd1Label;
    QLabel *label_Kd_2;
    QLabel *label_26;
    QLabel *kp6Label;
    QLabel *kd6Label;
    QLabel *label_27;
    QLabel *kd2Label;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_110;
    QLabel *kd3Label;
    QLabel *kp4Label;
    QLabel *kp1Label;
    QLabel *kp5Label;
    QLabel *kp3Label;
    QLabel *kd4Label;
    QLabel *ki4Label;
    QLabel *ki2Label;
    QLabel *ki3Label;
    QLabel *label_Ki_2;
    QLabel *ki5Label;
    QLabel *ki1Label;
    QLabel *ki6Label;
    QWidget *Input;
    QWidget *gridLayoutWidget_20;
    QGridLayout *GridGainsLabels;
    QDoubleSpinBox *kd2SB;
    QLabel *label_2;
    QDoubleSpinBox *ki1SB;
    QLabel *label_3;
    QDoubleSpinBox *kp4SB;
    QDoubleSpinBox *ki4SB;
    QLabel *label_4;
    QDoubleSpinBox *kd5SB;
    QDoubleSpinBox *kp5SB;
    QDoubleSpinBox *ki2SB;
    QLabel *label_Ki;
    QDoubleSpinBox *kp6SB;
    QDoubleSpinBox *kp1SB;
    QDoubleSpinBox *kd1SB;
    QLabel *label_5;
    QLabel *label_57;
    QLabel *label_Kp;
    QLabel *label_58;
    QDoubleSpinBox *ki6SB;
    QDoubleSpinBox *kd4SB;
    QDoubleSpinBox *kp3SB;
    QLabel *label_Kd;
    QDoubleSpinBox *ki3SB;
    QDoubleSpinBox *kd3SB;
    QDoubleSpinBox *kp2SB;
    QLabel *label_59;
    QDoubleSpinBox *kd6SB;
    QDoubleSpinBox *ki5SB;
    QLabel *label;
    QStackedWidget *Screenmc;
    QWidget *Labels_mc;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Masavirtual;
    QLabel *mcValueLabel;
    QWidget *Input_mc;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_76;
    QDoubleSpinBox *mcValueSB;
    QPushButton *cambiarGainsPB;
    QFrame *ScreenLg;
    QWidget *gridLayoutWidget_21;
    QGridLayout *Layout_Lg;
    QLabel *label_Lg;
    QLabel *label_Lg_value;
    QFrame *PosicionFrame;
    QStackedWidget *ScreenQd;
    QWidget *QdLabels;
    QWidget *gridLayoutWidget_24;
    QGridLayout *gridLayout_Qd_labels;
    QLabel *label_130;
    QLabel *label_131;
    QLabel *label_134;
    QLabel *label_135;
    QLabel *label_posqd2;
    QLabel *label_posqd5;
    QLabel *label_posqd4;
    QLabel *label_posqd6;
    QLabel *label_133;
    QLabel *label_137;
    QLabel *label_posqd1;
    QLabel *label_136;
    QLabel *label_posqd3;
    QLabel *label_132;
    QLabel *label_gripperValueQd;
    QLabel *label_143;
    QWidget *QdSpinBox;
    QWidget *gridLayoutWidget_23;
    QGridLayout *gridLayout_Qd_SB;
    QDoubleSpinBox *qd4SB;
    QLabel *label_129;
    QLabel *label_124;
    QDoubleSpinBox *qd2SB;
    QLabel *label_123;
    QDoubleSpinBox *qd3SB;
    QDoubleSpinBox *qd6SB;
    QLabel *label_126;
    QDoubleSpinBox *qd1SB;
    QLabel *label_122;
    QLabel *label_127;
    QDoubleSpinBox *qd5SB;
    QLabel *label_125;
    QDoubleSpinBox *gripValueSB;
    QLabel *label_128;
    QLabel *label_144;
    QPushButton *CambiarQdPB;
    QPushButton *PosPackPB;
    QPushButton *PosZeroPB;
    QPushButton *PosHomePB;
    QWidget *gridLayoutWidget_22;
    QGridLayout *QLabels;
    QLabel *label_q3;
    QLabel *label_q6;
    QLabel *label_113;
    QLabel *label_139;
    QLabel *label_121;
    QLabel *label_q5;
    QLabel *label_115;
    QLabel *label_EFy;
    QLabel *label_141;
    QLabel *label_114;
    QLabel *label_112;
    QLabel *label_118;
    QLabel *label_q2;
    QLabel *label_gripperValue;
    QLabel *label_q4;
    QLabel *label_EFz;
    QLabel *label_q1;
    QLabel *label_140;
    QLabel *label_EFx;
    QLabel *label_116;
    QLabel *label_117;
    QLabel *label_120;
    QFrame *line_2;
    QFrame *line_3;
    QGroupBox *Plots;
    QPushButton *ActivarGraficasPB;
    QComboBox *ElegirGraficaCB;
    QLabel *label_agraficar;
    QLabel *label_posarticulaciones;
    QCheckBox *PosicionDeseadaRD;
    QGroupBox *RunMode;
    QRadioButton *SimulacionRB;
    QRadioButton *CorrerRobotRB;
    QMenuBar *menubar;
    QMenu *menuREAD_ME;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1020);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(1020103, 16777215));
        scrollArea->setSizeIncrement(QSize(16, 10));
        scrollArea->setBaseSize(QSize(0, -1));
        QFont font;
        font.setPointSize(11);
        scrollArea->setFont(font);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignBottom|Qt::AlignJustify);
        scrollContents = new QWidget();
        scrollContents->setObjectName("scrollContents");
        scrollContents->setGeometry(QRect(0, 0, 1886, 959));
        sizePolicy.setHeightForWidth(scrollContents->sizePolicy().hasHeightForWidth());
        scrollContents->setSizePolicy(sizePolicy);
        label_KinovaGen3Lite = new QLabel(scrollContents);
        label_KinovaGen3Lite->setObjectName("label_KinovaGen3Lite");
        label_KinovaGen3Lite->setGeometry(QRect(10, 10, 321, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Perpetua Titling MT")});
        font1.setPointSize(22);
        label_KinovaGen3Lite->setFont(font1);
        ConectarPB = new QPushButton(scrollContents);
        ConectarPB->setObjectName("ConectarPB");
        ConectarPB->setGeometry(QRect(750, 20, 121, 31));
        QFont font2;
        font2.setPointSize(12);
        ConectarPB->setFont(font2);
        ConectarPB->setCursor(QCursor(Qt::PointingHandCursor));
        formLayoutWidget = new QWidget(scrollContents);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(330, 10, 371, 51));
        ScreenEstadoRobot = new QFormLayout(formLayoutWidget);
        ScreenEstadoRobot->setObjectName("ScreenEstadoRobot");
        ScreenEstadoRobot->setContentsMargins(0, 0, 0, 0);
        label_Estado = new QLabel(formLayoutWidget);
        label_Estado->setObjectName("label_Estado");
        label_Estado->setFont(font2);

        ScreenEstadoRobot->setWidget(0, QFormLayout::LabelRole, label_Estado);

        label_EstadoActual = new QLabel(formLayoutWidget);
        label_EstadoActual->setObjectName("label_EstadoActual");
        label_EstadoActual->setFont(font2);

        ScreenEstadoRobot->setWidget(0, QFormLayout::FieldRole, label_EstadoActual);

        label_Robot = new QLabel(formLayoutWidget);
        label_Robot->setObjectName("label_Robot");
        label_Robot->setFont(font2);

        ScreenEstadoRobot->setWidget(1, QFormLayout::LabelRole, label_Robot);

        label_IP = new QLabel(formLayoutWidget);
        label_IP->setObjectName("label_IP");
        label_IP->setFont(font2);

        ScreenEstadoRobot->setWidget(1, QFormLayout::FieldRole, label_IP);

        label_EstadoActual->raise();
        label_IP->raise();
        label_Estado->raise();
        label_Robot->raise();
        Ejecucion = new QGroupBox(scrollContents);
        Ejecucion->setObjectName("Ejecucion");
        Ejecucion->setGeometry(QRect(1610, 70, 261, 401));
        Ejecucion->setMinimumSize(QSize(261, 21));
        Ejecucion->setMaximumSize(QSize(261, 411));
        Ejecucion->setFont(font2);
        PlayFrame = new QFrame(Ejecucion);
        PlayFrame->setObjectName("PlayFrame");
        PlayFrame->setGeometry(QRect(0, 20, 261, 371));
        PlayFrame->setFrameShape(QFrame::NoFrame);
        PlayFrame->setFrameShadow(QFrame::Raised);
        MostrarErrores = new QTextBrowser(PlayFrame);
        MostrarErrores->setObjectName("MostrarErrores");
        MostrarErrores->setGeometry(QRect(10, 230, 241, 131));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(11);
        MostrarErrores->setFont(font3);
        label_138 = new QLabel(PlayFrame);
        label_138->setObjectName("label_138");
        label_138->setGeometry(QRect(20, 200, 81, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(12);
        label_138->setFont(font4);
        ScreenRunStop = new QStackedWidget(PlayFrame);
        ScreenRunStop->setObjectName("ScreenRunStop");
        ScreenRunStop->setGeometry(QRect(10, 10, 241, 181));
        Iniciar = new QWidget();
        Iniciar->setObjectName("Iniciar");
        IniciarPB = new QPushButton(Iniciar);
        IniciarPB->setObjectName("IniciarPB");
        IniciarPB->setGeometry(QRect(40, 20, 161, 51));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI")});
        font5.setPointSize(12);
        font5.setBold(true);
        IniciarPB->setFont(font5);
        IniciarPB->setCursor(QCursor(Qt::PointingHandCursor));
        moverAltoNivelPB = new QPushButton(Iniciar);
        moverAltoNivelPB->setObjectName("moverAltoNivelPB");
        moverAltoNivelPB->setGeometry(QRect(0, 130, 241, 31));
        ScreenRunStop->addWidget(Iniciar);
        Playing = new QWidget();
        Playing->setObjectName("Playing");
        StopPB = new QPushButton(Playing);
        StopPB->setObjectName("StopPB");
        StopPB->setGeometry(QRect(40, 20, 161, 51));
        StopPB->setFont(font5);
        StopPB->setCursor(QCursor(Qt::PointingHandCursor));
        ScreenRunStop->addWidget(Playing);
        Detenido = new QWidget();
        Detenido->setObjectName("Detenido");
        FinalizarPB = new QPushButton(Detenido);
        FinalizarPB->setObjectName("FinalizarPB");
        FinalizarPB->setGeometry(QRect(40, 20, 161, 51));
        FinalizarPB->setFont(font5);
        FinalizarPB->setCursor(QCursor(Qt::PointingHandCursor));
        CancelarGravedadPB = new QPushButton(Detenido);
        CancelarGravedadPB->setObjectName("CancelarGravedadPB");
        CancelarGravedadPB->setGeometry(QRect(30, 80, 181, 41));
        CancelarGravedadPB->setFont(font5);
        CancelarGravedadPB->setCursor(QCursor(Qt::PointingHandCursor));
        moverAltoNivelPB_2 = new QPushButton(Detenido);
        moverAltoNivelPB_2->setObjectName("moverAltoNivelPB_2");
        moverAltoNivelPB_2->setGeometry(QRect(0, 130, 241, 31));
        ScreenRunStop->addWidget(Detenido);
        Final = new QWidget();
        Final->setObjectName("Final");
        FinalizarPB_2 = new QPushButton(Final);
        FinalizarPB_2->setObjectName("FinalizarPB_2");
        FinalizarPB_2->setGeometry(QRect(10, 30, 221, 41));
        FinalizarPB_2->setFont(font5);
        FinalizarPB_2->setCursor(QCursor(Qt::PointingHandCursor));
        GuardarTrayectoriaPB = new QPushButton(Final);
        GuardarTrayectoriaPB->setObjectName("GuardarTrayectoriaPB");
        GuardarTrayectoriaPB->setGeometry(QRect(10, 120, 221, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Segoe UI")});
        font6.setPointSize(12);
        font6.setBold(false);
        GuardarTrayectoriaPB->setFont(font6);
        GuardarTrayectoriaPB->setCursor(QCursor(Qt::PointingHandCursor));
        AccionTerminadaRB = new QRadioButton(Final);
        AccionTerminadaRB->setObjectName("AccionTerminadaRB");
        AccionTerminadaRB->setEnabled(false);
        AccionTerminadaRB->setGeometry(QRect(40, 80, 181, 31));
        AccionTerminadaRB->setCheckable(true);
        AccionTerminadaRB->setChecked(true);
        ScreenRunStop->addWidget(Final);
        AltoNivel = new QWidget();
        AltoNivel->setObjectName("AltoNivel");
        goToHomePB = new QPushButton(AltoNivel);
        goToHomePB->setObjectName("goToHomePB");
        goToHomePB->setGeometry(QRect(20, 70, 201, 24));
        QFont font7;
        font7.setPointSize(10);
        goToHomePB->setFont(font7);
        goToHomePB->setCursor(QCursor(Qt::PointingHandCursor));
        goToZeroPB = new QPushButton(AltoNivel);
        goToZeroPB->setObjectName("goToZeroPB");
        goToZeroPB->setGeometry(QRect(20, 30, 201, 25));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Segoe UI")});
        font8.setPointSize(10);
        goToZeroPB->setFont(font8);
        goToZeroPB->setCursor(QCursor(Qt::PointingHandCursor));
        goToPackPB = new QPushButton(AltoNivel);
        goToPackPB->setObjectName("goToPackPB");
        goToPackPB->setGeometry(QRect(20, 110, 201, 25));
        goToPackPB->setFont(font8);
        goToPackPB->setCursor(QCursor(Qt::PointingHandCursor));
        regresarMenuPB = new QPushButton(AltoNivel);
        regresarMenuPB->setObjectName("regresarMenuPB");
        regresarMenuPB->setGeometry(QRect(20, 150, 201, 31));
        regresarMenuPB->setFont(font);
        regresarMenuPB->setCursor(QCursor(Qt::PointingHandCursor));
        label_142 = new QLabel(AltoNivel);
        label_142->setObjectName("label_142");
        label_142->setGeometry(QRect(60, 0, 141, 30));
        label_142->setMinimumSize(QSize(0, 30));
        label_142->setMaximumSize(QSize(16777215, 30));
        label_142->setFont(font2);
        ScreenRunStop->addWidget(AltoNivel);
        RobotSetting = new QGroupBox(scrollContents);
        RobotSetting->setObjectName("RobotSetting");
        RobotSetting->setGeometry(QRect(10, 69, 1581, 401));
        RobotSetting->setMinimumSize(QSize(0, 21));
        RobotSetting->setMaximumSize(QSize(1611, 411));
        RobotSetting->setFont(font2);
        SettingFrame = new QFrame(RobotSetting);
        SettingFrame->setObjectName("SettingFrame");
        SettingFrame->setGeometry(QRect(0, 20, 361, 351));
        SettingFrame->setFrameShape(QFrame::NoFrame);
        SettingFrame->setFrameShadow(QFrame::Raised);
        CambiarTiempoPB = new QPushButton(SettingFrame);
        CambiarTiempoPB->setObjectName("CambiarTiempoPB");
        CambiarTiempoPB->setGeometry(QRect(90, 310, 161, 31));
        CambiarTiempoPB->setFont(font3);
        CambiarTiempoPB->setCursor(QCursor(Qt::PointingHandCursor));
        CambiarControlPB = new QPushButton(SettingFrame);
        CambiarControlPB->setObjectName("CambiarControlPB");
        CambiarControlPB->setGeometry(QRect(90, 110, 161, 31));
        CambiarControlPB->setFont(font3);
        CambiarControlPB->setCursor(QCursor(Qt::PointingHandCursor));
        gridLayoutWidget_12 = new QWidget(SettingFrame);
        gridLayoutWidget_12->setObjectName("gridLayoutWidget_12");
        gridLayoutWidget_12->setGeometry(QRect(20, 180, 321, 121));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_12);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        ScreenTiempo = new QStackedWidget(gridLayoutWidget_12);
        ScreenTiempo->setObjectName("ScreenTiempo");
        Label_2 = new QWidget();
        Label_2->setObjectName("Label_2");
        gridLayoutWidget_15 = new QWidget(Label_2);
        gridLayoutWidget_15->setObjectName("gridLayoutWidget_15");
        gridLayoutWidget_15->setGeometry(QRect(0, 0, 321, 111));
        gridLayout_9 = new QGridLayout(gridLayoutWidget_15);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_Segundos = new QLabel(gridLayoutWidget_15);
        label_Segundos->setObjectName("label_Segundos");
        label_Segundos->setLayoutDirection(Qt::LeftToRight);
        label_Segundos->setFrameShape(QFrame::StyledPanel);

        gridLayout_9->addWidget(label_Segundos, 1, 0, 1, 1);

        label_101 = new QLabel(gridLayoutWidget_15);
        label_101->setObjectName("label_101");
        label_101->setMinimumSize(QSize(156, 51));
        label_101->setMaximumSize(QSize(156, 51));
        label_101->setFrameShape(QFrame::NoFrame);

        gridLayout_9->addWidget(label_101, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_15);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(319, 52));
        label_9->setMaximumSize(QSize(319, 52));
        label_9->setFrameShape(QFrame::StyledPanel);
        label_9->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(label_9, 0, 0, 1, 2);

        ScreenTiempo->addWidget(Label_2);
        Input_5 = new QWidget();
        Input_5->setObjectName("Input_5");
        gridLayoutWidget_16 = new QWidget(Input_5);
        gridLayoutWidget_16->setObjectName("gridLayoutWidget_16");
        gridLayoutWidget_16->setGeometry(QRect(0, 0, 321, 111));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_16);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_104 = new QLabel(gridLayoutWidget_16);
        label_104->setObjectName("label_104");
        label_104->setFrameShape(QFrame::StyledPanel);
        label_104->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(label_104, 0, 0, 1, 2);

        label_105 = new QLabel(gridLayoutWidget_16);
        label_105->setObjectName("label_105");

        gridLayout_10->addWidget(label_105, 1, 1, 1, 1);

        TiempoSB = new QSpinBox(gridLayoutWidget_16);
        TiempoSB->setObjectName("TiempoSB");
        TiempoSB->setMinimumSize(QSize(0, 51));
        TiempoSB->setMaximum(20);

        gridLayout_10->addWidget(TiempoSB, 1, 0, 1, 1);

        ScreenTiempo->addWidget(Input_5);

        gridLayout_8->addWidget(ScreenTiempo, 0, 0, 1, 1);

        gridLayoutWidget_17 = new QWidget(SettingFrame);
        gridLayoutWidget_17->setObjectName("gridLayoutWidget_17");
        gridLayoutWidget_17->setGeometry(QRect(20, 20, 321, 81));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_17);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        ControlSelectCB = new QComboBox(gridLayoutWidget_17);
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->addItem(QString());
        ControlSelectCB->setObjectName("ControlSelectCB");
        ControlSelectCB->setFont(font6);
        ControlSelectCB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_11->addWidget(ControlSelectCB, 1, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_17);
        label_15->setObjectName("label_15");
        label_15->setMinimumSize(QSize(0, 44));
        label_15->setMaximumSize(QSize(319, 44));
        label_15->setFrameShape(QFrame::StyledPanel);
        label_15->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(label_15, 0, 0, 1, 1);

        GainsFrame = new QFrame(RobotSetting);
        GainsFrame->setObjectName("GainsFrame");
        GainsFrame->setGeometry(QRect(390, 20, 621, 381));
        GainsFrame->setFrameShape(QFrame::NoFrame);
        GainsFrame->setFrameShadow(QFrame::Raised);
        ScreenvirtualGains = new QStackedWidget(GainsFrame);
        ScreenvirtualGains->setObjectName("ScreenvirtualGains");
        ScreenvirtualGains->setGeometry(QRect(350, 10, 261, 291));
        ScreenvirtualGains->setFont(font2);
        Labels_GainsVirtual = new QWidget();
        Labels_GainsVirtual->setObjectName("Labels_GainsVirtual");
        gridLayoutWidget_6 = new QWidget(Labels_GainsVirtual);
        gridLayoutWidget_6->setObjectName("gridLayoutWidget_6");
        gridLayoutWidget_6->setGeometry(QRect(20, 0, 231, 291));
        gridLayoutWidget_6->setFont(font2);
        gridLayout_GainsVirtual = new QGridLayout(gridLayoutWidget_6);
        gridLayout_GainsVirtual->setObjectName("gridLayout_GainsVirtual");
        gridLayout_GainsVirtual->setContentsMargins(0, 0, 0, 0);
        label_86 = new QLabel(gridLayoutWidget_6);
        label_86->setObjectName("label_86");
        label_86->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_86, 5, 0, 1, 1);

        label_87 = new QLabel(gridLayoutWidget_6);
        label_87->setObjectName("label_87");
        label_87->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_87, 2, 0, 1, 1);

        kc5Label = new QLabel(gridLayoutWidget_6);
        kc5Label->setObjectName("kc5Label");
        kc5Label->setMinimumSize(QSize(0, 26));
        kc5Label->setFont(font2);
        kc5Label->setFrameShape(QFrame::StyledPanel);
        kc5Label->setFrameShadow(QFrame::Sunken);

        gridLayout_GainsVirtual->addWidget(kc5Label, 6, 1, 1, 1);

        kc4Label = new QLabel(gridLayoutWidget_6);
        kc4Label->setObjectName("kc4Label");
        kc4Label->setMinimumSize(QSize(0, 26));
        kc4Label->setFont(font2);
        kc4Label->setFrameShape(QFrame::StyledPanel);
        kc4Label->setFrameShadow(QFrame::Sunken);

        gridLayout_GainsVirtual->addWidget(kc4Label, 5, 1, 1, 1);

        label_88 = new QLabel(gridLayoutWidget_6);
        label_88->setObjectName("label_88");
        label_88->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_88, 3, 0, 1, 1);

        label_89 = new QLabel(gridLayoutWidget_6);
        label_89->setObjectName("label_89");
        label_89->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_89, 6, 0, 1, 1);

        kc1Label = new QLabel(gridLayoutWidget_6);
        kc1Label->setObjectName("kc1Label");
        kc1Label->setMinimumSize(QSize(0, 26));
        kc1Label->setFont(font2);
        kc1Label->setFrameShape(QFrame::StyledPanel);
        kc1Label->setFrameShadow(QFrame::Sunken);

        gridLayout_GainsVirtual->addWidget(kc1Label, 2, 1, 1, 1);

        kc6Label = new QLabel(gridLayoutWidget_6);
        kc6Label->setObjectName("kc6Label");
        kc6Label->setMinimumSize(QSize(0, 26));
        kc6Label->setFont(font2);
        kc6Label->setFrameShape(QFrame::StyledPanel);
        kc6Label->setFrameShadow(QFrame::Sunken);

        gridLayout_GainsVirtual->addWidget(kc6Label, 7, 1, 1, 1);

        kc2Label = new QLabel(gridLayoutWidget_6);
        kc2Label->setObjectName("kc2Label");
        kc2Label->setMinimumSize(QSize(0, 26));
        kc2Label->setFont(font2);
        kc2Label->setFrameShape(QFrame::StyledPanel);
        kc2Label->setFrameShadow(QFrame::Sunken);

        gridLayout_GainsVirtual->addWidget(kc2Label, 3, 1, 1, 1);

        kc3Label = new QLabel(gridLayoutWidget_6);
        kc3Label->setObjectName("kc3Label");
        kc3Label->setMinimumSize(QSize(0, 26));
        kc3Label->setFont(font2);
        kc3Label->setFrameShape(QFrame::StyledPanel);
        kc3Label->setFrameShadow(QFrame::Sunken);

        gridLayout_GainsVirtual->addWidget(kc3Label, 4, 1, 1, 1);

        label_90 = new QLabel(gridLayoutWidget_6);
        label_90->setObjectName("label_90");
        label_90->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_90, 7, 0, 1, 1);

        label_91 = new QLabel(gridLayoutWidget_6);
        label_91->setObjectName("label_91");
        label_91->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_91, 4, 0, 1, 1);

        label_93 = new QLabel(gridLayoutWidget_6);
        label_93->setObjectName("label_93");
        label_93->setMinimumSize(QSize(0, 27));
        label_93->setMaximumSize(QSize(108, 16777215));
        label_93->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_93, 1, 1, 1, 1);

        label_107 = new QLabel(gridLayoutWidget_6);
        label_107->setObjectName("label_107");
        label_107->setMinimumSize(QSize(115, 27));
        label_107->setMaximumSize(QSize(115, 16777215));

        gridLayout_GainsVirtual->addWidget(label_107, 1, 0, 1, 1);

        label_95 = new QLabel(gridLayoutWidget_6);
        label_95->setObjectName("label_95");
        label_95->setMinimumSize(QSize(229, 30));
        label_95->setMaximumSize(QSize(229, 28));
        label_95->setFont(font2);

        gridLayout_GainsVirtual->addWidget(label_95, 0, 0, 1, 2);

        ScreenvirtualGains->addWidget(Labels_GainsVirtual);
        Input_GainsVirtual = new QWidget();
        Input_GainsVirtual->setObjectName("Input_GainsVirtual");
        gridLayoutWidget_18 = new QWidget(Input_GainsVirtual);
        gridLayoutWidget_18->setObjectName("gridLayoutWidget_18");
        gridLayoutWidget_18->setGeometry(QRect(20, 0, 231, 291));
        gridLayout = new QGridLayout(gridLayoutWidget_18);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        kc3SB = new QDoubleSpinBox(gridLayoutWidget_18);
        kc3SB->setObjectName("kc3SB");
        kc3SB->setMinimumSize(QSize(0, 31));
        kc3SB->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(kc3SB, 4, 1, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_18);
        label_37->setObjectName("label_37");
        label_37->setMinimumSize(QSize(0, 31));
        label_37->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_37, 7, 0, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_18);
        label_38->setObjectName("label_38");
        label_38->setMinimumSize(QSize(0, 31));
        label_38->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_38, 6, 0, 1, 1);

        kc5SB = new QDoubleSpinBox(gridLayoutWidget_18);
        kc5SB->setObjectName("kc5SB");
        kc5SB->setMinimumSize(QSize(0, 31));
        kc5SB->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(kc5SB, 6, 1, 1, 1);

        kc1SB = new QDoubleSpinBox(gridLayoutWidget_18);
        kc1SB->setObjectName("kc1SB");
        kc1SB->setMinimumSize(QSize(0, 31));
        kc1SB->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(kc1SB, 2, 1, 1, 1);

        kc4SB = new QDoubleSpinBox(gridLayoutWidget_18);
        kc4SB->setObjectName("kc4SB");
        kc4SB->setMinimumSize(QSize(0, 31));
        kc4SB->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(kc4SB, 5, 1, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_18);
        label_39->setObjectName("label_39");
        label_39->setMinimumSize(QSize(0, 31));
        label_39->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_39, 3, 0, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_18);
        label_40->setObjectName("label_40");
        label_40->setMinimumSize(QSize(0, 31));
        label_40->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_40, 4, 0, 1, 1);

        label_41 = new QLabel(gridLayoutWidget_18);
        label_41->setObjectName("label_41");
        label_41->setMinimumSize(QSize(0, 31));
        label_41->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_41, 5, 0, 1, 1);

        kc2SB = new QDoubleSpinBox(gridLayoutWidget_18);
        kc2SB->setObjectName("kc2SB");
        kc2SB->setMinimumSize(QSize(0, 31));
        kc2SB->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(kc2SB, 3, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_18);
        label_16->setObjectName("label_16");
        label_16->setMinimumSize(QSize(0, 31));
        label_16->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_16, 2, 0, 1, 1);

        kc6SB = new QDoubleSpinBox(gridLayoutWidget_18);
        kc6SB->setObjectName("kc6SB");
        kc6SB->setMinimumSize(QSize(0, 31));
        kc6SB->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(kc6SB, 7, 1, 1, 1);

        label_42 = new QLabel(gridLayoutWidget_18);
        label_42->setObjectName("label_42");
        label_42->setMinimumSize(QSize(0, 31));
        label_42->setMaximumSize(QSize(108, 32));

        gridLayout->addWidget(label_42, 1, 1, 1, 1);

        label_109 = new QLabel(gridLayoutWidget_18);
        label_109->setObjectName("label_109");
        label_109->setMinimumSize(QSize(0, 31));
        label_109->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(label_109, 1, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_18);
        label_20->setObjectName("label_20");
        label_20->setMinimumSize(QSize(0, 30));
        label_20->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(label_20, 0, 0, 1, 2);

        ScreenvirtualGains->addWidget(Input_GainsVirtual);
        ScreenGains = new QStackedWidget(GainsFrame);
        ScreenGains->setObjectName("ScreenGains");
        ScreenGains->setGeometry(QRect(0, 10, 361, 291));
        ScreenGains->setFont(font2);
        Labels_3 = new QWidget();
        Labels_3->setObjectName("Labels_3");
        gridLayoutWidget_19 = new QWidget(Labels_3);
        gridLayoutWidget_19->setObjectName("gridLayoutWidget_19");
        gridLayoutWidget_19->setGeometry(QRect(0, 0, 361, 291));
        gridLayoutWidget_19->setFont(font2);
        GridGainsSB = new QGridLayout(gridLayoutWidget_19);
        GridGainsSB->setObjectName("GridGainsSB");
        GridGainsSB->setContentsMargins(0, 0, 0, 0);
        label_43 = new QLabel(gridLayoutWidget_19);
        label_43->setObjectName("label_43");
        label_43->setMinimumSize(QSize(0, 31));
        label_43->setMaximumSize(QSize(16777215, 31));
        label_43->setFont(font2);
        label_43->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_43, 6, 0, 1, 1);

        label_Kp_2 = new QLabel(gridLayoutWidget_19);
        label_Kp_2->setObjectName("label_Kp_2");
        label_Kp_2->setMinimumSize(QSize(85, 31));
        label_Kp_2->setMaximumSize(QSize(85, 31));
        label_Kp_2->setFont(font2);
        label_Kp_2->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_Kp_2, 1, 1, 1, 1);

        kd5Label = new QLabel(gridLayoutWidget_19);
        kd5Label->setObjectName("kd5Label");
        kd5Label->setMinimumSize(QSize(0, 31));
        kd5Label->setMaximumSize(QSize(16777215, 31));
        kd5Label->setFont(font2);
        kd5Label->setFrameShape(QFrame::StyledPanel);
        kd5Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kd5Label, 6, 3, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_19);
        label_24->setObjectName("label_24");
        label_24->setMinimumSize(QSize(0, 31));
        label_24->setMaximumSize(QSize(16777215, 31));
        label_24->setFont(font2);
        label_24->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_24, 5, 0, 1, 1);

        kp2Label = new QLabel(gridLayoutWidget_19);
        kp2Label->setObjectName("kp2Label");
        kp2Label->setMinimumSize(QSize(0, 31));
        kp2Label->setMaximumSize(QSize(16777215, 31));
        kp2Label->setFont(font2);
        kp2Label->setFrameShape(QFrame::StyledPanel);
        kp2Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kp2Label, 3, 1, 1, 1);

        kd1Label = new QLabel(gridLayoutWidget_19);
        kd1Label->setObjectName("kd1Label");
        kd1Label->setMinimumSize(QSize(0, 31));
        kd1Label->setMaximumSize(QSize(16777215, 31));
        kd1Label->setFont(font2);
        kd1Label->setFrameShape(QFrame::StyledPanel);
        kd1Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kd1Label, 2, 3, 1, 1);

        label_Kd_2 = new QLabel(gridLayoutWidget_19);
        label_Kd_2->setObjectName("label_Kd_2");
        label_Kd_2->setMinimumSize(QSize(0, 31));
        label_Kd_2->setMaximumSize(QSize(16777215, 31));
        label_Kd_2->setFont(font2);
        label_Kd_2->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_Kd_2, 1, 3, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_19);
        label_26->setObjectName("label_26");
        label_26->setMinimumSize(QSize(0, 31));
        label_26->setMaximumSize(QSize(16777215, 31));
        label_26->setFont(font2);
        label_26->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_26, 3, 0, 1, 1);

        kp6Label = new QLabel(gridLayoutWidget_19);
        kp6Label->setObjectName("kp6Label");
        kp6Label->setMinimumSize(QSize(0, 31));
        kp6Label->setMaximumSize(QSize(16777215, 31));
        kp6Label->setFont(font2);
        kp6Label->setFrameShape(QFrame::StyledPanel);
        kp6Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kp6Label, 7, 1, 1, 1);

        kd6Label = new QLabel(gridLayoutWidget_19);
        kd6Label->setObjectName("kd6Label");
        kd6Label->setMinimumSize(QSize(0, 31));
        kd6Label->setMaximumSize(QSize(16777215, 31));
        kd6Label->setFont(font2);
        kd6Label->setFrameShape(QFrame::StyledPanel);
        kd6Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kd6Label, 7, 3, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_19);
        label_27->setObjectName("label_27");
        label_27->setMinimumSize(QSize(0, 31));
        label_27->setMaximumSize(QSize(16777215, 31));
        label_27->setFont(font2);
        label_27->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_27, 4, 0, 1, 1);

        kd2Label = new QLabel(gridLayoutWidget_19);
        kd2Label->setObjectName("kd2Label");
        kd2Label->setMinimumSize(QSize(0, 31));
        kd2Label->setMaximumSize(QSize(16777215, 31));
        kd2Label->setFont(font2);
        kd2Label->setFrameShape(QFrame::StyledPanel);
        kd2Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kd2Label, 3, 3, 1, 1);

        label_44 = new QLabel(gridLayoutWidget_19);
        label_44->setObjectName("label_44");
        label_44->setMinimumSize(QSize(0, 31));
        label_44->setMaximumSize(QSize(16777215, 31));
        label_44->setFont(font2);
        label_44->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_44, 7, 0, 1, 1);

        label_45 = new QLabel(gridLayoutWidget_19);
        label_45->setObjectName("label_45");
        label_45->setMinimumSize(QSize(0, 31));
        label_45->setMaximumSize(QSize(16777215, 31));
        label_45->setFont(font2);
        label_45->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_45, 2, 0, 1, 1);

        label_46 = new QLabel(gridLayoutWidget_19);
        label_46->setObjectName("label_46");
        label_46->setMinimumSize(QSize(0, 31));
        label_46->setMaximumSize(QSize(16777215, 31));
        label_46->setFont(font2);
        label_46->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_46, 1, 0, 1, 1);

        label_110 = new QLabel(gridLayoutWidget_19);
        label_110->setObjectName("label_110");
        label_110->setMinimumSize(QSize(350, 30));
        label_110->setMaximumSize(QSize(350, 30));

        GridGainsSB->addWidget(label_110, 0, 0, 1, 4);

        kd3Label = new QLabel(gridLayoutWidget_19);
        kd3Label->setObjectName("kd3Label");
        kd3Label->setMinimumSize(QSize(0, 31));
        kd3Label->setMaximumSize(QSize(16777215, 31));
        kd3Label->setFont(font2);
        kd3Label->setFrameShape(QFrame::StyledPanel);
        kd3Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kd3Label, 4, 3, 1, 1);

        kp4Label = new QLabel(gridLayoutWidget_19);
        kp4Label->setObjectName("kp4Label");
        kp4Label->setMinimumSize(QSize(0, 31));
        kp4Label->setMaximumSize(QSize(16777215, 31));
        kp4Label->setFont(font2);
        kp4Label->setFrameShape(QFrame::StyledPanel);
        kp4Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kp4Label, 5, 1, 1, 1);

        kp1Label = new QLabel(gridLayoutWidget_19);
        kp1Label->setObjectName("kp1Label");
        kp1Label->setMinimumSize(QSize(0, 31));
        kp1Label->setMaximumSize(QSize(16777215, 31));
        kp1Label->setFont(font2);
        kp1Label->setFrameShape(QFrame::StyledPanel);
        kp1Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kp1Label, 2, 1, 1, 1);

        kp5Label = new QLabel(gridLayoutWidget_19);
        kp5Label->setObjectName("kp5Label");
        kp5Label->setMinimumSize(QSize(0, 31));
        kp5Label->setMaximumSize(QSize(16777215, 31));
        kp5Label->setFont(font2);
        kp5Label->setFrameShape(QFrame::StyledPanel);
        kp5Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kp5Label, 6, 1, 1, 1);

        kp3Label = new QLabel(gridLayoutWidget_19);
        kp3Label->setObjectName("kp3Label");
        kp3Label->setMinimumSize(QSize(0, 31));
        kp3Label->setMaximumSize(QSize(16777215, 31));
        kp3Label->setFont(font2);
        kp3Label->setFrameShape(QFrame::StyledPanel);
        kp3Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kp3Label, 4, 1, 1, 1);

        kd4Label = new QLabel(gridLayoutWidget_19);
        kd4Label->setObjectName("kd4Label");
        kd4Label->setMinimumSize(QSize(0, 31));
        kd4Label->setMaximumSize(QSize(16777215, 31));
        kd4Label->setFont(font2);
        kd4Label->setFrameShape(QFrame::StyledPanel);
        kd4Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(kd4Label, 5, 3, 1, 1);

        ki4Label = new QLabel(gridLayoutWidget_19);
        ki4Label->setObjectName("ki4Label");
        ki4Label->setMinimumSize(QSize(0, 31));
        ki4Label->setMaximumSize(QSize(16777215, 31));
        ki4Label->setFont(font2);
        ki4Label->setFrameShape(QFrame::StyledPanel);
        ki4Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(ki4Label, 5, 2, 1, 1);

        ki2Label = new QLabel(gridLayoutWidget_19);
        ki2Label->setObjectName("ki2Label");
        ki2Label->setMinimumSize(QSize(0, 31));
        ki2Label->setMaximumSize(QSize(16777215, 31));
        ki2Label->setFont(font2);
        ki2Label->setFrameShape(QFrame::StyledPanel);
        ki2Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(ki2Label, 3, 2, 1, 1);

        ki3Label = new QLabel(gridLayoutWidget_19);
        ki3Label->setObjectName("ki3Label");
        ki3Label->setMinimumSize(QSize(0, 31));
        ki3Label->setMaximumSize(QSize(16777215, 31));
        ki3Label->setFont(font2);
        ki3Label->setFrameShape(QFrame::StyledPanel);
        ki3Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(ki3Label, 4, 2, 1, 1);

        label_Ki_2 = new QLabel(gridLayoutWidget_19);
        label_Ki_2->setObjectName("label_Ki_2");
        label_Ki_2->setEnabled(true);
        label_Ki_2->setMinimumSize(QSize(0, 31));
        label_Ki_2->setMaximumSize(QSize(85, 31));
        label_Ki_2->setFont(font2);
        label_Ki_2->setFrameShape(QFrame::NoFrame);

        GridGainsSB->addWidget(label_Ki_2, 1, 2, 1, 1);

        ki5Label = new QLabel(gridLayoutWidget_19);
        ki5Label->setObjectName("ki5Label");
        ki5Label->setMinimumSize(QSize(0, 31));
        ki5Label->setMaximumSize(QSize(16777215, 31));
        ki5Label->setFont(font2);
        ki5Label->setFrameShape(QFrame::StyledPanel);
        ki5Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(ki5Label, 6, 2, 1, 1);

        ki1Label = new QLabel(gridLayoutWidget_19);
        ki1Label->setObjectName("ki1Label");
        ki1Label->setMinimumSize(QSize(0, 31));
        ki1Label->setMaximumSize(QSize(16777215, 31));
        ki1Label->setFont(font2);
        ki1Label->setFrameShape(QFrame::StyledPanel);
        ki1Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(ki1Label, 2, 2, 1, 1);

        ki6Label = new QLabel(gridLayoutWidget_19);
        ki6Label->setObjectName("ki6Label");
        ki6Label->setMinimumSize(QSize(0, 31));
        ki6Label->setMaximumSize(QSize(16777215, 31));
        ki6Label->setFont(font2);
        ki6Label->setFrameShape(QFrame::StyledPanel);
        ki6Label->setFrameShadow(QFrame::Sunken);

        GridGainsSB->addWidget(ki6Label, 7, 2, 1, 1);

        ScreenGains->addWidget(Labels_3);
        Input = new QWidget();
        Input->setObjectName("Input");
        gridLayoutWidget_20 = new QWidget(Input);
        gridLayoutWidget_20->setObjectName("gridLayoutWidget_20");
        gridLayoutWidget_20->setGeometry(QRect(0, 0, 361, 291));
        GridGainsLabels = new QGridLayout(gridLayoutWidget_20);
        GridGainsLabels->setObjectName("GridGainsLabels");
        GridGainsLabels->setContentsMargins(0, 0, 0, 0);
        kd2SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kd2SB->setObjectName("kd2SB");
        kd2SB->setMinimumSize(QSize(83, 31));
        kd2SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kd2SB, 3, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_20);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(83, 31));
        label_2->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(label_2, 3, 0, 1, 1);

        ki1SB = new QDoubleSpinBox(gridLayoutWidget_20);
        ki1SB->setObjectName("ki1SB");
        ki1SB->setMinimumSize(QSize(83, 31));
        ki1SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(ki1SB, 2, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_20);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(83, 31));
        label_3->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(label_3, 7, 0, 1, 1);

        kp4SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kp4SB->setObjectName("kp4SB");
        kp4SB->setMinimumSize(QSize(83, 31));
        kp4SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kp4SB, 5, 1, 1, 1);

        ki4SB = new QDoubleSpinBox(gridLayoutWidget_20);
        ki4SB->setObjectName("ki4SB");
        ki4SB->setMinimumSize(QSize(83, 31));
        ki4SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(ki4SB, 5, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_20);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(83, 31));
        label_4->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(label_4, 6, 0, 1, 1);

        kd5SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kd5SB->setObjectName("kd5SB");
        kd5SB->setMinimumSize(QSize(83, 31));
        kd5SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kd5SB, 6, 3, 1, 1);

        kp5SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kp5SB->setObjectName("kp5SB");
        kp5SB->setMinimumSize(QSize(83, 31));
        kp5SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kp5SB, 6, 1, 1, 1);

        ki2SB = new QDoubleSpinBox(gridLayoutWidget_20);
        ki2SB->setObjectName("ki2SB");
        ki2SB->setMinimumSize(QSize(83, 31));
        ki2SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(ki2SB, 3, 2, 1, 1);

        label_Ki = new QLabel(gridLayoutWidget_20);
        label_Ki->setObjectName("label_Ki");
        label_Ki->setMinimumSize(QSize(85, 31));
        label_Ki->setMaximumSize(QSize(85, 31));

        GridGainsLabels->addWidget(label_Ki, 1, 2, 1, 1);

        kp6SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kp6SB->setObjectName("kp6SB");
        kp6SB->setMinimumSize(QSize(83, 31));
        kp6SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kp6SB, 7, 1, 1, 1);

        kp1SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kp1SB->setObjectName("kp1SB");
        kp1SB->setMinimumSize(QSize(83, 31));
        kp1SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kp1SB, 2, 1, 1, 1);

        kd1SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kd1SB->setObjectName("kd1SB");
        kd1SB->setMinimumSize(QSize(83, 31));
        kd1SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kd1SB, 2, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_20);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(83, 31));
        label_5->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(label_5, 2, 0, 1, 1);

        label_57 = new QLabel(gridLayoutWidget_20);
        label_57->setObjectName("label_57");
        label_57->setMinimumSize(QSize(83, 31));
        label_57->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(label_57, 4, 0, 1, 1);

        label_Kp = new QLabel(gridLayoutWidget_20);
        label_Kp->setObjectName("label_Kp");
        label_Kp->setMinimumSize(QSize(85, 31));
        label_Kp->setMaximumSize(QSize(85, 31));

        GridGainsLabels->addWidget(label_Kp, 1, 1, 1, 1);

        label_58 = new QLabel(gridLayoutWidget_20);
        label_58->setObjectName("label_58");
        label_58->setMinimumSize(QSize(83, 31));
        label_58->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(label_58, 5, 0, 1, 1);

        ki6SB = new QDoubleSpinBox(gridLayoutWidget_20);
        ki6SB->setObjectName("ki6SB");
        ki6SB->setMinimumSize(QSize(83, 31));
        ki6SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(ki6SB, 7, 2, 1, 1);

        kd4SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kd4SB->setObjectName("kd4SB");
        kd4SB->setMinimumSize(QSize(83, 31));
        kd4SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kd4SB, 5, 3, 1, 1);

        kp3SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kp3SB->setObjectName("kp3SB");
        kp3SB->setMinimumSize(QSize(83, 31));
        kp3SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kp3SB, 4, 1, 1, 1);

        label_Kd = new QLabel(gridLayoutWidget_20);
        label_Kd->setObjectName("label_Kd");
        label_Kd->setMinimumSize(QSize(85, 31));
        label_Kd->setMaximumSize(QSize(85, 31));

        GridGainsLabels->addWidget(label_Kd, 1, 3, 1, 1);

        ki3SB = new QDoubleSpinBox(gridLayoutWidget_20);
        ki3SB->setObjectName("ki3SB");
        ki3SB->setMinimumSize(QSize(83, 31));
        ki3SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(ki3SB, 4, 2, 1, 1);

        kd3SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kd3SB->setObjectName("kd3SB");
        kd3SB->setMinimumSize(QSize(83, 31));
        kd3SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kd3SB, 4, 3, 1, 1);

        kp2SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kp2SB->setObjectName("kp2SB");
        kp2SB->setMinimumSize(QSize(83, 31));
        kp2SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kp2SB, 3, 1, 1, 1);

        label_59 = new QLabel(gridLayoutWidget_20);
        label_59->setObjectName("label_59");
        label_59->setMinimumSize(QSize(86, 31));
        label_59->setMaximumSize(QSize(86, 31));

        GridGainsLabels->addWidget(label_59, 1, 0, 1, 1);

        kd6SB = new QDoubleSpinBox(gridLayoutWidget_20);
        kd6SB->setObjectName("kd6SB");
        kd6SB->setMinimumSize(QSize(83, 31));
        kd6SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(kd6SB, 7, 3, 1, 1);

        ki5SB = new QDoubleSpinBox(gridLayoutWidget_20);
        ki5SB->setObjectName("ki5SB");
        ki5SB->setMinimumSize(QSize(83, 31));
        ki5SB->setMaximumSize(QSize(16777215, 31));

        GridGainsLabels->addWidget(ki5SB, 6, 2, 1, 1);

        label = new QLabel(gridLayoutWidget_20);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));

        GridGainsLabels->addWidget(label, 0, 0, 1, 4);

        ScreenGains->addWidget(Input);
        Screenmc = new QStackedWidget(GainsFrame);
        Screenmc->setObjectName("Screenmc");
        Screenmc->setGeometry(QRect(370, 310, 231, 41));
        Screenmc->setFont(font2);
        Labels_mc = new QWidget();
        Labels_mc->setObjectName("Labels_mc");
        horizontalLayoutWidget_3 = new QWidget(Labels_mc);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 231, 33));
        horizontalLayoutWidget_3->setFont(font2);
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Masavirtual = new QLabel(horizontalLayoutWidget_3);
        label_Masavirtual->setObjectName("label_Masavirtual");
        label_Masavirtual->setMaximumSize(QSize(900, 31));
        label_Masavirtual->setFont(font2);

        horizontalLayout_4->addWidget(label_Masavirtual);

        mcValueLabel = new QLabel(horizontalLayoutWidget_3);
        mcValueLabel->setObjectName("mcValueLabel");
        mcValueLabel->setMinimumSize(QSize(0, 26));
        mcValueLabel->setMaximumSize(QSize(804, 31));
        mcValueLabel->setFont(font2);
        mcValueLabel->setFrameShape(QFrame::StyledPanel);
        mcValueLabel->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(mcValueLabel);

        Screenmc->addWidget(Labels_mc);
        Input_mc = new QWidget();
        Input_mc->setObjectName("Input_mc");
        horizontalLayoutWidget_4 = new QWidget(Input_mc);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(0, 0, 231, 33));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_76 = new QLabel(horizontalLayoutWidget_4);
        label_76->setObjectName("label_76");

        horizontalLayout_5->addWidget(label_76);

        mcValueSB = new QDoubleSpinBox(horizontalLayoutWidget_4);
        mcValueSB->setObjectName("mcValueSB");
        mcValueSB->setMinimumSize(QSize(84, 31));

        horizontalLayout_5->addWidget(mcValueSB);

        Screenmc->addWidget(Input_mc);
        cambiarGainsPB = new QPushButton(GainsFrame);
        cambiarGainsPB->setObjectName("cambiarGainsPB");
        cambiarGainsPB->setGeometry(QRect(210, 310, 151, 31));
        cambiarGainsPB->setFont(font3);
        cambiarGainsPB->setCursor(QCursor(Qt::PointingHandCursor));
        ScreenLg = new QFrame(GainsFrame);
        ScreenLg->setObjectName("ScreenLg");
        ScreenLg->setGeometry(QRect(0, 310, 181, 41));
        ScreenLg->setFrameShape(QFrame::NoFrame);
        ScreenLg->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_21 = new QWidget(ScreenLg);
        gridLayoutWidget_21->setObjectName("gridLayoutWidget_21");
        gridLayoutWidget_21->setGeometry(QRect(0, 0, 174, 33));
        Layout_Lg = new QGridLayout(gridLayoutWidget_21);
        Layout_Lg->setObjectName("Layout_Lg");
        Layout_Lg->setContentsMargins(0, 0, 0, 0);
        label_Lg = new QLabel(gridLayoutWidget_21);
        label_Lg->setObjectName("label_Lg");
        label_Lg->setMinimumSize(QSize(83, 31));
        label_Lg->setMaximumSize(QSize(83, 16777215));

        Layout_Lg->addWidget(label_Lg, 0, 0, 1, 1);

        label_Lg_value = new QLabel(gridLayoutWidget_21);
        label_Lg_value->setObjectName("label_Lg_value");
        label_Lg_value->setMinimumSize(QSize(83, 0));
        label_Lg_value->setMaximumSize(QSize(83, 83));
        label_Lg_value->setFrameShape(QFrame::StyledPanel);

        Layout_Lg->addWidget(label_Lg_value, 0, 1, 1, 1);

        PosicionFrame = new QFrame(RobotSetting);
        PosicionFrame->setObjectName("PosicionFrame");
        PosicionFrame->setGeometry(QRect(1040, 20, 531, 381));
        PosicionFrame->setFrameShape(QFrame::NoFrame);
        PosicionFrame->setFrameShadow(QFrame::Raised);
        ScreenQd = new QStackedWidget(PosicionFrame);
        ScreenQd->setObjectName("ScreenQd");
        ScreenQd->setGeometry(QRect(270, 10, 271, 251));
        ScreenQd->setMinimumSize(QSize(0, 0));
        ScreenQd->setMaximumSize(QSize(16777215, 350));
        ScreenQd->setFont(font2);
        QdLabels = new QWidget();
        QdLabels->setObjectName("QdLabels");
        gridLayoutWidget_24 = new QWidget(QdLabels);
        gridLayoutWidget_24->setObjectName("gridLayoutWidget_24");
        gridLayoutWidget_24->setGeometry(QRect(10, 0, 284, 242));
        gridLayout_Qd_labels = new QGridLayout(gridLayoutWidget_24);
        gridLayout_Qd_labels->setObjectName("gridLayout_Qd_labels");
        gridLayout_Qd_labels->setContentsMargins(0, 0, 0, 0);
        label_130 = new QLabel(gridLayoutWidget_24);
        label_130->setObjectName("label_130");
        label_130->setMinimumSize(QSize(0, 0));
        label_130->setMaximumSize(QSize(50, 24));
        label_130->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_130, 3, 2, 1, 1);

        label_131 = new QLabel(gridLayoutWidget_24);
        label_131->setObjectName("label_131");
        label_131->setMinimumSize(QSize(0, 0));
        label_131->setMaximumSize(QSize(50, 2800));
        label_131->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_131, 5, 2, 1, 1);

        label_134 = new QLabel(gridLayoutWidget_24);
        label_134->setObjectName("label_134");
        label_134->setMinimumSize(QSize(0, 0));
        label_134->setMaximumSize(QSize(50, 24));
        label_134->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_134, 1, 2, 1, 1);

        label_135 = new QLabel(gridLayoutWidget_24);
        label_135->setObjectName("label_135");
        label_135->setMinimumSize(QSize(0, 0));
        label_135->setMaximumSize(QSize(50, 24));
        label_135->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_135, 2, 2, 1, 1);

        label_posqd2 = new QLabel(gridLayoutWidget_24);
        label_posqd2->setObjectName("label_posqd2");
        label_posqd2->setMinimumSize(QSize(0, 24));
        label_posqd2->setMaximumSize(QSize(16777215, 24));
        label_posqd2->setFont(font2);
        label_posqd2->setFrameShape(QFrame::StyledPanel);
        label_posqd2->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_posqd2, 2, 3, 1, 1);

        label_posqd5 = new QLabel(gridLayoutWidget_24);
        label_posqd5->setObjectName("label_posqd5");
        label_posqd5->setMinimumSize(QSize(0, 24));
        label_posqd5->setMaximumSize(QSize(16777215, 24));
        label_posqd5->setFont(font2);
        label_posqd5->setFrameShape(QFrame::StyledPanel);
        label_posqd5->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_posqd5, 5, 3, 1, 1);

        label_posqd4 = new QLabel(gridLayoutWidget_24);
        label_posqd4->setObjectName("label_posqd4");
        label_posqd4->setMinimumSize(QSize(0, 24));
        label_posqd4->setMaximumSize(QSize(16777215, 24));
        label_posqd4->setFont(font2);
        label_posqd4->setFrameShape(QFrame::StyledPanel);
        label_posqd4->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_posqd4, 4, 3, 1, 1);

        label_posqd6 = new QLabel(gridLayoutWidget_24);
        label_posqd6->setObjectName("label_posqd6");
        label_posqd6->setMinimumSize(QSize(0, 24));
        label_posqd6->setMaximumSize(QSize(16777215, 24));
        label_posqd6->setFont(font2);
        label_posqd6->setFrameShape(QFrame::StyledPanel);
        label_posqd6->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_posqd6, 6, 3, 1, 1);

        label_133 = new QLabel(gridLayoutWidget_24);
        label_133->setObjectName("label_133");
        label_133->setMinimumSize(QSize(0, 0));
        label_133->setMaximumSize(QSize(21300, 2800));
        label_133->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_133, 6, 2, 1, 1);

        label_137 = new QLabel(gridLayoutWidget_24);
        label_137->setObjectName("label_137");
        label_137->setMinimumSize(QSize(0, 30));
        label_137->setMaximumSize(QSize(16777215, 30));
        label_137->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_137, 0, 1, 1, 3);

        label_posqd1 = new QLabel(gridLayoutWidget_24);
        label_posqd1->setObjectName("label_posqd1");
        label_posqd1->setMinimumSize(QSize(0, 24));
        label_posqd1->setMaximumSize(QSize(10000, 24));
        label_posqd1->setFont(font2);
        label_posqd1->setFrameShape(QFrame::StyledPanel);
        label_posqd1->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_posqd1, 1, 3, 1, 1);

        label_136 = new QLabel(gridLayoutWidget_24);
        label_136->setObjectName("label_136");
        label_136->setMinimumSize(QSize(0, 24));
        label_136->setMaximumSize(QSize(16777215, 23));
        label_136->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_136, 7, 1, 1, 2);

        label_posqd3 = new QLabel(gridLayoutWidget_24);
        label_posqd3->setObjectName("label_posqd3");
        label_posqd3->setMinimumSize(QSize(0, 24));
        label_posqd3->setMaximumSize(QSize(16777215, 24));
        label_posqd3->setFont(font2);
        label_posqd3->setFrameShape(QFrame::StyledPanel);
        label_posqd3->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_posqd3, 3, 3, 1, 1);

        label_132 = new QLabel(gridLayoutWidget_24);
        label_132->setObjectName("label_132");
        label_132->setMinimumSize(QSize(0, 24));
        label_132->setMaximumSize(QSize(50, 24));
        label_132->setFont(font2);

        gridLayout_Qd_labels->addWidget(label_132, 4, 2, 1, 1);

        label_gripperValueQd = new QLabel(gridLayoutWidget_24);
        label_gripperValueQd->setObjectName("label_gripperValueQd");
        label_gripperValueQd->setMinimumSize(QSize(0, 24));
        label_gripperValueQd->setMaximumSize(QSize(16777215, 28));
        label_gripperValueQd->setFont(font2);
        label_gripperValueQd->setFrameShape(QFrame::StyledPanel);
        label_gripperValueQd->setFrameShadow(QFrame::Sunken);

        gridLayout_Qd_labels->addWidget(label_gripperValueQd, 7, 3, 1, 1);

        label_143 = new QLabel(gridLayoutWidget_24);
        label_143->setObjectName("label_143");
        label_143->setMinimumSize(QSize(31, 0));
        label_143->setMaximumSize(QSize(31, 15));

        gridLayout_Qd_labels->addWidget(label_143, 1, 4, 1, 1);

        ScreenQd->addWidget(QdLabels);
        QdSpinBox = new QWidget();
        QdSpinBox->setObjectName("QdSpinBox");
        gridLayoutWidget_23 = new QWidget(QdSpinBox);
        gridLayoutWidget_23->setObjectName("gridLayoutWidget_23");
        gridLayoutWidget_23->setGeometry(QRect(10, 0, 284, 242));
        gridLayout_Qd_SB = new QGridLayout(gridLayoutWidget_23);
        gridLayout_Qd_SB->setObjectName("gridLayout_Qd_SB");
        gridLayout_Qd_SB->setContentsMargins(0, 0, 0, 0);
        qd4SB = new QDoubleSpinBox(gridLayoutWidget_23);
        qd4SB->setObjectName("qd4SB");
        qd4SB->setMinimumSize(QSize(0, 24));
        qd4SB->setMaximumSize(QSize(123, 24));
        qd4SB->setMinimum(-148.979999999999990);
        qd4SB->setMaximum(148.979999999999990);

        gridLayout_Qd_SB->addWidget(qd4SB, 4, 3, 1, 1);

        label_129 = new QLabel(gridLayoutWidget_23);
        label_129->setObjectName("label_129");
        label_129->setMinimumSize(QSize(0, 30));
        label_129->setMaximumSize(QSize(16777215, 30));
        label_129->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_129, 0, 1, 1, 3);

        label_124 = new QLabel(gridLayoutWidget_23);
        label_124->setObjectName("label_124");
        label_124->setMinimumSize(QSize(0, 24));
        label_124->setMaximumSize(QSize(50, 24));
        label_124->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_124, 4, 2, 1, 1);

        qd2SB = new QDoubleSpinBox(gridLayoutWidget_23);
        qd2SB->setObjectName("qd2SB");
        qd2SB->setMinimumSize(QSize(0, 24));
        qd2SB->setMaximumSize(QSize(123, 24));
        qd2SB->setMinimum(-150.099999999999994);
        qd2SB->setMaximum(150.099999999999994);

        gridLayout_Qd_SB->addWidget(qd2SB, 2, 3, 1, 1);

        label_123 = new QLabel(gridLayoutWidget_23);
        label_123->setObjectName("label_123");
        label_123->setMinimumSize(QSize(0, 24));
        label_123->setMaximumSize(QSize(50, 24));
        label_123->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_123, 5, 2, 1, 1);

        qd3SB = new QDoubleSpinBox(gridLayoutWidget_23);
        qd3SB->setObjectName("qd3SB");
        qd3SB->setMinimumSize(QSize(0, 24));
        qd3SB->setMaximumSize(QSize(123, 24));
        qd3SB->setMinimum(-150.099999999999994);
        qd3SB->setMaximum(150.099999999999994);

        gridLayout_Qd_SB->addWidget(qd3SB, 3, 3, 1, 1);

        qd6SB = new QDoubleSpinBox(gridLayoutWidget_23);
        qd6SB->setObjectName("qd6SB");
        qd6SB->setMinimumSize(QSize(0, 24));
        qd6SB->setMaximumSize(QSize(123, 24));
        qd6SB->setMinimum(-148.979999999999990);
        qd6SB->setMaximum(148.979999999999990);

        gridLayout_Qd_SB->addWidget(qd6SB, 6, 3, 1, 1);

        label_126 = new QLabel(gridLayoutWidget_23);
        label_126->setObjectName("label_126");
        label_126->setMinimumSize(QSize(0, 24));
        label_126->setMaximumSize(QSize(50, 24));
        label_126->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_126, 1, 2, 1, 1);

        qd1SB = new QDoubleSpinBox(gridLayoutWidget_23);
        qd1SB->setObjectName("qd1SB");
        qd1SB->setMinimumSize(QSize(0, 24));
        qd1SB->setMaximumSize(QSize(123, 24));
        qd1SB->setMinimum(-154.099999999999994);
        qd1SB->setValue(0.000000000000000);

        gridLayout_Qd_SB->addWidget(qd1SB, 1, 3, 1, 1);

        label_122 = new QLabel(gridLayoutWidget_23);
        label_122->setObjectName("label_122");
        label_122->setMinimumSize(QSize(0, 24));
        label_122->setMaximumSize(QSize(50, 24));
        label_122->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_122, 3, 2, 1, 1);

        label_127 = new QLabel(gridLayoutWidget_23);
        label_127->setObjectName("label_127");
        label_127->setMinimumSize(QSize(0, 24));
        label_127->setMaximumSize(QSize(50, 24));
        label_127->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_127, 2, 2, 1, 1);

        qd5SB = new QDoubleSpinBox(gridLayoutWidget_23);
        qd5SB->setObjectName("qd5SB");
        qd5SB->setMinimumSize(QSize(0, 24));
        qd5SB->setMaximumSize(QSize(123, 24));
        qd5SB->setMinimum(-144.969999999999999);
        qd5SB->setMaximum(145.000000000000000);

        gridLayout_Qd_SB->addWidget(qd5SB, 5, 3, 1, 1);

        label_125 = new QLabel(gridLayoutWidget_23);
        label_125->setObjectName("label_125");
        label_125->setMinimumSize(QSize(0, 24));
        label_125->setMaximumSize(QSize(21300, 24));
        label_125->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_125, 6, 2, 1, 1);

        gripValueSB = new QDoubleSpinBox(gridLayoutWidget_23);
        gripValueSB->setObjectName("gripValueSB");
        gripValueSB->setMinimumSize(QSize(0, 24));
        gripValueSB->setMaximumSize(QSize(123, 24));

        gridLayout_Qd_SB->addWidget(gripValueSB, 7, 3, 1, 1);

        label_128 = new QLabel(gridLayoutWidget_23);
        label_128->setObjectName("label_128");
        label_128->setMinimumSize(QSize(141, 24));
        label_128->setMaximumSize(QSize(141, 24));
        label_128->setFont(font2);

        gridLayout_Qd_SB->addWidget(label_128, 7, 1, 1, 2);

        label_144 = new QLabel(gridLayoutWidget_23);
        label_144->setObjectName("label_144");
        label_144->setMinimumSize(QSize(31, 0));
        label_144->setMaximumSize(QSize(31, 15));

        gridLayout_Qd_SB->addWidget(label_144, 1, 4, 1, 1);

        ScreenQd->addWidget(QdSpinBox);
        CambiarQdPB = new QPushButton(PosicionFrame);
        CambiarQdPB->setObjectName("CambiarQdPB");
        CambiarQdPB->setGeometry(QRect(310, 260, 211, 25));
        CambiarQdPB->setFont(font3);
        CambiarQdPB->setCursor(QCursor(Qt::PointingHandCursor));
        PosPackPB = new QPushButton(PosicionFrame);
        PosPackPB->setObjectName("PosPackPB");
        PosPackPB->setGeometry(QRect(310, 350, 211, 25));
        PosPackPB->setFont(font8);
        PosPackPB->setCursor(QCursor(Qt::PointingHandCursor));
        PosZeroPB = new QPushButton(PosicionFrame);
        PosZeroPB->setObjectName("PosZeroPB");
        PosZeroPB->setGeometry(QRect(310, 290, 211, 25));
        PosZeroPB->setFont(font8);
        PosZeroPB->setCursor(QCursor(Qt::PointingHandCursor));
        PosHomePB = new QPushButton(PosicionFrame);
        PosHomePB->setObjectName("PosHomePB");
        PosHomePB->setGeometry(QRect(309, 320, 211, 24));
        PosHomePB->setFont(font7);
        PosHomePB->setCursor(QCursor(Qt::PointingHandCursor));
        gridLayoutWidget_22 = new QWidget(PosicionFrame);
        gridLayoutWidget_22->setObjectName("gridLayoutWidget_22");
        gridLayoutWidget_22->setGeometry(QRect(0, 10, 281, 301));
        gridLayoutWidget_22->setFont(font2);
        QLabels = new QGridLayout(gridLayoutWidget_22);
        QLabels->setObjectName("QLabels");
        QLabels->setContentsMargins(0, 0, 0, 0);
        label_q3 = new QLabel(gridLayoutWidget_22);
        label_q3->setObjectName("label_q3");
        label_q3->setMaximumSize(QSize(16777215, 24));
        label_q3->setFont(font2);
        label_q3->setFrameShape(QFrame::StyledPanel);
        label_q3->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_q3, 3, 3, 1, 2);

        label_q6 = new QLabel(gridLayoutWidget_22);
        label_q6->setObjectName("label_q6");
        label_q6->setMaximumSize(QSize(16777215, 24));
        label_q6->setFont(font2);
        label_q6->setFrameShape(QFrame::StyledPanel);
        label_q6->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_q6, 6, 3, 1, 2);

        label_113 = new QLabel(gridLayoutWidget_22);
        label_113->setObjectName("label_113");
        label_113->setMaximumSize(QSize(16777215, 28));
        label_113->setFont(font2);

        QLabels->addWidget(label_113, 3, 2, 1, 1);

        label_139 = new QLabel(gridLayoutWidget_22);
        label_139->setObjectName("label_139");
        label_139->setMinimumSize(QSize(31, 0));
        label_139->setMaximumSize(QSize(31, 15));

        QLabels->addWidget(label_139, 8, 0, 1, 1);

        label_121 = new QLabel(gridLayoutWidget_22);
        label_121->setObjectName("label_121");
        label_121->setMaximumSize(QSize(16777215, 28));
        label_121->setFont(font2);

        QLabels->addWidget(label_121, 2, 2, 1, 1);

        label_q5 = new QLabel(gridLayoutWidget_22);
        label_q5->setObjectName("label_q5");
        label_q5->setMaximumSize(QSize(16777215, 24));
        label_q5->setFont(font2);
        label_q5->setFrameShape(QFrame::StyledPanel);
        label_q5->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_q5, 5, 3, 1, 2);

        label_115 = new QLabel(gridLayoutWidget_22);
        label_115->setObjectName("label_115");
        label_115->setMaximumSize(QSize(16777215, 28));
        label_115->setFont(font2);

        QLabels->addWidget(label_115, 4, 2, 1, 1);

        label_EFy = new QLabel(gridLayoutWidget_22);
        label_EFy->setObjectName("label_EFy");
        label_EFy->setMaximumSize(QSize(31, 16777215));
        label_EFy->setFont(font2);
        label_EFy->setFrameShape(QFrame::StyledPanel);
        label_EFy->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_EFy, 8, 3, 1, 1);

        label_141 = new QLabel(gridLayoutWidget_22);
        label_141->setObjectName("label_141");
        label_141->setMinimumSize(QSize(31, 0));
        label_141->setMaximumSize(QSize(31, 15));

        QLabels->addWidget(label_141, 8, 4, 1, 1);

        label_114 = new QLabel(gridLayoutWidget_22);
        label_114->setObjectName("label_114");
        label_114->setMaximumSize(QSize(16777215, 28));
        label_114->setFont(font2);

        QLabels->addWidget(label_114, 6, 2, 1, 1);

        label_112 = new QLabel(gridLayoutWidget_22);
        label_112->setObjectName("label_112");
        label_112->setMaximumSize(QSize(16777215, 28));
        label_112->setFont(font2);

        QLabels->addWidget(label_112, 1, 2, 1, 1);

        label_118 = new QLabel(gridLayoutWidget_22);
        label_118->setObjectName("label_118");
        label_118->setMaximumSize(QSize(16777215, 28));
        label_118->setFont(font2);

        QLabels->addWidget(label_118, 5, 2, 1, 1);

        label_q2 = new QLabel(gridLayoutWidget_22);
        label_q2->setObjectName("label_q2");
        label_q2->setMaximumSize(QSize(16777215, 24));
        label_q2->setFont(font2);
        label_q2->setFrameShape(QFrame::StyledPanel);
        label_q2->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_q2, 2, 3, 1, 2);

        label_gripperValue = new QLabel(gridLayoutWidget_22);
        label_gripperValue->setObjectName("label_gripperValue");
        label_gripperValue->setMaximumSize(QSize(16777215, 31));
        label_gripperValue->setFont(font2);
        label_gripperValue->setFrameShape(QFrame::StyledPanel);
        label_gripperValue->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_gripperValue, 10, 4, 1, 2);

        label_q4 = new QLabel(gridLayoutWidget_22);
        label_q4->setObjectName("label_q4");
        label_q4->setMaximumSize(QSize(16777215, 24));
        label_q4->setFont(font2);
        label_q4->setFrameShape(QFrame::StyledPanel);
        label_q4->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_q4, 4, 3, 1, 2);

        label_EFz = new QLabel(gridLayoutWidget_22);
        label_EFz->setObjectName("label_EFz");
        label_EFz->setMinimumSize(QSize(31, 0));
        label_EFz->setMaximumSize(QSize(31, 16777215));
        label_EFz->setFont(font2);
        label_EFz->setFrameShape(QFrame::StyledPanel);
        label_EFz->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_EFz, 8, 5, 1, 1);

        label_q1 = new QLabel(gridLayoutWidget_22);
        label_q1->setObjectName("label_q1");
        label_q1->setMaximumSize(QSize(16777215, 24));
        label_q1->setFont(font2);
        label_q1->setFrameShape(QFrame::StyledPanel);
        label_q1->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_q1, 1, 3, 1, 2);

        label_140 = new QLabel(gridLayoutWidget_22);
        label_140->setObjectName("label_140");
        label_140->setMinimumSize(QSize(31, 0));
        label_140->setMaximumSize(QSize(31, 25));

        QLabels->addWidget(label_140, 8, 2, 1, 1);

        label_EFx = new QLabel(gridLayoutWidget_22);
        label_EFx->setObjectName("label_EFx");
        label_EFx->setMaximumSize(QSize(31, 16777215));
        label_EFx->setFont(font2);
        label_EFx->setFrameShape(QFrame::StyledPanel);
        label_EFx->setFrameShadow(QFrame::Sunken);

        QLabels->addWidget(label_EFx, 8, 1, 1, 1);

        label_116 = new QLabel(gridLayoutWidget_22);
        label_116->setObjectName("label_116");
        label_116->setMaximumSize(QSize(16777215, 23));
        label_116->setFont(font2);

        QLabels->addWidget(label_116, 7, 0, 1, 6);

        label_117 = new QLabel(gridLayoutWidget_22);
        label_117->setObjectName("label_117");
        label_117->setMinimumSize(QSize(0, 30));
        label_117->setMaximumSize(QSize(16777215, 29));
        label_117->setFont(font2);

        QLabels->addWidget(label_117, 0, 1, 1, 5);

        label_120 = new QLabel(gridLayoutWidget_22);
        label_120->setObjectName("label_120");
        label_120->setMaximumSize(QSize(16777215, 31));
        label_120->setFont(font2);

        QLabels->addWidget(label_120, 10, 1, 1, 3);

        label_EFz->raise();
        label_q4->raise();
        label_116->raise();
        label_117->raise();
        label_q5->raise();
        label_EFx->raise();
        label_q3->raise();
        label_q1->raise();
        label_q6->raise();
        label_q2->raise();
        label_EFy->raise();
        label_120->raise();
        label_139->raise();
        label_140->raise();
        label_141->raise();
        label_112->raise();
        label_121->raise();
        label_113->raise();
        label_115->raise();
        label_118->raise();
        label_114->raise();
        label_gripperValue->raise();
        line_2 = new QFrame(RobotSetting);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(1010, 20, 51, 381));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(RobotSetting);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(350, 20, 41, 391));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2->raise();
        line_3->raise();
        SettingFrame->raise();
        GainsFrame->raise();
        PosicionFrame->raise();
        Plots = new QGroupBox(scrollContents);
        Plots->setObjectName("Plots");
        Plots->setGeometry(QRect(10, 469, 1861, 461));
        Plots->setMinimumSize(QSize(0, 21));
        Plots->setMaximumSize(QSize(1881, 481));
        Plots->setFont(font2);
        ActivarGraficasPB = new QPushButton(Plots);
        ActivarGraficasPB->setObjectName("ActivarGraficasPB");
        ActivarGraficasPB->setGeometry(QRect(40, 40, 121, 25));
        ActivarGraficasPB->setFont(font);
        ActivarGraficasPB->setCursor(QCursor(Qt::PointingHandCursor));
        ElegirGraficaCB = new QComboBox(Plots);
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->addItem(QString());
        ElegirGraficaCB->setObjectName("ElegirGraficaCB");
        ElegirGraficaCB->setEnabled(false);
        ElegirGraficaCB->setGeometry(QRect(40, 190, 221, 23));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Arial")});
        font9.setPointSize(12);
        ElegirGraficaCB->setFont(font9);
        ElegirGraficaCB->setCursor(QCursor(Qt::PointingHandCursor));
        label_agraficar = new QLabel(Plots);
        label_agraficar->setObjectName("label_agraficar");
        label_agraficar->setGeometry(QRect(40, 120, 81, 31));
        label_posarticulaciones = new QLabel(Plots);
        label_posarticulaciones->setObjectName("label_posarticulaciones");
        label_posarticulaciones->setGeometry(QRect(40, 160, 231, 16));
        PosicionDeseadaRD = new QCheckBox(Plots);
        PosicionDeseadaRD->setObjectName("PosicionDeseadaRD");
        PosicionDeseadaRD->setGeometry(QRect(40, 220, 171, 22));
        PosicionDeseadaRD->setChecked(true);
        RunMode = new QGroupBox(scrollContents);
        RunMode->setObjectName("RunMode");
        RunMode->setGeometry(QRect(1610, 0, 261, 51));
        RunMode->setFont(font2);
        SimulacionRB = new QRadioButton(RunMode);
        SimulacionRB->setObjectName("SimulacionRB");
        SimulacionRB->setGeometry(QRect(3, 30, 101, 16));
        SimulacionRB->setFont(font);
        SimulacionRB->setChecked(true);
        CorrerRobotRB = new QRadioButton(RunMode);
        CorrerRobotRB->setObjectName("CorrerRobotRB");
        CorrerRobotRB->setGeometry(QRect(110, 30, 161, 16));
        CorrerRobotRB->setFont(font);
        scrollArea->setWidget(scrollContents);
        label_KinovaGen3Lite->raise();
        formLayoutWidget->raise();
        Ejecucion->raise();
        RobotSetting->raise();
        Plots->raise();
        RunMode->raise();
        ConectarPB->raise();

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 22));
        menuREAD_ME = new QMenu(menubar);
        menuREAD_ME->setObjectName("menuREAD_ME");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuREAD_ME->menuAction());

        retranslateUi(MainWindow);

        ScreenRunStop->setCurrentIndex(0);
        ScreenTiempo->setCurrentIndex(0);
        ScreenvirtualGains->setCurrentIndex(0);
        ScreenGains->setCurrentIndex(0);
        Screenmc->setCurrentIndex(0);
        ScreenQd->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_KinovaGen3Lite->setText(QCoreApplication::translate("MainWindow", "Kinova Gen 3 Lite", nullptr));
        ConectarPB->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        label_Estado->setText(QCoreApplication::translate("MainWindow", "Estado:", nullptr));
        label_EstadoActual->setText(QCoreApplication::translate("MainWindow", "No conectado", nullptr));
        label_Robot->setText(QCoreApplication::translate("MainWindow", "Robot IP:", nullptr));
        label_IP->setText(QCoreApplication::translate("MainWindow", "No conectado", nullptr));
        Ejecucion->setTitle(QCoreApplication::translate("MainWindow", "Ejecuci\303\263n", nullptr));
        label_138->setText(QCoreApplication::translate("MainWindow", "Errores:", nullptr));
        IniciarPB->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        moverAltoNivelPB->setText(QCoreApplication::translate("MainWindow", "Mover el Robot a otra Posici\303\263n", nullptr));
        StopPB->setText(QCoreApplication::translate("MainWindow", "Detener", nullptr));
        FinalizarPB->setText(QCoreApplication::translate("MainWindow", "Finalizar", nullptr));
        CancelarGravedadPB->setText(QCoreApplication::translate("MainWindow", "Cancelar Gravedad", nullptr));
        moverAltoNivelPB_2->setText(QCoreApplication::translate("MainWindow", "Mover el Robot a otra Posici\303\263n", nullptr));
        FinalizarPB_2->setText(QCoreApplication::translate("MainWindow", "Terminar", nullptr));
        GuardarTrayectoriaPB->setText(QCoreApplication::translate("MainWindow", "Guardar Trayectoria", nullptr));
        AccionTerminadaRB->setText(QCoreApplication::translate("MainWindow", "Acci\303\263n Completada", nullptr));
        goToHomePB->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        goToZeroPB->setText(QCoreApplication::translate("MainWindow", "Zero", nullptr));
        goToPackPB->setText(QCoreApplication::translate("MainWindow", "Packaging", nullptr));
        regresarMenuPB->setText(QCoreApplication::translate("MainWindow", "Regresar", nullptr));
        label_142->setText(QCoreApplication::translate("MainWindow", "Mover el Robot a:", nullptr));
        RobotSetting->setTitle(QCoreApplication::translate("MainWindow", "Configuraci\303\263n del Robot", nullptr));
        CambiarTiempoPB->setText(QCoreApplication::translate("MainWindow", "Cambiar Tiempo", nullptr));
        CambiarControlPB->setText(QCoreApplication::translate("MainWindow", "Seleccionar Control", nullptr));
        label_Segundos->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_101->setText(QCoreApplication::translate("MainWindow", "Segundos", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Tiempo de acci\303\263n", nullptr));
        label_104->setText(QCoreApplication::translate("MainWindow", "Tiempo de acci\303\263n", nullptr));
        label_105->setText(QCoreApplication::translate("MainWindow", "Segundos", nullptr));
        ControlSelectCB->setItemText(0, QCoreApplication::translate("MainWindow", "PD + Cancelaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(1, QCoreApplication::translate("MainWindow", "PD + Compensaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(2, QCoreApplication::translate("MainWindow", "P'D' + Cancelaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(3, QCoreApplication::translate("MainWindow", "P'D' + Compensaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(4, QCoreApplication::translate("MainWindow", "sPsD + Cancelaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(5, QCoreApplication::translate("MainWindow", "sPsD + Compensaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(6, QCoreApplication::translate("MainWindow", "sPs'D' + Cancelaci\303\263n de Gravedad", nullptr));
        ControlSelectCB->setItemText(7, QCoreApplication::translate("MainWindow", "sPs'D' + Compensaci\303\263n de Gravedad", nullptr));

        label_15->setText(QCoreApplication::translate("MainWindow", "Control", nullptr));
        label_86->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        kc5Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kc4Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_88->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_89->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        kc1Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kc6Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kc2Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kc3Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_90->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_91->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        label_93->setText(QCoreApplication::translate("MainWindow", "Kc", nullptr));
        label_107->setText(QCoreApplication::translate("MainWindow", "Actuador", nullptr));
        label_95->setText(QCoreApplication::translate("MainWindow", "Ganancias del Control Virtual", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Kc", nullptr));
        label_109->setText(QCoreApplication::translate("MainWindow", "Actuador", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Ganancias del Control Virtual", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        label_Kp_2->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        kd5Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        kp2Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kd1Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_Kd_2->setText(QCoreApplication::translate("MainWindow", "Kd", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        kp6Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kd6Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        kd2Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Actuador", nullptr));
        label_110->setText(QCoreApplication::translate("MainWindow", "Ganancias del Robot", nullptr));
        kd3Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kp4Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kp1Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kp5Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kp3Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kd4Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ki4Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ki2Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ki3Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_Ki_2->setText(QCoreApplication::translate("MainWindow", "Ki", nullptr));
        ki5Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ki1Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ki6Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        label_Ki->setText(QCoreApplication::translate("MainWindow", "Ki", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        label_Kp->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_Kd->setText(QCoreApplication::translate("MainWindow", "Kd", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "Actuador", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ganancias del Robot", nullptr));
        label_Masavirtual->setText(QCoreApplication::translate("MainWindow", "Masa Virtual:", nullptr));
        mcValueLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "Masa Virtual:", nullptr));
        cambiarGainsPB->setText(QCoreApplication::translate("MainWindow", "Cambiar Ganancias", nullptr));
        label_Lg->setText(QCoreApplication::translate("MainWindow", "Lg:", nullptr));
        label_Lg_value->setText(QString());
        label_130->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        label_131->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        label_134->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_135->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_posqd2->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_posqd5->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_posqd4->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_posqd6->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_133->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_137->setText(QCoreApplication::translate("MainWindow", "Posici\303\263n deseada del Robot (deg):", nullptr));
        label_posqd1->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_136->setText(QCoreApplication::translate("MainWindow", "Claw Grip (0-100%):", nullptr));
        label_posqd3->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_132->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_gripperValueQd->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        label_143->setText(QString());
        label_129->setText(QCoreApplication::translate("MainWindow", "Posici\303\263n deseada del Robot (deg):", nullptr));
        label_124->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_123->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        label_126->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_122->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        label_127->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_125->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "Claw Grip (0-100%):", nullptr));
        label_144->setText(QString());
        CambiarQdPB->setText(QCoreApplication::translate("MainWindow", "Cambiar Posici\303\263n Deseada", nullptr));
        PosPackPB->setText(QCoreApplication::translate("MainWindow", "Packaging", nullptr));
        PosZeroPB->setText(QCoreApplication::translate("MainWindow", "Zero", nullptr));
        PosHomePB->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_q3->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_q6->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_113->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        label_139->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        label_121->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_q5->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_115->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_EFy->setText(QString());
        label_141->setText(QCoreApplication::translate("MainWindow", "z:", nullptr));
        label_114->setText(QCoreApplication::translate("MainWindow", "6:", nullptr));
        label_112->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_118->setText(QCoreApplication::translate("MainWindow", "5:", nullptr));
        label_q2->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_gripperValue->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        label_q4->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_EFz->setText(QString());
        label_q1->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_140->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        label_EFx->setText(QString());
        label_116->setText(QCoreApplication::translate("MainWindow", "End Efector:", nullptr));
        label_117->setText(QCoreApplication::translate("MainWindow", "Posici\303\263n del Robot (deg):", nullptr));
        label_120->setText(QCoreApplication::translate("MainWindow", "Claw Grip (0-100%):", nullptr));
        Plots->setTitle(QCoreApplication::translate("MainWindow", "Gr\303\241ficas", nullptr));
        ActivarGraficasPB->setText(QCoreApplication::translate("MainWindow", "Activar Gr\303\241ficas", nullptr));
        ElegirGraficaCB->setItemText(0, QCoreApplication::translate("MainWindow", "Posici\303\263n de la Articulaci\303\263n 1", nullptr));
        ElegirGraficaCB->setItemText(1, QCoreApplication::translate("MainWindow", "Posici\303\263n de la Articulaci\303\263n 2", nullptr));
        ElegirGraficaCB->setItemText(2, QCoreApplication::translate("MainWindow", "Posici\303\263n de la Articulaci\303\263n 3", nullptr));
        ElegirGraficaCB->setItemText(3, QCoreApplication::translate("MainWindow", "Posici\303\263n de la Articulaci\303\263n 4", nullptr));
        ElegirGraficaCB->setItemText(4, QCoreApplication::translate("MainWindow", "Posici\303\263n de la Articulaci\303\263n 5", nullptr));
        ElegirGraficaCB->setItemText(5, QCoreApplication::translate("MainWindow", "Posici\303\263n de la Articulaci\303\263n 6", nullptr));
        ElegirGraficaCB->setItemText(6, QCoreApplication::translate("MainWindow", "Todas las Articulaciones", nullptr));

        label_agraficar->setText(QCoreApplication::translate("MainWindow", "A Graficar:", nullptr));
        label_posarticulaciones->setText(QCoreApplication::translate("MainWindow", "Posiciones de las Articulaciones:", nullptr));
        PosicionDeseadaRD->setText(QCoreApplication::translate("MainWindow", "Posiciones Deseadas", nullptr));
        RunMode->setTitle(QCoreApplication::translate("MainWindow", "Modo:", nullptr));
        SimulacionRB->setText(QCoreApplication::translate("MainWindow", "Simulaci\303\263n", nullptr));
        CorrerRobotRB->setText(QCoreApplication::translate("MainWindow", "Correr en el Robot", nullptr));
        menuREAD_ME->setTitle(QCoreApplication::translate("MainWindow", "READ ME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
