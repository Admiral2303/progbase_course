#include "doctor_inf.h"
#include "ui_doctor_inf.h"
#include <QSqlError>

#include <QtSql>
#include <QSqlDriver>
#include <QDesktopWidget>
#include "query.h"

Doctor_inf::Doctor_inf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctor_inf)
{
    ui->setupUi(this);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);

    ui->label_3->setScaledContents(true);
    ui->label_4->setScaledContents(true);
    ui->label_5->setScaledContents(true);
    ui->label_6->setScaledContents(true);
    ui->label_7->setScaledContents(true);
    QPixmap pixmap(":/data/star2.png");
    ui->pushButton_3->setIcon(pixmap);
    ui->pushButton_8->setIcon(pixmap);
    ui->pushButton_5->setIcon(pixmap);
    ui->pushButton_6->setIcon(pixmap);
    ui->pushButton_7->setIcon(pixmap);
}

Doctor_inf::~Doctor_inf()
{
    delete ui;
}

QString Doctor_inf:: get_name(){
    return ui->nameLineEdit->text();
}

QString Doctor_inf:: get_surname(){
    return ui->LineEdit->text();
}

QString Doctor_inf:: get_cabinet(){
    return ui->LineEdit_3->text();
}

void Doctor_inf::on_pushButton_clicked()
{
    QSqlQuery query = take_doctorInf("name", this->get_name());
    if(query.first()){
        ui->nameLineEdit->setText(query.value(0).toString());
        ui->LineEdit->setText(query.value(1).toString());
        ui->LineEdit_2->setText(query.value(2).toString());
        ui->LineEdit_3->setText(query.value(3).toString());
        ui->LineEdit_4->setText(query.value(4).toString());
        ui->LineEdit_5->setText(query.value(5).toString() + "-" + query.value(8).toString());
        ui->LineEdit_6->setText(query.value(6).toString());
        ui->LineEdit_7->setText(query.value(7).toString());
        ui->label->setText("");
        this->load_rating();
    }
    else{
        clear();
        ui->label->setText("Не вірно вказані данні");
    }

}

void Doctor_inf::on_pushButton_2_clicked()
{
    QSqlQuery query = take_doctorInf("surname", this->get_surname());
    if(query.first()){
        ui->nameLineEdit->setText(query.value(0).toString());
        ui->LineEdit->setText(query.value(1).toString());
        ui->LineEdit_2->setText(query.value(2).toString());
        ui->LineEdit_3->setText(query.value(3).toString());
        ui->LineEdit_4->setText(query.value(4).toString());
        ui->LineEdit_5->setText(query.value(5).toString() + "-" + query.value(8).toString());
        ui->LineEdit_6->setText(query.value(6).toString());
        ui->LineEdit_7->setText(query.value(7).toString());
        ui->label->setText("");
        this->load_rating();
    }
    else{
        clear();
        ui->label->setText("Не вірно вказані данні");
    }
}
void Doctor_inf:: clear(){
    ui->nameLineEdit->setText("");
    ui->LineEdit->setText("");
    ui->LineEdit_2->setText("");
    ui->LineEdit_3->setText("");
    ui->LineEdit_4->setText("");
}

void Doctor_inf::on_pushButton_4_clicked()
{
    QSqlQuery query =  take_doctorInf("cabinet", this->get_cabinet());
    if(query.first()){
        ui->nameLineEdit->setText(query.value(0).toString());
        ui->LineEdit->setText(query.value(1).toString());
        ui->LineEdit_2->setText(query.value(2).toString());
        ui->LineEdit_3->setText(query.value(3).toString());
        ui->LineEdit_4->setText(query.value(4).toString());
        ui->LineEdit_5->setText(query.value(5).toString() + "-" + query.value(8).toString());
        ui->LineEdit_6->setText(query.value(6).toString());
        ui->LineEdit_7->setText(query.value(7).toString());
        ui->label->setText("");
        this->load_rating();
    }
    else{
        clear();
        ui->label->setText("Не вірно вказані данні");
    }
}

