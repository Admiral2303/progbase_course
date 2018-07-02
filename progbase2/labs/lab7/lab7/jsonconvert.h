#ifndef JSONCONVERT_H
#define JSONCONVERT_H
#include <iostream>
#include<vector>
#include <QString>
#include "pokemon.h"

using namespace std;

pokemon* parse(string jsonvect);
//vector<pokemon*> parse(vector<string> jsonvect);
QString remove_headers(QString str);
vector<QString> types(string str);



#endif // JSONCONVERT_H
