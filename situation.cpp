#include "situation.h"
#include "ui_situation.h"
#include <QFile>
#include <QDate>

situation::situation(QWidget * admin , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::situation)
{
    ui->setupUi(this);
    this->qMain = main;
    this->admin = admin;
    load();
}

void situation::load()
{
    ui->tableWidget->setRowCount(0);

    QFile file("F:/Qt/Library/get_return.txt");
    file.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in1(&file);

    get_return.clear();
    while(!in1.atEnd())
    {
       QStringList line = in1.readLine().split(" ");
       get_return[qMakePair(line[0],line[1])] = QDate::fromString(line[2], "yyyyMMdd");
    }

    file.close();




    int j=0;
    for(auto i=get_return.begin() ; i != get_return.end() ; ++i)
    {
            QDate current = QDate:: currentDate();
            int d = current.daysTo(i.value());


            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            //isbn
            QTableWidgetItem *isbn1 = new QTableWidgetItem();
            if(d == 1 || d == 0)
                isbn1->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn1->setBackground(QBrush(QColor(239,129,130)));

            isbn1->setText(i.key().second);
            ui->tableWidget->setItem(j,1,isbn1);



            //name
            QTableWidgetItem *isbn2 = new QTableWidgetItem();
            if(d == 1 || d == 0)
                isbn2->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn2->setBackground(QBrush(QColor(239,129,130)));

            isbn2->setText(i.key().first);
            ui->tableWidget->setItem(j,0,isbn2);



            //date return
            QTableWidgetItem *isbn3 = new QTableWidgetItem();
            if(d == 1 || d == 0)
                isbn3->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn3->setBackground(QBrush(QColor(239,129,130)));

            isbn3->setText(i.value().toString("yyyy MMM dd"));
            ui->tableWidget->setItem(j,3,isbn3);



            //date get
            QTableWidgetItem *isbn4 = new QTableWidgetItem();
            if(d == 1 || d == 0)
                isbn4->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn4->setBackground(QBrush(QColor(239,129,130)));

            QDate get_day = i.value().addDays(-7);
            isbn4->setText(get_day.toString("yyyy MMM dd"));
            ui->tableWidget->setItem(j,2,isbn4);




            j++;

    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

situation::~situation()
{
    delete ui;
}

void situation::on_closeButton_clicked()
{
    this->close();
}


void situation::on_menuButton_clicked()
{
    qMain->show();
    this->hide();
}


void situation::on_dashButton_clicked()
{
    admin->show();
    this->close();
}


void situation::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 == "")
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
            ui->tableWidget->showRow(i);
    else
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
        {
            if(ui->tableWidget->item(i,0)->text().startsWith(arg1 , Qt::CaseInsensitive))
                ui->tableWidget->showRow(i);
            else
                ui->tableWidget->hideRow(i);
        }
}

