#include <stdlib.h>
#include <stdio.h>
#include "vector.h"


int main(int argc, char **argv)
{
 // read in file
 printf("filename: %s\n", argv[1]);

    FILE *file;
    file = fopen(argv[1], "r");
    char c;
 while ((c=fgetc(file))!=EOF)
 {
     printf("%c", c);
 }


  return 0;
}