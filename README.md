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
$ sudo apt install clang
```

### Enable "make" Command
Run the following scripts to add these necessary environment variables to the end of `.bashrc` file in Ubuntu. 

```bash
$ echo 'export CC="clang"' >> ~/.bashrc
$ echo 'export CFLAGS="-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow"' >> ~/.bashrc
$ echo 'export LDLIBS="-lcrypt -lcs50 -lm"' >> ~/.bashrc
```
To reload the file, use:

```bash
$ source ~/.bashrc
```

#### Development
Now you can compile your `C` source code using:

```bash
$ make your_file_name
```
