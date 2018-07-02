#ifndef CARD_H
#define CARD_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>
#include <QTableWidget>
#include "doctor.h"

namespace Ui {
class Card;
}

class Card : public QDialog
{
    Q_OBJECT

public:
    explicit Card(QWidget *parent = 0);
    ~Card();
  //  QString get_palate();
  //  QString  get_date();
    QString  get_medicament();
    QString  get_analysis();
    QString  get_report();
    QString  get_status();
    QString  get_diagnosis();
    void set_enabled(bool en);
    void set_status(QString str);
    void set_report(QString str);
    void set_analysis(QString str);
    void set_medicament(QString str);
  //  void set_date(QString str);
    //void set_palate(QString str);
    void set_diagnosis(QString str);


private slots:


private:
    Ui::Card *ui;
};

#endif // CARD_H
