//3 - Faça um programa que leia 10 números inteiros e armazene em uma matriz.
//Depois, utilize a aritmética de ponteiros para imprimir todos os elementos da matriz.

#include <stdio.h>
void main(){

	int matriz[5][2];  
	int *ponteiro;


	for (int i = 0; i < 5; i++){ //recebe
		for (int j = 0; j < 2; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	printf("\n agr imprimindo\n");

	for (int i = 0; i < 5; i++){ //imprime
		printf("( ");
		for (int j = 0; j < 2; j++){
			ponteiro = &matriz[i][j];
			printf("%d ", *ponteiro);
		}
		printf(")\n");
	}
	printf("\n");
}