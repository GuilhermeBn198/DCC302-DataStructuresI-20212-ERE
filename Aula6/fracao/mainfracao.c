#include <stdio.h>
#include "./fracao.h"

int main() {
	fracao f1 = cria_fracao(4,6);
	fracao f2 = cria_fracao(3,5);
	fracao fsoma = soma_fracao(f1,f2);
	printf("%d/%d\n",get_numerador(fsoma), get_denominador(fsoma));

	return 0;
	}

//and this is how we correctly use the encapsulated TAD functions that we made in the previous archives in other programs