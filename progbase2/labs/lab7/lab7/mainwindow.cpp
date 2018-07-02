#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QCloseEvent>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pokemons = get_pokemons(2);
    type = Pokemons_types();
    foreach (pokemon * cur, pokemons) {
        QVariant qVariant;
        qVariant.setValue(*cur);
        QListWidgetItem* qPokemonsListItem = new QListWidgetItem();
        qPokemonsListItem->setText(cur->get_name());
        qPokemonsListItem->setData(Qt::UserRole, qVariant);
        ui->listWidget->addItem(qPokemonsListItem);
    }

    for(auto item : type){
        ui->comboBox_3->addItem(item);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_listWidget_itemSelectionChanged()
{
    QList<QListWidgetItem *> items = ui->listWidget->selectedItems();
    bool hasselected = items.size() > 0;
    if(hasselected){
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        int el = (ui->listWidget->currentIndex()).row();
        ui->nameLineEdit->setText(pokemons[el]->get_name());
        ui->weightLineEdit->setText(QString::fromStdString(to_string(pokemons[el]->get_weight())));
        ui->heightLineEdit->setText(QString::fromStdString(to_string(pokemons[el]->get_height())));
        vector<QString> abilities = pokemons[el]->get_abilities();
        for(int i = 0; i < abilities.size(); i++){
            ui->comboBox->addItem(abilities[i]);
        }

        vector<QString> types = pokemons[el]->get_types();
        for(int i = 0; i < types.size(); i++){
            ui->comboBox_2->addItem(types[i]);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox_3->currentText() == "ALL"){
        foreach (pokemon * cur, pokemons) {
            QVariant qVariant;
            qVariant.setValue(*cur);
            QListWidgetItem * qPokemonsListItem = new QListWidgetItem();
            qPokemonsListItem->setText(cur->get_name());
            qPokemonsListItem->setData(Qt::UserRole, qVariant);
            ui->listWidget->addItem(qPokemonsListItem);
        }
    }
    else{
        ui->listWidget->clear();
        QString type_s = ui->comboBox_3->currentText();
        for(int i = 0; i < pokemons.size();i++){
            vector<QString> types = pokemons[i]->get_types();
            for(int k = 0; k < types.size();k++){
                if(types[k] == type_s){
                    QVariant qVariant;
                    qVariant.setValue(*pokemons[i]);
                    QListWidgetItem * qPokemonsListItem = new QListWidgetItem();
                    qPokemonsListItem->setText(pokemons[i]->get_name());
                    qPokemonsListItem->setData(Qt::UserRole, qVariant);
                    ui->listWidget->addItem(qPokemonsListItem);
                }
            }
        }
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    ui->listWidget->clear();
    for (pokemon * st :pokemons) {
        delete st;
    }
    qDebug() << "Window closed!";
    event->accept();
}


void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::close();
}
