
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>


#include "list.h"
#include "xml.h"


struct ListNode{
    void * data;
    struct ListNode * next;
};

struct List{
  struct ListNode * head;
};



struct ListNode * ListNode_new(void * data) {
  struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->next = NULL;
  node->data = data;   
  return node;
}


struct List * List_new(void) {
  struct List * list = (struct List *)malloc(sizeof(struct List));
  list->head = NULL;
return list;
}



void List_addLast(struct List * self, void * data) {
  struct ListNode * node = ListNode_new(data);
  if (self->head == NULL) {
    self->head = node;
    return;
  }
  struct ListNode * cur = self->head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = node;
}



void ListNode_free(ListNode ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}





int List_count(void * self){
  List * curr = self;
  ListNode * cur = curr->head;
  int count = 0;
  while(cur != NULL){
    count ++;
    cur = cur->next;
  }
  return count;
}




ListNode * List_head_return(void * self){
  List * cur = self;
  return cur->head;
}

void * ListNode_data_return(ListNode * self){
  return self->data;
}

ListNode * List_next_return(ListNode * self){
  return self->next;
}


void List_cleanList(List * self){
    int size = List_count(self);
    int i = 0;
    for(i = 0; i < size; i++){
        ListNode * curr = self->head;
        if(curr == NULL) return;
        if(curr->next == NULL){
            ListNode_free(&curr);
            self->head = NULL;
            return;
        } 
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        ListNode_free(&(curr->next));
        curr->next = NULL;
    }
}

void List_free(List ** self){
    free(*self);
    *self = NULL;
}


void delete_list(List * self){
   List_cleanList(self);
     int size = List_count(self);
     ListNode * cur = self->head;
     int i = 0; 
     for(; i < size; i++){
         Client * curr = cur->data;
         Client_free(&curr);
         cur = cur->next;
     }
     List_free(&self);
}

