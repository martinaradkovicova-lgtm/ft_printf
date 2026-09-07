#include "ft_printf.h"

int print_pointer(void *pointer)
{
	unsigned long	p;
	int				count;

	count = 0;
	p = (unsigned long)pointer;
	if (pointer == NULL)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += print_base(p, "0123456789abcdef");
	}
	return (count);
}
