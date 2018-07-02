#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include <xml_func.h>






struct Freelancer{
    char name[20];
    int salary;
    float score;

};

struct Configuration{
	char filepath[200];
};


void free_freelancer(void * self){
	Freelancer * self1 = self;
	free(self1);
	self1 = NULL;
}


void free_config(void * self){
	Configuration * self1 = self;
	free(self1);
	self1 = NULL;
}


void print1(Freelancer * self){
	printf("\n name: %s;\n salary: %i;\n score: %f;\n", self->name, self->salary, self->score);
	
}





void XmlLoader_saveToFile(struct Freelancer * self, char * filename){
	FILE * fout = fopen(filename, "w");
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	char strBuf[500];
	strBuf[0] = '\0';
	doc = xmlNewDoc(BAD_CAST "1.0");
	rootNode = xmlNewNode(NULL, BAD_CAST "freelancer");
	xmlDocSetRootElement(doc, rootNode);
	xmlNewChild(rootNode, NULL, BAD_CAST "name", BAD_CAST self->name);
	sprintf(strBuf, "%i", self->salary);  
	xmlNewChild(rootNode, NULL, BAD_CAST "salary", BAD_CAST strBuf);
	sprintf(strBuf, "%f", self->score);  
	xmlNewChild(rootNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	char  str[500]; 
	strcpy(str, (char *)bufferPtr->content);
	str[strlen(str)-1] ='\0';
	fprintf(fout,"%s",  str);
	xmlBufferFree(bufferPtr);
	xmlFreeDoc(doc);
	fclose(fout);
}






void XmlLoader_loadFromString(Freelancer * self, const char * xmlStr) {

    xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        if (XML_ELEMENT_NODE == xCur->type) {
            if (XML_ELEMENT_NODE == xCur->type) {		
				char * content = (char *)xmlNodeGetContent(xCur);
				if(xmlStrcmp(xCur->name, BAD_CAST "name") == 0){
					strcpy(self->name, content);
				}
				if(xmlStrcmp(xCur->name, BAD_CAST "salary") == 0){
					self->salary = atoi(content);
				}
				if(xmlStrcmp(xCur->name, BAD_CAST "score") == 0){
					self->score = atof(content);
				}
				xmlFree(content);
            }
	    }
	}
	xmlFreeDoc(xDoc);
    return;
}


void readAllText(const char * filename, char * text) {
	char line[500];
    FILE * fr = fopen(filename, "r");
    if(fr == NULL){
        puts("ERROR");
        return;
    }
    while(fgets(line, 100, fr)) {
        strcat(text, line);
    }
	fclose(fr);
}

void writeAllText(const char * filename, char * text) {
    FILE * fout = fopen(filename, "w");
    for(int i = 0; i < strlen(text); i++){
        fprintf(fout,"%c", text[i]);
    }
	fclose(fout);
}


char * Filepath_get(Configuration * self){
    char* str = malloc(100 * sizeof(char));
    strcpy(str, self->filepath);
    return str;
}







void Freelancer_free(Freelancer ** self){
	free(*self);
    *self = NULL;
}



Freelancer * Freelancer_new(void){
	Freelancer * self = malloc(sizeof(struct Freelancer));
	strcpy(self->name, "");
	self->salary = 0;
	self->score = 0.0;
	return self;
}



void XmlLoader_loadConfiguration(Configuration * self, char * filename) {
	char xmlStr[2000];
	xmlStr[0] = '\0';
	readAllText(filename, xmlStr);
    xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        if (XML_ELEMENT_NODE == xCur->type) {
			char * content = (char *)xmlNodeGetContent(xCur);
			if(xmlStrcmp(xCur->name, BAD_CAST "filepath") == 0){
				strcpy(self->filepath, content);
			}
			xmlFree(content);
         }
    }
	xmlFreeDoc(xDoc);
    return;
}


Configuration * Conf_new(){
    Configuration * self = malloc(sizeof(struct Configuration));
    return self;
}

void prnt(Configuration * self){
    printf("%s", self->filepath);
}





void Save_configuration(char * filename, Configuration * self){
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	doc = xmlNewDoc(BAD_CAST "1.0");
	rootNode = xmlNewNode(NULL, BAD_CAST "config");
	xmlDocSetRootElement(doc, rootNode);
	xmlNewChild(rootNode, NULL, BAD_CAST "filepath", BAD_CAST self->filepath);
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	writeAllText(filename, (char *)bufferPtr->content);
	xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
}


void change_filepath(Configuration * self, char * str){
    strcpy(self->filepath, str);
}


void set_Name(Freelancer * self, char * name){
	strcpy(self->name, name);
}
void set_Salary(Freelancer * self, int salary){
	self->salary = salary;
}
void set_Score(Freelancer * self, float score){
	self->score = score;
}


