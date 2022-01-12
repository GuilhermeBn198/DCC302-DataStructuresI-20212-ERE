#include <stdio.h>
#include "./fracao.h"

fracao cria_fracao(int n, int d) {
	fracao f;
	f.numerador = n;
	f.denominador = d;
	return f;
}

int get_numerador(fracao f) {
	return f.numerador;
}

int get_denominador(fracao f) {
	return f.denominador;
}

int mdc(int n1, int n2) {
	while (n2 != 0) {
		int resto = n1 % n2;
		n1 = n2;
		n2 = resto;
	}
	return n1;
}

int mmc(int n1, int n2){
	return (n1*n2)/mdc(n1,n2);
}

fracao soma_fracao(fracao f1, fracao f2){
	int n1 = get_numerador(f1);
	int d1 = get_denominador(f1);
	int n2 = get_numerador(f2);
	int d2 = get_denominador(f2); 

	int denF = mmc(d1, d2);
	int numF = ((denF/d1)*n1) + ((denF/d2)*n2);
	
	return cria_fracao(numF, denF);
	}

//this is the implementation arquive that we need for our TAD program to work correctly