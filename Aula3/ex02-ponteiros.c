#include <stdio.h>

void imprime(int *v) {
	int i;
	for (i = 0; i < 5; i++){
		printf("%d", *(v+i));
	}
	printf("\n");
}
int main(){
	
	int v[5] = {100, 000, 45, 22, 31};
	int *pv = &v[0];
	*pv = 200; //isso aqui vai alterar o primeiro indice do vetor v através do ponteiro que está modificando diretamente no endereço de memoria do vetor, que no caso é 100 e vai passar a ser 200
	imprime(v);
	return 0;
}
