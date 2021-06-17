#ifndef ADDGOODSDIALOG_H
#define ADDGOODSDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class addgoodsDialog;
}

class addgoodsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addgoodsDialog(QWidget *parent = nullptr);
    ~addgoodsDialog();

private slots:
    void on_addButton_clicked();

    void on_cancleButton_clicked();

private:
    Ui::addgoodsDialog *ui;
};

#endif // ADDGOODSDIALOG_H
