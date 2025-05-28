# get_next_line

## 📌 Description

`get_next_line` is a function designed to read a file line by line, returning a line each time it is called, including the newline character (`\n`) if present. This project is a common exercise at 42 school to practice file reading, buffer management, and memory handling in C.

## 🧠 Goal

The main goal is to implement the function:

```c
char *get_next_line(int fd);

```
Which returns the next line from a file descriptor fd, or NULL if there's nothing more to read or an error occurs.

## 📚 Usage

### ✅ Compilation

To compile the project, you can use:

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line

```
Note: You must define BUFFER_SIZE manually or with a -D flag in the compiler command.

### ✅ Function Prototype

```c
char *get_next_line(int fd);

```
- Returns a line read from a file descriptor.

- Returns NULL when there's nothing left to read or an error occurs.

- Handles multiple file descriptors simultaneously.

## 📁 Files

```
| File                    | Description                               |
| ----------------------- | ----------------------------------------- |
| `get_next_line.c`       | Contains the core logic for reading lines |
| `get_next_line_utils.c` | Utility functions used by `get_next_line` |
| `get_next_line.h`       | Header file with function prototypes      |
| `main.c` *(optional)*   | File for testing the function             |
```
