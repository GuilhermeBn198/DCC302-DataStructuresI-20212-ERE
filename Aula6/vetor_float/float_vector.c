#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

FloatVector* create(int capacity){
	FloatVector *vec = (FloatVector*) malloc(sizeof(FloatVector)); //this (FloatVector*) is a casting of the output of the malloc function which by default goes by void, in this case we use the casting to convert the output to FloatVector pointer
	vec->capacity = capacity;
	vec->size = 0;
	vec->data = malloc(capacity * sizeof(float));
	return vec;
}

void destroy(FloatVector** vec_ref){
	FloatVector* vec = *vec_ref;
	free(vec->data);
	free(vec);
	*vec_ref = NULL;
}

int size(FloatVector* vector){
	return vector->size;
}

int capacity(FloatVector* vector){
	return vector->capacity;
}

float get(FloatVector* vector, int index){
	if(index < 0 || index >= vector->size){
		fprintf(stderr,"ERROR in get()\n");
		fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vector->size-1);
		exit(EXIT_FAILURE);
	}
	return vector->data[index];
}

void append(FloatVector* vector, float val){
	if (vector->size == vector->capacity){
		fprintf(stderr,"ERROR in append()\n");
		fprintf(stderr, "Vector is full\n");
		exit(EXIT_FAILURE);
	}
	vector->data[vector->size] = val;
	vector->size++;
}

void set(FloatVector* vector, int index, float val) {
	if (vector->size == vector->capacity){
		fprintf(stderr,"ERROR in set()\n");
		fprintf(stderr, "Vector is full\n");
		exit(EXIT_FAILURE);
	}
	if(index < 0 || index >= vector->size){
		fprintf(stderr,"ERROR in set()\n");
		fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vector->size-1);
		exit(EXIT_FAILURE);
	}
	append(vector, vector->data[index]);
	vector->data[index] = val;
}

void print(FloatVector* vector){
	int i;
	puts("---------------------------");
	printf("Size: %d\n", vector->size);
	printf("Capacity: %d\n", vector->capacity);
	puts("---------------------------");
	for (i = 0; i < vector->size; i++)
	{
		printf("| %f |", vector->data[i]);
		printf("| %d |", i);
	}
	puts("\n---------------------------");
}   
