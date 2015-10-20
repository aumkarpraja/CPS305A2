// Define a vector type
typedef struct {
  int size;      // size of vector array
  int *item;     // array of integers storing
} Vector;

void vectorRead(Vector *V);

void vectorAdd(Vector *V, int var, int index);
