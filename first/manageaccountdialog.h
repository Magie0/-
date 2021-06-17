#ifndef MANAGEACCOUNTDIALOG_H
#define MANAGEACCOUNTDIALOG_H

#include <QDialog>
#include <QMessageBox>//消息提示框

namespace Ui {
class manageAccountDialog;
}

class manageAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit manageAccountDialog(QWidget *parent = nullptr);
    ~manageAccountDialog();

private slots:
    void enable1Button();
    void enable2Button();
    void on_investButton_clicked();

    void on_consumeButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::manageAccountDialog *ui;
};

#endif // MANAGEACCOUNTDIALOG_H
