/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLabel *label;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *label_2;
    QLabel *userLabel;
    QPushButton *passwordButton;
    QPushButton *discountButton;
    QPushButton *searchButton;
    QPushButton *managegoodsButton;
    QPushButton *managebalanceButton;
    QPushButton *addgoodsButton;
    QPushButton *cancelloginButton;
    QPushButton *freshButton;
    QPushButton *addtocartButton;
    QPushButton *cartButton;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1091, 698);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 120, 901, 481));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 30, 221, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(780, 20, 99, 28));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(910, 20, 99, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 20, 81, 21));
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(180, 20, 81, 18));
        passwordButton = new QPushButton(centralwidget);
        passwordButton->setObjectName(QStringLiteral("passwordButton"));
        passwordButton->setGeometry(QRect(110, 70, 99, 28));
        passwordButton->setInputMethodHints(Qt::ImhNone);
        discountButton = new QPushButton(centralwidget);
        discountButton->setObjectName(QStringLiteral("discountButton"));
        discountButton->setGeometry(QRect(300, 20, 99, 28));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(30, 620, 99, 28));
        managegoodsButton = new QPushButton(centralwidget);
        managegoodsButton->setObjectName(QStringLiteral("managegoodsButton"));
        managegoodsButton->setGeometry(QRect(940, 620, 99, 28));
        managebalanceButton = new QPushButton(centralwidget);
        managebalanceButton->setObjectName(QStringLiteral("managebalanceButton"));
        managebalanceButton->setGeometry(QRect(220, 70, 99, 28));
        addgoodsButton = new QPushButton(centralwidget);
        addgoodsButton->setObjectName(QStringLiteral("addgoodsButton"));
        addgoodsButton->setGeometry(QRect(830, 620, 99, 28));
        cancelloginButton = new QPushButton(centralwidget);
        cancelloginButton->setObjectName(QStringLiteral("cancelloginButton"));
        cancelloginButton->setGeometry(QRect(780, 70, 99, 28));
        freshButton = new QPushButton(centralwidget);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        freshButton->setGeometry(QRect(910, 70, 99, 28));
        addtocartButton = new QPushButton(centralwidget);
        addtocartButton->setObjectName(QStringLiteral("addtocartButton"));
        addtocartButton->setEnabled(true);
        addtocartButton->setGeometry(QRect(920, 170, 121, 31));
        cartButton = new QPushButton(centralwidget);
        cartButton->setObjectName(QStringLiteral("cartButton"));
        cartButton->setGeometry(QRect(920, 320, 99, 28));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(1020, 330, 20, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1091, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\224\265\345\225\206\344\272\244\346\230\223\345\271\263\345\217\260", Q_NULLPTR));
        loginButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        registerButton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        userLabel->setText(QApplication::translate("MainWindow", "\350\257\267\345\205\210\347\231\273\345\275\225", Q_NULLPTR));
        passwordButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        discountButton->setText(QApplication::translate("MainWindow", "\346\211\223\346\212\230", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        managegoodsButton->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\347\256\241\347\220\206", Q_NULLPTR));
        managebalanceButton->setText(QApplication::translate("MainWindow", "\344\275\231\351\242\235\347\256\241\347\220\206", Q_NULLPTR));
        addgoodsButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\225\206\345\223\201", Q_NULLPTR));
        cancelloginButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        freshButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", Q_NULLPTR));
        addtocartButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\207\263\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        cartButton->setText(QApplication::translate("MainWindow", "\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
