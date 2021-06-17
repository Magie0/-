#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDialog>
#include <QMessageBox>//消息提示框
#include <QDebug>
#include <QTableWidgetItem>
namespace Ui {
class shoppingcart;
}

class shoppingcart : public QDialog
{
    Q_OBJECT

public:
    explicit shoppingcart(QWidget *parent = nullptr);
    ~shoppingcart();

private:
    Ui::shoppingcart *ui;
    void initialize();

private slots:
    void OnDeleteClicked();
    void dataChanged(QTableWidgetItem*);
    void on_buyButton_clicked();
    void stateChanged(int);
    void on_orderButton_clicked();
    void on_freshButton_clicked();
};

#endif // SHOPPINGCART_H
