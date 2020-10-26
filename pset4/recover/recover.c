#include <stdio.h>
#include <stdlib.h>

 
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open raw file and check for validity
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Close files
    fclose(file);
}