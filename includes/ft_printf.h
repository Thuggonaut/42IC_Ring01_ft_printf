#ifndef FT_PRINTF_H //These directives are used to prevent multiple inclusions of the header file
# define FT_PRINTF_H //They check if the FT_PRINTF_H macro is not defined and then define it, ensuring that the content within the #ifndef and #endif blocks is processed only once

# include <stdlib.h> //Provides functions for dynamic memory allocation, process control, and other general-purpose utilities
# include <stdarg.h> //Contains macros and functions to work with variadic arguments
# include <unistd.h> //Provides access to various operating system services, including I/O operations such as write()
# include <stdio.h> //Provides functions for standard input/output operations

int		ft_printf(const char *format, ...); //The recreation of printf(). Takes in a format string, and a variable number of arguments
int		ft_handle_char(va_list ap); //Handles the %c format specifier
int		ft_handle_string(va_list ap); //Handles the %s format specifier
int		ft_handle_int(va_list ap); //Handles the %d and %i format specifiers
int		ft_handle_unsigned(va_list ap); //Handles the %u format specifier
int		ft_handle_pointer(va_list ap);
int		ft_handle_hexlower(va_list ap);
int		ft_handle_hexupper(va_list ap);
int	  ft_handle_percent(void);
size_t  ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr_base(unsigned long long nb, const char *base);

#endif
