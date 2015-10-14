#include <stdlib.h>
#include <stdio.h>
#include "vector.h"


int main(int argc, char *argv[])
{
 // read in file
 printf("filename: %s", argv[1]);

 FILE *file = fopen(argv[1], "r");
 scanf("%s",  file);


  return 0;
}
