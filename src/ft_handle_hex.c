#include "ft_printf.h"

int	ft_handle_hexlower(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	unsigned int	n; //To store the value of the next argument retrieved from `ap` for processing

	n = va_arg(ap, unsigned int); //Retrieve an unsigned integer argument from `ap` and assign it to `n`
	return (ft_putnbr_base(n, "0123456789abcdef")); //Converts the unsigned integer `n` into a string representation using the provided base. See #1
}

int	ft_handle_hexupper(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789ABCDEF")); //See #1
}

/*
#1	`ft_putnbr_base()` converts an unsigned integer `n` into a string representation using a specific base. In this case, the base 
	is hexadecimal with lowercase letters.
		- The first argument passed to `ft_putnbr_base` is `n`, which represents the unsigned integer that needs to be 
		  converted.
		- The second argument passed to `ft_putnbr_base` is the string `"0123456789abcdef"`. This string serves as the base for 
		  the conversion. In hexadecimal, the base is composed of the digits 0-9 followed by lowercase letters a-f.
			* In computer science and mathematics, hexadecimal (or hex) is a numbering system that uses a base of 16. It is 
			  commonly used to represent binary values in a more compact and human-readable form. 
			* Hexadecimal digits range from 0 to 15, and since the decimal system only has digits from 0 to 9, additional 
			  symbols are needed to represent values from 10 to 15. After digit 9, the alphabetical characters a to f 					  
			  (lowercase) are used to represent the values 10 to 15, respectively.
			* So, the string "0123456789abcdef" is used as the base for the hexadecimal conversion.
		- The return value of `ft_putnbr_base` represents the resulting string after the conversion. In other words, it returns 
		  the hexadecimal representation of the unsigned integer `n` in lowercase.
*/