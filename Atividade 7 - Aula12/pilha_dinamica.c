/*
--implementação de uma pilha estatica
--autor: guilherme Bernardo
--data:27/02/2022
*/

#include <stdio.h>
#include <stdlib.h>

// ---------------------- definição da estrutura!----------------------

typedef struct Node{
	int dado;
	struct Node *prox;
} Node;

typedef struct Stack{
	Node *topo;
} Stack;
// ---------------------- construtores e destrutores
void initStack(Stack *stack) {
	stack->topo = NULL;
}

//---------------------- funções! -----------------------
void pushIntoStack(int dado, Stack *stack){
	Node *ptr = (Node*) malloc(sizeof(Node));
	if(ptr == NULL){
		printf("Erro de alocação de nó. \n");
		return;
	} else {
		ptr->dado = dado;
		ptr->prox = stack->topo;
		stack->topo = ptr;
	}
}

int popOutStack(Stack *stack){
	Node* ptr = stack->topo;
	int dado;
	if (ptr == NULL){
		printf("Pilha Vazia!\n");
		return 0;
	} else {
		stack->topo = ptr->prox;
		ptr->prox = NULL;
		dado = ptr->dado;
		free(ptr);
		return dado;
	}
}

void printStack(Stack *stack){
	Node* ptr = stack->topo;
	if (ptr == NULL){
		printf("Pilha vazia!\n");
	}else{
		while(ptr != NULL){
			printf("%d ", ptr->dado);
			ptr = ptr->prox;
		}
		puts("");
	}
	
}

// ---------------------- testes! ----------------------

int main(){
	Stack *stack1 = malloc(sizeof(Stack));
	if(stack1 == NULL) {
		printf("Erro de alocação da Pilha\n");
		exit(0);
	} else {
		initStack(stack1);
		printStack(stack1);

		printf("tentando empilhar 1, 2 , 3\n");
		pushIntoStack(1, stack1);
		pushIntoStack(2, stack1);
		pushIntoStack(3, stack1);
		puts("");
		printf("resultado:\n");
		printStack(stack1);
		puts("");
		printf("agora tentando desempilhar!\n");
		popOutStack(stack1);
		printf("agora tentando desempilhar!\n");
		popOutStack(stack1);
		puts("");
		printf("resultado:\n");
		printStack(stack1);
	}


	return 0;
}