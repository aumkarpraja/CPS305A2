#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

//VectorRead function
//Reads vector from stdin
void vectorRead(Vector *V)
{
    int i;

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

//Adds the vector to var
void vectorAdd(Vector *V, int var, int index)
{
	V->item[index] = var;
}
