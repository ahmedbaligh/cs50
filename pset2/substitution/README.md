# Substitution

This program allows users to encrypt messages using a substitution cipher that the user enters. This substitution cipher consists of 26 alphabetic letters, each of which replaces an original alphabet letter based on its corresponding position.

## Implementation Details

* The value of the cipher is entered as a second command-line argument when running the program.

* The program only accepts a single command-line argument that is a string of 26 letters, otherwise it will exit and output the following:

    * `missing command-line argument`, if no command-line argument was entered.
    
    * `too many command-line arguments`, if more than one command-line arguments were entered.

    * `enter exactly 26 alphabetic letters`, if the cipher contains more than 26 letters.

    * `all letters must be alphabetic`, if the cipher contains non-alphabetical character.

    * `use each letter only once`, if any letter in the cipher is repeated.

* The program prompts the user for plaintext, the text to be encrypted.

* The program prints the encrypted text, which has the following properties:

    * Non-alphabetic characters are outputted unchanged.

    * Case is preserved, regardless of the value or the case of any letter in the cipher: capitalized letters remain capitalized; lowercase letters remain lowercase.
    

## Usage

To run the compiled file, run `./substitution` in the `substitution` directory and the program's behaviour should be as per the examples below.


```bash
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ
```

```bash
$ ./substitution VCHPRZGJN-@/KFBDQWAXEUYMOI
all letters must be alphabetic
```

```bash
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp
```

```bash
$ ./substitution VCHPRZGJNTXSKFADQWAXEUYMOI
use each letter only once
```

```bash
$ ./substitution FOLRNCPW
enter exactly 26 alphabetic letters
```
