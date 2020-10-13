# Mario

This program simulates the right-aligned pyramid of blocks, which Mario must ascend, toward the end of World 1-1 in Nintendo’s Super Mario Brothers.

However, this program recreates the pyramid in text, replacing the blocks hashes `(#)`.


## Implementation Details

* The program prompts the user for the height of the pyramid.

    * The height must be a positive integer, inclusivly between 1 and 8; if not, the user will be re-prompted.

## Usage

To run the compiled file, run `./mario` in the `mario/less` directory and the program's behaviour should be as per the examples below.

```
$ ./mario
Enter the height of the pyramid: 8
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```

```
$ ./mario
Enter the height of the pyramid: -1
Enter the height of the pyramid: 0
Enter the height of the pyramid: 42
Enter the height of the pyramid: 50
Enter the height of the pyramid: 4
   #
  ##
 ###
####
```
