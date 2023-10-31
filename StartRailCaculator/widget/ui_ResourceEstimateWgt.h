/********************************************************************************
** Form generated from reading UI file 'ResourceEstimateWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOURCEESTIMATEWGT_H
#define UI_RESOURCEESTIMATEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResourceEstimateWgt
{
public:
    QHBoxLayout *horizontalLayout_8;
    QWidget *wgt_graph;
    QVBoxLayout *verticalLayout_7;
    QWidget *wgt_panel;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_input;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_today;
    QDateEdit *dateEdit_today;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_stopDay;
    QDateEdit *dateEdit_stopday;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout;
    QLabel *label_currentTicket;
    QSpinBox *spinBox_currentTicket;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_currentCrystal;
    QSpinBox *spinBox_currentCrystal;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_smallMonthCard;
    QCheckBox *checkBox_bigMonthCard;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_smallMonthCardReaminDay;
    QSpinBox *spinBox_smallMonthCardRemainDay;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_currentPaidCrystal;
    QSpinBox *spinBox_currentPaidCrystal;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *spinBox_averageAbyssNum;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_startCaculate;
    QPushButton *pushButton_resetParameter;
    QLabel *label_ErrorMessage;
    QGroupBox *groupBox_output;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_currentEqualCrystal;
    QLabel *label_CurrentEqualTicket;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_StopDayCrystal;
    QLabel *label_StopdayTicket;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_StopDayPaidCrystal;
    QLabel *label_placeHolder_1;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_StopdayEqualCrystal;
    QLabel *label_StopDayEqualTicket;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_SmallMonthCardInvestment;
    QLabel *label_BigMonthCardInvestment;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_TotalInvestMent;
    QLabel *label_PlaceHolder_2;
    QPushButton *pushButton_clearResult;
    QGroupBox *groupBox_comment;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_comment;
    QLabel *label_comment1;
    QLabel *label_comment2;
    QLabel *label_comment3;
    QLabel *label_comment4;
    QLabel *label_comment4_2;
    QLabel *label_comment5;
    QWidget *widget_placeholder;

    void setupUi(QWidget *ResourceEstimateWgt)
    {
        if (ResourceEstimateWgt->objectName().isEmpty())
            ResourceEstimateWgt->setObjectName(QString::fromUtf8("ResourceEstimateWgt"));
        ResourceEstimateWgt->resize(1266, 865);
        horizontalLayout_8 = new QHBoxLayout(ResourceEstimateWgt);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        wgt_graph = new QWidget(ResourceEstimateWgt);
        wgt_graph->setObjectName(QString::fromUtf8("wgt_graph"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wgt_graph->sizePolicy().hasHeightForWidth());
        wgt_graph->setSizePolicy(sizePolicy);
        wgt_graph->setMinimumSize(QSize(640, 320));

        horizontalLayout_8->addWidget(wgt_graph);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        wgt_panel = new QWidget(ResourceEstimateWgt);
        wgt_panel->setObjectName(QString::fromUtf8("wgt_panel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wgt_panel->sizePolicy().hasHeightForWidth());
        wgt_panel->setSizePolicy(sizePolicy1);
        wgt_panel->setMinimumSize(QSize(434, 715));
        wgt_panel->setMaximumSize(QSize(320, 715));
        verticalLayout_3 = new QVBoxLayout(wgt_panel);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_input = new QGroupBox(wgt_panel);
        groupBox_input->setObjectName(QString::fromUtf8("groupBox_input"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_input->sizePolicy().hasHeightForWidth());
        groupBox_input->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(groupBox_input);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_today = new QLabel(groupBox_input);
        label_today->setObjectName(QString::fromUtf8("label_today"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_today->sizePolicy().hasHeightForWidth());
        label_today->setSizePolicy(sizePolicy3);
        label_today->setMinimumSize(QSize(0, 24));
        label_today->setMaximumSize(QSize(16777215, 24));
        label_today->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(label_today);

        dateEdit_today = new QDateEdit(groupBox_input);
        dateEdit_today->setObjectName(QString::fromUtf8("dateEdit_today"));
        sizePolicy1.setHeightForWidth(dateEdit_today->sizePolicy().hasHeightForWidth());
        dateEdit_today->setSizePolicy(sizePolicy1);
        dateEdit_today->setMinimumSize(QSize(100, 24));
        dateEdit_today->setMaximumSize(QSize(100, 24));

        horizontalLayout_3->addWidget(dateEdit_today);


        horizontalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_stopDay = new QLabel(groupBox_input);
        label_stopDay->setObjectName(QString::fromUtf8("label_stopDay"));

        horizontalLayout_5->addWidget(label_stopDay);

        dateEdit_stopday = new QDateEdit(groupBox_input);
        dateEdit_stopday->setObjectName(QString::fromUtf8("dateEdit_stopday"));
        sizePolicy1.setHeightForWidth(dateEdit_stopday->sizePolicy().hasHeightForWidth());
        dateEdit_stopday->setSizePolicy(sizePolicy1);
        dateEdit_stopday->setMinimumSize(QSize(100, 24));
        dateEdit_stopday->setMaximumSize(QSize(100, 24));

        horizontalLayout_5->addWidget(dateEdit_stopday);


        horizontalLayout_11->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_currentTicket = new QLabel(groupBox_input);
        label_currentTicket->setObjectName(QString::fromUtf8("label_currentTicket"));
        sizePolicy3.setHeightForWidth(label_currentTicket->sizePolicy().hasHeightForWidth());
        label_currentTicket->setSizePolicy(sizePolicy3);
        label_currentTicket->setMinimumSize(QSize(0, 24));
        label_currentTicket->setMaximumSize(QSize(16777215, 24));
        label_currentTicket->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(label_currentTicket);

        spinBox_currentTicket = new QSpinBox(groupBox_input);
        spinBox_currentTicket->setObjectName(QString::fromUtf8("spinBox_currentTicket"));
        sizePolicy1.setHeightForWidth(spinBox_currentTicket->sizePolicy().hasHeightForWidth());
        spinBox_currentTicket->setSizePolicy(sizePolicy1);
        spinBox_currentTicket->setMinimumSize(QSize(70, 24));
        spinBox_currentTicket->setMaximumSize(QSize(70, 24));
        spinBox_currentTicket->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_currentTicket->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_currentTicket->setMaximum(100000);

        horizontalLayout->addWidget(spinBox_currentTicket);


        horizontalLayout_13->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_currentCrystal = new QLabel(groupBox_input);
        label_currentCrystal->setObjectName(QString::fromUtf8("label_currentCrystal"));
        sizePolicy3.setHeightForWidth(label_currentCrystal->sizePolicy().hasHeightForWidth());
        label_currentCrystal->setSizePolicy(sizePolicy3);
        label_currentCrystal->setMinimumSize(QSize(0, 24));
        label_currentCrystal->setMaximumSize(QSize(16777215, 24));
        label_currentCrystal->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(label_currentCrystal);

        spinBox_currentCrystal = new QSpinBox(groupBox_input);
        spinBox_currentCrystal->setObjectName(QString::fromUtf8("spinBox_currentCrystal"));
        sizePolicy1.setHeightForWidth(spinBox_currentCrystal->sizePolicy().hasHeightForWidth());
        spinBox_currentCrystal->setSizePolicy(sizePolicy1);
        spinBox_currentCrystal->setMinimumSize(QSize(70, 24));
        spinBox_currentCrystal->setMaximumSize(QSize(70, 24));
        spinBox_currentCrystal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_currentCrystal->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_currentCrystal->setMaximum(10000000);

        horizontalLayout_2->addWidget(spinBox_currentCrystal);


        horizontalLayout_13->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        checkBox_smallMonthCard = new QCheckBox(groupBox_input);
        checkBox_smallMonthCard->setObjectName(QString::fromUtf8("checkBox_smallMonthCard"));

        horizontalLayout_10->addWidget(checkBox_smallMonthCard);

        checkBox_bigMonthCard = new QCheckBox(groupBox_input);
        checkBox_bigMonthCard->setObjectName(QString::fromUtf8("checkBox_bigMonthCard"));

        horizontalLayout_10->addWidget(checkBox_bigMonthCard);


        horizontalLayout_12->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_smallMonthCardReaminDay = new QLabel(groupBox_input);
        label_smallMonthCardReaminDay->setObjectName(QString::fromUtf8("label_smallMonthCardReaminDay"));
        label_smallMonthCardReaminDay->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_9->addWidget(label_smallMonthCardReaminDay);

        spinBox_smallMonthCardRemainDay = new QSpinBox(groupBox_input);
        spinBox_smallMonthCardRemainDay->setObjectName(QString::fromUtf8("spinBox_smallMonthCardRemainDay"));
        sizePolicy1.setHeightForWidth(spinBox_smallMonthCardRemainDay->sizePolicy().hasHeightForWidth());
        spinBox_smallMonthCardRemainDay->setSizePolicy(sizePolicy1);
        spinBox_smallMonthCardRemainDay->setMinimumSize(QSize(48, 24));
        spinBox_smallMonthCardRemainDay->setMaximumSize(QSize(48, 24));
        spinBox_smallMonthCardRemainDay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_smallMonthCardRemainDay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_smallMonthCardRemainDay->setMaximum(30);

        horizontalLayout_9->addWidget(spinBox_smallMonthCardRemainDay);


        horizontalLayout_12->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_currentPaidCrystal = new QLabel(groupBox_input);
        label_currentPaidCrystal->setObjectName(QString::fromUtf8("label_currentPaidCrystal"));
        sizePolicy3.setHeightForWidth(label_currentPaidCrystal->sizePolicy().hasHeightForWidth());
        label_currentPaidCrystal->setSizePolicy(sizePolicy3);
        label_currentPaidCrystal->setMinimumSize(QSize(0, 24));
        label_currentPaidCrystal->setMaximumSize(QSize(16777215, 24));
        label_currentPaidCrystal->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_7->addWidget(label_currentPaidCrystal);

        spinBox_currentPaidCrystal = new QSpinBox(groupBox_input);
        spinBox_currentPaidCrystal->setObjectName(QString::fromUtf8("spinBox_currentPaidCrystal"));
        sizePolicy1.setHeightForWidth(spinBox_currentPaidCrystal->sizePolicy().hasHeightForWidth());
        spinBox_currentPaidCrystal->setSizePolicy(sizePolicy1);
        spinBox_currentPaidCrystal->setMinimumSize(QSize(70, 24));
        spinBox_currentPaidCrystal->setMaximumSize(QSize(70, 24));
        spinBox_currentPaidCrystal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_currentPaidCrystal->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_currentPaidCrystal->setMaximum(10000000);

        horizontalLayout_7->addWidget(spinBox_currentPaidCrystal);


        horizontalLayout_14->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(groupBox_input);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_4->addWidget(label);

        spinBox_averageAbyssNum = new QSpinBox(groupBox_input);
        spinBox_averageAbyssNum->setObjectName(QString::fromUtf8("spinBox_averageAbyssNum"));
        sizePolicy1.setHeightForWidth(spinBox_averageAbyssNum->sizePolicy().hasHeightForWidth());
        spinBox_averageAbyssNum->setSizePolicy(sizePolicy1);
        spinBox_averageAbyssNum->setMinimumSize(QSize(50, 24));
        spinBox_averageAbyssNum->setMaximumSize(QSize(50, 24));
        spinBox_averageAbyssNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(spinBox_averageAbyssNum);


        horizontalLayout_14->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_14);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_startCaculate = new QPushButton(groupBox_input);
        pushButton_startCaculate->setObjectName(QString::fromUtf8("pushButton_startCaculate"));
        sizePolicy3.setHeightForWidth(pushButton_startCaculate->sizePolicy().hasHeightForWidth());
        pushButton_startCaculate->setSizePolicy(sizePolicy3);
        pushButton_startCaculate->setMinimumSize(QSize(64, 32));

        horizontalLayout_6->addWidget(pushButton_startCaculate);

        pushButton_resetParameter = new QPushButton(groupBox_input);
        pushButton_resetParameter->setObjectName(QString::fromUtf8("pushButton_resetParameter"));
        pushButton_resetParameter->setMinimumSize(QSize(64, 32));

        horizontalLayout_6->addWidget(pushButton_resetParameter);


        verticalLayout_5->addLayout(horizontalLayout_6);

        label_ErrorMessage = new QLabel(groupBox_input);
        label_ErrorMessage->setObjectName(QString::fromUtf8("label_ErrorMessage"));
        sizePolicy3.setHeightForWidth(label_ErrorMessage->sizePolicy().hasHeightForWidth());
        label_ErrorMessage->setSizePolicy(sizePolicy3);
        label_ErrorMessage->setMinimumSize(QSize(0, 24));
        label_ErrorMessage->setMaximumSize(QSize(16777215, 24));
        label_ErrorMessage->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_5->addWidget(label_ErrorMessage);


        verticalLayout->addLayout(verticalLayout_5);


        verticalLayout_3->addWidget(groupBox_input);

        groupBox_output = new QGroupBox(wgt_panel);
        groupBox_output->setObjectName(QString::fromUtf8("groupBox_output"));
        sizePolicy3.setHeightForWidth(groupBox_output->sizePolicy().hasHeightForWidth());
        groupBox_output->setSizePolicy(sizePolicy3);
        groupBox_output->setFocusPolicy(Qt::StrongFocus);
        verticalLayout_2 = new QVBoxLayout(groupBox_output);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_currentEqualCrystal = new QLabel(groupBox_output);
        label_currentEqualCrystal->setObjectName(QString::fromUtf8("label_currentEqualCrystal"));
        label_currentEqualCrystal->setMinimumSize(QSize(180, 24));
        label_currentEqualCrystal->setMaximumSize(QSize(180, 24));
        label_currentEqualCrystal->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_15->addWidget(label_currentEqualCrystal);

        label_CurrentEqualTicket = new QLabel(groupBox_output);
        label_CurrentEqualTicket->setObjectName(QString::fromUtf8("label_CurrentEqualTicket"));
        label_CurrentEqualTicket->setMinimumSize(QSize(180, 24));
        label_CurrentEqualTicket->setMaximumSize(QSize(180, 24));
        label_CurrentEqualTicket->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_15->addWidget(label_CurrentEqualTicket);


        verticalLayout_6->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_StopDayCrystal = new QLabel(groupBox_output);
        label_StopDayCrystal->setObjectName(QString::fromUtf8("label_StopDayCrystal"));
        sizePolicy1.setHeightForWidth(label_StopDayCrystal->sizePolicy().hasHeightForWidth());
        label_StopDayCrystal->setSizePolicy(sizePolicy1);
        label_StopDayCrystal->setMinimumSize(QSize(180, 24));
        label_StopDayCrystal->setMaximumSize(QSize(180, 24));
        label_StopDayCrystal->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_16->addWidget(label_StopDayCrystal);

        label_StopdayTicket = new QLabel(groupBox_output);
        label_StopdayTicket->setObjectName(QString::fromUtf8("label_StopdayTicket"));
        sizePolicy1.setHeightForWidth(label_StopdayTicket->sizePolicy().hasHeightForWidth());
        label_StopdayTicket->setSizePolicy(sizePolicy1);
        label_StopdayTicket->setMinimumSize(QSize(180, 24));
        label_StopdayTicket->setMaximumSize(QSize(180, 24));
        label_StopdayTicket->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_16->addWidget(label_StopdayTicket);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_StopDayPaidCrystal = new QLabel(groupBox_output);
        label_StopDayPaidCrystal->setObjectName(QString::fromUtf8("label_StopDayPaidCrystal"));
        label_StopDayPaidCrystal->setMinimumSize(QSize(180, 24));
        label_StopDayPaidCrystal->setMaximumSize(QSize(180, 24));
        label_StopDayPaidCrystal->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_19->addWidget(label_StopDayPaidCrystal);

        label_placeHolder_1 = new QLabel(groupBox_output);
        label_placeHolder_1->setObjectName(QString::fromUtf8("label_placeHolder_1"));
        sizePolicy1.setHeightForWidth(label_placeHolder_1->sizePolicy().hasHeightForWidth());
        label_placeHolder_1->setSizePolicy(sizePolicy1);
        label_placeHolder_1->setMinimumSize(QSize(180, 24));
        label_placeHolder_1->setMaximumSize(QSize(180, 24));
        label_placeHolder_1->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_19->addWidget(label_placeHolder_1);


        verticalLayout_6->addLayout(horizontalLayout_19);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_StopdayEqualCrystal = new QLabel(groupBox_output);
        label_StopdayEqualCrystal->setObjectName(QString::fromUtf8("label_StopdayEqualCrystal"));
        sizePolicy1.setHeightForWidth(label_StopdayEqualCrystal->sizePolicy().hasHeightForWidth());
        label_StopdayEqualCrystal->setSizePolicy(sizePolicy1);
        label_StopdayEqualCrystal->setMinimumSize(QSize(180, 24));
        label_StopdayEqualCrystal->setMaximumSize(QSize(180, 24));
        label_StopdayEqualCrystal->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_17->addWidget(label_StopdayEqualCrystal);

        label_StopDayEqualTicket = new QLabel(groupBox_output);
        label_StopDayEqualTicket->setObjectName(QString::fromUtf8("label_StopDayEqualTicket"));
        label_StopDayEqualTicket->setMinimumSize(QSize(180, 24));
        label_StopDayEqualTicket->setMaximumSize(QSize(180, 24));
        label_StopDayEqualTicket->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_17->addWidget(label_StopDayEqualTicket);


        verticalLayout_6->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_SmallMonthCardInvestment = new QLabel(groupBox_output);
        label_SmallMonthCardInvestment->setObjectName(QString::fromUtf8("label_SmallMonthCardInvestment"));
        sizePolicy1.setHeightForWidth(label_SmallMonthCardInvestment->sizePolicy().hasHeightForWidth());
        label_SmallMonthCardInvestment->setSizePolicy(sizePolicy1);
        label_SmallMonthCardInvestment->setMinimumSize(QSize(180, 24));
        label_SmallMonthCardInvestment->setMaximumSize(QSize(180, 24));
        label_SmallMonthCardInvestment->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_18->addWidget(label_SmallMonthCardInvestment);

        label_BigMonthCardInvestment = new QLabel(groupBox_output);
        label_BigMonthCardInvestment->setObjectName(QString::fromUtf8("label_BigMonthCardInvestment"));
        sizePolicy1.setHeightForWidth(label_BigMonthCardInvestment->sizePolicy().hasHeightForWidth());
        label_BigMonthCardInvestment->setSizePolicy(sizePolicy1);
        label_BigMonthCardInvestment->setMinimumSize(QSize(180, 24));
        label_BigMonthCardInvestment->setMaximumSize(QSize(180, 24));
        label_BigMonthCardInvestment->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_18->addWidget(label_BigMonthCardInvestment);


        verticalLayout_6->addLayout(horizontalLayout_18);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_TotalInvestMent = new QLabel(groupBox_output);
        label_TotalInvestMent->setObjectName(QString::fromUtf8("label_TotalInvestMent"));
        sizePolicy1.setHeightForWidth(label_TotalInvestMent->sizePolicy().hasHeightForWidth());
        label_TotalInvestMent->setSizePolicy(sizePolicy1);
        label_TotalInvestMent->setMinimumSize(QSize(180, 24));
        label_TotalInvestMent->setMaximumSize(QSize(180, 24));
        label_TotalInvestMent->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_20->addWidget(label_TotalInvestMent);

        label_PlaceHolder_2 = new QLabel(groupBox_output);
        label_PlaceHolder_2->setObjectName(QString::fromUtf8("label_PlaceHolder_2"));
        sizePolicy1.setHeightForWidth(label_PlaceHolder_2->sizePolicy().hasHeightForWidth());
        label_PlaceHolder_2->setSizePolicy(sizePolicy1);
        label_PlaceHolder_2->setMinimumSize(QSize(180, 24));
        label_PlaceHolder_2->setMaximumSize(QSize(180, 24));

        horizontalLayout_20->addWidget(label_PlaceHolder_2);


        verticalLayout_6->addLayout(horizontalLayout_20);


        verticalLayout_2->addLayout(verticalLayout_6);

        pushButton_clearResult = new QPushButton(groupBox_output);
        pushButton_clearResult->setObjectName(QString::fromUtf8("pushButton_clearResult"));
        pushButton_clearResult->setMinimumSize(QSize(64, 32));

        verticalLayout_2->addWidget(pushButton_clearResult);


        verticalLayout_3->addWidget(groupBox_output);

        groupBox_comment = new QGroupBox(wgt_panel);
        groupBox_comment->setObjectName(QString::fromUtf8("groupBox_comment"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_comment->sizePolicy().hasHeightForWidth());
        groupBox_comment->setSizePolicy(sizePolicy4);
        groupBox_comment->setFocusPolicy(Qt::StrongFocus);
        verticalLayout_4 = new QVBoxLayout(groupBox_comment);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_comment = new QVBoxLayout();
        verticalLayout_comment->setObjectName(QString::fromUtf8("verticalLayout_comment"));
        label_comment1 = new QLabel(groupBox_comment);
        label_comment1->setObjectName(QString::fromUtf8("label_comment1"));

        verticalLayout_comment->addWidget(label_comment1);

        label_comment2 = new QLabel(groupBox_comment);
        label_comment2->setObjectName(QString::fromUtf8("label_comment2"));

        verticalLayout_comment->addWidget(label_comment2);

        label_comment3 = new QLabel(groupBox_comment);
        label_comment3->setObjectName(QString::fromUtf8("label_comment3"));

        verticalLayout_comment->addWidget(label_comment3);

        label_comment4 = new QLabel(groupBox_comment);
        label_comment4->setObjectName(QString::fromUtf8("label_comment4"));

        verticalLayout_comment->addWidget(label_comment4);

        label_comment4_2 = new QLabel(groupBox_comment);
        label_comment4_2->setObjectName(QString::fromUtf8("label_comment4_2"));

        verticalLayout_comment->addWidget(label_comment4_2);

        label_comment5 = new QLabel(groupBox_comment);
        label_comment5->setObjectName(QString::fromUtf8("label_comment5"));

        verticalLayout_comment->addWidget(label_comment5);


        verticalLayout_4->addLayout(verticalLayout_comment);


        verticalLayout_3->addWidget(groupBox_comment);


        verticalLayout_7->addWidget(wgt_panel);

        widget_placeholder = new QWidget(ResourceEstimateWgt);
        widget_placeholder->setObjectName(QString::fromUtf8("widget_placeholder"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget_placeholder->sizePolicy().hasHeightForWidth());
        widget_placeholder->setSizePolicy(sizePolicy5);

        verticalLayout_7->addWidget(widget_placeholder);


        horizontalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(ResourceEstimateWgt);

        QMetaObject::connectSlotsByName(ResourceEstimateWgt);
    } // setupUi

    void retranslateUi(QWidget *ResourceEstimateWgt)
    {
        ResourceEstimateWgt->setWindowTitle(QApplication::translate("ResourceEstimateWgt", "Form", nullptr));
        groupBox_input->setTitle(QApplication::translate("ResourceEstimateWgt", "\350\256\241\347\256\227\345\217\202\346\225\260", nullptr));
        label_today->setText(QApplication::translate("ResourceEstimateWgt", "\344\273\212\345\244\251\346\227\245\346\234\237", nullptr));
        label_stopDay->setText(QApplication::translate("ResourceEstimateWgt", "\345\201\234\346\255\242\346\227\245\346\234\237", nullptr));
        label_currentTicket->setText(QApplication::translate("ResourceEstimateWgt", "\345\275\223\345\211\215\344\270\223\347\245\250", nullptr));
        label_currentCrystal->setText(QApplication::translate("ResourceEstimateWgt", "\345\275\223\345\211\215\346\230\237\347\220\274", nullptr));
        checkBox_smallMonthCard->setText(QApplication::translate("ResourceEstimateWgt", "\345\260\217\346\234\210\345\215\241", nullptr));
        checkBox_bigMonthCard->setText(QApplication::translate("ResourceEstimateWgt", "\345\244\247\346\234\210\345\215\241", nullptr));
        label_smallMonthCardReaminDay->setText(QApplication::translate("ResourceEstimateWgt", "\345\260\217\346\234\210\345\215\241\345\211\251\344\275\231\345\244\251\346\225\260", nullptr));
        label_currentPaidCrystal->setText(QApplication::translate("ResourceEstimateWgt", "\345\275\223\345\211\215\345\217\244\350\200\201\346\242\246\345\215\216", nullptr));
        label->setText(QApplication::translate("ResourceEstimateWgt", "\346\267\267\346\262\214\345\233\236\345\277\206\345\271\263\345\235\207\345\261\202\346\225\260", nullptr));
        pushButton_startCaculate->setText(QApplication::translate("ResourceEstimateWgt", "\345\274\200\345\247\213\350\256\241\347\256\227", nullptr));
        pushButton_resetParameter->setText(QApplication::translate("ResourceEstimateWgt", "\351\207\215\347\275\256\345\217\202\346\225\260", nullptr));
        label_ErrorMessage->setText(QApplication::translate("ResourceEstimateWgt", "\351\224\231\350\257\257\346\266\210\346\201\257:", nullptr));
        groupBox_output->setTitle(QApplication::translate("ResourceEstimateWgt", "\350\256\241\347\256\227\347\273\223\346\236\234", nullptr));
        label_currentEqualCrystal->setText(QApplication::translate("ResourceEstimateWgt", "\345\275\223\345\211\215\347\255\211\346\225\210\346\230\237\347\220\274\357\274\232", nullptr));
        label_CurrentEqualTicket->setText(QApplication::translate("ResourceEstimateWgt", "\345\275\223\345\211\215\347\255\211\346\225\210\344\270\223\347\245\250\357\274\232", nullptr));
        label_StopDayCrystal->setText(QApplication::translate("ResourceEstimateWgt", "\345\201\234\346\255\242\346\227\245\346\234\237\346\230\237\347\220\274:", nullptr));
        label_StopdayTicket->setText(QApplication::translate("ResourceEstimateWgt", "\345\201\234\346\255\242\346\227\245\346\234\237\344\270\223\347\245\250:", nullptr));
        label_StopDayPaidCrystal->setText(QApplication::translate("ResourceEstimateWgt", "\345\201\234\346\255\242\346\227\245\346\234\237\345\217\244\350\200\201\346\242\246\345\215\216:", nullptr));
        label_placeHolder_1->setText(QString());
        label_StopdayEqualCrystal->setText(QApplication::translate("ResourceEstimateWgt", "\345\201\234\346\255\242\346\227\245\346\234\237\347\255\211\346\225\210\346\230\237\347\220\274:", nullptr));
        label_StopDayEqualTicket->setText(QApplication::translate("ResourceEstimateWgt", "\345\201\234\346\255\242\346\227\245\346\234\237\347\255\211\346\225\210\344\270\223\347\245\250:", nullptr));
        label_SmallMonthCardInvestment->setText(QApplication::translate("ResourceEstimateWgt", "\347\264\257\350\256\241\345\260\217\346\234\210\345\215\241\346\212\225\345\205\245\357\274\232", nullptr));
        label_BigMonthCardInvestment->setText(QApplication::translate("ResourceEstimateWgt", "\347\264\257\350\256\241\345\244\247\346\234\210\345\215\241\346\212\225\345\205\245\357\274\232", nullptr));
        label_TotalInvestMent->setText(QApplication::translate("ResourceEstimateWgt", "\347\264\257\350\256\241\346\200\273\346\212\225\345\205\245\357\274\232", nullptr));
        label_PlaceHolder_2->setText(QString());
        pushButton_clearResult->setText(QApplication::translate("ResourceEstimateWgt", "\346\270\205\347\220\206\347\273\223\346\236\234", nullptr));
        groupBox_comment->setTitle(QApplication::translate("ResourceEstimateWgt", "\345\244\207\346\263\250", nullptr));
        label_comment1->setText(QApplication::translate("ResourceEstimateWgt", "1.\350\256\241\347\256\227\344\273\205\345\214\205\345\220\253\357\274\232\345\244\247\345\260\217\346\234\210\345\215\241/\346\227\245\345\270\270/\346\267\261\346\270\212/\346\250\241\346\213\237\345\256\207\345\256\231/\345\225\206\345\272\227/\346\233\264\346\226\260", nullptr));
        label_comment2->setText(QApplication::translate("ResourceEstimateWgt", "2.\351\273\230\350\256\244\345\244\247\347\211\210\346\234\254\346\233\264\346\226\260\350\241\245\345\201\277\344\270\272300\347\273\264\346\212\244+300\344\277\256BUG", nullptr));
        label_comment3->setText(QApplication::translate("ResourceEstimateWgt", "3.\351\273\230\350\256\244\346\257\217\346\234\210\347\254\254\344\270\200\345\244\251\345\216\273\344\275\231\347\203\254\345\225\206\345\272\227\346\215\242\345\217\2265\346\212\275", nullptr));
        label_comment4->setText(QApplication::translate("ResourceEstimateWgt", "4.\351\273\230\350\256\244\345\274\200\345\247\213\346\227\245\346\234\237\345\222\214\347\273\223\346\235\237\346\227\245\345\235\207\350\216\267\345\276\227\344\272\206\345\275\223\345\244\251\346\211\200\346\234\211\345\217\257\350\203\275\347\232\204\346\224\266\347\233\212", nullptr));
        label_comment4_2->setText(QApplication::translate("ResourceEstimateWgt", "\357\274\210\345\244\247\345\260\217\346\234\210\345\215\241+\346\250\241\346\213\237\345\256\207\345\256\231+\346\267\267\346\262\214\345\233\236\345\277\206+\345\275\223\346\234\210\345\225\206\345\272\227\344\270\223\347\245\250\357\274\211", nullptr));
        label_comment5->setText(QApplication::translate("ResourceEstimateWgt", "5.\350\256\241\347\256\227\346\227\266\351\227\264\344\273\205\351\231\220\357\274\2322023/4/26-2024/4/26\357\274\210\344\270\215\347\204\266\350\257\257\345\267\256\345\244\252\345\244\247\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResourceEstimateWgt: public Ui_ResourceEstimateWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOURCEESTIMATEWGT_H
