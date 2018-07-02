#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}
int Dialog1:: get_salary(){
    //return stoi((ui->salaryLineEdit->text()).toStdString());
    return  ui->spinBox->value();
}
