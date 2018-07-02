#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pbconsole.h>
#include <math.h>
#include <ctype.h>
#include <progbase.h>


struct profecional{
	char profname[100];
	int salary;
	float score;
	struct  {
	char name[100];
	char surname[100];
	int year;
} information;
} ;

/*void profecional_print(struct profecional * profs[]) {
    printf("\nFullname: %s; Salary: %i; Score: %f; name : %s; surname : %s; year %i;\n",
        st->profname, st->salary, st->score, st->information.name, st->information.surname, st->information.year);
}*/

void profecional_scanf(struct profecional *st){
  char profname[50];
  int salary =0;
  float score =0.0;
  char name[50];
  char surname[50];
  int year = 0;
	printf("enter profname");
  scanf("%s", &(*profname));
  strcpy(st->profname, profname);
  printf("enter salary");
  scanf("%i", &salary);
  st->salary = salary;
  printf("enter score");
  scanf("%f", &score);
  st->score = score;
  printf("enter name");
  scanf("%s", &(*name));
  strcpy(st->information.name,name);
  printf("enter surname");
  scanf("%s", &(*surname));
  strcpy(st->information.surname,surname);
  printf("enter year");
  scanf("%i", &year);
  st->information.year = year;

}

/*int texttostruct(struct profecional *st){
	char text[100];
	printf ("введіть текст");
	scanf(text,"%s%i%f%s%s%i",st->profname,&st->salary,&st->score,st->information.name,st->information.surname,&st->information.year);
	return EXIT_SUCCESS;
}*/



void stringtostruct( struct profecional * profs[]){
	int i =0;
	char str[200];
	fgets(str, 200, stdin);
	while(i !=1000){
		if(profs[i] == NULL){
		profs[i] = malloc(sizeof(struct profecional));
		sscanf(str,"%s %i %f %s %s %i",profs[i]->profname,&profs[i]->salary,&profs[i]->score,profs[i]->information.name,profs[i]->information.surname,&profs[i]->information.year);
		break;
		}
		else{
			i++;
		}
	}
}

void structtostring(struct profecional *st){
char str[200];
sprintf(str,"%s %i %f %s %s %i",st->profname,st->salary,st->score,st->information.name,st->information.surname,st->information.year);
printf("%s",str );
}

char enterstring(char *str){
	//char str[200];
	fgets(str, 200, stdin);
return *str;
}


void texttostruct(struct profecional * profs[]){
	int k = 0;
	int i=0;
	char str[200];
	while(1){
		printf("Якщо бажаєте продовжити нажміть 2 якщо ні нажміть 1\n");
		k = conGetChar();
		conReset();
		if(k==49){
			break;
		}
		if(k== 50){
			enterstring(str);
			if(profs[i]== NULL){
				profs[i] = malloc(sizeof(struct profecional));
				sscanf(str,"%s %i %f %s %s %i",profs[i]->profname,&profs[i]->salary,&profs[i]->score,profs[i]->information.name,profs[i]->information.surname,&profs[i]->information.year);
				str[0] = '\0';
				i++;
			}
		}
	}
}

void structtotext(struct profecional * profs[]){
	int i=0;
	for(i=0;i<1000;i++){
		if(profs[i] != NULL){
			printf("%s ",profs[i]->profname);
			printf("%i ",profs[i]->salary);
			printf("%f ",profs[i]->score);
			printf("%s ",profs[i]->information.name);
			printf("%s ",profs[i]->information.surname);
			printf("%i \n",profs[i]->information.year);
		}
	}
}
void deletestruct(struct profecional * profs[]){
	int i = 0;
		printf("Введіть індекс структури яку потрібно удалити");
		scanf ("%i",&i);
		profs[i] = NULL;
}
void copystruct (struct profecional * profs[]){
	int i =0;
	int k =0;
	printf("Введіть індекс структури з якої потрібно скопіювати значення");
	scanf ("%i",&i);
	if(profs[i] == NULL){
		profs[i] = malloc(sizeof(struct profecional));
	}
	printf("Введіть індекс структури в яку потрібно скопіювати значення");
	scanf ("%i",&k);
	if(profs[k] == NULL){
		profs[k] = malloc(sizeof(struct profecional));
		strcpy(profs[k]->profname,profs[i]->profname);
 		profs[k]->salary=	profs[i]->salary  ;
		profs[k]->score = profs[i]->score;
		strcpy(profs[k]->information.name,profs[i]->information.name);
		strcpy(profs[k]->information.surname,profs[i]->information.surname);
		profs[k]->information.year = profs[i]->information.year ;
}
}

