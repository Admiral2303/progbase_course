
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase.h>
#include <progbase/console.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <jansson.h>



#include <convert.h>

#include <list.h>

#include <function.h>



void * text_in_struct1(void * self,char * filename){
    char * str = (char*)malloc(100 * sizeof(char));
    FILE * fin = fopen(filename, "r");
    if(fin == NULL){
        return NULL;
    }
    while(fgets(str, 100, fin)){
        Profecional * cur = Prof_new();
        str_in_struct(str, cur);
        List_addLast(self, cur);
    }
    free(str);
    fclose(fin);
    return self;
}


void file_output(void * self , char * filename){
    FILE * fout = fopen(filename, "w");
    ListNode  * cur = List_head_return(self);
    while(cur != NULL){
        fprintf(fout,"profname: %s; salary: %i; score: %.1f; name: %s; surname: %s; year: %i;\n",
        get_ProfName(ListNode_data_return(cur)),get_Salary(ListNode_data_return(cur)),
        get_Score(ListNode_data_return(cur)), get_Name(ListNode_data_return(cur)),
        get_SurName(ListNode_data_return(cur)), get_Year(ListNode_data_return(cur)));

        cur = List_next_return(cur);
    }
    fclose(fout);
}





void XmlLoader_saveToFile(void * list, const char * filename){
    FILE * fout = fopen(filename, "w");
    char str[10000];
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * freelancerNode = NULL;
    ListNode * cur = List_head_return(list);
    rootNode = xmlNewNode(NULL, BAD_CAST "profecionals");
     doc = xmlNewDoc(BAD_CAST "1.0");
     int i = 0;
     char strBuf[100];
    while(i != List_count(list) ){
        Profecional * self = ListNode_data_return(cur);
        xmlDocSetRootElement(doc, rootNode);
        freelancerNode = xmlNewChild(rootNode, NULL, BAD_CAST "profecional", NULL);
        xmlNewChild(freelancerNode, NULL, BAD_CAST "profname", BAD_CAST  get_ProfName(self));
        sprintf(strBuf, "%i",  get_Salary(self));  
        xmlNewChild(freelancerNode, NULL, BAD_CAST "salary", BAD_CAST strBuf);
        sprintf(strBuf, "%f",  get_Score(self));  
        xmlNewChild(freelancerNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
        xmlNewChild(freelancerNode, NULL, BAD_CAST "name", BAD_CAST  get_Name(self));
        xmlNewChild(freelancerNode, NULL, BAD_CAST "surname", BAD_CAST  get_SurName(self));
        sprintf(strBuf, "%i",  get_Year(self));
        xmlNewChild(freelancerNode, NULL, BAD_CAST "year", BAD_CAST strBuf);
        cur = List_next_return(cur);
        i ++;
    }
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	strcpy(str, (const char *)bufferPtr->content);
	xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
    fprintf(fout,"%s", str);
    fclose(fout);
}


void XmlLoader_loadFromFile(void * list, const char * filename) {
    char * xmlStr = (char*)malloc(3000 * sizeof(char));
    xmlStr[0]= '\0';
    readAllText(filename, xmlStr);
    xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        
         if (XML_ELEMENT_NODE == xCur->type) {
            Profecional * self = Prof_new();
            for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
                if (XML_ELEMENT_NODE == xJ->type) {
					char * content = (char *)xmlNodeGetContent(xJ);
					if(xmlStrcmp(xJ->name, BAD_CAST "profname") == 0){
						set_ProfName(self,content);
					}
					if(xmlStrcmp(xJ->name, BAD_CAST "salary") == 0){
						set_Salary(self,content);
					}
					if(xmlStrcmp(xJ->name, BAD_CAST "score") == 0){
						set_Score(self,content);
					}
                    if(xmlStrcmp(xJ->name, BAD_CAST "name") == 0){
						set_Name(self,content);
					}
                    if(xmlStrcmp(xJ->name, BAD_CAST "surname") == 0){
						set_SurName(self,content);
					}
                    if(xmlStrcmp(xJ->name, BAD_CAST "year") == 0){
						set_Year(self,content);
					}
					xmlFree(content);
                }
            }
            List_addLast(list, self);
        }
    }
	xmlFreeDoc(xDoc);
    free(xmlStr);
    return;
}


void readAllText(const char * filename, char * text) {
	char line[500];
    line[0] = '\0';
    FILE * fr = fopen(filename, "r");
    if(fr == NULL){
        conMove(25,60);
        puts("ERROR");
    }
    else{
        while(fgets(line, 100, fr)) {
            strcat(text, line);
        }
    }
	fclose(fr);
}



void JsonLoader_saveToFile(char * filename, void * self) {
     FILE * fout = fopen(filename, "w");
    ListNode * curr = List_head_return(self);
	json_t * array = json_array(); 
    while(curr != NULL){  
	    json_t * groupObj = json_object(); 
			Profecional * currr = ListNode_data_return(curr);
            json_object_set_new(groupObj, "profname", json_string(get_ProfName(currr)));
            json_object_set_new(groupObj, "salary", json_integer(get_Salary(currr)));
            json_object_set_new(groupObj, "score", json_real(get_Score(currr)));
            json_object_set_new(groupObj, "name", json_string(get_Name(currr)));
            json_object_set_new(groupObj, "surname", json_string(get_SurName(currr)));
            json_object_set_new(groupObj, "year", json_integer(get_Year(currr)));
			json_array_append(array, groupObj);
            curr = List_next_return(curr); 
			json_decref(groupObj);
		}
         
	char * jsonString = json_dumps(array, JSON_INDENT(2) | JSON_PRESERVE_ORDER); 
	fprintf(fout,"%s",jsonString);
    fclose(fout);
	free(jsonString);
	json_decref(array);
}



void JsonLoader_loadFromFile(void * self, const char * filename){
    char * jsonStr = (char*)malloc(3000 * sizeof(char));
    jsonStr[0]= '\0';
    readAllText(filename, jsonStr);
	json_error_t err;
	json_t * jsonArr = json_loads(jsonStr, 0, &err);
	int index = 0;
	json_t * value = NULL;
	json_array_foreach(jsonArr, index, value) {
	    Profecional * new = Prof_new();
        set_ProfName(new, (char *)json_string_value(json_object_get(value, "profname")));
        set_Salary1(new, json_integer_value(json_object_get(value, "salary")));
        set_Score1(new, json_real_value(json_object_get(value, "score")));
        set_Name(new, (char *)json_string_value(json_object_get(value, "name")));
        set_SurName(new, (char *)json_string_value(json_object_get(value, "surname")));
        set_Year1(new, json_integer_value(json_object_get(value, "salary")));
        List_addLast(self,new);
	};
	json_decref(jsonArr);
    free(jsonStr);
}








