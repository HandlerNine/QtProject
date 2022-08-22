#ifndef EMOJISELECT_H
#define EMOJISELECT_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class EmojiSelect;
}

class EmojiSelect : public QWidget
{
    Q_OBJECT

public:
    explicit EmojiSelect(QWidget *parent = 0);
    ~EmojiSelect();

private slots:
    void on_toolButton_clicked();

    void on_selectbtn_clicked();

    void on_confirmbtn_clicked();

private:
    Ui::EmojiSelect *ui;
};

#endif // EMOJISELECT_H
