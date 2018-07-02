#include "maindoctor.h"
#include "ui_maindoctor.h"

#include <QDebug>
//#include "ui_dialog.h"
#include <QString>
#include "mainwindow.h"
#include <QSqlError>

#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include "doctor_add.h"
#include <QDesktopWidget>
#include "query.h"
#include <QCompleter>

maindoctor::maindoctor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::maindoctor)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->tableWidget->setColumnWidth(1, 140);
//    ui->tableWidget->setColumnWidth(2, 120);
//    ui->tableWidget->setColumnWidth(3, 120);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/index.jpeg"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);

}
maindoctor::~maindoctor()
{
    delete ui;
}

void maindoctor::on_pushButton_clicked()
{
    Doctor_add  frm;
    QSqlQuery query;
    if (frm.exec()){
        QString name = frm.get_name();
        QString surname = frm.get_surname();
        QString position = frm.get_position();
        QString cabinet = frm.get_cabinet();
        QString phone = frm.get_phone();
        QString login = frm.get_login();
        QString password = frm.get_password();
        QString work_start = frm.get_worskStart();
        QString work_end = frm.get_workEnd();
        add_newDoctor(name,surname,position,cabinet,phone,login,password,work_start,work_end);
        this->reload_table();
    }

}

void maindoctor::on_pushButton_3_clicked()
{
    if(ui->tableWidget->currentRow() >= 0){
        QString id = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
        Doctor_add  frm;
//        QString sql1 = "SELECT DISTINCT name, surname, position, cabinet, phone, login, password FROM doctor WHERE id_doctor =";
//        sql1 += id;
        QSqlQuery query = get_doctorInf(id);
        if (query.exec()){
            if(query.first()){
                frm.set_name(query.value(0).toString());
                frm.set_surname(query.value(1).toString());
                frm.set_position(query.value(2).toString());
                frm.set_cabinet(query.value(3).toString());
                frm.set_phone(query.value(4).toString());
                frm.set_login(query.value(5).toString());
                frm.set_password(query.value(6).toString());
            }
        }
        if (frm.exec()){
            QString name = frm.get_name();
            QString surname = frm.get_surname();
            QString position = frm.get_position();
            QString cabinet = frm.get_cabinet();
            QString phone = frm.get_phone();
            QString login = frm.get_login();
            QString password = frm.get_password();
            QString work_start = frm.get_worskStart();
            QString work_end = frm.get_workEnd();
            update_doctorInf(name,surname,position,cabinet,phone,login,password,id,work_start,work_end);
            this->reload_table();
        }
    }
}

void maindoctor::on_pushButton_4_clicked()
{
    this->hide();
    MainWindow *frm = new MainWindow();
    frm->show();
}


void maindoctor:: reload_table(){
    ui->tableWidget->setRowCount(0);
    QSqlQuery query = get_doctorsInf();
    while (query.next()){
        int rows = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(rows, 4, new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(rows, 5, new QTableWidgetItem(query.value(7).toString()));;
    }
}

void maindoctor::on_pushButton_2_clicked()
{
    if(ui->tableWidget->currentRow() >= 0){
        QSqlQuery query;
        QString sql = "DELETE FROM doctor WHERE id_doctor = ";
        int toDelete = ui->tableWidget->row(ui->tableWidget->selectedItems().first());
        auto items = ui->tableWidget->selectedItems();
        bool hasselected = items.size() > 0;
        if(hasselected){
            QString id = ui->tableWidget->item(toDelete,0)->text();
            sql += id;
            if(!query.exec(sql)){
               qDebug() << "ERROR: " << query.lastError().text();
            }
            this->reload_table();
        }
    }
}

void maindoctor::on_pushButton_5_clicked()
{
    ui->pushButton->setEnabled(false);
    if(ui->tableWidget->currentRow() >= 0){
        QString id = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
        Doctor_add  frm;
        QSqlQuery query = get_doctorInf(id);
        if(query.first()){
            frm.set_name(query.value(0).toString());
            frm.set_surname(query.value(1).toString());
            frm.set_position(query.value(2).toString());
            frm.set_cabinet(query.value(3).toString());
            frm.set_phone(query.value(4).toString());
            frm.set_login(query.value(5).toString());
            frm.set_password(query.value(6).toString());
            frm.set_enabled();
        }
        else{
            qDebug() << query.lastError();
        }
        qDebug() << query.lastQuery();
        if (frm.exec()){
        }
    }
}

void maindoctor::on_pushButton_6_clicked()
{
    ui->tableWidget->setRowCount(0);
    QString search = ui->lineEdit->text();
    QString sql = "SELECT DISTINCT id_doctor,name,cabinet, login, password FROM doctor WHERE id_doctor =";
    sql += search;
    QSqlQuery query;
    if(query.exec(sql)){
         set_data_to_Table(query);
    }
    else{
        QString sql1 = "SELECT DISTINCT id_doctor,name,cabinet, login, password FROM doctor WHERE name = ";
        sql1 += "'" + search +"'";
        if(query.exec(sql1)){
            set_data_to_Table(query);
        }
    }
}


void maindoctor:: set_data_to_Table(QSqlQuery query){
    if(query.first()){
        int rows = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(rows, 4, new QTableWidgetItem(query.value(4).toString()));

    }
}

void maindoctor::on_pushButton_7_clicked()
{
    this->reload_table();
}

void maindoctor::on_lineEdit_textChanged(const QString &arg1)
{
//    for(int row(0); row < ui->tableWidget->rowCount();row++) ui->tableWidget->setRowHidden(row,true);
//    QList<QTableWidgetItem*>matches = ui->tableWidget->findItems(arg1,Qt::MatchFlag::MatchContains);
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
//        ui->tableWidget->setRowHidden(row,false);
//    }
    QStringList wordList;
    for(int i = 0 ; i < ui->tableWidget->rowCount();i++){
        wordList.push_back(ui->tableWidget->item(i,0)->text());
    }
    for(int i = 0 ; i < ui->tableWidget->rowCount();i++){
        wordList.push_back(ui->tableWidget->item(i,1)->text());
    }
    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
}
