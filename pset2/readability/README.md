# Readability

This program allows users to computes the approximate grade level needed to comprehend some text. The readability test used in this program is the [Coleman-Liau index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index), which a test designed to output the U.S. grade level needed to understand the text in question.

## Implementation Details

* The program prompts the user to enter some reading text.

* Based on the [Coleman-Liau index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index), the output will be one of the following:

    * `Grade X`, where X is the index rounded to the nearest integer, if if the index is between 1 and 16.
    * `Before Grade 1`, if the index is less than one.
    * `Grade 16+`, if the index is equivalent to or greater than a senior undergraduate reading level.
    

## Usage

To run the compiled file, run `./readability` in the `readability` directory and the program's behaviour should be as per the examples below.

```
$ ./readability
Text: One fish. Two fish. Red fish. Blue fish.
Before Grade 1
```

```
$ ./readability
Text: In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
Grade 7
```

```
$ ./readability
Text: It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
Grade 10
```

```
$ ./readability
Text: A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.
Grade 16+
```