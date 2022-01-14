#include "float_vector.h"
#include <stdio.h>

int main(){
	FloatVector *vector = create(5);
	append(vector, 46.4);
	append(vector, 224.7);
	append(vector, 85.9);
	print(vector);	
	//printf("Valor do indice: %f",get(vector, 2));
	set(vector, 1, 77.9);
	set(vector, 2, 17.9);
	print(vector);
}