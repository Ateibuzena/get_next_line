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
```

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
- Add all the helper functions you need in the `get_next_line_utils.c` file.ç
- Your program must compile with the flag -D BUFFER_SIZE=xx. This flag will be used to determine the buffer size for the readings of your get_next_line(). This parameter will be modified by your evaluators and by Moulinette to test your program.
- The program will be compiled as follows (an example using a buffer size of 42):
```c
  cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <files>.c
```
- `get_next_line()` is considered to have undefined behavior if the file pointed to by fd has changed since the last call, provided read() has not reached the end of the file.
- `get_next_line()` is considered to have undefined behavior when reading from a binary file. However, you can implement a logical way to handle this issue if desired.

### Chapter IV  
#### Bonus Part  

This project is quite straightforward and doesn't leave much room for bonuses. However, we trust in your creativity. If you have completed the mandatory part, try it with these bonuses.  

Here are the requirements for the bonus part:  
- Develop `get_next_line()` using only one static variable.
- Your `get_next_line` should be able to handle multiple file descriptors (fd) simultaneously. That is, if you have three available fds for reading (for example: 3, 4, and 5), you should be able to use `get_next_line` alternately on fd 3, then on fd 4, and then on fd 5 without losing the reading context for each fd.  
- Append the suffix `_bonus.[c\h]` to the files in this bonus part. This means, in addition to the mandatory part files, you must deliver the following three files:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`


