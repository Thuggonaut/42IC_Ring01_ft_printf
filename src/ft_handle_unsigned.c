#include "ft_printf.h"

int	ft_handle_unsigned(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	unsigned int	n; //To store the value of the next `unsigned int` argument retrieved from `ap` for processing

	n = va_arg(ap, unsigned int); //Retrieves the next `unsigned int` argument from `ap` and assigns it to `n`
	return (ft_putnbr_base(n, "0123456789")); //Prints the value of `n` in base 10 (decimal) and returns the number of characters printed
}
