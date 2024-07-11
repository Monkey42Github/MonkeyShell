# Minishell 42

This project is an implementation of a mini command-line interpreter (minishell) in C, developed as part of the curriculum at 42 school.

## Description

A minishell is a program that acts as a simplified command-line interpreter, akin to Unix shells (such as bash, zsh, etc.). It allows users to execute system commands, navigate the file system, and perform basic operations like input/output stream redirection and managing background processes.

## Features

- **Execution of system commands.** 
- **Management of built-in commands (e.g., cd, echo, pwd).** 
- **Handling redirection operators (<, >, >>).** 
- **Support for pipes (|) for inter-process communication.** 
- **Signal handling for controlling background processes.** 

## Compilation and Execution

1. Clone this repository to your machine:
  ```sh
  git clone <lien vers le dépôt Git>
  ```
2. Navigate to the project directory:
  ```sh
  cd Minishell
  ```
3. Compile the project by running:
  ```sh
  make
  ```
4. Launch the minishell by executing:
  ```sh
   ./minishell
  ```

## Explanation

The minishell is built primarily using low-level system calls such as `fork()`, `exec()`, and `wait()`. It parses user-entered commands, tokenizes them, and executes based on the command-line structure.

Implementation of advanced features like redirections and pipes requires a deep understanding of file descriptor manipulation and process management in C.

The development of a minishell is an excellent exercise for understanding the internal workings of Unix shells and improving skills in system programming.

## Contributors
[pschemit](https://github.com/Monkey42Github)

[yboughan](https://github.com/YoussefBOUGHANMI)
