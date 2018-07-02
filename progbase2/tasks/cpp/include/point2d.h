#pragma once
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    int x;
    int y;
    string name;
public:
    Point(int k, int i,  string name1);
    Point();
    float vectorlength();
    ~Point();
    void Print();
};





