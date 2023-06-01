#include "ft_printf.h"

int	ft_handle_pointer(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	void	*n; //To store the address of any data type. `void*` because he specific data type of the pointer is not known in advance

	n = va_arg(ap, void *); //Retrieves the next argument from `ap` and assigns it to `n`
	write(1, "0x", 2); //Writes the characters "0x" to the standard output. See #1
	return (ft_putnbr_base((unsigned long long)n, "0123456789abcdef") + 2); //Converts the pointer value `n` to its hexadecimal representation and prints it. See #2
}

/*
`ft_handle_point()` takes a pointer argument, prefixes it with "0x", converts it to a hexadecimal representation using 
`ft_putnbr_base()`, and returns the number of characters printed.

#1	In C programming, it is common to use the prefix "0x" when representing hexadecimal numbers, especially when dealing with 
	memory addresses stored in pointers. 
		- The "0x" prefix indicates that the subsequent characters represent a hexadecimal value.

	`write(1, "0x", 2);` writes the characters "0x" to the standard output (file descriptor 1). 
		- `2` is the specified number of character to write because "0x" is a string literal with two characters: '0' and 'x'. 

	By writing "0x" before printing the hexadecimal representation of a pointer, it helps convey that the following characters 
	represent a memory address in hexadecimal format. 
		- For example, if the pointer value is 0x12345678, the output would be 0x12345678.

	The "0x" prefix is not required for representing hexadecimal numbers, but it is a convention that makes it easier to identify
	and interpret the value as a memory address or hexadecimal value.
	
#2	`ft_putnbr_base()` function is being used to convert the pointer value `n` to its hexadecimal representation. It takes 
	an `unsigned long long` integer and converts it to a string representation in the specified base.
	
	The first argument passed to `ft_putnbr_base` is `(unsigned long long)n`. 
		- This is a typecast of the pointer value `n` to an `unsigned long long` integer. 
		- The purpose of this typecast is to ensure that the function receives an appropriate numerical value to convert.

	The second argument passed to ft_putnbr_base is the base string "0123456789abcdef". 
		- This string represents the set of characters used in hexadecimal numbers (digits 0-9 and letters a-f).

	`ft_putnbr_base` converts the given numerical value to a string representation using the specified base. 
		- For example, if the pointer value is `0x123`, the function would convert it to the string `"123"` in hexadecimal.

	`ft_putnbr_base` returns the number of characters printed (i.e., the length of the resulting string). 
		- The `+ 2` part of the line `return (ft_putnbr_base((unsigned long long)n, "0123456789abcdef") + 2);` adds 2 to this
		  length.
		- The addition of `2` is necessary to account for the `"0x"` prefix that was written to the standard output before 
		  calling `ft_putnbr_base`. Since `"0x"` is always printed as part of the pointer representation, it should be included 
		  in the total count of characters printed.

	Finally, the return statement returns the total number of characters printed from the `ft_handle_pointer` function. This count 
	includes both the characters returned by `ft_putnbr_base` and the "0x" prefix. The calling code can then use this information as 
	needed.
*/
