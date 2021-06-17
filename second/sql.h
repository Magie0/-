#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class sql
{
public:
    sql();

private:
    //创建数据库
    void createDB();
    //创建数据表
    void createTable();
    //查询
    void queryTable();
    QSqlDatabase db; // 建立QT程序和数据的连接
    QSqlQueryModel model; // 保存和遍历查询结果
};

#endif // SQL_H
