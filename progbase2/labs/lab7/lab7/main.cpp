#include "mainwindow.h"
#include <QApplication>
#include "tcp_client.h"
#include <QDebug>
#include <iostream>
#include <string>
#include <jsonconvert.h>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
