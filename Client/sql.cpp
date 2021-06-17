#include "sql.h"

sql::sql()
{

}

void sql::createDB()
{
    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Goods.db");
    //打开数据库
    if(db.open()==true)
        qDebug() << "打开成功";

}

void sql::createTable()
{
    QSqlQuery query;
    QString str = QString("CREATE TABLE Goods ("
                          "id INT PRIMARY KEY NOT NULL,"
                          "type TEXT NOT NULL,"
                          "name TEXT NOT NULL,"
                          "price REAL NOT NULL,"
                          "surplus INT NOT NULL,"
                          "storename TEXT NOT NULL,"
                          "discount REAL NOT NULL,"
                          "describe TEXT)");
     if(query.exec(str) == true)
         qDebug() << "TableOK";
     else
         qDebug() << "cao";
}

void sql::queryTable()
{
    // 构造一个查询数据表的sql语句
        QString str ("SELECT * FROM Goods");
        // 执行sql语句并保存结果到model
        model.setQuery (str);
        // 显示结果到ui
        //ui->tableView->setModel (&model);
}
