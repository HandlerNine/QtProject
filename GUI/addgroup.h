#ifndef ADDGROUP_H
#define ADDGROUP_H

#include <QWidget>

#include "Entity/grouplist.h"
#include "Entity/added_group.h"
#include "GUI/addsuccess.h"


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
    void sendGroup(QString GroupID);

private:
    Ui::addgroup *ui;
};

#endif // ADDGROUP_H
