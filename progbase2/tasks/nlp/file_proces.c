#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "list.h"

#include "file_proces.h"


Text * File_readFile(Text * self, const char * fileName){
    FILE * fin = fopen(fileName, "r");
    if(fin == NULL){
        return NULL;
    }
    char buffer[500];
    int check = 0;
    int wordIndex = 0;
    while(fgets(buffer, 500, fin) != NULL){
        buffer[strlen(buffer)] = '\0';
        for(int i = 0; i < strlen(buffer); i++){
        if(check == 1){
            check = 0;
        }
        char ch = buffer[i];
        if(isalpha(ch)){
            char str[20];
            while(isalpha(buffer[i])) {
                str[wordIndex] = buffer[i];
                i++;
                wordIndex++;
            }
            str[wordIndex] = '\0';
            Word * ptrWord = Word_new(str);
            wordIndex = 0;
            i--;
            Text_addLast(self, ptrWord);
            Word1_free(&ptrWord);
            } 
            else continue;
        }
    }
    fclose(fin);
    return self;
}



void File_printResult(Text * self, const char * writeFileName, int count) {
  FILE * fout = fopen(writeFileName, "w");
  assert(fout != NULL);

  int i = 0;
    for (i = 0; i < count - 1; i++) {
        fprintf(fout, "%s", Word_getString(Text_getWord(self, i)));
        fputc('\n', fout);
    }
    fprintf(fout, "%s", Word_getString(Text_getWord(self, i)));
    fputc('\n', fout);
    fclose(fout);
}









