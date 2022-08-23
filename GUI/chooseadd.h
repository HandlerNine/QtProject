#ifndef CHOOSEADD_H
#define CHOOSEADD_H

#include <QWidget>

namespace Ui {
class chooseadd;
}

class chooseadd : public QWidget
{
    Q_OBJECT

public:
    explicit chooseadd(QWidget *parent = 0);
    ~chooseadd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void sendChooseAddSignal(int tag);

private:
    Ui::chooseadd *ui;
};

#endif // CHOOSEADD_H
