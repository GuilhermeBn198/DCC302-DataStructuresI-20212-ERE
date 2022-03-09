
/*
	Autor: Guilherme Bernardo 2019004044
	Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:

	Primeiro os Pares
	Depois os Ímpares
	
	Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.

	Entrada
	A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) Este é o número de linhas de entrada que vem logo a seguir. As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.

	Saída
	Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. Cada número deve ser impresso em uma linha, conforme exemplo abaixo.	
*/
#include <stdio.h>
#include <stdlib.h>

int ascend(void const *a, void const *b ){
    return (*(int*)a - *(int*)b );
}

int descend(void const *a, void const *b ){
    return (*(int*)b - *(int*)a );
}

int main(){
    int n, i, num, par, impar;
    
    scanf("%d", &n);
    par = 0;
    impar = 0;
    int numpar[n];
    int numimpar[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        if(num%2 == 0){
            numpar[par] = num;
            par++;
        }else{
            numimpar[impar] = num;
            impar++;
        }
    }
    qsort(numpar, par, sizeof(int), ascend);
    qsort(numimpar, impar, sizeof(int), descend); 
    puts("");
    puts("ordenando...");
    puts("");
    for(i = 0; i < par; i++){
        printf("%d\n",numpar[i]);
    }
    for(i = 0; i < impar; i++){
        printf("%d\n",numimpar[i]);
    }
    
    return 0;
}