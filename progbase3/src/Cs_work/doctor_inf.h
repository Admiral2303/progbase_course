#ifndef DOCTOR_INF_H
#define DOCTOR_INF_H

#include <QDialog>

namespace Ui {
class Doctor_inf;
}

class Doctor_inf : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor_inf(QWidget *parent = 0);
    ~Doctor_inf();
    QString get_name();
    QString get_surname();
    QString get_cabinet();
    void clear();
    void load_rating();
    void loadinf();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Doctor_inf *ui;
};

#endif // DOCTOR_INF_H
