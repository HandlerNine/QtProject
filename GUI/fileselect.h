#ifndef FILESELECT_H
#define FILESELECT_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class FileSelect;
}

class FileSelect : public QWidget
{
    Q_OBJECT

public:
    explicit FileSelect(QWidget *parent = 0);
    ~FileSelect();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_selectbtn_clicked();

    void on_confirmbtn_clicked();

private:
    Ui::FileSelect *ui;
};

#endif // FILESELECT_H
