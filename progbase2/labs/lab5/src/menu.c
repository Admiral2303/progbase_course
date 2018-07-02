#include <progbase.h>
#include <stdio.h>
#include <stdlib.h>
#include <progbase/console.h>
#include <ctype.h>
#include <string.h>

#include <menu.h>
#include <list.h>
#include <convert.h>

void line()
{
    int i=0;
    conClear();
    conSetAttr (BG_WHITE);
    for(i=0; i < 121; i++)
    {
        printf(" ");
        conMove(1,i);
    }
    for(i = 0; i < 121; i++)
    {
        printf(" ");
        conMove(30,i);
    }
    for(i = 0; i < 121; i++)
    {
        printf(" ");
        conMove(15,i);
    }
    for(i = 0; i < 30; i++)
    {
        printf(" ");
        conMove(i,120);
    }
    for(i = 0; i < 31; i++)
    {
        printf(" ");
        conMove(i,1);
    }
    printf("\n");
    conReset();
}


void prntleftline(){
    conSetAttr (BG_WHITE);
    for(int i = 0; i < 30 ; i++)
    {
        printf(" ");
        conMove(i,1);
    }
    conReset();
    conMove(21, 118);
    puts(" ");
    conMove(22, 118);
    puts(" ");
}

void printfirstmenu()
{
    for(int j=2; j < 5; j++)
    {
        for(int i = 2; i < 120; i++)
        {
            conMove(j,i);
            conSetAttr(BG_YELLOW);
            printf(" ");
        }
    }
    conReset();
    conMove(3,55);
    conSetAttr(BG_YELLOW);
    conSetAttr(FG_RED);
    printf("LAB 3");
    conReset();
    conSetAttr(FG_GREEN);
    conMove(8,45);
    printf("1.Дії з структурами");
    conMove(9,45);
    printf("2.Зчитати дані із файлу або записати дані на файл");
    conMove(10,45);
    printf("q-вихід");
    conReset();
    conMove(122,1);
}


void clearmainmenu()
{
    for(int j=2; j < 15; j++)
    {
        for(int i = 2; i < 120; i++)
        {
            conMove(j,i);
            printf(" ");
        }
    }
}


void printsecondmenu()
{

    conSetAttr(FG_CYAN);
    conMove(4,35);
    printf("Виберіть дію");
    conReset();
    conSetAttr(FG_GREEN);
    conMove(5,35);
    printf("1. Заповнити структуру");
    conMove(6,35);
    printf("2. Вивести структуру по заданому індексу");
    conMove(7,35);
    printf("3. Видалити структуру по заданому індексу");
    conMove(8,35);
    printf("4. Вивести всі заповненні структури");
    conMove(9,35);
    printf("5. Скопіювати дані з одної структури в іншу");
    conMove(10,35);
    printf("6. Змінити поле структури по вказаному індексу");
    conMove(11,35);
    printf("7. Знайти назву професій в яких заробітня плата більша за введену");
    conMove(12,35);
    printf("q - вихід");
    for(int j=2; j < 4  ; j++)
    {
        for(int i = 2; i < 120; i++)
        {
            conMove(j,i);
            conSetAttr(BG_YELLOW);
            printf(" ");
        }
    }
    conSetAttr(FG_RED);
    conSetAttr(BG_YELLOW);
    conMove(2, 45);
    printf("Створeння нового масиву даних");
    conMove(41,3);
    conReset();
}
void clearstringtostruct()
{
    for(int j = 16; j < 30; j++)
    {
        for(int i = 3; i < 118; i++)
        {
            printf(" ");
            conMove(j,i);
        }
    }
    conMove(28,120);
    conSetAttr(BG_WHITE);
    printf(" ");
    conReset();
    //for(int i = 16; i < 30;i++){
        conMove(23,1);
        conSetAttr(BG_WHITE);
        printf(" ");
        conMove(19,1);
        conSetAttr(BG_WHITE);
        printf(" ");
        conMove(25,1);
        conSetAttr(BG_WHITE);
        printf(" ");
    //}
    conReset();
}
void clear()
{
    int i = 0;
    int j = 0;
    for(i = 16; i < 29; i ++)
    {
        for(j = 2; j < 120; j++)
        {
            conMove(i, j );
            printf(" ");
        }
    }
}

void clearfield()
{
    for(int i = 2; i < 120; i++)
    {
        conMove(16,i);
        printf(" ");
        conReset();
    }
    for(int i = 16; i < 30; i++)
    {
        conSetAttr(BG_WHITE);
        conMove(i,40);
        printf(" ");
        conReset();
    }
    for(int i = 17; i < 30 ; i++)
    {
        for(int j = 41; j < 120; j++)
        {
            conMove(i,j);
            printf(" ");
        }
    }
}

