# 1. Simplified Bash

|  |  |
| :-: | - |
| Topic | UNIX Shell |
| Related | Operating Systems |
| Stack | C |
| Slides | [simplified_bash_slides](https://docs.google.com/presentation/d/e/2PACX-1vQSxwSMoJDOQPgxk54X9hex6qQ2wNgS5lrL-LxMWLos_R5PeMSnAYUUB9rMKJOcoukkRApPxQK3qkh5/pub?start=false&loop=false&delayms=3000) |

# Description

A program that launches executables and builtins. A group project made in collaboration with <a href="mailto:arthur@prahin.net" target="_blank">Arthur Prahin.</a>

# Key features
- Handles pipes, logical operators and subshell. 
- Expands env var and *
- Echo, cd, pwd, export, unset, env, exit are implemented..

# Getting Started

First, compile the program:

```bash
make
```

Then run the compiled executable:

```bash
./minihell
```

Optionally, after you compiled the program, you can run the tester (test.sh). <br>
Make sure to allow test.sh to be executed with "chmod".

```bash
chmod u+x test.sh
./test.sh
```

# Simplified Bash tester
![test.sh](https://i.ibb.co/XsxGKJc/minihell.png)
