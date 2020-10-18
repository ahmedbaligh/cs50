# Runoff

This program simulates a runoff election, which is also called a ranked-choice system. In a ranked-choice system, voters can vote for more than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. At the end of the election, whichever candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election.

If no candidate has more than 50% of the vote, then an “instant runoff” occurrs. The candidate who received the fewest number of votes is eliminated from the election, and anyone who originally chose that candidate as their first preference now has their second preference considered.

The process repeats: if no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner. If every remaining candidate has the exact same number of votes, the election is a tie between all remaining candidates.

## Implementation Details

* The names of the candidates are entered as command-line arguments, sperated by single spaces.

    * If no command-line arguments were entered, the program outputs `Usage: runoff [candidate ...]` and exits.

    * If more than 9 candidates were entered, the program outputs `Maximum number of candidates is 9` and exits.

* The program prompts the user for the number of voters and only accepts integers, otherwise the user is reprompted.

* The program then prompts for votes equal to the number entered by the user.

    * Each voter needs to vote for all candidates in a ranked preference manner, where the first candidate entered is their top choice.

    * If the input is not a name of an existing candidate in the ballot, the program prints `Invalid vote.` and exits immediately.

* After all votes are entered, the program outputs the name(s) of the candidate(s), who won (or tied) in the election.
    

## Usage

To run the compiled file, run `./runoff` in the `runoff` directory and the program's behaviour should be as per the examples below.


```bash
./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

```bash
$ ./runoff Alice Bob Charlie Ahmed Mohamed Yumi Nono Soso Mark Lolo
Maximum number of candidates is 9
```

```bash
$ ./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: nmfkd
Invalid vote.
```

```bash
$ ./plurality
Usage: plurality [candidate ...]
```

```bash
$ ./runoff Alice Bob Charlie
Number of voters: 4
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
Charlie
```
