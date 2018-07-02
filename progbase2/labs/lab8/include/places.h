/**
    @file
    @brief Information about favourite place
*/

#ifndef Places_H
#define Places_H
#include <string>
using namespace std;

/**
    @class Places
    @brief defines a favourite place
*/
class Places
{
    int id;
    string name;
    string location;

public:
    /**
        @brief default constructor for Places
    */
    Places();

     /**
        @brief default public destructor for Place
    */
    ~Places();

    /**
        @brief Constructor of the class
        @param id - object id
        @param name - object name
        @param location - object location
    */
    Places(int id,string name,string location);

    /**
        @brief get object id
        @returns unique number of Place
    */
    int get_id();

    /**
        @brief get object id
        @returns name of Place
    */
    string get_name();
    /**
        @brief get object location
        @returns location of Place
    */
    string get_location();
};

#endif // Places_H