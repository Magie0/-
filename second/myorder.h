#ifndef MYORDER_H
#define MYORDER_H

#include <QDialog>

namespace Ui {
class myorder;
}

class myorder : public QDialog
{
    Q_OBJECT

public:
    explicit myorder(QWidget *parent = nullptr);
    ~myorder();

private:
    Ui::myorder *ui;
    void initialize();
private slots:
    void cancleClicked();
    void payClicked();
};

#endif // MYORDER_H
