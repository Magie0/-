#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

/*
 * 其中默认构造函数直接使用C++11标准，account()=default */

class account{
protected:
    QString username;       //用户名
    QString password;       //密码
    int id;                 //id==0为消费者，id==1为商家
    double balance;          //账户余额

public:
    /* 构造函数 */
    account();
    account(QString s1, QString s2, int i1, float f1):username(s1),password(s2),id(i1),balance(f1)
{}
    /* 私有成员的get/set函数 */
   QString getUsername() const;
   void setUsername(QString username);
   QString getPassword()const;
   void setPassword(QString password);
   //int getID();
   void setID(int id);
   virtual int getUserType() = 0;
   double getBalance() const;
   void setBalance(double balance);
   /* addBanlance和subBalance提供对账户余额的直接增减 */
   void addBalance(double add);
   bool subBalance(double sub);
};

class buyer:public account{
public:
    buyer();
    virtual int getUserType() override;
};
class store:public account{
public:
    store();
    virtual int getUserType() override;
};

#endif // ACCOUNT_H
