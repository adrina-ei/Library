#include "closeboy.h"
#include "ui_closeboy.h"

closeBoy::closeBoy(QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::closeBoy)
{
    ui->setupUi(this);

    //Transfer main
    this->qMain = main;
}

//Dragable
void closeBoy::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void closeBoy::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

closeBoy::~closeBoy()
{
    delete ui;
}

//Close and menu
void closeBoy::on_pushButton_clicked()
{
    this->close();
}

void closeBoy::on_pushButton_2_clicked()
{
    qMain->show();
    this->close();
}

