/********************************************************************************
** Form generated from reading UI file 'managegoodsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEGOODSDIALOG_H
#define UI_MANAGEGOODSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_managegoodsDialog
{
public:
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *priceEdit;
    QLineEdit *numEdit;
    QPushButton *priceokButton;
    QPushButton *numokButton;
    QComboBox *comboBox;
    QLineEdit *goodsEdit;
    QPushButton *searchButton;
    QLabel *nameLabel;
    QPushButton *cancelButton;

    void setupUi(QDialog *managegoodsDialog)
    {
        if (managegoodsDialog->objectName().isEmpty())
            managegoodsDialog->setObjectName(QStringLiteral("managegoodsDialog"));
        managegoodsDialog->resize(688, 585);
        tableView = new QTableView(managegoodsDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(25, 101, 611, 271));
        label = new QLabel(managegoodsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 40, 81, 18));
        label_2 = new QLabel(managegoodsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 460, 121, 31));
        label_3 = new QLabel(managegoodsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 520, 111, 31));
        priceEdit = new QLineEdit(managegoodsDialog);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));
        priceEdit->setGeometry(QRect(240, 460, 113, 25));
        numEdit = new QLineEdit(managegoodsDialog);
        numEdit->setObjectName(QStringLiteral("numEdit"));
        numEdit->setGeometry(QRect(240, 520, 113, 25));
        priceokButton = new QPushButton(managegoodsDialog);
        priceokButton->setObjectName(QStringLiteral("priceokButton"));
        priceokButton->setEnabled(false);
        priceokButton->setGeometry(QRect(420, 460, 99, 28));
        numokButton = new QPushButton(managegoodsDialog);
        numokButton->setObjectName(QStringLiteral("numokButton"));
        numokButton->setEnabled(false);
        numokButton->setGeometry(QRect(420, 520, 99, 28));
        comboBox = new QComboBox(managegoodsDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 400, 94, 24));
        goodsEdit = new QLineEdit(managegoodsDialog);
        goodsEdit->setObjectName(QStringLiteral("goodsEdit"));
        goodsEdit->setGeometry(QRect(240, 400, 113, 25));
        searchButton = new QPushButton(managegoodsDialog);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setEnabled(false);
        searchButton->setGeometry(QRect(420, 400, 99, 28));
        nameLabel = new QLabel(managegoodsDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(300, 40, 81, 18));
        cancelButton = new QPushButton(managegoodsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(570, 520, 99, 28));

        retranslateUi(managegoodsDialog);

        QMetaObject::connectSlotsByName(managegoodsDialog);
    } // setupUi

    void retranslateUi(QDialog *managegoodsDialog)
    {
        managegoodsDialog->setWindowTitle(QApplication::translate("managegoodsDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("managegoodsDialog", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("managegoodsDialog", "\344\277\256\346\224\271\344\273\267\346\240\274\344\270\272:", Q_NULLPTR));
        label_3->setText(QApplication::translate("managegoodsDialog", "\344\277\256\346\224\271\346\225\260\351\207\217\344\270\272:", Q_NULLPTR));
        priceokButton->setText(QApplication::translate("managegoodsDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        numokButton->setText(QApplication::translate("managegoodsDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("managegoodsDialog", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
         << QApplication::translate("managegoodsDialog", "id", Q_NULLPTR)
         << QApplication::translate("managegoodsDialog", "type", Q_NULLPTR)
         << QApplication::translate("managegoodsDialog", "name", Q_NULLPTR)
        );
        searchButton->setText(QApplication::translate("managegoodsDialog", "\346\237\245\346\211\276", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("managegoodsDialog", "TextLabel", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("managegoodsDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class managegoodsDialog: public Ui_managegoodsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEGOODSDIALOG_H
