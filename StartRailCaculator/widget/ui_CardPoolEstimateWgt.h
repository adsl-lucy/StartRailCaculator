/********************************************************************************
** Form generated from reading UI file 'CardPoolEstimateWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDPOOLESTIMATEWGT_H
#define UI_CARDPOOLESTIMATEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_CardPoolEstimateWgt
{
public:
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_graph;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_panel;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_character;
    QRadioButton *radioButton_weapon;
    QCheckBox *checkBox_wrongGold;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_areadyInTicket;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_startEstimate;
    QPushButton *pushButton_resetPara;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QProgressBar *progressBar_EstimatePos;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_poolType;
    QLabel *label_distanceToBigGuarantee;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_PorbGetUpAtsmallGuarantee;
    QLabel *label_PorbGetUpAtBigGuarantee;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_ExpectationGetPos;
    QLabel *label_ExpectationCrystalExpense;
    QPushButton *pushButton_clearResult;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_17;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_18;
    QWidget *widget_placeholder;

    void setupUi(QWidget *CardPoolEstimateWgt)
    {
        if (CardPoolEstimateWgt->objectName().isEmpty())
            CardPoolEstimateWgt->setObjectName(QString::fromUtf8("CardPoolEstimateWgt"));
        CardPoolEstimateWgt->resize(1097, 830);
        horizontalLayout_8 = new QHBoxLayout(CardPoolEstimateWgt);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        widget_graph = new QWidget(CardPoolEstimateWgt);
        widget_graph->setObjectName(QString::fromUtf8("widget_graph"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_graph->sizePolicy().hasHeightForWidth());
        widget_graph->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(widget_graph);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_panel = new QWidget(CardPoolEstimateWgt);
        widget_panel->setObjectName(QString::fromUtf8("widget_panel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_panel->sizePolicy().hasHeightForWidth());
        widget_panel->setSizePolicy(sizePolicy1);
        widget_panel->setMinimumSize(QSize(464, 0));
        widget_panel->setMaximumSize(QSize(464, 701));
        verticalLayout_5 = new QVBoxLayout(widget_panel);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(widget_panel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setCheckable(false);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_character = new QRadioButton(groupBox);
        radioButton_character->setObjectName(QString::fromUtf8("radioButton_character"));

        horizontalLayout->addWidget(radioButton_character);

        radioButton_weapon = new QRadioButton(groupBox);
        radioButton_weapon->setObjectName(QString::fromUtf8("radioButton_weapon"));

        horizontalLayout->addWidget(radioButton_weapon);


        verticalLayout->addWidget(groupBox);

        checkBox_wrongGold = new QCheckBox(groupBox_2);
        checkBox_wrongGold->setObjectName(QString::fromUtf8("checkBox_wrongGold"));

        verticalLayout->addWidget(checkBox_wrongGold);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBox_areadyInTicket = new QSpinBox(groupBox_2);
        spinBox_areadyInTicket->setObjectName(QString::fromUtf8("spinBox_areadyInTicket"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_areadyInTicket->sizePolicy().hasHeightForWidth());
        spinBox_areadyInTicket->setSizePolicy(sizePolicy2);
        spinBox_areadyInTicket->setMinimumSize(QSize(48, 24));
        spinBox_areadyInTicket->setMaximumSize(QSize(24, 16777215));
        spinBox_areadyInTicket->setMaximum(89);

        horizontalLayout_2->addWidget(spinBox_areadyInTicket);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_startEstimate = new QPushButton(groupBox_2);
        pushButton_startEstimate->setObjectName(QString::fromUtf8("pushButton_startEstimate"));

        horizontalLayout_4->addWidget(pushButton_startEstimate);

        pushButton_resetPara = new QPushButton(groupBox_2);
        pushButton_resetPara->setObjectName(QString::fromUtf8("pushButton_resetPara"));

        horizontalLayout_4->addWidget(pushButton_resetPara);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setMaximumSize(QSize(16777215, 24));

        horizontalLayout_3->addWidget(label_2);

        progressBar_EstimatePos = new QProgressBar(groupBox_2);
        progressBar_EstimatePos->setObjectName(QString::fromUtf8("progressBar_EstimatePos"));
        progressBar_EstimatePos->setValue(24);

        horizontalLayout_3->addWidget(progressBar_EstimatePos);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget_panel);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_poolType = new QLabel(groupBox_3);
        label_poolType->setObjectName(QString::fromUtf8("label_poolType"));

        horizontalLayout_5->addWidget(label_poolType);

        label_distanceToBigGuarantee = new QLabel(groupBox_3);
        label_distanceToBigGuarantee->setObjectName(QString::fromUtf8("label_distanceToBigGuarantee"));

        horizontalLayout_5->addWidget(label_distanceToBigGuarantee);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_PorbGetUpAtsmallGuarantee = new QLabel(groupBox_3);
        label_PorbGetUpAtsmallGuarantee->setObjectName(QString::fromUtf8("label_PorbGetUpAtsmallGuarantee"));

        horizontalLayout_6->addWidget(label_PorbGetUpAtsmallGuarantee);

        label_PorbGetUpAtBigGuarantee = new QLabel(groupBox_3);
        label_PorbGetUpAtBigGuarantee->setObjectName(QString::fromUtf8("label_PorbGetUpAtBigGuarantee"));

        horizontalLayout_6->addWidget(label_PorbGetUpAtBigGuarantee);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_ExpectationGetPos = new QLabel(groupBox_3);
        label_ExpectationGetPos->setObjectName(QString::fromUtf8("label_ExpectationGetPos"));

        horizontalLayout_7->addWidget(label_ExpectationGetPos);

        label_ExpectationCrystalExpense = new QLabel(groupBox_3);
        label_ExpectationCrystalExpense->setObjectName(QString::fromUtf8("label_ExpectationCrystalExpense"));

        horizontalLayout_7->addWidget(label_ExpectationCrystalExpense);


        verticalLayout_3->addLayout(horizontalLayout_7);

        pushButton_clearResult = new QPushButton(groupBox_3);
        pushButton_clearResult->setObjectName(QString::fromUtf8("pushButton_clearResult"));

        verticalLayout_3->addWidget(pushButton_clearResult);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget_panel);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_4->addWidget(label_17);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_4->addWidget(label_18);


        verticalLayout_5->addWidget(groupBox_4);


        verticalLayout_6->addWidget(widget_panel);

        widget_placeholder = new QWidget(CardPoolEstimateWgt);
        widget_placeholder->setObjectName(QString::fromUtf8("widget_placeholder"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_placeholder->sizePolicy().hasHeightForWidth());
        widget_placeholder->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(widget_placeholder);


        horizontalLayout_8->addLayout(verticalLayout_6);


        retranslateUi(CardPoolEstimateWgt);

        QMetaObject::connectSlotsByName(CardPoolEstimateWgt);
    } // setupUi

    void retranslateUi(QWidget *CardPoolEstimateWgt)
    {
        CardPoolEstimateWgt->setWindowTitle(QApplication::translate("CardPoolEstimateWgt", "Form", nullptr));
        groupBox_2->setTitle(QApplication::translate("CardPoolEstimateWgt", "\346\250\241\346\213\237\345\217\202\346\225\260", nullptr));
        groupBox->setTitle(QApplication::translate("CardPoolEstimateWgt", "\345\215\241\346\261\240\347\261\273\345\236\213", nullptr));
        radioButton_character->setText(QApplication::translate("CardPoolEstimateWgt", "\350\247\222\350\211\262", nullptr));
        radioButton_weapon->setText(QApplication::translate("CardPoolEstimateWgt", "\345\205\211\351\224\245", nullptr));
        checkBox_wrongGold->setText(QApplication::translate("CardPoolEstimateWgt", "\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\346\255\252\344\272\206", nullptr));
        label->setText(QApplication::translate("CardPoolEstimateWgt", "\345\267\262\345\236\253\346\212\275\346\225\260\357\274\210\350\267\235\347\246\273\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\357\274\211", nullptr));
        pushButton_startEstimate->setText(QApplication::translate("CardPoolEstimateWgt", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
        pushButton_resetPara->setText(QApplication::translate("CardPoolEstimateWgt", "\351\207\215\347\275\256\345\217\202\346\225\260", nullptr));
        label_2->setText(QApplication::translate("CardPoolEstimateWgt", "\346\250\241\346\213\237\350\277\233\345\272\246", nullptr));
        groupBox_3->setTitle(QApplication::translate("CardPoolEstimateWgt", "\350\256\241\347\256\227\347\273\223\346\236\234", nullptr));
        label_poolType->setText(QApplication::translate("CardPoolEstimateWgt", "\345\215\241\346\261\240\347\261\273\345\236\213\357\274\232", nullptr));
        label_distanceToBigGuarantee->setText(QApplication::translate("CardPoolEstimateWgt", "\350\267\235\347\246\273\345\244\247\344\277\235\345\272\225\345\211\251\344\275\231\346\212\275\346\225\260\357\274\232", nullptr));
        label_PorbGetUpAtsmallGuarantee->setText(QApplication::translate("CardPoolEstimateWgt", "\344\272\216\345\260\217\344\277\235\345\272\225\344\275\215\347\275\256\345\207\272\350\264\247\346\246\202\347\216\207\357\274\232", nullptr));
        label_PorbGetUpAtBigGuarantee->setText(QApplication::translate("CardPoolEstimateWgt", "\344\272\216\345\244\247\344\277\235\345\272\225\344\275\215\347\275\256\345\207\272\350\264\247\346\246\202\347\216\207", nullptr));
        label_ExpectationGetPos->setText(QApplication::translate("CardPoolEstimateWgt", "\346\234\237\346\234\233\345\207\272\350\264\247\344\275\215\347\275\256\357\274\232", nullptr));
        label_ExpectationCrystalExpense->setText(QApplication::translate("CardPoolEstimateWgt", "\346\234\237\346\234\233\346\212\225\345\205\245\346\230\237\347\220\274\357\274\232", nullptr));
        pushButton_clearResult->setText(QApplication::translate("CardPoolEstimateWgt", "\346\270\205\347\220\206\347\273\223\346\236\234", nullptr));
        groupBox_4->setTitle(QApplication::translate("CardPoolEstimateWgt", "\345\244\207\346\263\250", nullptr));
        label_8->setText(QApplication::translate("CardPoolEstimateWgt", "1.\350\247\222\350\211\262\346\261\240\344\272\224\346\230\237\345\237\272\347\241\200\346\246\202\347\216\2070.6%\357\274\214\345\205\211\351\224\245\346\261\240\344\272\224\346\230\237\345\237\272\347\241\200\346\246\202\347\216\2070.8%", nullptr));
        label_17->setText(QApplication::translate("CardPoolEstimateWgt", "2.\350\247\222\350\211\262\346\261\240\344\272\224\346\230\237\344\270\272UP\346\246\202\347\216\20750%\357\274\214\345\205\211\351\224\245\346\261\240\344\272\224\346\230\237\344\270\272UP\346\246\202\347\216\20775%", nullptr));
        label_9->setText(QApplication::translate("CardPoolEstimateWgt", "3.\350\247\222\350\211\262\346\261\240\345\260\217\344\277\235\345\272\22590\346\212\275\357\274\214\345\244\247\344\277\235\345\272\225180\346\212\275", nullptr));
        label_10->setText(QApplication::translate("CardPoolEstimateWgt", "4.\345\205\211\351\224\245\346\261\240\345\260\217\344\277\235\345\272\22580\346\212\275\357\274\214\345\244\247\344\277\235\345\272\225160\346\212\275", nullptr));
        label_6->setText(QApplication::translate("CardPoolEstimateWgt", "5.\350\247\222\350\211\262\346\261\240\345\246\202\346\236\234\345\211\21589\346\212\275\346\234\252\345\207\272\344\272\224\346\230\237\357\274\214\345\210\231\347\254\25490\346\212\275\345\277\205\345\207\272\344\272\224\346\230\237", nullptr));
        label_11->setText(QApplication::translate("CardPoolEstimateWgt", "6.\345\205\211\351\224\245\346\261\240\345\246\202\346\236\234\345\211\21579\346\212\275\346\234\252\345\207\272\344\272\224\346\230\237\357\274\214\345\210\231\347\254\25480\346\212\275\345\277\205\345\207\272\344\272\224\346\230\237", nullptr));
        label_7->setText(QApplication::translate("CardPoolEstimateWgt", "7.\345\246\202\346\236\234\344\270\212\344\270\200\344\270\252\344\272\224\346\230\237\344\270\215\346\230\257UP\357\274\214\345\210\231\344\270\213\344\270\200\344\270\252\344\272\224\346\230\237\345\277\205\345\207\272UP", nullptr));
        label_18->setText(QApplication::translate("CardPoolEstimateWgt", "8.\346\250\241\346\213\237\346\254\241\346\225\260\357\274\23210\344\270\207\346\254\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardPoolEstimateWgt: public Ui_CardPoolEstimateWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDPOOLESTIMATEWGT_H
