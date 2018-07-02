#ifndef DIALOG_H
#define DIALOG_H
#include <string>
#include <QDialog>
using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    int  get_year();
    string get_surname();
    string  get_name();
    float get_score();
    int  get_salary();
    string get_profname();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
