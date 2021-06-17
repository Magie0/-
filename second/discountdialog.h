#ifndef DISCOUNTDIALOG_H
#define DISCOUNTDIALOG_H

#include <QDialog>

#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class discountDialog;
}

class discountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit discountDialog(QWidget *parent = nullptr);
    ~discountDialog();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::discountDialog *ui;
};

#endif // DISCOUNTDIALOG_H
