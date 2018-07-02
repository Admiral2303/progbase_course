#include "request.h"
#include <iostream>
#include <cctype>

using namespace std;

Request::Request(){
    path = "";
    key = "";
    value = "";
}

Request::Request(string request){
    int endmethod = request.find(" ");
    int endpath = request.find(" HTTP/1.1");
    string path1 = string(request, endmethod + 1, endpath - endmethod - 1);
    path = path1;
    int query1 = path.find("?");
    int query2 = path.find("=");
    if(query1 != string::npos){
        key = string(path, query1 + 1, query2 - query1 - 1);
    } 
    if(query2 != string::npos){
        value = string(path, query2 + 1, path.length() - query2);
    } else {
        int findslash = path.find("/", 1);
        value = string(path, findslash + 1, path1.length() - findslash);
    }
}

Request::~Request(){}

string Request::get_path(){
     return path; 
}
string Request::get_key(){
     return key;
}
string Request::get_value(){
     return value; 
}