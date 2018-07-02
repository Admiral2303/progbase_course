#include "patient_card.h"
#include "ui_patient_card.h"
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include <QDesktopWidget>
#include "query.h"

Patient_card::Patient_card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Patient_card)
{
    ui->setupUi(this);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/3.jpg"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);

}

Patient_card::~Patient_card()
{
    delete ui;
}


void Patient_card:: load_table(QString id){
    ui->tableWidget->setRowCount(0);
    QSqlQuery query = take_observitionINF(id);
    while (query.next()){
        int rows = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(query.value(4).toString()));
    }
}

void Patient_card:: set_id(QString id){
    ui->label_2->setText(id);
}
