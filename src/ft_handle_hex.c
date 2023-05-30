#include "ft_printf.h"

int	ft_handle_hexlower(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789abcdef"));
}

int	ft_handle_hexupper(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789ABCDEF"));
}
