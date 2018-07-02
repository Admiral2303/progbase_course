#include "freelancer.h"
#include <string>




Freelancer :: Freelancer(string name, string surname, int salary, float score){
    this->name = name;
    this->surname = surname;
    this->salary = salary;
    this->score = score;
}

Freelancer:: Freelancer(){}

Freelancer :: ~Freelancer(){}



string Freelancer ::  getname(){
    return this->name;
}

string Freelancer ::  getsurname(){
    return this->surname;
}

int Freelancer ::  getsalary(){
    return this->salary;
}

float Freelancer ::  getscore(){
    return this->score;
}
