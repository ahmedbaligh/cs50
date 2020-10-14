#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Prototypes
int check_arguments_validity(int count, string arguments[]);

int main(int argc, string argv[])
{
    // Check command line arguments don't meet the conditions
    int k = check_arguments_validity(argc, argv);
    
    // Exit, if command line arguments don't meet the conditions
    if (k == -1)
    {
        return 1;
    }

    // If key is very large, reduce it to an equivalent value
    while (k > 26)
    {
        k -= 26;
    }
    
    // Prompt for text
    string text = get_string("plaintext: ");
    
    char letter;
    char cipher;
    // Print encrypted text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        letter = text[i];
        
        // Only encrypt text, if it's alphabetical
        if (isalpha(letter))
        {
            // Encrypt alphabetical letters
            cipher = (int) letter + k;
            
            // Let letters overflow after encryption
            if (!isalpha(cipher))
            {
                cipher = (int) cipher - 26;
            }
        }
        // Don't encrypt non-alphabetical letters
        else
        {
            cipher = letter;
        }
        
        printf("%c", cipher);
    }
    
    // Add new line at the end
    printf("\n");
}


int check_arguments_validity(int count, string arguments[])
{
    // Alert and exit, if no arguments were given
    if (count < 2)
    {
        printf("missing command-line argument\n");
        return -1;
    }
    // Alert and exit, if more than one argument were given
    else if (count > 2)
    {
        printf("too many command-line arguments\n");
        return -1;
    }
    
    // Advise and exit, if the argument was not decimal
    for (int i = 0, n = strlen(arguments[1]); i < n; i++)
    {
        if (!isdigit(arguments[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return -1;
        }
    }
    
    // Convert the argument to an actual integer
    return atoi(arguments[1]);
}
