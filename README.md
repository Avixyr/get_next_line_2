*This project has been created as part of the 42 curriculum by Avixyr.*

# get_next_line

## Description

`get_next_line` is a C function developed as part of the 42 curriculum. The goal of the project is to create a function that returns a line read from a file descriptor.

The function is written in C.

## Instructions

### Requirements

- The system headers required by `get_next_line.h`.

### Use the library

Include `get_next_line.h` in your C source and udw the function. For example:

```sh
fd = open("test",O_RDONLY);
s = get_next_line(fd);
free(s1);
close(fd);
```

## Get_next_line contents

Only handle multiple fd with bonus.

### Bonus

Compile with _bonus.c and bonus.h allow the use of `get_next_line` with multiple fd.

## Resources

- The C standard library reference: [cppreference — C library](https://en.cppreference.com/w/c)
- The geeksforgeeks page on static variable : [geeksforgeeks.org/c/static-variables-in-c/](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- The 42 curriculum and the subject provided by the campus are the project requirements for expected behavior and function prototypes.
