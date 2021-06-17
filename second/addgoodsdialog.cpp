#include "addgoodsdialog.h"
#include "ui_addgoodsdialog.h"
#include<QSqlRecord>
#include "account.h"
#include "goods.h"
extern store* storePtr;

addgoodsDialog::addgoodsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addgoodsDialog)
{
    ui->setupUi(this);
}

addgoodsDialog::~addgoodsDialog()
{
    delete ui;
}

void addgoodsDialog::on_addButton_clicked()
{
    QSqlQuery query;
    QString sortSql = QString (
                          "SELECT * FROM Goods ORDER BY id DESC");
    //qDebug() << sortSql;
    QSqlQueryModel model;
    model.setQuery(sortSql);
    int id = model.record(0).value("id").toInt() + 1;
    qDebug() << id;
    //int id = goodsID;//取出数据库中最大ID再+1
    //goodsID++;
    QString type = ui->goodstype->text();
    QString name = ui->goodsname->text();
    if(type=="food"||type=="dress"||type=="books")
    {
        bool test1 = false,test2 = false;
    double price = ui->goodsprice->text().toDouble(&test1);
    if(price<0)
        test1 = false;
    if(test1==false)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入正数",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else{
    int num = ui->goodsnum->text().toInt(&test2);
    if(num<0)
        test2 = false;
    if(test2==false)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入正整数",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else{
    QString describe = ui->goodsdescribe->text();
    QString str = QString("INSERT INTO Goods VALUES(%1,'%2','%3',%4,%5,'%6',%7,'%8')"
                          ).arg(id).arg(type).arg(name).arg(price).arg(num).arg(storePtr->getUsername()).arg(price).arg(describe);
    if(query.exec(str)==false)
    {
        qDebug() << str;
    }
    else{
        qDebug() << "添加成功";
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "添加成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        //创建对象
        if(type=="food")
        {
            food f;
            f.setID(id);
            f.setName(name);
            f.setPrice(price);
            f.setSurplus(num);
            f.setStorename(storePtr->getUsername());
        }
        else if(type=="dress")
        {
            dress d;
            d.setID(id);
            d.setName(name);
            d.setPrice(price);
            d.setSurplus(num);
            d.setStorename(storePtr->getUsername());
        }
        else if(type=="books")
        {
            books b;
            b.setID(id);
            b.setName(name);
            b.setPrice(price);
            b.setSurplus(num);
            b.setStorename(storePtr->getUsername());
        }
        //queryTable();
    }
    ui->goodstype->setText("");
    ui->goodsname->setText("");
    ui->goodsprice->setText("");
    ui->goodsnum->setText("");
    ui->goodsdescribe->setText("");
    }
    }
    }
    else
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入正确的商品类型",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        ui->goodstype->setText("");
        ui->goodsname->setText("");
        ui->goodsprice->setText("");
        ui->goodsnum->setText("");
        //ui->storename->setText("");
    }
}

void addgoodsDialog::on_cancleButton_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "添加商品",
                "是否确定退出？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}
