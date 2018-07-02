#ifndef RESPONSE_H
#define RESPONSE_H
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>
#include <string>
#include "QDebug"
#include <cmath>
#include <vector>

using namespace std;
class Response
{
    bool status;
    vector<int> numbers;
    QString error;
public:
    Response(QString jsonString);
    void print();
};

#endif // RESPONSE_H
