#include "myorder.h"
#include "ui_myorder.h"
#include "goods.h"
#include "account.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
using namespace std;

extern vector<vector<dress>> orderdress;
extern vector<vector<food>> orderfood;
extern vector<vector<books>> orderbooks;
extern buyer* buyerPtr;
extern store* storePtr;
extern int ID;
vector<int> ispayed;

myorder::myorder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myorder)
{
    ui->setupUi(this);
    initialize();
}

myorder::~myorder()
{
    delete ui;
}

void myorder::initialize()
{
    int ordersize = orderfood.size();
    ispayed.resize(ordersize);
    int row = ordersize;
    for(int i =0;i<ordersize;i++)
    {
        if(orderfood[i][0].getID()!=-1)
            row += orderfood[i].size();
        if(orderdress[i][0].getID()!=-1)
            row += orderdress[i].size();
        if(orderbooks[i][0].getID()!=-1)
            row += orderbooks[i].size();
    }
    ui->tableWidget->setRowCount(row);    //设置行
    ui->tableWidget->setColumnCount(7); //设置列
    //设置表头内容
    QStringList header;
    header<<tr("ID")<<tr("商家名")<<tr("种类")<<tr("商品名")<<tr("商品原价")<<tr("折扣价")<<tr("购买数量");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    int usesize = 0;
    for(int i = 0;i< (int)ordersize;i++)
    {
        ui->tableWidget->setItem(usesize,0,new QTableWidgetItem("订单"+QString::number(i+1)));
        QLabel *label = new QLabel();
        label->setText("总金额为:");
        ui->tableWidget->setCellWidget(usesize,3,label);
        double money = 0;
        int moneyrow = usesize;
        if(ispayed[usesize]!=1)
        {
        QPushButton *cancel = new QPushButton();
        cancel->setText("取消订单");
        connect(cancel, SIGNAL(clicked()), this, SLOT(cancleClicked()));
        ui->tableWidget->setCellWidget(usesize,5,cancel);
        QPushButton *pay = new QPushButton();
        pay->setText("支付");
        connect(pay, SIGNAL(clicked()), this, SLOT(payClicked()));
        ui->tableWidget->setCellWidget(usesize,6,pay);
        }
        else
        {
            QLabel *label = new QLabel();
            label->setText("已支付");
            ui->tableWidget->setCellWidget(usesize,6,label);
        }
        usesize++;
        for(int j =0 ;j<(int)orderfood[i].size();j++)
        {
            if(orderfood[i][0].getID()==-1)
                break;
            else
            {
                money += (orderfood[i][j].getDiscount()*orderfood[i][j].getBuynumber());
                ui->tableWidget->setItem(usesize,0,new QTableWidgetItem(QString::number(orderfood[i][j].getID())));
                ui->tableWidget->setItem(usesize,1,new QTableWidgetItem(orderfood[i][j].getStorename()));
                ui->tableWidget->setItem(usesize,2,new QTableWidgetItem("food"));
                ui->tableWidget->setItem(usesize,3,new QTableWidgetItem(orderfood[i][j].getName()));
                ui->tableWidget->setItem(usesize,4,new QTableWidgetItem(QString::number(orderfood[i][j].getPrice())));
                ui->tableWidget->setItem(usesize,5,new QTableWidgetItem(QString::number(orderfood[i][j].getDiscount())));
                ui->tableWidget->setItem(usesize,6,new QTableWidgetItem(QString::number(orderfood[i][j].getBuynumber())));
                usesize++;
            }
        }
        for(int j =0 ;j<(int)orderdress[i].size();j++)
        {
            if(orderdress[i][0].getID()==-1)
                break;
            else
            {
                money += (orderdress[i][j].getDiscount()*orderdress[i][j].getBuynumber());
                ui->tableWidget->setItem(usesize,0,new QTableWidgetItem(QString::number(orderdress[i][j].getID())));
                ui->tableWidget->setItem(usesize,1,new QTableWidgetItem(orderdress[i][j].getStorename()));
                ui->tableWidget->setItem(usesize,2,new QTableWidgetItem("dress"));
                ui->tableWidget->setItem(usesize,3,new QTableWidgetItem(orderdress[i][j].getName()));
                ui->tableWidget->setItem(usesize,4,new QTableWidgetItem(QString::number(orderdress[i][j].getPrice())));
                ui->tableWidget->setItem(usesize,5,new QTableWidgetItem(QString::number(orderdress[i][j].getDiscount())));
                ui->tableWidget->setItem(usesize,6,new QTableWidgetItem(QString::number(orderdress[i][j].getBuynumber())));
                usesize++;
            }
        }
        for(int j =0 ;j<(int)orderbooks[i].size();j++)
        {
            if(orderbooks[i][0].getID()==-1)
                break;
            else
            {
                money += (orderbooks[i][j].getDiscount()*orderbooks[i][j].getBuynumber());
                ui->tableWidget->setItem(usesize,0,new QTableWidgetItem(QString::number(orderbooks[i][j].getID())));
                ui->tableWidget->setItem(usesize,1,new QTableWidgetItem(orderbooks[i][j].getStorename()));
                ui->tableWidget->setItem(usesize,2,new QTableWidgetItem("books"));
                ui->tableWidget->setItem(usesize,3,new QTableWidgetItem(orderbooks[i][j].getName()));
                ui->tableWidget->setItem(usesize,4,new QTableWidgetItem(QString::number(orderbooks[i][j].getPrice())));
                ui->tableWidget->setItem(usesize,5,new QTableWidgetItem(QString::number(orderbooks[i][j].getDiscount())));
                ui->tableWidget->setItem(usesize,6,new QTableWidgetItem(QString::number(orderbooks[i][j].getBuynumber())));
                usesize++;
            }
        }
        ui->tableWidget->setItem(moneyrow,4,new QTableWidgetItem(QString::number(money)));
    }
}

