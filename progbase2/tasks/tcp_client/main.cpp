#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>
#include <string>
#include <progbase.h>
#include <progbase-cpp/net.h>
#include <progbase/net.h>
#include "QDebug"
#include <cmath>
#include "response.h"


using namespace progbase::net;
using namespace std;
void print(vector<int> A);
int main(void)
{
    QString jsonString;
    //std ::string str1;
    vector<int> Array;
    vector<int> final;
    const int serverPort = 3000;
    TcpClient client;
        NetMessage message(100);
        try {
            client.connect(IpAddress("127.0.0.1", serverPort));
            message.setDataString("numbers");
            client.send(message);
            cout << ">> Request sent" << endl;
            do {
                client.receive(message);
                std ::string str = message.dataAsString();
                cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
                jsonString += QString::fromStdString(str);
            } while (!message.isEmpty());
        } catch(NetException const & exc) {
            cerr << exc.what() << endl;
        }
        Response * resp = new Response(jsonString);
        resp->print();
        delete resp;
        return 0;
}

