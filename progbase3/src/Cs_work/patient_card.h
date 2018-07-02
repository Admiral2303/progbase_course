#ifndef PATIENT_CARD_H
#define PATIENT_CARD_H

#include <QDialog>

namespace Ui {
class Patient_card;
}

class Patient_card : public QDialog
{
    Q_OBJECT

public:
    explicit Patient_card(QWidget *parent = 0);
    ~Patient_card();
    void set_id(QString id);
    void load_table(QString id);

private:
    Ui::Patient_card *ui;
};

#endif // PATIENT_CARD_H
