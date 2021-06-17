#include "manageaccountdialog.h"
#include "ui_manageaccountdialog.h"
#include "account.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QDebug>

using namespace std;

extern bool isLogged;
extern buyer* buyerPtr;
extern store* storePtr;
extern int ID;

manageAccountDialog::manageAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageAccountDialog)
{
    ui->setupUi(this);
    if(isLogged&&ID==0)
    {
        ui->nameLabel->setText(buyerPtr->getUsername());
        ui->balanceLabel->setNum(buyerPtr->getBalance());
    }
    else if(isLogged&&ID==1)
    {
        ui->nameLabel->setText(storePtr->getUsername());
        ui->balanceLabel->setNum(storePtr->getBalance());
    }
    connect(ui->investNum,SIGNAL(textChanged(QString)),this,SLOT(enable1Button()));
    connect(ui->consumeNum,SIGNAL(textChanged(QString)),this,SLOT(enable2Button()));
}

manageAccountDialog::~manageAccountDialog()
{
    delete ui;
}

void manageAccountDialog::enable1Button()
{
    bool bXok;
    ui->investNum->text().toDouble(&bXok);
    ui->investButton->setEnabled(bXok);
}

void manageAccountDialog::enable2Button()
{
    bool bXok;
    ui->consumeNum->text().toDouble(&bXok);
    ui->consumeButton->setEnabled(bXok);
}

