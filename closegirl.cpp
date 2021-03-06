#include "closegirl.h"
#include "ui_closegirl.h"

closeGirl::closeGirl(QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::closeGirl)
{
    ui->setupUi(this);

    //Transfer main
    this->qMain = main;
}

closeGirl::~closeGirl()
{
    delete ui;
}

//Dragable
void closeGirl::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void closeGirl::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

//Close and menu
void closeGirl::on_pushButton_clicked()
{
    this->close();
}

void closeGirl::on_pushButton_2_clicked()
{
    qMain->show();
    this->close();
}

