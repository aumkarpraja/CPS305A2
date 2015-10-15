typedef struct {
    int *item;
    int size;
    int cur_length;
}Path;

void PathInit(Path *P, int size); //using DMA
int PathAddEntry(Path *P, int entry );
int PathRemoveEntry(Path *P );
void PathPrint(Path P);

//add all this shit
