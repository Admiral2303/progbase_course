#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

using namespace std;

class Request{
    string path;
    string key;
    string value;
public:
    Request();
    Request(string request);
    ~Request();
    string get_path();
    string get_key();
    string get_value();
};

#endif //REQUEST_H