void myorder::cancleClicked()
{
    QPushButton *senderObj=qobject_cast<QPushButton*>(sender());
    if(senderObj == nullptr)
    {
        return;
    }
    QModelIndex idx = ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int row=idx.row();
    QString str = ui->tableWidget->item(row,0)->text();
    qDebug()<<str;
    QString Num = str.mid(2);
    qDebug()<<Num;
    int num = Num.toUInt() - 1;
    qDebug()<<num;
    mSocket = new QUdpSocket();
    mSocket->bind(10004,QAbstractSocket::DontShareAddress);
    //修改数据库
    for(int i =0 ;i<(int)orderfood[num].size();i++)
    {
        int id = orderfood[num][i].getID();
        qDebug() << id;
        if(id!=-1)
        {
            QString ID = QString::number(id);
            QString Surplus = QString::number(orderfood[num][i].getSurplus());
            QString MyData="0010" + ID + ' ' + Surplus;
            mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
            /*
            QSqlQuery query;
            QString str =
                    QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(orderfood[num][i].getSurplus()).arg(id);
            query.exec(str);
            */
        }
    }
    for(int i =0 ;i<(int)orderdress[num].size();i++)
    {
        int id = orderdress[num][i].getID();
        qDebug() << id;
        if(id!=-1)
        {
            QString ID = QString::number(id);
            QString Surplus = QString::number(orderdress[num][i].getSurplus());
            QString MyData="0010" + ID + ' ' + Surplus;
            mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
            /*QSqlQuery query;
            QString str =
                    QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(orderdress[num][i].getSurplus()).arg(id);
            query.exec(str);*/
        }
    }
    for(int i =0 ;i<(int)orderbooks[num].size();i++)
    {
        int id = orderbooks[num][i].getID();
        qDebug() << id;
        if(id!=-1)
        {
            QString ID = QString::number(id);
            QString Surplus = QString::number(orderbooks[num][i].getSurplus());
            QString MyData="0010" + ID + ' ' + Surplus;
            mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
            /*QSqlQuery query;
            QString str =
                    QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(orderbooks[num][i].getSurplus()).arg(id);
            query.exec(str);*/
        }
    }
    //删除vector中的元素
    orderfood.erase(orderfood.begin()+num);
    qDebug() << orderfood.size();
    orderbooks.erase(orderbooks.begin()+num);
    qDebug() << orderbooks.size();
    orderdress.erase(orderdress.begin()+num);
    qDebug() << orderdress.size();
    //重新显示
    initialize();
}

