#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include "freelancer.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    array.insert(array.end(), new Freelancer("vadim","scherbina",2156,10.56));
    array.insert(array.end(), new Freelancer("dima", "levchenko",1980,11.69));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string name = array[count]->getname();

    ui->labels->setText(QString::fromStdString(name));
    count--;

}

void MainWindow::on_pushButton_2_clicked()
{
//    vector<Freelancer*> array;


    string name = array[count]->getname();
    string surname = array[count]->getsurname();
    int salary = array[count]->getsalary();
//    float score = array[count]->getscore();
    ui->label_2->setText(QString::fromStdString(name));
    ui->label_3->setText(QString::fromStdString(surname));
    ui->label_4->setText(QString::number(salary));
  //  ui->label_4->setText(QString::());
    count++;
}
