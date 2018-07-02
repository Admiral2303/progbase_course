#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <QString>
#include <vector>
#include <QMetaType>

using namespace std;

class pokemon
{
    QString name;
    int weight;
    int height;
    vector<QString> abilities;
    vector<QString> types;

public:
    pokemon();
    void set_name(QString name);
    void set_weight(int weight);
    void set_abilities(vector<QString>);
    void set_types(vector<QString>);
    void set_height(int height);
    void print();
    QString get_name();
    int get_height();
    int get_weight();
    vector<QString> get_abilities();
    vector<QString> get_types();

};
Q_DECLARE_METATYPE(pokemon)

#endif // POKEMON_H
