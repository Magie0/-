#ifndef LOGIN_H
#define LOGIN_H
#include "ui_loginDialog.h"
#include <QMessageBox>//消息提示框
#include <QDebug>

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
};

#endif // LOGIN_H
