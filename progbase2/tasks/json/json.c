#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <jansson.h>

#include "list.h"
#include "json.h"

struct Client {
	char name1[20];    
};


struct Freelancer{
    char name[20];
    int salary;
    float score;
    List * client;
};



void JsonLoader_saveToString(char * str, Freelancer * self) {
	json_t * json = json_object();
	json_object_set_new(json, "name", json_string(self->name));
	json_object_set_new(json, "salary", json_integer(self->salary));
	json_object_set_new(json, "score", json_real(self->score));
    ListNode * curr = List_head_return(self->client);
	json_t * array = json_array(); 
    while(curr != NULL){  
	    json_t * groupObj = json_object(); 
			Client * currr = ListNode_data_return(curr);
            json_object_set_new(groupObj, "name1", json_string(currr->name1));
			json_array_append(array, groupObj);
            curr = List_next_return(curr); 
			json_decref(groupObj);
		}
         json_object_set_new(json, "client", array);
	char * jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER); 
	strcpy(str, jsonString);
	free(jsonString);
	json_decref(json);
}



void JsonLoader_loadFromString(Freelancer * self, char * jsonStr){
	json_error_t err;
	json_t * val = json_loads(jsonStr, 0,  &err);
	strcpy(self->name ,(char *)json_string_value(json_object_get(val, "name")));
	self->salary = json_integer_value(json_object_get(val, "salary"));
	self->score = json_real_value(json_object_get(val, "score"));	
	int index = 0;
	json_t * value = NULL;
	json_t * array = json_object_get(val, "client");
	List * list = List_new();
	json_array_foreach(array, index, value) {
		char * name  = (char *)json_string_value(json_object_get(value, "name1"));
		Client * new = new_Client(name);
		List_addLast(list, new);
	}	
	self->client = list;	
	json_decref(val);
}


Client * new_Client(char * name){
	 struct Client * client = (struct Client *)malloc(sizeof(struct Client));
  	 strcpy(client->name1, name);
	 return client;
}




Freelancer * Freelancer_new(void){
	Freelancer * self = malloc(sizeof(struct Freelancer));
	strcpy(self->name, "");
	self->salary = 0;
	self->score = 0.0;
	self->client = NULL;
	return self;
}


void Freelancer_free(Freelancer ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void Client_free(void ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void Client1_free(Client ** self){
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



void print(Freelancer * self){
	printf("\n name: %s;\n salary: %i;\n score: %f;\n", self->name, self->salary, self->score);
	ListNode * cur = List_head_return(self->client);
	 while(cur != NULL){
		Client * ng = ListNode_data_return(cur);
	  	printf(" Client: (%s)\n", ng->name1);
	  	cur = List_next_return(cur);
	 }
}
