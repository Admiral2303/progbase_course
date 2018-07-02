#include "tcp_client.h"
#include <progbase-cpp/net.h>
#include <iostream>
#include <pokemon.h>
#include <jsonconvert.h>

using namespace std;
using namespace progbase::net;



vector<pokemon*> get_pokemons(int count) {
    vector<string> final_str;
    //"GET /api/v2/pokemon/1/ HTTP/1.0\r\nHost: pokeapi.co\r\n\r\n"
    for(int i = 1; i <= count;i++){
        string jsonstr = "";
        TcpClient client;
        NetMessage message(100);
        string set = "GET /api/v2/pokemon/" + to_string(i) + "/ HTTP/1.0\r\nHost: pokeapi.co\r\n\r\n";
        cout << set;
        try {
            client.connect(IpAddress(Ip::resolveHostname("pokeapi.co"), 80));
            message.setDataString(set);
            client.send(message);
            cout << ">> Request sent" << endl;
            do {
                client.receive(message);
                std::string str = message.dataAsString();
                jsonstr += str;
                //cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
            } while (!message.isEmpty());
        } catch(NetException const & exc) {
            cerr << exc.what() << endl;
        }
        final_str.push_back(jsonstr);
   }
   vector<pokemon*> pokemons;
   for(int i = 0; i < final_str.size();i++){
       pokemon *pokem = parse(final_str[i]);
       pokemons.push_back(pokem);
   }
   return pokemons;
}


vector<QString> Pokemons_types() {
        string jsonstr = "";
        TcpClient client;
        NetMessage message(100);
        try {
            client.connect(IpAddress(Ip::resolveHostname("pokeapi.co"), 80));
            message.setDataString("GET /api/v2/type/ HTTP/1.0\r\nHost: pokeapi.co\r\n\r\n");
            client.send(message);
            cout << ">> Request sent" << endl;
            do {
                client.receive(message);
                std::string str = message.dataAsString();
                jsonstr +=str;
                //cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
            } while (!message.isEmpty());
        } catch(NetException const & exc) {
            cerr << exc.what() << endl;
        }
         vector<QString> type = types(jsonstr);
    return type;
}






