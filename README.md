# 42_IC_Ring01_ft_printf

## Preface:
- This ft_printf project is completed without the bonus.
- The subject.pdf requires a recode of the printf() function from libc, without implementing the buffer management of the original printf().
- Our ft_printf.c must handle the following conversions: c, s, p, d, i, u, x, X, %.
- The following consists of how I tackled this project, which includes drafting a plan about what I needed to learn, and how I could start. 
- Notes are included.

## Outline of the Plan:
- Step 1: [Learn the original prinft() function](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#step-1-learn-the-original-prinft-function)
- Step 2: Learn about Variadic functions
- Step 3: Write the structure of directories/source files (tree)
- Step 4: Create the directories
- Step 5: Write the ft_printf.h header file
- Step 6: Write the conversion and utility (helper functions) source files
- Step 7: Write the ft_printf.c source file
- Step 8: Write the Makefile
- Step 9: Compile the library of ft_printf
- Step 10: Test the ft_printf() against the original printf

## Step 1: Learn the original prinft() function:
1. `printf()` is used to print formatted output to the standard output stream.
    - The ***'f'*** in ***'printf'*** refers to ***'formatted string'*** and which is surrounded by double quotes ***"  "***.
2. It is defined in the standard C library ***'stdio.h'***.
3. The prototype is:

    `int printf(const char  *format, ...);`

4. `printf()` returns an ***'int'*** value representing the number of characters printed (excluding the null terminator). It returns a negative value if an error occurs. <sub>Note: My ft_printf() did not account for this</sub>
    - `const char  *format` is a pointer to a ***'format string'*** specifying the format of the output. 
        - The ***'format string'*** contains placeholders (% specifiers) that are replaced by the corresponding values specified in subsequent arguments.
        - The ***'%'*** placeholders are followed by a format specifier character, specifying the type of the argument to be printed.
            - For example, `%c` for character, `%i` for int, and `%s` for string.
            - `%` means, "colloquially plug in some value here".
            - If your ***'format string'*** has two or more `%` placeholders, it'll plug the first variable argument into the first `%`, then the second variable argument to the second `%`, and so on and so forth, in a left --> right order of operations.
            - Escape characters such as newline `\n` and tab `\t` are supported.
            - For example, `printf("My name is %s\n I am %i years old\n", name_variable, age_variable);` 
    - `...` is an ellipsis indicating that `printf()` accepts a variable number of arguments. 
        - These additional arguments correspond to the values that will replace the placeholders in the format string.
5. `printf()` is a ***'variadic function'***, meaning it can accept a different number of arguments based on the ***'format string'*** provided.


## Step 2: Learn about Variadic functions
🔸 **Variadic functions**
1. Is a function that takes a variable number of arguments at runtime, such as `printf` that takes any number of arguments, and formats them into a string according to a ***'format string'***. 
2. Key features of a variadic function includes: 
    - the `stdarg.h` header file
    - the `va_list ` data type
    - the `va_start()`, `va_arg`, `va_copy` and `va_end` macros

### stdarg.h header file
- Provides a set of maros and data types that allow you to work with variable-length argument lists.
- 


4.	Structure:

ft_printf/
│
├── Makefile
│
├── .gitignore
│
├── includes/
│   ├── ft_printf.h (define lookup_table here)
│   └── libft.h
│
├── libft/
│   ├── Makefile
│   ├── src/
│   ├── libft.h
│   └── libft.a
│
├── srcs/
│   ├── ft_printf.c
│   ├── ft_parse.c
│   ├── ft_convert.c
│   ├── ft_utils.c
│   ├── ft_handle_char.c
│   ├── ft_handle_int.c
│   ├── ft_handle_pointer.c
│   ├── ft_handle_decimal.c
│   ├── ft_handle_string.c
│   ├── ft_handle_unsigned.c
│   ├── ft_handle_hexadecimal.c
│   ├── ft_handle_percent.c
│   ├── ft_handle_width.c
│   ├── ft_handle_precision.c
│   └── ft_handle_flags.c
│
├── main.c (optional)
│
└── libftprintf.a

5.	Create the ft_printf/, includes/, libft/ and srcs/ directories

6.	Inside the includes directory, create two header files: libft.h and ft_printf.h
o	libft.h will contain all the necessary function prototypes from your libft library, while 
o	ft_printf.h will contain the necessary prototypes and declarations for your ft_printf function. Define the lookup_table here, that returns the appropriate conversion function based on the specifier character.

7.	Inside the libft directory, create a header file called libft.h
o	Include the Makefile 
o	Include all the libft source files in src/.
o	Compile using ar.

8.	Inside the srcs/, create a file called ft_printf.c. 
o	This file will contain the main ft_printf function.
o	Write a basic version of the ft_printf function that can handle simple string printing. 
o	Start by writing the necessary #include statements for the ft_printf.h and libft.h header files, and then 
o	Write a basic loop that reads the format string and prints out any non-format characters it finds.

9.	Create the srcs files to handle each conversion specifier:
o	ft_parse.c: contains functions for parsing the format string and extracting the relevant information, such as the format flags, width, precision, and specifier.
o	ft_convert.c: contains the conversion functions for each of the supported specifiers, such as ft_handle_char, ft_handle_string, ft_handle_int, etc. These functions are called by the lookup table based on the specifier character.
o	ft_handle_char.c: The function that handles the %c specifier.
%c Prints a single character.
o	ft_handle_string.c: The function that handles the %s specifier.
%s Prints a string (as defined by the common C convention).
o	ft_handle_int.c: a single conversion function that handles both %d and %i specifiers:
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
o	ft_handle_pointer.c: The function that handles the %p specifier.
%p The void * pointer argument has to be printed in hexadecimal format.
o	ft_handle_unsigned.c: The function that handles the %u specifier.
%u Prints an unsigned decimal (base 10) number.
o	ft_handle_hexadecimal.c: The function that handles the %x and %X specifiers.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
o	ft_handle_percent.c: The function that handles the %% specifier.
%% Prints a percent sign.
o	ft_handle_flags.c: The function that handles the -0. flags.
o	ft_handle_width.c: The function that handles the minimum field width.
o	ft_handle_precision.c: The function that handles the precision field.

o	NOTE:
The functions ft_handle_flags, ft_handle_width, and ft_handle_precision are typically called by the conversion functions for handling the respective flags and fields.
For example, the conversion function for %d specifier may call ft_handle_flags to handle the flags like - or 0, ft_handle_width to handle the minimum field width, and ft_handle_precision to handle the precision field.
These functions are not part of the lookup table, but they are used in conjunction with the lookup table to implement the conversion functions for each specifier.

10.	Write the Makefile

11.	Create the library “libftprintf.a” using ar:
o	When you run the make command, your Makefile should compile all the necessary source files into object files and then use the ar command to create the libftprintf.a

12.	Test against the original printf()
