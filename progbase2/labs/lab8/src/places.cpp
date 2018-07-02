

#include "places.h"
Places::Places(){
    this->name = "";
    this->id = 0;
    this->location = "";
}

Places:: ~Places(){}

Places::Places(int id,string name,string location)
{
    this->name = name;
    this->id = id;
    this->location = location;
}

int Places:: get_id(){
    return this->id;
}


string Places:: get_name(){
    return this->name;
}


string Places:: get_location(){
    return this->location;
}