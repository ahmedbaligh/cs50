# Credit

This program revisit Problem Set 1's Credit and does the exact same thing, but this time in Python. Credit allows users to determine if the number they enter is a valid credit card number or not, based on [Luhn’s Algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm).

## Implementation Details

* The program prompts the user for a number.

    * The inputed number must be an integer, without the hyphens found on the card, otherwise the user will be re-prompted.

* If the entered number meets the above criteria, the output will be one of the following:

    * AMEX, if it is an American Express card.
    * MASTERCARD, if it is a MasterCard card.
    * VISA, if it is a Visa card.
    * INVALID, if it is not a valid card number.

## Usage

To run the program, make sure to be in the `credit` directory, execute `python3 credit.py` and the program's behaviour should be as per the examples below.

```bash
$ python3 credit.py
Number: 4003600000000014
VISA
```

```bash
$ python3 credit.py
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
```

```bash
$ python3 credit.py
Number: 6176292929
INVALID
```
