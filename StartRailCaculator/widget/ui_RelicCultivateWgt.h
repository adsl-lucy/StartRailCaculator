/********************************************************************************
** Form generated from reading UI file 'RelicCultivateWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELICCULTIVATEWGT_H
#define UI_RELICCULTIVATEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RelicCultivateWgt
{
public:
    QHBoxLayout *horizontalLayout_22;
    QWidget *widget_graph;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_panel;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_targetRelic;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_head;
    QRadioButton *radioButton_hand;
    QRadioButton *radioButton_clothes;
    QRadioButton *radioButton_shoes;
    QFrame *line;
    QRadioButton *radioButton_cord;
    QRadioButton *radioButton_ball;
    QGroupBox *groupBox_ValidPriProperites;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_PriProAttactPercent;
    QCheckBox *checkBox_PriProCriticalProb;
    QCheckBox *checkBox_PriProCriticalDamage;
    QCheckBox *checkBox_PriProSpeed;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_PriProChargeEfficiency;
    QCheckBox *checkBox_PriProBreakDamage;
    QCheckBox *checkBox_PriProDebuffAccuracy;
    QCheckBox *checkBox_PriProHealAddition;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_PriProHPPercentage;
    QCheckBox *checkBox_PriProDefencePercentage;
    QWidget *widget_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_21;
    QCheckBox *checkBox_PriProFire;
    QCheckBox *checkBox_PriProThunder;
    QCheckBox *checkBox_PriProWind;
    QCheckBox *checkBox_PriProIce;
    QHBoxLayout *horizontalLayout_23;
    QCheckBox *checkBox_PriProNull;
    QCheckBox *checkBox_PriProQuantum;
    QCheckBox *checkBox_PriProPhysical;
    QWidget *widget_4;
    QGroupBox *groupBox_SubProFilter;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_SubProAttackValue;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_SubProAttackValue;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox_SubProAttackPercentage;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_SubProAttactPercentage;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *checkBox_SubProCriticalPercentage;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_SubProCriticalPercentage;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox_SubProCriticialDamage;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_SubProCriticalDamage;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *checkBox_SubProSpeed;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_SubProSpeed;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_SubProDebuffAccuracy;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_SubProDebuffAccuracy;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_SubProBreakDamage;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_SubProBreakDamage;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_SubProHPValue;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_SubProHPValue;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_SubProHPPercentage;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_SubProHPPercentage;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_SubProDefenceValue;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_SubProDefenceValue;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_SubProDefencePercentage;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_SubProDefencePercentage;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBox_SubProDebuffDefence;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_SubProDebuffDefence;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QSpinBox *spinBox_playTime;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButton_startEstimate;
    QPushButton *pushButton_resetPara;
    QPushButton *pushButton_clearResult;
    QLabel *label_14;
    QProgressBar *progressBar_EstimateProgress;
    QLabel *label_ErrorMsg;
    QGroupBox *groupBox_statisticalConclusiaon;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_PriProValidProportion;
    QLabel *label_PriProValidGetProbability;
    QLabel *label_PriProValidGetTimeExpectation;
    QLabel *label_PriProValidGetPlayTimeExpectation;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_AllProValidProportion;
    QLabel *label_AllPropertyValidGetPercentage;
    QLabel *label_AllProValidGetTimeExpectation;
    QLabel *label_AllPropertyGetPlayTimeExpectation;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_20;

    void setupUi(QWidget *RelicCultivateWgt)
    {
        if (RelicCultivateWgt->objectName().isEmpty())
            RelicCultivateWgt->setObjectName(QString::fromUtf8("RelicCultivateWgt"));
        RelicCultivateWgt->resize(1324, 870);
        horizontalLayout_22 = new QHBoxLayout(RelicCultivateWgt);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        widget_graph = new QWidget(RelicCultivateWgt);
        widget_graph->setObjectName(QString::fromUtf8("widget_graph"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_graph->sizePolicy().hasHeightForWidth());
        widget_graph->setSizePolicy(sizePolicy);

        horizontalLayout_22->addWidget(widget_graph);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_panel = new QWidget(RelicCultivateWgt);
        widget_panel->setObjectName(QString::fromUtf8("widget_panel"));
        widget_panel->setMinimumSize(QSize(544, 826));
        widget_panel->setMaximumSize(QSize(544, 826));
        verticalLayout_5 = new QVBoxLayout(widget_panel);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_targetRelic = new QGroupBox(widget_panel);
        groupBox_targetRelic->setObjectName(QString::fromUtf8("groupBox_targetRelic"));
        horizontalLayout = new QHBoxLayout(groupBox_targetRelic);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_head = new QRadioButton(groupBox_targetRelic);
        radioButton_head->setObjectName(QString::fromUtf8("radioButton_head"));
        radioButton_head->setMinimumSize(QSize(48, 24));
        radioButton_head->setMaximumSize(QSize(48, 24));

        horizontalLayout->addWidget(radioButton_head);

        radioButton_hand = new QRadioButton(groupBox_targetRelic);
        radioButton_hand->setObjectName(QString::fromUtf8("radioButton_hand"));
        radioButton_hand->setMinimumSize(QSize(48, 24));
        radioButton_hand->setMaximumSize(QSize(48, 24));

        horizontalLayout->addWidget(radioButton_hand);

        radioButton_clothes = new QRadioButton(groupBox_targetRelic);
        radioButton_clothes->setObjectName(QString::fromUtf8("radioButton_clothes"));
        radioButton_clothes->setMinimumSize(QSize(48, 24));
        radioButton_clothes->setMaximumSize(QSize(48, 24));

        horizontalLayout->addWidget(radioButton_clothes);

        radioButton_shoes = new QRadioButton(groupBox_targetRelic);
        radioButton_shoes->setObjectName(QString::fromUtf8("radioButton_shoes"));
        radioButton_shoes->setMinimumSize(QSize(48, 24));
        radioButton_shoes->setMaximumSize(QSize(48, 24));

        horizontalLayout->addWidget(radioButton_shoes);

        line = new QFrame(groupBox_targetRelic);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        radioButton_cord = new QRadioButton(groupBox_targetRelic);
        radioButton_cord->setObjectName(QString::fromUtf8("radioButton_cord"));
        radioButton_cord->setMinimumSize(QSize(48, 24));
        radioButton_cord->setMaximumSize(QSize(48, 24));

        horizontalLayout->addWidget(radioButton_cord);

        radioButton_ball = new QRadioButton(groupBox_targetRelic);
        radioButton_ball->setObjectName(QString::fromUtf8("radioButton_ball"));
        radioButton_ball->setMinimumSize(QSize(48, 24));
        radioButton_ball->setMaximumSize(QSize(48, 24));

        horizontalLayout->addWidget(radioButton_ball);


        verticalLayout_5->addWidget(groupBox_targetRelic);

        groupBox_ValidPriProperites = new QGroupBox(widget_panel);
        groupBox_ValidPriProperites->setObjectName(QString::fromUtf8("groupBox_ValidPriProperites"));
        verticalLayout = new QVBoxLayout(groupBox_ValidPriProperites);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_PriProAttactPercent = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProAttactPercent->setObjectName(QString::fromUtf8("checkBox_PriProAttactPercent"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_PriProAttactPercent->sizePolicy().hasHeightForWidth());
        checkBox_PriProAttactPercent->setSizePolicy(sizePolicy1);
        checkBox_PriProAttactPercent->setMinimumSize(QSize(102, 24));
        checkBox_PriProAttactPercent->setMaximumSize(QSize(102, 24));

        horizontalLayout_2->addWidget(checkBox_PriProAttactPercent);

        checkBox_PriProCriticalProb = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProCriticalProb->setObjectName(QString::fromUtf8("checkBox_PriProCriticalProb"));
        checkBox_PriProCriticalProb->setMinimumSize(QSize(102, 24));
        checkBox_PriProCriticalProb->setMaximumSize(QSize(102, 24));

        horizontalLayout_2->addWidget(checkBox_PriProCriticalProb);

        checkBox_PriProCriticalDamage = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProCriticalDamage->setObjectName(QString::fromUtf8("checkBox_PriProCriticalDamage"));
        sizePolicy1.setHeightForWidth(checkBox_PriProCriticalDamage->sizePolicy().hasHeightForWidth());
        checkBox_PriProCriticalDamage->setSizePolicy(sizePolicy1);
        checkBox_PriProCriticalDamage->setMinimumSize(QSize(102, 24));
        checkBox_PriProCriticalDamage->setMaximumSize(QSize(102, 24));

        horizontalLayout_2->addWidget(checkBox_PriProCriticalDamage);

        checkBox_PriProSpeed = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProSpeed->setObjectName(QString::fromUtf8("checkBox_PriProSpeed"));
        sizePolicy1.setHeightForWidth(checkBox_PriProSpeed->sizePolicy().hasHeightForWidth());
        checkBox_PriProSpeed->setSizePolicy(sizePolicy1);
        checkBox_PriProSpeed->setMinimumSize(QSize(102, 24));
        checkBox_PriProSpeed->setMaximumSize(QSize(102, 24));

        horizontalLayout_2->addWidget(checkBox_PriProSpeed);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_PriProChargeEfficiency = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProChargeEfficiency->setObjectName(QString::fromUtf8("checkBox_PriProChargeEfficiency"));
        sizePolicy1.setHeightForWidth(checkBox_PriProChargeEfficiency->sizePolicy().hasHeightForWidth());
        checkBox_PriProChargeEfficiency->setSizePolicy(sizePolicy1);
        checkBox_PriProChargeEfficiency->setMinimumSize(QSize(102, 24));
        checkBox_PriProChargeEfficiency->setMaximumSize(QSize(102, 24));

        horizontalLayout_4->addWidget(checkBox_PriProChargeEfficiency);

        checkBox_PriProBreakDamage = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProBreakDamage->setObjectName(QString::fromUtf8("checkBox_PriProBreakDamage"));
        sizePolicy1.setHeightForWidth(checkBox_PriProBreakDamage->sizePolicy().hasHeightForWidth());
        checkBox_PriProBreakDamage->setSizePolicy(sizePolicy1);
        checkBox_PriProBreakDamage->setMinimumSize(QSize(102, 24));
        checkBox_PriProBreakDamage->setMaximumSize(QSize(102, 24));

        horizontalLayout_4->addWidget(checkBox_PriProBreakDamage);

        checkBox_PriProDebuffAccuracy = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProDebuffAccuracy->setObjectName(QString::fromUtf8("checkBox_PriProDebuffAccuracy"));
        sizePolicy1.setHeightForWidth(checkBox_PriProDebuffAccuracy->sizePolicy().hasHeightForWidth());
        checkBox_PriProDebuffAccuracy->setSizePolicy(sizePolicy1);
        checkBox_PriProDebuffAccuracy->setMinimumSize(QSize(102, 24));
        checkBox_PriProDebuffAccuracy->setMaximumSize(QSize(102, 24));

        horizontalLayout_4->addWidget(checkBox_PriProDebuffAccuracy);

        checkBox_PriProHealAddition = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProHealAddition->setObjectName(QString::fromUtf8("checkBox_PriProHealAddition"));
        sizePolicy1.setHeightForWidth(checkBox_PriProHealAddition->sizePolicy().hasHeightForWidth());
        checkBox_PriProHealAddition->setSizePolicy(sizePolicy1);
        checkBox_PriProHealAddition->setMinimumSize(QSize(102, 24));
        checkBox_PriProHealAddition->setMaximumSize(QSize(102, 24));

        horizontalLayout_4->addWidget(checkBox_PriProHealAddition);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, -1);
        checkBox_PriProHPPercentage = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProHPPercentage->setObjectName(QString::fromUtf8("checkBox_PriProHPPercentage"));
        sizePolicy1.setHeightForWidth(checkBox_PriProHPPercentage->sizePolicy().hasHeightForWidth());
        checkBox_PriProHPPercentage->setSizePolicy(sizePolicy1);
        checkBox_PriProHPPercentage->setMinimumSize(QSize(102, 24));
        checkBox_PriProHPPercentage->setMaximumSize(QSize(102, 24));

        horizontalLayout_3->addWidget(checkBox_PriProHPPercentage);

        checkBox_PriProDefencePercentage = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProDefencePercentage->setObjectName(QString::fromUtf8("checkBox_PriProDefencePercentage"));
        sizePolicy1.setHeightForWidth(checkBox_PriProDefencePercentage->sizePolicy().hasHeightForWidth());
        checkBox_PriProDefencePercentage->setSizePolicy(sizePolicy1);
        checkBox_PriProDefencePercentage->setMinimumSize(QSize(102, 24));
        checkBox_PriProDefencePercentage->setMaximumSize(QSize(102, 24));

        horizontalLayout_3->addWidget(checkBox_PriProDefencePercentage);

        widget_5 = new QWidget(groupBox_ValidPriProperites);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        widget_5->setMinimumSize(QSize(102, 24));
        widget_5->setMaximumSize(QSize(102, 24));

        horizontalLayout_3->addWidget(widget_5);

        widget_3 = new QWidget(groupBox_ValidPriProperites);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMinimumSize(QSize(102, 24));
        widget_3->setMaximumSize(QSize(102, 24));

        horizontalLayout_3->addWidget(widget_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        checkBox_PriProFire = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProFire->setObjectName(QString::fromUtf8("checkBox_PriProFire"));
        sizePolicy1.setHeightForWidth(checkBox_PriProFire->sizePolicy().hasHeightForWidth());
        checkBox_PriProFire->setSizePolicy(sizePolicy1);
        checkBox_PriProFire->setMinimumSize(QSize(102, 24));
        checkBox_PriProFire->setMaximumSize(QSize(102, 24));

        horizontalLayout_21->addWidget(checkBox_PriProFire);

        checkBox_PriProThunder = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProThunder->setObjectName(QString::fromUtf8("checkBox_PriProThunder"));
        checkBox_PriProThunder->setMinimumSize(QSize(102, 24));
        checkBox_PriProThunder->setMaximumSize(QSize(102, 24));

        horizontalLayout_21->addWidget(checkBox_PriProThunder);

        checkBox_PriProWind = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProWind->setObjectName(QString::fromUtf8("checkBox_PriProWind"));
        checkBox_PriProWind->setMinimumSize(QSize(102, 24));
        checkBox_PriProWind->setMaximumSize(QSize(102, 24));

        horizontalLayout_21->addWidget(checkBox_PriProWind);

        checkBox_PriProIce = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProIce->setObjectName(QString::fromUtf8("checkBox_PriProIce"));
        checkBox_PriProIce->setMinimumSize(QSize(102, 24));
        checkBox_PriProIce->setMaximumSize(QSize(102, 24));

        horizontalLayout_21->addWidget(checkBox_PriProIce);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, -1, -1, -1);
        checkBox_PriProNull = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProNull->setObjectName(QString::fromUtf8("checkBox_PriProNull"));
        checkBox_PriProNull->setMinimumSize(QSize(102, 24));
        checkBox_PriProNull->setMaximumSize(QSize(102, 24));

        horizontalLayout_23->addWidget(checkBox_PriProNull);

        checkBox_PriProQuantum = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProQuantum->setObjectName(QString::fromUtf8("checkBox_PriProQuantum"));
        checkBox_PriProQuantum->setMinimumSize(QSize(102, 24));
        checkBox_PriProQuantum->setMaximumSize(QSize(102, 24));

        horizontalLayout_23->addWidget(checkBox_PriProQuantum);

        checkBox_PriProPhysical = new QCheckBox(groupBox_ValidPriProperites);
        checkBox_PriProPhysical->setObjectName(QString::fromUtf8("checkBox_PriProPhysical"));
        checkBox_PriProPhysical->setMinimumSize(QSize(102, 24));
        checkBox_PriProPhysical->setMaximumSize(QSize(102, 24));

        horizontalLayout_23->addWidget(checkBox_PriProPhysical);

        widget_4 = new QWidget(groupBox_ValidPriProperites);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(102, 24));
        widget_4->setMaximumSize(QSize(102, 24));

        horizontalLayout_23->addWidget(widget_4);


        verticalLayout->addLayout(horizontalLayout_23);


        verticalLayout_5->addWidget(groupBox_ValidPriProperites);

        groupBox_SubProFilter = new QGroupBox(widget_panel);
        groupBox_SubProFilter->setObjectName(QString::fromUtf8("groupBox_SubProFilter"));
        horizontalLayout_17 = new QHBoxLayout(groupBox_SubProFilter);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        checkBox_SubProAttackValue = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProAttackValue->setObjectName(QString::fromUtf8("checkBox_SubProAttackValue"));
        sizePolicy1.setHeightForWidth(checkBox_SubProAttackValue->sizePolicy().hasHeightForWidth());
        checkBox_SubProAttackValue->setSizePolicy(sizePolicy1);
        checkBox_SubProAttackValue->setMinimumSize(QSize(102, 24));
        checkBox_SubProAttackValue->setMaximumSize(QSize(102, 24));

        horizontalLayout_7->addWidget(checkBox_SubProAttackValue);

        label_3 = new QLabel(groupBox_SubProFilter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(64, 24));
        label_3->setMaximumSize(QSize(64, 24));

        horizontalLayout_7->addWidget(label_3);

        doubleSpinBox_SubProAttackValue = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProAttackValue->setObjectName(QString::fromUtf8("doubleSpinBox_SubProAttackValue"));
        doubleSpinBox_SubProAttackValue->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProAttackValue->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProAttackValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProAttackValue->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_7->addWidget(doubleSpinBox_SubProAttackValue);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        checkBox_SubProAttackPercentage = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProAttackPercentage->setObjectName(QString::fromUtf8("checkBox_SubProAttackPercentage"));
        sizePolicy1.setHeightForWidth(checkBox_SubProAttackPercentage->sizePolicy().hasHeightForWidth());
        checkBox_SubProAttackPercentage->setSizePolicy(sizePolicy1);
        checkBox_SubProAttackPercentage->setMinimumSize(QSize(102, 24));
        checkBox_SubProAttackPercentage->setMaximumSize(QSize(102, 24));

        horizontalLayout_8->addWidget(checkBox_SubProAttackPercentage);

        label_4 = new QLabel(groupBox_SubProFilter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(64, 24));
        label_4->setMaximumSize(QSize(64, 24));

        horizontalLayout_8->addWidget(label_4);

        doubleSpinBox_SubProAttactPercentage = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProAttactPercentage->setObjectName(QString::fromUtf8("doubleSpinBox_SubProAttactPercentage"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProAttactPercentage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProAttactPercentage->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProAttactPercentage->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProAttactPercentage->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProAttactPercentage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProAttactPercentage->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_8->addWidget(doubleSpinBox_SubProAttactPercentage);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        checkBox_SubProCriticalPercentage = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProCriticalPercentage->setObjectName(QString::fromUtf8("checkBox_SubProCriticalPercentage"));
        sizePolicy1.setHeightForWidth(checkBox_SubProCriticalPercentage->sizePolicy().hasHeightForWidth());
        checkBox_SubProCriticalPercentage->setSizePolicy(sizePolicy1);
        checkBox_SubProCriticalPercentage->setMinimumSize(QSize(102, 24));
        checkBox_SubProCriticalPercentage->setMaximumSize(QSize(102, 24));

        horizontalLayout_14->addWidget(checkBox_SubProCriticalPercentage);

        label_10 = new QLabel(groupBox_SubProFilter);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(64, 24));
        label_10->setMaximumSize(QSize(64, 24));

        horizontalLayout_14->addWidget(label_10);

        doubleSpinBox_SubProCriticalPercentage = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProCriticalPercentage->setObjectName(QString::fromUtf8("doubleSpinBox_SubProCriticalPercentage"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProCriticalPercentage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProCriticalPercentage->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProCriticalPercentage->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProCriticalPercentage->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProCriticalPercentage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProCriticalPercentage->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_14->addWidget(doubleSpinBox_SubProCriticalPercentage);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        checkBox_SubProCriticialDamage = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProCriticialDamage->setObjectName(QString::fromUtf8("checkBox_SubProCriticialDamage"));
        sizePolicy1.setHeightForWidth(checkBox_SubProCriticialDamage->sizePolicy().hasHeightForWidth());
        checkBox_SubProCriticialDamage->setSizePolicy(sizePolicy1);
        checkBox_SubProCriticialDamage->setMinimumSize(QSize(102, 24));
        checkBox_SubProCriticialDamage->setMaximumSize(QSize(102, 24));

        horizontalLayout_15->addWidget(checkBox_SubProCriticialDamage);

        label_11 = new QLabel(groupBox_SubProFilter);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(64, 24));
        label_11->setMaximumSize(QSize(64, 24));

        horizontalLayout_15->addWidget(label_11);

        doubleSpinBox_SubProCriticalDamage = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProCriticalDamage->setObjectName(QString::fromUtf8("doubleSpinBox_SubProCriticalDamage"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProCriticalDamage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProCriticalDamage->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProCriticalDamage->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProCriticalDamage->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProCriticalDamage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProCriticalDamage->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_15->addWidget(doubleSpinBox_SubProCriticalDamage);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        checkBox_SubProSpeed = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProSpeed->setObjectName(QString::fromUtf8("checkBox_SubProSpeed"));
        sizePolicy1.setHeightForWidth(checkBox_SubProSpeed->sizePolicy().hasHeightForWidth());
        checkBox_SubProSpeed->setSizePolicy(sizePolicy1);
        checkBox_SubProSpeed->setMinimumSize(QSize(102, 24));
        checkBox_SubProSpeed->setMaximumSize(QSize(102, 24));

        horizontalLayout_16->addWidget(checkBox_SubProSpeed);

        label_12 = new QLabel(groupBox_SubProFilter);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(64, 24));
        label_12->setMaximumSize(QSize(64, 24));

        horizontalLayout_16->addWidget(label_12);

        doubleSpinBox_SubProSpeed = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProSpeed->setObjectName(QString::fromUtf8("doubleSpinBox_SubProSpeed"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProSpeed->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProSpeed->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProSpeed->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProSpeed->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_16->addWidget(doubleSpinBox_SubProSpeed);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        checkBox_SubProDebuffAccuracy = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProDebuffAccuracy->setObjectName(QString::fromUtf8("checkBox_SubProDebuffAccuracy"));
        sizePolicy1.setHeightForWidth(checkBox_SubProDebuffAccuracy->sizePolicy().hasHeightForWidth());
        checkBox_SubProDebuffAccuracy->setSizePolicy(sizePolicy1);
        checkBox_SubProDebuffAccuracy->setMinimumSize(QSize(102, 24));
        checkBox_SubProDebuffAccuracy->setMaximumSize(QSize(102, 24));

        horizontalLayout_12->addWidget(checkBox_SubProDebuffAccuracy);

        label_8 = new QLabel(groupBox_SubProFilter);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(64, 24));
        label_8->setMaximumSize(QSize(64, 24));

        horizontalLayout_12->addWidget(label_8);

        doubleSpinBox_SubProDebuffAccuracy = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProDebuffAccuracy->setObjectName(QString::fromUtf8("doubleSpinBox_SubProDebuffAccuracy"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProDebuffAccuracy->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProDebuffAccuracy->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProDebuffAccuracy->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProDebuffAccuracy->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProDebuffAccuracy->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProDebuffAccuracy->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_12->addWidget(doubleSpinBox_SubProDebuffAccuracy);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        checkBox_SubProBreakDamage = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProBreakDamage->setObjectName(QString::fromUtf8("checkBox_SubProBreakDamage"));
        sizePolicy1.setHeightForWidth(checkBox_SubProBreakDamage->sizePolicy().hasHeightForWidth());
        checkBox_SubProBreakDamage->setSizePolicy(sizePolicy1);
        checkBox_SubProBreakDamage->setMinimumSize(QSize(102, 24));
        checkBox_SubProBreakDamage->setMaximumSize(QSize(102, 24));

        horizontalLayout_13->addWidget(checkBox_SubProBreakDamage);

        label_9 = new QLabel(groupBox_SubProFilter);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(64, 24));
        label_9->setMaximumSize(QSize(64, 24));

        horizontalLayout_13->addWidget(label_9);

        doubleSpinBox_SubProBreakDamage = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProBreakDamage->setObjectName(QString::fromUtf8("doubleSpinBox_SubProBreakDamage"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProBreakDamage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProBreakDamage->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProBreakDamage->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProBreakDamage->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProBreakDamage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProBreakDamage->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_13->addWidget(doubleSpinBox_SubProBreakDamage);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout_17->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBox_SubProHPValue = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProHPValue->setObjectName(QString::fromUtf8("checkBox_SubProHPValue"));
        sizePolicy1.setHeightForWidth(checkBox_SubProHPValue->sizePolicy().hasHeightForWidth());
        checkBox_SubProHPValue->setSizePolicy(sizePolicy1);
        checkBox_SubProHPValue->setMinimumSize(QSize(102, 24));
        checkBox_SubProHPValue->setMaximumSize(QSize(102, 24));

        horizontalLayout_5->addWidget(checkBox_SubProHPValue);

        label = new QLabel(groupBox_SubProFilter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(64, 24));
        label->setMaximumSize(QSize(64, 24));

        horizontalLayout_5->addWidget(label);

        doubleSpinBox_SubProHPValue = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProHPValue->setObjectName(QString::fromUtf8("doubleSpinBox_SubProHPValue"));
        doubleSpinBox_SubProHPValue->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProHPValue->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProHPValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProHPValue->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_5->addWidget(doubleSpinBox_SubProHPValue);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkBox_SubProHPPercentage = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProHPPercentage->setObjectName(QString::fromUtf8("checkBox_SubProHPPercentage"));
        sizePolicy1.setHeightForWidth(checkBox_SubProHPPercentage->sizePolicy().hasHeightForWidth());
        checkBox_SubProHPPercentage->setSizePolicy(sizePolicy1);
        checkBox_SubProHPPercentage->setMinimumSize(QSize(102, 24));
        checkBox_SubProHPPercentage->setMaximumSize(QSize(102, 24));

        horizontalLayout_6->addWidget(checkBox_SubProHPPercentage);

        label_2 = new QLabel(groupBox_SubProFilter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(64, 24));
        label_2->setMaximumSize(QSize(64, 24));

        horizontalLayout_6->addWidget(label_2);

        doubleSpinBox_SubProHPPercentage = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProHPPercentage->setObjectName(QString::fromUtf8("doubleSpinBox_SubProHPPercentage"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProHPPercentage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProHPPercentage->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProHPPercentage->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProHPPercentage->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProHPPercentage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProHPPercentage->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_6->addWidget(doubleSpinBox_SubProHPPercentage);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        checkBox_SubProDefenceValue = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProDefenceValue->setObjectName(QString::fromUtf8("checkBox_SubProDefenceValue"));
        sizePolicy1.setHeightForWidth(checkBox_SubProDefenceValue->sizePolicy().hasHeightForWidth());
        checkBox_SubProDefenceValue->setSizePolicy(sizePolicy1);
        checkBox_SubProDefenceValue->setMinimumSize(QSize(102, 24));
        checkBox_SubProDefenceValue->setMaximumSize(QSize(102, 24));

        horizontalLayout_9->addWidget(checkBox_SubProDefenceValue);

        label_5 = new QLabel(groupBox_SubProFilter);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(64, 24));
        label_5->setMaximumSize(QSize(64, 24));

        horizontalLayout_9->addWidget(label_5);

        doubleSpinBox_SubProDefenceValue = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProDefenceValue->setObjectName(QString::fromUtf8("doubleSpinBox_SubProDefenceValue"));
        doubleSpinBox_SubProDefenceValue->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProDefenceValue->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProDefenceValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProDefenceValue->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_9->addWidget(doubleSpinBox_SubProDefenceValue);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        checkBox_SubProDefencePercentage = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProDefencePercentage->setObjectName(QString::fromUtf8("checkBox_SubProDefencePercentage"));
        sizePolicy1.setHeightForWidth(checkBox_SubProDefencePercentage->sizePolicy().hasHeightForWidth());
        checkBox_SubProDefencePercentage->setSizePolicy(sizePolicy1);
        checkBox_SubProDefencePercentage->setMinimumSize(QSize(102, 24));
        checkBox_SubProDefencePercentage->setMaximumSize(QSize(102, 24));

        horizontalLayout_10->addWidget(checkBox_SubProDefencePercentage);

        label_6 = new QLabel(groupBox_SubProFilter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(64, 24));
        label_6->setMaximumSize(QSize(64, 24));

        horizontalLayout_10->addWidget(label_6);

        doubleSpinBox_SubProDefencePercentage = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProDefencePercentage->setObjectName(QString::fromUtf8("doubleSpinBox_SubProDefencePercentage"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProDefencePercentage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProDefencePercentage->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProDefencePercentage->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProDefencePercentage->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProDefencePercentage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProDefencePercentage->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_10->addWidget(doubleSpinBox_SubProDefencePercentage);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        checkBox_SubProDebuffDefence = new QCheckBox(groupBox_SubProFilter);
        checkBox_SubProDebuffDefence->setObjectName(QString::fromUtf8("checkBox_SubProDebuffDefence"));
        sizePolicy1.setHeightForWidth(checkBox_SubProDebuffDefence->sizePolicy().hasHeightForWidth());
        checkBox_SubProDebuffDefence->setSizePolicy(sizePolicy1);
        checkBox_SubProDebuffDefence->setMinimumSize(QSize(102, 24));
        checkBox_SubProDebuffDefence->setMaximumSize(QSize(102, 24));

        horizontalLayout_11->addWidget(checkBox_SubProDebuffDefence);

        label_7 = new QLabel(groupBox_SubProFilter);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(64, 24));
        label_7->setMaximumSize(QSize(64, 24));

        horizontalLayout_11->addWidget(label_7);

        doubleSpinBox_SubProDebuffDefence = new QDoubleSpinBox(groupBox_SubProFilter);
        doubleSpinBox_SubProDebuffDefence->setObjectName(QString::fromUtf8("doubleSpinBox_SubProDebuffDefence"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_SubProDebuffDefence->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SubProDebuffDefence->setSizePolicy(sizePolicy1);
        doubleSpinBox_SubProDebuffDefence->setMinimumSize(QSize(64, 24));
        doubleSpinBox_SubProDebuffDefence->setMaximumSize(QSize(64, 24));
        doubleSpinBox_SubProDebuffDefence->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_SubProDebuffDefence->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_11->addWidget(doubleSpinBox_SubProDebuffDefence);


        verticalLayout_3->addLayout(horizontalLayout_11);

        widget = new QWidget(groupBox_SubProFilter);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 56));
        widget->setMaximumSize(QSize(16777215, 56));

        verticalLayout_3->addWidget(widget);


        horizontalLayout_17->addLayout(verticalLayout_3);


        verticalLayout_5->addWidget(groupBox_SubProFilter);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_13 = new QLabel(widget_panel);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        horizontalLayout_18->addWidget(label_13);

        spinBox_playTime = new QSpinBox(widget_panel);
        spinBox_playTime->setObjectName(QString::fromUtf8("spinBox_playTime"));
        sizePolicy1.setHeightForWidth(spinBox_playTime->sizePolicy().hasHeightForWidth());
        spinBox_playTime->setSizePolicy(sizePolicy1);
        spinBox_playTime->setMinimumSize(QSize(48, 24));
        spinBox_playTime->setMaximumSize(QSize(48, 24));
        spinBox_playTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_playTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_playTime->setMaximum(10000000);

        horizontalLayout_18->addWidget(spinBox_playTime);

        widget_2 = new QWidget(widget_panel);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        horizontalLayout_18->addWidget(widget_2);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        pushButton_startEstimate = new QPushButton(widget_panel);
        pushButton_startEstimate->setObjectName(QString::fromUtf8("pushButton_startEstimate"));

        horizontalLayout_19->addWidget(pushButton_startEstimate);

        pushButton_resetPara = new QPushButton(widget_panel);
        pushButton_resetPara->setObjectName(QString::fromUtf8("pushButton_resetPara"));

        horizontalLayout_19->addWidget(pushButton_resetPara);

        pushButton_clearResult = new QPushButton(widget_panel);
        pushButton_clearResult->setObjectName(QString::fromUtf8("pushButton_clearResult"));

        horizontalLayout_19->addWidget(pushButton_clearResult);

        label_14 = new QLabel(widget_panel);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_19->addWidget(label_14);

        progressBar_EstimateProgress = new QProgressBar(widget_panel);
        progressBar_EstimateProgress->setObjectName(QString::fromUtf8("progressBar_EstimateProgress"));
        progressBar_EstimateProgress->setValue(24);

        horizontalLayout_19->addWidget(progressBar_EstimateProgress);


        verticalLayout_5->addLayout(horizontalLayout_19);

        label_ErrorMsg = new QLabel(widget_panel);
        label_ErrorMsg->setObjectName(QString::fromUtf8("label_ErrorMsg"));
        sizePolicy2.setHeightForWidth(label_ErrorMsg->sizePolicy().hasHeightForWidth());
        label_ErrorMsg->setSizePolicy(sizePolicy2);
        label_ErrorMsg->setMinimumSize(QSize(0, 24));
        label_ErrorMsg->setMaximumSize(QSize(16777215, 24));

        verticalLayout_5->addWidget(label_ErrorMsg);

        groupBox_statisticalConclusiaon = new QGroupBox(widget_panel);
        groupBox_statisticalConclusiaon->setObjectName(QString::fromUtf8("groupBox_statisticalConclusiaon"));
        horizontalLayout_20 = new QHBoxLayout(groupBox_statisticalConclusiaon);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_PriProValidProportion = new QLabel(groupBox_statisticalConclusiaon);
        label_PriProValidProportion->setObjectName(QString::fromUtf8("label_PriProValidProportion"));

        verticalLayout_6->addWidget(label_PriProValidProportion);

        label_PriProValidGetProbability = new QLabel(groupBox_statisticalConclusiaon);
        label_PriProValidGetProbability->setObjectName(QString::fromUtf8("label_PriProValidGetProbability"));

        verticalLayout_6->addWidget(label_PriProValidGetProbability);

        label_PriProValidGetTimeExpectation = new QLabel(groupBox_statisticalConclusiaon);
        label_PriProValidGetTimeExpectation->setObjectName(QString::fromUtf8("label_PriProValidGetTimeExpectation"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(248);
        sizePolicy3.setVerticalStretch(12);
        sizePolicy3.setHeightForWidth(label_PriProValidGetTimeExpectation->sizePolicy().hasHeightForWidth());
        label_PriProValidGetTimeExpectation->setSizePolicy(sizePolicy3);
        label_PriProValidGetTimeExpectation->setMinimumSize(QSize(248, 12));

        verticalLayout_6->addWidget(label_PriProValidGetTimeExpectation);

        label_PriProValidGetPlayTimeExpectation = new QLabel(groupBox_statisticalConclusiaon);
        label_PriProValidGetPlayTimeExpectation->setObjectName(QString::fromUtf8("label_PriProValidGetPlayTimeExpectation"));

        verticalLayout_6->addWidget(label_PriProValidGetPlayTimeExpectation);


        horizontalLayout_20->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_AllProValidProportion = new QLabel(groupBox_statisticalConclusiaon);
        label_AllProValidProportion->setObjectName(QString::fromUtf8("label_AllProValidProportion"));

        verticalLayout_7->addWidget(label_AllProValidProportion);

        label_AllPropertyValidGetPercentage = new QLabel(groupBox_statisticalConclusiaon);
        label_AllPropertyValidGetPercentage->setObjectName(QString::fromUtf8("label_AllPropertyValidGetPercentage"));

        verticalLayout_7->addWidget(label_AllPropertyValidGetPercentage);

        label_AllProValidGetTimeExpectation = new QLabel(groupBox_statisticalConclusiaon);
        label_AllProValidGetTimeExpectation->setObjectName(QString::fromUtf8("label_AllProValidGetTimeExpectation"));
        sizePolicy3.setHeightForWidth(label_AllProValidGetTimeExpectation->sizePolicy().hasHeightForWidth());
        label_AllProValidGetTimeExpectation->setSizePolicy(sizePolicy3);
        label_AllProValidGetTimeExpectation->setMinimumSize(QSize(248, 12));

        verticalLayout_7->addWidget(label_AllProValidGetTimeExpectation);

        label_AllPropertyGetPlayTimeExpectation = new QLabel(groupBox_statisticalConclusiaon);
        label_AllPropertyGetPlayTimeExpectation->setObjectName(QString::fromUtf8("label_AllPropertyGetPlayTimeExpectation"));

        verticalLayout_7->addWidget(label_AllPropertyGetPlayTimeExpectation);


        horizontalLayout_20->addLayout(verticalLayout_7);


        verticalLayout_5->addWidget(groupBox_statisticalConclusiaon);

        groupBox_4 = new QGroupBox(widget_panel);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_4->addWidget(label_16);

        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_4->addWidget(label_19);

        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_4->addWidget(label_20);


        verticalLayout_5->addWidget(groupBox_4);


        verticalLayout_8->addWidget(widget_panel);


        horizontalLayout_22->addLayout(verticalLayout_8);


        retranslateUi(RelicCultivateWgt);

        QMetaObject::connectSlotsByName(RelicCultivateWgt);
    } // setupUi

    void retranslateUi(QWidget *RelicCultivateWgt)
    {
        RelicCultivateWgt->setWindowTitle(QApplication::translate("RelicCultivateWgt", "Form", nullptr));
        groupBox_targetRelic->setTitle(QApplication::translate("RelicCultivateWgt", "\350\256\241\347\256\227\345\234\243\351\201\227\347\211\251", nullptr));
        radioButton_head->setText(QApplication::translate("RelicCultivateWgt", "\345\244\264", nullptr));
        radioButton_hand->setText(QApplication::translate("RelicCultivateWgt", "\346\211\213", nullptr));
        radioButton_clothes->setText(QApplication::translate("RelicCultivateWgt", "\350\241\243", nullptr));
        radioButton_shoes->setText(QApplication::translate("RelicCultivateWgt", "\351\236\213", nullptr));
        radioButton_cord->setText(QApplication::translate("RelicCultivateWgt", "\347\273\263", nullptr));
        radioButton_ball->setText(QApplication::translate("RelicCultivateWgt", "\347\220\203", nullptr));
        groupBox_ValidPriProperites->setTitle(QApplication::translate("RelicCultivateWgt", "\346\234\211\346\225\210\344\270\273\345\261\236\346\200\247", nullptr));
        checkBox_PriProAttactPercent->setText(QApplication::translate("RelicCultivateWgt", "\347\231\276\345\210\206\346\257\224\346\224\273\345\207\273", nullptr));
        checkBox_PriProCriticalProb->setText(QApplication::translate("RelicCultivateWgt", "\346\232\264\345\207\273\347\216\207", nullptr));
        checkBox_PriProCriticalDamage->setText(QApplication::translate("RelicCultivateWgt", "\346\232\264\345\207\273\344\274\244\345\256\263", nullptr));
        checkBox_PriProSpeed->setText(QApplication::translate("RelicCultivateWgt", "\351\200\237\345\272\246", nullptr));
        checkBox_PriProChargeEfficiency->setText(QApplication::translate("RelicCultivateWgt", "\345\205\205\350\203\275\346\225\210\347\216\207", nullptr));
        checkBox_PriProBreakDamage->setText(QApplication::translate("RelicCultivateWgt", "\345\207\273\347\240\264\347\211\271\346\224\273", nullptr));
        checkBox_PriProDebuffAccuracy->setText(QApplication::translate("RelicCultivateWgt", "\346\225\210\346\236\234\345\221\275\344\270\255", nullptr));
        checkBox_PriProHealAddition->setText(QApplication::translate("RelicCultivateWgt", "\346\262\273\347\226\227\345\212\240\346\210\220", nullptr));
        checkBox_PriProHPPercentage->setText(QApplication::translate("RelicCultivateWgt", "\347\231\276\345\210\206\346\257\224\347\224\237\345\221\275", nullptr));
        checkBox_PriProDefencePercentage->setText(QApplication::translate("RelicCultivateWgt", "\347\231\276\345\210\206\346\257\224\351\230\262\345\276\241", nullptr));
        checkBox_PriProFire->setText(QApplication::translate("RelicCultivateWgt", "\347\201\253\344\274\244\345\212\240\346\210\220", nullptr));
        checkBox_PriProThunder->setText(QApplication::translate("RelicCultivateWgt", "\351\233\267\344\274\244\345\212\240\346\210\220", nullptr));
        checkBox_PriProWind->setText(QApplication::translate("RelicCultivateWgt", "\351\243\216\344\274\244\345\212\240\346\210\220", nullptr));
        checkBox_PriProIce->setText(QApplication::translate("RelicCultivateWgt", "\345\206\260\344\274\244\345\212\240\346\210\220", nullptr));
        checkBox_PriProNull->setText(QApplication::translate("RelicCultivateWgt", "\350\231\232\346\227\240\345\212\240\346\210\220", nullptr));
        checkBox_PriProQuantum->setText(QApplication::translate("RelicCultivateWgt", "\351\207\217\345\255\220\345\212\240\346\210\220", nullptr));
        checkBox_PriProPhysical->setText(QApplication::translate("RelicCultivateWgt", "\347\211\251\347\220\206\345\212\240\346\210\220", nullptr));
        groupBox_SubProFilter->setTitle(QApplication::translate("RelicCultivateWgt", "\345\211\257\350\257\215\347\274\200\347\255\233\351\200\211\346\235\241\344\273\266", nullptr));
        checkBox_SubProAttackValue->setText(QApplication::translate("RelicCultivateWgt", "\345\233\272\345\256\232\346\224\273\345\207\273\345\212\233", nullptr));
        label_3->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProAttackPercentage->setText(QApplication::translate("RelicCultivateWgt", "\347\231\276\345\210\206\346\257\224\346\224\273\345\207\273", nullptr));
        label_4->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProCriticalPercentage->setText(QApplication::translate("RelicCultivateWgt", "\346\232\264\345\207\273\347\216\207", nullptr));
        label_10->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProCriticialDamage->setText(QApplication::translate("RelicCultivateWgt", "\346\232\264\345\207\273\344\274\244\345\256\263", nullptr));
        label_11->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProSpeed->setText(QApplication::translate("RelicCultivateWgt", "\351\200\237\345\272\246", nullptr));
        label_12->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProDebuffAccuracy->setText(QApplication::translate("RelicCultivateWgt", "\346\225\210\346\236\234\345\221\275\344\270\255", nullptr));
        label_8->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProBreakDamage->setText(QApplication::translate("RelicCultivateWgt", "\345\207\273\347\240\264\347\211\271\346\224\273", nullptr));
        label_9->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProHPValue->setText(QApplication::translate("RelicCultivateWgt", "\345\233\272\345\256\232\347\224\237\345\221\275\345\200\274", nullptr));
        label->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProHPPercentage->setText(QApplication::translate("RelicCultivateWgt", "\347\231\276\345\210\206\346\257\224\347\224\237\345\221\275", nullptr));
        label_2->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProDefenceValue->setText(QApplication::translate("RelicCultivateWgt", "\345\233\272\345\256\232\351\230\262\345\276\241\345\212\233", nullptr));
        label_5->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProDefencePercentage->setText(QApplication::translate("RelicCultivateWgt", "\347\231\276\345\210\206\346\257\224\351\230\262\345\276\241", nullptr));
        label_6->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        checkBox_SubProDebuffDefence->setText(QApplication::translate("RelicCultivateWgt", "\346\225\210\346\236\234\346\212\265\346\212\227", nullptr));
        label_7->setText(QApplication::translate("RelicCultivateWgt", "\345\244\247\344\272\216\347\255\211\344\272\216", nullptr));
        label_13->setText(QApplication::translate("RelicCultivateWgt", "\346\211\223\346\234\254\346\254\241\346\225\260", nullptr));
        pushButton_startEstimate->setText(QApplication::translate("RelicCultivateWgt", "\345\274\200\345\247\213\350\256\241\347\256\227", nullptr));
        pushButton_resetPara->setText(QApplication::translate("RelicCultivateWgt", "\351\207\215\347\275\256\345\217\202\346\225\260", nullptr));
        pushButton_clearResult->setText(QApplication::translate("RelicCultivateWgt", "\346\270\205\347\220\206\347\273\223\346\236\234", nullptr));
        label_14->setText(QApplication::translate("RelicCultivateWgt", "\350\256\241\347\256\227\350\277\233\345\272\246", nullptr));
        label_ErrorMsg->setText(QApplication::translate("RelicCultivateWgt", "\351\224\231\350\257\257\347\240\201", nullptr));
        groupBox_statisticalConclusiaon->setTitle(QApplication::translate("RelicCultivateWgt", "\347\273\237\350\256\241\347\273\223\350\256\272", nullptr));
        label_PriProValidProportion->setText(QApplication::translate("RelicCultivateWgt", "\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\257\224\344\276\213\357\274\232", nullptr));
        label_PriProValidGetProbability->setText(QApplication::translate("RelicCultivateWgt", "\346\211\223\346\234\254\350\216\267\345\217\226\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\246\202\347\216\207\357\274\232", nullptr));
        label_PriProValidGetTimeExpectation->setText(QApplication::translate("RelicCultivateWgt", "\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\350\216\267\345\217\226\346\234\237\346\234\233\357\274\232", nullptr));
        label_PriProValidGetPlayTimeExpectation->setText(QApplication::translate("RelicCultivateWgt", "\350\216\267\345\217\226\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\211\223\346\234\254\346\254\241\346\225\260\346\234\237\346\234\233\357\274\232", nullptr));
        label_AllProValidProportion->setText(QApplication::translate("RelicCultivateWgt", "\345\205\250\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\257\224\344\276\213\357\274\232", nullptr));
        label_AllPropertyValidGetPercentage->setText(QApplication::translate("RelicCultivateWgt", "\346\211\223\346\234\254\350\216\267\345\217\226\345\205\250\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\246\202\347\216\207\357\274\232", nullptr));
        label_AllProValidGetTimeExpectation->setText(QApplication::translate("RelicCultivateWgt", "\345\205\250\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\350\216\267\345\217\226\346\234\237\346\234\233\357\274\232", nullptr));
        label_AllPropertyGetPlayTimeExpectation->setText(QApplication::translate("RelicCultivateWgt", "\350\216\267\345\217\226\345\205\250\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\211\223\346\234\254\346\254\241\346\225\260\346\234\237\346\234\233\357\274\232", nullptr));
        groupBox_4->setTitle(QApplication::translate("RelicCultivateWgt", "\345\244\207\346\263\250", nullptr));
        label_15->setText(QApplication::translate("RelicCultivateWgt", "1.\350\256\241\347\256\227\347\232\204\346\230\257\346\237\220\344\270\200\344\270\252\346\234\254\344\270\255\346\237\220\344\270\200\344\270\252\345\245\227\350\243\205\347\232\204\346\237\220\344\270\200\344\270\252\351\203\250\344\273\266", nullptr));
        label_16->setText(QApplication::translate("RelicCultivateWgt", "2.\345\217\252\346\234\211\346\273\241\350\266\263\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210+\345\211\257\345\261\236\346\200\247\346\234\211\346\225\210\347\232\204\345\234\243\351\201\227\347\211\251\346\211\215\344\274\232\350\242\253\350\256\244\344\275\234\346\234\211\346\225\210", nullptr));
        label_19->setText(QApplication::translate("RelicCultivateWgt", "3.\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\346\257\224\344\276\213\357\274\232\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\346\200\273\346\225\260/\350\216\267\345\217\226\351\201\227\347\211\251\346\200\273\346\225\260", nullptr));
        label_20->setText(QApplication::translate("RelicCultivateWgt", "4.\346\211\223\346\234\254\350\216\267\345\217\226\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\346\246\202\347\216\207\357\274\232\346\211\223\346\234\254\350\216\267\345\276\227\344\270\273\345\261\236\346\200\247\346\234\211\346\225\210\351\201\227\347\211\251\347\232\204\346\254\241\346\225\260/\346\200\273\346\211\223\346\234\254\346\254\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RelicCultivateWgt: public Ui_RelicCultivateWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELICCULTIVATEWGT_H
