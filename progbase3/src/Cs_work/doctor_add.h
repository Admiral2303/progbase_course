#ifndef DOCTOR_ADD_H
#define DOCTOR_ADD_H

#include <QDialog>

namespace Ui {
class Doctor_add;
}

class Doctor_add : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor_add(QWidget *parent = 0);
    ~Doctor_add();
    QString get_name();
    QString get_surname();
    QString get_departament();
    QString get_position();
    QString get_cabinet();
    QString get_phone();
    QString get_login();
    QString get_password();
    QString get_worskStart();
    QString get_workEnd();
    void set_name(QString str);
    void set_surname(QString str);
    void set_position(QString str);
    void set_cabinet(QString str);
    void set_phone(QString str);
    void set_login(QString str);
    void set_password(QString str);
    void set_enabled();
    void add_specialty();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();


private:
    Ui::Doctor_add *ui;
};

#endif // DOCTOR_ADD_H
