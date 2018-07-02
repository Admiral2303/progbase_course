#include "help.h"
#include "ui_help.h"
#include "smtp.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/index.jpeg"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
}

Help::~Help()
{
    delete ui;
}

QString Help:: get_name(){
    return ui->LineEdit->text();
}

QString Help:: get_surname(){
    return ui->LineEdit_2->text();
}

QString Help:: get_report(){
    return ui->textEdit->toPlainText();
}

void Help::on_pushButton_clicked()
{

}
