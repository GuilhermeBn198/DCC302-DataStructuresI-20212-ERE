#include <stdio.h>
#define LINHAS 5
#define COLUNAS 2

int main(){
	int i,j;
	int mat[LINHAS][COLUNAS] = {		
		{10,20},
		{30,40},
		{50,60},
		{70,80},
		{90,100} };
	int *mat = mat;
	int *ponteiro = &mat [3][1];


	for (i = 0; i < LINHAS; i++){
		for (j = 0; i < COLUNAS; i++){
		printf("%d", *(*(mat + i) + j));
		}
		printf("\n");
	}
	return 0;
}