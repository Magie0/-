/********************************************************************************
** Form generated from reading UI file 'searchgoodsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHGOODSDIALOG_H
#define UI_SEARCHGOODSDIALOG_H

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

class Ui_searchgoodsDialog
{
public:
    QComboBox *valuecomboBox;
    QComboBox *conditioncomboBox;
    QPushButton *searchButton;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QPushButton *sortButton;
    QComboBox *searchcomboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *cancelButton;
    QPushButton *addtocartButton;

    void setupUi(QDialog *searchgoodsDialog)
    {
        if (searchgoodsDialog->objectName().isEmpty())
            searchgoodsDialog->setObjectName(QStringLiteral("searchgoodsDialog"));
        searchgoodsDialog->resize(897, 613);
        valuecomboBox = new QComboBox(searchgoodsDialog);
        valuecomboBox->setObjectName(QStringLiteral("valuecomboBox"));
        valuecomboBox->setGeometry(QRect(90, 0, 151, 51));
        QFont font;
        font.setPointSize(18);
        valuecomboBox->setFont(font);
        conditioncomboBox = new QComboBox(searchgoodsDialog);
        conditioncomboBox->setObjectName(QStringLiteral("conditioncomboBox"));
        conditioncomboBox->setGeometry(QRect(290, 0, 161, 51));
        conditioncomboBox->setFont(font);
        searchButton = new QPushButton(searchgoodsDialog);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setEnabled(false);
        searchButton->setGeometry(QRect(580, 470, 101, 31));
        tableView = new QTableView(searchgoodsDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 70, 861, 341));
        label = new QLabel(searchgoodsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 430, 81, 18));
        label_2 = new QLabel(searchgoodsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 430, 81, 18));
        sortButton = new QPushButton(searchgoodsDialog);
        sortButton->setObjectName(QStringLiteral("sortButton"));
        sortButton->setGeometry(QRect(580, 0, 151, 51));
        searchcomboBox = new QComboBox(searchgoodsDialog);
        searchcomboBox->setObjectName(QStringLiteral("searchcomboBox"));
        searchcomboBox->setGeometry(QRect(130, 460, 151, 51));
        lineEdit = new QLineEdit(searchgoodsDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(300, 470, 113, 25));
        lineEdit_2 = new QLineEdit(searchgoodsDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(430, 470, 113, 25));
        cancelButton = new QPushButton(searchgoodsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(580, 530, 99, 28));
        addtocartButton = new QPushButton(searchgoodsDialog);
        addtocartButton->setObjectName(QStringLiteral("addtocartButton"));
        addtocartButton->setGeometry(QRect(730, 470, 93, 28));

        retranslateUi(searchgoodsDialog);

        QMetaObject::connectSlotsByName(searchgoodsDialog);
    } // setupUi

    void retranslateUi(QDialog *searchgoodsDialog)
    {
        searchgoodsDialog->setWindowTitle(QApplication::translate("searchgoodsDialog", "Dialog", Q_NULLPTR));
        valuecomboBox->clear();
        valuecomboBox->insertItems(0, QStringList()
         << QApplication::translate("searchgoodsDialog", "id", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "name", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "price", Q_NULLPTR)
        );
        conditioncomboBox->clear();
        conditioncomboBox->insertItems(0, QStringList()
         << QApplication::translate("searchgoodsDialog", "\345\215\207\345\272\217", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "\351\231\215\345\272\217", Q_NULLPTR)
        );
        searchButton->setText(QApplication::translate("searchgoodsDialog", "\347\255\233\351\200\211", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        sortButton->setText(QApplication::translate("searchgoodsDialog", "\346\211\200\346\234\211\345\225\206\345\223\201\346\216\222\345\272\217", Q_NULLPTR));
        searchcomboBox->clear();
        searchcomboBox->insertItems(0, QStringList()
         << QApplication::translate("searchgoodsDialog", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "name", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "type", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "storename", Q_NULLPTR)
         << QApplication::translate("searchgoodsDialog", "price", Q_NULLPTR)
        );
        cancelButton->setText(QApplication::translate("searchgoodsDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        addtocartButton->setText(QApplication::translate("searchgoodsDialog", "\346\267\273\345\212\240\350\207\263\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchgoodsDialog: public Ui_searchgoodsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHGOODSDIALOG_H
