#include<stdio.h>
#include<math.h>

int power(int base, int exp){
	if (exp == 0) return 1;
	else if (exp == 1)  return base;
	else if (exp>1) base = base*power(base, exp-1);
}

int main(){
	int x = 2;
	int y = 3;
	printf ("\n %d \n", power(x, y));
}