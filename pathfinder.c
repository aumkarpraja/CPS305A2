	#include <stdio.h>
	#include <stdlib.h>
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
	int size;
	Vector userQuestion(Vector vector)
	{
		int i, var;

		printf("Input size of vector: ");
		scanf("%d", &size);

		// if user gives a size less than 0, don't let them continue
		if (size < 0)
		{
			printf("Invalid size, try again!\n");
			userQuestion(vector);
		}

		// initialize the vector based on user size
		vectorInit(&vector, size);

	// loop through the questions needed to fill the array
		for (i = 0; i < size-1; i++) {
			printf("Add a number to the vector.\n");
			scanf("%d", &var);
					if (var < 0)
							printf("Invalid number, try again.\n"); // user can't enter negatives
					else
							vectorAdd(&vector, var, i); // Add whatever the user wants
		}
			vectorAdd(&vector, 0, size-1); // Add the final 0
			vectorPrint(&vector); // DEBUG

			return vector;
	}

	int AllPathsRec(int position, Vector *V)
	{
		// BASE CASE: Only one entry in the array, it leads immediately to the point
		// required. If there is no entries then there is no path.
		if (size == 1)
		{
			printf("%d\n", V->item[0]);
			printf("Path was found!\n");
			return 1;
		}

		if (size == 0)
		{
			printf("No path was found.\n");
			return 0;
		}
		// RECURSIVE CASE, n-1 each time if a solution isn't found, no solution if it
		// goes all the way to the end.
		int lastPosition = 0;
		while (1)
		{
			if (position < size - 1){
			position = position + V->item[position];
			position = lastPosition;
			}
			// overflow case, NEEDS TO BE FIXED
			if (position > size - 1)
			{
				position = position - lastPosition;
				position = position - V->item[position];
			}///////////////
			printf("next index: %d\n", position); // DEBUG
			if (position == size-1)
			{
				printf("Path was found!\n");
				return 1;
			}

		}
	}

	int main()
	{
		// init vector, make sure it carries over the same vector into main
		Vector vector = userQuestion(vector);

		// ask the user the required questions
		printf("Vector at 0: %d\n",vectorGet(&vector, 0));

		// Exit result 0 = failed to find paths, exit result 1 = found paths
		printf("EXIT RESULT: %d", AllPathsRec(0, &vector));
		return 0;
	}
