# Plurality

This program simulates a plurality election, in which every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

## Implementation Details

* The names of the candidates are entered as command-line arguments, sperated by single spaces.

    * If no command-line arguments were entered, the program outputs `Usage: plurality [candidate ...]` and exits.

    * If more than 9 candidates were entered, the program outputs `Maximum number of candidates is 9` and exits.

* The program prompts the user for the number of voters and only accepts integers, otherwise the user is reprompted.

* The program then asks for votes equal to the number entered by the user.

    * If the input is not a name of an existing candidate in the ballot, the program prints `Invalid vote.` and reprompts the user.

* After all votes are entered, the program outputs the name(s) of the candidate(s) with the highest number of votes.
    

## Usage

To run the compiled file, run `./plurality` in the `plurality` directory and the program's behaviour should be as per the examples below.


```bash
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```

```bash
$ ./plurality Alice Bob Charlie Ahmed Mohamed Koko Nono Toto Popo Lolo
Maximum number of candidates is 9
```

```bash
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice
```

```bash
$ ./plurality
Usage: plurality [candidate ...]
```

```bash
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```
