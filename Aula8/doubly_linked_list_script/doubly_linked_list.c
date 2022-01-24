#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//------------STRUCT DEFINITIONS-----------------

typedef struct _doubly_node {
	int val;
	struct _doubly_node *prev;
	struct _doubly_node *next;
} Doubly_Node, Node;

typedef struct _doubly_linked_list {
	Doubly_Node *begin;
	Doubly_Node *end;
	size_t size;
} Doubly_Linked_List, List;

//-CONSTRUCTORS & DECONSTRUCTORS OF THE SCRUCTURES----

Node *create_node(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

List *create_list() {
	List *L = (List *)malloc(sizeof(List));
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;
	return L;
}

void destroy_list(List **L_ref){
	List *L = *L_ref;
	Node *p = L->begin;
	Node *aux = NULL;
	while(p != NULL){
		aux = p;
		p = p->next;
		free(aux);
	}	
	free(L);
	*L_ref = NULL;
}

//--------------FUNCTIONS-------------

bool list_is_empty(List *L) { 
	return L->size == 0;
}

void list_add_first(List *L, int val){
	Node *p = create_node(val);
	p->next = L->begin; //p point to the next node in the list
	
	//case 1: if the list is empty
	if (list_is_empty(L)){
		L->end = p;
	
	//case 2: if the list is not empty
	} else { 
		L->begin->prev = p; //next in the list point back to p
	}
	L->begin = p; //the beggining node will point now to p
	L->size++;
}

void list_print(List* L){
	Node* p = L->begin;
	printf("L-> ");
	while (p != NULL) {
		printf("%d-> ", p->val);
		p = p->next;
	}
	printf("NULL\n");
	// if (L->end == NULL){
	// 	printf("L->end = NULL\n");
	// } else {
	// 	printf("L->end = %d\n", L->end->val);
	// }

	//this is a ternary IF! the IF of the PRO programers
	L->end == NULL ? printf("L->end = NULL\n") : printf("L->end = %d\n", L->end->val);

	printf("Size = %lu\n", L->size);
}

void list_print_inverse(List* L){
	Node* p = L->end;
	printf("L-> ");
	while (p != NULL) {
		printf("%d-> ", p->val);
		p = p->prev;
	}
	printf("NULL\n");

	if (L->begin == NULL){
		printf("L->begin = NULL\n");
	} else {
		printf("L->begin = %d\n", L->begin->val);
	}

	//this is a ternary IF! the IF of the PRO programers
	//L->begin == NULL ? printf("L->begin = NULL\n") : printf("L->begin = %d\n", L->begin->val);
}

//-------------------CODE TEST----------------------
int main(){
	List *L = create_list();
	list_add_first(L,7);
	list_add_first(L,4);
	list_add_first(L,2);
	list_add_first(L,10);

	list_print(L);
	list_print_inverse(L);

	destroy_list(&L);
	return 0;
}