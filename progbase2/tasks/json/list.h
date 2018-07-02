#ifndef LIST_H
#define LIST_H



typedef struct ListNode ListNode;
typedef struct List List;

struct ListNode * ListNode_new(void * data);
struct List * List_new(void);
void List_addLast(struct List * self, void * data);
void ListNode_free(ListNode ** self);


ListNode * List_head_return(void * self);
void * ListNode_data_return(ListNode * self);
ListNode * List_next_return(ListNode * self);
int List_count(void * self);

void List_free(List ** self);
void List_clear(List * self);


#endif
