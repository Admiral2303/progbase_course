#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "xml.h"
#include "list.h"



int main(void){
    Freelancer*  self =  sample();
    char str[10000];
    XmlLoader_saveToString(str, self);
    printf("%s", str);
    Freelancer * self1 = Freelancer_new();
    XmlLoader_loadFromString(self1, str);
    print(self1);
    puts("");


    List * del = listget(self);
    List * del1 = listget(self1);
    delete_list(del1);
    delete_list(del);
    Freelancer_free(&self1);    
    Freelancer_free(&self);
    return 0;
}
