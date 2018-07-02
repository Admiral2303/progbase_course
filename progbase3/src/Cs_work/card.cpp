#include "card.h"
#include "ui_card.h"
#include <QBrush>
#include <QDesktopWidget>
#include "query.h"

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
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

}

Card::~Card()
{
    delete ui;
}

QString Card:: get_medicament(){
    return ui->LineEdit_4->text();
}

QString Card:: get_analysis(){
    return ui->LineEdit_5->text();
}

QString Card:: get_report(){
    return ui->textEdit->toPlainText();
}

QString Card:: get_diagnosis(){
    return ui->LineEdit_6->text();
}


void Card:: set_enabled(bool en){
    if(en == false){
        ui->LineEdit_4->setEnabled(false);
        ui->LineEdit_5->setEnabled(false);
        ui->LineEdit_6->setEnabled(false);
        ui->textEdit->setEnabled(false);
    }
    else{
        ui->LineEdit_4->setEnabled(true);
        ui->LineEdit_5->setEnabled(true);
        ui->LineEdit_6->setEnabled(true);
        ui->textEdit->setEnabled(true);
    }
}


void Card:: set_medicament(QString str){
    return ui->LineEdit_4->setText(str);
}

void Card:: set_analysis(QString str){
    return ui->LineEdit_5->setText(str);
}
void Card:: set_diagnosis(QString str){
    ui->LineEdit_6->setText(str);
}


void Card:: set_report(QString str){
    return ui->textEdit->setText(str);
}




