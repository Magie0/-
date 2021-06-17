/********************************************************************************
** Form generated from reading UI file 'manageaccountdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEACCOUNTDIALOG_H
#define UI_MANAGEACCOUNTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_manageAccountDialog
{
public:
    QLabel *label;
    QLabel *balanceLabel;
    QPushButton *investButton;
    QPushButton *consumeButton;
    QLabel *label_3;
    QLabel *nameLabel;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *investNum;
    QLineEdit *consumeNum;
    QPushButton *pushButton;

    void setupUi(QDialog *manageAccountDialog)
    {
        if (manageAccountDialog->objectName().isEmpty())
            manageAccountDialog->setObjectName(QStringLiteral("manageAccountDialog"));
        manageAccountDialog->resize(725, 479);
        label = new QLabel(manageAccountDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 100, 111, 21));
        balanceLabel = new QLabel(manageAccountDialog);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setGeometry(QRect(350, 100, 81, 18));
        investButton = new QPushButton(manageAccountDialog);
        investButton->setObjectName(QStringLiteral("investButton"));
        investButton->setEnabled(false);
        investButton->setGeometry(QRect(150, 320, 99, 28));
        consumeButton = new QPushButton(manageAccountDialog);
        consumeButton->setObjectName(QStringLiteral("consumeButton"));
        consumeButton->setEnabled(false);
        consumeButton->setGeometry(QRect(460, 320, 99, 28));
        label_3 = new QLabel(manageAccountDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 30, 81, 18));
        nameLabel = new QLabel(manageAccountDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(310, 30, 81, 18));
        label_2 = new QLabel(manageAccountDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 220, 141, 41));
        label_4 = new QLabel(manageAccountDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 220, 141, 41));
        investNum = new QLineEdit(manageAccountDialog);
        investNum->setObjectName(QStringLiteral("investNum"));
        investNum->setGeometry(QRect(180, 230, 113, 25));
        consumeNum = new QLineEdit(manageAccountDialog);
        consumeNum->setObjectName(QStringLiteral("consumeNum"));
        consumeNum->setGeometry(QRect(500, 230, 113, 25));
        pushButton = new QPushButton(manageAccountDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 420, 99, 28));

        retranslateUi(manageAccountDialog);

        QMetaObject::connectSlotsByName(manageAccountDialog);
    } // setupUi

    void retranslateUi(QDialog *manageAccountDialog)
    {
        manageAccountDialog->setWindowTitle(QApplication::translate("manageAccountDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("manageAccountDialog", "\346\202\250\347\232\204\344\275\231\351\242\235\344\270\272\357\274\232", Q_NULLPTR));
        balanceLabel->setText(QApplication::translate("manageAccountDialog", "TextLabel", Q_NULLPTR));
        investButton->setText(QApplication::translate("manageAccountDialog", "\345\205\205\345\200\274", Q_NULLPTR));
        consumeButton->setText(QApplication::translate("manageAccountDialog", "\346\266\210\350\264\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("manageAccountDialog", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("manageAccountDialog", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("manageAccountDialog", "\346\202\250\347\232\204\345\205\205\345\200\274\351\207\221\351\242\235\344\270\272:", Q_NULLPTR));
        label_4->setText(QApplication::translate("manageAccountDialog", "\346\202\250\347\232\204\346\266\210\350\264\271\351\207\221\351\242\235\344\270\272:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("manageAccountDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class manageAccountDialog: public Ui_manageAccountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEACCOUNTDIALOG_H
