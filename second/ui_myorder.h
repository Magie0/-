/********************************************************************************
** Form generated from reading UI file 'myorder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYORDER_H
#define UI_MYORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_myorder
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *myorder)
    {
        if (myorder->objectName().isEmpty())
            myorder->setObjectName(QStringLiteral("myorder"));
        myorder->resize(989, 757);
        tableWidget = new QTableWidget(myorder);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 10, 981, 741));

        retranslateUi(myorder);

        QMetaObject::connectSlotsByName(myorder);
    } // setupUi

    void retranslateUi(QDialog *myorder)
    {
        myorder->setWindowTitle(QApplication::translate("myorder", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class myorder: public Ui_myorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYORDER_H
