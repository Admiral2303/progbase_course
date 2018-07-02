#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "json.h"
#include "list.h"




int main(void){
    Freelancer *  self =  sample();
    char  str[500] ;
    JsonLoader_saveToString(str, self);
    puts(str);
    Freelancer * self1 = Freelancer_new();
    JsonLoader_loadFromString(self1, str);
    print(self1);

    List * del = listget(self);
    List * del1 = listget(self1);
    List_clear(del);
    List_clear(del1);
    Freelancer_free(&self1);    
    Freelancer_free(&self);
    return 0;
}

