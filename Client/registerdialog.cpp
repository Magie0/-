#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <fstream>
registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    //信号和槽的连接
    connect(ui->userBox,SIGNAL(toggled(bool)),this,SLOT(on_userBox_stateChanged(bool)));
    connect(ui->storeBox,SIGNAL(toggled(bool)),this,SLOT(on_storeBox_stateChanged(bool)));
    connect(ui->new_username,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    connect(ui->new_password,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    connect(ui->new_password2,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    connect(ui->userBox,SIGNAL(toggled(bool)),this,SLOT(enableButton()));
    connect(ui->storeBox,SIGNAL(toggled(bool)),this,SLOT(enableButton()));
    connect(ui->registerButton,SIGNAL(clicked()),this,SLOT(onRegister()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(onCancle()));
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::on_userBox_stateChanged(bool arg1)
{
    if(arg1){
            ui->storeBox->setCheckState(Qt::Unchecked);
    }
}

void registerDialog::on_storeBox_stateChanged(bool arg1)
{
    if(arg1){
            ui->userBox->setCheckState(Qt::Unchecked);
    }
}

void registerDialog::enableButton()
{
    bool bXok,bYok,bY2ok;
    bXok = ui->new_username->text()!="";
    ui->new_password->text().toDouble(&bYok);
    ui->new_password2->text().toDouble(&bY2ok);
    bool bZok = ui->userBox->isChecked() || ui->storeBox->isChecked();
    ui->registerButton->setEnabled(bXok && bYok && bY2ok && bZok);
}

void registerDialog::onRegister()
{
    //用户名和密码中是否有空格
    QString user = ui->new_username->text();
    QString pass = ui->new_password->text();
    QString pass2 = ui->new_password2->text();
    bool type = 0;
    if(ui->storeBox->isChecked())
        type = 1;
    int tmp = 0;
    for(int i =0;i<user.size();i++)
        if(user[i]==' ')
            tmp = 1;
    for(int i =0;i<pass.size();i++)
        if(pass[i]==' ')
            tmp = 1;
    for(int i =0;i<pass2.size();i++)
        if(pass2[i]==' ')
            tmp = 1;
    if(tmp==1)
    {
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "用户名和密码中含有空格",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
            msgBox.exec();
    }
    //用户名是否已存在
    std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
    if(!fs) {
        tmp = 1;
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "系统信息文件出错，请联系客服",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    std::string s1,s2;
    int id;
    double balance;
    while(fs >> s1 >> s2 >> id >> balance)
    {
        QString User = QString::fromStdString(s1);
        if(ui->new_username->text()==User){
            tmp = 1;
            QMessageBox msgBox(
                        QMessageBox::Critical,//图标
                        "Error",//标题
                        "该用户名已存在，请重新选取",//提示消息
                        QMessageBox::Ok,//按钮
                        this);//父窗口
            msgBox.exec();
        }
    }
    fs.close();
    //密码和确认密码是否一样
    if(tmp==0&&pass!=pass2)
    {
        tmp = 1;
        QMessageBox msgBox(
                    QMessageBox::Critical,//图标
                    "Error",//标题
                    "两次密码不相同，请重新输入",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
    }
    //将用户名 密码 用户类型存入文件
    if(tmp==0)
    {
        std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
        fs1 << '\n';
        std::string suser = user.toStdString();
        std::string spass = pass.toStdString();
        fs1 << suser << ' ' << spass << ' ' << type << ' ' << 0;
        fs1.close();
        QMessageBox msgBox(
                    QMessageBox::Information,//图标
                    "OK",//标题
                    "注册成功",//提示消息
                    QMessageBox::Ok,//按钮
                    this);//父窗口
        msgBox.exec();
        close();
    }
}

void registerDialog::onCancle()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                "注册",
                "是否确定取消注册？",
                QMessageBox::Yes|QMessageBox::No,
                this);
    if(msgBox.exec() == QMessageBox::Yes){
        close();
    }
}

