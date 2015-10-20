//path.c

typedef struct {
	int size;
	int *item;
    int curLen;
} Path;

void pathInit(Path *P, int size);

void pathRead(Path *P);

void pathAdd(Path *P, int var, int index);

void pathPrint(Path *P);

int pathCheck(Path *P, int pos);

void pathRemove(Path *P);
