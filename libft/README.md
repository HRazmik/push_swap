This project has been created as part of the 42 curriculum by rovnania
# Description

libft is a custom C library that re-implements standard C functions and adds additional utility functions for use in future projects.
This project is part of the 42 curriculum and aims to strengthen understanding of memory, strings, and linked lists.

The code is divided into three parts: Part 1, Part 2 and Part 3. 

## Part 1 – Libc Functions

Re-implementations of standard C library functions:

| Function   | Description                        |
| ---------- | ---------------------------------- |
| ft_isalpha | Checks for alphabetic character    |
| ft_isdigit | Checks for digit                   |
| ft_isalnum | Checks for alphanumeric            |
| ft_isascii | Checks for ASCII character         |
| ft_isprint | Checks for printable character     |
| ft_strlen  | Calculates string length           |
| ft_memset  | Fills memory with constant byte    |
| ft_bzero   | Zeros memory                       |
| ft_memcpy  | Copies memory area                 |
| ft_memmove | Safe memory copy                   |
| ft_strlcpy | Size-limited string copy           |
| ft_strlcat | Size-limited string concatenation  |
| ft_toupper | Converts to uppercase              |
| ft_tolower | Converts to lowercase              |
| ft_strchr  | Finds character in string          |
| ft_strrchr | Finds last occurrence of character |
| ft_strncmp | Compares strings                   |
| ft_memchr  | Finds byte in memory               |
| ft_memcmp  | Compares memory areas              |
| ft_strnstr | Locates substring                  |
| ft_atoi    | string to integer                  |
| ft_calloc  | Allocates zeroed memory            |
| ft_strdup  | Duplicates string                  |

## Part 2 – Additional Functions

| Function      | Description                          |
| ------------- | ------------------------------------ |
| ft_substr     | Extracts substring                   |
| ft_strjoin    | Joins two strings                    |
| ft_strtrim    | Trims characters                     |
| ft_split      | Splits string                        |
| ft_itoa       | Integer to string                    |
| ft_strmapi    | Applies function to string           |
| ft_striteri   | Iterates over string                 |
| ft_putchar_fd | Outputs character to file descriptor |
| ft_putstr_fd  | Outputs string to file descriptor    |
| ft_putendl_fd | Outputs string + newline             |
| ft_putnbr_fd  | Outputs number                       |

## Part 3 – Linked List Functions

| Function        | Description            |
| --------------- | ---------------------- |
| ft_lstnew       | Creates new node       |
| ft_lstadd_front | Adds node at beginning |
| ft_lstsize      | Counts nodes           |
| ft_lstlast      | Returns last node      |
| ft_lstadd_back  | Adds node at end       |
| ft_lstdelone    | Deletes one node       |
| ft_lstclear     | Deletes entire list    |
| ft_lstiter      | Iterates list          |
| ft_lstmap       | Maps list              |

# Instructions
To compile the code, run `make` in the terminal. This will create a library called `libft.a`.
To clean the object files and library, run `make clean` and `make fclean`, respectively.

| Rule          | Description                       |
| ------------- | --------------------------------- |
| `make`        | Compile the library               |
| `make clean`  | Remove object files               |
| `make fclean` | Remove object files and `libft.a` |
| `make re`     | Recompile everything              |

The library is accompanied by a header file called `libft.h`, which contains prototypes for all the functions in the library.
To use the library in your project, include the header file and link to the library.

Compile your program with the library:
```bash
cc main.c -L. -lft
```
Or manually:
```bash
cc main.c libft.a
```
# Resources

Helpful references used during the development of this project:
| Resource                                                                               | Description                                        |
| -------------------------------------------------------------------------------------- | -------------------------------------------------- |
| [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)                  | Official documentation for GNU Make and Makefiles  |
| [The GNU C Reference Manual](https://www.gnu.org/software/gnu-c-manual/)               | Complete reference for the C programming language  |
| [Makefile Tutorial](https://makefiletutorial.com/)                                     | Beginner-friendly guide to understanding Makefiles |
| [TutorialsPoint – C Programming](https://www.tutorialspoint.com/cprogramming/)         | Step-by-step tutorials and references for C        |
| [GeeksforGeeks – C Programming](https://www.geeksforgeeks.org/c-programming-language/) | Articles, examples, and explanations of C concepts |
| *The C Programming Language* – Brian W. Kernighan & Dennis M. Ritchie                  | Classic book covering the fundamentals of C        |

