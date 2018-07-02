#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


string Dialog:: get_profname(){
    return (ui->profnameLineEdit->text()).toStdString();
}

int Dialog :: get_salary(){
    //return stoi((ui->salaryLineEdit->text()).toStdString());
    return  ui->spinBox->value();
}

float Dialog :: get_score(){
    return ui->doubleSpinBox->value();
}

string Dialog :: get_name(){
    return (ui->nameLineEdit->text()).toStdString();
}

string Dialog :: get_surname(){
    return (ui->surnameLineEdit->text()).toStdString();
}

int Dialog :: get_year(){
    return ui->spinBox_2->value();
}



