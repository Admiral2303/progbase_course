#include "mainwindow.h"
#include <QApplication>
#include "freelancer.h"
#include <vector>
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    vector<Freelancer*> array;


//    array.insert(array.end(), new Freelancer("vadim","scherbina",2156,10.56));
//    array.insert(array.end(), new Freelancer("dima", "levchenko",1980,11.69));
//    cout << array[0]->getname();

    return a.exec();
}
