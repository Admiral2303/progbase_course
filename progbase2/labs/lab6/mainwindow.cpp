#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "dialog.h"
#include <QDebug>
#include <QModelIndex>
#include <QCloseEvent>
#include <QApplication>
#include "dialog1.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    prof.push_back(new profecional("programist",2156,10.56, "Ivan", "Petrenko", 1976));
    prof.push_back(new profecional("teacher",2000,10.56, "Vasya", "Pupkin", 1985));

    foreach (profecional * cur, prof) {
        QVariant qVariant;
        qVariant.setValue(*cur);
        QListWidgetItem * qProfecionalsListItem = new QListWidgetItem();
        qProfecionalsListItem->setText(QString::fromStdString(cur->get_profname()));
        qProfecionalsListItem->setData(Qt::UserRole, qVariant);
        ui->listWidget->addItem(qProfecionalsListItem);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
        if (dialog.exec()) {
            prof.push_back(new profecional(dialog.get_profname(),dialog.get_salary(),dialog.get_score(), dialog.get_name(), dialog.get_surname(), dialog.get_year()));
            ui->listWidget->addItem(QString::fromStdString(prof[prof.size() - 1]->get_profname()));
            profecional * cur = new profecional(dialog.get_profname(),dialog.get_salary(),dialog.get_score(), dialog.get_name(), dialog.get_surname(), dialog.get_year());
            QVariant qVariant;
            qVariant.setValue(*cur);

            QListWidgetItem *qStudentListItem = new QListWidgetItem();
            qStudentListItem->setText(QString::fromStdString(cur->get_profname()));
            qStudentListItem->setData(Qt::UserRole, qVariant);

            //ui->listWidget->addItem(qStudentListItem);
            delete cur;
            qDebug() << "Accepted!";
        } else {
            qDebug() << "Rejected!";
    }

}



void MainWindow::on_listWidget_itemSelectionChanged()
{
    ui->pushButton_2->isEnabled();
    QList<QListWidgetItem *> items = ui->listWidget->selectedItems();
    bool hasselected = items.size() > 0;
    if(hasselected){
        ui->pushButton_2->setEnabled(true);
        int el = (ui->listWidget->currentIndex()).row();
        qDebug() << el << endl;
        ui->label->setText(QString::fromStdString(prof[el]->get_profname()));
        ui->label_2->setText(QString::number(prof[el]->get_salary()));
        ui->label_3->setText(QString::number(prof[el]->get_score()));
        ui->label_4->setText(QString::fromStdString(prof[el]->get_data().get_name()));
        ui->label_5->setText(QString::fromStdString(prof[el]->get_data().get_surname()));
        ui->label_6->setText(QString::number(prof[el]->get_data().get_year()));
    }
    else{
        ui->label->setText("");
        ui->label_2->setText("");
        ui->label_3->setText("");
        ui->label_4->setText("");
        ui->label_5->setText("");
        ui->label_6->setText("");
        ui->pushButton_2->setEnabled(false);
    }
}





void MainWindow::on_pushButton_2_clicked()
{
    int toDelete = ui->listWidget->row( ui->listWidget->selectedItems().first());
    delete ui->listWidget->takeItem(toDelete);
    delete prof[toDelete];
    prof.erase(prof.begin() + toDelete);
}

void MainWindow::on_pushButton_3_clicked()
{

    Dialog1 dialog;
        if (dialog.exec()) {
            ui->listWidget_2->clear();
            for(int i = 0; i < prof.size(); i++){
                  if(prof[i]->get_salary() >  dialog.get_salary()){
                       ui->listWidget_2->addItem(QString::fromStdString(prof[i]->get_profname()));
                  }
            }
            qDebug() << "Accepted!";
        } else {
            qDebug() << "Rejected!";
    }


}



void MainWindow::closeEvent (QCloseEvent *event)
{
    for (profecional * st :prof) {
        delete st;
    }
    qDebug() << "Window closed!";
    event->accept();
}


void MainWindow::on_pushButton_4_clicked()
{
    MainWindow::close();
}


void MainWindow::on_actionfind_triggered()
{
    Dialog1 dialog;
        if (dialog.exec()) {
            ui->listWidget_2->clear();
            for(int i = 0; i < prof.size(); i++){
                  if(prof[i]->get_salary() >  dialog.get_salary()){
                       ui->listWidget_2->addItem(QString::fromStdString(prof[i]->get_profname()));
                  }
            }
            qDebug() << "Accepted!";
        } else {
            qDebug() << "Rejected!";
    }

}
