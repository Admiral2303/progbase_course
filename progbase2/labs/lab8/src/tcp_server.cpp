

#include <progbase-cpp/net.h>
#include <iostream>
#include <vector>
#include "places.h"
#include "tcp_server.h"
#include <fstream>
#include <ctype.h>
#include <string>
#include <jansson.h>
#include <time.h>
#include <stdio.h>
#include "jsonconverter.h"
#include "request.h"

using namespace std;
using namespace progbase::net;



int tcpServer() {
//int main(void){
    vector<Places*> place;
    place.push_back(new Places(0,"Sofievka", "Uman"));
    place.push_back(new Places(1,"Flora", "Uman"));
    place.push_back(new Places(2,"Golden gates", "Kiev"));
    place.push_back(new Places(3,"Maidan Nesalegnosti", "Kiev"));

    const int serverPort = 3110;
    TcpListener listener;
    NetMessage message(1000);
    string servername = "LOCAL";
    string developer = "Vadim Scherbina";
    //QTime currTime = QTime::currentTime();
    try {
        listener.bind(IpAddress("127.0.0.1", serverPort));
        listener.start();
        while (true) {
            cout << ">> Waiting for clients at " << serverPort << "..." << endl;
            TcpClient * client = listener.accept();
            client->receive(message);
            cout << ">> Received: " << endl << message.dataAsString() << endl;
            Request * req = new Request(message.dataAsString());
            // if( message.dataAsString().find("GET / HTTP/1.1") != string::npos){
            //     message.setDataString(serverInformation(servername, developer));
            // } else
            // 
            if(req->get_path() == "/"){
                message.setDataString(serverInformation(servername, developer));
            }else
            if(req->get_path()== "/favorites"){
                message.setDataString(myFavouritePlaces(place));
            }
             else
            if(req->get_path().find("/favorites?") != string::npos){
                message.setDataString(locationPlace(place, message.dataAsString()));

            } else
            if(req->get_path().find("/favorites/") != string::npos){
                message.setDataString(idPlace(place, message.dataAsString()));
            } else
            if(req->get_path()=="/file"){
                message.setDataString(fileInformation());
                     
            } else
            if(req->get_path()== "/file/data" && req->get_value() == "data"){
                message.setDataString(fileLetters());
            }
            else{
                 message.setDataString("Bad request");
            } 
            client->send(message);
            cout << ">> Response sent." << endl;
            delete client;
        }
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}

