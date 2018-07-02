#ifndef JSON_H
#define JSON_H

typedef struct Freelancer Freelancer;
typedef struct Client Client;

void JsonLoader_saveToString(char * str, Freelancer * self);
void readAllText(const char * filename, char * text);
void JsonLoader_loadFromString(Freelancer * self, char * jsonStr);
Client * new_Client(char * name);
Freelancer * Freelancer_new(void);
void Client_free(void ** self);
void Freelancer_free(Freelancer ** self);
Freelancer * sample(void);
void * listget(Freelancer * self);
void Client1_free(Client ** self);
void print(Freelancer * self);

#endif