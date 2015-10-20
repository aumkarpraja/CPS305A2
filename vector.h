// Define a vector type
typedef struct {
  int size;      // size of vector array
  int *item;     // array of integers storing
} Vector;

void vectorRead(Vector *V);

<<<<<<< HEAD
=======
int vectorGet(Vector *V, int index);

>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
void vectorAdd(Vector *V, int var, int index);
