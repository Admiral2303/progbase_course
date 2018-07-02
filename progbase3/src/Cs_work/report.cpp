#include "report.h"
#include <iostream>
#include <QString>
#include <QSqlError>
#include <QtSql>
#include <QSqlDriver>
#include <vector>

using namespace std;


vector<discharged_patient> discharged_patients(QString id_doctor){
    QSqlQuery query;
    vector<discharged_patient> dp;
    query.prepare("SELECT DISTINCT id_card, date, name, surname, disease, report FROM discharge_patients WHERE id_doctor= :id_doctor");
    query.bindValue(0, id_doctor);
    if(!query.exec()){
       qDebug() << "ERROR: " << query.lastError().text();
    }
    while(query.next()){
         discharged_patient patient;
         patient.id_card = query.value(0).toString();
         patient.date = query.value(1).toString();
         patient.name = query.value(2).toString();
         patient.surname = query.value(3).toString();
         patient.disease = query.value(4).toString();
         patient.report = query.value(5).toString();
         dp.push_back(patient);
    }

    return dp;
}

QString discharged_patientsReport(vector<discharged_patient> dp){
    QString report;
    for(int i = 0; i < dp.size(); i++){
        report += "id Картки: " + dp[i].id_card + "\n";
        report += "Дата: " + dp[i].date + "\n";
        report += "Імя: " + dp[i].name + "\n";
        report += "Прізвище: " + dp[i].surname + "\n";
        report += "Хвороба: " + dp[i].disease + "\n";
        report += "Додаток: " + dp[i].report + "\n\n\n";
    }
    return report;
}


vector<card> patient_card(QString id_card){
    QSqlQuery query;
    vector<card> self;
    query.prepare("SELECT DISTINCT date, medicament, analysis, report, diagnosis FROM observation WHERE id_card= :id_card");
    query.bindValue(0, id_card);
    if(!query.exec()){
       qDebug() << "ERROR: " << query.lastError().text();
    }
    while(query.next()){
         card patient_card;
         patient_card.date = query.value(0).toString();
         patient_card.medicament = query.value(1).toString();
         patient_card.analysis = query.value(2).toString();
         patient_card.report = query.value(3).toString();
         patient_card.diagnosis = query.value(4).toString();
         self.push_back(patient_card);
    }

    return self;
}


QString cardReport(vector<card> p_card){
    QString report;
    for(int i = 0; i < p_card.size(); i++){
        report += "Дата: " + p_card[i].date + "\n";
        report += "Ліки: " + p_card[i].medicament + "\n";
        report += "Аналізи: " + p_card[i].analysis + "\n";
        report += "Додаток: " + p_card[i].report + "\n";
        report += "Діагноз: " + p_card[i].diagnosis + "\n\n\n";
    }
    return report;
}

QString help_report(QString name , QString surname, QString rep){
    QString report;
    report += "Ім'я: " + name + ";\n";
    report += "Прізвище: " + surname + ";\n";
    report += "Повідомлення: " + rep + ";\n";
    return report;
}
