#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"
#include <fstream>
#include "account.h"
#include <string>
#include <iostream>
#include <QDebug>

using namespace std;

extern bool isLogged;
extern buyer* buyerPtr;
extern store* storePtr;
extern int ID;
changePasswordDialog::changePasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePasswordDialog)
{
        ui->setupUi(this);
    if(ID==1)
        ui->nameLabel->setText(storePtr->getUsername());
    else if(ID==0)
        ui->nameLabel->setText(buyerPtr->getUsername());
}

changePasswordDialog::~changePasswordDialog()
{
    delete ui;
}

void changePasswordDialog::on_okButton_clicked()
{
    //判断是否有空格
    QString pass = ui->newpassword->text();
    QString pass2 = ui->newpassword2->text();
    int tmp = 0;
    for(int i =0;i<pass.size();i++)
        if(pass[i]==' ')
            tmp = 1;
    for(int i = 0;i<pass.size();i++)
        if(pass[i]==' ')
            tmp = 1;
    if(tmp==1)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "请不要输入空格",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    //判断两次密码是否相等
    if(tmp==0&&pass!=pass2)
    {
        tmp = 1;
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "两次密码不相等，请重新输入",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    //修改密码
    if(tmp==0)
    {
        QString user;
        if(ID==1)
        {
            user = storePtr->getUsername();
            storePtr->setPassword(pass);
        }
        else if(ID==0)
        {
            user = buyerPtr->getUsername();
            buyerPtr->setPassword(pass);
        }
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
            if(user!=User){
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
        std::string spass = pass.toStdString();
        fs1 << s1 << ' ' << spass << ' ' << id << ' ' << balance;
        fs1.close();
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "YES",//标题
                    "修改成功!",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        ui->newpassword->setText("");
        ui->newpassword2->setText("");
    }
}

void changePasswordDialog::on_cancleButton_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "修改密码",
                "是否确定取消修改密码？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}
