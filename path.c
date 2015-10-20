#include <stdio.h>
#include <stdlib.h>
#include "path.h"

// reads in the path
void pathRead(Path *P)
 {
        printf("%d", P->size);
        int i;
        for (i = 0; i < sizeof(P) / sizeof(P[0]); i++)
                printf("%d ", P->item[i]);
}
// initializes path, allocates memory for the path
void pathInit(Path *P, int size)
{
        P->size = size;
        P->item = malloc(sizeof(int) * P->size);
        P->curLen = 0;
}

//pathAdd function, reports when full, otherwise adds to the
// current curLength and to the item array
void pathAdd(Path *P, int var, int index)
{
    if (P->curLen == P->size)
        printf("full\n");
    else
    {
        P->item[P->curLen] = var;
        P->curLen += 1;
    }
}

// checks the path
int pathCheck(Path *P, int pos)
{
    int i = 0;
    // loop thorugh P to the current size
    for(i = 0; i < P->curLen; i++)
        if((P->item[i]) == pos) // If the item is within path
            return 1;
    // else
    return -1;
}

// outputs path in a neat format
void pathPrint(Path *P)
{
        int i;
        for (i = 0; i < P->curLen; i++)
                printf("%d ", P->item[i]);
    printf("\n");
}

// cleans up the path (for more to be made if more solutions exist)
void pathRemove(Path *P)
{
    // if it's empty, then do nothing
    if (P->curLen == 0)
        printf("empty\n");
    else
        P->curLen -=1;
}
