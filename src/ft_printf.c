#include "../includes/ft_printf.h"

static int	ft_specifier(char c, va_list ap) //Takes a character `c`, representing the format specifier, and a `va_list` variable `ap`, used to access the variable arguments passed to the ft_printf function. See #1
{
	if (c == 'c')
		return (ft_handle_char(ap));
	if (c == 's')
		return (ft_handle_string(ap));
	if (c == 'i' || c == 'd')
		return (ft_handle_int(ap));
	if (c == 'u')
		return (ft_handle_unsigned(ap));
	if (c == 'p')
		return (ft_handle_pointer(ap));
	if (c == 'x')
		return (ft_handle_hexlower(ap));
	if (c == 'X')
		return (ft_handle_hexupper(ap));
	else if (c == '%')
		return(ft_handle_percent());
	return (write(1, &c, 1)); //If the format specifier `c` doesn't match any of the specifiers in `ft_specifier()`, print the character `c` as it is to the standard output, and returns the total number of characters printed
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			break ;
		else if (*format == '%')
			count += ft_specifier(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}


int	ft_printf(const char *format, ...) //takes a format string `format` as its first argument, followed by a variable number of arguments indicated by the ellipsis `...`
{
	va_list	ap; //`ap` is an argument pointer and will be used to access the variable arguments
	int		i; //Used as a loop counter to iterate through each character of the format string
	int		count; //Keeps track of the total number of characters printed

	if (!format) //Checks if the format string is `NULL`. If it is, the function returns `0`, indicating that no characters were printed
		return (0);
	va_start(ap, format); //`ap` is initialised by `va_start()` macro, which prepares `ap` to access the variable arguments passed to `ft_printf()`
	i = -1; //`-1` not `0` because it will be incremented before accessing the first character in the string. This allows the loop to start from `index 0` when `format[++i]` is first evaluated
	count = 0;
	while (format[++i]) //Loop through each character of the format string until it reaches the end of the string. See #2
	{
		if (format[i] == '%' && !format[i + 1]) //Checks if the current character is a '%' sign and the next character is '\0'. If true, it means there is a single '%' sign at the end of the format string, indicating an incomplete format specifier
			break ; //Terminates the loop prematurely, and continues with the code that follows the loop (in this case, it's the `va_end(ap)` and `return (count)`
		else if (format[i] == '%') //Checks if the current character in the `format` string is a '%' sign, indicating a format specifier is found
			count += ft_specifier(format[++i], ap); //Calls `ft_specifier()` with the correct format specifier and adds the return value to `count`, which keeps track of the total number of characters printed.See #3
		else
			count += write(1, &format[i], 1); //If none of the previous conditions are met, the current character is a regular character. It is written to the standard output, and the return value `1`, (indicating success) is added to `count`
	}
	va_end(ap); //Cleans up `ap` using the `va_end` macro
	return (count); //Returns the total number of characters printed, which is stored in `count`
}
/*
#1	This is a static function called `ft_specifier` and is responsible for handling different format specifiers and returning the number of characters printed.
		- A static function is a function that has a "static" storage class specifier in its declaration. 
		- In C, the static keyword applied to a function limits the scope of the function to the file in which 
		  it is defined. 
		- It essentially gives the function internal linkage, meaning that it can only be accessed within the 
	  	  same source file. It is not accessible from other files or translation units.

	`ft_specifier()` checks the value of the format specifier `c` and calls corresponding functions to handle each 
	specifier. 
		- For example, if c is 'c', it calls the `ft_handle_char()` function to handle the character specifier.

#2	The `while (format[++i]`) loop iterates through each character of the format string until it reaches '\0', 
	allowing the code inside the loop to handle each character according to the specified conditions.

	Using the pre-increment operator `++i` ensures that the loop starts with the first character of the format string
	and continues until the end of the string, allowing the code inside the loop to handle each character correctly:

	- Initially, the variable `i` is set to `-1` outside the loop.

	- When the loop starts, `++i` pre-increments, the value of `i` before using it in the loop condition. 	  
	  In other words, it increases the value of `i` by `1` and then uses the updated value.

	- The expression `format[++i]` is evaluated, which retrieves the character at `index i + 1` from the 
	  format string. Since `i` was pre-incremented, it represents the next index in each iteration. This 
	  expression effectively fetches the next character in each iteration of the loop.

	- `while (format[++i])` checks if the fetched character is not ('\0') indicating the end of the string.

	- The loop continues to iterate, incrementing `i` and retrieving the next character in each iteration 
	  until it reaches the null terminator.

#3	`format[++i]` increments the value of `i` by `1` and accesses the next character in the format string. 
		- By using the pre-increment operator `++i`, the value of `i` is incremented before it is used to 
	  	  access the character. 
		- This is done to skip the '%' sign and move to the next character, which represents the format 
	  	  specifier.

	The character representing the format specifier is passed as the first argument to `ft_specifier()`.
		- This allows `ft_specifier()` to handle the appropriate action based on the format specifier.

	`ap` is passed as the second argument to `ft_specifier()`, allowing it to access the variable arguments passed 
	to `ft_printf()`.

	The return value of `ft_specifier()` is added to the count variable using the `+=` operator. 
		- This allows `count` to keep track of the total number of characters printed so far.
*/
