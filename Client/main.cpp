#include "mainwindow.h"
#include "loginDialog.h"
#include "registerdialog.h"
#include "account.h"
#include "goods.h"
#include "changepassworddialog.h"
#include "addgoodsdialog.h"
#include "searchgoodsdialog.h"
#include "server.h"
#include <QDebug>
#include <QApplication>

using namespace std;

bool isLogged=false;
buyer* buyerPtr;
store* storePtr;
int ID = 0;
double Discount = 10;
vector<books> books,cartbooks;//商品
vector<dress> dress,cartdress;
vector<food> food,cartfood;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server s;
    MainWindow w;
    w.show();
    return a.exec();
}
