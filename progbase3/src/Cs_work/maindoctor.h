#ifndef MAINDOCTOR_H
#define MAINDOCTOR_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>

namespace Ui {
class maindoctor;
}

class maindoctor : public QMainWindow
{
    Q_OBJECT

public:
    explicit maindoctor(QWidget *parent = 0);
    ~maindoctor();
    void reload_table();
    void set_data_to_Table(QSqlQuery query);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::maindoctor *ui;

};

#endif // MAINDOCTOR_H
