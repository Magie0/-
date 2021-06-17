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
#include "shoppingcart.h"
#include "goods.h"
#include<QSqlRecord>


using namespace std;
extern bool isLogged;
extern buyer* buyerPtr;
extern store* storePtr;
extern int ID;
extern vector<books> cartbooks;
extern vector<dress> cartdress;
extern vector<food> cartfood;
int count1 = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    createDB();
    createTable();
    queryTable();
    */
    //修改
    mSocket = new QUdpSocket();
    mSocket->bind(10001,QAbstractSocket::DontShareAddress);
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    QString MyData="展示商品";
    mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
    //
    ui->tableWidget->setRowCount(20);    //设置行
    ui->tableWidget->setColumnCount(8); //设置列
    //设置表头内容
    QStringList header;
    header<<tr("id")<<tr("type")<<tr("name")<<tr("price")<<tr("surplus")<<tr("storename")<<tr("discount")<<tr("discribe");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->discountButton->hide();
    ui->passwordButton->hide();
    ui->managebalanceButton->hide();
    ui->addgoodsButton->hide();
    ui->managegoodsButton->hide();
    ui->cancelloginButton->hide();
    ui->addtocartButton->hide();
    ui->cartButton->hide();
    ui->tableWidget->hide();
    queryTable();
}

void MainWindow::readData()
{
    while (mSocket->hasPendingDatagrams())
    {
        QByteArray MyDate;//因为传送来的数据类型是未知，所以用bytearray
        MyDate.resize(mSocket->pendingDatagramSize());//mydata的数据大小取决于接收到的数据
        mSocket->readDatagram(MyDate.data(),MyDate.size());//读取数据

        QString str = QString::fromUtf8(MyDate);
        qDebug() <<"来自Server的报文："<< str;
        string Str = str.toStdString();
        QString id,name,type,price,surplus,storename,discount,discribe;
        int i = 0;
        while(str[i]!='#')
        {
            id = id + str[i];
            i++;
        }
        i++;
        while(str[i]!='#')
        {
            name = name + str[i];
            i++;
        }
        i++;
        while(str[i]!='#')
        {
            type = type + str[i];
            i++;
        }
        i++;
        while(str[i]!='#')
        {
            price = price + str[i];
            i++;
        }
        i++;
        while(str[i]!='#')
        {
            surplus = surplus + str[i];
            i++;
        }
        i++;
        while(str[i]!='#')
        {
            storename = storename + str[i];
            i++;
        }
        i++;
        while(str[i]!='#')
        {
            discount = discount + str[i];
            i++;
        }
        i++;
        while(i<str.size())
        {
            discribe = discribe + str[i];
            i++;
        }
        ui->tableWidget->setItem(count1,0,new QTableWidgetItem(id));
        ui->tableWidget->setItem(count1,1,new QTableWidgetItem(type));
        ui->tableWidget->setItem(count1,2,new QTableWidgetItem(name));
        ui->tableWidget->setItem(count1,3,new QTableWidgetItem(price));
        ui->tableWidget->setItem(count1,4,new QTableWidgetItem(surplus));
        ui->tableWidget->setItem(count1,5,new QTableWidgetItem(storename));
        ui->tableWidget->setItem(count1,6,new QTableWidgetItem(discount));
        ui->tableWidget->setItem(count1,7,new QTableWidgetItem(discribe));
        count1++;
    }
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
}

void MainWindow::queryTable()
{
    // 构造一个查询数据表的sql语句
        QString str ("SELECT * FROM Goods");
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        ui->tableView->verticalHeader()->hide(); // hide row number
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
        ui->addtocartButton->setHidden(false);
        ui->cartButton->setHidden(false);
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

void MainWindow::on_addtocartButton_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
        //获取选中的行
    qDebug() << curRow;
    int ok = QMessageBox::information(this,tr("添加至购物车"),tr("你确定"
                                                               "将此商品添加至购物车吗？"),
             QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        if(model.record(curRow).value("type")=="books")
        {
            class books Book;
            Book.setID(model.record(curRow).value("id").toInt());
            for(int i=0;i<(int)cartbooks.size();i++)
            {
                if(Book.getID()==cartbooks[i].getID())
                {
                    QMessageBox msgBox(
                                QMessageBox::Critical,//图标
                                "Error",//标题
                                "已有此商品，请勿重复添加!",//提示消息
                                QMessageBox::Ok,//按钮
                                this);//父窗口
                    msgBox.exec();
                    return;
                }
            }
            Book.setName(model.record(curRow).value("name").toString());
            Book.setPrice(model.record(curRow).value("price").toDouble());
            Book.setSurplus(model.record(curRow).value("surplus").toInt());
            Book.setStorename(model.record(curRow).value("storename").toString());
            Book.setDiscount(model.record(curRow).value("discount").toDouble());
            Book.setBuynumber(1);
            cartbooks.push_back(Book);
        }
        else if(model.record(curRow).value("type")=="dress")
        {
            class dress Dress;
            Dress.setID(model.record(curRow).value("id").toInt());
            for(int i=0;i<(int)cartdress.size();i++)
            {
                if(Dress.getID()==cartdress[i].getID())
                {
                    QMessageBox msgBox(
                                QMessageBox::Critical,//图标
                                "Error",//标题
                                "已有此商品，请勿重复添加!",//提示消息
                                QMessageBox::Ok,//按钮
                                this);//父窗口
                    msgBox.exec();
                    return;
                }
            }
            Dress.setName(model.record(curRow).value("name").toString());
            Dress.setPrice(model.record(curRow).value("price").toDouble());
            Dress.setSurplus(model.record(curRow).value("surplus").toInt());
            Dress.setStorename(model.record(curRow).value("storename").toString());
            Dress.setDiscount(model.record(curRow).value("discount").toDouble());
            Dress.setBuynumber(1);
            cartdress.push_back(Dress);
        }
        else if(model.record(curRow).value("type")=="food")
        {
            class food Food;
            Food.setID(model.record(curRow).value("id").toInt());
            for(int i=0;i<(int)cartfood.size();i++)
            {
                if(Food.getID()==cartfood[i].getID())
                {
                    QMessageBox msgBox(
                                QMessageBox::Critical,//图标
                                "Error",//标题
                                "已有此商品，请勿重复添加!",//提示消息
                                QMessageBox::Ok,//按钮
                                this);//父窗口
                    msgBox.exec();
                    return;
                }
            }
            Food.setName(model.record(curRow).value("name").toString());
            Food.setPrice(model.record(curRow).value("price").toDouble());
            Food.setSurplus(model.record(curRow).value("surplus").toInt());
            Food.setStorename(model.record(curRow).value("storename").toString());
            Food.setDiscount(model.record(curRow).value("discount").toDouble());
            Food.setBuynumber(1);
            cartfood.push_back(Food);
        }
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "Yes",//标题
                    "添加成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
}

void MainWindow::on_cartButton_clicked()
{
    shoppingcart s;
    s.exec();
}
