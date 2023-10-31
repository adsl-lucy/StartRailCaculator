/********************************************************************************
** Form generated from reading UI file 'InvestmentIncomeWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVESTMENTINCOMEWGT_H
#define UI_INVESTMENTINCOMEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvestmentIncomeWgt
{
public:
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_graph;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_3dGraph;
    QGroupBox *groupBox_CameraState;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QSlider *horizontalSlider_Hangle;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QSlider *horizontalSlider_Vangle;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_18;
    QSlider *horizontalSlider_Zoom;
    QWidget *widget_panel;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_crystal;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_ticket;
    QGroupBox *groupBox_drawCardType;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_CharacterOnly;
    QRadioButton *radioButton_WeaponOnly;
    QRadioButton *radioButton_getAll;
    QGroupBox *groupBox_PoolState;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *checkBox_lastGoldCharacterWrong;
    QHBoxLayout *horizontalLayout_16;
    QSpinBox *spinBox_charPoolAreadyInTicket;
    QLabel *label_25;
    QCheckBox *checkBox_lastGoldWeaponWrong;
    QHBoxLayout *horizontalLayout_17;
    QSpinBox *spinBox_WeaponPoolAreadyInTicket;
    QLabel *label_26;
    QGroupBox *groupBox_PoolTransformType;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_NCharacterMWeapon;
    QLabel *label_3;
    QSpinBox *spinBox_NChaMWea_Cha;
    QLabel *label_4;
    QSpinBox *spinBox_NChaMWea_Wea;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButton_NWeaponMChacter;
    QLabel *label_6;
    QSpinBox *spinBox_NWeaMCha_Wea;
    QLabel *label_7;
    QSpinBox *spinBox_NWeaMCha_Cha;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButton_NTickCharacterMTickWeapon;
    QLabel *label_10;
    QSpinBox *spinBox_NTChaMTWea_Cha;
    QLabel *label_11;
    QSpinBox *spinBox_NTChaMTWea_Wea;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioButton_NTickWeaponMTickCharacter;
    QLabel *label_13;
    QSpinBox *spinBox_NTWeaMTCha_Wea;
    QLabel *label_14;
    QSpinBox *spinBox_NTWeaMTCha_Cha;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_startEstimate;
    QPushButton *pushButton_resetPara;
    QPushButton *pushButton_clearResult;
    QLabel *label_9;
    QProgressBar *progressBar_EstmateState;
    QLabel *label_ErrMsg;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_InputCyrstal;
    QLabel *label_inputTicket;
    QLabel *label_drawCardType;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_NoUpCharacterProb;
    QLabel *label_getChaExpectation;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_NoUpWeaponProb;
    QLabel *label_getWeaponExpectation;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_21;
    QWidget *widget;

    void setupUi(QWidget *InvestmentIncomeWgt)
    {
        if (InvestmentIncomeWgt->objectName().isEmpty())
            InvestmentIncomeWgt->setObjectName(QString::fromUtf8("InvestmentIncomeWgt"));
        InvestmentIncomeWgt->resize(1596, 938);
        InvestmentIncomeWgt->setMinimumSize(QSize(1596, 938));
        horizontalLayout_11 = new QHBoxLayout(InvestmentIncomeWgt);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        widget_graph = new QWidget(InvestmentIncomeWgt);
        widget_graph->setObjectName(QString::fromUtf8("widget_graph"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_graph->sizePolicy().hasHeightForWidth());
        widget_graph->setSizePolicy(sizePolicy);
        verticalLayout_11 = new QVBoxLayout(widget_graph);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        widget_3dGraph = new QWidget(widget_graph);
        widget_3dGraph->setObjectName(QString::fromUtf8("widget_3dGraph"));

        verticalLayout_11->addWidget(widget_3dGraph);

        groupBox_CameraState = new QGroupBox(widget_graph);
        groupBox_CameraState->setObjectName(QString::fromUtf8("groupBox_CameraState"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_CameraState->sizePolicy().hasHeightForWidth());
        groupBox_CameraState->setSizePolicy(sizePolicy1);
        groupBox_CameraState->setMinimumSize(QSize(0, 180));
        groupBox_CameraState->setMaximumSize(QSize(16777215, 180));
        verticalLayout_7 = new QVBoxLayout(groupBox_CameraState);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_16 = new QLabel(groupBox_CameraState);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_12->addWidget(label_16);

        horizontalSlider_Hangle = new QSlider(groupBox_CameraState);
        horizontalSlider_Hangle->setObjectName(QString::fromUtf8("horizontalSlider_Hangle"));
        horizontalSlider_Hangle->setMinimum(-180);
        horizontalSlider_Hangle->setMaximum(180);
        horizontalSlider_Hangle->setOrientation(Qt::Horizontal);
        horizontalSlider_Hangle->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Hangle->setTickInterval(30);

        horizontalLayout_12->addWidget(horizontalSlider_Hangle);


        verticalLayout_7->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_17 = new QLabel(groupBox_CameraState);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_13->addWidget(label_17);

        horizontalSlider_Vangle = new QSlider(groupBox_CameraState);
        horizontalSlider_Vangle->setObjectName(QString::fromUtf8("horizontalSlider_Vangle"));
        horizontalSlider_Vangle->setMinimum(0);
        horizontalSlider_Vangle->setMaximum(90);
        horizontalSlider_Vangle->setOrientation(Qt::Horizontal);
        horizontalSlider_Vangle->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Vangle->setTickInterval(15);

        horizontalLayout_13->addWidget(horizontalSlider_Vangle);


        verticalLayout_7->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_18 = new QLabel(groupBox_CameraState);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_18);

        horizontalSlider_Zoom = new QSlider(groupBox_CameraState);
        horizontalSlider_Zoom->setObjectName(QString::fromUtf8("horizontalSlider_Zoom"));
        horizontalSlider_Zoom->setMinimum(50);
        horizontalSlider_Zoom->setMaximum(200);
        horizontalSlider_Zoom->setValue(100);
        horizontalSlider_Zoom->setOrientation(Qt::Horizontal);
        horizontalSlider_Zoom->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Zoom->setTickInterval(25);

        horizontalLayout_14->addWidget(horizontalSlider_Zoom);


        verticalLayout_7->addLayout(horizontalLayout_14);


        verticalLayout_11->addWidget(groupBox_CameraState);


        horizontalLayout_11->addWidget(widget_graph);

        widget_panel = new QWidget(InvestmentIncomeWgt);
        widget_panel->setObjectName(QString::fromUtf8("widget_panel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_panel->sizePolicy().hasHeightForWidth());
        widget_panel->setSizePolicy(sizePolicy2);
        widget_panel->setMinimumSize(QSize(532, 897));
        widget_panel->setMaximumSize(QSize(532, 2000));
        verticalLayout_6 = new QVBoxLayout(widget_panel);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_4 = new QGroupBox(widget_panel);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 430));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox_crystal = new QSpinBox(groupBox_2);
        spinBox_crystal->setObjectName(QString::fromUtf8("spinBox_crystal"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_crystal->sizePolicy().hasHeightForWidth());
        spinBox_crystal->setSizePolicy(sizePolicy3);
        spinBox_crystal->setMinimumSize(QSize(70, 24));
        spinBox_crystal->setMaximumSize(QSize(70, 24));
        spinBox_crystal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_crystal->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_crystal->setMaximum(10000000);

        horizontalLayout->addWidget(spinBox_crystal);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_ticket = new QSpinBox(groupBox_2);
        spinBox_ticket->setObjectName(QString::fromUtf8("spinBox_ticket"));
        sizePolicy3.setHeightForWidth(spinBox_ticket->sizePolicy().hasHeightForWidth());
        spinBox_ticket->setSizePolicy(sizePolicy3);
        spinBox_ticket->setMinimumSize(QSize(70, 24));
        spinBox_ticket->setMaximumSize(QSize(70, 24));
        spinBox_ticket->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_ticket->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ticket->setMaximum(10000);

        horizontalLayout_2->addWidget(spinBox_ticket);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_drawCardType = new QGroupBox(groupBox_4);
        groupBox_drawCardType->setObjectName(QString::fromUtf8("groupBox_drawCardType"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_drawCardType);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_CharacterOnly = new QRadioButton(groupBox_drawCardType);
        radioButton_CharacterOnly->setObjectName(QString::fromUtf8("radioButton_CharacterOnly"));

        horizontalLayout_3->addWidget(radioButton_CharacterOnly);

        radioButton_WeaponOnly = new QRadioButton(groupBox_drawCardType);
        radioButton_WeaponOnly->setObjectName(QString::fromUtf8("radioButton_WeaponOnly"));

        horizontalLayout_3->addWidget(radioButton_WeaponOnly);

        radioButton_getAll = new QRadioButton(groupBox_drawCardType);
        radioButton_getAll->setObjectName(QString::fromUtf8("radioButton_getAll"));

        horizontalLayout_3->addWidget(radioButton_getAll);


        verticalLayout_2->addWidget(groupBox_drawCardType);

        groupBox_PoolState = new QGroupBox(groupBox_4);
        groupBox_PoolState->setObjectName(QString::fromUtf8("groupBox_PoolState"));
        verticalLayout_10 = new QVBoxLayout(groupBox_PoolState);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        checkBox_lastGoldCharacterWrong = new QCheckBox(groupBox_PoolState);
        checkBox_lastGoldCharacterWrong->setObjectName(QString::fromUtf8("checkBox_lastGoldCharacterWrong"));

        verticalLayout_10->addWidget(checkBox_lastGoldCharacterWrong);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        spinBox_charPoolAreadyInTicket = new QSpinBox(groupBox_PoolState);
        spinBox_charPoolAreadyInTicket->setObjectName(QString::fromUtf8("spinBox_charPoolAreadyInTicket"));
        sizePolicy3.setHeightForWidth(spinBox_charPoolAreadyInTicket->sizePolicy().hasHeightForWidth());
        spinBox_charPoolAreadyInTicket->setSizePolicy(sizePolicy3);
        spinBox_charPoolAreadyInTicket->setMinimumSize(QSize(48, 24));
        spinBox_charPoolAreadyInTicket->setMaximumSize(QSize(48, 24));
        spinBox_charPoolAreadyInTicket->setMaximum(89);

        horizontalLayout_16->addWidget(spinBox_charPoolAreadyInTicket);

        label_25 = new QLabel(groupBox_PoolState);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_16->addWidget(label_25);


        verticalLayout_10->addLayout(horizontalLayout_16);

        checkBox_lastGoldWeaponWrong = new QCheckBox(groupBox_PoolState);
        checkBox_lastGoldWeaponWrong->setObjectName(QString::fromUtf8("checkBox_lastGoldWeaponWrong"));

        verticalLayout_10->addWidget(checkBox_lastGoldWeaponWrong);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        spinBox_WeaponPoolAreadyInTicket = new QSpinBox(groupBox_PoolState);
        spinBox_WeaponPoolAreadyInTicket->setObjectName(QString::fromUtf8("spinBox_WeaponPoolAreadyInTicket"));
        sizePolicy3.setHeightForWidth(spinBox_WeaponPoolAreadyInTicket->sizePolicy().hasHeightForWidth());
        spinBox_WeaponPoolAreadyInTicket->setSizePolicy(sizePolicy3);
        spinBox_WeaponPoolAreadyInTicket->setMinimumSize(QSize(48, 24));
        spinBox_WeaponPoolAreadyInTicket->setMaximumSize(QSize(48, 24));
        spinBox_WeaponPoolAreadyInTicket->setMaximum(89);

        horizontalLayout_17->addWidget(spinBox_WeaponPoolAreadyInTicket);

        label_26 = new QLabel(groupBox_PoolState);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_17->addWidget(label_26);


        verticalLayout_10->addLayout(horizontalLayout_17);


        verticalLayout_2->addWidget(groupBox_PoolState);

        groupBox_PoolTransformType = new QGroupBox(groupBox_4);
        groupBox_PoolTransformType->setObjectName(QString::fromUtf8("groupBox_PoolTransformType"));
        groupBox_PoolTransformType->setMinimumSize(QSize(421, 110));
        verticalLayout = new QVBoxLayout(groupBox_PoolTransformType);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioButton_NCharacterMWeapon = new QRadioButton(groupBox_PoolTransformType);
        radioButton_NCharacterMWeapon->setObjectName(QString::fromUtf8("radioButton_NCharacterMWeapon"));
        sizePolicy3.setHeightForWidth(radioButton_NCharacterMWeapon->sizePolicy().hasHeightForWidth());
        radioButton_NCharacterMWeapon->setSizePolicy(sizePolicy3);
        radioButton_NCharacterMWeapon->setMinimumSize(QSize(124, 24));
        radioButton_NCharacterMWeapon->setMaximumSize(QSize(124, 24));

        horizontalLayout_5->addWidget(radioButton_NCharacterMWeapon);

        label_3 = new QLabel(groupBox_PoolTransformType);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMinimumSize(QSize(36, 24));
        label_3->setMaximumSize(QSize(36, 24));

        horizontalLayout_5->addWidget(label_3);

        spinBox_NChaMWea_Cha = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NChaMWea_Cha->setObjectName(QString::fromUtf8("spinBox_NChaMWea_Cha"));
        sizePolicy3.setHeightForWidth(spinBox_NChaMWea_Cha->sizePolicy().hasHeightForWidth());
        spinBox_NChaMWea_Cha->setSizePolicy(sizePolicy3);
        spinBox_NChaMWea_Cha->setMinimumSize(QSize(48, 24));
        spinBox_NChaMWea_Cha->setMaximumSize(QSize(48, 24));
        spinBox_NChaMWea_Cha->setMinimum(1);
        spinBox_NChaMWea_Cha->setMaximum(7);

        horizontalLayout_5->addWidget(spinBox_NChaMWea_Cha);

        label_4 = new QLabel(groupBox_PoolTransformType);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 24));
        label_4->setMaximumSize(QSize(100, 24));

        horizontalLayout_5->addWidget(label_4);

        spinBox_NChaMWea_Wea = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NChaMWea_Wea->setObjectName(QString::fromUtf8("spinBox_NChaMWea_Wea"));
        sizePolicy3.setHeightForWidth(spinBox_NChaMWea_Wea->sizePolicy().hasHeightForWidth());
        spinBox_NChaMWea_Wea->setSizePolicy(sizePolicy3);
        spinBox_NChaMWea_Wea->setMinimumSize(QSize(48, 24));
        spinBox_NChaMWea_Wea->setMaximumSize(QSize(48, 24));
        spinBox_NChaMWea_Wea->setMinimum(1);
        spinBox_NChaMWea_Wea->setMaximum(5);

        horizontalLayout_5->addWidget(spinBox_NChaMWea_Wea);

        label_5 = new QLabel(groupBox_PoolTransformType);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(64, 24));
        label_5->setMaximumSize(QSize(64, 24));

        horizontalLayout_5->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        radioButton_NWeaponMChacter = new QRadioButton(groupBox_PoolTransformType);
        radioButton_NWeaponMChacter->setObjectName(QString::fromUtf8("radioButton_NWeaponMChacter"));
        sizePolicy3.setHeightForWidth(radioButton_NWeaponMChacter->sizePolicy().hasHeightForWidth());
        radioButton_NWeaponMChacter->setSizePolicy(sizePolicy3);
        radioButton_NWeaponMChacter->setMinimumSize(QSize(124, 24));
        radioButton_NWeaponMChacter->setMaximumSize(QSize(124, 24));

        horizontalLayout_6->addWidget(radioButton_NWeaponMChacter);

        label_6 = new QLabel(groupBox_PoolTransformType);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(36, 24));
        label_6->setMaximumSize(QSize(36, 24));

        horizontalLayout_6->addWidget(label_6);

        spinBox_NWeaMCha_Wea = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NWeaMCha_Wea->setObjectName(QString::fromUtf8("spinBox_NWeaMCha_Wea"));
        sizePolicy3.setHeightForWidth(spinBox_NWeaMCha_Wea->sizePolicy().hasHeightForWidth());
        spinBox_NWeaMCha_Wea->setSizePolicy(sizePolicy3);
        spinBox_NWeaMCha_Wea->setMinimumSize(QSize(48, 24));
        spinBox_NWeaMCha_Wea->setMaximumSize(QSize(48, 24));
        spinBox_NWeaMCha_Wea->setMinimum(1);
        spinBox_NWeaMCha_Wea->setMaximum(7);

        horizontalLayout_6->addWidget(spinBox_NWeaMCha_Wea);

        label_7 = new QLabel(groupBox_PoolTransformType);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 24));
        label_7->setMaximumSize(QSize(100, 24));

        horizontalLayout_6->addWidget(label_7);

        spinBox_NWeaMCha_Cha = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NWeaMCha_Cha->setObjectName(QString::fromUtf8("spinBox_NWeaMCha_Cha"));
        sizePolicy3.setHeightForWidth(spinBox_NWeaMCha_Cha->sizePolicy().hasHeightForWidth());
        spinBox_NWeaMCha_Cha->setSizePolicy(sizePolicy3);
        spinBox_NWeaMCha_Cha->setMinimumSize(QSize(48, 24));
        spinBox_NWeaMCha_Cha->setMaximumSize(QSize(48, 24));
        spinBox_NWeaMCha_Cha->setMinimum(1);
        spinBox_NWeaMCha_Cha->setMaximum(5);

        horizontalLayout_6->addWidget(spinBox_NWeaMCha_Cha);

        label_8 = new QLabel(groupBox_PoolTransformType);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(64, 24));
        label_8->setMaximumSize(QSize(64, 24));

        horizontalLayout_6->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        radioButton_NTickCharacterMTickWeapon = new QRadioButton(groupBox_PoolTransformType);
        radioButton_NTickCharacterMTickWeapon->setObjectName(QString::fromUtf8("radioButton_NTickCharacterMTickWeapon"));
        radioButton_NTickCharacterMTickWeapon->setMinimumSize(QSize(124, 24));
        radioButton_NTickCharacterMTickWeapon->setMaximumSize(QSize(124, 24));

        horizontalLayout_8->addWidget(radioButton_NTickCharacterMTickWeapon);

        label_10 = new QLabel(groupBox_PoolTransformType);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(36, 24));
        label_10->setMaximumSize(QSize(36, 24));

        horizontalLayout_8->addWidget(label_10);

        spinBox_NTChaMTWea_Cha = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NTChaMTWea_Cha->setObjectName(QString::fromUtf8("spinBox_NTChaMTWea_Cha"));
        sizePolicy3.setHeightForWidth(spinBox_NTChaMTWea_Cha->sizePolicy().hasHeightForWidth());
        spinBox_NTChaMTWea_Cha->setSizePolicy(sizePolicy3);
        spinBox_NTChaMTWea_Cha->setMinimumSize(QSize(48, 24));
        spinBox_NTChaMTWea_Cha->setMaximumSize(QSize(24, 16777215));
        spinBox_NTChaMTWea_Cha->setMinimum(1);
        spinBox_NTChaMTWea_Cha->setMaximum(100000);
        spinBox_NTChaMTWea_Cha->setValue(10);

        horizontalLayout_8->addWidget(spinBox_NTChaMTWea_Cha);

        label_11 = new QLabel(groupBox_PoolTransformType);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(100, 24));
        label_11->setMaximumSize(QSize(100, 24));

        horizontalLayout_8->addWidget(label_11);

        spinBox_NTChaMTWea_Wea = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NTChaMTWea_Wea->setObjectName(QString::fromUtf8("spinBox_NTChaMTWea_Wea"));
        sizePolicy3.setHeightForWidth(spinBox_NTChaMTWea_Wea->sizePolicy().hasHeightForWidth());
        spinBox_NTChaMTWea_Wea->setSizePolicy(sizePolicy3);
        spinBox_NTChaMTWea_Wea->setMinimumSize(QSize(48, 24));
        spinBox_NTChaMTWea_Wea->setMaximumSize(QSize(48, 24));
        spinBox_NTChaMTWea_Wea->setMinimum(1);
        spinBox_NTChaMTWea_Wea->setMaximum(100000);
        spinBox_NTChaMTWea_Wea->setValue(10);

        horizontalLayout_8->addWidget(spinBox_NTChaMTWea_Wea);

        label_12 = new QLabel(groupBox_PoolTransformType);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(64, 24));
        label_12->setMaximumSize(QSize(64, 24));

        horizontalLayout_8->addWidget(label_12);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        radioButton_NTickWeaponMTickCharacter = new QRadioButton(groupBox_PoolTransformType);
        radioButton_NTickWeaponMTickCharacter->setObjectName(QString::fromUtf8("radioButton_NTickWeaponMTickCharacter"));
        radioButton_NTickWeaponMTickCharacter->setMinimumSize(QSize(124, 24));
        radioButton_NTickWeaponMTickCharacter->setMaximumSize(QSize(124, 24));

        horizontalLayout_9->addWidget(radioButton_NTickWeaponMTickCharacter);

        label_13 = new QLabel(groupBox_PoolTransformType);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(36, 24));
        label_13->setMaximumSize(QSize(36, 24));

        horizontalLayout_9->addWidget(label_13);

        spinBox_NTWeaMTCha_Wea = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NTWeaMTCha_Wea->setObjectName(QString::fromUtf8("spinBox_NTWeaMTCha_Wea"));
        sizePolicy3.setHeightForWidth(spinBox_NTWeaMTCha_Wea->sizePolicy().hasHeightForWidth());
        spinBox_NTWeaMTCha_Wea->setSizePolicy(sizePolicy3);
        spinBox_NTWeaMTCha_Wea->setMinimumSize(QSize(48, 24));
        spinBox_NTWeaMTCha_Wea->setMaximumSize(QSize(48, 24));
        spinBox_NTWeaMTCha_Wea->setMinimum(1);
        spinBox_NTWeaMTCha_Wea->setMaximum(100000);
        spinBox_NTWeaMTCha_Wea->setValue(10);

        horizontalLayout_9->addWidget(spinBox_NTWeaMTCha_Wea);

        label_14 = new QLabel(groupBox_PoolTransformType);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(100, 24));
        label_14->setMaximumSize(QSize(100, 24));

        horizontalLayout_9->addWidget(label_14);

        spinBox_NTWeaMTCha_Cha = new QSpinBox(groupBox_PoolTransformType);
        spinBox_NTWeaMTCha_Cha->setObjectName(QString::fromUtf8("spinBox_NTWeaMTCha_Cha"));
        sizePolicy3.setHeightForWidth(spinBox_NTWeaMTCha_Cha->sizePolicy().hasHeightForWidth());
        spinBox_NTWeaMTCha_Cha->setSizePolicy(sizePolicy3);
        spinBox_NTWeaMTCha_Cha->setMinimumSize(QSize(48, 24));
        spinBox_NTWeaMTCha_Cha->setMaximumSize(QSize(48, 24));
        spinBox_NTWeaMTCha_Cha->setMinimum(1);
        spinBox_NTWeaMTCha_Cha->setMaximum(100000);
        spinBox_NTWeaMTCha_Cha->setValue(10);

        horizontalLayout_9->addWidget(spinBox_NTWeaMTCha_Cha);

        label_15 = new QLabel(groupBox_PoolTransformType);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(64, 24));
        label_15->setMaximumSize(QSize(64, 24));

        horizontalLayout_9->addWidget(label_15);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_2->addWidget(groupBox_PoolTransformType);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_startEstimate = new QPushButton(groupBox_4);
        pushButton_startEstimate->setObjectName(QString::fromUtf8("pushButton_startEstimate"));

        horizontalLayout_7->addWidget(pushButton_startEstimate);

        pushButton_resetPara = new QPushButton(groupBox_4);
        pushButton_resetPara->setObjectName(QString::fromUtf8("pushButton_resetPara"));

        horizontalLayout_7->addWidget(pushButton_resetPara);

        pushButton_clearResult = new QPushButton(groupBox_4);
        pushButton_clearResult->setObjectName(QString::fromUtf8("pushButton_clearResult"));

        horizontalLayout_7->addWidget(pushButton_clearResult);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        progressBar_EstmateState = new QProgressBar(groupBox_4);
        progressBar_EstmateState->setObjectName(QString::fromUtf8("progressBar_EstmateState"));
        progressBar_EstmateState->setValue(24);

        horizontalLayout_7->addWidget(progressBar_EstmateState);


        verticalLayout_2->addLayout(horizontalLayout_7);

        label_ErrMsg = new QLabel(groupBox_4);
        label_ErrMsg->setObjectName(QString::fromUtf8("label_ErrMsg"));
        sizePolicy1.setHeightForWidth(label_ErrMsg->sizePolicy().hasHeightForWidth());
        label_ErrMsg->setSizePolicy(sizePolicy1);
        label_ErrMsg->setMinimumSize(QSize(0, 24));
        label_ErrMsg->setMaximumSize(QSize(16777215, 24));

        verticalLayout_2->addWidget(label_ErrMsg);


        verticalLayout_6->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget_panel);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_9 = new QVBoxLayout(groupBox_5);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_InputCyrstal = new QLabel(groupBox_5);
        label_InputCyrstal->setObjectName(QString::fromUtf8("label_InputCyrstal"));

        horizontalLayout_10->addWidget(label_InputCyrstal);

        label_inputTicket = new QLabel(groupBox_5);
        label_inputTicket->setObjectName(QString::fromUtf8("label_inputTicket"));

        horizontalLayout_10->addWidget(label_inputTicket);


        verticalLayout_8->addLayout(horizontalLayout_10);

        label_drawCardType = new QLabel(groupBox_5);
        label_drawCardType->setObjectName(QString::fromUtf8("label_drawCardType"));

        verticalLayout_8->addWidget(label_drawCardType);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_NoUpCharacterProb = new QLabel(groupBox_5);
        label_NoUpCharacterProb->setObjectName(QString::fromUtf8("label_NoUpCharacterProb"));

        verticalLayout_3->addWidget(label_NoUpCharacterProb);

        label_getChaExpectation = new QLabel(groupBox_5);
        label_getChaExpectation->setObjectName(QString::fromUtf8("label_getChaExpectation"));

        verticalLayout_3->addWidget(label_getChaExpectation);


        horizontalLayout_15->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_NoUpWeaponProb = new QLabel(groupBox_5);
        label_NoUpWeaponProb->setObjectName(QString::fromUtf8("label_NoUpWeaponProb"));

        verticalLayout_4->addWidget(label_NoUpWeaponProb);

        label_getWeaponExpectation = new QLabel(groupBox_5);
        label_getWeaponExpectation->setObjectName(QString::fromUtf8("label_getWeaponExpectation"));

        verticalLayout_4->addWidget(label_getWeaponExpectation);


        horizontalLayout_15->addLayout(verticalLayout_4);


        verticalLayout_9->addLayout(horizontalLayout_15);


        verticalLayout_6->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(widget_panel);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy4);
        groupBox_6->setMinimumSize(QSize(532, 0));
        groupBox_6->setMaximumSize(QSize(532, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy2.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy2);
        label_20->setMinimumSize(QSize(532, 0));
        label_20->setMaximumSize(QSize(532, 16777215));

        verticalLayout_5->addWidget(label_20);

        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_5->addWidget(label_19);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_5->addWidget(label_21);


        verticalLayout_6->addWidget(groupBox_6);

        widget = new QWidget(widget_panel);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(widget);


        horizontalLayout_11->addWidget(widget_panel);


        retranslateUi(InvestmentIncomeWgt);

        QMetaObject::connectSlotsByName(InvestmentIncomeWgt);
    } // setupUi

    void retranslateUi(QWidget *InvestmentIncomeWgt)
    {
        InvestmentIncomeWgt->setWindowTitle(QApplication::translate("InvestmentIncomeWgt", "Form", nullptr));
        groupBox_CameraState->setTitle(QApplication::translate("InvestmentIncomeWgt", "\346\221\204\345\203\217\346\234\272", nullptr));
        label_16->setText(QApplication::translate("InvestmentIncomeWgt", "\346\260\264\345\271\263\350\247\222\345\272\246", nullptr));
        label_17->setText(QApplication::translate("InvestmentIncomeWgt", "\345\236\202\347\233\264\350\247\222\345\272\246", nullptr));
        label_18->setText(QApplication::translate("InvestmentIncomeWgt", "\351\225\234\345\244\264\347\274\251\346\224\276", nullptr));
        groupBox_4->setTitle(QApplication::translate("InvestmentIncomeWgt", "\350\256\241\347\256\227\345\217\202\346\225\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("InvestmentIncomeWgt", "\346\212\225\345\205\245\350\265\204\346\272\220\345\220\210\350\256\241", nullptr));
        label->setText(QApplication::translate("InvestmentIncomeWgt", "\346\212\225\345\205\245\346\230\237\347\220\274", nullptr));
        label_2->setText(QApplication::translate("InvestmentIncomeWgt", "\346\212\225\345\205\245\344\270\223\347\245\250", nullptr));
        groupBox_drawCardType->setTitle(QApplication::translate("InvestmentIncomeWgt", "\346\212\275\345\215\241\345\257\271\350\261\241", nullptr));
        radioButton_CharacterOnly->setText(QApplication::translate("InvestmentIncomeWgt", "\345\217\252\346\212\275\350\247\222\350\211\262", nullptr));
        radioButton_WeaponOnly->setText(QApplication::translate("InvestmentIncomeWgt", "\345\217\252\346\212\275\345\205\211\351\224\245", nullptr));
        radioButton_getAll->setText(QApplication::translate("InvestmentIncomeWgt", "\346\210\221\345\205\250\351\203\275\350\246\201", nullptr));
        groupBox_PoolState->setTitle(QApplication::translate("InvestmentIncomeWgt", "\345\215\241\346\261\240\347\212\266\346\200\201", nullptr));
        checkBox_lastGoldCharacterWrong->setText(QApplication::translate("InvestmentIncomeWgt", "\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\350\247\222\350\211\262\346\255\252\344\272\206", nullptr));
        label_25->setText(QApplication::translate("InvestmentIncomeWgt", "\350\247\222\350\211\262\346\261\240\345\236\253\344\272\206\357\274\210\350\267\235\347\246\273\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\350\247\222\350\211\262\357\274\211", nullptr));
        checkBox_lastGoldWeaponWrong->setText(QApplication::translate("InvestmentIncomeWgt", "\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\346\255\246\345\231\250\346\255\252\344\272\206", nullptr));
        label_26->setText(QApplication::translate("InvestmentIncomeWgt", "\346\255\246\345\231\250\346\261\240\345\236\253\344\272\206\357\274\210\350\267\235\347\246\273\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\346\255\246\345\231\250\357\274\211", nullptr));
        groupBox_PoolTransformType->setTitle(QApplication::translate("InvestmentIncomeWgt", "\345\215\241\346\261\240\350\275\256\346\215\242\346\226\271\345\274\217\357\274\210\344\273\205\351\231\220\351\203\275\346\212\275\346\203\205\345\275\242\357\274\211", nullptr));
        radioButton_NCharacterMWeapon->setText(QApplication::translate("InvestmentIncomeWgt", "\346\214\211\345\207\272\350\264\247\350\275\256\346\215\242\357\274\232", nullptr));
        label_3->setText(QApplication::translate("InvestmentIncomeWgt", "\345\205\210\346\212\275", nullptr));
        label_4->setText(QApplication::translate("InvestmentIncomeWgt", "\344\270\252UP\350\247\222\350\211\262\345\206\215", nullptr));
        label_5->setText(QApplication::translate("InvestmentIncomeWgt", "\344\270\252UP\345\205\211\351\224\245", nullptr));
        radioButton_NWeaponMChacter->setText(QApplication::translate("InvestmentIncomeWgt", "\346\214\211\345\207\272\350\264\247\350\275\256\346\215\242\357\274\232", nullptr));
        label_6->setText(QApplication::translate("InvestmentIncomeWgt", "\345\205\210\346\212\275", nullptr));
        label_7->setText(QApplication::translate("InvestmentIncomeWgt", "\344\270\252UP\345\205\211\351\224\245\345\206\215", nullptr));
        label_8->setText(QApplication::translate("InvestmentIncomeWgt", "\344\270\252UP\350\247\222\350\211\262", nullptr));
        radioButton_NTickCharacterMTickWeapon->setText(QApplication::translate("InvestmentIncomeWgt", "\346\214\211\346\257\224\344\276\213\346\212\225\345\205\245\357\274\232", nullptr));
        label_10->setText(QApplication::translate("InvestmentIncomeWgt", "\345\205\210\346\212\275", nullptr));
        label_11->setText(QApplication::translate("InvestmentIncomeWgt", "\345\217\221\350\247\222\350\211\262\346\261\240 \345\206\215\346\212\275", nullptr));
        label_12->setText(QApplication::translate("InvestmentIncomeWgt", "\345\217\221\345\205\211\351\224\245\346\261\240", nullptr));
        radioButton_NTickWeaponMTickCharacter->setText(QApplication::translate("InvestmentIncomeWgt", "\346\214\211\346\257\224\344\276\213\346\212\225\345\205\245\357\274\232", nullptr));
        label_13->setText(QApplication::translate("InvestmentIncomeWgt", "\345\205\210\346\212\275", nullptr));
        label_14->setText(QApplication::translate("InvestmentIncomeWgt", "\345\217\221\345\205\211\351\224\245\346\261\240 \345\206\215\346\212\275", nullptr));
        label_15->setText(QApplication::translate("InvestmentIncomeWgt", "\345\217\221\350\247\222\350\211\262\346\261\240", nullptr));
        pushButton_startEstimate->setText(QApplication::translate("InvestmentIncomeWgt", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
        pushButton_resetPara->setText(QApplication::translate("InvestmentIncomeWgt", "\351\207\215\347\275\256\345\217\202\346\225\260", nullptr));
        pushButton_clearResult->setText(QApplication::translate("InvestmentIncomeWgt", "\346\270\205\347\220\206\347\273\223\346\236\234", nullptr));
        label_9->setText(QApplication::translate("InvestmentIncomeWgt", "\350\256\241\347\256\227\350\277\233\345\272\246", nullptr));
        label_ErrMsg->setText(QApplication::translate("InvestmentIncomeWgt", "\351\242\204\347\225\231\351\224\231\350\257\257\347\240\201\344\275\215", nullptr));
        groupBox_5->setTitle(QApplication::translate("InvestmentIncomeWgt", "\347\273\237\350\256\241\347\273\223\350\256\272", nullptr));
        label_InputCyrstal->setText(QApplication::translate("InvestmentIncomeWgt", "\346\212\225\345\205\245\346\230\237\347\220\274\357\274\232", nullptr));
        label_inputTicket->setText(QApplication::translate("InvestmentIncomeWgt", "\346\212\225\345\205\245\344\270\223\347\245\250\357\274\232", nullptr));
        label_drawCardType->setText(QApplication::translate("InvestmentIncomeWgt", "\346\212\275\345\215\241\346\226\271\345\274\217\357\274\232", nullptr));
        label_NoUpCharacterProb->setText(QApplication::translate("InvestmentIncomeWgt", "UP\350\247\222\350\211\262\346\262\211\350\210\271\346\246\202\347\216\207\357\274\232", nullptr));
        label_getChaExpectation->setText(QApplication::translate("InvestmentIncomeWgt", "UP\350\247\222\350\211\262\345\207\272\350\264\247\346\234\237\346\234\233\357\274\232", nullptr));
        label_NoUpWeaponProb->setText(QApplication::translate("InvestmentIncomeWgt", "UP\346\255\246\345\231\250\346\262\211\350\210\271\346\246\202\347\216\207\357\274\232", nullptr));
        label_getWeaponExpectation->setText(QApplication::translate("InvestmentIncomeWgt", "UP\346\255\246\345\231\250\345\207\272\350\264\247\346\234\237\346\234\233\357\274\232", nullptr));
        groupBox_6->setTitle(QApplication::translate("InvestmentIncomeWgt", "\345\205\266\344\273\226", nullptr));
        label_20->setText(QApplication::translate("InvestmentIncomeWgt", "1.\346\214\211\344\275\217\345\217\263\351\224\256\346\213\226\346\213\275\345\233\276\350\241\250\346\224\271\345\217\230\346\221\204\345\203\217\346\234\272\350\247\222\345\272\246\357\274\214\346\273\232\350\275\256\346\224\271\345\217\230\347\274\251\346\224\276", nullptr));
        label_19->setText(QApplication::translate("InvestmentIncomeWgt", "2.\345\267\246\351\224\256\347\202\271\345\207\273\346\237\261\345\255\220\346\230\276\347\244\272\344\272\213\344\273\266\346\246\202\347\216\207", nullptr));
        label_21->setText(QApplication::translate("InvestmentIncomeWgt", "3.\346\250\241\346\213\237\346\254\241\346\225\260\344\270\27210\344\270\207\346\254\241\357\274\214\350\277\231\345\257\271\344\272\2161000\346\254\241\346\212\275\345\215\241\344\273\245\345\206\205\347\232\204\346\203\205\345\206\265\346\224\266\346\225\233\350\276\203\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvestmentIncomeWgt: public Ui_InvestmentIncomeWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVESTMENTINCOMEWGT_H
