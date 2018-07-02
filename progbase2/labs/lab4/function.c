
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase.h>
#include <progbase/console.h>





#include "convert.h"

#include "list.h"

#include "function.h"



List * text_in_struct1(void * self,char * filename){
    char * str = (char*)malloc(100 * sizeof(char));
    FILE * fin = fopen(filename, "r");
    if(fin == NULL){
        return NULL;
    }
    while(fgets(str, 100, fin)){
        Profecional * cur = Prof_new();
        str_in_struct(str, cur);
        List_addLast(self, cur);
    }
    free(str);
    fclose(fin);
    return self;
}


void file_output(List * self , char * filename){
    FILE * fout = fopen(filename, "w");
    ListNode  * cur = List_head_return(self);
    while(cur != NULL){
        fprintf(fout,"profname: %s; salary: %i; score: %.1f; name: %s; surname: %s; year: %i;\n",
        get_ProfName(ListNode_data_return(cur)),get_Salary(ListNode_data_return(cur)),
        get_Score(ListNode_data_return(cur)), get_Name(ListNode_data_return(cur)),
        get_SurName(ListNode_data_return(cur)), get_Year(ListNode_data_return(cur)));

        cur = List_next_return(cur);
    }
    fclose(fout);
}



