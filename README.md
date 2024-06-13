Reading a line from an fd is too boring.

**Summary:** The objective of this project is simple: to program a function that returns
a line read from a file descriptor.

# General Index

I. Objectives  
II. General Instructions  
III. Mandatory Part  
IV. Bonus Part  

## Chapter I  
### Objectives  
This project will not only allow you to add a quite practical function to your collection;  
it will also make you learn the incredible concept of static variables in C.

## Chapter II  
### General Instructions  
- Your project must be written in C.

## Chapter III  
### Mandatory Part  

**Function Name:**  
get_next_line  

**Prototype:**  
```c
char *get_next_line(int fd);

 **Files to Submit**
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

**Parameters**
- `fd`: File descriptor from which to read

**Return Value**
- If successful: the line read
- In case of failure or if the reading ends: NULL

**Allowed Functions**
- `read`
- `malloc`
- `free`

**Description**
Write a function that returns the line read from a file descriptor.


Calling your `get_next_line` function repeatedly (for example, using a loop) will allow you to read the contents of the file pointed to by the file descriptor, line by line, until the end.

- Your function should return the line that has just been read.
  If there is nothing more to read or if an error has occurred, it should return NULL.
- Ensure that your function behaves appropriately when reading from a file and when reading from stdin.
- Note that the returned line must end with the character `\n`, except if the end of the file is reached and it does not end with a `\n` character.
- In the header `get_next_line.h`, you should have at least the prototype of the `get_next_line` function.
- Add all the helper functions you need in the `get_next_line_utils.c` file.

