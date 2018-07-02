#include "pokemon.h"
#include <QDebug>

pokemon::pokemon()
{

}

void pokemon:: set_name(QString name){
    this->name = name;
}

void pokemon:: set_weight(int weight){
    this->weight = weight;
}

void pokemon:: set_abilities(vector<QString> abilities){
    this->abilities = abilities;
}

void pokemon:: set_height(int height){
    this->height = height;
}

void pokemon:: set_types(vector<QString> types){
    this->types = types;
}

QString pokemon:: get_name(){
    return this->name;
}

int pokemon:: get_height(){
    return this->height;
}

int pokemon:: get_weight(){
    return this->weight;
}

vector<QString> pokemon:: get_abilities(){
    return this->abilities;
}

vector<QString> pokemon:: get_types(){
    return this->types;
}


void pokemon:: print(){
    qDebug() << "name: " << this->name;
    qDebug() << "weight: " << this->weight;
    qDebug() << "height:" << this->height;
    for(int i = 0; i < this->abilities.size(); i++){
        qDebug()<<"ability: " << this->abilities[i];
    }
    for(int i = 0; i < this->types.size(); i++){
        qDebug()<<"type: " << this->types[i];
    }
    qDebug() << "\n";
}
