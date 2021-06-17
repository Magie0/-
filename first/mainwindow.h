#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_discountButton_clicked();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_passwordButton_clicked();

    void on_managebalanceButton_clicked();

    void on_searchButton_clicked();

    void on_addgoodsButton_clicked();

    void on_managegoodsButton_clicked();

    void on_cancelloginButton_clicked();

    void on_freshButton_clicked();

private:
    Ui::MainWindow *ui;
    //创建数据库
    void createDB();
    //创建数据表
    void createTable();
    //查询
    void queryTable();

private:
    QSqlDatabase db; // 建立QT程序和数据的连接
    QSqlQueryModel model; // 保存和遍历查询结果
};
#endif // MAINWINDOW_H
