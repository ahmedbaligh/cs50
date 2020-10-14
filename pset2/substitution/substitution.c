#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Prototypes
string check_arguments_validity(int count, string arguments[]);

int main(int argc, string argv[])
{
    // Check command line arguments don't meet the conditions
    string key = check_arguments_validity(argc, argv);

    // Exit, if command line arguments don't meet the conditions
    if (atoi(key) == -1)
    {
        return 1;
    }

    // Covert each letter in the key to lower case
    for (int i = 0; i < 26; i++)
    {
        key[i] = tolower(key[i]);
    }

    // Prompt for text
    string text = get_string("plaintext: ");

    char letter;
    int index;
    char cipher;
    // Print encrypted text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        letter = text[i];

        // Only encrypt text, if it's alphabetic
        if (isalpha(letter))
        {
            // Get each letter's cipher from its equivalent index
            // in the key, and appropriately transform its case
            if (islower(letter))
            {
                index = (int) letter - 97;
                cipher = tolower(key[index]);
            }
            else
            {
                index = (int) letter - 65;
                cipher = toupper(key[index]);
            }
        }
        // Don't encrypt non-alphabetic letters
        else
        {
            cipher = letter;
        }

        printf("%c", cipher);
    }

    // Add new line at the end
    printf("\n");
}


string check_arguments_validity(int count, string arguments[])
{
    // Alert and exit, if no arguments were given
    if (count < 2)
    {
        printf("missing command-line argument\n");
        return "-1";
    }
    // Alert and exit, if more than one argument were given
    else if (count > 2)
    {
        printf("too many command-line arguments\n");
        return "-1";
    }

    string cipher = arguments[1];
    int lettersCount = strlen(cipher);
    // Advise and exit, if the cipher has less than 26 letters
    if (lettersCount != 26)
    {
        printf("enter exactly 26 alphabetic letters\n");
        return "-1";
    }

    // Initialize an array to store each letter in the cipher
    int alphabets[26];
    for (int i = 0; i < 26; i++)
    {
        alphabets[i] = 0;
    }

    // Iterate over each cipher in the key
    int index;
    for (int i = 0; i < lettersCount; i++)
    {
        // Advise and exit, if any letter in the cipher is not alphabetic
        if (!isalpha(cipher[i]))
        {
            printf("all letters must be alphabetic\n");
            return "-1";
        }

        // Index each letter in the cipher to the pre-intialized array
        // that each unique case-insensitive letter has a unique index
        index = (int) tolower(cipher[i]) - 97;

        // If an index is empty, assign the appropriate letter to it
        if (alphabets[index] == 0)
        {
            alphabets[index] = cipher[i];
        }
        // Advise and exit, if a letter in the cipher is repeated
        else
        {
            printf("use each letter only once\n");
            return "-1";
        }
    }

    return cipher;
}
