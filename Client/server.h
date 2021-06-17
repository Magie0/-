#ifndef SERVER_H
#define SERVER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>//消息提示框

#include <QUdpSocket>

class server:public QObject
{
    Q_OBJECT
public:
    server();

private:
    //创建数据库
    void createDB();
    //创建数据表
    void createTable();
    //查询
    void queryTable();


private:
    QUdpSocket *read;//因为要在槽函数使用，因此这里在头文件进行定义
    void onAccepted(QString,QString);

private slots:
    void readData();//槽函数用于对接受的数据进行处理

private:
    QSqlDatabase db; // 建立QT程序和数据的连接
    QSqlQueryModel model; // 保存和遍历查询结果
};

#endif // SERVER_H
