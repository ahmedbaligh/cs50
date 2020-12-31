# CS50 Problem Sets
This repository contains my own solutions to weekly problem sets in CS50, Harvard University's introduction to the intellectual enterprises of computer science and the art of programming.


## CS50 Library for C

### Library Installation

```bash
curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
sudo apt-get install libcs50
```

or refer to [CS50 Library for C](https://github.com/cs50/libcs50/tree/master) for more information.

#### Library Usage

Now, to use the CS50 Library in your `C` programs, just write `#include <cs50.h>` atop your code.

### Clang Installation
Install the `Clang` compiler on Linux:

```bash
sudo apt install clang
```

## Enable CS50-specific Commands

### `make` Command

The `make` command simplifies the process of compiling your `C` source code. 

Run the following scripts to add these necessary environment variables to the end of `.bashrc` file in Ubuntu. 

```bash
echo 'export CC="clang"' >> ~/.bashrc
echo 'export CFLAGS="-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow"' >> ~/.bashrc
echo 'export LDLIBS="-lcrypt -lcs50 -lm"' >> ~/.bashrc
```
To reload the file, use:

```bash
source ~/.bashrc
```

#### Usage

Now you can compile your `C` source code using:

```bash
make <your_file_name>
```

### `help50` Command

The `help50` command can be used to help you identify errors that arise, when compiling our code.

Make sure you have Python 3.6 or higher installed, then run the following: 

```bash
pip3 install help50
```

#### Usage

```bash
help50 make <your_file_name>
```

### `check50` Command

The `check50` command is used to give you automatic feedback on the correctness of your code, as it compares your code to pre-written tests in a git repo, if the checks exist for this certain CS50 problem set.

Make sure you have Python 3.6 or higher installed, then run the following: 

```bash
pip3 install check50
```

#### Usage

You need to know the the slug of the certain problem set you want to check. For instance, this here:

```bash
check50 cs50/problems/2020/x/credit
```
checks the correctness of CS50x Credit problem set from Week 1.


## CS50 Library for Python

Firstly make sure that you have the latest version of `Python3` installed. If you do not, simply execute:

```bash
sudo apt-get update
sudo apt-get install python3.8 python3-pip
```

### Library Installation

```bash
pip3 install cs50
```

#### Library Usage

Now, to use the CS50 Library in your `Python` programs, you can just import the entire library by putting `import cs50` at the top in your Python program, or you could import specific functions (e.g. `get_string()`) using `from cs50 import get_string`.

### SQLite Installation

Install the SQLite Database Mangement System on Linux:

```bash
sudo apt install sqlite3
```
