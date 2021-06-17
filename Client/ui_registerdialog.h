/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *new_password2;
    QCheckBox *storeBox;
    QLineEdit *new_password;
    QLineEdit *new_username;
    QLabel *label_2;
    QCheckBox *userBox;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *registerButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *registerDialog)
    {
        if (registerDialog->objectName().isEmpty())
            registerDialog->setObjectName(QStringLiteral("registerDialog"));
        registerDialog->resize(875, 601);
        registerDialog->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(registerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(registerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(43, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(registerDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 4, 1, 1);

        label_4 = new QLabel(registerDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 4, 1, 1);

        new_password2 = new QLineEdit(registerDialog);
        new_password2->setObjectName(QStringLiteral("new_password2"));
        new_password2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(new_password2, 3, 1, 1, 2);

        storeBox = new QCheckBox(registerDialog);
        storeBox->setObjectName(QStringLiteral("storeBox"));

        gridLayout->addWidget(storeBox, 4, 1, 1, 1);

        new_password = new QLineEdit(registerDialog);
        new_password->setObjectName(QStringLiteral("new_password"));
        new_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(new_password, 2, 1, 1, 2);

        new_username = new QLineEdit(registerDialog);
        new_username->setObjectName(QStringLiteral("new_username"));

        gridLayout->addWidget(new_username, 0, 1, 1, 2);

        label_2 = new QLabel(registerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 4, 1, 1);

        userBox = new QCheckBox(registerDialog);
        userBox->setObjectName(QStringLiteral("userBox"));

        gridLayout->addWidget(userBox, 4, 2, 1, 1);

        label_3 = new QLabel(registerDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 4, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        registerButton = new QPushButton(registerDialog);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setEnabled(false);

        horizontalLayout->addWidget(registerButton);

        cancelButton = new QPushButton(registerDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(registerDialog);

        QMetaObject::connectSlotsByName(registerDialog);
    } // setupUi

    void retranslateUi(QDialog *registerDialog)
    {
        registerDialog->setWindowTitle(QApplication::translate("registerDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("registerDialog", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        label_5->setText(QApplication::translate("registerDialog", "\351\200\211\346\213\251\350\264\246\346\210\267\347\261\273\345\236\213", Q_NULLPTR));
        label_4->setText(QApplication::translate("registerDialog", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        storeBox->setText(QApplication::translate("registerDialog", "\345\225\206\345\256\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("registerDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        userBox->setText(QApplication::translate("registerDialog", "\347\224\250\346\210\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("registerDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        registerButton->setText(QApplication::translate("registerDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("registerDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
