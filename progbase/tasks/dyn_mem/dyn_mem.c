#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pbconsole.h>
#include <progbase.h>

int main(void)
{
    char * inputStr     = NULL;
    int * count = NULL;
    int * flag = NULL;

    inputStr = (char *) malloc(100 * sizeof(char));
    count = (int  *) malloc( 1 * sizeof(int ));
    flag = (int  *) malloc( 1 * sizeof(int ));

    if (NULL == inputStr || NULL == count || NULL == flag)
    {
        printf("Alloc error");
        return EXIT_FAILURE;
    }
    *flag = 0;
    printf("На основі введеної строки обчислити і вивести останній символ шістнадцяткової цифри, або символ ‘0’ якщо такого немає.\n");
    printf("Please, input string: ");
    fgets(inputStr, 100, stdin);
    for(*count = strlen(inputStr); *count > 0 ; (*count)--)
    {
        if(isxdigit(inputStr[*count]))
        {
        		conSetAttr(FG_RED);
            printf("останній символ шістнадцяткової цифри = %c\n", inputStr[(*count)]);
            *flag = 1;
            conReset();
            break;
        }
    }
    if(*flag == 0)
    {
        printf("\n0\n");
    }
    free(inputStr);
    free(count);
    free(flag);
    return EXIT_SUCCESS;
}