void myorder::payClicked()
{
    QPushButton *senderObj=qobject_cast<QPushButton*>(sender());
    if(senderObj == nullptr)
    {
        return;
    }
    QModelIndex idx = ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int row=idx.row();

    //确认按钮
    int ok = QMessageBox::information(this,tr("支付"),tr("你确定"
                                                               "要支付此订单吗？"),
             QMessageBox::Yes,QMessageBox::No);
    //修改文件金额，消费者扣除金额，商家增加金额
    if(ok == QMessageBox::Yes)
    {
        nSocket = new QUdpSocket();
        nSocket->bind(10005,QAbstractSocket::DontShareAddress);
            double sub = ui->tableWidget->item(row,4)->text().toDouble();
            qDebug() << sub;
            if(buyerPtr->subBalance(sub))
            {
                QLabel *label1 = new QLabel();
                label1->setText("");
                ui->tableWidget->setCellWidget(row,5,label1);
                QLabel *label = new QLabel();
                label->setText("已支付");
                ispayed[row] = 1;
                ui->tableWidget->setCellWidget(row,6,label);
                QMessageBox msgBox(
                            QMessageBox::Information,//图标
                            "YES",//标题
                            "恭喜你,支付成功!",//提示消息
                            QMessageBox::Ok,//按钮
                            this);//父窗口
                msgBox.exec();
                double balance = buyerPtr->getBalance();
                QString Balance = QString::number(balance,10,3);
                QString MyData="0011" + buyerPtr->getUsername() + ' ' + Balance;
                nSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
            }
            else
            {
                QMessageBox msgBox(
                            QMessageBox::Critical,//图标
                            "Error",//标题
                            "您的余额不足，请先充值，支付失败",//提示消息
                            QMessageBox::Ok,//按钮
                            this);//父窗口
                msgBox.exec();
            }
        //商家余额增加
        QString str = ui->tableWidget->item(row,0)->text();
        QString Num = str.mid(2);
        int num = Num.toUInt() - 1;
        for(int i = 0;i<(int)orderfood[num].size();i++)
        {
            if(orderfood[num][0].getID()==-1)
                break;
            QString name = orderfood[num][i].getStorename();
            double balance = (orderfood[num][i].getDiscount()*orderfood[num][i].getBuynumber());
            QString Balance = QString::number(balance,10,3);
            QString MyData="0111" + name + ' ' + Balance;
            nSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
        }
        for(int i = 0;i<(int)orderdress[num].size();i++)
        {
            if(orderdress[num][0].getID()==-1)
                break;
            QString name = orderdress[num][i].getStorename();
            double balance = (orderdress[num][i].getDiscount()*orderdress[num][i].getBuynumber());
            QString Balance = QString::number(balance,10,3);
            QString MyData="0111" + name + ' ' + Balance;
            nSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
        }
        for(int i = 0;i<(int)orderbooks[num].size();i++)
        {
            if(orderbooks[num][0].getID()==-1)
                break;
            QString name = orderbooks[num][i].getStorename();
            double balance = (orderbooks[num][i].getDiscount()*orderbooks[num][i].getBuynumber());
            QString Balance = QString::number(balance,10,3);
            QString MyData="0111" + name + ' ' + Balance;
            nSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
        }
    }
}