void Doctor_inf:: load_rating(){
    QSqlQuery query;
    QPixmap pixmap(":/data/star2.png");
    QPixmap pixmap1(":/data/star1.png");
    double rating = 0;
    int atempt = 0;
    query.prepare("SELECT DISTINCT rating, atempt FROM doctor WHERE name= :name");
    query.bindValue(0,ui->nameLineEdit->text());
    if(query.exec()){
        if(query.first()){
            rating = query.value(0).toDouble();
            atempt = query.value(1).toInt();
        }
    }

    else{
        qDebug() << query.lastError();
    }
    rating = rating / (double)atempt;
    if(rating == 0){
        ui->label_3->setPixmap(pixmap);
        ui->label_4->setPixmap(pixmap);
        ui->label_5->setPixmap(pixmap);
        ui->label_6->setPixmap(pixmap);
        ui->label_7->setPixmap(pixmap);
    }
    if(rating >=0 && rating <1){
        ui->label_3->setPixmap(pixmap1);
        ui->label_4->setPixmap(pixmap);
        ui->label_5->setPixmap(pixmap);
        ui->label_6->setPixmap(pixmap);
        ui->label_7->setPixmap(pixmap);
    }
    if(rating >=1 && rating <2){
        ui->label_3->setPixmap(pixmap1);
        ui->label_4->setPixmap(pixmap1);
        ui->label_5->setPixmap(pixmap);
        ui->label_6->setPixmap(pixmap);
        ui->label_7->setPixmap(pixmap);
    }
    if(rating >=2 && rating <3){
        ui->label_3->setPixmap(pixmap1);
        ui->label_4->setPixmap(pixmap1);
        ui->label_5->setPixmap(pixmap1);
        ui->label_6->setPixmap(pixmap);
        ui->label_7->setPixmap(pixmap);
    }
    if(rating >3 && rating <4){
        ui->label_3->setPixmap(pixmap1);
        ui->label_4->setPixmap(pixmap1);
        ui->label_5->setPixmap(pixmap1);
        ui->label_6->setPixmap(pixmap1);
        ui->label_7->setPixmap(pixmap);
    }
    if(rating >=4 && rating <= 5){
        ui->label_3->setPixmap(pixmap1);
        ui->label_4->setPixmap(pixmap1);
        ui->label_5->setPixmap(pixmap1);
        ui->label_6->setPixmap(pixmap1);
        ui->label_7->setPixmap(pixmap1);
    }
}


void Doctor_inf::on_pushButton_3_clicked()
{
//    QSqlQuery query;
    double rating = ui->LineEdit_6->text().toDouble();
    int atempt = 0;
    if(ui->LineEdit_7->text() != ""){
        atempt = ui->LineEdit_7->text().toInt() + 1;
        rating = rating + 1.0;
    }
    else{
        rating = 1.0;
        atempt = 1;
    }
    set_doctor_rating(QString::number(rating),QString::number(atempt), ui->nameLineEdit->text(), ui->LineEdit->text());
    this->loadinf();
    qDebug() << rating;
    QPixmap pixmap(":/data/star1.png");
    ui->pushButton_3->setIcon(pixmap);
    QPixmap pixmap1(":/data/star2.png");
    ui->pushButton_8->setIcon(pixmap1);
    ui->pushButton_5->setIcon(pixmap1);
    ui->pushButton_6->setIcon(pixmap1);
    ui->pushButton_7->setIcon(pixmap1);
    ui->LineEdit_7->setText(QString::number(atempt));
}

void Doctor_inf::on_pushButton_5_clicked()
{
    double rating = ui->LineEdit_6->text().toDouble();
    int atempt = 0;
    if(ui->LineEdit_7->text() != ""){
        atempt = ui->LineEdit_7->text().toInt() + 1;
        rating = rating + 2.0;
    }
    else{
        rating = 2.0;
        atempt = 1;
    }
    set_doctor_rating(QString::number(rating),QString::number(atempt), ui->nameLineEdit->text(), ui->LineEdit->text());
    this->loadinf();
    QPixmap pixmap(":/data/star1.png");
    ui->pushButton_3->setIcon(pixmap);
    QPixmap pixmap1(":/data/star2.png");
    ui->pushButton_8->setIcon(pixmap1);
    ui->pushButton_5->setIcon(pixmap);
    ui->pushButton_6->setIcon(pixmap1);
    ui->pushButton_7->setIcon(pixmap1);
    ui->LineEdit_7->setText(QString::number(atempt));
}

