#include "doctor.h"
#include "ui_doctor.h"
#include <QDebug>
#include <QString>
#include "mainwindow.h"
#include "information_patient.h"
#include <QSqlResult>
#include <iostream>
#include <card.h>
#include <QTableWidget>
#include "patient_card.h"
#include "appointment.h"
#include "discharge_patients.h"
#include <QDesktopWidget>
#include <QCompleter>
#include <query.h>
#include <QMessageBox>

using namespace std;

doctor::doctor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::doctor)
{
    ui->setupUi(this);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    ui->tableWidget_patient->setColumnWidth(3, 120);
    brush->setTextureImage(QImage(":/firstWindow/index.jpeg"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
    ui->tableWidget_patient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_patient->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);
    for(int i = 1; i <= 60 ; i++){
        ui->comboBox->addItem(QString::number(i));
    }

}

doctor::~doctor()
{
    delete ui;
}

void doctor:: reload_table(){
    ui->tableWidget_patient->setRowCount(0);

    QSqlQuery query = load_Doctortable(ui->label_7->text());
    while (query.next()){
        int rows = ui->tableWidget_patient->rowCount();
        ui->tableWidget_patient->insertRow(rows);
        ui->tableWidget_patient->setItem(rows, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget_patient->setItem(rows, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget_patient->setItem(rows, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget_patient->setItem(rows, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget_patient->setItem(rows, 4, new QTableWidgetItem(query.value(4).toString()));
    }
}


void doctor::on_pushButton_clicked()
{
        QSqlQuery query = add_patient_toDoctor(ui->label_7->text(), ui->spinBox->text());
        this->reload_table();
}


QString doctor:: id(QString name, QString surname){
    QString sql1 = "SELECT DISTINCT id_patient FROM patient WHERE name = ";
    sql1 += "'" + name + "' AND ";
    sql1 += "surname = '" + surname + "'";
    QSqlQuery query;

    if(query.exec(sql1)){
        qDebug() << "YES";
    }
    else{
        qDebug() << "ERROR: " << query.lastError().text();
        qDebug() << sql1;
    }
    if(query.first()){
        return query.value(0).toString();
    }
    else{
        return "";
    }
}



void doctor::on_pushButton_3_clicked()
{

    auto items = ui->tableWidget_patient->selectedItems();
    bool hasselected = items.size() > 0;
    if(hasselected){
        int i = ui->tableWidget_patient->currentRow(); //строка
        QString element = ui->tableWidget_patient->item(i,0)->text();
        QSqlQuery query = take_infPatient(element);
        QString id;
        if (query.next()){
            Information_patient frm;
            frm.enabled_email();
            frm.set_data(query.value(0).toString(), query.value(1).toString(),
                          query.value(2).toString(),query.value(3).toString(),
                          query.value(4).toString(),query.value(5).toString(),
                          query.value(6).toString(),query.value(7).toString());
            id = query.value(0).toString();
            frm.log_and_pas();
            if (frm.exec()) {
                query = update_patientInf(frm.get_name(),frm.get_surname(),frm.get_birthdate(),frm.get_address(),frm.get_phone(),frm.get_introduction_date(), frm.get_notes(), id);
                this->reload_table();
            }
        }
    }
}



void doctor::on_pushButton_4_clicked()
{
    this->hide();
    MainWindow *frm = new MainWindow();
    frm->show();
}

void doctor::on_pushButton_6_clicked()
{
        auto items = ui->tableWidget_patient->selectedItems();
        bool hasselected = items.size() > 0;
        if(hasselected){
            int i= ui->tableWidget_patient->currentRow(); //строка
            QString element = ui->tableWidget_patient->item(i,0)->text();
            QSqlQuery query = take_infPatient(element);
            if (query.next()){
                Information_patient frm;
                frm.log_and_pas();
                frm.enabled();
                frm.enabled_email();
                frm.set_data(query.value(0).toString(), query.value(1).toString(),
                              query.value(2).toString(),query.value(3).toString(),
                              query.value(4).toString(),query.value(5).toString(),
                              query.value(6).toString(),query.value(7).toString());
                if (frm.exec()) {}
                ui->pushButton_6->setEnabled(false);
            }

        }
}

void doctor::on_tableWidget_patient_itemSelectionChanged()
{
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
}

void doctor:: set_id(QString id){
    ui->label_7->setText(id);
}

QString doctor:: get_id(){
    return ui->label_7->text();
}


void doctor::on_pushButton_2_clicked()
{
    auto items = ui->tableWidget_patient->selectedItems();
    bool hasselected = items.size() > 0;
    if(hasselected){
        QSqlQuery query;
        QString id = ui->tableWidget_patient->item(ui->tableWidget_patient->currentRow(),0)->text();
        QString palate = ui->tableWidget_patient->item(ui->tableWidget_patient->currentRow(),4)->text();
        query.prepare("UPDATE patient SET status = 'health', id_doctor= :id_doctor, palate = ' ' WHERE id_patient= :id_patient");
        query.bindValue(0, "-1");
        query.bindValue(1, id);
        if(query.exec()){}
        query.prepare("SELECT * FROM observation ORDER BY time ASC");
        if(query.exec()){}
        query = take_observisionInf();
        QString report;
        QString diagnosis;
        while(query.next()){
            if(query.value(0).toString() == id){
                report = query.value(1).toString();
                diagnosis = query.value(2).toString();
            }
        }
        QString curentDate = QDate::currentDate().toString("yyyy.MM.dd");
        query =  insert_intoDischarged_patients(ui->tableWidget_patient->item(ui->tableWidget_patient->currentRow(),1)->text(),
                                                        ui->tableWidget_patient->item(ui->tableWidget_patient->currentRow(),2)->text(),
                                                        ui->label_7->text(), diagnosis, report, curentDate, id);
        query.prepare("SELECT DISTINCT num_place FROM palate WHERE no_palate= :no_palate");
        query.bindValue(0, palate);
        if(query.exec()){}
        int num_place = 0;
        if(query.first()){
            num_place = query.value(0).toInt();
        }
        if(num_place < 4){
            num_place = num_place + 1;
        }
        query.prepare("UPDATE palate SET num_place=:num_place WHERE no_palate = :no_palate");
        query.bindValue(0,QString::number(num_place));
        query.bindValue(1,palate);
        if(query.exec()){}
        this->reload_table();
    }
}


void doctor:: set_name_surname(QString name, QString surname){
    ui->label_2->setText(name);
    ui->label_3->setText(surname);
}

void doctor::on_pushButton_5_clicked()
{
    ui->tableWidget_patient->setRowCount(0);
    QString search = ui->lineEdit->text();
    QString sql = "SELECT DISTINCT id_patient,name,surname,introduction_date,palate FROM patient WHERE id_patient =";
    sql += search;
    QSqlQuery query;// = take_infpatient_byField("id_patient", search);
    if(query.exec(sql)){
         set_data_to_Table(query);
    }
    else{
        QString sql1 = "SELECT DISTINCT id_patient,name,surname,introduction_date,palate FROM patient WHERE name = ";
        sql1 += "'" + search +"'";
        query = take_infpatient_byField("name", search);
        if(query.exec(sql1)){
            set_data_to_Table(query);
        }
//        else{
//          //  qDebug() << query.lastError().text();
//            QString sql2 = "SELECT DISTINCT id_patient,name,surname,introduction_date,palate FROM patient WHERE surname = ";
//            sql2 +="'" + search + "'";
//           // query = take_infpatient_byField("surname", search);
//            if(query.exec(sql2)){
//                 set_data_to_Table(query);
//            }
//            else{
//                QString sql3 = "SELECT DISTINCT id_patient,name,surname,introduction_date,palate FROM patient WHERE introduction_date = ";
//                sql3 +="'"+ search + "'";
//                if(query.exec(sql3)){
//                     set_data_to_Table(query);
//                }
//            }
//        }
    }
}

void doctor::on_pushButton_7_clicked()
{
    this->reload_table();
}

void doctor:: set_data_to_Table(QSqlQuery query){
    if(query.first()){
        qDebug() << query.value(2).toString();
        int rows = ui->tableWidget_patient->rowCount();
        ui->tableWidget_patient->insertRow(rows);
        ui->tableWidget_patient->setItem(rows, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget_patient->setItem(rows, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget_patient->setItem(rows, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget_patient->setItem(rows, 3, new QTableWidgetItem(query.value(3).toString()));
    }
}

void doctor::on_pushButton_8_clicked(){
    if(ui->tableWidget_patient->currentRow() >= 0){
        int i = ui->tableWidget_patient->currentRow();
        QString name = ui->tableWidget_patient->item(i,1)->text();
        QString surname = ui->tableWidget_patient->item(i,2)->text();
        insert_intoCard(this->id(name, surname));

        QString sort = "SELECT * FROM <observation> ORDER BY id_observ DESC";

        QString element = ui->tableWidget_patient->item(i,0)->text();
        QSqlQuery query;
        if(query.exec(sort)){}
        Patient_card card;
        card.set_id(element);
        card.load_table(element);
        if(card.exec()){}
    }
}

QString doctor:: get_el(){
    int i = ui->tableWidget_patient->currentRow();
    QString element = ui->tableWidget_patient->item(i,0)->text();
    return element;
}


void doctor::on_pushButton_10_clicked()
{

    int i = ui->tableWidget_patient->currentRow();
    if(i >= 0){
        QString element = ui->tableWidget_patient->item(i,0)->text();
        Card frm;
        if (frm.exec()){
              insert_intoObservision(frm.get_medicament(),frm.get_analysis(),frm.get_report(),frm.get_diagnosis(),element);
        }
     }
}

void doctor::on_pushButton_11_clicked()
{
    Appointment frm;
    frm.set_id(ui->label_7->text());
    frm.load_table(ui->label_7->text());
    if(frm.exec()){

    }
}

void doctor::on_pushButton_9_clicked()
{
    Discharge_patients frm;
    frm.set_id(ui->label_7->text());
    frm.load_table(ui->label_7->text());
    if(frm.exec()){

    }
}

void doctor::on_lineEdit_textChanged(const QString &arg1)
{
//    for(int row(0); row < ui->tableWidget_patient->rowCount();row++) ui->tableWidget_patient->setRowHidden(row,true);
//    QList<QTableWidgetItem*>matches = ui->tableWidget_patient->findItems(arg1,Qt::MatchFlag::MatchContains);
//    for(int i = 0; i < matches.size();){
//        QTableWidgetItem * item = matches.at(i);
//        if(item->column() == 1){
//            matches.removeAt(i);
//        } else{
//            i++;
//        }
//    }
//    for(QTableWidgetItem* item:matches){
//        int row = item->row();
//        ui->tableWidget_patient->setRowHidden(row,false);
//    }
    QStringList wordList;
    for(int i = 0 ; i < ui->tableWidget_patient->rowCount();i++){
        wordList.push_back(ui->tableWidget_patient->item(i,0)->text());
    }
    for(int i = 0 ; i < ui->tableWidget_patient->rowCount();i++){
        wordList.push_back(ui->tableWidget_patient->item(i,1)->text());
    }
    for(int i = 0 ; i < ui->tableWidget_patient->rowCount();i++){
        wordList.push_back(ui->tableWidget_patient->item(i,2)->text());
    }
    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);

}

void doctor::on_pushButton_12_clicked()
{
    int i = ui->tableWidget_patient->currentRow();
    if(i >= 0){
    QString element = ui->tableWidget_patient->item(i,0)->text();
    QString palate = ui->comboBox->currentText();
    QSqlQuery query;
    query.prepare("SELECT DISTINCT num_place FROM palate WHERE no_palate = :palate");
    query.bindValue(0,palate);
    if(query.exec()){}
    int num_place;
    if(query.first()){
        num_place = query.value(0).toInt();
    }
    if(num_place > 0){
        query.prepare("UPDATE patient SET palate=:palate WHERE id_patient = :id_patient");
        query.bindValue(0, palate);
        query.bindValue(1,element);
        if(query.exec()){}
        num_place = num_place - 1;
        query.prepare("UPDATE palate SET num_place=:num_place WHERE no_palate = :no_palate");
        query.bindValue(0,QString::number(num_place));
        query.bindValue(1,palate);
        if(query.exec()){}
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Палата заповнена");
        msgBox.exec();
    }
    this->reload_table();
    }
}

void doctor::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text().toInt() >= 0){
        ui->pushButton->setEnabled(true);
    }
}
