#include "information_patient.h"
#include "ui_information_patient.h"
#include <QIcon>
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include <vector>
#include <QDesktopWidget>

using namespace std;

Information_patient::Information_patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information_patient)
{
    ui->setupUi(this);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/1.jpg"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);

}



Information_patient::~Information_patient()
{
    delete ui;
}
void Information_patient:: set_data(QString id_patient, QString name,
                                QString surname, QString birth_date,
                                QString address, QString phone_number,
                                QString introduction_date, QString notes){
    ui->LineEdit_13->setText(name);
    ui->LineEdit_14->setText(surname);
    ui->LineEdit_15->setText(birth_date);
    ui->LineEdit_16->setText(address);
    ui->LineEdit_17->setText(phone_number);
    ui->LineEdit_18->setText(introduction_date);
    ui->textEdit->setText(notes);
}


QString Information_patient:: get_name(){
    return ui->LineEdit_13->text();
}

QString Information_patient:: get_surname(){
    return ui->LineEdit_14->text();
}

QString Information_patient:: get_birthdate(){
    return ui->LineEdit_15->text();
}

QString Information_patient:: get_address(){
    return ui->LineEdit_16->text();
}

QString Information_patient:: get_phone(){
    return ui->LineEdit_17->text();
}

QString Information_patient:: get_introduction_date(){
    return ui->LineEdit_18->text();
}

QString Information_patient:: get_notes(){
    return ui->textEdit->toPlainText();
}
QString Information_patient:: get_login(){
    return ui->LineEdit->text();
}

QString Information_patient:: get_password(){
    return ui->LineEdit_2->text();
}

QString Information_patient:: get_email(){
    return ui->lineEdit->text();
}


void Information_patient::on_pushButton_2_clicked()
{
    ui->LineEdit_13->clear();
}

void Information_patient::on_pushButton_3_clicked()
{
    ui->LineEdit_14->clear();
}

void Information_patient::on_pushButton_4_clicked()
{
    ui->LineEdit_15->clear();
}

void Information_patient::on_pushButton_5_clicked()
{
    ui->LineEdit_16->clear();
}

void Information_patient::on_pushButton_6_clicked()
{
    ui->LineEdit_17->clear();
}

void Information_patient::on_pushButton_7_clicked()
{
    ui->LineEdit_18->clear();
}

void Information_patient::on_pushButton_8_clicked()
{
    ui->textEdit->clear();
}

void Information_patient::on_pushButton_9_clicked()
{
    ui->LineEdit_13->clear();
    ui->LineEdit_14->clear();
    ui->LineEdit_15->clear();
    ui->LineEdit_16->clear();
    ui->LineEdit_17->clear();
    ui->LineEdit_18->clear();
    ui->textEdit->clear();
    ui->LineEdit->clear();
    ui->LineEdit_2->clear();
}

void Information_patient:: enabled(){
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->label->setVisible(false);
    ui->LineEdit_13->setEnabled(false);
    ui->LineEdit_14->setEnabled(false);
    ui->LineEdit_15->setEnabled(false);
    ui->LineEdit_16->setEnabled(false);
    ui->LineEdit_17->setEnabled(false);
    ui->LineEdit_18->setEnabled(false);
    ui->textEdit->setEnabled(false);
}

void Information_patient:: log_and_pas(){
    ui->LineEdit->setText("*****");
    ui->LineEdit_2->setText("*****");
}


void Information_patient:: enabled_email(){
    ui->lineEdit->setVisible(false);
    ui->label_2->setVisible(false);
    ui->LineEdit->setEnabled(false);
    ui->LineEdit_2->setEnabled(false);
}



void Information_patient::on_pushButton_10_clicked()
{
    ui->LineEdit->clear();
}

void Information_patient::on_pushButton_11_clicked()
{
    ui->LineEdit_2->clear();
}
