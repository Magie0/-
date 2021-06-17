#include "server.h"
#include<QSqlRecord>
#include <fstream>

using namespace std;
server::server()
{
    read=new QUdpSocket;
    read->bind(10000,QAbstractSocket::DontShareAddress);//绑定端口
    connect(read,SIGNAL(readyRead()),this,SLOT(readData()));//这里要注意，在接收到数据以后，readready()函数会被自动触发，你可以理解成按钮的click事件

    createDB();
    createTable();
    queryTable();
}

void server::readData()
{
    while (read->hasPendingDatagrams())
    {
        QByteArray MyDate;//因为传送来的数据类型是未知，所以用bytearray
        MyDate.resize(read->pendingDatagramSize());//mydata的数据大小取决于接收到的数据
        read->readDatagram(MyDate.data(),MyDate.size());//读取数据

        QString str = QString::fromUtf8(MyDate);
        string Str = str.toStdString();
        string messageID;
        if(str.size()>4)
        {
            for(int i=0;i<4;i++)
            {
                messageID = messageID + Str[i];
            }
        }
        qDebug() << "来自Client的报文："<< str;
        if(str=="展示商品")
        {
            int row = model.rowCount();
            for(int i=0;i<row;i++)
            {
                QString goodsinfo = model.record(i).value("id").toString() + '#' + model.record(i).value("name").toString()+ '#' + model.record(i).value("type").toString()+ '#' + model.record(i).value("price").toString()
                        + '#'+ model.record(i).value("surplus").toString() + '#'+ model.record(i).value("storename").toString() + '#'+ model.record(i).value("discount").toString() + '#'+ model.record(i).value("describe").toString();
                read->writeDatagram(goodsinfo.toUtf8(),QHostAddress::LocalHost,10001);
            }
        }
        else if(messageID=="0000")//登录消息
        {
            QString name,password = "";
            for(int i = 4;i<str.size();i++)
            {
                if(str[i]!=' ')
                {
                    name = name + str[i];
                }
                else
                {
                    for(int j = i+1;j<str.size();j++)
                    {
                        password = password + str[j];
                    }
                    break;
                }
            }
            qDebug() << name;
            qDebug() << password;
            onAccepted(name,password);
        }
        else if(messageID=="0001")
        {
            QString id,surplus;
            for(int i =4;i<str.size();i++)
            {
                if(str[i]!=' ')
                {
                    id = id + str[i];
                }
                else
                {
                    for(int j = i+1;j<str.size();j++)
                    {
                        surplus = surplus + str[j];
                    }
                    break;
                }
            }
            int ID = id.toInt();
            int Surplus = surplus.toInt();
            QSqlQuery query;
                    QString str =
                            QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(Surplus).arg(ID);
                    query.exec(str);
        }
        else if(messageID=="0010")
        {
            QString id,surplus;
            for(int i =4;i<str.size();i++)
            {
                if(str[i]!=' ')
                {
                    id = id + str[i];
                }
                else
                {
                    for(int j = i+1;j<str.size();j++)
                    {
                        surplus = surplus + str[j];
                    }
                    break;
                }
            }
            int ID = id.toInt();
            int Surplus = surplus.toInt();
            QSqlQuery query;
            QString str =
                    QString("UPDATE Goods SET surplus = %1 WHERE id = %2").arg(Surplus).arg(ID);
            query.exec(str);
        }
        else if(messageID=="0011")
        {
            QString name,Balance;
            for(int i =4;i<str.size();i++)
            {
                if(str[i]!=' ')
                {
                    name = name + str[i];
                }
                else
                {
                    for(int j = i+1;j<str.size();j++)
                    {
                        Balance = Balance + str[j];
                    }
                    break;
                }
            }
            double money = Balance.toDouble();
            std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
            std::string s1,s2;
            int id,n = 1;
            double balance;
            while(fs >> s1 >> s2 >> id >> balance)
            {
                QString User = QString::fromStdString(s1);
                if(name!=User){
                    n++;
                }
                else
                    break;
            }
            ifstream file("C:\\Users\\17375\\Desktop\\account.txt");
            string line;
            int count = 0;
            ofstream outfile("test.txt", ios::out | ios::trunc);
            while (!file.eof()) {
                getline(file, line);
                if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
                    outfile << line << endl;
                count++;
            }
            outfile.close();
            file.close();
            ofstream outfile1("C:\\Users\\17375\\Desktop\\account.txt", ios::out | ios::trunc);
            fstream file1("test.txt");
            while (!file1.eof()) {
                getline(file1, line);
                outfile1 << line ;
                if(!file1.eof()) outfile1<<"\n";
            }
            outfile1.close();
            file1.close();
            system("del test.txt");//删除中间文件
            //重新加入此用户的信息
            std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
            //fs1 << '\n';
            fs1 << s1 << ' ' << s2 << ' ' << id << ' ' << money;
            fs1.close();
        }
        else if(messageID=="0111")
        {
            QString name,Balance;
            for(int i =4;i<str.size();i++)
            {
                if(str[i]!=' ')
                {
                    name = name + str[i];
                }
                else
                {
                    for(int j = i+1;j<str.size();j++)
                    {
                        Balance = Balance + str[j];
                    }
                    break;
                }
            }
            double money = Balance.toDouble();
            std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
            std::string s1,s2;
            int id,n = 1;
            double balance;
            while(fs >> s1 >> s2 >> id >> balance)
            {
                QString User = QString::fromStdString(s1);
                if(name!=User){
                    n++;
                }
                else
                    break;
            }
            ifstream file("C:\\Users\\17375\\Desktop\\account.txt");
            string line;
            int count = 0;
            ofstream outfile("test.txt", ios::out | ios::trunc);
            while (!file.eof()) {
                getline(file, line);
                if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
                    outfile << line << endl;
                count++;
            }
            outfile.close();
            file.close();
            ofstream outfile1("C:\\Users\\17375\\Desktop\\account.txt", ios::out | ios::trunc);
            fstream file1("test.txt");
            while (!file1.eof()) {
                getline(file1, line);
                outfile1 << line ;
                if(!file1.eof()) outfile1<<"\n";
            }
            outfile1.close();
            file1.close();
            system("del test.txt");//删除中间文件
            //重新加入此用户的信息
            std::fstream fs1("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::app);
            //fs1 << '\n';
            balance = balance + money;
            fs1 << s1 << ' ' << s2 << ' ' << id << ' ' << balance;
            fs1.close();
        }
    }
}

void server::createDB()
{
    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Goods.db");
    //打开数据库
    if(db.open()==true)
        qDebug() << "打开成功";

}

void server::createTable()
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
}

