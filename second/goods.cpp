#include "goods.h"

goods::goods()
{

}

QString goods::getName() const
{
    return this->name;
}

void goods::setName(QString name)
{
    this->name = name;
}

void goods::setPrice(double price)
{
    this->price = price;
}

int goods::getSurplus() const
{
    return this->surplus;
}

void goods::setSurplus(int surplus)
{
    this->surplus = surplus;
}

QString goods::getStorename() const
{
    return this->storename;
}

void goods::setStorename(QString storename)
{
    this->storename = storename;
}

int goods::getID() const
{
    return this->id;
}

void goods::setID(int id)
{
    this->id = id;
}

double goods::getDiscount() const
{
    return this->discount;
}

void goods::setDiscount(double discount)
{
    this->discount = discount;
}

void goods::setBuynumber(int buynumber)
{
    this->buynumber = buynumber;
}

int goods::getBuynumber() const
{
    return this->buynumber;
}

double books::getPrice()
{
    return this->price;
}

double food::getPrice()
{
    return this->price;
}

double dress::getPrice()
{
    return this->price;
}
