#ifndef SEARCHGOODSDIALOG_H
#define SEARCHGOODSDIALOG_H

#include <QDialog>
#include <QMessageBox>//消息提示框
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>


namespace Ui {
class searchgoodsDialog;
}

class searchgoodsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchgoodsDialog(QWidget *parent = nullptr);
    ~searchgoodsDialog();

private slots:
    //void enable1Button();
    //void enable2Button();
    void on_searchButton_clicked();

    void on_sortButton_clicked();

    void on_searchcomboBox_currentTextChanged(const QString &arg1);

    void on_cancelButton_clicked();

private:
    Ui::searchgoodsDialog *ui;
private:
    void queryTable();
    QSqlQueryModel model;
};

#endif // SEARCHGOODSDIALOG_H