void printthirdmenu()
{
    for(int j=2; j < 5; j++)
    {
        for(int i = 2; i < 120; i++)
        {
            conMove(j,i);
            conSetAttr(BG_YELLOW);
            printf(" ");
        }
    }
    conReset();
    conMove(3,55);
    conSetAttr(BG_YELLOW);
    conSetAttr(FG_RED);
    printf("Menu 2");
    conReset();
    conSetAttr(FG_GREEN);
    conMove(8,45);
    printf("1.Зчитати з файлу");
    conMove(9,45);
    printf("2.Записати на файл структури");
    conReset();
    conMove(10,45);
    conSetAttr(FG_GREEN);
    printf("q - вихід");
    conReset();
    conMove(122,1);
}

void cleanall()
{
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 120; j++)
        {
            conMove(i,j);
            printf(" ");
        }

    }
}

void cleanstr(int i, int j)
{
    for(; j < 118; j++)
    {
        conMove(i,j);
        printf(" ");
    }
}


void printdots(int k){
  const unsigned long MILLIS = 5;
  if(k==0){
    for(int i = 0;i<=120;i++){
      conMove(1,i);
      conSetAttr(BG_CYAN);
      puts(" ");
      conMove(30,120-i);
      conSetAttr(BG_CYAN);
      puts(" ");
      if(i <=30){
        conMove(i,1);
        conSetAttr(BG_GREEN);
        puts(" ");
        conMove(i,120);
        conSetAttr(BG_GREEN);
        puts(" ");
      }
      sleepMillis(MILLIS);
    }
  }
  else{
    for(int i= 120;i > 0;i--){
      conMove(1,i);
      conSetAttr(BG_MAGENTA);
      puts(" ");
      conMove(30,120-i);
      conSetAttr(BG_MAGENTA);
      puts(" ");
      if(i <=30){
        conMove(i,1);
        conSetAttr(BG_WHITE);
        puts(" ");
        conMove(i,120);
        conSetAttr(BG_WHITE);
        puts(" ");
      }
      sleepMillis(MILLIS);
    }
  }
conReset();
}



/////////////////////////
void List_print(void * self1){
    List * self = self1;
    const unsigned long MILLIS = 100;
    ListNode * curr = List_head_return(self);
    int k = 0;  
    int z = 0;
    while(curr != NULL){
        if(k > 60){
            clearstringtostruct();
            k=0;
        }
        Profecional * cur = ListNode_data_return(curr);
        char * profname = get_ProfName(cur);
        int salary = get_Salary(cur);
        float score = get_Score(cur);
        char * name = get_Name(cur);
        char * surname = get_SurName(cur);
        int year = get_Year(cur);
        conMove(17,3+k); 
        printf("Назва професії: %s\n",  profname);
        conMove(18,3+k);
        printf("Зарплата: %i\n", salary);
        conMove(19,3+k);
        printf("Рейтинг професії: %.1f\n", score);
        conMove(20,3+k);
        printf("Імя робітника: %s\n", name);
        conMove(21,3+k);
        printf("Прізвище робітника: %s\n", surname);
        conMove(22,3+k);
        printf("Рік народження: %i\n\n", year);    
        curr = List_next_return(curr);
        conMove(45,1);
        k = k + 50;
        conMove(25,3);
        conSetAttr(FG_RED);
        printf("Якщо бажаєте переглянути далі нажміть '2'  якщо хочете зупинитись нажміть '1'");
        conReset();
        z = conGetChar();
        if (z == '1'){
            break;
        }
        if (z == '2'){
            continue;
        }
        sleepMillis(MILLIS);
        fflush(stdout);
    }
    cleanstr(25,2);
    conMove(27,50);
    conSetAttr(FG_GREEN);
    puts("Всі структури виведенні");
    conReset();
}




