#include "account.h"
QString account::getUsername() const{
    return this->username;
}

void account::setUsername(QString username){
    this->username=username;
}

QString account::getPassword() const{
    return this->password;
}

void account::setPassword(QString password){
    this->password=password;
}


void account::setID(int id){
    this->id=id;
}

double account::getBalance() const{
    return this->balance;
}

void account::setBalance(double balance){
    this->balance=balance;
}

void account::addBalance(double add){
    this->balance+=add;
}

bool account::subBalance(double sub){
    if(this->balance<sub)
        return false;
    else{
        this->balance-=sub;
        return true;
    }
}

buyer::buyer():account(0,0,0,0)
{ }

int buyer::getUserType(){
    return this->id;
}

store::store():account(0,0,0,0)
{ }

int store::getUserType(){
    return this->id;
}
