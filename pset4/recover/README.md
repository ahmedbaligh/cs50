# Recover

This program allows users to recover JPEG images from a forensic image. In other words, if you have the raw version of some deleted JPEGs, you can recover them using this program.

## Implementation Details

* The name of forensic image to recover from is entered as a command-line argument when running the program in the following form: `./recover card.raw`.

    * If more or less than one command-line argument is entered, the program outputs `Usage: ./recover image` and exits.

    * If the input forensic image does not exist or is invalid, the program outputs `Could not open file.` and exits.

* Each recovered image is named in the following format: `###.jpg` (e.g. 037.jpg).

* Recovered images are saved to the same directory as that of the program.


## Usage

To run the compiled file, run `./recover` in the `recover` directory and the program's behaviour should be as per the examples below.


```bash
./recover card.raw
```

```bash
$ ./recover
Usage: ./recover image
```

```bash
$ ./recover card
Could not open file.
```
