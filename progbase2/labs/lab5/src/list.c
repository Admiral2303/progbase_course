
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase/console.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>



#include <list.h>


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


void List_addFirst(struct List * self, void * data) {
  struct ListNode * node = ListNode_new(data);
  node->next = self->head;
  self->head = node;
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

void ListNode_remove(List * self, int position) {
    int i = 0;
    //assert(self->head != NULL);
    struct ListNode * cur = self->head;
    if(self->head == NULL){
      return;
    }
    if (position == 0) {
        ListNode_removeFirst(self);
        return;
    }
    while(cur->next->next != NULL && i != position) {
        cur = cur->next;
        i++;
    }
    if(i != position-1){
      puts("Данний вузол не заповнений");
    }
    else{
      struct ListNode * node = cur->next;
      cur->next = node->next;
    }
}


ListNode * ListNode_removeFirst(List * self) {
    assert(self->head != NULL);
    struct ListNode * node = self->head;
    self->head = node->next;
    ListNode_free(&node);
    return self->head;
}



void ListNode_free(ListNode ** self){
   assert(NULL != self);
   Clean_prof(&(*self)->data);
   free(*self);
   *self = NULL;
}

void Clean_prof(void ** self){
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




void ListNode_add_in_position(List * self, int position, void * data){
struct ListNode * node = ListNode_new(data);
  if (self->head == NULL) {
    self->head = node;
    return;
  }
  struct ListNode * cur = self->head;
  int i = List_count(self);
  while (i == position-1) {
    cur = cur->next;
    i++;
  }
  node->next = cur->next;
  cur->next = node;
}

void List_clear(List * self) {
    ListNode * cur = self->head;
    if(self->head == NULL){
    return;
  }
    while (cur != NULL) {
        ListNode * node = cur;
        cur = cur->next; 
        ListNode_free(&node);
    }
    List_free(&self);
}

void List_clear1(List * self) {
  if(self->head == NULL){
    return;
  }
    ListNode * cur = self->head;
    while (cur != NULL) {
        ListNode * node = cur;
        cur = cur->next; 
        ListNode_free(&node);
    }
}



void List_free(List ** self){
   assert(NULL != self);
   free(*self);
   *self = NULL;
}
