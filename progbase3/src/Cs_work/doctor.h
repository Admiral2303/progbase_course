#ifndef DOCTOR_H
#define DOCTOR_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>
#include <QTableWidget>

namespace Ui {
class doctor;
}

class doctor : public QMainWindow
{
    Q_OBJECT

public:
    explicit doctor(QWidget *parent = 0);
    ~doctor();
    void reload_table();
    void set_id(QString id);
    void set_name_surname(QString name, QString surname);
    void set_data_to_Table(QSqlQuery query);
    QString id(QString name, QString surname);
    QString get_el();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_6_clicked();

    void on_tableWidget_patient_itemSelectionChanged();
    QString get_id();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::doctor *ui;
};

#endif // DOCTOR_H
