#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

//VectorRead function
//Reads vector from stdin
<<<<<<< HEAD
void vectorRead(Vector *V)
=======
void vectorRead(Vector *V) {
    
    int i;
    
    // get size
    printf("Size of vector: ");
    scanf("%d", &V->size);
    
    // if negative
    if (V->size < 0){
        printf("Invalid number, try again.\n");
        vectorRead(V);
    }
    
    // init item in Vector
    V->item = (int*)malloc(sizeof(int) * V->size);
    
    // read into array
    for (i = 0; i < V->size; i++)
        scanf("%d", &V->item[i]);

   }

int vectorGet(Vector *V, int index)
>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
{
    int i;

<<<<<<< HEAD
    // get size
    printf("Size of vector: ");
    scanf("%d", &V->size);

    // if negative
    if (V->size < 0){
        printf("Invalid number, try again.\n");
        vectorRead(V); // else read in
    }

    // init item in Vector
    V->item = malloc(sizeof(int) * V->size);

    // read into array
    for (i = 0; i < V->size; i++)
        scanf("%d", &V->item[i]);
   }

=======
>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
//Adds the vector to var
void vectorAdd(Vector *V, int var, int index)
{
	V->item[index] = var;
}
<<<<<<< HEAD
=======

//Prints the vector value, remove this after
void vectorPrint(Vector *V)
{
  int i;
	for (i = 0; i < V->size; i++)
		printf("[%d] Vector Val: %d\n",i, V->item[i]);
}
>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
