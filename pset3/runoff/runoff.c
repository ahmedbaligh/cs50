#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate exists
        if (!strcmp(name, candidates[i].name))
        {
            // Update voter preference to  
            preferences[voter][rank] = i;
            return true;
        }
    }
    
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate over each voter's votes
    for (int voter = 0; voter < voter_count; voter++)
    {
        // Iterate over all candidates
        for (int candidate = 0; candidate < candidate_count; candidate++)
        {
            // Increament candidate's number of votes if voter voted
            // for this candidate and the candidate is not eliminated
            if (preferences[voter][0] == candidate && !candidates[candidate].eliminated)
            {
                candidates[candidate].votes += 1;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Iterate over all candidates
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        // If a candidate has more than half of 
        // the votes, print their name as the winner
        if (candidates[candidate].votes > 0.5 * voter_count)
        {
            printf("%s\n", candidates[candidate].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initialize the minimum as the votes for the first candidate
    int min = candidates[0].votes;

    // Iterate over all the remaining candidates to check for lower votes
    for (int i = 1; i < candidate_count; i++)
    {
        // Only check candidates who have not been eliminated
        if (!candidates[i].eliminated)
        {
            // If a candidate's votes are lower than the
            // current minimum then make it the new minimum
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }

    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Number of tied and uneliminated candidates
    int tie_count = 0;
    int not_eliminated_count = 0;

    // Iterate over all the candidates to check for ties
    for (int i = 0; i < candidate_count; i++)
    {
        // Only check candidates who have not been eliminated
        if (!candidates[i].eliminated)
        {
            // Increament the number of uneliminated candidates
            not_eliminated_count++;

            // If there is a tie, increament the number of ties
            if (candidates[i].votes == min)
                tie_count++;
            
        }
    }
    
    // Return true, only if all uneliminated candidates have ties
    if (tie_count == not_eliminated_count)
        return true;
    
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
