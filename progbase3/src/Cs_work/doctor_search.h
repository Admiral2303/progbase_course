#ifndef DOCTOR_SEARCH_H
#define DOCTOR_SEARCH_H

#include <QDialog>

namespace Ui {
class Doctor_search;
}

class Doctor_search : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor_search(QWidget *parent = 0);
    ~Doctor_search();

private:
    Ui::Doctor_search *ui;
};

#endif // DOCTOR_SEARCH_H
