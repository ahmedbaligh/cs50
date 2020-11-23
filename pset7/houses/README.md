# Houses

Simple program consisting of 2 scripts, one to import data from a `csv` file containing the names and birth years of `Harry Potter` characters into a SQLite database. The second script can then query that database to print a roster for the house, specified by the user.


## Implementation Details

* The program takes a database file in `csv` format as a first command-line argument when running the `import.py` script.

    * If anything other than 2 command-line arguments are entered, the program outputs `Usage: python import.py data.csv` and exits.

* The program takes a [Harry Potter House](https://en.wikipedia.org/wiki/Hogwarts#Houses) as a first command-line argument when running the `roster.py` script.

    * If anything other than 2 command-line arguments are entered, the program outputs `Usage: python roster.py house_name` and exits.

* The output of the second script is a roster of the specified house, ordered by the characters' last name, then first name.

## Usage

To run the program, make sure to be in the `houses` directory, execute `python3 import.py characters.csv`, then `python3 roster.py <house_name>` and the program's behaviour should be as per the examples below.

```
$ python3 import.py characters.csv
$ python3 roster.py Gryffindor
Lavender Brown, born 1979
Colin Creevey, born 1981
Seamus Finnigan, born 1979
Hermione Jean Granger, born 1979
Neville Longbottom, born 1980
Parvati Patil, born 1979
Harry James Potter, born 1980
Dean Thomas, born 1980
Romilda Vane, born 1981
Ginevra Molly Weasley, born 1981
Ronald Bilius Weasley, born 1980
```

```
$ python3 roster.py Hufflepuff
Hannah Abbott, born 1980
Susan Bones, born 1979
Cedric Diggory, born 1977
Justin Finch-Fletchley, born 1979
Ernest Macmillan, born 1980
```

```
$ python3 roster.py Ravenclaw
Terry Boot, born 1980
Mandy Brocklehurst, born 1979
Cho Chang, born 1979
Penelope Clearwater, born 1976
Michael Corner, born 1979
Roger Davies, born 1978
Marietta Edgecombe, born 1978
Anthony Goldstein, born 1980
Robert Hilliard, born 1974
Luna Lovegood, born 1981
Isobel MacDougal, born 1980
Padma Patil, born 1979
Lisa Turpin, born 1979
```

```
$ python3 roster.py Slytherin
Millicent Bulstrode, born 1979
Vincent Crabbe, born 1979
Tracey Davis, born 1980
Marcus Flint, born 1975
Gregory Goyle, born 1980
Terence Higgs, born 1979
Draco Lucius Malfoy, born 1980
Adelaide Murton, born 1982
Pansy Parkinson, born 1979
Adrian Pucey, born 1977
Blaise Zabini, born 1979
```
