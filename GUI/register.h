#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_confirmbtn_clicked();

    void on_backbtn_clicked();


    void on_toolButton_2_clicked();

    void on_toolButton_clicked();


private:
    Ui::Register *ui;
    QPoint m_point;
};

#endif // REGISTER_H
