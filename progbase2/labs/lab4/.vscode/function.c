#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pbconsole.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>

#include "function.h"
#include "menu.h"

    

struct ListNode * ListNode_new(Profecional prof) {
  struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->next = NULL;
  node->prof = prof;
    return node;
}


struct List * List_new(void) {
  struct List * list = (struct List *)malloc(sizeof(struct List));
  list->head = NULL;
return list;
}

struct Profecional * str_in_struct(char * str, struct Profecional * profs){
    sscanf(str, "%s %i %f %s %s %i",profs->profname,&profs->salary,&profs->score,profs->information.name,profs->information.surname,&profs->information.year);
    return profs;
}

struct Profecional ** text_in_struct(struct Profecional * profs[], int size, char * filename){
    char * str = (char*)malloc(100 * sizeof(char));
    FILE * fin = fopen(filename, "r");
    if(fin == NULL){
        return NULL;
    }
    for(int i = 0; i < size; i++){
        fgets(str, 100, fin);
        str_in_struct(str, profs[i]);
    }
    free(str);
    fclose(fin);
    return profs;
}

/*  List * create_List(struct Profecional * profs){
  List * new_List = List_new();

  new_List->head->prof->profname =  profs->profname;
  new_List->head->prof->salary = profs->salary;
  new_List->head->prof->score = profs->score;
  new_List->head->prof->information.name = profs->information.name;
  new_List->head->prof->information.surname = profs->information.surname;
  new_List->head->prof->information.year = profs->information.year;



  return new_List;
}*/


void List_addFirst(struct List * self, Profecional prof) {
  struct ListNode * node = ListNode_new(prof);
  node->next = self->head;
  self->head = node;
}

void List_addLast(struct List * self, Profecional * prof) {
  struct ListNode * node = ListNode_new(*prof);
  if (self->head == NULL) {
    self->head = node;
    return;
  }
  struct ListNode * cur = self->head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = node;
}

void List_insert(struct List * self, int position, Profecional prof) {
  assert(position >= 0);
  if (position == 0) {
    List_addFirst(self, prof);
    return;
  }
  struct ListNode * node = ListNode_new(prof);
  int i = 0;
  struct ListNode * cur = self->head;
  while (cur->next != NULL && i != position - 1) {
    cur = cur->next;
    i++;
  }
  if (i != position - 1) assert(0);
    node->next = cur->next;
    cur->next = node;
}


int overwrite_struct(List * profs ,int size, int index_from, int index_to){
  if(index_from < 0 || index_from >= size || index_to < 0 || index_to >= size) return EXIT_FAILURE;
    int count = 0;
    ListNode * prof_to = profs->head;
    ListNode * prof_from = profs->head;
    //find prof_to
    while(count < index_to){
      count++;
      prof_to = prof_to->next;
    }
    count = 0;
    //find prof_from
    while(count < index_from){
      count++;
      prof_from = prof_from->next;
    }
    overwrite_all_fields(&prof_to->prof, prof_from->prof.profname, prof_from->prof.salary, prof_from->prof.score,
       prof_from->prof.information.name, prof_from->prof.information.surname, prof_from->prof.information.year);
    return EXIT_SUCCESS;
}
void List_print(List * self){
  ListNode * cur = self->head;
  while(cur != NULL){
    printf("Назва професії: %s\n", cur->prof.profname);
    printf("Зарплата: %i\n", cur->prof.salary);
    printf("Рейтинг професії: %.1f\n", cur->prof.score);
    printf("Імя робітника: %s\n", cur->prof.information.name);
    printf("Прізвище робітника: %s\n", cur->prof.information.surname);
    printf("Рік народження: %i\n", cur->prof.information.year);
    cur = cur->next;
  }
}

