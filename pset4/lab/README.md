# Runoff

This program allows users to modify the volume of a WAV audio file by a scale of their choice.


## Implementation Details

* The program should be called with 3 command-line arguments: the name of the original file, the name of the file to be created, and the factor to scale with. 

    * If no command-line arguments were entered or if they were entered incorrectly, the program outputs `Usage: ./volume input.wav output.wav factor` and exits.
    
    * The names of the input and output files should be entered with the `.wav` extension.
    
    * The scaling factor is a floating point number.

* If it executes successfully, nothing is printed and the output file is stored in the same directory.
    

## Usage

To run the compiled file, run `./volume` in the `lab` directory and the program's behaviour should be as per the examples below.


```bash
./volume input.wav output.wav 2.0
```

```bash
./volume input.wav output.wav 0.5
```

```bash
$ ./volume
Usage: ./volume input.wav output.wav factor
```
