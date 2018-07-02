#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "list.h"


struct Text
{
   WordNode * head;
};

struct Word
{
    char word[20];     
};

struct WordNode{
Word word;
WordNode * next;
};

struct TextNode{
    Text data;
    struct TextNode * next;
};






void Word1_free(Word ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void Word_free(struct WordNode ** self) {
    assert(NULL != self);
    free(*self);
    self = NULL;
}



Word * Word_new(const char * str) {
    Word * data = (Word *)
    malloc(sizeof(Word));
    sscanf(str, "%s", data->word);
    return data;
}




WordNode * WordNode_copy(Text * self){
    WordNode * cur = self->head;
    return cur;
}
char * Word_getString(Word * self) {
    return self->word;
}



 Word * Text_getWord(Text * self, int wordIndex) {
    int count = 0;
    WordNode * cur = self->head;
    while (cur != NULL && count != wordIndex) {
        cur = cur->next;
        count++;
    }
    return &cur->word;
}



WordNode * Word_remove(Text * self) {
    struct WordNode * cur = self->head;
    if(strlen(cur->word.word) <= 3) {
        cur = Word_removeFirst(self);
        return cur;
    }
    while(cur->next->next != NULL && strlen(cur->next->word.word) > 3) {
        cur = cur->next;
    }
    struct WordNode * node = cur->next;
    cur->next = node->next;
    Word_free(&node);
    return cur->next;
}

struct WordNode * WordNode_new(Word word) {
    struct WordNode * node = (struct WordNode *)malloc(sizeof(struct WordNode));
    node->next = NULL;
    node->word = word;
    return node;
}

WordNode * Word_removeFirst(Text * self) {
    assert(self->head != NULL);
    struct WordNode * node = self->head;
    self->head = node->next;
    Word_free(&node);
    return self->head;
}

struct Text * TextList_new (void) {
    struct Text * list = (struct Text *)malloc(sizeof(struct Text));
    list->head = NULL;
    return list;
}

struct TextNode * TextNode_new(Text sent) {
    struct TextNode * node = (struct TextNode *)malloc(sizeof(struct TextNode *));
    node->next = NULL;
    node->data = sent;
    return node;
}



void Text_addLast(Text * self, Word * data) {
    WordNode * node = WordNode_new(*data);
    if (self->head == NULL) {
        self->head = node;
        return;
    }
    struct WordNode * cur = self->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = node;
}

void Text_change(Text * text1, Text* text2){
    text1->head = text2->head;
}


void Text_free(struct Text ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

int Text_count(struct Text * self) {
    int count = 0;
    WordNode * cur = self->head;
    while (cur != NULL) {
        count += 1;
        cur = cur->next;
    }
    return count;
}



void TextNode_free(struct TextNode ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

struct WordNode * Text_minWord(Text * self) {
    assert(self->head != NULL);
    struct WordNode * cur = self->head;
    struct WordNode * min = self->head;
    while (cur != NULL) {
        if (strlen(cur->word.word) < strlen(min->word.word)) {
            min = cur;
        }
        cur = cur->next;
    }
    return min;
}

void Text_removeNode(Text * self, struct WordNode * min) {
    assert(self->head != NULL);
    struct WordNode * cur = self->head;
    if (strcmp(self->head->word.word,min->word.word) == 0) {
        Text_removeFirst(self);
        return;
    }
    while (cur->next->next != NULL && strcmp(cur->next->word.word,min->word.word) != 0) {
        cur = cur->next;
    }
    struct WordNode * node = cur->next;
    cur->next = node->next;  
}

WordNode * Text_removeFirst(Text * self) {
    assert(self->head != NULL);
    struct WordNode * node = self->head;
    self->head = node->next;
    return self->head;
}

void Text_cleanList(Text * self){
    int size = Text_count(self);
    for(int i = 0; i < size; i++){
        WordNode * curr = self->head;
        if(curr == NULL) return;
        if(curr->next == NULL){
            Word_free(&curr);
            self->head = NULL;
            return;
        } 
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        Word_free(&(curr->next));
        curr->next = NULL;
    }
}

Word * getWord(WordNode * node) {
    return &node->word;
}
