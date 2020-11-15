# Mario

This program revisit Problem Set 1's Mario (more) and does the exact same thing, but this time in Python. Mario (more) simulates the adjacent pyramids of blocks, which Mario must hop over, toward the end of World 1-1 in Nintendo’s Super Mario Brothers.

However, this program recreates the pyramid in text, replacing each block with a hash `(#)`.


## Implementation Details

* The program prompts the user for the height of the pyramid.

    * The height must be a positive integer, inclusivly between 1 and 8; if not, the user will be re-prompted.

## Usage

To run the program, make sure to be in the `/mario/more` directory, execute `python3 mario.py` and the program's behaviour should be as per the examples below.

```
$ python3 mario.py
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

```
$ python3 mario.py
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```



