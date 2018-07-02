#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pbconsole.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>

#include "function.h"
#include "menu.h"

#define NUMBEROFSTRUCTS  1000


void stringtostruct( struct profecional * profs[])
{
    int i =0;
    char str[200];
    conMove(16,3);
    conMove(17,3);
    conMove(41,3);
    while(i != NUMBEROFSTRUCTS)
    {
        if(profs[i] == NULL)
        {
            profs[i] = malloc(sizeof(struct profecional));

            printstructs(profs ,i, str);
            break;
        }
        else
        {
            i++;
        }
    }
    conReset();
    conMove(51,45);
}


void printstructs(struct profecional * profs[] ,int i, char *str)
{
    conMove(16,3);
    conSetAttr(FG_BLUE);
    printf("Hазва професії: ");
    conReset();
    scanf("%s",str);
    strcpy(profs[i]->profname,str);

    while(1)
    {
        str[0] = '\0';
        conMove(17,3);
        conSetAttr(FG_BLUE);
        printf("Зарплата:");
        conReset();
        scanf("%s",str);
        if(validtest(str)== 0 )
        {
            profs[i]->salary = atoi(str);
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
        str[0] = '\0';
        conMove(18,3);
        conSetAttr(FG_BLUE);
        printf("Pейтинг професії: ");
        conReset();
        scanf("%s",str);
        if(validtestfloat(str)== 0 )
        {
            profs[i]->score = atof(str);
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
    str[0] = '\0';
    conMove(19,3);
    conSetAttr(FG_BLUE);
    printf("Імя робітника: ");
    conReset();
    scanf("%s",str);
    strcpy(profs[i]->information.name,str);


    str[0] = '\0';
    conMove(20,3);
    conSetAttr(FG_BLUE);
    printf("Прізвище робітника: ");
    conReset();
    scanf("%s",str);
    strcpy(profs[i]->information.surname,str);


    while(1)
    {
        str[0] = '\0';
        conMove(21,3);
        conSetAttr(FG_BLUE);
        printf("Рік народження: ");
        conReset();
        scanf("%s",str);
        if(validtest(str)== 0 )
        {
            cleanstr(22,3);
            profs[i]->information.year = atoi(str);
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


void structtostring( struct profecional * profs[])
{
    conReset();
    int i = enterstuct();
    if(profs[i] == NULL)
    {
        conMove(18,3);
        conSetAttr(FG_CYAN);
        printf("Задана структура не завпонена");
        conReset();
    }
    else
    {
        conMove(17,3);
        printf("Назва професії: %s", profs[i]->profname);
        conMove(18,3);
        printf("Зарплата: %i", profs[i]->salary);
        conMove(19,3);
        printf("Рейтинг професії: %.1f", profs[i]->score);
        conMove(20,3);
        printf("Імя робітника: %s", profs[i]->information.name);
        conMove(21,3);
        printf("Прізвище робітника: %s", profs[i]->information.surname);
        conMove(22,3);
        printf("Рік народження: %i", profs[i]->information.year);
    }
}



int enterstuct(void)
{
    int i = 0;
    char str[10];

    conMove(16,3);
    printf("Введіть номер структури яку потрібно вивести ");
    scanf("%s",str);
    for(int k = 0; k < 10; k++)
    {
        if (isdigit(str[k]))
        {
            i = atoi(str);
            return i;
        }
    }
    return 1001;
}

void texttostruct(struct profecional * profs[])
{

    int k = 0;
    int i=0;
    char str[200];
    int flag = 0;


    while(1)
    {
        clearstringtostruct();
        conMove(41,3);
        if(flag == 0)
        {
            conMove(16,3);
            printf("Якщо хочете заповнити структуру нажміть 2");
            k = conGetChar();
        }
        if(flag == 1)
        {
            conMove(16,3);
            printf("Якщо бажаєте продовжити нажміть 2 якщо ні нажміть 1\n");
            k = conGetChar();

        }
        flag = 1;
        if(k=='1')
        {
            clearstringtostruct();
            break;

        }
        if(k == '2')
        {
            cleanstr(16,3);
            while(1)
            {
                if(profs[i]== NULL)
                {
                    profs[i] = malloc(sizeof(struct profecional));

                    printstructs(profs , i, str);
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
    }
}

void structtotext(struct profecional * profs[])
{
    clearstringtostruct();
    int i=0;
    int z = 0;
    const unsigned long MILLIS = 1;
    int k = 0;
    for(i=0; i< NUMBEROFSTRUCTS; i++)
    {

        if(profs[i] != NULL)
        {
            if(k > 60)
            {
                clearstringtostruct();
                k=0;
            }
            if(profs[i]->profname !='\0' && profs[i]->salary !=0)
            {
                conMove(17,3+k);
                printf("Назва професії: %s", profs[i]->profname);
                conMove(18,3+k);
                printf("Зарплата: %i", profs[i]->salary);
                conMove(19,3+k);
                printf("Рейтинг професії: %.1f", profs[i]->score);
                conMove(20,3+k);
                printf("Імя робітника: %s", profs[i]->information.name);
                conMove(21,3+k);
                printf("Прізвище робітника: %s", profs[i]->information.surname);
                conMove(22,3+k);
                printf("Рік народження: %i", profs[i]->information.year);
                conMove(45,1);
                k = k + 50;
                conMove(25,3);
                conSetAttr(FG_RED);
                printf("Якщо бажаєте переглянути далі нажміть '2'  якщо хочете зупинитись нажміть '1'");
                conReset();
                z = conGetChar();
                if (z == '1')
                {
                    break;
                }
                if (z == '2')
                {
                }

            }
        }
        sleepMillis(MILLIS);
        fflush(stdout);

    }
    if(i == 1000 || z == '1')
    {
        cleanstr(25,3);
        conMove(25,3);
        conSetAttr(FG_RED);
        printf("Всі структури виведенні");
        conReset();
    }
    conMove(41,3);
}



int scanint(char * str)
{
    int k = 0;
    int flag = 0;
    while(1)
    {
        if(validtest(str) == 0)
        {
            flag = 1;
            k = atoi(str);
            break;
        }
    }
    if(flag == 1)
    {
        return k;
    }
    else
    {
        return -1;
    }
}

int deltstruct1(struct profecional * profs[],int i)
{
    if(profs[i] != NULL)
    {
        free(profs[i]);
        profs[i] = NULL;
        return 0;
    }
    else
    {
        return 1;
    }
}



void deletestruct(struct profecional * profs[])
{
    clearstringtostruct();
    int i = 0;
    char str[100];
    conMove(16,3);
    printf("Введіть індекс структури яку потрібно удалити ");
    while(1)
    {
        str[0] = '\0';
        scanf ("%s",str);
        if(validtest(str) == 1)
        {
            conMove(17,3);
            printf("Неправильний ввід");
        }
        else
        {
            i = scanint(str);
            break;
        }
    }
    if(deltstruct1(profs,i) == 1 )
    {
        conMove(18,3);
        printf("Структура під номером %i не заповнена",i);
    }
    else
    {
        conMove(18,3);
        printf("Структура видалена");
    }
}

void copystruct (struct profecional * profs[])
{
    clearstringtostruct();
    int i =0;
    char str[100];
    int k =0;
    int flag = 0;
    conMove(16,3);
    printf("Введіть індекс структури з якої потрібно скопіювати значення ");
    scanf ("%s",str);
    i = scanint(str);
    if(i != -1 && checkstruct(profs,i) == 1)
    {
        conMove(17,3);
        conSetAttr(FG_RED);
        printf("Дана структура не заповнена");
        conReset();
        flag =1;
    }
    if( flag == 0)
    {
        str[0]='\0';
        conMove(18,3);
        printf("Введіть індекс структури в яку потрібно скопіювати значення ");
        scanf ("%s",str);
        k = scanint(str);
        if(profs[k] == NULL)
        {
            profs[k] =  malloc(sizeof(struct profecional));
        }
    }
    copstr(profs, i , k);
    conMove(45,1);
}


struct profecional * copstr(struct profecional * profs[],int i ,int k)
{
    if(profs[i] == NULL)
    {
        return NULL;
    }
    else
    {
        strcpy(profs[k]->profname,profs[i]->profname);
        profs[k]->salary=	profs[i]->salary  ;
        profs[k]->score = profs[i]->score;
        strcpy(profs[k]->information.name,profs[i]->information.name);
        strcpy(profs[k]->information.surname,profs[i]->information.surname);
        profs[k]->information.year = profs[i]->information.year ;
        return profs[k];
    }
}




int checkstruct(struct profecional * profs[],int i)
{
    if(profs[i] == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void rewhelp(int i, int j)
{
    conMove(i,j);
    printf("Якщо хочете продовжити виберіть поле для зміни якщо ні нажміть [q]");
}

void rewritefiealdinstruct(struct profecional * profs[])
{
    int i = 0;
    int k =0;
    char str[100];
    conMove(16,3);
    printf("Введіть індекс структури в якій потрібно перезаписати поле ");

    while(1){
      str[0] = '\0';
      cleanstr(16,61);
      conMove(16,62);
      scanf ("%s",str);
      if(validtest(str) == 0){
        i = scanint(str);
        break;
      }
      else{
        conMove(18,3);
        printf("Не правильний ввід");
      }
    }
    if (profs[i] == NULL)
    {
        profs[i] = malloc(sizeof(struct profecional));
    }
    conMove(17,3);
    conSetAttr(FG_CYAN);
    printf("Введіть яке поле змінити\n");
    conReset();
    conMove(18,3);
    printf("1 - назва професії\n");
    conMove(19,3);
    printf("2 - заробітня плата\n");
    conMove(20,3);
    printf("3 - рейтинг професії\n");
    conMove(21,3);
    printf("4 - імя робітника\n");
    conMove(22,3);
    printf("5 - прізвище робітника\n");
    conMove(23,3);
    printf("6 - рік народження працівника\n");

    while(1)
    {
        k = conGetChar();
        if (k == 'q')
        {
            clearstringtostruct();
            break;
        }
        switch (k)
        {
        case 49:
            clearfield();
            conMove(18,45);
            printf("Введіть назву професії ");
            scanf("%s",str);
            strcpy(profs[i]->profname,str);
            rewhelp(19,45);

            break;
        case 50:
            clearfield();
            while(1)
            {
                str[0] = '\0';
                conMove(19,45);
                printf("Введіть заробітню плату ");
                scanf("%s",str);
                if(validtest(str)== 0 )
                {
                    profs[i]->salary = atoi(str);
                    break;
                }
                else
                {
                    cleanstr(19,60);
                    conMove(20,45);
                    conSetAttr(FG_RED);
                    printf("Не правильний ввід введіть ще раз");
                    conReset();
                }
            }
            cleanstr(20,45);
            rewhelp(20,45);

            break;
        case 51:
            clearfield();
            while(1)
            {
                str[0] = '\0';
                conMove(20,45);
                printf("Введіть рейтинг професії ");
                scanf("%s",str);
                if(validtestfloat(str)== 0 )
                {
                    profs[i]->score = atof(str);
                    break;
                }
                else
                {
                    cleanstr(20,49);
                    conMove(21,45);
                    conSetAttr(FG_RED);
                    printf("Не правильний ввід введіть ще раз");
                    conReset();
                }
            }
            cleanstr(20,45);
            rewhelp(21,45);

            break;
        case 52:
            str[0]= '\0';
            clearfield();
            conMove(21,45);
            printf("Введіть імя працівника ");
            scanf("%s",str);
            strcpy(profs[i]->information.name,str);
            rewhelp(22,45);

            break;
        case 53:
            str[0] = '\0';
            clearfield();
            conMove(22,45);
            printf("Введіть прізвище ");
            scanf("%s",str);
            strcpy(profs[i]->information.surname,str);
            rewhelp(23,45);

            break;
        case 54:
            clearfield();
            while(1)
            {
                str[0] = '\0';
                conMove(23,45);
                printf("Введіть рік народження ");
                scanf("%s",str);
                if(validtest(str)== 0 )
                {
                    profs[i]->score = atoi(str);
                    break;
                }
                else
                {
                    cleanstr(23,45);
                    conMove(24,45);
                    conSetAttr(FG_RED);
                    printf("Не правильний ввід введіть ще раз");
                    conReset();
                }
            }
            cleanstr(24,68);
            rewhelp(24,45);

            break;
        }
    }
}






int filecheck(const char * readFileName)
{
    const char *read = readFileName;
    FILE * fin = fopen(read, "r");
    if (fin == NULL)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

int fileread(const char * readFileName, struct profecional *profs[])
{
    enum { BUFFER_SIZE = 1000 };
    const char *read = readFileName;
    char buffer[BUFFER_SIZE];
    int i = 0;
    FILE * fin = fopen(read, "r");
    if (filecheck(read) == 1)
    {
        conMove(16,3);
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }
    while (!feof(fin))
    {
        fgets(buffer, BUFFER_SIZE, fin);
        buffer[strlen(buffer) - 1] = '\0';
        while (i !=  NUMBEROFSTRUCTS)
        {
            if (profs[i] == NULL)
            {
                profs[i] = malloc(sizeof(struct profecional));
                break;
            }
            else
            {
                i++;
            }
        }
        sscanf(buffer,"%s %i %f %s %s %i",profs[i]->profname,&profs[i]->salary,&profs[i]->score,profs[i]->information.name,profs[i]->information.surname,&profs[i]->information.year);
        buffer[0]= '\0';
        i++;
    }
    conMove(17,3);
    printf("З файла считано ");
    fclose(fin);
    return EXIT_SUCCESS;
}

char filename(char str[100])
{
    fgets(str, 200, stdin);
    return *str;
}






int filewrite(struct profecional *profs[])
{
    char str[100];
    conMove(16,3);
    printf("Введіть назву файла в який потрібно записати структури ");
    filename(str);
    char *write = str;
    FILE *fout = fopen(write, "w");
    for(int i = 0; i <  NUMBEROFSTRUCTS; i++)
    {
        if(profs[i] != NULL && profs[i]->profname != '\0' && profs[i]->salary !=0 )
        {
            fprintf(fout,"Професія:%s| Зарплата:%i| Рейтинг професії%1.f| Імя: %s Прізвище: %s| Рік: %i\n ", profs[i]->profname,profs[i]->salary,profs[i]->score,profs[i]->information.name,profs[i]->information.surname,profs[i]->information.year);
        }
    }
    fclose(fout);
    return EXIT_SUCCESS;
}

void highestsalary(struct profecional *profs[])
{
    const unsigned long MILLIS = 500;
    int midsalary = 0;
    int k = 17;
    conMove(16,3);
    printf("Введіть заробітню плату відносно якої потрібно вивести профеcії з більшою зарплатою ");
    scanf ("%i", &midsalary);
    for(int i = 0; i <  NUMBEROFSTRUCTS; i++)
    {
        if(checksalary(profs,i,midsalary) == 0 )
        {
            if(k==29)
            {
                k=17;
                clear();
            }
            conMove(k,3);
            printf("Професії з середньою зарплатою більшою за введену: %s",profs[i]->profname );
            sleepMillis(MILLIS);
            k++;
            fflush(stdout);
        }
    }
}

int checksalary(struct profecional *profs[],int i,int midsalary)
{
    if(profs[i] != NULL && profs[i]->salary > midsalary)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
