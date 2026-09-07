#include "ft_printf.h"

int	print_int_dec(int num)
{
	long	nb;
	char	c;
	int		count;

	count = 0;
	nb = num;
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		c = nb + '0';
		count += print_char(c);
	}
	else
	{
		count += print_int_dec(nb / 10);
		count += print_int_dec(nb % 10);
	}
	return (count);
}
