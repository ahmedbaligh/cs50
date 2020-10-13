#include <cs50.h>
#include <stdio.h>

// Strict compiler function declaration
int get_pyramid_height(void);

int main(void)
{
   // Get height of the pyramid
    int height = get_pyramid_height();
    
    // Make the pyramid
    for (int row = 1; row <= height; row++)
    {
        // Reverse starting direction of the pyramid
        for (int space = height - row; space > 0; space--)
        {
            printf(" ");
        }
    
        // Make each column of the pyramid
        for (int col = 1; col <= row; col++)
        {
            printf("#");
        }
        
        // Start a new row
        printf("\n");
    }
}


int get_pyramid_height(void)
{
    int h;
    // Make sure user-entered height is between 1 and 8
    do 
    {
        h = get_int("Enter the height of the pyramid: ");
    }
    while ((h < 1) || (h > 8));
    
    return h;
}