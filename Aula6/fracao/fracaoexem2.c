#include <stdio.h>
#define numerador 0
#define denominador 1

typedef int fracao[2];

int main(){
	fracao f;
	printf ("Digite o numerador: ");
	scanf ("$d", &f[numerador]);
	printf ("\nDigite o denominador: ");
	scanf ("%d", &f[denominador]);
	return 0;
	}
