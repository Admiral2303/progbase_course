#ifndef FUNCTION_H
#define FUNCTION_H


struct List{
  struct ListNode * head;
};

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

struct ListNode{
    struct Profecional prof;
    struct ListNode * next;
};



typedef struct Profecional Profecional;
typedef struct ListNode ListNode;
typedef struct List List;


struct ListNode * ListNode_new(Profecional prof);
struct List * List_new(void);
struct Profecional * str_in_struct(char * str, struct Profecional * profs);
void List_insert(struct List * self, int position, Profecional prof);
void List_addLast(struct List * self, Profecional * prof);
void List_addFirst(struct List * self, Profecional prof);
Profecional * overwrite_all_fields(Profecional * prof, char * profname, int salary, float score, char * name,char * surname, int year);
int overwrite_struct(List * profs ,int size, int index_from, int index_to);
void List_print(List * self);
void add_struct(List * profs, Profecional prof, int size, int index);











int validtestfloat(char *str);
int validtest(char *str);

Profecional * Prof_input();
Profecional * Prof_new();
void Profecional_free(struct Profecional *self);

void List_print_Node(List * self, int position);
void ListNode_free(ListNode ** self);
void ListNode_remove(List * self, int position);
ListNode * ListNode_removeFirst(List * self);



#endif
