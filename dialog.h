#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

#define BLACK  "background-color: rgb(0, 0, 0);""min-width: 30px; min-height: 30px;""max-width:30px; max-height: 30px;""border-radius: 15px;  border:1px solid black;"
#define WHITE "background-color: rgb(255, 255, 255);""min-width: 30px; min-height: 30px;""max-width:30px; max-height: 30px;""border-radius: 15px;  border:1px solid black;"
#define TRANSPARENT "background: transparent;""min-width: 30px; min-height: 30px;""max-width:30px; max-height: 30px;""border-radius: 15px;"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:

    void Button_pressed_event();

    void Victory_or_defeat();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

    QList<QPushButton * > list_button;

    QString please_man;
};

#endif // DIALOG_H
