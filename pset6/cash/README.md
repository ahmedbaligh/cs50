# Cash

This program revisit Problem Set 1's Cash and does the exact same thing, but this time in Python. Cash lets you minimize the number of coins (change) you’re dispensing for each customer, by informing you of the least number coins you may return for any amount of owed money.

The program **only** incoperates, and accordingly calculates based upon, four types of US coins: _quarters_ (25¢), _dimes_ (10¢), _nickels_ (5¢), and _pennies_ (1¢).


## Implementation Details

* The program prompts the user for the money owed and the user will be re-prompted, if they enter:

    * a non-numerical value.

    * a negative numerical value.

    * in an invalid form (eg. $4.63, 463), instead of in a valid one (eg. 4.63).


## Usage

To run the program, make sure to be in the `cash` directory, execute `python3 cash.py` and the program's behaviour should be as per the examples below.

```bash
$ python3 cash.py
Change owed: 2.16
11
```

```bash
$ python3 cash.py
Change owed: -0.41
Change owed: foo
Change owed: 0.41
4
```

