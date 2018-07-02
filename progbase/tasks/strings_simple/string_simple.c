#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <progbase.h>
#include <pbconsole.h>

	int main (void){

	char str[]={"But it is not only it is old age and history that make Kyiv stand out among other cities. It is a uniqueand extremely harmonious combination of historic values and traditions with modern style and ways oflife that attracts crowds of people from all over the world to Kyiv. At present Kyiv is a leading industrial centre of Ukraine. Its industries manufacture sea-going fishingtrawlers, planes, automated laser equipment, hundreds of types of consumer goods. The city has over three hundries institutes."};
	int size;
	int i = 0;
	int count = 0;
	char consonants[] = {'B','C','D','F','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z'};
	char consonants1[] = {'b','c','d','f','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z','B','C','D','F','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z'};
	int j = 0;
	int sizecon = 0;
	int poslastvowel = 0;
	char str2[500];
	char str3[500];
	int str2lenth = 0;
	int l = 0;
	int str3lenth = 0;
	int k = 0;
	int sizecon1 = 0;
	int number = 0;


	sizecon1 = sizeof(consonants1);
	sizecon = sizeof(consonants);
/*********Task1*********/
	size = strlen(str);
	conSetAttr(FG_BLUE);
	printf("Task 1(Вивести текст повністю у консолі та загальну кількість символів у тексті.)\n");
	conReset();
		for(i = 0; i < strlen(str);i++){
			printf("%c",str[i]);
		}
		conSetAttr(FG_RED);
		printf("\nРозмір =  %i", size);
		conReset();
		printf("\n=====================================================================================================");


/*********Task2*********/
	conSetAttr(FG_BLUE);
	printf("\nTask 2(Вивести текст без пробільних символів та кількість виведених символів.)\n");
	conReset();
		for(i = 0; i < strlen(str);i++){
			if(isspace(str[i]) ==0){
				printf("%c", str[i]);
			}
			else{
				i++ ;
				printf("%c", str[i]);
			}
		count ++;
		}
		conSetAttr(FG_RED);
		printf("\nкількість елементів без пробілів = %i\n",count);
		conReset();
		printf("\n=====================================================================================================");
/**********Task3*********/
	conSetAttr(FG_BLUE);
	printf("\nTask3(Вивести всі речення тексту, кожне речення із нового рядка та із відміткою про кількість символів у виведеному реченні.)\n");
	conReset();
	count = 0;
		for(i = 0; i < strlen(str);i++){
				if((str[i] == '.') ||(str[i] ==  '!') ||(str[i] ==  '?')){
					conSetAttr(FG_RED);
					printf("%c\nкількість елементів в речені = %i\n",str[i], count+1);
					count = 0;
					printf("_________\n");
					conReset();
				}
				else{ 
					printf("%c", str[i]);
					count++;
				}
			}
		printf("\n=====================================================================================================");

/*************Task4************/

		conSetAttr(FG_BLUE);
		printf("\nTask4(Вивести загальну кількість слів у тексті.)\n");
		conReset();
		if(size != 0){
			count = 1;}
		else{
			count = 0; }
			for(i = 0; i < strlen(str);i++){
				if(isspace(str[i]) != 0){
					count++;
				}
			}
			conSetAttr(FG_RED);
			printf("кількість слів в тексті = %i",count);
			conReset();
			printf("\n=====================================================================================================");

/**************Task5****************/
			conSetAttr(FG_BLUE);
			printf("\nTask5(У одному рядку, через кому і один пробіл, вивести всі слова, що починаються на приголосну літеру у верхньому регістрі. Також вивести загальну кількість таких слів.)\n");
			conReset();
			count = 0;
				for(j = 0; j < sizecon; j ++){
					if(str[0] == consonants[j]){
						count = 1;
					}
				}
				for(i = 0; i < size;i++){
					for(j = 0; j < sizecon; j ++){
						if(isspace(str[i]) !=0 && str[i+1] == consonants[j]){
							count++;
						}
					}
				}
				for(i = size; i > 0; i--){
					for(j = 0; j < sizecon; j ++){
					if(isspace(str[i]) !=0 && str[i+1] == consonants[j]){
						poslastvowel = i-1;
					break;}
						}	
					if (poslastvowel != 0){
						break;}
				}

			i = 0;
				for(j = 0; j < sizecon; j ++){
					if(str[0] == consonants[j]){
						while(isalpha(str[i]) !=0 || ispunct(str[i]) ==0){
							printf("%c", str[i]);
							i++;
						}
						printf(", ");
					}
				}


 				for(i = 0; str[i]!='\0';i++){
					for(j = 0; j < sizecon; j ++){
 						if(isspace(str[i]) !=0 && str[i+1] == consonants[j]){
							i++; 
								while( isalpha(str[i]) != 0){
									printf("%c", str[i]);
									i++;
								}
								i--;
								if(i < poslastvowel){
									printf(", ");
								}
								else{
									printf(".");
								}
						}
					}
				}
				conSetAttr(FG_RED);
				printf("\nкількість слів на приголосну букву у верхньому регістрі = %i",count);
				conReset();
				printf("\n=====================================================================================================");
/****************Task6*************/
	conSetAttr(FG_BLUE);
	printf("\n\nTask 6(У одному рядку, через кому і один пробіл, вивести всі слова, у яких починаються та закінчуються на приголосну літеру. Також вивести загальну кількість таких слів.)\n");
	conReset();
	k=0;
		for(l = 0; l < sizecon1;l++){
			j++;
				if(str[0] == consonants1[l]){
					for(i = 0;  str[i]!='\0';i++){
						for(j = 0; j < sizecon1;j++){
							if(isalpha(str[i]) !=0 && str[i -1] == consonants1[j]){
								while(isalpha(str[k]) !=0){
									printf("%c", str[k]);
									k++;
									}
								}
								if(k!=0){break;}
							}
						}
						if(j!=0){break;}
					}
				}
				for(i = 0; str[i]!='\0';i++){
					for(j = 0; j < sizecon1; j ++){
 						if((isspace(str[i])!=0 || ispunct(str[i]) !=0) && str[i+1] == consonants1[j] ){
							i++;
								while( isalpha(str[i]) != 0){
									str2[l]= str[i];
									i++;
									l++;
								}
								i--;
								str2[l]=' ';
								l++;
								} 
						}
					}
					str2lenth = l;
					for(i = str2lenth; i>0 ;i--){
						for(j = 0; j < sizecon1; j ++){
	 						if(isspace(str2[i])!=0  && str2[i-1] == consonants1[j]){
								i--;
									while( isalpha(str2[i]) != 0){
										 str3[k]= str2[i];
										i--;
										k++;
									}
									i++;
									str3[k]=' ';
									str3[k+1] = ',';
									k=k+2;
									number ++;
									} 
							}
						}
						str3lenth = k;
							for(k=str3lenth -1 ;k >-1;k--){
								printf("%c", str3[k]);
							}
							conSetAttr(FG_RED);
							printf("\nкількість елементів які починаються і закінчуються на приголосну літеру = %i",number);
							conReset();


return 0;
}

