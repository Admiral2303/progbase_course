#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H
#include <iostream>
#include <vector>
#include <pokemon.h>
using namespace std;



//vector<string> tcpWebClient(int count);
vector<pokemon*> get_pokemons(int count);
vector<QString> Pokemons_types();
//string Pokemons_types();


#endif // TCP_CLIENT_H
