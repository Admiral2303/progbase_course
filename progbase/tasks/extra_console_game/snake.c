#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <pbconsole.h>
#include <time.h>






#define up  0
#define  left  1
#define right  2
#define  down  3

struct snake
{
    int x ;
    int y ;

};

struct dot
{
    int x;
    int y;
};

struct result
{
    char nickname[50];
    int score;
};



int openfile(struct result  result[], char * filename);
int structinfile(struct result result, char * filename);
void sortirovka(struct result result[],int i);
void end(int score, char name[50]);
int tabletostruct(char * filename, struct result results[]);
char name(char str[100]);
void clean();
int tempchoose(int temp);
void printscore(int score,int level);
void firstmenu();
void printsnake(struct snake snake[], int size);
struct dot randdot(struct dot dot);
void printdot(struct dot dot);
struct snake * move(struct snake snake[], int size, int position);
void lines();
int randomy();
int randomx();

int main(void)
{

    int flag1 = 0;
    int speedlevel = 0;
    int flag = 0;
    int score = 0;
    int temp = 150;
    struct snake snake[1800];
    struct dot dot;
    int gameover = 1;
    int position = 0;
    int size = 3;
    char name[100];
    struct result result[20];
    struct result to_write;
    int flag2 = 0;
    int i = 0;
    int flag3 = 0;
    lines();

    char key;


    conLockInput();
    firstmenu();

    while (1)
    {
        if(flag3 == 1 )
        {
            firstmenu();
        }
        size = 3;
        score = 0;
        speedlevel = 0;
        snake[0].x = 30;
        snake[0].y = 15;
        name[0] = '\0';
        gameover = 1;
        int k = conGetChar();
        flag2 = 0;
        if(k == '2')
        {
            clean();
            for(int i = 2; i < 35; i++)
            {
                for(int j = 2; j < 110; j++)
                {
                    conMove(i,j);
                    puts(" ");
                }
            }
            i = openfile(result, "output.txt");
            flag2 = 1;
            flag3 = 0;
            sortirovka(result,i);
        }
        if(k == '1')
        {
            clean();
            temp = tempchoose(temp);
            clean();
            conMove(23,45);
            puts("Введіть нікнейм");
            conMove(24,45);
            scanf("%s",name);
            flag2 = 0;

        }
        if(k == 'q')
        {
            break;
        }

        if(flag2 == 0)
        {
            printsnake(snake,size);
            conHideCursor();
            clean();
            key = 'w';
            lines();
            while(gameover != 0)
            {
                if(flag1 == 1)
                {
                    conMove(1,1);
                    conSetAttr(BG_YELLOW);
                    puts(" ");
                    conReset();
                }
                flag1 = 1;
                printscore(score,speedlevel);
                conMove(40,145);
                if(conIsKeyDown() != 0)
                {
                    key = fgetc(stdin);
                    conMove(40,145);
                    puts(" ");
                    switch(key)
                    {
                    case 'q':
                        gameover = 0;

                    }
                }
                else
                {
                    fflush(stdin);
                    sleepMillis(temp);

                    if(flag == 0)
                    {
                        dot = randdot(dot);
                        flag = 1;
                    }
                    printdot(dot);
                    if(key == 'w')
                    {
                        if(position != down)
                        {
                            position = up;
                            move(snake, size, up);
                        }
                        else
                        {
                            key = 's';
                            continue;
                        }
                    }
                    if(key == 'a')
                    {
                        if (position != right)
                        {
                            position = left;
                            move(snake, size, left);
                        }
                        else
                        {
                            key = 'd';
                            continue;
                        }
                    }
                    if(key == 's')
                    {
                        if(position != up)
                        {
                            position = down;
                            move(snake, size, down);
                        }
                        else
                        {
                            key = 'w';
                            continue;
                        }
                    }
                    if(key == 'd')
                    {
                        if(position != left)
                        {
                            position = right;
                            move(snake, size, right);
                        }
                        else
                        {
                            key = 'a';
                            continue;
                        }
                    }
                    if(snake[0].x == 1 || snake[0].x == 40)
                    {
                        gameover = 0;
                    }
                    if(snake[0].y == 1 || snake[0].y == 120)
                    {
                        gameover = 0;
                    }
                    for(int k = 3; k < size; k++)
                    {
                        if(snake[0].x == snake[k].x && snake[0].y == snake[k].y)
                        {
                            gameover = 0;
                        }
                    }
                    if(snake[0].x == dot.x && snake[0].y == dot.y)
                    {
                        size++;
                        score++;
                        flag = 0;
                        if(score % 3 == 0 )
                        {
                            if(speedlevel != 8)
                            {
                                speedlevel++;
                                temp -= 10;
                            }
                            if(speedlevel == 9)
                            {
                                temp = 0;
                            }
                        }
                    }

                }

            }

            if(gameover == 0)
            {
                end(score,name);
                conMove(26,45);
            }


            to_write.score = score;
            strcpy(to_write.nickname, name);
            structinfile(to_write,"output.txt");


        }


    }



    conUnlockInput();
    conShowCursor();
    conReset();


    return 0;
}



void lines()
{
    conClear();
    for(int i = 0; i <120; i++)
    {
        conMove(1,i);
        conSetAttr(BG_YELLOW);
        printf(" ");
        conMove(40,i);
        printf(" ");
    }
    for(int i = 0; i <= 40; i++)
    {
        conMove(i,1);
        conSetAttr(BG_YELLOW);
        printf(" ");
        conMove(i,120);
        conSetAttr(BG_YELLOW);
        printf(" ");
    }
    conReset();
    conMove(50,1);
}

