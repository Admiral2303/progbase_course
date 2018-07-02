#include "doctor_record.h"
#include "ui_doctor_record.h"
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include <vector>
#include <QDesktopWidget>
#include "query.h"

using namespace std;

Doctor_record::Doctor_record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctor_record)
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
    this->add_specialty();

}

Doctor_record::~Doctor_record()
{
    delete ui;
}

void Doctor_record:: add_specialty(){
    ui->comboBox_3->addItem("Хірург");
    ui->comboBox_3->addItem("Окуліст");
    ui->comboBox_3->addItem("Травматолог");
    ui->comboBox_3->addItem("Терапевпт");
    ui->comboBox_3->addItem("Дерматолог");
    ui->comboBox_3->addItem("Психолог");
    ui->comboBox_3->addItem("Ендокринолог");
    ui->comboBox_3->addItem("Стоматолог");
    ui->comboBox_3->addItem("Отоларинголог");
}
void Doctor_record:: set_id(QString id){
    ui->label_2->setText(id);
}

QDate Doctor_record:: get_date(){
    return ui->calendarWidget->selectedDate();
}

QString Doctor_record:: get_time(){
    return ui->comboBox_2->currentText();
}

QString Doctor_record:: get_doctor(){
    return ui->comboBox->currentText();
}

QString Doctor_record:: get_specialty(){
    return ui->comboBox_3->currentText();
}

void Doctor_record::on_pushButton_clicked()
{
    QString specialty = ui->comboBox_3->currentText();
    QSqlQuery query;
    QString id;
    query.prepare("SELECT DISTINCT name FROM doctor WHERE position = :position");

    query.bindValue(0,specialty);
    if(!query.exec()){
        qDebug() << "ERROR: " << query.lastError().text();
    }
    while(query.next()){
        ui->comboBox->addItem(query.value(0).toString());
    }

}

void Doctor_record:: set_visible(bool opt){
    if(opt == true){
        ui->pushButton_4    ->setVisible(false);
    }
    else{
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
    }
}

void Doctor_record::on_pushButton_2_clicked()
{
    QSqlQuery query;
    delete_doctorRecord(ui->label_2->text(), ui->calendarWidget->selectedDate().toString("yyyy.MM.dd"), ui->comboBox_2->currentText() );
    if(ui->comboBox_2->count() > 1){
        ui->comboBox_2->removeItem(ui->comboBox->currentIndex()+1);
    }
    else{
        ui->comboBox_2->removeItem(ui->comboBox->currentIndex());
    }
}

void Doctor_record::on_pushButton_3_clicked()
{
    ui->comboBox_2->clear();
    QSqlQuery query;
    QString id;
    query.prepare("SELECT DISTINCT id_doctor FROM doctor WHERE name=:name");
    query.bindValue(0,ui->comboBox->currentText());
    if(query.exec()){}
    if(query.first()){
         id = query.value(0).toString();
    }
    query = take_time_from_doctorRecord(id, ui->calendarWidget->selectedDate().toString("yyyy.MM.dd"), ui->label_2->text());
    while(query.next()){
        ui->comboBox_2->addItem(query.value(0).toString());
    }
}

void Doctor_record::on_pushButton_4_clicked()
{
    ui->comboBox_2->clear();
    QSqlQuery query;
    QString id;
    query = take_doctorId(ui->comboBox->currentText(), ui->comboBox_3->currentText());
    if(query.first()){
         id = query.value(0).toString();
    }
    query = get_doctorRecords(id, ui->calendarWidget->selectedDate().toString("yyyy.MM.dd"));
    vector<QString> time_rec;
    while(query.next()){
        time_rec.push_back(query.value(0).toString());
    }
    query.prepare("SELECT DISTINCT start_work, end_work FROM doctor WHERE id_doctor=:id_doctor");
    query.bindValue(0, id);
    if(query.exec()){}
    double start_work = 0.0;
    double end_work = 0.0;
    if(query.first()){
        start_work = query.value(0).toDouble();
        end_work = query.value(1).toDouble();
    }
    load_combobox( start_work,  end_work, time_rec);
}

void Doctor_record:: load_combobox(double start_work, double end_work,vector<QString> time_rec){
    int min1 = 0;
    int min2 = 30;
    for(int i = (int)start_work; i < (int)end_work; i++){
        QString time = QString::number(i);
        QString time1 = QString::number(i);
        time += "." + QString::number(min1) + QString::number(min1);
        time1 += "." + QString::number(min2);
        int flag = 0;
        int flag1 = 0;
        for(int i = 0; i < time_rec.size();i++){
            if(time == time_rec[i]){
                flag = 1;
                break;
            }
        }
        for(int i = 0; i < time_rec.size();i++){
            if(time1 == time_rec[i]){
                flag1 = 1;
                break;
            }
        }
        if(flag != 1){
            ui->comboBox_2->addItem(time);
        }
        if(flag1 != 1){
            ui->comboBox_2->addItem(time1);
        }
    }
}

