#ifndef CONVERT_H
#define CONVERT_H



typedef struct Profecional Profecional;

struct Profecional * str_in_struct(char * str, struct Profecional * profs);
Profecional * overwrite_all_fields(Profecional * prof, char * profname, int salary, float score, char * name,char * surname, int year);
Profecional * Prof_new();
void Profecional_free(Profecional ** self);

int validtest(char *str);
int validtestfloat(char *str);

char * get_ProfName(Profecional * self);
int get_Year(Profecional * self);
char *  get_SurName(Profecional * self);
char *  get_Name(Profecional * self);
float get_Score(Profecional * self);
int get_Salary(Profecional * self);

Profecional * rewrite_field(Profecional * prof, char * field, char * str);
int change_struct(void * self, int position,char * field, char * str);
int List_overwrite_struct(void * profs ,int size, int index_from, int index_to);
int find_Profecional(void * self, void * new1, int salary);

void profecional_input (Profecional * self);

void print(Profecional * self);

void set_ProfName(Profecional* self, char * str);
void set_Salary(Profecional* self, char * str);
void set_Score(Profecional* self, char * str);
void set_Name(Profecional* self, char * str);
void set_SurName(Profecional* self, char * str);
void set_Year(Profecional* self, char * str);
void set_Salary1(Profecional* self, int i);
void set_Score1(Profecional* self, float i);
void set_Year1(Profecional* self, int i);

#endif