#ifndef XML_H
#define XML_H


typedef struct Freelancer Freelancer;
typedef struct Client Client;





void XmlLoader_saveToString(char * str, Freelancer * self);
void XmlLoader_loadFromString(Freelancer * self, const char * xmlStr);
Client * new_Client(char * name);
void Client_free(Client ** self);
void Client1_free(void ** self);
Freelancer * sample(void);
void Freelancer_free(Freelancer ** self);
void * listget(Freelancer * self);
Freelancer * Freelancer_new(void);
void print(Freelancer * self);


	 


#endif
