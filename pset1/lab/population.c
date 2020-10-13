#include <cs50.h>
#include <stdio.h>

// Prototypes
int get_size(string when, int limit);

int main(void)
{
    // Prompt for start size
    int startSize = get_size("Start", 9);

    // Prompt for end size
    int endSize = get_size("End", startSize);

    // Calculate number of years until we reach threshold
    int annualGrowth;
    int years = 0;
    while (startSize < endSize)
    {
        // Calculate the growth for each year
        annualGrowth = (startSize / 3) - (startSize / 4);
        // Update the starting size for each year
        startSize += annualGrowth;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}

int get_size(string when, int limit)
{
    int size;
    do
    {
        // Prompt for the size based on time and allowed limit
        size = get_int("%s size: ", when);
    }
    while (size < limit);
    
    return size;
}