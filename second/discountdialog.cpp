#include "discountdialog.h"
#include "ui_discountdialog.h"
#include<QSqlRecord>

extern double Discount;
discountDialog::discountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountDialog)
{
    ui->setupUi(this);
}

discountDialog::~discountDialog()
{
    delete ui;
}

void discountDialog::on_okButton_clicked()
{
    QString type = ui->typeEdit->text();
    if(type=="books"||type=="dress"||type=="food")
    {
        bool test =false;
    double discount = ui->discountEdit->text().toDouble(&test);
    if(discount<=0&&discount>=10)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入0到10之间的数字",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
            msgBox.exec();
    }
    else
    {
        Discount = discount;
    QString Sql = QString (
                          "SELECT * FROM Goods");
    QSqlQueryModel model;
    model.setQuery(Sql);
    qDebug() << model.rowCount();
    int n = model.rowCount();
    for (int i = 0; i < n; i++)
    {
        double price = model.record(i).value("price").toDouble();
        qDebug() << price;
        price = price * discount /10;
        // 构造一个查询数据表的sql语句
        QString str = QString("UPDATE Goods SET discount = %1 WHERE id = %2 and type = '%3'").arg(price).arg(i).arg(type);
        // 执行sql语句
        QSqlQuery query;
        query.exec (str);
    }
    QMessageBox msgBox(
                QMessageBox::Information,//图标
                "YES",//标题
                "成功",//提示消息
                QMessageBox::Ok,//按钮
                this);//父窗口
        msgBox.exec();
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
        ui->typeEdit->setText("");
    }
}

void discountDialog::on_cancelButton_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "折扣",
                "是否确定退出？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}
