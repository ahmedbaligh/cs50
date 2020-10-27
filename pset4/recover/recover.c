#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define a byte
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
    int imgNum = 0;
    char *filename;
    FILE *img = NULL;
    while (fread(buffer, 512, 1, file))
    {
        // Detect whether this chunk is a jpeg through jpeg header values
        isJPEG = (buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0)  == 0xe0);

        // If a new jpeg header is detected and a jpeg image is already
        // open, then close that file and increase the jpeg count
        if (isJPEG && img != NULL)
        {
            fclose(img);
            imgNum++;
        }

        if (isJPEG)
        {
            // Format the name of each jpeg image to ###.jpg
            filename = malloc(3);
            sprintf(filename, "%03i.jpg", imgNum);

            // Create a jpeg image of correct name and format
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 3;
            }

            // Release memory resources
            free(filename);
        }

        // If there is an open jpeg file, write 512-byte chunk of data into it
        if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // Close last jpeg file
    fclose(img);

    // Close raw file
    fclose(file);
}