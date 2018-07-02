#ifndef DOCTOR_RECORD_H
#define DOCTOR_RECORD_H
#include <QDate>

#include <QDialog>
#include <vector>
using namespace std;

namespace Ui {
class Doctor_record;
}

class Doctor_record : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor_record(QWidget *parent = 0);
    ~Doctor_record();
    void set_id(QString id);
    QString get_doctor();
    QString get_time();
    QDate get_date();
    void set_visible(bool opt);
    void add_specialty();
    QString get_specialty();
    void load_combobox(double start_work, double end_work,vector<QString> time_rec);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Doctor_record *ui;
};

#endif // DOCTOR_RECORD_H
