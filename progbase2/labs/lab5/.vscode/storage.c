
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pbconsole.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>

#include "profecional.h"
#include "list.h"



struct Profecional * str_in_struct(char * str, struct Profecional * profs){
    char profname[20];
    int salary = 0;
    float score = 0.0;
    char name[20];
    char surname[20];
    int year = 0;
    sscanf(str, "%s %i %f %s %s %i",profname,&salary,&score,name,surname,&year);
    salary = get_Salary(profs) ;
    return profs;
}

List* text_in_struct(List * self, char * filename){
    char * str = (char*)malloc(100 * sizeof(char));
    FILE * fin = fopen(filename, "r");
    if(fin == NULL){
        return NULL;
    }
        while(fgets(str, 100, fin) != NULL){
            Profecional * prof = Prof_new();
            str_in_struct(str, prof);
            List_addLast(self, prof);
        }
    free(str);
    fclose(fin);
    return self;
}
