#ifndef XML_FUNC_H
#define XML_FUNC_H


typedef struct Freelancer Freelancer;
typedef struct Client Client;
typedef struct Configuration Configuration;



void XmlLoader_saveToFile(struct Freelancer * self, char * filename);
void XmlLoader_loadFromString(Freelancer * self, const char * filename);


Freelancer * sample(void);
void Freelancer_free(Freelancer ** self);
void * listget(Freelancer * self);
Freelancer * Freelancer_new(void);
void print(Freelancer * self);

void readAllText(const char * filename, char * text);
void XmlLoader_loadConfiguration(Configuration * self, char * filename);
Configuration * Conf_new();
void prnt(Configuration * self);
void Save_configuration(char * filename, Configuration * self);
void change_filepath(Configuration * self, char * str);
void writeAllText(const char * filename, char * text);
char * Filepath_get(Configuration * self);
void print1(Freelancer * self);


void set_Name(Freelancer * self, char * name);
void set_Salary(Freelancer * self, int salary);
void set_Score(Freelancer * self, float score);



void free_config(void * self);
void free_freelancer(void * self);


#endif