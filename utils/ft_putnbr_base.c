#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb, const char *base)
{
	unsigned long long	len;
	int					cnt;

	cnt = 0;
	len = ft_strlen(base);
	if (nb >= len)
		cnt += ft_putnbr_base(nb / len, base);
	cnt += ft_putchar(base[nb % len]);
	return (cnt);
}