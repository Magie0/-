/********************************************************************************
** Form generated from reading UI file 'changepassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDDIALOG_H
#define UI_CHANGEPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_changePasswordDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *nameLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *newpassword;
    QLabel *label_3;
    QLineEdit *newpassword2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancleButton;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *changePasswordDialog)
    {
        if (changePasswordDialog->objectName().isEmpty())
            changePasswordDialog->setObjectName(QStringLiteral("changePasswordDialog"));
        changePasswordDialog->resize(801, 443);
        gridLayout = new QGridLayout(changePasswordDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        nameLabel = new QLabel(changePasswordDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setLayoutDirection(Qt::LeftToRight);
        nameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameLabel, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(240, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(changePasswordDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        newpassword = new QLineEdit(changePasswordDialog);
        newpassword->setObjectName(QStringLiteral("newpassword"));

        formLayout->setWidget(0, QFormLayout::FieldRole, newpassword);

        label_3 = new QLabel(changePasswordDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        newpassword2 = new QLineEdit(changePasswordDialog);
        newpassword2->setObjectName(QStringLiteral("newpassword2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, newpassword2);


        gridLayout->addLayout(formLayout, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(239, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 67, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(changePasswordDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancleButton = new QPushButton(changePasswordDialog);
        cancleButton->setObjectName(QStringLiteral("cancleButton"));

        horizontalLayout->addWidget(cancleButton);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 1, 1, 1);


        retranslateUi(changePasswordDialog);

        QMetaObject::connectSlotsByName(changePasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *changePasswordDialog)
    {
        changePasswordDialog->setWindowTitle(QApplication::translate("changePasswordDialog", "Dialog", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("changePasswordDialog", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("changePasswordDialog", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("changePasswordDialog", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        okButton->setText(QApplication::translate("changePasswordDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancleButton->setText(QApplication::translate("changePasswordDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class changePasswordDialog: public Ui_changePasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDDIALOG_H
