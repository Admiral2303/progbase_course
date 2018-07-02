#include <progbase.h>
#include <pbconsole.h>
#include "function.h"
#include "menu.h"

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
    printf("1.Створити новий масив даних");
    conMove(9,45);
    printf("2.Зчитати масив даних із файлу або записати дані на файл");
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
    printf("1. Заповнити структуру через строку");
    conMove(6,35);
    printf("2. Вивести структуру по заданому індексу");
    conMove(7,35);
    printf("3. Заповнити структуру з тексту");
    conMove(8,35);
    printf("4. Видалити структуру по заданому індексу");
    conMove(9,35);
    printf("5. Вивести всі заповненні структури");
    conMove(10,35);
    printf("6. Скопіювати дані з одної структури в іншу");
    conMove(11,35);
    printf("7. Змінити поле структури по вказаному індексу");
    conMove(12,35);
    printf("8. Знайти назву професій в яких заробітня плата більша за введену");
    conMove(13,35);
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
