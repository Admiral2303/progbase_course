#include <stdio.h>
#include "list.h"
#include "file_proces.h"





void Text_sort (Text * self);
Text * Text_removeWords(Text * self);

int main(void) {   
    Text * text = TextList_new();
    File_readFile(text, "text1.txt");
    Text_removeWords(text);
    Text_sort(text);
    File_printResult(text, "out.txt", Text_count(text));    
    Text_cleanList(text);
    Text_free(&text);  
    return 0;
}


void Text_sort (Text * self) {
    int count = Text_count(self);
    int i = 0;
    Text * text = TextList_new();
    while (i != count) {   
        WordNode * min = Text_minWord(self);
        Word * new = getWord(min);              
        Text_addLast(text, new);
        Text_removeNode(self, min);   
        i++;   
        Word_free(&min);
    }
    Text_change(self,text);
    Text_free(&text);
}

Text * Text_removeWords(Text * self) {
    WordNode * cur = WordNode_copy(self) ;  
    while (cur != NULL) {
        cur = Word_remove(self);
    }
    Word_free(&cur);
    return self;
}