void List_print_Node(List * self, int position){
  int i = 0;
  ListNode * cur = self->head;
  while(cur != NULL &&  i != position){
    i++;
    cur = cur->next;
  }
  if(cur == NULL){
    conMove(18,3);
    puts("Даний вузол не заповнений");
  }
  else{
    conMove(17,3);
    printf("Назва професії: %s\n", cur->prof.profname);
    conMove(18,3);
    printf("Зарплата: %i\n", cur->prof.salary);
    conMove(19,3);
    printf("Рейтинг професії: %.1f\n", cur->prof.score);
    conMove(20,3);
    printf("Імя робітника: %s\n", cur->prof.information.name);
    conMove(21,3);
    printf("Прізвище робітника: %s\n", cur->prof.information.surname);
    conMove(22,3);
    printf("Рік народження: %i\n", cur->prof.information.year);
  }
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

/*void add_struct(List * profs, Profecional prof, int size, int index){
  if(index < 0 || index > size) return;
  if(index == 0) List_addFirst(profs, prof);
  else if(index == size) List_addLast(profs, prof);
  else(List_insert(profs, index, prof));
}*/





Profecional * Prof_new(){
struct Profecional * node = (struct Profecional*)malloc(sizeof(struct Profecional*));
    return node;
}


void Profecional_free(struct Profecional* self) {
    self->profname[0] = '\0';
	self->salary = 0;
	self->score = 0.0;
	self->information.name[0] = '\0';
	self->information.surname[0] = '\0';
	self->information.year = 0;
}

void ListNode_remove(List * self, int position) {
    int i = 0;
    assert(self->head != NULL);
    struct ListNode * cur = self->head;
    if (cur->next == NULL || position == 0) {
        ListNode_removeFirst(self);
        return;
    }
    while(cur->next->next != NULL && i != position) {
        cur = cur->next;
        i++;
    }
    struct ListNode * node = cur->next;
    cur->next = node->next;
    ListNode_free(&node);
}

ListNode * ListNode_removeFirst(List * self) {
    assert(self->head != NULL);
    struct ListNode * node = self->head;
    self->head = node->next;
    ListNode_free(&node);
    return self->head;
}



void ListNode_free(ListNode ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}





Profecional * Prof_input(){
  Profecional * prof =  Prof_new();
  char str[50];
  //scanf("%s", str);
  cleanstr(16,3);
  conMove(16,3);
  conSetAttr(FG_BLUE);
  printf("Назва професії: ");
  conReset();
  scanf("%s",str);
  strcpy(prof->profname,str);
    printf("%lu---------------------",strlen(str));
//   while(1)
//   {
//       str[0] = '\0';
//       conMove(17,3);
//       conSetAttr(FG_BLUE);
//       printf("Зарплата:");
//       conReset();
//       scanf("%s",str);
//       if(validtest(str)== 0 )
//       {
//           prof->salary = atoi(str);
//           break;
//       }
//       else
//       {
//           cleanstr(17,11);
//           conMove(18,3);
//           conSetAttr(FG_RED);
//           printf("Не правильний ввід введіть ще раз");
//           conReset();
//       }
//   }
//   cleanstr(18,3);
//   while(1)
//   {
//       str[0] = '\0';
//       conMove(18,3);
//       conSetAttr(FG_BLUE);
//       printf("Pейтинг професії: ");
//       conReset();
//       scanf("%s",str);
//       if(validtestfloat(str)== 0 )
//       {
//           prof->score = atof(str);
//           break;
//       }
//       else
//       {
//           cleanstr(18,19);
//           conMove(19,3);
//           conSetAttr(FG_RED);
//           printf("Не правильний ввід введіть ще раз");
//           conReset();
//       }
//   }
//   cleanstr(19,3);
//   str[0] = '\0';
//   conMove(19,3);
//   conSetAttr(FG_BLUE);
//   printf("Імя робітника: ");
//   conReset();
//   scanf("%s",str);
//   strcpy(prof->information.name,str);


//   str[0] = '\0';
//   conMove(20,3);
//   conSetAttr(FG_BLUE);
//   printf("Прізвище робітника: ");
//   conReset();
//   scanf("%s",str);
//   strcpy(prof->information.surname,str);


//   while(1)
//   {
//       str[0] = '\0';
//       conMove(21,3);
//       conSetAttr(FG_BLUE);
//       printf("Рік народження: ");
//       conReset();
//       scanf("%s",str);
//       if(validtest(str)== 0 )
//       {
//           cleanstr(22,3);
//           prof->information.year = atoi(str);
//           break;
//       }
//       else
//       {
//           cleanstr(21,16);
//           conMove(22,3);
//           conSetAttr(FG_RED);
//           printf("Не правильний ввід введіть ще раз");
//           conReset();
//       }
//   }
  return prof;
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
