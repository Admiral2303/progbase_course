#ifndef PATIENT_H
#define PATIENT_H

#include <QMainWindow>

namespace Ui {
class patient;
}

class patient : public QMainWindow
{
    Q_OBJECT

public:
    explicit patient(QWidget *parent = 0);
    ~patient();
    void set_name(QString name);
    void set_surname(QString surname);
    void set_id(int id);
    QString get_id();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


private:
    Ui::patient *ui;
};

#endif // PATIENT_H
