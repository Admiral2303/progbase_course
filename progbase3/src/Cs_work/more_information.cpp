#include "more_information.h"
#include "ui_more_inforation.h"

More_information::More_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::More_inforation)
{
    ui->setupUi(this);
}

More_information::~More_information()
{
    delete ui;
}

void More_information:: set_data(QString id_patient, QString name,
                                QString surname, QString birth_date,
                                QString address, QString phone_number,
                                QString introduction_date, QString notes){
    ui->iDLineEdit->setText(id_patient));
    ui->LineEdit->setText(name);
    ui->LineEdit_2->setText(surname);
    ui->LineEdit_3->setText(birth_date);
    ui->LineEdit_4->setText(address);
    ui->LineEdit_5->setText(phone_number);
    ui->LineEdit_6->setText(introduction_date);
    ui->textEdit->setText(notes);
}
