#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include "freelancer.h"
#include <iostream>
#include <QDebug>
#include <QCloseEvent>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    array.insert(array.end(), new Freelancer("Vadim","Scherbina",2156,10.56));
    array.insert(array.end(), new Freelancer("Yaroslav", "Zgurovskiy",3000,17.5));
    array.insert(array.end(), new Freelancer("Illya", "Telefus",1980,11.69));
    array.insert(array.end(), new Freelancer("Dima", "Levchenko",1630,17.39));
    array.insert(array.end(), new Freelancer("Sasha", "Kopyl",1790,18.41));

    ui->label->setText(QString::number(count));
    ui->label_2->setText(QString::fromStdString(array[count]->getname()));
    ui->label_3->setText(QString::fromStdString(array[count]->getsurname()));
    ui->label_4->setText(QString::number(array[count]->getsalary()));
    ui->label_5->setText(QString::number(array[count]->getscore(), 'f', 2));

}

   // string name = array[count]->getname();
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(count > 0){
        count--;
        ui->label->setText(QString::number(count));
        ui->label_2->setText(QString::fromStdString(array[count]->getname()));
        ui->label_3->setText(QString::fromStdString(array[count]->getsurname()));
        ui->label_4->setText(QString::number(array[count]->getsalary()));
        ui->label_5->setText(QString::number(array[count]->getscore(), 'f', 2));
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    if(count != array.size() - 1){
        count++;
        ui->label->setText(QString::number(count));
        ui->label_2->setText(QString::fromStdString(array[count]->getname()));
        ui->label_3->setText(QString::fromStdString(array[count]->getsurname()));
        ui->label_4->setText(QString::number(array[count]->getsalary()));
        ui->label_5->setText(QString::number(array[count]->getscore(), 'f', 2));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    MainWindow::close();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    for (Freelancer * st :array) {
        delete st;
    }
    qDebug() << "Window closed!";
    event->accept();
}


