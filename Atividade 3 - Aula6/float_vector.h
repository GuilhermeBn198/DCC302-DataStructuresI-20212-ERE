typedef struct{
  	int capacity; 
  	int size; 
  	float *data;
} FloatVector;

FloatVector* create(int capacity);
void set(FloatVector* vec, int index, float val);
float get(FloatVector* vec, int index);
int capacity(FloatVector* vec);
int size(FloatVector* vec);
void print(FloatVector* vec);
void append(FloatVector* vec, float val);
void remove_element(FloatVector* vec, int index);
void destroy(FloatVector** vec_ref);
FloatVector* copy(FloatVector* vec);