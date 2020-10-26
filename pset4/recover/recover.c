#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
 
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

    // Read 512-byte chunks of data from the raw file until it's the end of the file
    BYTE buffer[512];
    bool isJPEG;
    int count = 0;
    while (fread(buffer, 512, 1, file))
    {
        // Detect whether this chunk is a jpeg through jpeg header values
        isJPEG = (buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0)  == 0xe0);
        if (isJPEG)
        {
            count++;
        }
    }
    printf("Number: %i\n", count);

    // Close raw file
    fclose(file);
}