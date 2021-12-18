#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  	FloatVector *vector = create(10);
  	append(vector, 4.6);
  	append(vector, 22.4);
  	append(vector, 8.5);
  	print(vector);
  	remove_element(vector, 1);
  	print(vector);

 	FloatVector *CloneArray = copy(vector);
  	print(CloneArray);
  	return 0;
}