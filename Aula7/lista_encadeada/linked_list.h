#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef struct _node Node;
typedef struct _linked_list LinkedList;
Node* Node_create(int val);
LinkedList* LinkedList_create();
void LinkedList_add_first (LinkedList* L, int val) ;




#endif