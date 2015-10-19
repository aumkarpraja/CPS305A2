#include <stdio.h>
#include <stdlib.h>

#include "path.h"

void PathInit(Path *P, int size)
{
	P->size = size;
	P->item = (int*)malloc(size*sizeof(int));
	P->curLen = 0;
	printf("Path initialize\n");
}

int PathAddEntry(Path *P, int entry )
{
	if(P->curLen == P->size)
	{
		printf("Path is full\n");
	}
	else 
	{
		*(P->item + P->curLen) = entry;

		P->curLen += 1;
	}
}

int PathRemoveEntry(Path *P )
{
	if(P->curLen == 0)
	{
		printf("Path is empty\n");	
	}
	else
	{
		P->curLen -= 1;
	}
}

void PathPrint(Path *P)
{
	//printf("Path : Print Path (len : %d): \n", P->curLen);	
	int i ;

	for(i = 0 ; i < P->curLen ; i++)
	{
		printf("%d ",*(P->item+i));	
	}
	printf("\n");
}

int PathCheckPos(int position, Path *P)
{
	int i ;
	
	for(i = 0 ; i < P->curLen ; i++)
	{
		if( *(P->item + i) == position )
		{
			return 1;
		}
	}
	return -1;
}
