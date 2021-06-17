/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_shoppingcart
{
public:
    QPushButton *cancelButton;
    QTableWidget *tableWidget;
    QPushButton *buyButton;
    QPushButton *orderButton;
    QPushButton *freshButton;

    void setupUi(QDialog *shoppingcart)
    {
        if (shoppingcart->objectName().isEmpty())
            shoppingcart->setObjectName(QStringLiteral("shoppingcart"));
        shoppingcart->resize(1022, 773);
        cancelButton = new QPushButton(shoppingcart);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(880, 700, 99, 28));
        tableWidget = new QTableWidget(shoppingcart);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 30, 831, 691));
        buyButton = new QPushButton(shoppingcart);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(880, 570, 99, 28));
        orderButton = new QPushButton(shoppingcart);
        orderButton->setObjectName(QStringLiteral("orderButton"));
        orderButton->setGeometry(QRect(890, 180, 99, 28));
        freshButton = new QPushButton(shoppingcart);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        freshButton->setGeometry(QRect(890, 60, 93, 28));

        retranslateUi(shoppingcart);

        QMetaObject::connectSlotsByName(shoppingcart);
    } // setupUi

    void retranslateUi(QDialog *shoppingcart)
    {
        shoppingcart->setWindowTitle(QApplication::translate("shoppingcart", "Dialog", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("shoppingcart", "\351\200\200\345\207\272", Q_NULLPTR));
        buyButton->setText(QApplication::translate("shoppingcart", "\350\264\255\344\271\260", Q_NULLPTR));
        orderButton->setText(QApplication::translate("shoppingcart", "\346\210\221\347\232\204\350\256\242\345\215\225", Q_NULLPTR));
        freshButton->setText(QApplication::translate("shoppingcart", "\345\210\267\346\226\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class shoppingcart: public Ui_shoppingcart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
