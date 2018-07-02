
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>


#include "list.h"
#include "json.h"


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


void ListNode_free(ListNode ** self) {
    assert(NULL != self);
    Client_free(&(*self)->data);
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
void List_free(List ** self){
   assert(NULL != self);
   free(*self);
   *self = NULL;
}


void List_clear(List * self) {
    ListNode * cur = self->head;
    while (cur != NULL) {
        ListNode * node = cur;
        cur = cur->next; 
        ListNode_free(&node);
    }
    List_free(&self);
}
