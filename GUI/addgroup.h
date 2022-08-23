#ifndef ADDGROUP_H
#define ADDGROUP_H

#include <QWidget>

#include <./Entity/grouplist.h>

namespace Ui {
class addgroup;
}

class addgroup : public QWidget
{
    Q_OBJECT

public:
    explicit addgroup(QWidget *parent = 0);
    ~addgroup();
    grouplist grplst;

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

signals:
    void sendGroup(QString name);

private:
    Ui::addgroup *ui;
};

#endif // ADDGROUP_H
