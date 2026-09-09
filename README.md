
*This project has been created as part
of the 42 curriculum by mradkovi*
# ft_printf

## Description
The goal of this project was to create a custom function, `ft_printf`, that behaves exactly like the original `printf` function from the `stdio.h` C library (`man 3 printf`).

The implemented conversions are:
* `%c` - print a character 
* `%s` - print a string
* `%i` - print an integer
* `%d` - print a number in decimal notation
* `%x` - print a number in hexadecimal notation (lowercase)
* `%X` - print a number in hexadecimal notation (uppercase)
* `%p` - print an address (pointer)
* `%u` - print an unsigned number
* `%%` - print %

The function returns the number of characters printed.

## Instructions
### Compilation
The library is compiled using the provided **Makefile** with `-Wall -Wextra -Werror` flags.

**Available Makefile commands:**

```bash
make
```
Compiles all source files and creates libft.a

```bash
make clean
```
Removes all object files (.o)

```bash
make fclean
```
Removes object files and libft.a
```bash
make re
``` 
Rebuilds the library from scratch

## Usage

Include the header file in your C project
```c
#include "ft_printf.h"
```
Compile your project with `libftprintf.a`
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o prog_name
```

## Resources
* System manual pages (`man 3 printf`, `man stdarg`)
### Books
* **Head First C: A Brain Friendly Guide** - David Griffiths
* **Advanced Programming in the UNIX Enviroment** (http://www.apuebook.com/apue3e.html) by W. Richard Stevens, Stephen A. Rago - Chapter 5.11 (Formatted I/O)
* **C Programming: A Modern Approach** second Edition K. N. King - Chapter 26 (Miscellaneous Library Functions)
