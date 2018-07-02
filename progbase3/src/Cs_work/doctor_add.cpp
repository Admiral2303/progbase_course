#include "doctor_add.h"
#include "ui_doctor_add.h"
#include <QDesktopWidget>

Doctor_add::Doctor_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctor_add)
{
    ui->setupUi(this);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/1.jpg"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
    QPixmap pixmap1(":/del/1486504830-delete-dustbin-empty-recycle-recycling-remove-trash_81361.png");
    ui->pushButton->setIcon(pixmap1);
    ui->pushButton_2->setIcon(pixmap1);
    ui->pushButton_3->setIcon(pixmap1);
    ui->pushButton_5->setIcon(pixmap1);
    ui->pushButton_6->setIcon(pixmap1);
    ui->pushButton_10->setIcon(pixmap1);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);
    this->add_specialty();
    for(int i = 8; i < 12; i++){
        QString time = QString::number(i);
        time += "." + QString::number(0) + QString::number(0);
        ui->comboBox_2->addItem(time);
    }
    for(int i = 15; i < 19; i++){
        QString time = QString::number(i);
        time += "." + QString::number(0) + QString::number(0);
        ui->comboBox_3->addItem(time);
    }
}

Doctor_add::~Doctor_add()
{
    delete ui;
}

void Doctor_add:: add_specialty(){
    ui->comboBox->addItem("Хірург");
    ui->comboBox->addItem("Окуліст");
    ui->comboBox->addItem("Травматолог");
    ui->comboBox->addItem("Терапевпт");
    ui->comboBox->addItem("Дерматолог");
    ui->comboBox->addItem("Психолог");
    ui->comboBox->addItem("Ендокринолог");
    ui->comboBox->addItem("Стоматолог");
    ui->comboBox->addItem("Отоларинголог");
}

void Doctor_add::on_pushButton_clicked()
{
    ui->nameLineEdit->clear();
}

void Doctor_add::on_pushButton_2_clicked()
{
    ui->surnameLineEdit->clear();
}




void Doctor_add::on_pushButton_5_clicked()
{
    ui->cabinetLineEdit->clear();
}

void Doctor_add::on_pushButton_6_clicked()
{
    ui->phoneLineEdit->clear();
}

void Doctor_add::on_pushButton_8_clicked()
{
    ui->loginLineEdit->clear();
}

void Doctor_add::on_pushButton_7_clicked()
{
    ui->passwordLineEdit->clear();
}

void Doctor_add::on_pushButton_10_clicked()
{
    ui->nameLineEdit->clear();
    ui->surnameLineEdit->clear();
    ui->cabinetLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->loginLineEdit->clear();
    ui->passwordLineEdit->clear();

}

QString Doctor_add:: get_name(){
    return ui->nameLineEdit->text();
}


QString Doctor_add:: get_surname(){
    return ui->surnameLineEdit->text();
}

QString Doctor_add:: get_position(){
    return ui->comboBox->currentText();
}



QString Doctor_add:: get_cabinet(){
    return ui->cabinetLineEdit->text();
}

QString Doctor_add:: get_phone(){
    return ui->phoneLineEdit->text();
}

QString Doctor_add:: get_login(){
    return ui->loginLineEdit->text();
}

QString Doctor_add:: get_password(){
    return ui->passwordLineEdit->text();
}

QString Doctor_add:: get_worskStart(){
    return ui->comboBox_2->currentText();
}

QString Doctor_add:: get_workEnd(){
    return ui->comboBox_3->currentText();
}

void Doctor_add:: set_name(QString str){
    ui->nameLineEdit->setText(str);
}

void Doctor_add:: set_surname(QString str){
    ui->surnameLineEdit->setText(str);
}

void Doctor_add:: set_position(QString str){
    int i = 0;
    for(; i < ui->comboBox->count(); i++){
        if(ui->comboBox->itemText(i) != str){
            ui->comboBox->removeItem(i);
        }
    }
//    ui->comboBox->itemData(i);
}

void Doctor_add:: set_cabinet(QString str){
    ui->cabinetLineEdit->setText(str);
}

void Doctor_add:: set_phone(QString str){
    ui->phoneLineEdit->setText(str);
}

void Doctor_add:: set_login(QString str){
    ui->loginLineEdit->setText(str);
}

void Doctor_add:: set_password(QString str){
    ui->passwordLineEdit->setText(str);
}

void Doctor_add:: set_enabled(){
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->comboBox_3->setVisible(false);
    ui->nameLineEdit->setEnabled(false);
    ui->surnameLineEdit->setEnabled(false);
    ui->cabinetLineEdit->setEnabled(false);
    ui->phoneLineEdit->setEnabled(false);
    ui->loginLineEdit->setEnabled(false);
    ui->passwordLineEdit->setEnabled(false);
    ui->comboBox->setEnabled(false);


}