void Doctor_inf::on_pushButton_6_clicked()
{
    double rating = ui->LineEdit_6->text().toDouble();
    int atempt = 0;
    if(ui->LineEdit_7->text() != ""){
        atempt = ui->LineEdit_7->text().toInt() + 1;
        rating = rating + 3.0;
    }
    else{
        rating = 3.0;
        atempt = 1;
    }
    set_doctor_rating(QString::number(rating),QString::number(atempt), ui->nameLineEdit->text(), ui->LineEdit->text());
    this->loadinf();
    QPixmap pixmap(":/data/star1.png");
    ui->pushButton_3->setIcon(pixmap);
    QPixmap pixmap1(":/data/star2.png");
    ui->pushButton_8->setIcon(pixmap1);
    ui->pushButton_5->setIcon(pixmap);
    ui->pushButton_6->setIcon(pixmap);
    ui->pushButton_7->setIcon(pixmap1);
    ui->LineEdit_7->setText(QString::number(atempt));
}

void Doctor_inf::on_pushButton_7_clicked()
{
    double rating = ui->LineEdit_6->text().toDouble();
    int atempt = 0;
    if(ui->LineEdit_7->text() != ""){
        atempt = ui->LineEdit_7->text().toInt() + 1;
        rating = rating + 4.0 ;
    }
    else{
        rating = 4.0;
        atempt = 1;
    }
    set_doctor_rating(QString::number(rating),QString::number(atempt), ui->nameLineEdit->text(), ui->LineEdit->text());
    this->loadinf();
    QPixmap pixmap(":/data/star1.png");
    ui->pushButton_3->setIcon(pixmap);
    QPixmap pixmap1(":/data/star2.png");
    ui->pushButton_8->setIcon(pixmap1);
    ui->pushButton_5->setIcon(pixmap);
    ui->pushButton_6->setIcon(pixmap);
    ui->pushButton_7->setIcon(pixmap);
    ui->LineEdit_7->setText(QString::number(atempt));
}

void Doctor_inf::on_pushButton_8_clicked()
{
    double rating = ui->LineEdit_6->text().toDouble();
    int atempt = 0;
    if(ui->LineEdit_7->text() != ""){
        atempt = ui->LineEdit_7->text().toInt() + 1;
        rating = rating + 5.0;
    }
    else{
        rating = 5.0;
        atempt = 1;
    }
    set_doctor_rating(QString::number(rating),QString::number(atempt), ui->nameLineEdit->text(), ui->LineEdit->text());
    this->loadinf();
    QPixmap pixmap(":/data/star1.png");
    ui->pushButton_3->setIcon(pixmap);
    ui->pushButton_8->setIcon(pixmap);
    ui->pushButton_5->setIcon(pixmap);
    ui->pushButton_6->setIcon(pixmap);
    ui->pushButton_7->setIcon(pixmap);
    ui->LineEdit_7->setText(QString::number(atempt));
}

void Doctor_inf:: loadinf(){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT surname,position,cabinet,phone, office_hours,rating FROM doctor WHERE name= :name");
    query.bindValue(0,this->get_name());

    if(!query.exec()){
       qDebug() << "ERROR: " << query.lastError().text();
    }
    if(query.first()){
        ui->LineEdit->setText(query.value(0).toString());
        ui->LineEdit_2->setText(query.value(1).toString());
        ui->LineEdit_3->setText(query.value(2).toString());
        ui->LineEdit_4->setText(query.value(3).toString());
        ui->LineEdit_5->setText(query.value(4).toString());
        ui->LineEdit_6->setText(query.value(5).toString());
        ui->label->setText("");
        this->load_rating();
    }
}
