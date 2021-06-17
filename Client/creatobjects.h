#ifndef CREATOBJECTS_H
#define CREATOBJECTS_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class creatobjects
{
public:
    creatobjects();
private:
    QSqlQueryModel model; // 保存和遍历查询结果
};

#endif // CREATOBJECTS_H
