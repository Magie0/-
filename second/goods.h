#ifndef GOODS_H
#define GOODS_H

#include <QString>

class goods
{
protected:
    int id;//ID
    QString name;//商品名
    double price;//价格
    int surplus;//剩余量
    QString storename;//商家姓名
    double discount;
    int buynumber;//购买数量

public:
    goods();
    goods(QString s1,double p1,int i1):name(s1),price(p1),surplus(i1)
    {};
    virtual double getPrice() = 0;
    void setPrice(double);
    QString getName() const;
    void setName(QString);
    int getSurplus() const;
    void setSurplus(int);
    QString getStorename() const;
    void setStorename(QString);
    int getID() const;
    void setID(int);
    double getDiscount() const;
    void setDiscount(double);
    int getBuynumber() const;
    void setBuynumber(int);
};

class books:public goods
{
public:
    virtual double  getPrice() override;
};

class food:public goods
{
public:
    virtual double  getPrice() override;
};

class dress:public goods
{
public:
    virtual double  getPrice() override;
};

#endif // GOODS_H
