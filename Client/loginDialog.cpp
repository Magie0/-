#include "loginDialog.h"
#include <fstream>
#include "account.h"
#include "changepassworddialog.h"

extern bool isLogged;
extern buyer* buyerPtr;
extern store* storePtr;
extern int ID;
//构造函数
loginDialog::loginDialog()
    :ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    //信号和槽的连接
    //connect(ui->username,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    //connect(ui->password,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    connect(ui->loginBox,SIGNAL(accepted()),this,SLOT(onAccepted()));
    connect(ui->loginBox,SIGNAL(rejected()),this,SLOT(onRejected()));
}

void loginDialog::readData()
{
    while (mSocket->hasPendingDatagrams())
    {
        QByteArray MyDate;//因为传送来的数据类型是未知，所以用bytearray
        MyDate.resize(mSocket->pendingDatagramSize());//mydata的数据大小取决于接收到的数据
        mSocket->readDatagram(MyDate.data(),MyDate.size());//读取数据

        QString str = QString::fromUtf8(MyDate);
        qDebug() << "来自Server的报文：" <<str;
        if(str[0]=='0'&&str[1]=='0')//报错代码：00
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "请输入账户名或密码",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
        else if(str[0]=='0'&&str[1]=='1')
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "用户名或密码错误",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
                msgBox.exec();
        }
        else
        {
            QMessageBox msgBox(
                        QMessageBox::Information,//图标
                        "YES",//标题
                        "登陆成功",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
                msgBox.exec();
            QString user,pass,id,balance;
            int i = 2;
            while(str[i]!=' ')
            {
                user = user + str[i];
                i++;
            }
            qDebug() << user;
            i++;
            while(str[i]!=' ')
            {
                pass = pass + str[i];
                i++;
            }
            qDebug() << pass;
            i++;
            while(str[i]!=' ')
            {
                id = id + str[i];
                i++;
            }
            qDebug() << id;
            i++;
            while(i<str.size())
            {
                balance = balance + str[i];
                i++;
            }
            qDebug() << balance;
            isLogged=true;
            if(id.toInt()==0)//消费者
            {
                buyerPtr = new buyer;
                ID = 0;
                buyerPtr->setUsername(user);
                buyerPtr->setPassword(pass);
                buyerPtr->setID(id.toInt());
                buyerPtr->setBalance(balance.toDouble());
            }
            if(id.toInt()==1)//商家
            {
                storePtr = new store;
                ID = 1;
                storePtr->setUsername(user);
                storePtr->setPassword(pass);
                storePtr->setID(id.toInt());
                storePtr->setBalance(balance.toDouble());
            }
            close();//关闭登录窗口
        }
    }
}


//析构函数
loginDialog::~loginDialog()
{
    delete ui;
}
/*void loginDialog::enableButton()
{
    bool bXok,bYok;
    ui->username->text().toDouble(&bXok);
    ui->password->text().toDouble(&bYok);
    ui->loginBox->setEnabled(bXok && bYok);
}*/
//处理ok
void loginDialog::onAccepted()
{
    //修改
    mSocket = new QUdpSocket();
    mSocket->bind(10002,QAbstractSocket::DontShareAddress);
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    QString MyData="0000" + ui->username->text() + ' ' + ui->password->text();
    mSocket->writeDatagram(MyData.toUtf8(),QHostAddress::LocalHost,10000);
    /*
    if(ui->username->text()==""||ui->password->text()=="")
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请输入账户名或密码",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    else
    {
    std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::out);
    if(!fs) {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "系统信息文件出错，请联系客服",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    std::string s1,s2;
    int id,tmp=0;
    double balance;
    while(fs >> s1 >> s2 >> id >> balance)
    {
        QString user = QString::fromStdString(s1);
        QString pass = QString::fromStdString(s2);
        if(ui->username->text()==user&&ui->password->text()==pass){
            QMessageBox msgBox(
                        QMessageBox::Information,//图标
                        "YES",//标题
                        "登陆成功",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
                msgBox.exec();
            qDebug() << "登陆成功";
            isLogged=true;
            if(id==0)//消费者
            {
                buyerPtr = new buyer;
                ID = 0;
                buyerPtr->setUsername(user);
                buyerPtr->setPassword(pass);
                buyerPtr->setID(id);
                buyerPtr->setBalance(balance);
            }
            if(id==1)//商家
            {
                storePtr = new store;
                ID = 1;
                storePtr->setUsername(user);
                storePtr->setPassword(pass);
                storePtr->setID(id);
                storePtr->setBalance(balance);
            }
                        close();//关闭登录窗口
                        tmp = 1;
        }
    }
    fs.close();
    if(tmp==0)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "用户名或密码错误",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
            msgBox.exec();
    }
    }
    */
}
//处理cancel
void loginDialog::onRejected()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "登录",
                "是否确定取消登录？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}
