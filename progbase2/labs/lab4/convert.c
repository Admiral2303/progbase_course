
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase/console.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>

#include "convert.h"
#include "menu.h"





struct Profecional {
	char profname[10];
	int  salary;
	float score;
	struct  {
		char name[10];
		char surname[10];
		int year;
	} information;
};



struct Profecional * str_in_struct(char * str, struct Profecional * profs){
    sscanf(str, "%s %i %f %s %s %i",profs->profname,&profs->salary,&profs->score,profs->information.name,profs->information.surname,&profs->information.year);
    return profs;
}





Profecional * overwrite_all_fields(Profecional * prof, char * profname, int salary, float score, char * name,char * surname, int year){
  if(prof == NULL){
    return NULL;
  } else {
      strcpy(prof->profname, profname);
        prof->salary = salary;
        prof->score = score;
        strcpy(prof->information.name, name);
        strcpy(prof->information.surname, surname);
        prof->information.year = year;
    }
    return prof;
}


Profecional * Prof_new(){
    struct Profecional * data = (struct Profecional*)malloc(sizeof(struct Profecional));
    strcpy(data->profname, "");
    data->salary = 0;
    data->score = 0;
    strcpy(data->information.name, "");
    strcpy(data->information.surname, "");
    data->information.year = 0;
    return data;
}


void print(Profecional * self){
    printf("Назва професії: %s\n",  self->profname);
    printf("Зарплата: %i\n", self->salary);
    printf("Рейтинг професії: %.1f\n", self->score);
    printf("Імя робітника: %s\n", self->information.name);
    printf("Прізвище робітника: %s\n", self->information.surname);
    printf("Рік народження: %i\n\n", self->information.year);
}



void Profecional_free(Profecional **  self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}












int validtest(char *str)
{
    int flag = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(isalpha(str[i]) || isspace(str[i]) || ispunct(str[i]) )
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int change_struct(void * self, int position,char * field, char * str){
    if(List_head_return(self) == NULL){
        // conMove(28, 45);
        // conSetAttr(FG_RED);
        //puts("Данного вузла не існує");
        conReset();
        return 1;     
    }
    ListNode * cur = List_head_return(self);
    int count = List_count(self);
    int k = 0;
    
    while (k != count){
        if(k == position){
            Profecional * prof = ListNode_data_return(cur);
            rewrite_field(prof,field, str);
        }
        cur = List_next_return(cur);
        k++;
    }
    return 0;
}



int List_overwrite_struct(void * profs ,int size, int index_from, int index_to){
  if(index_from < 0 || index_from >= size || index_to < 0 || index_to >= size) return EXIT_FAILURE;
    int count = 0;
    ListNode * prof_to = List_head_return(profs);
    ListNode * prof_from = List_head_return(profs);

    while(count < index_to){
      count++;
      prof_to = List_next_return(prof_to);
    }
    count = 0;
    
    while(count < index_from){
      count++;
      prof_from = List_next_return(prof_from);
    }
    void * from = ListNode_data_return(prof_from);
    void * to = ListNode_data_return(prof_to);
    overwrite_all_fields(to, get_ProfName(from), get_Salary(from), get_Score(from),
       get_Name(from), get_SurName(from), get_Year(from));
    return EXIT_SUCCESS;
}







int validtestfloat(char *str)
{
    int flag = 2;
    int i =0;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i]=='.' && isdigit(str[i+1]))
        {
            flag = 0;
        }
    }
    for(i = 0; i < strlen(str); i++)
    {
        if(isalpha(str[i]) || isspace(str[i]))
        {
            flag = 1;
        }
    }

    if(flag >= 1)
    {
        //profs[i]->salary = atoi(str);
        return 1;
    }
    else
    {
        return 0;
    }
}

char * get_ProfName(Profecional * self){
  return self->profname;
}


int get_Salary(Profecional * self){
  return self->salary;
}


float get_Score(Profecional * self){
  return self->score;
}

char *  get_Name(Profecional * self){
  return self->information.name;
}

char *  get_SurName(Profecional * self){
  return self->information.surname;
}

int get_Year(Profecional * self){
  return self->information.year;
}



Profecional * rewrite_field(Profecional * prof, char * field, char * str){
    if(strcmp(field, "profname") == 0) strcpy(prof->profname, str);
    else if(strcmp(field, "salary") == 0) prof->salary = atoi(str);
    else if(strcmp(field, "score") == 0) prof->score = atof(str);
    else if(strcmp(field, "name") == 0) strcpy(prof->information.name, str);
    else if(strcmp(field, "surname") == 0) strcpy(prof->information.surname, str);
    else if(strcmp(field, "year") == 0) prof->information.year = atoi(str);
    return prof;
}


int find_Profecional(void * self,void * new1, int salary){
    if(List_head_return(self) == NULL){
        return 1;
    }
    ListNode * cur = List_head_return(self);
    while (cur != NULL){
      if(get_Salary(ListNode_data_return(cur)) > salary){
        Profecional * data = Prof_new();
        char * profname = get_ProfName((ListNode_data_return(cur)));
        int salary = get_Salary((ListNode_data_return(cur)));
        float score = get_Score((ListNode_data_return(cur)));
        char * name =  get_Name((ListNode_data_return(cur)));
        char * surname = get_SurName((ListNode_data_return(cur)));
        int year = get_Year((ListNode_data_return(cur)));
        data =  overwrite_all_fields(data, profname, salary,score, name,surname,year);
        List_addLast(new1,data);
      }
      cur = List_next_return(cur);
    }
    return 0;
}





