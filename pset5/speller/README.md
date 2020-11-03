# Speller

This program spell-checks text files using a dictionary of over 140,000 words that is loaded using a hash table.

## Implementation Details

* The name (with the path) of the text file to spell-check is entered as a command-line argument when running the program.

    * If other than 2 or 3 command-line arguments are entered, the program outputs `Usage: ./speller [DICTIONARY] text` and exits.

    * If the text file does not exist or is invalid, the program outputs `Could not open <name_of_textfile>.` and exits.

* The name of the dictionary is entered as an optional command-line argument.

    * If no dictionary was entered, the default dictionary `dictionaries/large` is selected.

    * If the dictionary does not exist or is invalid, the program outputs `Could not load <name_of_dictionary>.` and exits.

* Each misspelled word is printed in a new line.

    * Case is disregarded when spell-checking.

    * The count of the misspelled, dictionary's, and text's words are also printed.

    * Summaries of the time taken by every major function in the program as well as the total run time, are printed as well.

* Memory gets freed either when the program executes successfully, or even when it encounters an error midway.


## Usage

To run the compiled file, run `./speller` in the `speller` directory and the program's behaviour should be as per the examples below.


```bash
$ ./speller texts/constitution.txt

MISSPELLED WORDS

USConstitution
http
usconstitution
const
html
tempore
Impeachments
Nays
Nays
repassed
Piracies
Felonies
attainted
Langdon
Gilman
Brearley
Mifflin
Clymer
Fitzsimons
Jared
Gouvernour
McHenry
Jenifer
Blount
Spaight
Cotesworth
tempore
tempore
tempore
tempore

WORDS MISSPELLED:     30
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        7573
TIME IN load:         0.06
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.02
TIME IN TOTAL:        0.08
```
