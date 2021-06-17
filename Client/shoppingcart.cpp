#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "goods.h"
#include "myorder.h"
#include <QCheckBox>
#include <QDebug>

using namespace std;

vector<vector<dress>> orderdress;
vector<vector<food>> orderfood;
vector<vector<books>> orderbooks;
vector<books> Books;
vector<dress> Dress;
vector<food> Food;
extern vector<books> cartbooks;
extern vector<dress> cartdress;
extern vector<food> cartfood;
extern vector<books> books;
extern vector<dress> dress;
extern vector<food> food;
bool isfreashed = 0;

shoppingcart::shoppingcart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoppingcart)
{
    ui->setupUi(this);
    initialize();
    QTableWidgetItem item;
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(dataChanged(QTableWidgetItem*)));
}

void shoppingcart::initialize()
{
    isfreashed = 0;
    int row = cartfood.size() + cartbooks.size() + cartdress.size();
    ui->tableWidget->setRowCount(row);    //设置行
    ui->tableWidget->setColumnCount(10); //设置列
    //设置表头内容
    QStringList header;
    header<<tr("选择")<<tr("ID")<<tr("商家名")<<tr("种类")<<tr("商品名")<<tr("商品原价")<<tr("折扣价")<<tr("购买数量")<<tr("库存")<<tr("删除");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    int size = cartfood.size();
    for(int i =0 ;i< size;i++)
    {
        //qDebug() << cartfood[i].getID();
        QCheckBox *check = new QCheckBox();
        check->setText("勾选");
        connect(check,SIGNAL(stateChanged(int)),this,SLOT(stateChanged(int)));
        ui->tableWidget->setCellWidget(i,0,check);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(cartfood[i].getID())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(cartfood[i].getStorename()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem("food"));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(cartfood[i].getName()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(cartfood[i].getPrice())));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(cartfood[i].getDiscount())));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(cartfood[i].getBuynumber())));//此处为购买数量
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString::number(cartfood[i].getSurplus())));
        QPushButton *pBtn = new QPushButton();
        pBtn->setText("删除");
        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnDeleteClicked()));
        ui->tableWidget->setCellWidget(i,9,pBtn);
    }
    size = cartbooks.size()+cartfood.size();
    for(int i =cartfood.size() ,j=0;i< size;i++,j++)
    {
        //qDebug() << cartbooks[j].getID();
        QCheckBox *check = new QCheckBox();
        check->setText("勾选");
        connect(check,SIGNAL(stateChanged(int)),this,SLOT(stateChanged(int)));
        ui->tableWidget->setCellWidget(i,0,check);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(cartbooks[j].getID())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(cartbooks[j].getStorename()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem("books"));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(cartbooks[j].getName()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(cartbooks[j].getPrice())));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(cartbooks[j].getDiscount())));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(cartbooks[j].getBuynumber())));//surplus在此处为购买数量
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString::number(cartbooks[j].getSurplus())));
        QPushButton *pBtn = new QPushButton();
        pBtn->setText("删除");
        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnDeleteClicked()));
        ui->tableWidget->setCellWidget(i,9,pBtn);
    }
    size = row;
    for(int i =cartfood.size()+cartbooks.size(),j=0 ;i< size;i++,j++)
    {
        //qDebug() << cartdress[j].getID();
        QCheckBox *check = new QCheckBox();
        check->setText("勾选");
        connect(check,SIGNAL(stateChanged(int)),this,SLOT(stateChanged(int)));
        ui->tableWidget->setCellWidget(i,0,check);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(cartdress[j].getID())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(cartdress[j].getStorename()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem("dress"));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(cartdress[j].getName()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(cartdress[j].getPrice())));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(cartdress[j].getDiscount())));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(cartdress[j].getBuynumber())));//surplus在此处为购买数量
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString::number(cartdress[j].getSurplus())));
        QPushButton *pBtn = new QPushButton();
        pBtn->setText("删除");
        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnDeleteClicked()));
        ui->tableWidget->setCellWidget(i,9,pBtn);
    }
    isfreashed = 1;
}

shoppingcart::~shoppingcart()
{
    delete ui;
}

