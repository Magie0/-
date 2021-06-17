#ifndef MANAGEGOODSDIALOG_H
#define MANAGEGOODSDIALOG_H

#include <QDialog>
#include <QMessageBox>//消息提示框

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class managegoodsDialog;
}

class managegoodsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit managegoodsDialog(QWidget *parent = nullptr);
    ~managegoodsDialog();

private slots:
    void enable1Button();
    void enable2Button();
    void enable3Button();
    void queryTable();

    void on_priceokButton_clicked();

    void on_numokButton_clicked();

    void on_cancelButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::managegoodsDialog *ui;
    QSqlQueryModel model; // 保存和遍历查询结果
};

#endif // MANAGEGOODSDIALOG_H
