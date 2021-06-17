#include "mainwindow.h"
#include "loginDialog.h"
#include "registerdialog.h"
#include "account.h"
#include "goods.h"
#include "changepassworddialog.h"
#include "addgoodsdialog.h"
#include "searchgoodsdialog.h"
#include "myorder.h"
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
    MainWindow w;
    w.show();
    //a.connect(&a, SIGNAL(lastWindowClosed()),new myorder,SLOT(cancleClicked()));
    return a.exec();
}
