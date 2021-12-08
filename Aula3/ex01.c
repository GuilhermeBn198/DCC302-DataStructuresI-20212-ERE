#include <stdio.h>

void troca(int *x, int *y) {
	// printf("a: %d b: %d", x, y);
	int temp  = *x;
	*x = *y;
	*y = temp;
	// printf("a: %d b: %d", x, y);
}

int main(){

	int x = 10;
	int y = 20;
	troca(&x, &y);

	printf("%d %d \n", x, y);
	return 0;
}