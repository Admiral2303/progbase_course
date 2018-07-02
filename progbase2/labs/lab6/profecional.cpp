#include "profecional.h"

using namespace std;

profecional::profecional(){}

employee:: employee(){};

employee:: employee(string name, string surname, int year){
    this->name = name;
    this->surname = surname;
    this->year = year;
}

 profecional:: profecional(string profname, int salary, float score, string name, string surname, int year){
    this->profname = profname;
    this->salary = salary;
    this->score = score;
    this->data.set_name((name));
    this->data.set_surname(surname);
    this->data.set_year(year);
}

 void employee:: set_name(string name){
    this->name = name;
 }

 void employee:: set_surname(string surname){
    this->surname = surname;
 }

 void employee:: set_year(int year){
    this->year = year;
 }



string profecional ::  get_profname(){
    return this->profname;
}

int profecional :: get_salary(){
    return this->salary;
}

float profecional :: get_score(){
    return this->score;
}


employee profecional :: get_data(){
    return this->data;
}

string employee :: get_name(){
    return this->name;
}

string employee :: get_surname(){
    return this->surname;
}
int employee :: get_year(){
    return this->year;
}

void profecional :: set_profname(string profname){
    this->profname = profname;
}
