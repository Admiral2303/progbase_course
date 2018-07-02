#include "jsonconvert.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "pokemon.h"

//vector<pokemon*> parse(vector<string> jsonvect){
pokemon* parse(string jsonvect){
        pokemon * new_pokemon = new pokemon;
        QString jsonstr = remove_headers(QString::fromStdString(jsonvect/*[i]*/));
        QJsonDocument jdoc = QJsonDocument::fromJson(jsonstr.toUtf8());
        QJsonValue value_name = jdoc.object().value("name");
        new_pokemon->set_name(value_name.toString());
        QJsonValue value_weight = jdoc.object().value("weight");
        new_pokemon->set_weight(value_weight.toInt());

        vector<QString> abilities_aray;
        QJsonValue abilities = jdoc.object().value("abilities");
        QJsonArray array = abilities.toArray();
        foreach (const QJsonValue & v, array){
            QJsonValue ability = v.toObject().value("ability");
            QJsonValue ab = ability.toObject().value("name");
            abilities_aray.push_back(ab.toString());
        }

        QJsonValue value_height = jdoc.object().value("height");
        new_pokemon->set_height(value_height.toInt());

        vector<QString> types_aray;
        QJsonValue types = jdoc.object().value("types");
        QJsonArray array1 = types.toArray();
        foreach (const QJsonValue & v, array1){
            QJsonValue type = v.toObject().value("type");
            QJsonValue type_ad = type.toObject().value("name");
            types_aray.push_back(type_ad.toString());
        }




        new_pokemon->set_abilities(abilities_aray);
        new_pokemon->set_types(types_aray);
        return new_pokemon;
}







QString remove_headers(QString request_str){
    QString jsonstr;
    int flag = 0;
    int k = 0;
    for(int i = 0; i < request_str.size();i++){
        if(request_str[i] == '{'){
            flag = 1;
        }
        if(flag == 1){
            jsonstr[i] = request_str[i];
        }
    }

   //qDebug() << jsonstr;

    return jsonstr;
}







vector<QString> types(string str){

    vector<QString> type;
    QString jsonstr = remove_headers(QString::fromStdString(str));
    QJsonDocument jdoc = QJsonDocument::fromJson(jsonstr.toUtf8());
    QJsonValue results = jdoc.object().value("results");
    QJsonArray array = results.toArray();
    foreach (const QJsonValue & v, array){
        QJsonValue name = v.toObject().value("name");
        type.push_back(name.toString());
    }

    return type;
}