void shoppingcart::stateChanged(int state)
{
    QCheckBox *senderObj=qobject_cast<QCheckBox*>(sender());
    if(senderObj == nullptr)
    {
        return;
    }
    QModelIndex idx = ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int row=idx.row();
    if(state==Qt::Checked)
    {
        QString type = ui->tableWidget->item(row,3)->text();
        if(type=="food")
        {
            class food tmp;
            tmp.setID(ui->tableWidget->item(row,1)->text().toInt());
            tmp.setName(ui->tableWidget->item(row,4)->text());
            tmp.setPrice(ui->tableWidget->item(row,5)->text().toDouble());
            tmp.setBuynumber(ui->tableWidget->item(row,7)->text().toInt());
            tmp.setDiscount(ui->tableWidget->item(row,6)->text().toDouble());
            tmp.setStorename(ui->tableWidget->item(row,2)->text());
            tmp.setSurplus(ui->tableWidget->item(row,8)->text().toInt());
            Food.push_back(tmp);
        }
        else if(type=="dress")
        {
            class dress tmp;
            tmp.setID(ui->tableWidget->item(row,1)->text().toInt());
            tmp.setName(ui->tableWidget->item(row,4)->text());
            tmp.setPrice(ui->tableWidget->item(row,5)->text().toDouble());
            tmp.setBuynumber(ui->tableWidget->item(row,7)->text().toInt());
            tmp.setDiscount(ui->tableWidget->item(row,6)->text().toDouble());
            tmp.setStorename(ui->tableWidget->item(row,2)->text());
            tmp.setSurplus(ui->tableWidget->item(row,8)->text().toInt());
            Dress.push_back(tmp);
        }
        else if(type=="books")
        {
            class books tmp;
            tmp.setID(ui->tableWidget->item(row,1)->text().toInt());
            tmp.setName(ui->tableWidget->item(row,4)->text());
            tmp.setPrice(ui->tableWidget->item(row,5)->text().toDouble());
            tmp.setBuynumber(ui->tableWidget->item(row,7)->text().toInt());
            tmp.setDiscount(ui->tableWidget->item(row,6)->text().toDouble());
            tmp.setStorename(ui->tableWidget->item(row,2)->text());
            tmp.setSurplus(ui->tableWidget->item(row,8)->text().toInt());
            Books.push_back(tmp);
        }
    }
    else if(state==Qt::Unchecked)
    {
        QString type = ui->tableWidget->item(row,3)->text();
        int id = ui->tableWidget->item(row,1)->text().toInt();
        if(type=="food")
        {
            for(int i = 0;i< (int)Food.size();i++)
            {
                if(id==Food[i].getID())
                    Food.erase(Food.begin()+i);
            }
        }
        else if(type=="dress")
        {
            for(int i = 0;i< (int)Dress.size();i++)
            {
                if(id==Dress[i].getID())
                    Dress.erase(Dress.begin()+i);
            }
        }
        else if(type=="books")
        {
            for(int i = 0;i< (int)Books.size();i++)
            {
                if(id==Books[i].getID())
                    Books.erase(Books.begin()+i);
            }
        }
    }
}


void shoppingcart::dataChanged(QTableWidgetItem* Item)
{
    if(isfreashed==1)
    {
    int surplus = Item->text().toInt();
    int row = Item->row();
    qDebug() << row;
    int id = ui->tableWidget->item(row,1)->text().toInt();
    qDebug() << id;
    for(int i =0 ;i<(int)cartfood.size();i++)
    {
        if(cartfood[i].getID()==id)
        {
            cartfood[i].setBuynumber(surplus);
            //qDebug() <<"surplus" <<cartfood[i].getSurplus();
        }
    }
    for(int i =0 ;i<(int)cartbooks.size();i++)
    {
        if(cartbooks[i].getID()==id)
            cartbooks[i].setBuynumber(surplus);
    }
    for(int i =0 ;i<(int)cartdress.size();i++)
    {
        if(cartdress[i].getID()==id)
            cartdress[i].setBuynumber(surplus);
    }
    }
}


