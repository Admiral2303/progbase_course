#include "mainwindow.h"
#include <QSqlDriver>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>
#include <iostream>
#include "ui_doctor.h"
#include "doctor.h"
#include "report.h"
#include <QDesktopWidget>



using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qDebug() << "sqlite not available";
        return 1;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("/home/vadim/COURSE_WORK/cs_work");
    if(!db.open()) {
        qDebug() << "ERROR: " << db.lastError();
        return 1;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
