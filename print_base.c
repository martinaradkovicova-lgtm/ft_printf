#include "ft_printf.h"

int	print_base(unsigned long num, char *base)
{
	size_t		   	base_len;
	char			c;
	int				count;
	
	count = 0;
	base_len = ft_strlen(base);
	if(num < base_len)
	{
		c = base[num];
		count += print_char(c);
	}
	else
	{
		count += print_base(num / base_len, base);
		count += print_char(base[num % base_len]);
	}
	return (count);
}
