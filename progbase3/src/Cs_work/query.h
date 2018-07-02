#ifndef QUERY_H
#define QUERY_H
#include <QSqlError>

#include <QtSql>
#include <QSqlDriver>

QSqlQuery load_Doctortable(QString id_doctor);
QSqlQuery add_patient_toDoctor(QString id_doctor, QString id_patient);
QSqlQuery take_infPatient(QString element);
QSqlQuery update_patientInf(QString name, QString surname, QString birth_date, QString address, QString phone_number, QString introduction_date, QString notes, QString id_patient);
QSqlQuery take_observisionInf();
QSqlQuery insert_intoDischarged_patients(QString name, QString surname, QString id_doctor, QString disease, QString report, QString date, QString id_card);
QSqlQuery insert_intoCard(QString id);
QSqlQuery insert_intoObservision(QString medicament, QString analysis, QString report, QString diagnosis, QString id_card);
QSqlQuery take_inf_from_observation_withDate(QString date);
QSqlQuery take_log_and_pasw_fromDoctor(QString id_doctor);
QSqlQuery take_log_and_pasw_fromPatient(QString id_patient);
QSqlQuery take_dischargedPatients(QString id_doctor);
QSqlQuery take_doctorInf(QString str, QString value);
QSqlQuery set_doctor_rating(QString rating,QString atempt, QString name, QString surname);
QSqlQuery get_doctorRecords(QString id_doctor, QString date);
QSqlQuery delete_doctorRecord(QString id_patient, QString date, QString time);
QSqlQuery take_time_from_doctorRecord(QString id_doctor, QString date, QString id_patient);
QSqlQuery add_newDoctor(QString name, QString surname,QString position,QString cabinet,QString phone, QString login,QString password, QString work_start, QString work_end);
QSqlQuery update_doctorInf(QString name,QString surname,QString position,QString cabinet,QString phone,QString login,QString password,QString id,QString work_start, QString work_end);
QSqlQuery get_doctorsInf();
QSqlQuery take_doctorId(QString name, QString position);
QSqlQuery insert_intoDoctor_record(QString id_doctor, QString id_patient,QString date,QString time,QString name,QString surname);
QSqlQuery take_observitionINF(QString id);
QSqlQuery get_doctorInf(QString id_doctor);
QSqlQuery insert_patient(QString name,QString surname,QString birth_date,QString address,QString phone_number,QString introduction_date,QString notes,QString login,QString password);
QSqlQuery take_infpatient_byField(QString str, QString search);



#endif // QUERY_H
