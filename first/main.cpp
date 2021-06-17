#include "mainwindow.h"
#include "loginDialog.h"
#include "registerdialog.h"
#include "account.h"
#include "changepassworddialog.h"
#include "addgoodsdialog.h"
#include "searchgoodsdialog.h"
#include <QApplication>

bool isLogged=false;
buyer* buyerPtr;
store* storePtr;
int ID = 0;
double Discount = 10;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
