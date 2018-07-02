#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "xml.h"
#include "list.h"

struct Client {
	char  name1[20];
};



struct Freelancer{
    char name[20];
    int salary;
    float score;
    List * client;
};


void XmlLoader_saveToString(char * str, struct Freelancer * self){
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * freelancerNode = NULL;
	xmlNode * clientNode = NULL;
	char strBuf[100];
	doc = xmlNewDoc(BAD_CAST "1.0");
	rootNode = xmlNewNode(NULL, BAD_CAST "freelancers");
	xmlDocSetRootElement(doc, rootNode);
	freelancerNode = xmlNewChild(rootNode, NULL, BAD_CAST "freelancer", NULL);
	xmlNewChild(freelancerNode, NULL, BAD_CAST "name", BAD_CAST self->name);
	sprintf(strBuf, "%i", self->salary);  
	xmlNewChild(freelancerNode, NULL, BAD_CAST "salary", BAD_CAST strBuf);
	sprintf(strBuf, "%f", self->score);  
	xmlNewChild(freelancerNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
		ListNode * curr = List_head_return(self->client);
		int size = List_count(self->client);
		int i = 0;
		while(i != size){
			clientNode = xmlNewChild(freelancerNode, NULL, BAD_CAST "client", NULL);
			Client * currr = ListNode_data_return(curr);
			xmlNewProp(clientNode, BAD_CAST "name1", BAD_CAST currr->name1);
			curr = List_next_return(curr);
			i++;
			Client_free(&currr);
		}
		ListNode_free(&curr);
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	strcpy(str, (const char *)bufferPtr->content);
	xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
}






void XmlLoader_loadFromString(Freelancer * self, const char * xmlStr) {
	List * newl = List_new();
    xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        if (XML_ELEMENT_NODE == xCur->type) {
            printf("Tag name <%s>\n", xCur->name);
            for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
                if (XML_ELEMENT_NODE == xJ->type) {
					if (xmlStrcmp(xJ->name, BAD_CAST "client") == 0) {                
						char * name = (char *)xmlGetProp(xJ, BAD_CAST "name1");
						Client * new = new_Client(name);
						List_addLast(newl, new);
						xmlFree(name);
                        continue;
                    }
					char * content = (char *)xmlNodeGetContent(xJ);
					if(xmlStrcmp(xJ->name, BAD_CAST "name") == 0){
						strcpy(self->name, content);
					}
					if(xmlStrcmp(xJ->name, BAD_CAST "salary") == 0){
						self->salary = atoi(content);
					}
					if(xmlStrcmp(xJ->name, BAD_CAST "score") == 0){
						self->score = atof(content);
					}
					xmlFree(content);
                }
            }
        }
    }
	xmlFreeDoc(xDoc);
	self->client = newl;
    return;
}







Client * new_Client(char * name){
	 struct Client * client = malloc(sizeof(struct Client));
  	 strcpy(client->name1, name);
	 return client;
}

void Freelancer_free(Freelancer ** self){
    free(*self);
    *self = NULL;
}

void Client_free(Client ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void Client1_free(void ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}


Freelancer * sample(void){
	List * cur = List_new();
	Client * vadim =  new_Client("vadim");
	Client * ilya = new_Client("ilya") ;
	Client * misha = new_Client("misha");
	List_addLast(cur, vadim);
	List_addLast(cur, ilya);
	List_addLast(cur, misha);
	struct Freelancer * self = malloc(sizeof(struct Freelancer));
	strcpy(self->name,"Taras");
	self->salary = 1145;
	self->score = 4.6;
	self->client = cur;
	return self;
}


void * listget(Freelancer * self){
	return self->client;
}


Freelancer * Freelancer_new(void){
	Freelancer * self = malloc(sizeof(struct Freelancer));
	strcpy(self->name, "");
	self->salary = 0;
	self->score = 0.0;
	self->client = NULL;
	return self;
}

void print(Freelancer * self){
	printf("\n name: %s;\n salary: %i;\n score: %f;\n", self->name, self->salary, self->score);
	ListNode * cur = List_head_return(self->client);
	 while(cur != NULL){
		Client * ng = ListNode_data_return(cur);
	  	printf(" Client: (%s)\n", ng->name1);
	  	cur = List_next_return(cur);
		Client_free(&ng);
	 }
}
