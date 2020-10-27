# Filter

This program allows users to apply several image filters to BMP images like Grayscale, Sepia, Reflection, and Blur.

## Implementation Details

* The name of the input and output image and the filter are entered as command-line arguments when running the program in the following form: `./filter -g infile.bmp outfile.bmp`.

    * If no command-line arguments were entered, the program outputs `Usage: filter [flag] infile outfile` and exits.

    * If the filter entered does not exist, the program outputs `Invalid filter.` and exits.

    * If more than one filter are entered, the program outputs `Only one filter allowed.` and exits.

    * If the input image does not exist, the program outputs `Could not open <image_name>.` and exits.

    * If the input image is not of type BMP, the program outputs `Unsupported file format.` and exits.

    * If the output image could not be created, the program outputs `Could not create <image_name>.` and exits.

* The name of the filter is entered as a flag, when running the program, where:

    * `-g` means Grayscale filter.

    * `-s` means Sepia filter.

    * `-r` means Reflection filter.

    * `-b` means Blur filter.
    

## Usage

To run the compiled file, run `./filter` in the `filter/less` directory and the program's behaviour should be as per the examples below.


```bash
./filter -r images/courtyard.bmp reflected.bmp
```

```bash
$ ./filter -b images/courtyard.bmp
Usage: filter [flag] infile outfile
```

```bash
$ ./filter -s fake.bmp new.bmp
Could not open fake.bmp.
```

```
$ ./filter -n images/courtyard.bmp new.bmp
./filter: invalid option -- 'n'
Invalid filter.
```

```bash
$ ./filter -b images/stadium.bmp blurred.bmp
```

```bash
$ ./filter -r images/sample.jpg new.bmp
Unsupported file format.
```
