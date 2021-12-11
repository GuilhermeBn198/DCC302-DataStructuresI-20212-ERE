#include <stdio.h>
#include <math.h>

int soma(int n1, int n2) {
	int cont = abs(n2-n1);
	int som = n1-n2;
	if (cont == 0) return som;
	else if (cont == 1) return (som+n2);
	else if (cont >1) som = som + soma(n1+1,n2);
	return som;
}

int main(){
	printf("%d", soma(5,3)); 
	return 0;
}