void print_Node(void * self1, int position){
    List * self = self1;
    ListNode * curr = List_head_return(self);
    int i = 0;
    while(curr != NULL){
        if(i == position){
            Profecional * cur = ListNode_data_return(curr);
            conMove(17,3);
            printf("Назва професії: %s\n",  get_ProfName(cur));
            conMove(18,3);
            printf("Зарплата: %i\n", get_Salary(cur));
            conMove(19,3);
            printf("Рейтинг професії: %.1f\n", get_Score(cur));
            conMove(20,3);
            printf("Імя робітника: %s\n", get_Name(cur));
            conMove(21,3);
            printf("Прізвище робітника: %s\n", get_SurName(cur));
            conMove(22,3);
            printf("Рік народження: %i\n\n", get_Year(cur));
            break;
        }
        i++;
        curr = List_next_return(curr);
    }   
    if(position > List_count(self) || List_count(self) == 0){
        conMove(18,3);
        conSetAttr(FG_RED);
        puts("Даний вузол не заповнений");
        conReset();
    }
}


 char * print_change_struct(char * str){
    conMove(16,3);
    conSetAttr(FG_BLUE);
    puts("Введіть поле яке потрібно змінити");
    conReset();
    conMove(19,3);
    puts("profname");
    conMove(20,3);
    puts("salary");
    conMove(21,3);
    puts("score");
    conMove(22,3);
    puts("name");
    conMove(23,3);
    puts("surname");
    conMove(24,3);
    puts("year");

    conMove(16, 37);

    if(scanf("%s", str) == 1){

    }
    
    conMove(17,3);
    conSetAttr(FG_GREEN);
    puts("Введіть позицію вузла в якому змінити дані");
    conReset();
    conMove(18,3);
    conSetAttr(FG_RED);
    puts("Bведіть нові дані");
    conReset();
    return str;
 }


void Prof_input(char * str){
    str[0] = '\0';
  char * profname = (char*)malloc(50 *(sizeof(char)));
  char * salary = (char*)malloc(50 *(sizeof(char)));
  char * score = (char*)malloc(50 *(sizeof(char)));
  char * name = (char*)malloc(50 *(sizeof(char)));
  char * surname = (char*)malloc(50 *(sizeof(char)));
  char * year = (char*)malloc(50 *(sizeof(char)));

  
  cleanstr(16,3);
  profname[0] = '\0';
  conMove(16,3);
  conSetAttr(FG_BLUE);
  printf("Назва професії: ");
  conReset();
  if(scanf("%s",profname) ==1){

  }
  

  while(1)
  {   
      salary[0] = '\0';
      conMove(17,3);
      conSetAttr(FG_BLUE);
      printf("Зарплата:");
      conReset();
      if(scanf("%s",salary)==1){
      }
      if(validtest(salary)== 0 )
      {
          break;
      }
      else
      {
          cleanstr(17,11);
          conMove(18,3);
          conSetAttr(FG_RED);
          printf("Не правильний ввід введіть ще раз");
          conReset();
      }
  }
  cleanstr(18,3);
  while(1)
  {
      
      score[0] = '\0';
      conMove(18,3);
      conSetAttr(FG_BLUE);
      printf("Pейтинг професії: ");
      conReset();
      if(scanf("%s",score) == 1){

      }
      if(validtestfloat(score)== 0 )
      {
          break;
      }
      else
      {
          cleanstr(18,19);
          conMove(19,3);
          conSetAttr(FG_RED);
          printf("Не правильний ввід введіть ще раз");
          conReset();
      }
  }
  cleanstr(19,3);
  name[0] = '\0';
  conMove(19,3);
  conSetAttr(FG_BLUE);
  printf("Імя робітника: ");
  conReset();
  if(scanf("%s",name)==1){
      
  }

  conMove(20,3);
  conSetAttr(FG_BLUE);
  printf("Прізвище робітника: ");
  conReset();
  surname[0] = '\0';
  if(scanf("%s",surname)==1){

  }
  

  while(1)
  {
      conMove(21,3);
      conSetAttr(FG_BLUE);
      printf("Рік народження: ");
      conReset();
      year[0] = '\0';      
      if(scanf("%s",year) ==1){

      }
      if(validtest(year)== 0 )
      {
          cleanstr(22,3);
          break;
      }
      else
      {
          cleanstr(21,16);
          conMove(22,3);
          conSetAttr(FG_RED);
          printf("Не правильний ввід введіть ще раз");
          conReset();
      }
  }
  size_t len = strlen(profname);
  size_t len1 = strlen(salary);
  size_t len2 = strlen(score);
  size_t len3 = strlen(name);
  size_t len4 = strlen(surname);
  size_t len5 = strlen(year);
  strncpy(str, profname, len +1);
  strncpy(str + len, " ", 1);
  len = len + 1;
  strncpy(str + len, salary, len1 +1);
  len1 = len + len1;
  strncpy(str + len1, " ", 2);
  strncpy(str + len1 +1, score, len2 +5);
  len2 = len2 + len1+1;
  strncpy(str + len2, " ", 2);
  strncpy(str + len2 +1, name, len3 + 5);
  len3 = len3 + len2+1;
  strncpy(str + len3, " ", 2);
  strncpy(str + len3 +1, surname, len4 + 5);
  len4 = len3 + len4;
  strncpy(str + len4, " ", 2);
  strncpy(str + len4 +1, year, len5 + 5);


free(profname);
free(salary);
free(score);
free(name);
free(surname);
free(year);

}

