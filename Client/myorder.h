#ifndef MYORDER_H
#define MYORDER_H

#include <QDialog>
#include <QUdpSocket>

namespace Ui {
class myorder;
}

class myorder : public QDialog
{
    Q_OBJECT

public:
    explicit myorder(QWidget *parent = nullptr);
    ~myorder();

private:
    Ui::myorder *ui;
    void initialize();
private slots:
    void cancleClicked();
    void payClicked();

private:
    QUdpSocket *mSocket,*nSocket;//因为要在槽函数使用，因此这里在头文件进行定义
};

#endif // MYORDER_H
