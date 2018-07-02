/**
    @file
    @brief Module to convert data to Json string
*/
#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H
#include <iostream>
#include <vector>
#include "places.h"
using namespace std;

/**
    @brief get server information
    @return Json string that contains information about server
*/
string serverInformation(string servername, string developer);

/**
    @brief get all places in Json fromat
    @param place - vector of my favourites Places 
    @return string in Json format that contain information about all places
*/
string myFavouritePlaces(vector<Places*> place);


/**
    @brief get information about my favourites places with some location
    @param place - the vector with my favourite places
    @param message - HTTP request to server
    @returns json string which contains information about selected places
*/
string locationPlace(vector<Places*> place, string message);

/**
    @brief get information about my favourites places with some id
    @param place - the vector with my favourite places
    @param message - HTTP request to server
    @returns json string which contains information about place with selected id
*/
string idPlace(vector<Places*> place, string message);

/**
    @brief Take data from file
    @returns json string which contains information about file size, file name and file data
*/
string fileInformation();

/**
    @brief Calculate letters in Upper register and in Lower
    @returns information about letters in Upper register and in Lower
*/
string fileLetters();








#endif //JSONCONVERTER_H