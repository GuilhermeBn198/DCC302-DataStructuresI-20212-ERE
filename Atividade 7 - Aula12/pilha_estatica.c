/*
	--implementação de uma pilha estatica
	--autor: guilherme Bernardo
	--data:08/02/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------- definição da estrutura!----------------------
typedef struct _stack {
	long capacity;
	long top;
	int * data;
} Stack;

// ---------------------- construtores e destrutores
Stack *Stack_create(size_t capacity){
	Stack *S = (Stack*) malloc(sizeof(Stack));
	S->capacity = capacity;
	S->top = -1;
	S->data = malloc(capacity * sizeof(int));
	return S;
}

void Stack_destroy(Stack **S_ref){
	Stack *S = *S_ref;
	free(S->data);
	free(S);
	*S_ref = NULL;
}

//---------------------- funções! -----------------------
bool Stack_is_empty(Stack *S){
	return S->top == -1;
}

bool Stack_is_full(Stack *S){
	return S->top == (S->capacity - 1);
}

void Stack_push(Stack *S, int val){
	if (Stack_is_full(S)){
		printf("Stack if full\n");
		exit(EXIT_FAILURE); //return
	} else {
		S->top++;
		S->data[S->top] = val;
	}
}

int Stack_peek(Stack *S){
	if (Stack_is_empty(S)){
		printf("Stack if empty\n");
		exit(EXIT_FAILURE); //return
	} 
	return S->data[S->top];
}

int Stack_pop(Stack *S){
	if (Stack_is_empty(S)){
		printf("Stack if empty\n");
		exit(EXIT_FAILURE); //return
	} 
	int val = S->data[S->top];
	S->top--; 
	return val;
}

void Stack_print (Stack *S){
	printf("Capacity: %ld\n", S->capacity);
	printf("Top: %ld\n", S->top);
	printf("Size: %ld\n",S->top+1);

	for (long i = 0; i<= S->top; i++){
		printf("%d, ", S->data[i]);
	}
	puts("");
}


// ---------------------- testes! ----------------------

int main(){
	Stack *S = Stack_create(5);
	int top_val = 0;
	// Stack_print(S);
	// puts("\nPeeking");
	// top_val = Stack_peek(S);
	// printf("top_val = %d\n", top_val);

	Stack_print(S);
	puts("\nPushing: 0, 10, 20");
	Stack_push(S, 0);
	Stack_push(S, 10);
	Stack_push(S, 20);

	puts("\nPeeking");
	top_val = Stack_peek(S);
	printf("top_val = %d\n", top_val);

	puts("\nPopping");
	top_val = Stack_pop(S);
	printf("top_val = %d\n", top_val);

	puts("\nPushing: 30, 40, 50");
	Stack_push(S, 30);
	Stack_push(S, 40);
	Stack_push(S, 50);
	puts("");
	Stack_print(S);


	Stack_destroy(&S);
	return 0;
}