void shoppingcart::OnDeleteClicked()
{
    int ok = QMessageBox::information(this,tr("删除"),tr("你确定"
                                                               "将此商品从购物车删除吗？"),
             QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
    QPushButton *senderObj=qobject_cast<QPushButton*>(sender());
    if(senderObj == nullptr)
    {
        return;
    }
    QModelIndex idx = ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int row=idx.row();
    qDebug() << "删除";
    qDebug() << row;
    //QString type = ui->tableWidget->item(0,1)->text();
    int id = ui->tableWidget->item(row,1)->text().toInt();
    qDebug() << id;
    for(int i =0 ;i<(int)cartfood.size();i++)
    {
        if(cartfood[i].getID()==id)
            cartfood.erase(cartfood.begin()+i);
    }
    for(int i =0 ;i<(int)cartbooks.size();i++)
    {
        if(cartbooks[i].getID()==id)
            cartbooks.erase(cartbooks.begin()+i);
    }
    for(int i =0 ;i<(int)cartdress.size();i++)
    {
        if(cartdress[i].getID()==id)
            cartdress.erase(cartdress.begin()+i);
    }
    //ui->tableWidget->removeRow(row);
    QMessageBox msgBox(
                QMessageBox::Information,//图标
                "删除",//标题
                "删除成功",//提示消息
                QMessageBox::Ok,//按钮
                this);//父窗口
    msgBox.exec();
    initialize();
    }
}

