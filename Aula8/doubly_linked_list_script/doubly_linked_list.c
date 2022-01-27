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

void destroy_list(List **L_ref){ //free allocated space
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

void list_add_last(List *L, int val) {
  	Node *p = create_node(val);
  	if (list_is_empty(L)) {
    		L->end = p;
    		L->begin = p;
  	} else {
    		p->prev = L->end;
    		L->end->next = p;
  	}
  	L->end = p;
  	L->size++;
}

void list_remove(List *L, int val) {
  	Node *p = L->begin; 				//p node receives the first node!!!!
  	while (p != NULL) {
    		if (p->val == val) { 			//verify if p is equal to val:
      		if (L->begin->val == val) {  	//verify if the first node is equal to val:
        			L->begin = p->next;  	//the first node point to p->next
        			p->next->prev = NULL; 	//the prev pointer of the first node after p points to NULL
      		} else {  				//if the first node isn't equal to val then:
        			p->prev->next = p->next;// the next pointer of the previous node of p will point to the next pointer of p
      		}
      		free(p);
      		L->size--;
    		}
    		p = p->next;  				//run p through the list
  	}
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
	list_add_first(L,10);
	puts("iteration with add first");
	list_print(L);
	puts("");

	//list_print_inverse(L);
	
	puts("----------------------------------------");
	
	puts("");
	puts("iteration with add last");
	list_add_last(L,50);
	list_print(L);

	puts("");

	//list_print_inverse(L);
	
	puts("----------------------------------------");
	
	puts("");
	puts("iteration with list_remove");
	list_remove(L,50);
	list_remove(L,4);
	list_print(L);
	destroy_list(&L);
	return 0;
}