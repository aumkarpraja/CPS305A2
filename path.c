#include <stdio.h>
#include <stdlib.h>
#include "path.h"

//pathRead function
void pathRead(Path *P) {
        printf("%d", P->size);
        //printf("%lud ", sizeof(V) / sizeof(V[0]));
        int i;
        for (i = 0; i < sizeof(P) / sizeof(P[0]); i++) {
                printf("%d ", P->item[i]);
        }
}
//pathInit function
void pathInit(Path *P, int size) {
        P->size = size;
        P->item = (int*)malloc(sizeof(int) * P->size);
        P->current_len = 0;
}

//pathAdd function
void pathAdd(Path *P, int var, int index) {
    if (P->current_len == P->size)
        printf("full\n");
    else
    {
        *(P->item + P->current_len) = var;
        P->current_len += 1;
    }
}

int pathCheck(Path *P, int pos)
{
    int i = 0;
    for(i = 0; i < P->current_len; i++)
        if((P->item[i]) == pos)
            return 1;
    // else
    return -1;
}

//pathPrint function
void pathPrint(Path *P) {
        int i;
        for (i = 0; i < P->current_len; i++) {
                printf("%d ", P->item[i]);
        }
    printf("\n");

}

void pathRemove(Path *P)
{
    if (P->current_len == 0)
        printf("empty\n");
    else
        P->current_len -=1;
}
