#include "ft_printf.h"

int	ft_handle_percent(void) //The void parameter list indicates that the function doesn't take any arguments
{
	ft_putchar('%'); //Prints `%` to the standard output
	return (1); //`1` indicates that the function successfully handled the '%' specifier
}