void manageAccountDialog::on_investButton_clicked()
{
    if(isLogged&&ID==0)
    {
        buyerPtr->addBalance(ui->investNum->text().toDouble());
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "恭喜你,充值成功!",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
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
        int id,n = 1;
        double balance;
        while(fs >> s1 >> s2 >> id >> balance)
        {
            QString User = QString::fromStdString(s1);
            if(buyerPtr->getUsername()!=User){
                n++;
            }
            else
                break;
        }
        qDebug() << n;
        ifstream file("C:\\Users\\17375\\Desktop\\account.txt");
        string line;
        int count = 0;
        ofstream outfile("test.txt", ios::out | ios::trunc);
        while (!file.eof()) {
            getline(file, line);
            if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
                outfile << line << endl;
            count++;
        }
        outfile.close();
        file.close();
        ofstream outfile1("C:\\Users\\17375\\Desktop\\account.txt", ios::out | ios::trunc);
        fstream file1("test.txt");
        while (!file1.eof()) {
            getline(file1, line);
            outfile1 << line;
            if(!file1.eof()) outfile1<<"\n";
        }
        outfile1.close();
        file1.close();
        system("del test.txt");//删除中间文件
        //重新加入此用户的信息
        std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
        //fs1 << '\n';
        fs1 << s1 << ' ' << s2 << ' ' << id << ' ' << buyerPtr->getBalance();
        fs1.close();
    }
    else if(isLogged&&ID==1)
    {
        storePtr->addBalance(ui->investNum->text().toDouble());
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "恭喜你,充值成功!",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
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
        int id,n = 1;
        double balance;
        while(fs >> s1 >> s2 >> id >> balance)
        {
            QString User = QString::fromStdString(s1);
            if(storePtr->getUsername()!=User){
                n++;
            }
            else
                break;
        }
        qDebug() << n;
        ifstream file("C:\\Users\\17375\\Desktop\\account.txt");
        string line;
        int count = 0;
        ofstream outfile("test.txt", ios::out | ios::trunc);
        while (!file.eof()) {
            getline(file, line);
            if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
                outfile << line << endl;
            count++;
        }
        outfile.close();
        file.close();
        ofstream outfile1("C:\\Users\\17375\\Desktop\\account.txt", ios::out | ios::trunc);
        fstream file1("test.txt");
        while (!file1.eof()) {
            getline(file1, line);
            outfile1 << line;
            if(!file1.eof()) outfile1<<"\n";
        }
        outfile1.close();
        file1.close();
        system("del test.txt");//删除中间文件
        //重新加入此用户的信息
        std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
        //fs1 << '\n';
        fs1 << s1 << ' ' << s2 << ' ' << id << ' ' << storePtr->getBalance();
        fs1.close();
    }
    else
    {
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "Error",//标题
                    "充值失败，请重试",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    //更新状态
    if(isLogged&&ID==0)
    {
        //ui->nameLabel->setText(buyerPtr->getUsername());
        ui->balanceLabel->setNum(buyerPtr->getBalance());
    }
    else if(isLogged&&ID==1)
    {
        //ui->nameLabel->setText(storePtr->getUsername());
        ui->balanceLabel->setNum(storePtr->getBalance());
    }
    //更新到文件中

    ui->investNum->setText("");
}

void manageAccountDialog::on_consumeButton_clicked()
{
    if(isLogged&&ID==0)
    {
        if(buyerPtr->subBalance(ui->consumeNum->text().toDouble()))
        {
            QMessageBox msgBox(
                        QMessageBox::Information,//图标
                        "YES",//标题
                        "恭喜你,消费成功!",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
            std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
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
            int id,n = 1;
            double balance;
            while(fs >> s1 >> s2 >> id >> balance)
            {
                QString User = QString::fromStdString(s1);
                if(buyerPtr->getUsername()!=User){
                    n++;
                }
                else
                    break;
            }
            qDebug() << n;
            ifstream file("C:\\Users\\17375\\Desktop\\account.txt");
            string line;
            int count = 0;
            ofstream outfile("test.txt", ios::out | ios::trunc);
            while (!file.eof()) {
                getline(file, line);
                if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
                    outfile << line << endl;
                count++;
            }
            outfile.close();
            file.close();
            ofstream outfile1("C:\\Users\\17375\\Desktop\\account.txt", ios::out | ios::trunc);
            fstream file1("test.txt");
            while (!file1.eof()) {
                getline(file1, line);
                outfile1 << line ;
                if(!file1.eof()) outfile1<<"\n";
            }
            outfile1.close();
            file1.close();
            system("del test.txt");//删除中间文件
            //重新加入此用户的信息
            std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
            //fs1 << '\n';
            fs1 << s1 << ' ' << s2 << ' ' << id << ' ' << buyerPtr->getBalance();
            fs1.close();
        }
        else
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "您的余额不足，请先充值",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
    }
    else if(isLogged&&ID==1)
    {
        if(storePtr->subBalance(ui->consumeNum->text().toDouble()))
        {
            QMessageBox msgBox(
                        QMessageBox::Information,//图标
                        "YES",//标题
                        "恭喜你,消费成功!",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
            std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
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
            int id,n = 1;
            double balance;
            while(fs >> s1 >> s2 >> id >> balance)
            {
                QString User = QString::fromStdString(s1);
                if(storePtr->getUsername()!=User){
                    n++;
                }
                else
                    break;
            }
            qDebug() << n;
            ifstream file("C:\\Users\\17375\\Desktop\\account.txt");
            string line;
            int count = 0;
            ofstream outfile("test.txt", ios::out | ios::trunc);
            while (!file.eof()) {
                getline(file, line);
                if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
                    outfile << line << endl;
                count++;
            }
            outfile.close();
            file.close();
            ofstream outfile1("C:\\Users\\17375\\Desktop\\account.txt", ios::out | ios::trunc);
            fstream file1("test.txt");
            while (!file1.eof()) {
                getline(file1, line);
                outfile1 << line ;
                if(!file1.eof()) outfile1<<"\n";
            }
            outfile1.close();
            file1.close();
            system("del test.txt");//删除中间文件
            //重新加入此用户的信息
            std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
            //fs1 << '\n';
            fs1 << s1 << ' ' << s2 << ' ' << id << ' ' << storePtr->getBalance();
            fs1.close();
        }
        else
        {
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "您的余额不足，请先充值",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "Error",//标题
                    "消费失败，请重试",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    //更新状态
    if(isLogged&&ID==0)
    {
        //ui->nameLabel->setText(buyerPtr->getUsername());
        ui->balanceLabel->setNum(buyerPtr->getBalance());
    }
    else if(isLogged&&ID==1)
    {
        //ui->nameLabel->setText(storePtr->getUsername());
        ui->balanceLabel->setNum(storePtr->getBalance());
    }
    //更新到文件中

    ui->consumeNum->setText("");
}

void manageAccountDialog::on_pushButton_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "充值消费",
                "是否确定退出充值和消费？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}
