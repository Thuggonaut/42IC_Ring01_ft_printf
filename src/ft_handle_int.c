#include "ft_printf.h"

int	ft_handle_int(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	long long	n; //To store the value of the next `int` argument retrieved from `ap` for processing. `long long` because it allows for the storage of a wider range of integer values compared to `int`
	int		neg; //To keep track of whether the integer is negative

	n = va_arg(ap, int); //Retrieves the next argument of type `long long int` from `ap` and assigns it to `n`
	neg = 0;
	if (n < 0) //Checks if the integer is negative
	{
		n *= -1; //Convert it to a positive value
		neg++; //`neg` now represents the number of negative signs that will be printed (which is `1`)
		write(1, "-", 1); //Prints the negative sign to the standard output
	}
	return (ft_putnbr_base(n, "0123456789") + neg); //Prints the positive value of `n` in base 10 (decimal) and returns the number of characters printed. See #1 
}

/*
#1	By adding `neg` to the return value, the function accounts for the negative sign that was printed if `n` was negative.
	In other words, adding `neg to the return value essentially adjusts the final count of characters to include the negative sign if needed.
*/
