#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int val;
	struct _node *next;
} Node;

typedef struct _linked_list {
	Node *begin;
	Node *end;
} LinkedList;

Node* Node_Create(int val) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

LinkedList* LinkedList_create() {
	LinkedList* L = (LinkedList*) malloc(sizeof(LinkedList));
	L->begin = NULL;
	L->end = NULL;
	return L;
}

// void LinkedList_add_first (LinkedList* L, int val) {     //mais facil leitura, mais devagar
// 	Node* p = Node_Create(val);
// 	if (L->begin == NULL){

// 		L->begin = p;
// 	} else {	
// 		p->next = L->begin;
// 		L->begin = p;
// 	}
// }
void LinkedList_add_first (LinkedList* L, int val) {	  //mais logicamente correto, mais dificil de entender, garante emprego!!!
	Node* p = Node_Create(val);
	p->next = L->begin;
	L->begin = p;
}

void LinkedList_add_last (LinkedList* L, int val) {
	Node* q = Node_Create(val);
	if (L->begin == NULL){ //se a lista estiver vazia
 		L->begin = q;
		L->end = q;
	} else {
		L->end->next = q;
		L->end = q;
	}
}

void LinkedList_add_last_slow (LinkedList* L, int val) {
	Node* q = Node_Create(val);
	if (L->begin == NULL){
 		L->begin = q;
	} else {
		Node* p = L->begin; 
		while (p->next != NULL) { //enquanto p nao é o ultimo nó, ou seja, enquanto houver um proximo nó
			p = p->next;
		}
		//a partir daqui o ponteiro p aponta para o nó no final da lista basta apontar o p->next para o novo nó
		p->next = q;
	}
}
 

void LinkedList_print(LinkedList* L){
	Node* p = L->begin;
	printf("L-> ");
	while (p != NULL){
		printf("%d-> ", p->val);
		p= p->next;
	}
	printf("NULL\n");
}