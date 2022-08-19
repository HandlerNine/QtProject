#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_confirmbtn_clicked();

    void on_backbtn_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
