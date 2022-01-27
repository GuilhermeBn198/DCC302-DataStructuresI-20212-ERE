#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

//------------STRUCT DEFINITIONS-----------------

typedef struct _doubly_node {
	char nome[MAX];
	struct _doubly_node *prev;
	struct _doubly_node *next;
} Friend;

typedef struct _doubly_linked_list {
	Friend *begin;
	Friend *end;
	size_t size;
} LuiggysList;

//-CONSTRUCTORS & DECONSTRUCTORS OF THE SCRUCTURES----

Friend *create_node(char nome1[]) {
	Friend *friend = (Friend *)malloc(sizeof(Friend));
	strcpy(friend->nome, nome1);
	friend->next = NULL;
	friend->prev = NULL;
	return friend;
}

LuiggysList *create_list() {
	LuiggysList *L = (LuiggysList *)malloc(sizeof(LuiggysList));
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;
	return L;
}

//--------------FUNCTIONS-------------
bool list_is_empty(LuiggysList *L) { 
	return L->size == 0;
}

void list_add_last(LuiggysList *L, char nome[]){
	//caso a lista estiver vazia
	Friend *p = create_node(nome);
	if (list_is_empty(L)){
		L->begin = p;
	} else { //caso haja mais de um elemento
		L->end->next = p;
		p->prev = L->end;
	}
	L->end = p;
	L->size++;
}

void list_print(LuiggysList* L){
	Friend* p = L->begin;  						
	while (p != NULL) {				
		printf("%s-> ", p->nome);		
		p = p->next;   				
	}
	L->end == NULL ? printf(" NULL\n") :
							printf(" %s \n", L->end->nome);	
	printf("\nSize = %lu\n\n", L->size);
}

void list_print_new(LuiggysList* L){
	Friend* p = L->begin;  						
	while (p->next != NULL) {				
		printf("%s ", p->nome);		
		p = p->next;   				
	}
	printf ("%s\n", p->nome);
}

LuiggysList* list_add_friend(LuiggysList* L, LuiggysList* N, char amigo[]) {
	if (!list_is_empty(L) && !list_is_empty(N)){
		Friend *p = L->begin;
		while (p != NULL) {
			if (strncmp(p->nome, amigo, strlen(p->nome)) == 0){ //amigo existe na lista 1
				if (p == L->begin) { //amigo no inicio
					N->end->next = L->begin;
					L->begin->prev = N->end;
					N->end = L->end;
					return N;
				} else { //amigo no meio ou fim
					p->prev->next = N->begin;
					N->begin->prev = p->prev;
					N->end->next = p;
					p->prev = N->end;
					return L;
				}
			}
			p = p->next;
		}
		//amigo n existe ou é o nao
		L->end->next = N->begin;
		N->begin->prev = L->end;
		L->end = N->end;
		return L;
	}
	return NULL;	
}

//-------------------CODE TEST----------------------

int main(int argc, char const *argv[]){
	LuiggysList *L = create_list();
	LuiggysList *N = create_list();
	
	char entrada1[MAX];
	char entrada2[MAX];
	char amigo[MAX];

	//linha 1
	fgets(entrada1, sizeof(entrada1), stdin);
	char *token;
	token = strtok(entrada1, " \n");
	while (token != NULL)
	{
		list_add_last(L, token);
		token = strtok(NULL, " \n");
	}
	fflush(stdin);
	
	//linha 2
	fgets(entrada2, sizeof(entrada2), stdin);
	token = strtok(entrada2, " \n");
	while (token != NULL)
	{
		list_add_last(N, token);
		token = strtok(NULL, " \n");
	}
	fflush(stdin);

	//ler amigo
	fgets(amigo, sizeof(amigo), stdin);
	fflush(stdin);


	LuiggysList *S = create_list();
	S = list_add_friend(L,N, amigo);
	S->size = L->size + N->size;
	list_print_new(S);
	return 0;
}
