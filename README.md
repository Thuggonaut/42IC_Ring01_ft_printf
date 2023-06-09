# 🖨️ 42_IC_Ring01_ft_printf

## Preface:
- This ft_printf project is completed without the bonus.
- The subject.pdf requires a recode of the printf() function from libc, without implementing the buffer management of the original printf().
- Our ft_printf.c must handle the following conversions: c, s, p, d, i, u, x, X, %.
- The following consists of how I tackled this project, which includes drafting a plan about what I needed to learn, and where to begin. 
- Notes are included.

## 🔷 Outline of the Plan:
- Step 1: [Learn the original prinft() function](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#step-1-learn-the-original-prinft-function)
- Step 2: [Learn about Variadic functions](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#-step-2-learn-about-variadic-functions)
- Step 3: [Write the structure of directories/source files (tree)](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#-step-3-write-the-structure-of-directoriessource-files-tree)
- Step 4: [Create the directories](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#-step-4-create-the-directories)
- Step 5: [Write the ft_printf.h header file](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#-step-5-write-the-ft_printfh-header-file)
- Step 6: [Write the format specifier handler and utility (helper functions) source files](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#-step-6-write-the-fprmat-specifier-handler-and-utility-helper-functions-source-files)
- Step 7: [Write the ft_printf.c source file](https://github.com/Thuggonaut/42IC_Ring01_ft_printf/blob/master/README.md#-step-7-write-the-ft_printfc-source-file)
- Step 8: Write the Makefile
- Step 9: Compile the library of ft_printf()
- Step 10: Test the ft_printf() against the original printf()

## 🔷 Step 1: Learn the original prinft() function:
1. `printf()` is used to print formatted output to the standard output stream.
    - The ***'f'*** in ***'printf'*** refers to ***'formatted string'*** and which is surrounded by double quotes ***"  "***.
2. It is defined in the standard C library ***'stdio.h'***.
3. The prototype is:

    `int printf(const char  *format, ...);`

4. `printf()` returns an ***'int'*** value representing the number of characters printed (excluding the null terminator). It returns a negative value if an error occurs. <sub>Note: My ft_printf() did not account for this. However, I still passed Moulinnette with 100%</sub>
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


## 🔷 Step 2: Learn about Variadic functions
### 🔸Variadic functions
1. Is a function that takes a variable number of arguments at runtime, such as `printf` that takes any number of arguments, and formats them into a string according to a ***'format string'***. 
2. Key features of a variadic function includes: 
    - the `stdarg.h` header file
    - the `va_list ` data type
    - the `va_start()`, `va_arg`, `va_copy` and `va_end` macros. <sub>Note: Our ft_printf() does not need to call the `va_copy` macro</sub>


### 🔸 stdarg.h header file
1. Provides a set of macros and data types that allow you to work with variable-length argument lists.
    - A variable argument list is a mechanism that alows a function to accept a variable number of arguments of different types. 
2. A variable argument list is declared using the elipsis `...` as the last parameter in the function prototype, and indicates that a variable number of arguments of any type, will be accepted.
3. In a function with variable-length arguments, the number and types of arguments are not known at compile time, so they're unable to be explicitly declared. 
    - In C, the compiler needs to know the number and types of arguments of a function in order to generate the correct code for the function.
    - When declaring a function with fixed parameters, the number and types of parameters are known at compile time, so the compiler can generate the appropriate code. 
        - For example, suppose we declare a function called `int    average(int num, ...);` to take a number of arguments of type `int`, in order to calculate the average of the sum.
        - We may call the function as  `average(5,     1, 2, 3, 4, 5);`
        - `5` tells us there will be five arguments following, all of which are type   `int`. 
    - In a function with variable-length arguments however, this is unknown at compile time. Instead, the function relies on runtime information to determine the number and types of arguments passed in. 
        -   This is where the `stdarg.h` library comes in, and is used to access the arguments through a `va_list` object (a pointer that points to a variable-length argument list).
4. `stdarg.h` defines three important macros that are used for working with variable-length argument lists.
    - `va_start()` is used to initialise the variable-length argument list.
    - `va_arg()` is used to access the variable-length argument list.
    - `va_end()` is used to terminate the variable-length argument list.


### 🔸 va_list data type
1. The `va_list` data type represents a variable-length argument list. 
2. It is used to create a list of arguments because recall, the number and types of the arguments are not known at compile time. 
3. `va_list` is implemented as a pointer to a memory location where the arguments are stored.
4. Because the compiler doesn't know in advance how many arguments will be passed, or what their types are, to handle this, the ***'stack'*** is used to store the arguments in memory at runtime (execution from when the program is launched, to when the program is terminated).
    - The ***'stack'*** is a region of memory used to store temporary variables and function call frames during program execution.
5. To use `va_list`, you first need to declare a variable type `va_list` in the function that uses it.
    - For example;
        ```
        void    my_printf(const char *format, ...)
        {
            va_list     arg_ptr;
            
            //Rest of the function
        }
        ```
6. Once the `va_list` variable is declared, you need to initialize it using the `va_start()` macro.


### 🔸 va_start() macro
1. The `va_start()` macro initializes the `va_list` variable with the arguments passed into a variadic function (such as `printf()`). 
2. It is neccessary to call `va_start()` at the beginning of the function, to properly initialize the `va_list` object, making it ready for access. 
3. `va_start()` takes two arguments:
    - The `va_list` variable that points to the variable-length argument list
    - The name of the last named parameter of the function.
        - It is important for  `va_start()` to know the last named parameter, because it uses its memory location to determine the location of the first variable argument:
        ```
        #include <stdarg.h>
        #include <stdio.h>

        void    my_prinft(const char *format, ...)      
        {
            va_list     arg_ptr;                        
            va_start(arg_ptr, format);                  
                                                          
            //Access the variable-length argument
            //Clean up the variable-length argument
        }
        ```
        - There is only one named parameter here, making `format` the  last
        - A `va_list` variable pointer is declared called `arg_ptr`
        - `va_start()` uses the address of `format` as a reference point
        - It then sets the `arg_ptr` to point to the address, where the variable-length argument list should begin (the memory location right after where `format` is)  


4. After the `va_list arg_ptr` has been initialized, each of its variable argument is now ready to be accessed using the `va_arg()` macro.


### 🔸 va_arg() macro
1. `va_arg()` is used to retrieve each individual argument from the variable-length argument list. 
2. It takes two arguments:
    - The `va_list` variable pointer that points to the variable-length argument list
    - The data type of the next argument in the variable-length argument list
3. As `va_arg()` retrieves the next argument from the variable-length argument list, it returns its value, before advancing the `va_list` pointer to point to the next argument in the process.
    - The data type passed as the second argument of `va_arg()` must match the type of the next argument in the variable-length argument list. 
4. Example of how to use `va_arg()`:
    ```
    #include <stdio.h>
    #niclude <stdarg.h>

    void    print_ints(int count, ...)      
    {
        va_list     args;
        va_start(args, count);

        int     i = 0;
        while (i < count)
        {
            int arg = va_arg(args, int);
            printf("%d ", arg);
            i++;
        }
        va_end(args);
    }

    int main()
    {
        print_ints(3,   1, 2, 3);
        return (0);
    }
    ```
    - Define a function called `print_ints` that takes a variable number of arguments
    - The first argument is an integer named `count` that specifies the number of arguments to follow in the variable argument list
    - Recall, the elipsis `...` indicates there will be additional variable arguments
    - Declare a `va_list` variable pointer called `args`, that will point to the variable argument list
    - `va_start()` initializes `args`. It uses the address of `count` as a reference point and sets `args` to point to the first variable argument (the memory location right after `count`)
    - The variable arguments are now ready to be accessed by `va_arg()`
    - The `while` loop runs `count` number of times, each time iterating over, and retrieving each integer argument using `va_arg()`
    - `va_arg()` takes in as arguments, the argument pointer `args`, and the data type of the next argument `int`
    `printf()` prints the integer argument and a space
    - `va_end()` is called to signal the end of the variable argument list.
    - In the main, `printf()` is called three times, each time printing out an integer value


### 🔸 va_end() macro
1. `va_end()` is used to indicate you are finished processing a variable-length argument list.
2. It's necessary to call `va_end()` at the end of a variadic function to clean up the `va_list` variable.
    - When you use `va_start()` to initialize a `va_list` variable pointer, the system needs to do some "book-keeping" (keeping track of information such as: the starting address of the argument list; the type and size of each argument; the number of arguments), to set up the processing of the variable arguments.
    - `va_end()` tells the system you are done processing variable arguments, and to "clean up" the `va_list` variable. 
    - This "clean up' involves de-allocating any resources that were allocated to support the variable argument processing.
3. `va_end()` takes one argument: the `va_list` variable, that is to be cleaned up.
4. Example of how to use `va_end()`:
    ```
    #include <stdio.h>
    #niclude <stdarg.h>

    void    print_strings(int count, ...)      
    {
        va_list     args;
        va_start(args, count);

        int     i = 0;
        while (i < count)
        {
            char *str = va_arg(args, char *);
            printf("%s ", str);
            i++;
        }
        va_end(args);
    }

    int main()
    {
        print_strings(3, "hello", "world", "!")
        return (0);
    }
    ```
    - Define a function `print_strings()` that takes an integer named `count` and a variable number of arguments `...`
    - `count` specifies how many additional arguments will be passed into `print_string()`
    - Declare a `va_list` variable pointer named `args` that will point to the variable argument list
    - `va_start()` initializes `args` and sets `args` to point to the first variable argument from the list (the memory location right after `count`)
    - The `while` loop iterates over the variable arguments `count` number of times
    - `va_arg()` is used to retrieve the next argument from `args`
    - Since we know that all the arguments are strings, we cast the argument to type `char *` because it is a pointer type that points to an array of characters (a string)
    - `printf()` prints the string before incrementing the loop counter `i`
    - `va_end()` cleans up `args`
    - In the main, `printf()` is called three times, each time printing out a string, and outputting `hello world !`


## 🔷 Step 3: Write the structure of directories/source files (tree)
```
ft_printf/
│
├── Makefile
│
├── includes/
│   └── ft_printf.h 
│
├── srcs/
│   ├── ft_handle_char.c
│   ├── ft_handle_int.c
│   ├── ft_handle_pointer.c
│   ├── ft_handle_string.c
│   ├── ft_handle_unsigned.c
│   ├── ft_handle_hex.c
│   ├── ft_handle_percent.c
│   └── ft_printf.c
│
└── utils/
    ├── ft_putchar.c
    ├── ft_putnbr_base.c     //We need a function to convert a number to a hexadecimal string for the "%x, %X" specifiers
    └── ft_strlen.c
```


## 🔷 Step 4: Create the directories
1. Create the ft_printf/, includes/, srcs/ and utils/ directories in iTerm.


## 🔷 Step 5: Write the ft_printf.h header file
1. Inside the includes/ directory, write the header file: `ft_printf.h`
    - `ft_printf.h` will contain the necessary prototypes and declarations for your ft_printf function. 


## 🔷 Step 6: Write the format specifier handler and utility (helper functions) source files
### 🔸 The conversion source files
1. Inside the srcs/ directory, write the srcs files to handle each format specifier:
    - `ft_handle_char.c`: The function that handles the %c specifier.
        - `%c` Prints a single character.
    - `ft_handle_string.c`: The function that handles the %s specifier.
        - `%s` Prints a string (as defined by the common C convention).
    - `ft_handle_int.c`: a single conversion function that handles both %d and %i specifiers:
        - `%d` Prints a decimal (base 10) number.
        - `%i` Prints an integer in base 10.
    - `ft_handle_pointer.c`: The function that handles the %p specifier.
        - `%p` The void * pointer argument has to be printed in hexadecimal format.
    - `ft_handle_unsigned.c`: The function that handles the %u specifier.
        - `%u` Prints an unsigned decimal (base 10) number.
    - `ft_handle_hexadecimal.c`: The function that handles the %x and %X specifiers.
        - `%x` Prints a number in hexadecimal (base 16) lowercase format.
        - `%X` Prints a number in hexadecimal (base 16) uppercase format.
    - `ft_handle_percent.c`: The function that handles the %% specifier.
        - `%%` Prints a percent sign.


### 🔸 The utility source files
1. Inside the utils/ directory, write the utility (helper functions) source files:
    - `ft_putnbr_base.c`: converts a number and writes said number in a specified base, e.g. base 16.
    - `ft_putchar.c`: writes a single character.
    - `ft_strlen.c`: calculates the length of a string


## 🔷 Step 7: Write the ft_printf.c source file
1. Inside the srcs/ directory, write a file called `ft_printf.c`. 
    - This file will contain the main ft_printf function.
2. Start by including the necessary header file `ft_printf.h` which contains the function prototypes and required definitions.
3. Define a function (e.g. 'ft_specifier') that takes a character `c` representing the format specifier and a `va_list` variable pointer, used to access the variable arguments passed to the `ft_printf()` function. 
    - This function determines the appropriate handling function based on the format specifier and calls it with the `va_list` variable pointer argument.
    - Use conditional statements (such as `if`) to check the value of the format specifier character `c`. 
    - Depending on the value, call the corresponding handling function, such as `ft_handle_char()` for `c`, `ft_handle_string()` for `s`, `ft_handle_int()` for `i` or `d`, and so on. 
    - If the format specifier does not match any of the format specifiers, use the `write()` function to print the character `c` as it is, to the standard output and return the total number of characters printed.
4. Define the `ft_printf()` function that combines the ***'format string'*** and variable arguments to produce formatted output according to the specified format specifiers.
    - The `ft_printf()` function serves as the entry point for using the `ft_printf` functionality. 
    - It takes a ***'format string'*** `const char *format` as its first argument, which specifies the format of the output, and additional variable arguments `...` that correspond to the format specifiers in the ***'format string'***.
    - When you call the `ft_printf` function, you provide a ***'format string'*** that specifies how the output should be formatted, and you can pass any number of additional arguments that will be used to fill in the placeholders `%` in the ***'format string'***.
    - The `ft_printf` function processes the ***'format string'***, replaces the placeholders with the corresponding values from the variable arguments, and prints the formatted output to the standard output. 
    - It then returns the total number of characters printed.
5. Inside the `ft_printf` function, declare a `va_list` variable pointer (e.g. 'ap') and an integer variable (e.g 'count') to keep track of the number of characters printed.
    - Recall, you need to declare the variable type `va_list` (pointer to a variable argument list) in the function that uses it, in this case, it is the `ft_printf.c` source file, (which takes in a variable-length argument list `...`).
6. Start the variable argument processing by calling `va_start` with the `va_list` variable pointer, and the last named parameter of `ft_printf()`.
    - For example, `va_start(ap, format);`
7. Use a `while` loop to iterate through each character in the ***'format string'*** until the end of the ***'format string'*** is reached.
    - Inside the loop, check if the current character in the ***'format string'*** is a `%` placeholder character
    - Check if the next character after the `%` placeholder exists. If it doesn't exist, the format specifier is incomplete and the function should ***"break"*** out of the `while` loop.
    - If the current character is a `%` placeholder character, and the next character exists:
        - Increment the ***'format string'*** to skip the `%` placeholder character
        - Then, call `ft_specifier` with the next character as the ***'format specifier'*** (e.g. 'char c') and the `va_list` variable pointer (e.g. 'ap') as the argument. 
        - Add the return value of `ft_specifier` to the integer variable (e.g. 'count') that keeps track of the number of characters printed.
    - If the current character is not a `%` placeholder character, use the `write()` function to print the current character of the ***'format string'*** to the standard output and increment the counter (e.g. 'count') by 1.
    - After each iteration, increment the ***'format string'*** to move to the next character in the ***'format string'***.
8. After the loop ends, call `va_end()` to clean up the variable argument processing.
9. Finally, return the total count of characters printed (e.g. 'count').


## 🔷 Step 8: Write the Makefile

## 🔷 Step 9: Compile the library of ft_printf

## 🔷 Step 10: Test the ft_printf() against the original printf
