#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#define LENGTH 1000

void VectorRead(Vector *v)
{
	int size;
	int i ; 
	
	printf("Enter the vector size : ");
	scanf("%d", &size);

	v->size = size;
	v->item = (int*)malloc(size*sizeof(int));

	printf("Enter the vector (no: %d)\n",size);
	for(i = 0 ; i < size ; i++)
	{
		scanf("%d", v->item + i);
	}
	
}
