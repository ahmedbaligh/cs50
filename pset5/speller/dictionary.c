// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// Optimally chosen as a prime number that is 1.3 
// times the words count in the large dictionary
const unsigned int N = 186019;

// Hash table
node *table[N];

// Initialize the count of the dictionary's words
unsigned int words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Creates a lowercase copy of word
    int n = strlen(word);
    char lowerWord[n + 1];
    for (int i = 0; i <= n; i++)
    {
        lowerWord[i] = tolower(word[i]);
    }

    // Hash the word
    int index = hash(lowerWord);

    // Initialize a cursor to the head node of the hased word
    node *nextNode = table[index];

    // Search all nodes in the linked list 
    while (nextNode != NULL)
    {
        // Check if the word is in the dictionary, regardless of case
        if (strcasecmp(nextNode->word, lowerWord) == 0)
        {
            return true;
        }
        nextNode = nextNode->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    
    // Allocate memory for a buffer to hold each word in the dictionary
    char *buffer = malloc(LENGTH + 1);
    if (buffer == NULL)
    {
        return false;
    }

    // Read every word in the dictionary, one at a time
    while (fscanf(dict, "%s", buffer) != EOF)
    {
        // Allocate memory for each new linked list element
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy each read word into a new node
        strcpy(n->word, buffer);

        // Hash each word to get it an index in the hash table
        int index = hash(n->word);

        // Insert each new node at the start of linked lists in the hash table
        n->next = table[index];
        table[index] = n;

        // Increament the dictionary's word count
        words++;
    }

    // Release memory resources and close open dictionary
    free(buffer);
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each head node in the array
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        // Free each node in each linked list in the hash table
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
