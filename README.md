*This project has been created as part of the 42 curriculum by hugo-mar.*

# ft_printf

## Description

**ft_printf** is a 42 project focused on recreating the behaviour of the standard C `printf()` function. The goal is to build a custom formatted output function called `ft_printf()` while learning how variadic functions work in C.

This project is an important step in the 42 curriculum because it introduces:

- variadic arguments with `stdarg.h`
- formatted output parsing
- conversion dispatching
- number-to-string conversion
- hexadecimal formatting
- pointer formatting
- output counting
- modular and extensible code design

The final result is a library named `libftprintf.a` containing an implementation of:

```c
int ft_printf(const char *format, ...);
```

According to the subject, the function must mimic the original `printf()` for the mandatory conversions and will be compared against the real `printf()`. It must be built as a static library using `ar`, and the header file must be named `ft_printf.h`.

---

## Project Goals

The main objectives of this project are:

- to understand and use variadic functions in C
- to parse a format string safely and clearly
- to dispatch each format specifier to the correct printing function
- to convert values into the appropriate textual representation
- to return the exact number of printed characters
- to write structured code that can later be extended for bonuses

The subject itself highlights that the key to a successful `ft_printf` is well-structured and extensible code.

---

## Mandatory Requirements

The mandatory part requires the implementation of the following conversions:

- `%c` prints a single character
- `%s` prints a string
- `%p` prints a pointer in hexadecimal format
- `%d` prints a signed decimal integer
- `%i` prints a signed decimal integer
- `%u` prints an unsigned decimal integer
- `%x` prints an unsigned number in lowercase hexadecimal
- `%X` prints an unsigned number in uppercase hexadecimal
- `%%` prints a percent sign

The subject also explicitly states:

- do not implement the original `printf()` buffer management
- the function will be compared against the original `printf()`
- the output library must be named `libftprintf.a`
- the library must be created at the root of the repository
- the allowed external functions are:
  - `malloc`
  - `free`
  - `write`
  - `va_start`
  - `va_arg`
  - `va_copy`
  - `va_end`

---

## How ft_printf Works

At a high level, `ft_printf()` reads the format string character by character.

### Basic execution flow

1. iterate through the format string
2. if the current character is not `%`, write it directly
3. if the current character is `%`, inspect the next character
4. determine which conversion is requested
5. fetch the corresponding argument from the variadic list
6. convert it to its textual representation if needed
7. write the result to standard output
8. keep track of the total number of printed characters
9. return that count at the end

This approach is simple, clear, and well suited to the mandatory part of the project.

---

## Chosen Algorithm and Data Structure

The subject explicitly requires a detailed explanation and justification of the chosen algorithm and data structure, so this section addresses that directly.

### Chosen algorithm

A straightforward and reliable algorithm for `ft_printf()` is a linear parser with conversion dispatch.

The parser scans the format string once from left to right. Whenever it encounters a normal character, it prints it immediately. Whenever it finds `%`, it looks at the next character and routes execution to a dedicated handler function.

Example of a common dispatch design:

- `print_char()`
- `print_string()`
- `print_pointer()`
- `print_decimal()`
- `print_unsigned()`
- `print_hex_lower()`
- `print_hex_upper()`
- `print_percent()`

### Why this algorithm makes sense

This is a good choice because:

- it matches the sequential nature of the format string
- it is easy to understand and debug
- it avoids unnecessary complexity
- it keeps the mandatory part small and maintainable
- it naturally supports future bonus extensions

Since the mandatory format is limited to a fixed set of conversions, there is no need for a more complex parsing engine.

### Chosen data structure

For the mandatory part, the most appropriate data structure is usually:

- a simple character pointer or index to walk through the format string
- a `va_list` to access variadic arguments
- possibly a small set of helper functions for each conversion

This minimal design is justified because the subject only requires a restricted subset of `printf()`. A more elaborate token structure or parser state machine would usually be unnecessary for the mandatory version.

### Optional extensible design

If the code is written with bonuses in mind, a small parser state structure can also be useful later. For example, bonus implementations may benefit from a struct that stores:

- width
- precision
- flags
- current conversion type

That said, for the mandatory part, a direct parser plus helper functions is generally the cleanest and most efficient approach.

---

## Conversion Logic

### Characters and strings

- `%c` writes one character
- `%s` writes a string
- if your implementation chooses to handle `NULL` strings defensively, it should do so consistently with expected behaviour

### Signed integers

