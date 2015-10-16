#include <stdio.h>
#include "vector.h"
/*
Possible method:
Interate randomly with math.rand to and if statements to attempt to get
to 11. Try 'x' amount of times till it can be determined that there are
no possible combinations for amount of work done.
*/

/*
Algorith
Beause starting is 0, make algorithm to print out the shortest path to N-1 of the array, then using the shortest path, take the 2nd position in the path, and find all possibly paths using addition and subtraction, print if exists then do the same with 3rd position etc...
*/



int main() {
	int size;
	//int var;
	Vector vector;

	printf("Input size of vector.\n");
	scanf("%d", &size);
	
	vectorInit(&vector, size);
	for (int i = 0; i < size; i++) {
		int var;
		printf("Add a number to the vector.\n");
		scanf("%d", &var);
		vectorAdd(&vector, var, i);
	}

	vectorPrint(&vector);
	//vector->size = 1;
//	vector->item = malloc(sizeof(int) * vector->size);
//	vector->item = 1;
//	VectorRead(vector);	
}
