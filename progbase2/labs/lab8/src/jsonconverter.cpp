#include <iostream>
#include <vector>
#include "places.h"
#include "tcp_server.h"
#include <fstream>
#include <ctype.h>
#include <string>
#include <jansson.h>
#include <string.h>

using namespace std;


string serverInformation(string servername, string developer){
    time_t rawtime;
    struct tm * timeinfo; 
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    json_t * json = json_object();               
    json_object_set_new(json, "title", json_string(servername.c_str()));
    json_object_set_new(json, "developer", json_string(developer.c_str()));
    json_object_set_new(json, "time", json_string(asctime (timeinfo)));
    string jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    return jsonString;
}


string myFavouritePlaces(vector<Places*> place){
    json_t * array = json_array(); 
    for(int i = 0; i < place.size(); i++){
        json_t * json = json_object();
        json_object_set_new(json, "id", json_integer(place[i]->get_id()));
        json_object_set_new(json, "name", json_string(place[i]->get_name().c_str()));
        json_object_set_new(json, "location", json_string(place[i]->get_location().c_str()));
        json_array_append(array, json);
        json_decref(json);
    }
    string jsonString = json_dumps(array, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    return jsonString;
}


string locationPlace(vector<Places*> place, string message){
    json_t * array = json_array(); 
    string get = "GET /favorites?location=";
    int i = get.size();
    string key = "";
    while(message[i] != ' '){
        key += message[i];
        i++;
    }
    // return key;
    //string search = get_key(message.dataAsString());
    string jsonString;
    int flag = 0;
    for(int i = 0; i < place.size();i++){
        if(place[i]->get_location() == key){
            json_t * json = json_object();
            json_object_set_new(json, "id", json_integer(place[i]->get_id()));
            json_object_set_new(json, "name", json_string(place[i]->get_name().c_str()));
            json_object_set_new(json, "location", json_string(place[i]->get_location().c_str()));
            json_array_append(array, json);
            json_decref(json);
            flag = 1;
        }
        if(flag == 0){
            jsonString = "404 Not found";
        }
    }
    if(flag == 1){
        jsonString = json_dumps(array, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    }

    return jsonString;
}


string idPlace(vector<Places*> place, string message){
    string get = "GET /favorites/";
    int i = get.size();
    string num = "";
    for(; message[i] != ' '; i++){
        num += message[i];
    }
    int id = stoi(num);
    string jsonString;
    int flag = 0;
    for(int i = 0; i < place.size();i++){
        if(place[i]->get_id() == id){
            json_t * json = json_object();
            json_object_set_new(json, "id", json_integer(place[i]->get_id()));
            json_object_set_new(json, "name", json_string(place[i]->get_name().c_str()));
            json_object_set_new(json, "location", json_string(place[i]->get_location().c_str()));
            jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
            flag = 1;
        }
        if(flag == 0){
            jsonString = "404 Not found";
        }

    }
    return jsonString;
}

string fileInformation(){
    string line;
    string text;
    ifstream myfile ("/home/vadim/lab8/data/data.txt");
    if (myfile.is_open()){
        while (! myfile.eof() ){
        getline (myfile,line);
        text += line;
    }
    myfile.close();
    }
   
    json_t * json = json_object();
    json_object_set_new(json, "name", json_string("data.txt"));
    fstream file("/home/vadim/lab8/data/data.txt");
    int size = 0;
    file.seekg (0, std::ios::end);
    size = file.tellg();
    json_object_set_new(json, "size", json_integer(size));
    json_object_set_new(json, "content", json_string(text.c_str()));
    string jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    cout << jsonString;
    return jsonString;
}

string fileLetters(){
    string line;
    string text;
    ifstream myfile ("/home/vadim/lab8/data/data.txt");
    if (myfile.is_open()){
        while (! myfile.eof() ){
            getline (myfile,line);
            text += line;
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 
    int lower = 0;
    int upper = 0;
    for(int i = 0; i < text.size(); i++){
        if(islower(text[i])){
            lower++;
        }
        if(isupper(text[i])){
            upper++;
        }
    }
    json_t * json = json_object();
    json_object_set_new(json, "lower", json_integer(lower));
    json_object_set_new(json, "upper", json_integer(lower));
    string jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    return jsonString;
}
