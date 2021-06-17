#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>
#include <QMessageBox>//消息提示框

namespace Ui {
class changePasswordDialog;
}

class changePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changePasswordDialog(QWidget *parent = nullptr);
    ~changePasswordDialog();

private slots:
    void on_okButton_clicked();

    void on_cancleButton_clicked();

private:
    Ui::changePasswordDialog *ui;
};

#endif // CHANGEPASSWORDDIALOG_H
