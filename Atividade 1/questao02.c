/*
Elabore um programa que declare 4 variáveis do tipo inteiro e 4 do tipo ponteiro para inteiro, e faça com que as variáveis ponteiro apontem para as variáveis. Coloque comandos que permitam modificar os valores das variáveis inteiras através das variáveis ponteiro. Faça a simulação passo-a-passo para visualizar o que está acontecendo em cada 
linha do programa. 
*/
#include <stdio.h>

void brabo(int* x,int y){
    *x = y;
}

void main(){
    int a = 0, b=0, c=0, d=0;
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;
    printf("\na = %d, b = %d c, = %d e d = %d\n\n", a, b, c, d);
    brabo(pa, 10);
    brabo(pb, 20);
    brabo(pc, 30);
    brabo(pd, 55);
    printf("a = %d, b = %d c = %d d = %d\n\n", a, b, c, d);
}