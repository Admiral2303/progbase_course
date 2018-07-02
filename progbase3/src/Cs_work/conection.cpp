#include "conection.h"
#include "ui_conection.h"
#include "ui_doctor.h"
#include "doctor.h"
#include "patient.h"
#include "information_patient.h"
#include <QSqlError>

#include <QtSql>
#include <QSqlDriver>
#include <QDesktopWidget>
#include "mainwindow.h"
#include <QDesktopWidget>
#include "query.h"
#include <QMessageBox>
#include "smtp.h"

conection::conection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::conection)
{
    ui->setupUi(this);
    ui->paswordLineEdit->setEchoMode(QLineEdit::Password);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);
}

conection::~conection()
{
    delete ui;
}
//log : vadim  pas: 3220




void conection::on_pushButton_clicked()
{
    if(ui->label_2->text() == "Doctor"){
        QString login = ui->loginLineEdit->text();
        QString password = ui->paswordLineEdit->text();
        int id = ui->spinBox->value();
        QSqlQuery query =  take_log_and_pasw_fromDoctor(QString:: number(id));
         if (query.next() && login == query.value(0).toString() && password == query.value(1).toString()){
             qDebug() << "Acess";
             this->hide();
             doctor *frm = new doctor();
             frm->show();
             frm->set_id(QString:: number(id));
             frm->set_name_surname(query.value(2).toString(), query.value(3).toString());
             frm->reload_table();
         }
         else{
            qDebug() << "ERROR: " << query.lastError().text();
            ui->label->setText("Не вірний логін чи пароль");
        }
    }
    if(ui->label_2->text() == "Patient"){
        QString login = ui->loginLineEdit->text();
        QString password = ui->paswordLineEdit->text();
        int id = ui->spinBox->value();
        QSqlQuery query = take_log_and_pasw_fromPatient(QString:: number(id));
         if (query.next() && login == query.value(0).toString() && password == query.value(1).toString()){
             qDebug() << "Acess";
             this->hide();
             patient * frm = new patient();
             frm->show();
             frm->set_name(query.value(2).toString());
             frm->set_surname(query.value(3).toString());
             frm->set_id(id);
         }
         else{
            qDebug() << "ERROR: " << query.lastError().text();
            ui->label->setText("Не вірний логін чи пароль");
        }
    }
}

void conection:: set_name(QString str){
    ui->label_2->setText(str);
}


 void conection:: set_regist(bool st){
     if(st == false){
         ui->pushButton_3->setVisible(false);
     }
     else{
         ui->pushButton_3->setVisible(true);
     }
 }

void conection::on_pushButton_3_clicked()
{
    Information_patient frm;
    QSqlQuery query;
    QString id;
    if(frm.exec()){
        insert_patient(frm.get_name(),frm.get_surname(),frm.get_birthdate(),frm.get_address(),frm.get_phone(),frm.get_introduction_date(),frm.get_notes(),frm.get_login(),frm.get_password());
        query.prepare("SELECT id_patient, login, password FROM patient ORDER BY id_patient DESC LIMIT 1");
        if(!query.exec()){
            qDebug() << query.lastError().text();
        }
        QString data;
        if(query.first()){
            qDebug() << query.value(0).toString();
            data += "login: " + query.value(1).toString() + ";\n";
            data += "password: " + query.value(2).toString() + ";\n";
            data += "id: " + query.value(0).toString() + ";\n";
            id = query.value(0).toString();
        }
        QMessageBox msgBox;
        msgBox.setText(data);
        msgBox.exec();
        char email[] = "admiral230399@gmail.com";
        char password[] = "Vadim2303";

        QString report = "login: " + frm.get_login() + ";\n" + "password: " + frm.get_password() + ";\n" + "id: " + id + ";";
        QString send = frm.get_email();
        Smtp * smtp = new Smtp(email, password, "smtp.gmail.com");
        smtp->sendMail(email, send , "Дані для входу",report);
    }
}

void conection::on_pushButton_2_clicked()
{
    this->hide();
    MainWindow *frm = new MainWindow();
    frm->show();
}
