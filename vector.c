#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

//VectorRead function
//Reads vector from stdin
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
{
  return V->item[index];
}

//Adds the vector to var
void vectorAdd(Vector *V, int var, int index)
{
	V->item[index] = var;
}

//Prints the vector value, remove this after
void vectorPrint(Vector *V)
{
  int i;
	for (i = 0; i < V->size; i++)
		printf("[%d] Vector Val: %d\n",i, V->item[i]);
}
