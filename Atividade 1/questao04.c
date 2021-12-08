/* Elabore um programa que armazene valores aleatórios em um vetor de inteiros
de 10 posições e depois, em outro vetor de ponteiros de inteiros de tamanho 10,
coloque os endereços dos valores do vetor de inteiros de forma ordenada crescente,
ficando a primeira posição do vetor de ponteiros com o endereço do menor valor até
a última posição que conterá o endereço do maior valor. 
*/
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    void main(){
        srand(time(NULL));
        int i, j, a; 
        int n =10;
        int number[10];
        int *pnumber[10];

        for (int i = 0; i <= 10; i++){ //define valores dos inteiros
            number[i] = rand() % 200;
            pnumber[i] = &number[i];
            } 
 
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j){
                if (*pnumber[i] > number[j]) 
                {
                    a =  *pnumber[i];
                    *pnumber[i] = number[j];
                    number[j] = a;
                }
            }
        }
 
        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", *pnumber[i]);
 
    }
