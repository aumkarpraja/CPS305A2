//
//  pathfinderother.c
//  CPS305A2
//
//  Created by Aumkar Prajapati on 2015-10-19.
//  Copyright © 2015 Aumkar Prajapati. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "path.h"

int solReceived;

int AllPathsRec(int position, Vector *V, Path *Solution)
{
    int nextPos;
    int x;
    int posCheck;
    
    posCheck = PathCheckPos(position, Solution);
    
    if(position < 0 || position > V->size || posCheck > 0)
    { //pos <0, pos > vector size, pos already checked
        return -1;
    }
    else
    {
        PathAddEntry(Solution, position);
        if(position == V->size - 1)
        {
            PathPrint(Solution);
            PathRemoveEntry(Solution);
            
            solReceived = 1;         //to check whether at least one solution was recieved
            return 0;
        }
        else
        {
            x = *(V->item + position);
            nextPos = position + x ;
            AllPathsRec(nextPos,V,Solution);
            nextPos = position - x ;
            AllPathsRec(nextPos,V,Solution);
        }
        PathRemoveEntry(Solution);
    }
}



int main()
{
    int size;
    
    Vector *v = (Vector *) malloc(sizeof(Vector));
    VectorRead(v);
    size = v->size;
    
    Path *p = (Path *) malloc(sizeof(Path));
    PathInit(p, size);
    
    solReceived = 0;
    AllPathsRec(0,v,p);
    if(solReceived == 0){
        printf("No solution\n");
    }
    getchar();
    return 0;
}