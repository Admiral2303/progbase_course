#include "patient.h"
#include "ui_patient.h"
#include "doctor_inf.h"
#include "patient_card.h"
#include "doctor_record.h"
#include <QDate>
#include "mainwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include "smtp.h"
#include "report.h"
#include <QDesktopWidget>
#include "query.h"

patient::patient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::patient)
{
    ui->setupUi(this);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/index.jpeg"));
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

patient::~patient()
{
    delete ui;
}

void patient::on_pushButton_clicked()
{
    Doctor_inf * frm = new Doctor_inf();
    //frm->show();
    if(frm->exec()){

    }

}

void patient:: set_name(QString name){
    ui->label_2->setText(name);
}

void patient:: set_surname(QString surname){
    ui->label_3->setText(surname);
}

void patient:: set_id(int id){
    ui->label_6->setText(QString::number(id));
}

void patient::on_pushButton_2_clicked()
{
    Patient_card * frm = new Patient_card();
    frm->set_id(ui->label_6->text());
    frm->load_table(ui->label_6->text());
    frm->show();
}

QString patient:: get_id(){
    return ui->label_6->text();
}


void patient::on_pushButton_6_clicked()
{
    Doctor_record frm;
    frm.set_visible(false);
    frm.set_id(ui->label_6->text());
    //frm.show();
    if(frm.exec()){
        QDate date = frm.get_date();
        QString record_date = date.toString("yyyy.MM.dd");
        QString record_time = frm.get_time();
        QString id;
        QSqlQuery query = take_doctorId(frm.get_doctor(), frm.get_specialty());
        if(query.first()){
             id = query.value(0).toString();
        }
        qDebug() << id;
        insert_intoDoctor_record(id, ui->label_6->text(), record_date, record_time, ui->label_2->text(), ui->label_3->text());
    }
}

void patient::on_pushButton_7_clicked()
{
    Doctor_record frm;
    frm.set_visible(true);
    frm.set_id(ui->label_6->text());
    if(frm.exec()){

    }
}

void patient::on_pushButton_4_clicked()
{
    this->hide();
    MainWindow *frm = new MainWindow();
    frm->show();
}

void patient::on_pushButton_5_clicked()
{

    char email[] = "admiral230399@gmail.com";
    char password[] = "Vadim2303";

    QString report =  cardReport(patient_card(ui->label_6->text()));
    Smtp * smtp = new Smtp(email, password, "smtp.gmail.com");

    smtp->sendMail(email, ui->lineEdit->text() , "Записи в картці",report);
}


