#include <stdio.h>
#include <stdlib.h>
#include "path.h"

//pathRead function
void pathRead(Path *P) {
        printf("%d", P->size);
        //printf("%lud ", sizeof(V) / sizeof(V[0]));
        int i;
        for (i = 0; i < sizeof(P) / sizeof(P[0]); i++) {
                printf("%d ", P->items[i]);
        }
}
//pathInit function
void pathInit(Path *P, int size) {
        P->size = size;
        P->items = malloc(sizeof(int) * P->size);
}

//pathAdd function
void pathAdd(Path *P, int var, int index) {
	P->items[index] = var;
}

//pathPrint function
void pathPrint(Path *P) {
        int i;
        for (i = 0; i < P->size; i++) {
                printf("Vector Val: %d\n", P->items[i]);
        }

}
