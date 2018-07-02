#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int file_process(const char * readFileName, const char * writeFileName)
{
		enum { BUFFER_SIZE = 250 };
    const char *read = readFileName;
    const char *write =  writeFileName;
    char buffer[BUFFER_SIZE];

    long number = 0;
    FILE * fin = fopen(read, "r");
    FILE * fout = fopen(write, "w");
    fprintf(fout,"%s\n\n", "Для кожного рядка, який починається на ціле число (від'ємні також враховувати), записати у рядок всі числа у діапазоні [-30, 30], розділяючи їх комами.");
    if (fin == NULL)
    {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }
    while (!feof(fin))
    {
        fgets(buffer, BUFFER_SIZE, fin);
        buffer[strlen(buffer) - 1] = '\0';
        if(isdigit(buffer[0]) ||(buffer[0] == '-' && isdigit(buffer[1])))
        {
            const char * ptr = buffer;
            while(*ptr!='\0')
            {
                if(isdigit(*ptr) || (*ptr == '-' ))
                {
                    number = strtol(ptr,(char**)&ptr,10);
                    if(number >= -30 && number <=30)
                    {
                        fprintf(fout," %ld,", number);
                    }
                }
                else
                {
                    ptr++;
                }

            }
        }
    }
    fseek(fout,-1,SEEK_END);
    fputs("." , fout);

    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
}
int main(void)
{
    file_process("input.txt", "output.txt");
    return 0;
}
