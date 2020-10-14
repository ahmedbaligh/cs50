# Lab 2: Scrabble

This program allows users to enter two words, one for each player, then calculates the score of each word. Both scores are compared and the winning player is notified.

Points are scored for each alphabetic character as per the table below:

<table>
    <thead>
        <tr>
            <th>A</th>
            <th>B</th>
            <th>C</th>
            <th>D</th>
            <th>E</th>
            <th>F</th>
            <th>G</th>
            <th>H</th>
            <th>I</th>
            <th>J</th>
            <th>K</th>
            <th>L</th>
            <th>M</th>
            <th>N</th>
            <th>O</th>
            <th>P</th>
            <th>Q</th>
            <th>R</th>
            <th>S</th>
            <th>T</th>
            <th>U</th>
            <th>V</th>
            <th>W</th>
            <th>X</th>
            <th>Y</th>
            <th>Z</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>3</td>
            <td>3</td>
            <td>2</td>
            <td>1</td>
            <td>4</td>
            <td>2</td>
            <td>4</td>
            <td>1</td>
            <td>8</td>
            <td>5</td>
            <td>1</td>
            <td>3</td>
            <td>1</td>
            <td>1</td>
            <td>3</td>
            <td>10</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>1</td>
            <td>4</td>
            <td>4</td>
            <td>8</td>
            <td>4</td>
            <td>10</td>
        </tr>
    </tbody>
</table>


## Implementation Details

* The program prompts the users twice, one for the first player's word and another for the second's.

* The program is case-insensitive.

* All non-alphabetic characters are worth `0` points.

* If both entries have the same score, the program outputs `Tie!`.

---
## Usage

To run the compiled file, run `./scrabble` in the `lab` directory and the program's behaviour should be as per the examples below.

```bash
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

```bash
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```

```bash
$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
```

```bash
$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
```