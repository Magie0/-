#ifndef LOGIN_H
#define LOGIN_H
#include "ui_loginDialog.h"
#include <QMessageBox>//消息提示框
#include <QDebug>

#include <QUdpSocket>

class loginDialog:public QDialog {
    Q_OBJECT
public:
    loginDialog();
    ~loginDialog();
public slots:
    //ok使能
    //void enableButton();
    //处理OK按钮的槽函数
    void onAccepted();
    //处理Cancle按钮的槽函数
    void onRejected();
private:
    Ui::loginDialog *ui;

private:
    QUdpSocket *mSocket;//因为要在槽函数使用，因此这里在头文件进行定义

public slots:
    void readData();//槽函数用于对接受的数据进行处理
};

#endif // LOGIN_H
