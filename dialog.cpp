#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    please_man = "黑";

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            QPushButton * pu = new QPushButton(ui->label_board);
            pu->setStyleSheet(TRANSPARENT);
            pu->setGeometry(10 + 39 * j, 10 + 39 * i, 40, 40);
            list_button << pu;
        }
    }
    for(int i = 0; i < list_button.length(); i++){
        list_button[i]->show();
        connect(list_button[i],SIGNAL(clicked()),this,SLOT(Button_pressed_event()));
        //        list_button[i]->setText(QString::number(i));
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Button_pressed_event()
{
    if(please_man == "黑"){
        for(int i = 0; i < list_button.length(); i++){
            if(list_button[i]->hasFocus()){
                list_button[i]->setStyleSheet(BLACK);
            }
        }
        please_man = "白";
    }
    else if(please_man == "白"){
        for(int i = 0; i < list_button.length(); i++){
            if(list_button[i]->hasFocus()){
                list_button[i]->setStyleSheet(WHITE);
            }
        }
        please_man = "黑";
    }
    Victory_or_defeat();
}

void Dialog::Victory_or_defeat()
{
    /*判断胜负*/
    if(please_man == "黑"){  //判断白棋
        QList<int > list;
        for(int i = 0; i < list_button.length(); i++){
            if(list_button[i]->styleSheet() == WHITE){
                list << i;
            }
        }
        for(int a = 0; a < list.length(); a++){
            for(int b = 0; b < list.length(); b++){
                if(list[b] - list[a] == 1){  //横向
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == 1){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == 1){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == 1){
                                            ui->label->setText("白方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(list[b] - list[a] == 15){  //纵向
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == 15){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == 15){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == 15){
                                            ui->label->setText("白方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(list[b] - list[a] == 16){  //右斜
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == 16){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == 16){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == 16){
                                            ui->label->setText("白方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(list[b] - list[a] == -14){  //左斜
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == -14){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == -14){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == -14){
                                            ui->label->setText("白方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    else if(please_man == "白"){  //判断黑棋
        QList<int > list;
        for(int i = 0; i < list_button.length(); i++){
            if(list_button[i]->styleSheet() == BLACK){
                list << i;
            }
        }
        for(int a = 0; a < list.length(); a++){
            for(int b = 0; b < list.length(); b++){
                if(list[b] - list[a] == 1){  //横向
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == 1){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == 1){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == 1){
                                            ui->label->setText("黑方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(list[b] - list[a] == 15){  //纵向
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == 15){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == 15){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == 15){
                                            ui->label->setText("黑方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(list[b] - list[a] == 16){  //右斜
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == 16){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == 16){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == 16){
                                            ui->label->setText("黑方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(list[b] - list[a] == -14){  //左斜
                    for(int c = 0; c < list.length(); c++){
                        if(list[c] - list[b] == -14){
                            for(int d = 0; d < list.length(); d++){
                                if(list[d] - list[c] == -14){
                                    for(int e = 0; e < list.length(); e++){
                                        if(list[e] - list[d] == -14){
                                            ui->label->setText("黑方胜");
                                            please_man = "结束";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


}


void Dialog::on_pushButton_clicked()
{
    please_man = "黑";
    for(int i = 0; i < list_button.length(); i++){
        list_button[i]->setStyleSheet(TRANSPARENT);
    }
    ui->label->setText("黑棋先行");
}

