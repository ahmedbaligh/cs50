#include <cs50.h>
#include <stdio.h>

// Strict compiler function declaration
float get_positive_float(void);

int main(void)
{
    // Get the amount owed in positive numbers only
    float owed = get_positive_float();
    
    // Keep track of the number of used coins
    int counter = 0;
    
    // Find the type of used coins
    while (owed > 0)
    {
        // Subtract the value of the largest coin type until 'owed' is zero
        if (owed >= 0.25)
        {
            owed -= 0.25;
        }
        else if (owed >= 0.1)
        {
            owed -= 0.1;
        }
        else if (owed >= 0.05)
        {
            owed -= 0.05;
        }
        else
        {
            owed -= 0.01;
        }
        
        // One coin was used
        counter++;
    }
    
    printf("%i\n", counter);
}

float get_positive_float(void)
{
    float money;
    
    // Reprompt the user until they enter a positive decimal
    do
    {
        money = get_float("Change owed: ");
    }
    while (money < 0);
    
    return money;
}