# CS50 Problem Sets
This repository contains my own solutions to weekly problem sets in CS50, Harvard University's introduction to the intellectual enterprises of computer science and the art of programming. **(ongoing)**


## CS50 Library for C

### Library Installation

#### Ubuntu
```bash
$ curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
$ sudo apt-get install libcs50
```

#### Fedora
```bash
$ curl -s https://packagecloud.io/install/repositories/cs50/repo/script.rpm.sh | sudo bash
$ yum install libcs50
```
or refer to [CS50 Library for C](https://github.com/cs50/libcs50/tree/master) for more information.

### Clang Installation
Install the Clang compiler on Linux:

```bash
sudo apt install clang
```

## Enable CS50-specific Commands

### `make` Command

The `make` command simplifies the process of compiling your `C` source code. 

Run the following scripts to add these necessary environment variables to the end of `.bashrc` file in Ubuntu. 

```bash
$ echo 'export CC="clang"' >> ~/.bashrc
$ echo 'export CFLAGS="-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow"' >> ~/.bashrc
$ echo 'export LDLIBS="-lcrypt -lcs50 -lm"' >> ~/.bashrc
```
To reload the file, use:

```bash
source ~/.bashrc
```

#### Usage
Now you can compile your `C` source code using:

```bash
make your_file_name
```

### `help50` Command

The `help50` command can be used to help you identify errors that arise, when compiling our code.

Make sure you have Python 3.6 or higher installed, then run the following: 

```bash
pip install help50
```

#### Usage

```bash
help50 make your_file_name
```

### `check50` Command

The `check50` command is used to give you automatic feedback on the correctness of your code, as it compares your code to pre-written tests in a git repo, if the checks exist for this certain CS50 problem set.

Make sure you have Python 3.6 or higher installed, then run the following: 

```bash
pip install check50
```

#### Usage

You need to know the the slug of the certain problem set you want to check. For instance, this here:

```bash
check50 cs50/problems/2020/x/credit
```
checks the correctness of CS50x Credit problem set from Week 1.