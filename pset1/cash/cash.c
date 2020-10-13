#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Strict compiler function declaration
float get_positive_rounded(void);

int main(void)
{
    // Get the amount owed in positive rounded integers
    int owed = get_positive_rounded();
    
    // Keep track of the number of used coins
    int counter = 0;
    
    // Find the type of used coins
    while (owed > 0)
    {
        
        // Subtract the value of the largest coin type until 'owed' is zero
        if (owed >= 25)
        {
            owed -= 25;
        }
        else if (owed >= 10)
        {
            owed -= 10;
        }
        else if (owed >= 5)
        {
            owed -= 5;
        }
        else
        {
            owed -= 1;
        }
        
        // One coin was used
        counter++;
    }
    
    printf("Coins: %i\n", counter);
}

float get_positive_rounded(void)
{
    float money;
    
    // Reprompt the user until they enter a positive decimal
    do
    {
        money = get_float("Change owed: ");
    }
    while (money < 0);
    
    return round(money * 100);
}
