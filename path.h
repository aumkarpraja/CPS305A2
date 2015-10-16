//path.c

typedef struct {
	int size;
	int *items;
} Path;

void pathInit(Path *P, int size);

void pathRead(Path *P);

void pathAdd(Path *P, int var, int index);

void pathPrint(Path *P);
