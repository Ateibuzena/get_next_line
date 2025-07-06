# � get_next_line - Line-by-Line File Reader

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-42-green.svg)](https://github.com/42School/norminette)

## 📖 Description

`get_next_line` is a C function that reads a file descriptor line by line, returning one line each time it's called (including the newline character, if present). The bonus version extends this functionality to handle multiple file descriptors simultaneously. This project is a fundamental exercise at 42 School, focusing on file I/O, buffer management, and memory handling in C.

## ✨ Features
- Read from any file descriptor (files, stdin, etc.)
- Handles multiple file descriptors simultaneously (bonus)
- Efficient buffer management
- Custom utility functions for string operations
- Bonus version with support for multiple file descriptors using a linked list

## 📄 Function Prototypes

**Mandatory:**
```c
char *get_next_line(int fd);
```

**Bonus:**
```c
char *get_next_line(int fd);
char *ft_free(char *ptr);
size_t ft_strlen(const char *s);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(const char *str, int c);
typedef struct s_fdnode {
    char *buffer;
    int fd;
    struct s_fdnode *next;
} t_fdnode;
t_fdnode *ft_newnode(int fd);
char *ft_freenode(t_fdnode **list, int fd);
```

## �️ Usage

### Compilation

**Mandatory version:**
```sh
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
```

**Bonus version:**
```sh
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

You can set the buffer size at compile time:
```sh
gcc -D BUFFER_SIZE=100 ...
```

### Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## 📁 File Structure

| File                        | Description                                      |
|-----------------------------|--------------------------------------------------|
| `get_next_line.c`           | Core logic for reading lines                     |
| `get_next_line_utils.c`     | Utility functions for string and memory handling |
| `get_next_line.h`           | Header for mandatory version                     |
| `get_next_line_bonus.c`     | Bonus: multi-fd support                          |
| `get_next_line_utils_bonus.c`| Bonus: utilities for bonus version               |
| `get_next_line_bonus.h`     | Header for bonus version                        |

## 📚 Learning Points
- File descriptor management
- Dynamic memory allocation and freeing
- Custom string manipulation functions
- Handling edge cases (EOF, errors, empty lines)
- Linked list usage for bonus multi-fd support

## 🏫 42 School Project
This project is part of the 42 School curriculum. For more information, visit the [42 Network](https://www.42network.org/).

---
*Developed by azubieta*
