#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginDialog.h"
#include "registerdialog.h"
#include "account.h"
#include "changepassworddialog.h"
#include "addgoodsdialog.h"
#include "searchgoodsdialog.h"
#include "manageaccountdialog.h"
#include "managegoodsdialog.h"
#include "discountdialog.h"
extern bool isLogged;
extern buyer* buyerPtr;
extern store* storePtr;
extern int ID;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDB();
    createTable();
    queryTable();
    ui->discountButton->hide();
    ui->passwordButton->hide();
    ui->managebalanceButton->hide();
    ui->addgoodsButton->hide();
    ui->managegoodsButton->hide();
    ui->cancelloginButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDB()
{
    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Goods.db");
    //打开数据库
    if(db.open()==true)
        qDebug() << "打开成功";

}

void MainWindow::createTable()
{
    QSqlQuery query;
    QString str = QString("CREATE TABLE Goods ("
                          "id INT PRIMARY KEY NOT NULL,"
                          "type TEXT NOT NULL,"
                          "name TEXT NOT NULL,"
                          "price REAL NOT NULL,"
                          "surplus INT NOT NULL,"
                          "storename TEXT NOT NULL,"
                          "discount REAL NOT NULL,"
                          "describe TEXT)");
     if(query.exec(str) == true)
         qDebug() << "TableOK";
     else
         qDebug() << "cao";
}

void MainWindow::queryTable()
{
    // 构造一个查询数据表的sql语句
        QString str ("SELECT * FROM Goods");
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        ui->tableView->setModel (&model);
}

void MainWindow::on_discountButton_clicked()
{
    discountDialog d;
    d.exec();
}

void MainWindow::on_loginButton_clicked()
{
    loginDialog l;
    l.exec();
    if(isLogged&&ID==0)
    {
        ui->userLabel->setText(buyerPtr->getUsername());
        ui->passwordButton->setHidden(false);
        ui->managebalanceButton->setHidden(false);
        ui->cancelloginButton->setHidden(false);
        ui->loginButton->hide();
        ui->registerButton->hide();
    }
    if(isLogged&&ID==1)
    {
        ui->userLabel->setText(storePtr->getUsername());
        ui->passwordButton->setHidden(false);
        ui->managebalanceButton->setHidden(false);
        ui->cancelloginButton->setHidden(false);
        ui->addgoodsButton->setHidden(false);
        ui->managegoodsButton->setHidden(false);
        ui->loginButton->hide();
        ui->registerButton->hide();
        if(storePtr->getUsername()=="陆泽意")
            ui->discountButton->setHidden(false);
    }
}

void MainWindow::on_registerButton_clicked()
{
    registerDialog r;
    r.exec();
}

void MainWindow::on_passwordButton_clicked()
{
    changePasswordDialog c;
    c.exec();
}

void MainWindow::on_managebalanceButton_clicked()
{
    manageAccountDialog m;
    m.exec();
}

void MainWindow::on_searchButton_clicked()
{
    searchgoodsDialog s;
    s.exec();
}

void MainWindow::on_addgoodsButton_clicked()
{
    addgoodsDialog a;
    a.exec();
}

void MainWindow::on_managegoodsButton_clicked()
{
    managegoodsDialog m;
    m.exec();
}

void MainWindow::on_cancelloginButton_clicked()
{
    ID = 0;
    isLogged = 0;
    ui->loginButton->setHidden(false);
    ui->registerButton->setHidden(false);
    ui->userLabel->setText("请先登录");
    ui->discountButton->hide();
    ui->passwordButton->hide();
    ui->managebalanceButton->hide();
    ui->addgoodsButton->hide();
    ui->managegoodsButton->hide();
    ui->cancelloginButton->hide();
}

void MainWindow::on_freshButton_clicked()
{
    queryTable();
}
