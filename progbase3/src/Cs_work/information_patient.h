#ifndef INFORMATION_PATIENT_H
#define INFORMATION_PATIENT_H

#include <QDialog>

namespace Ui {
class Information_patient;
}

class Information_patient : public QDialog
{
    Q_OBJECT

public:
    explicit Information_patient(QWidget *parent = 0);
    ~Information_patient();
    void set_data(QString id_patient, QString name,
                                    QString surname, QString birth_date,
                                    QString address, QString phone_number,
                                    QString introduction_date, QString notes);
    QString get_id();
    QString get_name();
    QString get_surname();
    QString get_birthdate();
    QString get_address();
    QString get_phone();
    QString get_introduction_date();
    QString get_notes();
    QString get_login();
    QString get_password();
    QString get_email();
    void enabled();
    void free_id();
    void log_and_pas();
    void enabled_email();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::Information_patient *ui;
};

#endif // INFORMATION_PATIENT_H
