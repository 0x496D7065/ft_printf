*This project has been created as part of the 42 curriculum*

# ft_printf

## Description

ft_printf is a re-implementation of the C standard library function `printf`. It parses a format string and prints formatted output to standard output, returning the number of characters written. The project is built as a static library, `libftprintf.a`.

## Supported conversions

| Specifier | Output |
|---|---|
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal percent sign |

## Instructions

### Build

```bash
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # rebuilds everything
```

### Usage

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old (0x%x)\n", "world", 42, 42);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -o my_program
```

## Project structure

```
.
├── Makefile
├── ft_printf.h        # prototypes and includes
├── ft_printf.c        # format string parsing and dispatch
├── ft_print_hexa.c    # %x and %X
├── ft_print_ptr.c     # %p
└── ft_printf_aux.c    # helpers (characters, strings, integers)
```

## Implementation notes

- The format string is read one character at a time. Each `%` is followed by a conversion specifier, which is dispatched to the matching print function.
- Variable arguments are handled with `<stdarg.h>` (`va_list`, `va_start`, `va_arg`, `va_end`).
- Every print function returns the number of characters it wrote, and `ft_printf` sums these to produce its return value.

## Resources

- `man 3 printf` and `man 3 stdarg`
- [GNU C Library: Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
