#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDialog>

namespace Ui {
class Appointment;
}

class Appointment : public QDialog
{
    Q_OBJECT

public:
    explicit Appointment(QWidget *parent = 0);
    ~Appointment();
     void set_id(QString id);
     void load_table(QString id);

private:
    Ui::Appointment *ui;
};

#endif // APPOINTMENT_H
