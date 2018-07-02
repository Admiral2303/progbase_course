#ifndef CONECTION_H
#define CONECTION_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>

namespace Ui {
class conection;
}

class conection : public QMainWindow
{
    Q_OBJECT

public:
    explicit conection(QWidget *parent = 0);
    ~conection();
    void set_name(QString str);
     void set_regist(bool st);

private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::conection *ui;

};


#endif // CONECTION_H
