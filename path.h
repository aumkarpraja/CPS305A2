//path.c

typedef struct {
	int size;
	int *item;
<<<<<<< HEAD
    int curLen;
=======
    int current_len;
>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
} Path;

void pathInit(Path *P, int size);

void pathRead(Path *P);

void pathAdd(Path *P, int var, int index);

void pathPrint(Path *P);

int pathCheck(Path *P, int pos);

<<<<<<< HEAD
void pathRemove(Path *P);
=======
void pathRemove(Path *P);
>>>>>>> 729e35201936ac4d357b68d2b0717cb40405c595
