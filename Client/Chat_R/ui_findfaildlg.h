/********************************************************************************
** Form generated from reading UI file 'findfaildlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFAILDLG_H
#define UI_FINDFAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedbtn.h"

QT_BEGIN_NAMESPACE

class Ui_FindFailDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *fail_tip;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    ClickedBtn *fail_sure_btn;

    void setupUi(QDialog *FindFailDlg)
    {
        if (FindFailDlg->objectName().isEmpty())
            FindFailDlg->setObjectName("FindFailDlg");
        FindFailDlg->resize(260, 163);
        FindFailDlg->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(FindFailDlg);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        fail_tip = new QLabel(FindFailDlg);
        fail_tip->setObjectName("fail_tip");
        fail_tip->setMinimumSize(QSize(0, 25));
        fail_tip->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(fail_tip);

        label_2 = new QLabel(FindFailDlg);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(label_2);

        widget = new QWidget(FindFailDlg);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        fail_sure_btn = new ClickedBtn(widget);
        fail_sure_btn->setObjectName("fail_sure_btn");
        fail_sure_btn->setMinimumSize(QSize(100, 30));
        fail_sure_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(fail_sure_btn);


        verticalLayout->addWidget(widget);


        retranslateUi(FindFailDlg);

        QMetaObject::connectSlotsByName(FindFailDlg);
    } // setupUi

    void retranslateUi(QDialog *FindFailDlg)
    {
        FindFailDlg->setWindowTitle(QCoreApplication::translate("FindFailDlg", "Dialog", nullptr));
        fail_tip->setText(QCoreApplication::translate("FindFailDlg", "\346\227\240\346\263\225\346\211\276\345\210\260\350\257\245\347\224\250\346\210\267", nullptr));
        label_2->setText(QCoreApplication::translate("FindFailDlg", "\350\257\267\346\243\200\346\237\245\344\277\241\346\201\257\346\230\257\345\220\246\346\255\243\347\241\256", nullptr));
        fail_sure_btn->setText(QCoreApplication::translate("FindFailDlg", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindFailDlg: public Ui_FindFailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFAILDLG_H
