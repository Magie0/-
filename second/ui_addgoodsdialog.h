/********************************************************************************
** Form generated from reading UI file 'addgoodsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGOODSDIALOG_H
#define UI_ADDGOODSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addgoodsDialog
{
public:
    QPushButton *addButton;
    QPushButton *cancleButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *goodsname;
    QLabel *label_5;
    QLineEdit *goodstype;
    QLabel *label_2;
    QLineEdit *goodsprice;
    QLabel *label_3;
    QLineEdit *goodsnum;
    QLabel *label_4;
    QLineEdit *goodsdescribe;

    void setupUi(QDialog *addgoodsDialog)
    {
        if (addgoodsDialog->objectName().isEmpty())
            addgoodsDialog->setObjectName(QStringLiteral("addgoodsDialog"));
        addgoodsDialog->resize(715, 499);
        addButton = new QPushButton(addgoodsDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(200, 420, 99, 28));
        cancleButton = new QPushButton(addgoodsDialog);
        cancleButton->setObjectName(QStringLiteral("cancleButton"));
        cancleButton->setGeometry(QRect(420, 420, 99, 28));
        widget = new QWidget(addgoodsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(141, 61, 345, 191));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        goodsname = new QLineEdit(widget);
        goodsname->setObjectName(QStringLiteral("goodsname"));

        gridLayout->addWidget(goodsname, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        goodstype = new QLineEdit(widget);
        goodstype->setObjectName(QStringLiteral("goodstype"));

        gridLayout->addWidget(goodstype, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        goodsprice = new QLineEdit(widget);
        goodsprice->setObjectName(QStringLiteral("goodsprice"));

        gridLayout->addWidget(goodsprice, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        goodsnum = new QLineEdit(widget);
        goodsnum->setObjectName(QStringLiteral("goodsnum"));

        gridLayout->addWidget(goodsnum, 3, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        goodsdescribe = new QLineEdit(widget);
        goodsdescribe->setObjectName(QStringLiteral("goodsdescribe"));

        gridLayout->addWidget(goodsdescribe, 4, 1, 1, 1);


        retranslateUi(addgoodsDialog);

        QMetaObject::connectSlotsByName(addgoodsDialog);
    } // setupUi

    void retranslateUi(QDialog *addgoodsDialog)
    {
        addgoodsDialog->setWindowTitle(QApplication::translate("addgoodsDialog", "Dialog", Q_NULLPTR));
        addButton->setText(QApplication::translate("addgoodsDialog", "\346\267\273\345\212\240", Q_NULLPTR));
        cancleButton->setText(QApplication::translate("addgoodsDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("addgoodsDialog", "\345\225\206\345\223\201\345\220\215:", Q_NULLPTR));
        label_5->setText(QApplication::translate("addgoodsDialog", "\345\225\206\345\223\201\347\261\273\345\236\213:", Q_NULLPTR));
        label_2->setText(QApplication::translate("addgoodsDialog", "\344\273\267\346\240\274:", Q_NULLPTR));
        label_3->setText(QApplication::translate("addgoodsDialog", "\346\225\260\351\207\217:", Q_NULLPTR));
        label_4->setText(QApplication::translate("addgoodsDialog", "\345\225\206\345\223\201\346\217\217\350\277\260:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addgoodsDialog: public Ui_addgoodsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGOODSDIALOG_H
