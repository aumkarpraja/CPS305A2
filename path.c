#include <stdio.h>
#include "path.h"

//pathRead function
void pathRead(Path *P) {
        printf("%d", V->size);
        //printf("%lud ", sizeof(V) / sizeof(V[0]));
        for (int i = 0; i < sizeof(P) / sizeof(P[0]); i++) {
                printf("%d ", P->item[i]);
        }
}
//pathInit function
void pathInit(Path *P) {
        P->size = size;
        P->item = malloc(sizeof(int) * P->size);
}

//pathAdd function
void pathAdd(Path *P, int var, int index) {
	P->item[index] = var;
}

//pathPrint function
void pathPrint(Vector *P) {
        for (int i = 0; i < P->size; i++) {
                printf("Vector Val: %d\n", P->item[i]);
        }

}
