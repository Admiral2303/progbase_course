
#ifndef REPORT_H
#define REPORT_H
#include <iostream>
#include <vector>
#include <QString>

using namespace std;

typedef struct{
    QString id_card;
    QString date;
    QString name;
    QString surname;
    QString disease;
    QString report;
}discharged_patient;



typedef struct{
    QString date;
    QString medicament;
    QString analysis;
    QString report;
    QString diagnosis;
}card;

vector<discharged_patient> discharged_patients(QString id_doctor);
QString discharged_patientsReport(vector<discharged_patient> dp);

vector<card> patient_card(QString id_card);
QString cardReport(vector<card> p_card);
QString help_report(QString name , QString surname, QString rep);

#endif // REPORT_H
