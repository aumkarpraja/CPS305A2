<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "path.h"

int check;

// the recursive method that does the operation
int allPathsRec(int position, Vector *V, Path *Solution)
{
    // contains variable for temp storage, a next var to store other values,
    // a check flag to make sure there was a solution and an index var to help
    // organize the array of path values
    int var, next, indexVal;
    indexVal = 0; // for the path vals

    // check for sol
    check = pathCheck(Solution, position);

    // If the index size is i+x, i-x beyond size then not possible
    if(check > 0 || position < 0 || position > V->size)
        return -1;

    else
    {
        pathAdd(Solution, position, indexVal);
        indexVal++;

        // solution has been reached, print the path
        if (position == V->size - 1)
        {
            printf("\n");
            pathPrint(Solution); // output
            pathRemove(Solution); // clear buffer
            check = 1; // there is a solution!
            return 1; // to provide an end
        }
        else // keep doing ops
        {
            // contains the item in temp space
            var = V->item[position];
            // i+x
            next = position + var;
            // recurse
            allPathsRec(next, V, Solution);
            // i-x
            next = position - var;
            // recurse in - cases
            allPathsRec(next, V, Solution);
        }
        // clear path so that another path can be printed
        pathRemove(Solution);
    }
    return 0;
}

int main()
{
		printf("------------------------------\n"); // for neatness

		int size;
    // Init path and vector
    Vector *V = malloc(sizeof(Vector));
    vectorRead(V); // initialize and read in
		Path *P = malloc(sizeof(Path));
	  size = V->size; // alloc size
		pathInit(P, size);

		printf("------------------------------\n"); // for neatness
		// run the recursive algorithm
		allPathsRec(0, V, P);

=======
	#include <stdio.h>
	#include <stdlib.h>
    #include <stdio.h>
	#include "vector.h"
    #include "path.h"

	/*
	Algorithm
	Beause starting is 0, make algorithm to print out the shortest path to N-1 of the array, then using the shortest path, take the 2nd position in the path, and find all possibly paths using addition and subtraction, print if exists then do the same with 3rd position etc...
	*/

int check;

int allPathsRec(int position, Vector *V, Path *Solution)
{
    // contains variable for temp storage, a next var to store other values,
    // a check flag to make sure there was a solution and an index var to help
    // organize the array of path values
    int var, next, indexVal;
    indexVal = 0;
    
    check = pathCheck(Solution, position);
    
    // If the index size is i+x, i-x beyond size then not possible
    if(check > 0 || position < 0 || position > V->size)
        return -1;
    
    else
    {
        pathAdd(Solution, position, indexVal);
        indexVal++;
        
        // solution has been reached, print the path
        if (position == V->size - 1)
        {
            printf("\n");
            pathPrint(Solution);
            pathRemove(Solution);
            check = 1; // there is a solution!
            return 1;
        }
        else
        {
            // contains the item in temp space
            var = V->item[position];
            // i+x
            next = position + var;
            // recurse
            allPathsRec(next, V, Solution);
            // i-x
            next = position - var;
            // recursive
            allPathsRec(next, V, Solution);
        }
        pathRemove(Solution);
    }
    return check;
}

int main()
{
    int size, flag;
    
    Vector *V = (Vector*)malloc(sizeof(Vector));
    vectorRead(V);
    
    size = V->size;
    
    Path *P = (Path*) malloc(sizeof(Path));
    pathInit(P, size);
   
    check = 0;

    flag = allPathsRec(0, V, P);
    printf("FLAG: %d\n", flag);
    
    if (flag == -1)
        printf("No solution!\n");
    else
        printf("Solution found!\n");
    
>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
    return 0;
}
