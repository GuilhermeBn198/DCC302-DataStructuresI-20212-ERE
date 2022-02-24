#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//------------STRUCT DEFINITIONS-----------------

typedef struct _circ_node {
	int val;
	struct _circ_node *prev;
	struct _circ_node *next;
} CircNode;

typedef struct _circ_list {
	CircNode *begin;
	CircNode *end;
	size_t size;
} CircList;

//-CONSTRUCTORS & DECONSTRUCTORS OF THE SCRUCTURES----

CircNode *create_node(int val) {
	CircNode *cnode = (CircNode *)malloc(sizeof(CircNode));
	cnode->val = val;
	cnode->next = cnode;
	cnode->prev = cnode;
	return cnode;
}

CircList *create_list() {
	CircList *L = (CircList *)malloc(sizeof(CircList));
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;
	return L;
}

void destroy_list(CircList **L_ref){ //free allocated space
	CircList *L = *L_ref;

	CircNode *p = L->begin;
	CircNode *aux = NULL;

	while(p != L->end){
		aux = p;
		p = p->next;
		free(aux);
	}	
	free(p);
	free(L);
	*L_ref = NULL;
}

//--------------FUNCTIONS-------------

bool circlist_is_empty(CircList *L) { 
	return L->size == 0;
}

void circList_add_first(CircList *L, int val){
	
	CircNode *p = create_node(val);
	p->next = L->begin; //p point to the next node in the list
	
	
	
	if (circlist_is_empty(L)){ //case 1: if the list is empty
		L->begin = p;
		L->end = p;

	} else { //case 2: if the list is not empty 
		p->next = L->begin;
		L->begin->prev = p;
		L->begin = p;
		
		//parte circular!
		p->prev = L->end;
		L->end->next = p;
	}
	L->begin = p; //the beggining node will point now to p
	L->size++;
}
void list_remove(CircList *L, int val) {
  	CircNode *p = L->begin; 				//p node receives the first node!!!!
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

void verify_Duplicated(CircList *L){
	int terminated = 0;
	p = L->begin;
	while (terminated == 0){
		if (L->begin == p){
			
		}
		
	}
}

void circ_list_print(CircList* L){
	if (circlist_is_empty(L)) {
		printf("L -> NULL\n");
		printf("L -> begin -> NULL\n");
	} else {
		CircNode *p = L->begin;
		printf("L -> ");
		do
		{
			printf("%d -> ", p->val);
			p = p->next;
		} while (p != L->begin);
		printf("Size: %lu\n\n", L->size);
	}
}

//-------------------CODE TEST----------------------
int main(){
	
	return 0;
}