void shoppingcart::on_buyButton_clicked()
{
    bool right = 1;
    //生成订单失败
    if(Food.empty()&&Dress.empty()&&Books.empty())
    {
        right = 0;
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Erorr",//标题
                    "生成订单失败，请选择商品!",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        return;
    }
    int buynumber = 0;
    for(int i = 0;i<(int)Food.size();i++)
    {
        if(Food[i].getBuynumber()>Food[i].getSurplus())
        {
            qDebug() << Food[i].getBuynumber();
            qDebug() << Food[i].getSurplus();
            right =0;
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Erorr",//标题
                        "库存不足，生成订单失败!",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
            return;
        }
        else
        {
            if(Food[i].getBuynumber()<0)
            {
                QMessageBox msgBox(
                            QMessageBox::Critical,//图标
                            "Erorr",//标题
                            "购买数量小于0，生成订单失败!",//提示消息
                            QMessageBox::Ok,//按钮
                            this);//父窗口
                msgBox.exec();
                return;
            }
            buynumber += Food[i].getBuynumber();
        }
    }
    for(int i = 0;i < (int)Dress.size();i++)
    {
        if(Dress[i].getBuynumber()>Dress[i].getSurplus())
        {
            qDebug() << Dress[i].getBuynumber();
            qDebug() << Dress[i].getSurplus();
            right = 0;
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Erorr",//标题
                        "库存不足，生成订单失败!",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
            return;
        }
        else
        {
            if(Dress[i].getBuynumber()<0)
            {
                QMessageBox msgBox(
                            QMessageBox::Critical,//图标
                            "Erorr",//标题
                            "购买数量小于0，生成订单失败!",//提示消息
                            QMessageBox::Ok,//按钮
                            this);//父窗口
                msgBox.exec();
                return;
            }
            buynumber += Dress[i].getBuynumber();
        }
    }
    for(int i = 0;i<(int)Books.size();i++)
    {
        if(Books[i].getBuynumber()>Books[i].getSurplus())
        {
            right = 0;
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Erorr",//标题
                        "库存不足，生成订单失败!",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
            return;
        }
        else
        {
            if(Books[i].getBuynumber()<0)
            {
                QMessageBox msgBox(
                            QMessageBox::Critical,//图标
                            "Erorr",//标题
                            "购买数量小于0，生成订单失败!",//提示消息
                            QMessageBox::Ok,//按钮
                            this);//父窗口
                msgBox.exec();
                return;
            }
            buynumber += Books[i].getBuynumber();
        }
    }
    if(buynumber==0)
    {
        right = 0;
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Erorr",//标题
                    "购买总数为0，生成订单失败!",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        return;
    }
    if(right==1)
    {
    //生成订单成功，则
        mSocket = new QUdpSocket();
        mSocket->bind(10003,QAbstractSocket::DontShareAddress);
        //connect(mSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    //把购物车中的商品删除
    for(int i = 0;i<(int)Food.size();i++)
    {
        int id = Food[i].getID();
        QString ID = QString::number(id);
        QString Surplus = QString::number(Food[i].getSurplus()-Food[i].getBuynumber());
        QString MyData="0001" + ID + ' ' + Surplus;
        mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
        for(int j =0 ;j<(int)cartfood.size();j++)
        {
            if(cartfood[j].getID()==id)
                cartfood.erase(cartfood.begin()+j);
        }
    }
    for(int i = 0;i<(int)Dress.size();i++)
    {
        int id = Dress[i].getID();
        QString ID = QString::number(id);
        QString Surplus = QString::number(Dress[i].getSurplus()-Dress[i].getBuynumber());
        QString MyData="0001" + ID + ' ' + Surplus;
        mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
        for(int j =0 ;j<(int)cartdress.size();j++)
        {
            if(cartdress[j].getID()==id)
                cartdress.erase(cartdress.begin()+j);
        }
    }
    for(int i =0;i<(int)Books.size();i++)
    {
        int id = Books[i].getID();
        QString ID = QString::number(id);
        QString Surplus = QString::number(Books[i].getSurplus()-Books[i].getBuynumber());
        QString MyData="0001" + ID + ' ' + Surplus;
        mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
        for(int j =0 ;j<(int)cartbooks.size();j++)
        {
            if(cartbooks[j].getID()==id)
                cartbooks.erase(cartbooks.begin()+j);
        }
    }
    //把商品类的剩余量减少，实现冻结功能，写入数据库中
    for(int i = 0;i<(int)Food.size();i++)
    {
        int id = Food[i].getID();
        /*QSqlQuery query;
        QString str =
                QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(Food[i].getSurplus()-Food[i].getBuynumber()).arg(id);
        query.exec(str);*/
        for(int j =0 ;j<(int)food.size();j++)
        {
            if(food[j].getID()==id)
                food[j].setSurplus(Food[i].getSurplus()-Food[i].getBuynumber());
        }
    }
    for(int i = 0;i<(int)Dress.size();i++)
    {
        int id = Dress[i].getID();
        /*QSqlQuery query;
        QString str =
                QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(Dress[i].getSurplus()-Dress[i].getBuynumber()).arg(id);
        query.exec(str);*/
        for(int j =0 ;j<(int)dress.size();j++)
        {
            if(dress[j].getID()==id)
                dress[j].setSurplus(Dress[i].getSurplus()-Dress[i].getBuynumber());
        }
    }
    for(int i =0;i<(int)Books.size();i++)
    {
        int id = Books[i].getID();
        /*QSqlQuery query;
        QString str =
                QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(Books[i].getSurplus()-Books[i].getBuynumber()).arg(id);
        query.exec(str);*/
        for(int j =0 ;j<(int)books.size();j++)
        {
            if(books[j].getID()==id)
                books[j].setSurplus(Books[i].getSurplus()-Books[i].getBuynumber());
        }
    }
    //把此订单存入vector中
    if(!Food.empty())
        orderfood.push_back(Food);
    else
    {
        class food tmp;
        tmp.setID(-1);
        Food.push_back(tmp);
        orderfood.push_back(Food);
    }
    if(!Dress.empty())
        orderdress.push_back(Dress);
    else
    {
        class dress tmp;
        tmp.setID(-1);
        Dress.push_back(tmp);
        orderdress.push_back(Dress);
    }
    if(!Books.empty())
        orderbooks.push_back(Books);
    else
    {
        class books tmp;
        tmp.setID(-1);
        Books.push_back(tmp);
        orderbooks.push_back(Books);
    }
    //清除Food Dress Books
    Food.clear();
    Dress.clear();
    Books.clear();
    //跳转到订单页面
    myorder m;
    m.exec();
    //刷新页面
    initialize();
    }
}

void shoppingcart::on_orderButton_clicked()
{
    myorder m;
    m.exec();
}

void shoppingcart::on_freshButton_clicked()
{
    initialize();
    Food.clear();
    Dress.clear();
    Books.clear();
}
