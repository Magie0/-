#include "searchgoodsdialog.h"
#include "ui_searchgoodsdialog.h"

searchgoodsDialog::searchgoodsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchgoodsDialog)
{
    ui->setupUi(this);
    queryTable();
    //connect(ui->username,SIGNAL(textChanged(QString)),this,SLOT(enable1Button()));
    //connect(ui->username,SIGNAL(textChanged(QString)),this,SLOT(enable1Button()));
}

searchgoodsDialog::~searchgoodsDialog()
{
    delete ui;
}

void searchgoodsDialog::queryTable()
{
    // 构造一个查询数据表的sql语句
    QString str ("SELECT * FROM Goods");
    // 执行sql语句并保存结果到model
    model.setQuery (str);
    // 显示结果到ui
    ui->tableView->setModel (&model);
}

void searchgoodsDialog::on_searchButton_clicked()
{
    QString Condition = ui->searchcomboBox->currentText();
    if(Condition == "type")
    {
       QString type = ui->lineEdit->text();
       qDebug() << type;
       if(type=="")
       {
           QMessageBox msgBox(
                       QMessageBox::Critical,//图标
                       "Error",//标题
                       "请输入商品类型",//提示消息
                       QMessageBox::Ok,//按钮
                       this);//父窗口
           msgBox.exec();
       }
       else if(type=="books"||type=="dress"||type=="food")
       {
           QString value = ui->valuecomboBox->currentText ();
           // 获取排序的条件：升序 / 降序
           // 获取排序的条件：升序 / 降序
           QString conditon;
           if (ui->conditioncomboBox->currentIndex ()) {
               conditon = "DESC";
           } else {
               conditon = "ASC";
           }
           QString Sql = QString (
                             "SELECT * FROM Goods WHERE type = '%1' ORDER BY %2 %3").arg(type).arg (value).arg (conditon);
           // 执行sql语句并保存结果到model
           model.setQuery (Sql);
           // 显示结果到ui
           ui->tableView->setModel (&model);
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
       }
    }
    else if(Condition == "storename")
    {
        QString storename = ui->lineEdit->text();
        qDebug() << storename;
        if(storename=="")
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "请输入商家名",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
        else
        {
            QString value = ui->valuecomboBox->currentText ();
            // 获取排序的条件：升序 / 降序
            // 获取排序的条件：升序 / 降序
            QString conditon;
            if (ui->conditioncomboBox->currentIndex ()) {
                conditon = "DESC";
            } else {
                conditon = "ASC";
            }
            QString Sql = QString (
                              "SELECT * FROM Goods WHERE storename = '%1' ORDER BY %2 %3").arg(storename).arg (value).arg (conditon);
            // 执行sql语句并保存结果到model
            model.setQuery (Sql);
            // 显示结果到ui
            ui->tableView->setModel (&model);
        }
    }
    else if(Condition == "price")
    {
        bool test1 = false,test2 = false;
        double lowprice = ui->lineEdit->text().toDouble(&test1);
        double highprice = ui->lineEdit_2->text().toDouble(&test2);
        qDebug() << lowprice << endl << highprice;
        if(lowprice<0||highprice<0)
        {
            test1 = false;
            test2 = false;
        }
        if(ui->lineEdit->text()==""||ui->lineEdit_2->text()=="")
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "请输入价格区间",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
        else if(highprice<lowprice)
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "请输入正确的价格区间",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
        else if(test1==true&&test2==true)
        {
            QString value = ui->valuecomboBox->currentText ();
            // 获取排序的条件：升序 / 降序
            // 获取排序的条件：升序 / 降序
            QString conditon;
            if (ui->conditioncomboBox->currentIndex ()) {
                conditon = "DESC";
            } else {
                conditon = "ASC";
            }
            QString Sql = QString (
                              "SELECT * FROM Goods WHERE price BETWEEN %1 and %2 ORDER BY %3 %4").arg(lowprice).arg (highprice).arg(value).arg (conditon);
            // 执行sql语句并保存结果到model
            model.setQuery (Sql);
            // 显示结果到ui
            ui->tableView->setModel (&model);
        }
        else if(test1==false||test2==false)
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "请输入正整数(包括0)",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
    }
    else if(Condition=="name")
    {
        QString name = ui->lineEdit->text();
        qDebug() << name;
        if(name=="")
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "请输入商品名",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
        else
        {
            QString value = ui->valuecomboBox->currentText ();
            // 获取排序的条件：升序 / 降序
            // 获取排序的条件：升序 / 降序
            QString conditon;
            if (ui->conditioncomboBox->currentIndex ()) {
                conditon = "DESC";
            } else {
                conditon = "ASC";
            }
            QString Sql = QString (
                              "SELECT * FROM Goods WHERE name like '%"+name+"%' ORDER BY %2 %3").arg (value).arg (conditon);
            // 执行sql语句并保存结果到model
            model.setQuery (Sql);
            // 显示结果到ui
            ui->tableView->setModel (&model);
        }
    }
    else
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请选择正确的筛选类型",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

void searchgoodsDialog::on_sortButton_clicked()
{
    QString value = ui->valuecomboBox->currentText ();
    // 获取排序的条件：升序 / 降序
    // 获取排序的条件：升序 / 降序
    QString conditon;
    if (ui->conditioncomboBox->currentIndex ()) {
        conditon = "DESC";
    } else {
        conditon = "ASC";
    }
    QString sortSql = QString (
                      "SELECT * FROM Goods ORDER BY %1 %2").arg (value).arg (conditon);
    // 执行sql语句并保存结果到model
    model.setQuery (sortSql);
    // 显示结果到ui
    ui->tableView->setModel (&model);
}

void searchgoodsDialog::on_searchcomboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="请选择")
    {
        ui->label->setText("");
        ui->label_2->setText("");
        ui->lineEdit->setHidden(true);
        ui->lineEdit_2->setHidden(true);
    }
    else if(arg1=="name")
    {
        ui->label->setText("名称");
        ui->label_2->setText("");
        ui->lineEdit->setHidden(false);
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setHidden(true);
        ui->searchButton->setEnabled(true);
    }
    else if(arg1=="type")
    {
        ui->label->setText("商品类型");
        ui->label_2->setText("");
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setHidden(true);
        ui->searchButton->setEnabled(true);
    }
    else if(arg1=="storename")
    {
        ui->label->setText("商家名");
        ui->label_2->setText("");
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setHidden(true);
        ui->searchButton->setEnabled(true);
    }
    else if(arg1=="price")
    {
        ui->label->setText("最低价");
        ui->label_2->setText("最高价");
        ui->lineEdit->setEnabled(true);
        ui->lineEdit->setHidden(false);
        ui->lineEdit_2->setHidden(false);
        ui->lineEdit_2->setEnabled(true);
        ui->searchButton->setEnabled(true);
    }
}

void searchgoodsDialog::on_cancelButton_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "退出",
                "是否确定退出？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}
