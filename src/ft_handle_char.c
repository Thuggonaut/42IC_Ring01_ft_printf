#include "ft_printf.h"

int	ft_handle_char(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	char	c; //To store the character argument that will be printed

	c = va_arg(ap, int); //Retrieves the next argument from the variable argument list ap using the `va_arg` macro. See #1
	return (write(1, &c, 1)); //Writes the character c to the standard output and returns the number of bytes written.
}

/*
#1	The `int` type is used because the `%c` format specifier expects an int argument that represents a character. By assigning the
	value to a char variable, the code ensures that only the character portion of the argument is stored, discarding any additional
	information.
*/
