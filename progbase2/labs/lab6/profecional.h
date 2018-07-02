#ifndef PROFECIONAL_H
#define PROFECIONAL_H
#include <string>
#include <QMetaType>
using namespace std;






class employee
{
private:
    string name;
    string surname;
    int year;
public:
   employee();
   employee(string name, string surname, int year);
   string get_name();
   string get_surname();
   int get_year();
   void set_name(string name);
   void set_surname(string surname);
   void set_year(int year);
};


class profecional
{
private:
    string profname;
    int salary;
    float score;
    employee data;
public:
    profecional();
    profecional(string profname, int salary, float score, string name, string surname, int year);
    string get_profname();
    int get_salary();
    float get_score();
    void set_profname(string profname);
    employee get_data();
};

Q_DECLARE_METATYPE(profecional)

#endif // PROFECIONAL_H
