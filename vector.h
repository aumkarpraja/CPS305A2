// Define a vector type
typedef struct {
  int size;      // size of vector array
  int *item;     // array of integers storing
} Vector;

void VectorRead(Vector *V);

void vectorInit(Vector *V, int size);

void vectorAdd(Vector *V, int var, int index);

void vectorPrint(Vector *V);
