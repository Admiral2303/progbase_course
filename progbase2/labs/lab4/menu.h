#ifndef MENU_H
#define MENU_H

#include "convert.h"
#include "list.h"


void line();																										//////
void printfirstmenu();
void clearmainmenu();
void printsecondmenu();
void clearstringtostruct();																			///// MENU
void clear();
void rewhelp(int i, int j);
void clearfield();
void printthirdmenu();
void cleanall();
void cleanstr(int i, int j);																		/////

void printdots(int k);
void prntleftline();
void List_print(List * self);
void print_Node(List * self, int position);
char * print_change_struct(char * str);
void Prof_input(char * str);


#endif //MENU_h
