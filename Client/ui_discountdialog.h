/********************************************************************************
** Form generated from reading UI file 'discountdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCOUNTDIALOG_H
#define UI_DISCOUNTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_discountDialog
{
public:
    QLabel *label;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *discountEdit;
    QLabel *label_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *typeEdit;

    void setupUi(QDialog *discountDialog)
    {
        if (discountDialog->objectName().isEmpty())
            discountDialog->setObjectName(QStringLiteral("discountDialog"));
        discountDialog->resize(603, 450);
        label = new QLabel(discountDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 50, 201, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        okButton = new QPushButton(discountDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(130, 270, 99, 28));
        cancelButton = new QPushButton(discountDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(290, 270, 99, 28));
        widget = new QWidget(discountDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 160, 319, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        discountEdit = new QLineEdit(widget);
        discountEdit->setObjectName(QStringLiteral("discountEdit"));

        horizontalLayout->addWidget(discountEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        widget1 = new QWidget(discountDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(100, 110, 295, 27));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        typeEdit = new QLineEdit(widget1);
        typeEdit->setObjectName(QStringLiteral("typeEdit"));

        horizontalLayout_2->addWidget(typeEdit);


        retranslateUi(discountDialog);

        QMetaObject::connectSlotsByName(discountDialog);
    } // setupUi

    void retranslateUi(QDialog *discountDialog)
    {
        discountDialog->setWindowTitle(QApplication::translate("discountDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("discountDialog", "\347\256\241\347\220\206\345\221\230,\344\275\240\345\245\275", Q_NULLPTR));
        okButton->setText(QApplication::translate("discountDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("discountDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("discountDialog", "\350\257\267\350\276\223\345\205\245\346\212\230\346\211\243:", Q_NULLPTR));
        label_3->setText(QApplication::translate("discountDialog", "\346\212\230", Q_NULLPTR));
        label_4->setText(QApplication::translate("discountDialog", "\350\257\267\350\276\223\345\205\245\347\261\273\345\236\213:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class discountDialog: public Ui_discountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCOUNTDIALOG_H