struct snake * move(struct snake snake[], int size, int position)
{
    int deletex = 0;
    int deletey = 0;
    int masiv[size];
    for(int i = 0; i < size; i++)
    {
        masiv[i] = snake[i].x;
    }
    deletex = masiv[size - 1];
    for(int j = 0; j + 1 < size; j++)
    {
        snake[j + 1].x = masiv[j];
    }
    for(int i = 0; i < size; i++)
    {
        masiv[i] = snake[i].y;
    }
    deletey = masiv[size-1];
    for(int j = 0; j + 1 < size; j++)
    {
        snake[j + 1].y = masiv[j];
    }
    if(position == up)
    {
        snake[0].x--;
    }
    if(position == down)
    {
        snake[0].x++;
    }
    if(position == left)
    {
        snake[0].y--;
    }
    if(position == right)
    {
        snake[0].y++;
    }
    conMove(deletex, deletey);
    putchar(' ');
    conMove(snake[0].x, snake[0].y);
    conSetAttr(BG_RED);
    putchar(' ');
    conReset();


    return snake;
}


void printsnake(struct snake snake[], int size)
{
    for(int i = 0; i < size; i++)
    {
        conMove(snake[i].x, snake[i].y);
        conSetAttr(BG_RED);
        putchar(' ');
        conReset();
    }
}
struct dot randdot(struct dot dot)
{
    dot.x = randomx();
    dot.y = randomy();
    return dot;
}

void printdot(struct dot dot)
{
    conMove(dot.x,dot.y);
    conSetAttr(BG_INTENSITY_CYAN);
    puts(" ");
    conReset();

}

void printscore(int score,int level)
{
    conMove(1,55);
    conSetAttr(FG_GREEN);
    printf("LEVEL: %i", level);
    conMove(40,55);
    conSetAttr(FG_GREEN);
    printf("SCORE: %i", score);
    conReset();
}

void firstmenu()
{
    conMove(20,55);
    printf("1 -Почати гру");
    conMove(22,55);
    printf("2 -Таблиця результатів ") ;
}



int tempchoose(int temp)
{

    int k = 0;
    conMove(23,45);
    puts("Виберіть швидкість від 1 до 9");
    conMove(24,45);
    scanf("%i", &k);
    switch (k)
    {
    case 1:
        temp = 150;
        break;
    case 2:
        temp = 130;
        break;
    case 3:
        temp = 110;
        break;
    case 4:
        temp = 100;
        break;
    case 5:
        temp = 90;
        break;
    case 6:
        temp = 80;
        break;
    case 7:
        temp = 70;
        break;
    case 8:
        temp = 60;
        break;
    case 9:
        temp = 50;
        break;
    }
    return temp;
}
void clean()
{
    for(int i = 2; i < 40; i++)
    {
        for(int j = 2; j < 120; j++)
        {
            puts(" ");
            conMove(i,j);
        }
    }
    conMove(25,1);
    conSetAttr(BG_YELLOW);
    puts(" ");
    conMove(1,1);
    conSetAttr(BG_YELLOW);
    puts(" ");
    conReset();
}


char name(char str[100])
{
    conMove(23,45);
    scanf("%s",str );
    return *str;
}






int tabletostruct(char * filename, struct result results[])
{
    int i = 0;
    FILE * fin = fopen(filename, "r");
    if(fin == NULL)
    {
        return EXIT_FAILURE;
    }
    char str[50];
    while (fgets(str, 50, fin) != NULL)
    {
        str[strlen(str) - 1] = '\0';
        sscanf(str, "%i %s", &results[i].score, results[i].nickname);
        i++;
    }
    fclose(fin);
    return i;
}
/*int structto*/




void end(int score, char name[50])
{
    clean();
    conMove(18,45);
    conSetAttr(FG_CYAN);
    printf("%s Результат :%i",name,score);
    conReset();
    conMove(20,55);
    printf("1 -Почати гру");
    conMove(22,55);
    printf("2 -Таблиця результатів ") ;
    conMove(25,55);
    printf("q - вихід ") ;
}


void sortirovka(struct result result[],int i)
{
    int temp;
    conMove(3,45);
    puts("1 - Начати гру");
    conMove(5,45);
    puts("q - вихід");
    for(int p = 0; p <= i; p++)
    {
        for(int z = 0; z <= i-1-p; z++)
        {
            if(result[z+1].score < result[z].score)
            {
                temp = result[z].score;
                result[z].score = result[z+1].score;
                result[z+1].score = temp;
            }
        }
    }
    for(int k = 0; k <= i; k++)
    {
        conMove(12+k,45);
        printf("result: %i    -  nickname: %s\n",result[k].score, result[k].nickname);
    }
}

int openfile(struct result  result[], char * filename)
{
    char str[50];
    int i=0;
    FILE * fin = fopen("output.txt", "r");
    if(fin == NULL)
    {
        return EXIT_FAILURE;
    }
    while (fgets(str, 50, fin) != NULL)
    {
        str[strlen(str) - 1] = '\0';
        sscanf(str, "%i %s", &result[i].score, result[i].nickname);
        //dop[i] = result[i].score;
        //  printf("%i - %s\n",result[i].score, result[i].nickname);
        i++;
    }
    i--;
    return i;
}



int structinfile(struct result result, char * filename)
{
    char * str = (char*)malloc(100);
    if(str == NULL)
    {
        return EXIT_FAILURE;
    }
    FILE * fout = fopen(filename, "a+");
    if(fout == NULL)
    {
        return EXIT_FAILURE;
    }
    fseek(fout,0,SEEK_END);
    fprintf(fout, "%i %s\n" , result.score, result.nickname);
    fclose(fout);
    return EXIT_SUCCESS;
}


int randomx()
{
    srand(time(0));
    int x = rand() %(30-2) + 2 ;
    return x;
}

int randomy()
{
    srand(time(0));
    int y = rand() %(120-2) + 2 ;
    return y;
}
