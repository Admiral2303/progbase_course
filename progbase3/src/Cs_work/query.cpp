#include "query.h"

QSqlQuery load_Doctortable(QString id_doctor){
    QSqlQuery query;
    QString sqlToBuild = "SELECT DISTINCT id_patient,name,surname,introduction_date,palate FROM patient WHERE id_patient!= 0 AND id_doctor = ";
    sqlToBuild += id_doctor;
    const QString sql = sqlToBuild;
    if(!query.exec(sql)){
       qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery add_patient_toDoctor(QString id_doctor, QString id_patient){
    QSqlQuery query;
    QString curdate = QDate::currentDate().toString("yyyy.MM.dd");
    query.prepare("UPDATE patient SET status = 'ill', id_doctor= :id_doctor, introduction_date = :introduction_date WHERE id_patient= :id_patient");
    query.bindValue(0, id_doctor);
    query.bindValue(1, curdate);
    query.bindValue(2, id_patient);

    if(query.exec()){
        qDebug() << "YES";
    }
    else{
        qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery take_infPatient(QString element){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT id_patient,name,surname,birth_date,address,phone_number,introduction_date,notes FROM patient WHERE id_patient= :id_patient");
    query.bindValue(0, element);
    if(!query.exec()){
       qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery update_patientInf(QString name, QString surname, QString birth_date, QString address, QString phone_number, QString introduction_date, QString notes, QString id_patient){
    QSqlQuery query;
    query.prepare("UPDATE patient SET name=:name, surname = :surname, birth_date = :birth_date,address = :address,phone_number = :phone_number,introduction_date = :introduction_date, notes= :notes WHERE id_patient= :id_patient ");
    query.bindValue(0,name);
    query.bindValue(1,surname);
    query.bindValue(2,birth_date);
    query.bindValue(3,address);
    query.bindValue(4,phone_number);
    query.bindValue(5,introduction_date);
    query.bindValue(6,notes);
    query.bindValue(7,id_patient);
    if(query.exec()){}
    return query;
}

QSqlQuery take_observisionInf(){
    QSqlQuery query;
    query.prepare("SELECT id_card,report, diagnosis FROM observation ORDER BY id_observ DESC");
    if(!query.exec()){
        qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery insert_intoDischarged_patients(QString name, QString surname, QString id_doctor, QString disease, QString report, QString date, QString id_card){
    QSqlQuery query;
    query.prepare("INSERT INTO discharge_patients (name, surname,id_doctor, disease, report, date, id_card) VALUES (:name, :surname, :id_doctor, :disease, :report, :date, :id_card)");
    query.bindValue(0, name);
    query.bindValue(1, surname);
    query.bindValue(2, id_doctor);
    query.bindValue(3, disease);
    query.bindValue(4, report);
    query.bindValue(5, date);
    query.bindValue(6,id_card);
    if(!query.exec()){
        qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery insert_intoCard(QString id){
    QSqlQuery query;
    query.prepare("INSERT INTO card (palate, status,id_patient, id_card) values (' ', ' ',:id_patient, id_card)");
    query.bindValue(0, id);
    query.bindValue(1, id);
    if(query.exec()){}
//    sql4 += "'" + this->id(name, surname) + "', ";// + "')";
//    sql4 +="'" + this->id(name, surname) + "')";
    return query;
}

QSqlQuery insert_intoObservision(QString medicament, QString analysis, QString report, QString diagnosis, QString id_card){
    QString curdate = QDate::currentDate().toString("yyyy.MM.dd");
    QSqlQuery query;
    query.prepare("INSERT INTO observation (date, medicament, analysis, report, diagnosis, id_card) VALUES (:date, :medicament, :analysis, :report, :diagnosis, :id_card)"),
    query.bindValue(0, curdate);
    query.bindValue(1, medicament);
    query.bindValue(2, analysis);
    query.bindValue(3, report);
    query.bindValue(4, diagnosis);
    query.bindValue(5, id_card);
    if(!query.exec()){
        qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery take_inf_from_observation_withDate(QString date){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT date, medicament, analysis, diagnosis, report FROM observation WHERE date= :date");
    query.bindValue(0, date);
    if(query.exec()){}
    return query;
}


QSqlQuery take_log_and_pasw_fromDoctor(QString id_doctor){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT login, password, name , surname FROM doctor WHERE id_doctor= :id_doctor");
    query.bindValue(0, id_doctor);
    if(query.exec()){}
    return query;
}

QSqlQuery take_log_and_pasw_fromPatient(QString id_patient){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT login, password, name, surname FROM patient WHERE id_patient=:id_patient ");
    query.bindValue(0,id_patient);
    if(query.exec()){}
    return query;
}

QSqlQuery take_dischargedPatients(QString id_doctor){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT id_card,date,name,surname,disease FROM discharge_patients WHERE id_doctor= :id_doctor");
    query.bindValue(0,id_doctor);
    if(query.exec()){}
    return query;
}


QSqlQuery take_doctorInf(QString str, QString value){
    QSqlQuery query;
    QString sql = "SELECT DISTINCT name,surname,position,cabinet,phone,start_work, rating,atempt,end_work FROM doctor WHERE " + str + " =" +":value";
    query.prepare(sql);
    query.bindValue(0,value);
    if(query.exec()){}
    else{
        qDebug() << query.lastError().text();
    }
    return query;
}

QSqlQuery set_doctor_rating(QString rating,QString atempt, QString name, QString surname){
    QSqlQuery query;
    query.prepare("UPDATE doctor SET rating=:rating, atempt = :atempt WHERE name=:name AND surname = :surname");
    query.bindValue(0,rating);
    query.bindValue(1,atempt);
    query.bindValue(2,name);
    query.bindValue(3,surname);
    if(query.exec()){}
    return query;
}

QSqlQuery get_doctorRecords(QString id_doctor, QString date){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT time FROM doctor_record WHERE id_doctor=:id_doctor AND date=:date");
    query.bindValue(0, id_doctor);
    query.bindValue(1, date);
    if(query.exec()){}
    return query;
}

QSqlQuery delete_doctorRecord(QString id_patient, QString date, QString time){
    QSqlQuery query;
    query.prepare("DELETE FROM doctor_record WHERE id_patient=:id_patient AND date=:date AND time=:time");
    query.bindValue(0,id_patient);
    query.bindValue(1,date);
    query.bindValue(2,time);
    if(query.exec()){}
    return query;
}

QSqlQuery take_time_from_doctorRecord(QString id_doctor, QString date, QString id_patient){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT time FROM doctor_record WHERE id_doctor=:id_doctor AND date=:date AND id_patient=:id_patient");
    query.bindValue(0, id_doctor);
    query.bindValue(1, date);
    query.bindValue(2, id_patient);
    if(query.exec()){}
    return query;
}

QSqlQuery add_newDoctor(QString name, QString surname,QString position,QString cabinet,QString phone, QString login,QString password, QString work_start, QString work_end){
    QSqlQuery query;
    query.prepare("INSERT INTO doctor (name, surname, position,cabinet,phone,login,password, start_work, end_work) VALUES (:name, :surname, :position, :cabinet, :phone, :login, :password, :start_work, :end_work)");
    query.bindValue(0,name);
    query.bindValue(1,surname);
    query.bindValue(2,position);
    query.bindValue(3,cabinet);
    query.bindValue(4,phone);
    query.bindValue(5,login);
    query.bindValue(6,password);
    query.bindValue(7,work_start);
    query.bindValue(8,work_end);
    if(!query.exec()){
       qDebug() << query.lastError().text();
    }
    return query;
}

QSqlQuery update_doctorInf(QString name,QString surname,QString position,QString cabinet,QString phone,QString login,QString password,QString id,QString work_start, QString work_end){
    QSqlQuery query;
    query.prepare("UPDATE doctor SET name = :name, surname = :surname, position = :position, cabinet = :cabinet, phone = :phone, login =:login, password = :password,start_work = :start_work, end_work = :end_work  WHERE id_doctor = :id");
    query.bindValue(0,name);
    query.bindValue(1,surname);
    query.bindValue(2,position);
    query.bindValue(3,cabinet);
    query.bindValue(4,phone);
    query.bindValue(5,login);
    query.bindValue(6,password);
    query.bindValue(7, work_start);
    query.bindValue(8, work_end);
    query.bindValue(9, id);
    if(query.exec()){}
    return query;
}

QSqlQuery get_doctorsInf(){
    QSqlQuery query;
    QString sqlToBuild = "SELECT DISTINCT id_doctor,name,surname,position,cabinet,phone,login,password FROM doctor WHERE id_doctor != 0";
    const QString sql = sqlToBuild;
    if(query.exec(sql)){}
    return query;
}

QSqlQuery get_doctorInf(QString id_doctor){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT name, surname, position, cabinet, phone, login, password FROM doctor WHERE id_doctor =:id_doctor");
    query.bindValue(0, id_doctor);
    if(query.exec()){}
    return query;
}

QSqlQuery take_doctorId(QString name, QString position){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT id_doctor FROM doctor WHERE name=:name AND position = :position");
    query.bindValue(0,name);
    query.bindValue(1,position);
    if(query.exec()){}
    return query;
}

QSqlQuery insert_intoDoctor_record(QString id_doctor, QString id_patient,QString date,QString time,QString name,QString surname){
    QSqlQuery query;
    query.prepare("INSERT INTO doctor_record (id_doctor, id_patient, date, time, name, surname) VALUES (:id_doctor, :id_patient, :date , :time, :name, :surname)");
    query.bindValue(0, id_doctor);
    query.bindValue(1, id_patient);
    query.bindValue(2, date);
    query.bindValue(3, time);
    query.bindValue(4, name);
    query.bindValue(5, surname);
    if(!query.exec()){
       qDebug() << "ERROR: " << query.lastError().text();
    }
    return query;
}

QSqlQuery take_observitionINF(QString id){
    QSqlQuery query;
    query.prepare("SELECT DISTINCT date, medicament, analysis, report, diagnosis FROM observation WHERE id_card =:id_card ");
    query.bindValue(0,id);
    if(query.exec()){}
    return query;
}

QSqlQuery insert_patient(QString name,QString surname,QString birth_date,QString address,QString phone_number,QString introduction_date,QString notes,QString login,QString password){
    QSqlQuery query;
    query.prepare( "INSERT INTO patient (name,surname,birth_date,address,phone_number,introduction_date,notes, login, password) values (:name,:surname,:birth_date,:address,:phone_number,:introduction_date,:notes,:login,:password)");
    query.bindValue(0,name);
    query.bindValue(1,surname);
    query.bindValue(2,birth_date);
    query.bindValue(3,address);
    query.bindValue(4,phone_number);
    query.bindValue(5,introduction_date);
    query.bindValue(6,notes);
    query.bindValue(7,login);
    query.bindValue(8,password);
    if(query.exec()){}
    return query;
}

QSqlQuery take_infpatient_byField(QString str, QString search){
    QString sql = "SELECT DISTINCT id_patient,name,surname,birth_date,address,phone_number,introduction_date,notes FROM patient WHERE " + str + "= :val";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(0, search);
    //if(query.exec()){}
    return query;
}
