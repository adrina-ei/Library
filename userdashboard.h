#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class userdashboard;
}

class userdashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit userdashboard(QWidget * main , QString user , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    QString get_user();

    ~userdashboard();

private slots:



    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_logoutButton_clicked();

    void on_listButton_clicked();

    void on_pushButton_clicked();

    void on_getButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::userdashboard *ui;
    QPointF oldPos;
    QString user;
    QWidget * main;


};

#endif // USERDASHBOARD_H
