#include "creatobjects.h"
#include "goods.h"
#include<QSqlRecord>
#include <list>

using namespace std;

extern vector<books> books;//商品
extern vector<dress> dress;
extern vector<food> food;

creatobjects::creatobjects()
{
    // 构造一个查询数据表的sql语句
    qDebug() << "这里执行了";
    QString str ("SELECT * FROM Goods");
    // 执行sql语句并保存结果到model
    model.setQuery (str);
    //int column = model.columnCount();
    int row = model.rowCount();
    for(int i=0;i<row;i++)
    {
        if(model.record(i).value("type")=="books")
        {
            class books Book;
            Book.setID(model.record(i).value("id").toInt());
            Book.setName(model.record(i).value("name").toString());
            Book.setPrice(model.record(i).value("price").toDouble());
            Book.setSurplus(model.record(i).value("surplus").toInt());
            Book.setStorename(model.record(i).value("storename").toString());
            Book.setDiscount(model.record(i).value("discount").toDouble());
            books.push_back(Book);
        }
        else if(model.record(i).value("type")=="dress")
        {
            class dress Dress;
            Dress.setID(model.record(i).value("id").toInt());
            Dress.setName(model.record(i).value("name").toString());
            Dress.setPrice(model.record(i).value("price").toDouble());
            Dress.setSurplus(model.record(i).value("surplus").toInt());
            Dress.setStorename(model.record(i).value("storename").toString());
            Dress.setDiscount(model.record(i).value("discount").toDouble());
            dress.push_back(Dress);
        }
        else if(model.record(i).value("type")=="food")
        {
            class food Food;
            Food.setID(model.record(i).value("id").toInt());
            Food.setName(model.record(i).value("name").toString());
            Food.setPrice(model.record(i).value("price").toDouble());
            Food.setSurplus(model.record(i).value("surplus").toInt());
            Food.setStorename(model.record(i).value("storename").toString());
            Food.setDiscount(model.record(i).value("discount").toDouble());
            food.push_back(Food);
        }
    }
}
