#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <progbase/console.h>

#include "list.h"
#include "convert.h"
#include "menu.h"
#include "function.h"





int main(void){
conResize(100,150);
List * profs = List_new();

      conHideCursor();
     int k = 0;
     int position = 0;
     int delete = 0;
     int index_to = 0;
     int index_from = 0;


      line();
      printfirstmenu();
      printdots(0);
      while(1)
      {
          k = conGetChar();
          conReset();
          if(k == 'q')
          {
              cleanall();
              break;
          }
          switch(k)
          {
          case '1':
              printdots(1);
              clearmainmenu();
              printsecondmenu();
              while(1)
              {
                  k = conGetChar();
                  conReset();
                  if(k == 'q')
                  {
                      printdots(0);
                      clearstringtostruct();
                      clearmainmenu();
                      printfirstmenu();
                      break;

                  }
                  switch(k)
                  {
                  case '1':
                      clearstringtostruct();
                      Profecional * profs1 = Prof_new();
                      char * str1 = (char *)malloc(500 * sizeof(char));
                      Prof_input(str1);
                      //puts(str1);
                      profs1 = str_in_struct(str1,profs1);
                      List_addLast(profs,profs1);
                      str1[0] = '\0';
                      free(str1); 
                      prntleftline();               
                      break;
                  case '2':
                      prntleftline();
                      clearstringtostruct();
                      printsecondmenu();
                      conMove(16,3);
                      conSetAttr(FG_BLUE);
                      printf("Введіть номер вузла який потрібно вивести");
                      conReset();
                      conMove(16,45);
                      scanf("%i", &position);
                      print_Node(profs, position);
                      prntleftline();
                      break;
                  case '3':
                      prntleftline();
                      clearstringtostruct();
                      conMove(16,3);
                      printf("Введіть номер вузла який потрібно удалити");
                      conMove(16,45);
                      scanf("%i", &delete);
                      ListNode_remove(profs,delete);
                      clear();
                      prntleftline();
                      break;
                  case '4':
                      prntleftline();
                      clearstringtostruct();
                      List_print(profs);
                      prntleftline();
                      break;
                  case '5':
                      prntleftline();
                      clearstringtostruct();
                      conMove(16,3);
                      printf("Введіть номер вузла з якого скопіювати");
                      conMove(16,45);
                      scanf("%i", &index_from);
                      conMove(17,3);    
                                       
                      printf("Введіть номер вузла в якого скопіювати");  
                      conMove(17,45);    
                      scanf("%i", &index_to);                 
                      List_overwrite_struct(profs ,List_count(profs), index_from, index_to);
                      prntleftline();
                      break;
                  case '6':
                     prntleftline();
                      clearstringtostruct();
                      int position = 0;
                      char str[20];
                      print_change_struct(str);
                      conMove(17,45);
                      scanf("%i", &position);
                      conMove(18,20);
                      char field_data[20];
                      conMove(18,25); 
                      scanf("%s", field_data);
                      change_struct(profs,position,str,field_data);
                      prntleftline();
                      break;
                  case '7':
                      prntleftline();
                      clearstringtostruct();
                      int salary = 0; 
                      conMove(16,3);
                      printf("Введіть зарплату відносно якої шукати професії");
                      scanf("%i", &salary);
                      cleanstr(16,2);
                      List * new = List_new();
                      find_Profecional(profs,new, salary);
                      //new = find_Profecional(profs, salary);
                      List_print(new);
                      List_clear(new);
                      prntleftline();
                      break;
                  case '8':
                      clearstringtostruct();
                      break;
                  }
              }
              break;
          case '2':
              printdots(1);
              clearmainmenu();
              printthirdmenu();
              while(1)
              {
                  k = conGetChar();
                  conReset();
                  if(k == 'q')
                  {
                      printdots(0);
                      clearstringtostruct();
                      clearmainmenu();
                      printfirstmenu();
                      break;
                  }
                  switch (k)
                  {
                  case '1':
                      clearstringtostruct();
                      text_in_struct1(profs,"input.txt");
                      conMove(18,15);
                      puts("З файла считано");
                      break;
                  case '2':
                      clearstringtostruct();
                      file_output(profs , "output.txt");
                      conMove(18,15);
                      puts("В файл записанно");
                      break;
                  }
              }
              break;
          }
      }
      List_clear(profs);

      return 0;
  }
