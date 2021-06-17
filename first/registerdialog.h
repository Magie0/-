#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QMessageBox>//消息提示框
#include <QDebug>

namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();
public slots:
    void on_userBox_stateChanged(bool );
    void on_storeBox_stateChanged(bool );
    void enableButton();
    //处理注册按钮的槽函数
    void onRegister();
    //处理Cancle按钮的槽函数
    void onCancle();
private:
    Ui::registerDialog *ui;
};

#endif // REGISTERDIALOG_H
