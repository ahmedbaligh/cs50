# Lab 6: World Cup

This program runs simulations of the FIFA World Cup to estimate the percentages for each team's chance of winning. It uses a `csv` file that contains the names of the playing teams, along with their ratings. The order in which the teams are listed should determine which teams will play each other in each round.


## Implementation Details

* The program takes the name of the `csv` file as a command-line argument.

    * If more or less than one command-line arguments were entered, the program prints `Usage: python tournament.py FILENAME` and exits.

* This version of the program runs 1000 simulations.

    * The implementation can be easily changed to include any number of simulations.
    

## Usage

To run the program, make sure to be in the `lab` directory, execute `python3 tournament.py <filename.csv>` and the program's behaviour should be as per the examples below.

```bash
$ python3 tournament.py 2018m.csv
Belgium: 22.2% chance of winning
Brazil: 20.2% chance of winning
Portugal: 14.4% chance of winning
Spain: 12.8% chance of winning
Switzerland: 9.2% chance of winning
Argentina: 6.9% chance of winning
France: 3.2% chance of winning
Denmark: 3.0% chance of winning
England: 3.0% chance of winning
Colombia: 1.7% chance of winning
Croatia: 1.5% chance of winning
Uruguay: 0.7% chance of winning
Mexico: 0.6% chance of winning
Sweden: 0.6% chance of winning
Japan: 0.0% chance of winning
Russia: 0.0% chance of winning
```

```bash
$ python3 tournament.py
Usage: python tournament.py FILENAME
```

```bash
$ python3 tournament.py 2019w.csv
Germany: 16.9% chance of winning
United States: 14.3% chance of winning
England: 13.9% chance of winning
France: 9.2% chance of winning
Japan: 8.0% chance of winning
Australia: 6.4% chance of winning
Netherlands: 6.2% chance of winning
Canada: 5.9% chance of winning
Italy: 3.6% chance of winning
Brazil: 3.4% chance of winning
Sweden: 3.4% chance of winning
Norway: 3.1% chance of winning
Spain: 2.8% chance of winning
China PR: 2.8% chance of winning
Nigeria: 0.1% chance of winning
Cameroon: 0.0% chance of winning
```
