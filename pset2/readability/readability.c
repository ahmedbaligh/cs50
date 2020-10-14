#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes
int letters_count(string text);
int words_count(string text);
int sentences_count(string text);
void coleman_liau_index(float L, float S);

int main(void)
{
    // Prompt for text
    string text = get_string("Text: ");
    
    // Compute the number of letters, words, and sentences
    int letters = letters_count(text);
    float words = words_count(text);
    int sentences = sentences_count(text);
    
    // Calculate average number of letters per 100 words
    float L = (letters / words) * 100;
    
    // Calculate average number of sentences per 100 words
    float S = (sentences / words) * 100;
    
    // Print text's grade reading level
    coleman_liau_index(L, S);
}

int letters_count(string text)
{
    int count = 0;
    
    // Iterate over all letters in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Convert each letter to lowercase
        text[i] = tolower(text[i]);
        
        // Increase letter count if the letter is in the alphabet
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            count++;
        }
    }
    
    return count;
}


int words_count(string text)
{
    int count = 0;
    
    // Iterate over all letters in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Increase word count if there is a space
        if (text[i] == ' ')
        {
            count++;
        }
    }
    
    // Return the word count after incrementing for the last word
    return ++count;
}


int sentences_count(string text)
{
    int count = 0;
    
    // Iterate over all letters in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Increase word count if there is a space
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    
    return count;
}


void coleman_liau_index(float L, float S)
{
    // Compute the Coleman-Liau index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    
    // Determine the text's reading grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
