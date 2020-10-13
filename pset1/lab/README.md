# Lab 1: Population Growth

This program allows you to determine how long it takes for a population to reach a particular size, based on the assumption that an additional one-third of the current population are born and another one-quarter pass away each year.

## Implementation Details

* The program prompts the user for a starting population size.

    * The minimum allowed population size is 9; if the user enters a number less than 9, they will be re-prompted.

* The program prompts the user for an ending population size.

    * The ending population size must be larger than the starting size; the user will be re-prompted until this condition is met.

* The calculated number of years is an integer, rounded to reach, at least, the size of the end value.

## Usage

To run the compiled file, run `./population` in the `population` directory and the program's behaviour should be as per the examples below.

```bash
$ ./population
Start size: 1200
End size: 1300
Years: 1
```

```bash
$ ./population
Start size: -5
Start size: 3
Start size: 9
End size: 5
End size: 18
Years: 8
```

```bash
$ ./population
Start size: 20
End size: 1
End size: 10
End size: 100
Years: 20
```

```bash
$ ./population
Start size: 100
End size: 1000000
Years: 115
```