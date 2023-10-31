/********************************************************************************
** Form generated from reading UI file 'StarRailMainFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARRAILMAINFRAME_H
#define UI_STARRAILMAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StarRainMainFrame
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *StarRainMainFrame)
    {
        if (StarRainMainFrame->objectName().isEmpty())
            StarRainMainFrame->setObjectName(QString::fromUtf8("StarRainMainFrame"));
        StarRainMainFrame->resize(1280, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StarRainMainFrame->sizePolicy().hasHeightForWidth());
        StarRainMainFrame->setSizePolicy(sizePolicy);
        StarRainMainFrame->setMinimumSize(QSize(0, 0));
        StarRainMainFrame->setMaximumSize(QSize(9999, 9999));
        verticalLayout = new QVBoxLayout(StarRainMainFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(StarRainMainFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(tabWidget);


        retranslateUi(StarRainMainFrame);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(StarRainMainFrame);
    } // setupUi

    void retranslateUi(QWidget *StarRainMainFrame)
    {
        StarRainMainFrame->setWindowTitle(QApplication::translate("StarRainMainFrame", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StarRainMainFrame: public Ui_StarRainMainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARRAILMAINFRAME_H
