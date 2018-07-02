#include "point2d.h"



Point :: Point(int k, int i, string name1){
    x = k;
    y = i;
    name = name1;
}

float Point :: vectorlength(){
    float length = 0;
    length = sqrt(x * x + y * y);
    return length;
}
 Point::Point():x(0),y(0),name(""){}
 
 Point::~Point(){}

 void Point :: Print(){
     cout << "Coord x: " << x << endl;
     cout << "Coord y: " << y << endl;
     cout << "Name: " << name << endl;
 }
