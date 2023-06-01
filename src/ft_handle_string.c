#include "ft_printf.h"

int	ft_handle_string(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	char	*s; //To store the next `string` argument retrieved from `ap` for processing
	int		i; //To be used as a loop counter

	s = va_arg(ap, char *); //Retrieves the next `char` argument from `ap` and assigns it to `s` 
	if (!s) //Checks if `s` is a null pointer
		return (write(1, "(null)", 6)); //Writes the string "(null)" to the standard output. `6` specifies the number of characters to write because "(null)" is a string literal with 6 characters
	i = 0;
	while (s[i]) //Loop until the end of the string is reached
		write(1, &s[i++], 1); //Write to the standard output, the character at index `i` in the string `s`. Then, using the `i++` post-increment, move to the next character of `s` for processing
	return (i); //Return the number of characters written
}