void server::queryTable()
{
    // 构造一个查询数据表的sql语句
        QString str ("SELECT * FROM Goods");
        // 执行sql语句并保存结果到model
        model.setQuery (str);
}


void server::onAccepted(QString name,QString password)
{
    QString data;
    if(name==""||password=="")
    {
        data = "00";
        read->writeDatagram(data.toUtf8(),QHostAddress::LocalHost,10002);
        return;
    }
    else
    {
    std::fstream fs("C:\\Users\\17375\\Desktop\\account.txt",std::ios_base::in|std::ios::out);
    std::string s1,s2;
    int id,tmp=0;
    double balance;
    while(fs >> s1 >> s2 >> id >> balance)
    {
        QString user = QString::fromStdString(s1);
        QString pass = QString::fromStdString(s2);
        if(name==user&&password==pass){
            data = "11";
            QString ID  = QString::number(id);
            QString Balance  = QString::number(balance,10,5);
            data = data + user +' '+ pass +' ' + ID + ' ' + Balance;
            tmp = 1;
            read->writeDatagram(data.toUtf8(),QHostAddress::LocalHost,10002);
            return;
        }
    }
    fs.close();
    if(tmp==0)
    {
        data = "01";
        read->writeDatagram(data.toUtf8(),QHostAddress::LocalHost,10002);
        return;
    }
    }

}
