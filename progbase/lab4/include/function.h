#ifndef FUNCTION_H
#define FUNCTION_H
//#include <list.h>


void * text_in_struct1(void * self,char * filename);
void file_output(void * self , char * filename);
void XmlLoader_saveToFile(void * list, const char * filename);
void readAllText(const char * filename, char * text);
void XmlLoader_loadFromFile(void * list, const char * filename);
void JsonLoader_loadFromFile(void * self, const char * filename);
void JsonLoader_saveToFile(char * filename, void * self);


#endif