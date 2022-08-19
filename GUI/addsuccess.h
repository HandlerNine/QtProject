#ifndef ADDSUCCESS_H
#define ADDSUCCESS_H

#include <QWidget>

namespace Ui {
class addsuccess;
}

class addsuccess : public QWidget
{
    Q_OBJECT

public:
    explicit addsuccess(QWidget *parent = 0);
    ~addsuccess();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addsuccess *ui;
};

#endif // ADDSUCCESS_H
