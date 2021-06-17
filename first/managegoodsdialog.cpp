#include "managegoodsdialog.h"
#include "ui_managegoodsdialog.h"
#include "account.h"

extern store* storePtr;
extern double Discount;
managegoodsDialog::managegoodsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managegoodsDialog)
{
    ui->setupUi(this);
    queryTable();
    ui->nameLabel->setText(storePtr->getUsername());
    connect(ui->goodsEdit,SIGNAL(textChanged(QString)),this,SLOT(enable1Button()));
    connect(ui->priceEdit,SIGNAL(textChanged(QString)),this,SLOT(enable2Button()));
    connect(ui->numEdit,SIGNAL(textChanged(QString)),this,SLOT(enable3Button()));
}

managegoodsDialog::~managegoodsDialog()
{
    delete ui;
}

void managegoodsDialog::queryTable()
{
        // 构造一个查询数据表的sql语句
        QString str = QString("SELECT * FROM Goods WHERE storename = '%1'").arg(storePtr->getUsername());
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        ui->tableView->setModel (&model);
}

void managegoodsDialog::enable1Button()
{
    ui->searchButton->setEnabled(ui->goodsEdit->text()!="");
}

void managegoodsDialog::enable2Button()
{
    ui->priceokButton->setEnabled(ui->priceEdit->text()!="");
}

void managegoodsDialog::enable3Button()
{
    ui->numokButton->setEnabled(ui->numEdit->text()!="");
}

void managegoodsDialog::on_priceokButton_clicked()
{
    QString condition = ui->comboBox->currentText();
    //QString test = ui->priceEdit->text();
    bool test = false;
    double price = ui->priceEdit->text().toDouble(&test);
    if(price<0)
        test = false;
    if(test==false)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入正确的正数(包括0)",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else
    {
    if(condition == "请选择")
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请选择",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(condition == "id")
    {
        int id = ui->goodsEdit->text().toInt();
        qDebug() << id;
        // 构造一个查询数据表的sql语句
        QString str = QString("UPDATE Goods SET price = %1 WHERE storename = '%2' and id = %3").arg(price).arg(storePtr->getUsername()).arg(id);
        QString str0 = QString("UPDATE Goods SET discount = %1 WHERE storename = '%2' and id = %3").arg(price*Discount/10).arg(storePtr->getUsername()).arg(id);
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        model.setQuery(str0);
        QString str2 = QString("SELECT * FROM Goods WHERE storename = '%1' and id = %2").arg(storePtr->getUsername()).arg(id);
        model.setQuery (str2);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(condition == "type")
    {
        // 构造一个查询数据表的sql语句
        QString str =
                QString("UPDATE Goods SET price = %1 WHERE storename = '%2' and type = '%3'").arg(price).arg(storePtr->getUsername()).arg(ui->goodsEdit->text());
        QString str0 =
                QString("UPDATE Goods SET discount = %1 WHERE storename = '%2' and type = '%3'").arg(price*Discount/10).arg(storePtr->getUsername()).arg(ui->goodsEdit->text());
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        model.setQuery (str0);
        QString str2 =
                QString("SELECT * FROM Goods WHERE storename = '%1' and type = '%2'").arg(storePtr->getUsername()).arg(ui->goodsEdit->text());
        model.setQuery (str2);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(condition == "name")
    {
        // 构造一个查询数据表的sql语句
        QString name = ui->goodsEdit->text();
        QString str =
                QString("UPDATE Goods SET price = %1 WHERE storename = '%2' and  name LIKE '%"+name+"%' ").arg(price).arg(storePtr->getUsername());
        model.setQuery (str);
        QString str0 =
                QString("UPDATE Goods SET discount = %1 WHERE storename = '%2' and  name LIKE '%"+name+"%' ").arg(price*Discount/10).arg(storePtr->getUsername());
        model.setQuery (str0);
        QString str2 =
                QString("SELECT * FROM Goods WHERE storename = '%1' and name LIKE '%"+name+"%'").arg(storePtr->getUsername());//.arg(ui->goodsEdit->text());
        model.setQuery (str2);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    }
    ui->priceEdit->setText("");
}

void managegoodsDialog::on_numokButton_clicked()
{
    QString condition = ui->comboBox->currentText();
    //QString test = ui->priceEdit->text();
    bool test = false;
    int num = ui->numEdit->text().toInt(&test);
    if(test==false)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入正整数",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else
    {
    if(num<0)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入大于0的整数",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    if(num>=0&&condition == "请选择")
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请选择",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(num>=0&&condition == "id")
    {
        int id = ui->goodsEdit->text().toInt();
        qDebug() << id;
        // 构造一个查询数据表的sql语句
        QString str = QString("UPDATE Goods SET surplus = %1 WHERE storename = '%2' and id = %3").arg(num).arg(storePtr->getUsername()).arg(id);
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        QString str2 = QString("SELECT * FROM Goods WHERE storename = '%1' and id = %2").arg(storePtr->getUsername()).arg(id);
        model.setQuery (str2);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(num>=0&&condition == "type")
    {
        // 构造一个查询数据表的sql语句
        QString str =
                QString("UPDATE Goods SET surplus = %1 WHERE storename = '%2' and type = '%3'").arg(num).arg(storePtr->getUsername()).arg(ui->goodsEdit->text());
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        QString str2 =
                QString("SELECT * FROM Goods WHERE storename = '%1' and type = '%2'").arg(storePtr->getUsername()).arg(ui->goodsEdit->text());
        model.setQuery (str2);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(num>=0&&condition == "name")
    {
        QString name = ui->goodsEdit->text();
        // 构造一个查询数据表的sql语句
        QString str =
                QString("UPDATE Goods SET surplus = %1 WHERE storename = '%2' and name LIKE '%"+name+"%'").arg(num).arg(storePtr->getUsername());//.arg(ui->goodsEdit->text());
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        QString str2 =
                QString("SELECT * FROM Goods WHERE storename = '%1' and name LIKE '%"+name+"%'").arg(storePtr->getUsername());
        model.setQuery (str2);
        // 显示结果到ui
        ui->tableView->setModel (&model);
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    }
    ui->numEdit->setText("");
}

void managegoodsDialog::on_cancelButton_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "管理商品",
                "是否确定退出管理商品？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}

void managegoodsDialog::on_searchButton_clicked()
{
    QString condition = ui->comboBox->currentText();
    if(condition == "请选择")
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请选择",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else if(condition == "id")
    {
        int id = ui->goodsEdit->text().toInt();
        qDebug() << id;
        // 构造一个查询数据表的sql语句
        QString str = QString("SELECT * FROM Goods WHERE storename = '%1' and id = %2").arg(storePtr->getUsername()).arg(id);
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        ui->tableView->setModel (&model);
    }
    else if(condition == "type")
    {
        // 构造一个查询数据表的sql语句
        QString str =
                QString("SELECT * FROM Goods WHERE storename = '%1' and type = '%2'").arg(storePtr->getUsername()).arg(ui->goodsEdit->text());
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        ui->tableView->setModel (&model);
    }
    else if(condition == "name")
    {
        QString name = ui->goodsEdit->text();
        // 构造一个查询数据表的sql语句
        QString str =
                QString("SELECT * FROM Goods WHERE storename = '%1' and name LIKE '%"+name+"%' ").arg(storePtr->getUsername());
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        ui->tableView->setModel (&model);
    }
}
