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
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_shoppingcart
{
public:
    QTableView *tableView;

    void setupUi(QDialog *shoppingcart)
    {
        if (shoppingcart->objectName().isEmpty())
            shoppingcart->setObjectName(QStringLiteral("shoppingcart"));
        shoppingcart->resize(841, 609);
        tableView = new QTableView(shoppingcart);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 40, 671, 491));

        retranslateUi(shoppingcart);

        QMetaObject::connectSlotsByName(shoppingcart);
    } // setupUi

    void retranslateUi(QDialog *shoppingcart)
    {
        shoppingcart->setWindowTitle(QApplication::translate("shoppingcart", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class shoppingcart: public Ui_shoppingcart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
