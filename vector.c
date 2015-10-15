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

    // read in file while it hasn't reached the end
    while ((c=fgetc(file))!=EOF)
    {
        // new lines should seperate the size and items in the array
        if (c == '\n')
        {
            printf("THERE WAS A NEW LINE\n");
        }
        
        // ignore spaces
        else if (c==' ')
        {
            printf("space");
        }
        else
        printf("%c", c);
        
    }
    free(file); // free space used after file is done being read from
    
    


  return 0;
}