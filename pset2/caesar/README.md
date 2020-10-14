# Caesar

This program allows users to encrypt messages using Caesar’s cipher, which shifts each letter in the message by some number of places, which is the value of the key that the user inputs.

## Implementation Details

* The value of the key is entered as a second command-line argument when running the program.

* The program only accepts a single command-line argument that is also a non-negative integer, otherwise it will exit and output the following:

    * `missing command-line argument`, if no command-line argument was entered.
    
    * `too many command-line arguments`, if more than one command-line arguments were entered.

    * `Usage: ./caesar key`, if a non-negative integer was entered.

* The program prompts the user for plaintext, the text to be encrypted.

* The program prints the encrypted text, which has the following properties:

    * Non-alphabetic characters are not shifted and remain the same.

    * Alphabetical characters that exceed the letter `z` are not shifted to non-alphabetic characters, but rather rotated through the alphabet of their same case.

    * Case is preserved, no matter what the value of the key is: capitalized letters remain capitalized; lowercase letters remain lowercase.
    

## Usage

To run the compiled file, run `./caesar` in the `caesar` directory and the program's behaviour should be as per the examples below.

```bash
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```

```bash
$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
```

```bash
$ ./caesar HELLO
Usage: ./caesar key
```

```
$ ./caesar
missing command-line argument
```

```
$ ./caesar 1 2 3
too many command-line arguments
```
