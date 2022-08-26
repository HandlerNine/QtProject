#ifndef ADDFAIL_H
#define ADDFAIL_H

#include <QDialog>

namespace Ui {
class AddFail;
}

class AddFail : public QDialog
{
    Q_OBJECT

public:
    explicit AddFail(QWidget *parent = 0);
    ~AddFail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddFail *ui;
};

#endif // ADDFAIL_H
