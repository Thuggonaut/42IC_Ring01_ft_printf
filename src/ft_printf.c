#include "./includes/ft_printf.h"

static int	ft_specifier(char c, va_list ap)
{
	if (c == 'c')
		return (ft_handle_char(ap));
	if (c == 's')
		return (ft_handle_str(ap));
	if (c == 'i' || c == 'd')
		return (ft_handle_int(ap));
	if (c == 'u')
		return (ft_handle_uns(ap));
	if (c == 'p')
		return (ft_handle_pointer(ap));
	if (c == 'x')
		return (ft_handle_hexlower(ap));
	if (c == 'X')
		return (ft_handle_hexupper(ap));
	else if (c == '%')
		return(ft_handle_percent());
	return (write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	if (!format)
		return (0);
	va_start(ap, format);
	i = -1;
	cnt = 0;
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		else if (format[i] == '%')
			cnt += ft_specifier(format[++i], ap);
		else
			cnt += write(1, &format[i], 1);
	}
	va_end(ap);
	return (cnt);
}