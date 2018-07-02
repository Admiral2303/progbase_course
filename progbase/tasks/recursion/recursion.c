#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pbconsole.h>



int xdigitsNum(const char * str);
int main(void) {
    char str[100];
    int number = 0;
    int j = 0;
    printf("PLease, enter a string: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    printf("You've entered: %s\n", str);

    
    number = xdigitsNum(str);
    for(j=0; j < strlen(str); j++){
    	if(isxdigit(str[j])){
    		conSetAttr(FG_RED);
    		printf("%c", str[j]);
    		conReset();
   		 }
   		 else {
   		 	printf("%c",str[j]);
   		 }
    }
    printf("\nTask: get number of all hex numbers in string: %i\n\n", number);

    return EXIT_SUCCESS;
}

int xdigitsNum(const char * str) {
    char firstChar = str[0];   
    static int i = 0;
    static int num = 0;
    if (firstChar == '\0') {
    	return num;
    }
     
     else if(!isxdigit(firstChar)){
     		return xdigitsNum(str+1); 
     }
     else{
     		num=1+i;
				i++;
     		return xdigitsNum(str+1);
     }
  
      }   

