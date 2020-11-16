# DNA

This program identifies a person based on their DNA, using STR. An STR is a short sequence of DNA bases that tends to repeat consecutively numerous times at specific locations inside of a person’s DNA. Given the DNA sequence of a person and a database containing STR counts for a list of individuals, the program will then output to whom the DNA (most likely) belongs—if there are any matches.

## Implementation Details

* The program takes a database file in `csv` format as a first command-line argument when running the program and the name of a `txt` file containing the DNA sequence as a second command-line argument.

    * If anything other than 3 command-line arguments are entered, the program outputs `Usage: python dna.py data.csv sequence.txt` and exits.

* The program outputs the name of the most likely match, if found. Otherwise, it prints `No match`.


## Usage

To run the program, make sure to be in the `dna` directory, execute `python3 dna.py <data.csv> <sequence.txt>` and the program's behaviour should be as per the examples below.


```bash
$ python3 dna.py databases/large.csv sequences/5.txt
Lavender
```

```bash
$ python3 dna.py databases/large.csv sequences/18.txt
No match
```

```bash
$ python3 dna.py
Usage: python dna.py data.csv sequence.txt
```

```bash
$ python3 dna.py databases/large.csv sequences/8.txt
Ginny
```
