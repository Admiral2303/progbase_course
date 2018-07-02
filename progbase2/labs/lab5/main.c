#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <progbase/console.h>

#include <list.h>
#include <convert.h>
#include <menu.h>
#include <function.h>





int main(void){
conResize(100,150);
List * profs = List_new();
      conHideCursor();
     int k = 0;
     int position = 0;
     int delete = 0;
     int index_to = 0;
     int index_from = 0;
     int l = 0;
   //  int m = 0;

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
                      if(scanf("%i", &position)== 1){

                      }
                      print_Node(profs, position);
                      prntleftline();
                      break;
                  case '3':
                      prntleftline();
                      clearstringtostruct();
                      conMove(16,3);
                      printf("Введіть номер вузла який потрібно удалити");
                      conMove(16,45);
                      if(scanf("%i", &delete) == 1){

                      }
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
                      if(scanf("%i", &index_from)==1){

                      }
                      conMove(17,3);                   
                      printf("Введіть номер вузла в якого скопіювати");  
                      conMove(17,45);    
                      if(scanf("%i", &index_to)==1){

                      }             
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
                      if(scanf("%i", &position)==1){

                      }
                      conMove(18,20);
                      char field_data[20];
                      conMove(18,25); 
                      if(scanf("%s", field_data)==1){

                      }
                      change_struct(profs,position,str,field_data);
                      prntleftline();
                      break;
                  case '7':
                      prntleftline();
                      clearstringtostruct();
                      int salary = 0; 
                      conMove(16,3);
                      printf("Введіть зарплату відносно якої шукати професії");
                      if(scanf("%i", &salary) == 1){

                      }
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
                      conMove(16,3);
                      puts("1.зчитати з xml файла");
                      conMove(17,3);
                      puts("2.зчитати з json файла");
                      conMove(16, 35);
                      if(scanf("%i", &l) == 1){}
                      if(l == 1){
                         XmlLoader_loadFromFile(profs, "dima.xml");
                         conMove(18,15);
                         puts("З файла считано");
                      }
                      if(l == 2){
                         JsonLoader_loadFromFile(profs, "input_json.json");
                         conMove(18,15);
                         puts("З файла считано");
                      }
                      break;
                  case '2':
                      clearstringtostruct();
                      conMove(16,3);
                      puts("1.записати в xml файла");
                      conMove(17,3);
                      puts("2.записати в json файла");
                      int output = 0;
                      conMove(16, 35);
                      if(scanf("%i", &output)==1){
                      }
                      if(output == 1){
                         conMove(19,3);
                         puts("Введіть назву файла в який зберегти");
                         char str1[100];
                         conMove(20,3);
                         if(scanf("%s", str1)==1){
                         }
                         XmlLoader_saveToFile(profs, str1);
                         conMove(24,3);
                         conSetAttr(FG_RED);                         
                         puts("В файл записано");
                         conReset();
                      }
                      if(output == 2){
                         conMove(19,3);
                         puts("Введіть назву файла в який зберегти");
                         char str2[100];
                         conMove(20,3);
                         if(scanf("%s", str2)==1){}
                         JsonLoader_saveToFile(str2, profs);
                         conMove(24,3);
                         conSetAttr(FG_RED);
                         puts("В файл записано");
                         conReset();
                      }
                     // clearstringtostruct();
                      break;
                  }
              }
              break;
          }
      }
      List_clear(profs);

      return 0;
  }
