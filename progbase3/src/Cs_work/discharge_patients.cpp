#include "discharge_patients.h"
#include "ui_discharge_patients.h"
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include "smtp.h"
#include "report.h"
#include <QDesktopWidget>
#include "query.h"

Discharge_patients::Discharge_patients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Discharge_patients)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/3.jpg"));
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

Discharge_patients::~Discharge_patients()
{
    delete ui;
}

void Discharge_patients:: load_table(QString id_doctor){
    ui->tableWidget->setRowCount(0);
    QSqlQuery query = take_dischargedPatients(id_doctor);
    while (query.next()){
        int rows = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(id_doctor));
        ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(rows, 4, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(rows, 5, new QTableWidgetItem(query.value(4).toString()));
    }
}

void Discharge_patients::on_pushButton_clicked()
{
    char email[] = "admiral230399@gmail.com";
    char password[] = "Vadim2303";

    QString report =  discharged_patientsReport(discharged_patients(ui->label_3->text()));
    Smtp * smtp = new Smtp(email, password, "smtp.gmail.com");

    smtp->sendMail(email, ui->lineEdit->text() , "Виписані пацієнти",report);
}

void Discharge_patients:: set_id(QString id){
    ui->label_3->setText(id);
}
