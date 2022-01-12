typedef struct {
	int capacity; //max elements size
	int size; //actual quantity of elements
	float *data;
} FloatVector;

FloatVector* create(int capacity);
void destroy(FloatVector** vec_ref);
int size(FloatVector* vector);
int capacity(FloatVector* vector);
float get(FloatVector* vector, int index);
void append(FloatVector* vector, float val);
void set(FloatVector* vector, int index, float val);
void print(FloatVector* vector);
