*This project has been created as part of the 42 curriculum by hugo-mar.*

# ft_printf

## Description

**ft_printf** is a 42 project whose goal is to recreate part of the behaviour of the standard C `printf()` function.

The project introduces **variadic functions** and requires building a custom formatted output function:

```c
int ft_printf(const char *format, ...);
```

The final result is a static library named `libftprintf.a` containing `ft_printf()` and its helper functions.

This implementation focuses on the mandatory part of the project and supports the required basic conversions while keeping the code simple, readable, and modular.

---

## Project Goal

The aim of the project is to understand how formatted output works internally by:

- parsing a format string
- reading variadic arguments with `va_list`
- dispatching each conversion to the correct helper function
- printing characters, strings, numbers, pointers, and hexadecimal values
- returning the total number of printed characters

This project is also useful because, once completed, `ft_printf()` can later be reused in other 42 C projects.

---

## Supported Conversions

This implementation handles the mandatory conversions:

- `%c` prints a single character
- `%s` prints a string
- `%p` prints a pointer in hexadecimal format
- `%d` prints a decimal integer
- `%i` prints an integer in base 10
- `%u` prints an unsigned decimal integer
- `%x` prints a hexadecimal number in lowercase
- `%X` prints a hexadecimal number in uppercase
- `%%` prints a percent sign

As required by the subject, buffer management from the original `printf()` is not implemented.

---

## How This Implementation Works

This version of `ft_printf()` uses a simple and direct approach:

- it reads the format string one character at a time
- ordinary characters are written immediately
- when `%` is found, the next character is checked
- the corresponding helper function is called depending on the conversion
- each helper returns the number of printed characters
- `ft_printf()` accumulates that value and returns the final total

The implementation is based on a small dispatcher function that selects the correct helper for each format specifier.

The helper functions used are:

- `ft_prtchr`
- `ft_prtstr`
- `ft_prtptr`
- `ft_prtnbr`
- `ft_prtunbr`
- `ft_prthexlo`
- `ft_prthexup`

This matches the code structure you implemented: a central `ft_printf()` function, one dispatch function, and dedicated printing helpers for each data type.

---

## Implementation Notes

A few specific behaviours of this implementation are worth mentioning:

- if `format` is `NULL`, `ft_printf()` returns `-1`
- if `%s` receives a `NULL` pointer, it prints `(null)`
- if `%p` receives a null pointer, it prints `(nil)`
- decimal and hexadecimal number printing are implemented recursively
- output is written directly with `write()`
- no dynamic memory allocation is required for the mandatory part in this implementation

This keeps the project compact and close to the essentials of the assignment.

---

## Files and Structure

A minimal implementation can be organised with:

- `ft_printf.c`
- helper source files for each conversion
- `ft_printf.h`
- `Makefile`

The subject requires the library to be named `libftprintf.a` and created at the root of the repository.

---

## Instructions

### Compilation

Compile the project with:

```bash
make
```

The Makefile should provide at least the following rules:

```bash
make
make all
make clean
make fclean
make re
```

After compilation, the generated library should be:

```bash
libftprintf.a
```

### Using the library

To use `ft_printf()` in another C file:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s! Number: %d\n", "world", 42);
	return (0);
}
```

Compile an example program with:

```bash
cc main.c -L. -lftprintf -I. -o test
./test
```

---

## Example Usage

### Characters and strings

```c
ft_printf("Name: %s\n", "Hugo");
ft_printf("Letter: %c\n", 'A');
```

### Signed and unsigned numbers

```c
ft_printf("d: %d | i: %i | u: %u\n", -42, 42, 42U);
```

### Hexadecimal and pointers

```c
ft_printf("x: %x | X: %X\n", 255, 255);
ft_printf("ptr: %p\n", ptr);
```

### Literal percent

```c
ft_printf("Progress: 100%%\n");
```

---

## Technical Constraints

According to the subject, the project must:

- be written in C
- follow the Norm
- compile with `-Wall -Wextra -Werror`
- use `ar` to create the static library
- create `libftprintf.a` at the root of the repository
- use `ft_printf.h` as the header file name

Allowed external functions for the project are:

- `malloc`
- `free`
- `write`
- `va_start`
- `va_arg`
- `va_copy`
- `va_end`

Even though `malloc` and `free` are allowed, this specific implementation does not need dynamic allocation for the mandatory part.

---

## Bonus

This README describes the mandatory part only.

The bonus version of the project may include support for:

- flags `-0.`
- minimum field width
- flags `#`, space, and `+`

If those features are not implemented, it is better not to claim bonus support in the README.

---

## Testing

Useful tests for this implementation include:

- plain text without conversions
- each mandatory specifier individually
- mixed format strings
- `NULL` strings
- null pointers with `%p`
- zero values
- negative integers
- large unsigned integers
- comparison of output and return values with the real `printf()`

---

## Resources

### Classic references

- 42 ft_printf subject
- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- C documentation about variadic functions
- documentation about hexadecimal conversion and pointer formatting

### Topics related to the project

- variadic functions in C
- `va_list`, `va_start`, `va_arg`, `va_end`
- format string parsing
- recursion in number printing
- hexadecimal representation
- return value handling in `printf()`

### AI Usage

AI was used as a support tool for:

- improving README wording and structure
- summarising the project requirements
- explaining the implementation in clear English

AI was not used as a substitute for understanding the code. The implementation should always remain fully explainable during evaluation.

---

## Final Notes

This `ft_printf` implementation is a simple mandatory-part version built around a direct parser and small helper functions.

Its goal is not to reproduce the full complexity of the original `printf()`, but to correctly handle the required conversions and provide a clean reusable output function for future 42 projects.
