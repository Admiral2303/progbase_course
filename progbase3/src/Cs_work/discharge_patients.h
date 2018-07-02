#ifndef DISCHARGE_PATIENTS_H
#define DISCHARGE_PATIENTS_H

#include <QDialog>

namespace Ui {
class Discharge_patients;
}

class Discharge_patients : public QDialog
{
    Q_OBJECT

public:
    explicit Discharge_patients(QWidget *parent = 0);
    ~Discharge_patients();
    void load_table(QString id_doctor);
    void set_id(QString id);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Discharge_patients *ui;
};

#endif // DISCHARGE_PATIENTS_H
