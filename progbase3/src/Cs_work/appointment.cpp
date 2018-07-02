#include "appointment.h"
#include "ui_appointment.h"
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include <vector>
#include <QDate>
#include <QDesktopWidget>
using namespace std;

Appointment::Appointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointment)
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

}



void Appointment:: load_table(QString id){
    QSqlQuery query;
    QString curdate = QDate::currentDate().toString("yyyy.MM.dd");
    query.prepare("SELECT DISTINCT name,surname,time FROM doctor_record WHERE id_doctor= :id_doctor AND date= :date");
    query.bindValue(0,id);
    query.bindValue(1,curdate);
    if(!query.exec()){
        qDebug() << query.lastError();
    }
    vector<double> time;
    vector<QString> name;
    vector<QString> surname;
    while(query.next()){
        name.push_back(query.value(0).toString());
        surname.push_back(query.value(1).toString());
        time.push_back(query.value(2).toDouble());
    }
    int size = time.size();
    for(int i = 0; i < size;i++){
        double min = time[0];
        int k = 0;
        int j = 0;
        for(; j < time.size();j++){
              if(time[j] < min){
                  min = time[j];
                  k = j;
              }
        }
        qDebug() << time[k];
        int rows = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(name[k]));
        ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(surname[k]));
        if((time[k] - (int)time[k]) > 0){
            ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(QString::number(time[k]) + "0"));
        }
        else{
            ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(QString::number(time[k]) + ".00"));
        }
        time.erase(time.begin() + k);
        name.erase(name.begin() + k);
        surname.erase(surname.begin() + k);
    }

}

Appointment::~Appointment()
{
    delete ui;
}

void Appointment:: set_id(QString id){
    ui->label_2->setText(id);
}