- `%d` and `%i` print integers in base 10
- negative values must include the minus sign
- conversion often involves recursive printing or temporary string creation

### Unsigned integers

- `%u` prints numbers in base 10 without sign handling

### Hexadecimal output

- `%x` uses lowercase hexadecimal digits
- `%X` uses uppercase hexadecimal digits

### Pointers

- `%p` prints a memory address in hexadecimal
- the usual representation starts with `0x`

### Literal percent

- `%%` prints a single `%`

---

## Suggested Project Structure

A common and clean structure for the project could look like this:

```txt
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_char.c
├── ft_print_str.c
├── ft_print_ptr.c
├── ft_print_nbr.c
├── ft_print_unsigned.c
├── ft_print_hex.c
└── utils/
```

Or, if preferred, helper files can stay at the root as allowed by the subject.

The key point is modularity: each conversion or utility should be isolated enough to keep the project readable and easy to maintain.

---

## Instructions

### Requirements

You need:

- a C compiler such as `cc`
- `make`
- the project source files
- optionally your `libft`, if you integrated reusable helpers from it

### Compilation

Compile the project with:

```bash
make
```

The subject requires at least the following Makefile rules:

```bash
make
make all
make clean
make fclean
make re
```

After compilation, the generated static library should be:

```bash
libftprintf.a
```

### Using ft_printf in another project

Include the header and link the library when compiling:

```bash
cc main.c -L. -lftprintf -I.
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s! Number: %d\n", "world", 42);
	return (0);
}
```

Compile example:

```bash
cc main.c -L. -lftprintf -I. -o test
./test
```

---

## Example Usage

### Basic text

```c
ft_printf("Hello, world!\n");
```

### Character and string

```c
ft_printf("Char: %c | String: %s\n", 'A', "forty-two");
```

### Signed and unsigned numbers

```c
ft_printf("d: %d | i: %i | u: %u\n", -42, 42, 42U);
```

### Hexadecimal and pointer

```c
ft_printf("x: %x | X: %X | p: %p\n", 255, 255, ptr);
```

### Literal percent

```c
ft_printf("Progress: 100%%\n");
```

---

## Technical Considerations

Important points when implementing `ft_printf()`:

- always return the total number of printed characters
- avoid undefined behaviour caused by wrong `va_arg` types
- keep conversion handlers small and focused
- be careful with `NULL` pointers for `%s` and `%p`
- ensure hexadecimal conversion works for zero values
- handle integer edge cases correctly
- avoid memory leaks if using temporary allocations
- make helper functions reusable and easy to test

Because `ft_printf()` is often reused later in other projects, reliability matters more than cleverness.

---

## Bonus Part

The bonus part may include support for:

- any combination of the flags `-0.`
- minimum field width for all conversions
- the flags `#`, space, and `+`

The subject warns that if you want to complete the bonus part, it is smart to think about extensibility from the beginning. It also makes clear that the bonus will only be evaluated if the mandatory part is perfect.

---

## Testing

Useful things to test include:

- plain strings without conversions
- repeated consecutive conversions
- `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- zero values
- negative signed integers
- large unsigned values
- `NULL` strings and pointers where relevant
- comparison of return values against the real `printf()`
- comparison of output formatting against the real `printf()`

It is a good idea to create small custom test files and compare behaviour carefully.

---

## Resources

### Official / Classic References

- 42 ft_printf subject PDF
- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- C standard library documentation
- documentation on variadic functions in C
- classic articles and tutorials on implementing custom printf-like functions

### Recommended topics to study

- variadic functions
- `va_list`, `va_start`, `va_arg`, `va_copy`, `va_end`
- integer to string conversion
- recursion vs iterative number printing
- hexadecimal conversion
- output counting
- parsing and dispatch patterns in C

### AI Usage

AI was used as a support tool for:

- organising and writing this README
- clarifying the project requirements from the subject
- helping explain the parsing strategy and algorithm choice
- improving the wording of technical explanations
- structuring the section about the chosen algorithm and data structure

AI was not used as a blind replacement for implementation work. Any code ideas inspired by AI should be reviewed, tested, and fully understood before being included in the project.

---

## Final Notes

`ft_printf` is one of the most useful foundational projects in the 42 curriculum. It teaches how formatted output really works and forces careful thinking about parsing, argument handling, conversions, and program structure.

Once completed properly, it becomes a reusable tool for many later C projects and a strong exercise in writing clean, extensible low-level code.
