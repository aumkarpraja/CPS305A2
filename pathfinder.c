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

    return 0;
}
