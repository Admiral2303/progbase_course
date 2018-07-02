#ifndef FREELANCER_H
#define FREELANCER_H
#include <string>
using namespace std;

class Freelancer
{
private:
    string name;
    string surname;
    int salary;
    float score;
public:
    Freelancer(string name, string surname, int salary, float score);
    Freelancer();
    ~Freelancer();
    string getname();
    string getsurname();
    int getsalary();
    float getscore();
};





#endif // FREELANCER_H