void rewritefiealdinstruct(struct profecional * profs[]){
	int i = 0;
	int k = 0;
	char profname[100];
	int salary = 0;
 	float score = 0.0;
	char name[100];
	char surname[100];
	int year = 0;

	printf("Введіть індекс структури в якій потрібно перезаписати поле");
	scanf ("%i",&i);
	if (profs[i] == NULL){
		profs[i] = malloc(sizeof(struct profecional));
	}
	printf("Введіть яке поле змінити\n");
	printf("1 - назва професії\n");
	printf("2 - заробітня плата\n");
	printf("3 - рейтинг професії\n");
	printf("4 - імя робітника\n");
	printf("5 - прізвище робітника\n");
	printf("6 - рік народження працівника\n");


	while(1){
		k = conGetChar();
		if (k == 27){
			break;
		}
		switch (k){
			case 49:
				printf("Введіть назву професії");
				scanf("%s",profname);
				strcpy(profs[i]->profname,profname);
			break;
			case 50:
				printf("Введіть заробітню плату");
				scanf("%i",&salary);
				profs[i]->salary = salary;
			break;
			case 51:
				printf("Введіть рейтинг професії");
				scanf("%f",&score);
				profs[i]->score = score;
			break;
			case 52:
				printf("Введіть заробітню плату");
				scanf("%s",name);
				strcpy(profs[i]->information.name,name);
			break;
			case 53:
			scanf("%s",surname);
				printf("Введіть прізвище");
				strcpy(profs[i]->information.surname,surname);
			break;
			case 54:
				printf("Введіть рік народження");
				scanf("%i", &year);
				profs[i]->information.year = year;
			break;
		}
	}
}

int fileread(const char * readFileName, struct profecional *profs[]){
	enum { BUFFER_SIZE = 1000 };
	const char *read = readFileName;
	char buffer[BUFFER_SIZE];
	int i = 0;
	FILE * fin = fopen(read, "r");
	if (fin == NULL){
    printf("Error opening file\n");
    return EXIT_FAILURE;
  }
	while (!feof(fin)){
  	fgets(buffer, BUFFER_SIZE, fin);
    buffer[strlen(buffer) - 1] = '\0';
			while (i != 1000) {
				if (profs[i] == NULL){
					profs[i] = malloc(sizeof(struct profecional));
					break;
				}
				else{
					i++;
				}
			}

			sscanf(buffer,"%s %i %f %s %s %i",profs[i]->profname,&profs[i]->salary,&profs[i]->score,profs[i]->information.name,profs[i]->information.surname,&profs[i]->information.year);
			buffer[0]= '\0';
			i++;
	}
	return EXIT_SUCCESS;
}

int filewrite(const char * writeFileName,struct profecional *profs[]){
	const char *write =  writeFileName;
  FILE * fout = fopen(write, "w");
	for(int i = 0; i < 1000; i++){
		if(profs[i] != NULL){
	  fprintf(fout,"%s %i %f %s %s %i ", profs[i]->profname,profs[i]->salary,profs[i]->score,profs[i]->information.name,profs[i]->information.surname,profs[i]->information.year);
		}
	}
return EXIT_SUCCESS;
}

void highestsalary(struct profecional *profs[]){
	int midsalary = 0;
	printf("Введіть заробітню плату відносно якої потрібно виіести профеcії з більшою зарплатою");
	scanf ("%i", &midsalary);
	for(int i = 0; i < 1000; i++){
		if(profs[i] != NULL && profs[i]->salary > midsalary ){
			printf("Провесії з середньою зарплатою більшою за введену:%s",profs[i]->profname );
		}
	}
}


char filename(char *str){
	//char str[200];
	fgets(str, 200, stdin);
return *str;
}



/*int fileouttext(const char *writeFileName, struct profecional *st ){
	const char *write = writeFileName;

	FILE * fout = fopen(write, "w");
	while (){
	fprintf(fout,"%s%i%f%s%s%i", st->profname,&st->salary,st->score,st->information.name,st->information.surname,st->information.year);
	st++;
}
	return EXIT_SUCCESS;
}*/





int main(void){

int number = 1000;
int i =0;
struct profecional * profs[1000];
//char *str = "sfds 121 25.2 dsf dsfd 251";

for(i = 0 ; i < 1000; i++){
	profs[i]= NULL;
}


/*for(i=0;i<number;i++){
  profs[i] = malloc(sizeof(struct profecional));
}*/

highestsalary(profs);

//rewritefiealdinstruct(profs);


/*for(int j =0;j < 20;j++){
	 profecional_print(profs[j]);
}*/


for(i=0;i < number;i++){
	free( profs[i]);
}
return 0;
}
