#include "ft_printf.h"

int	print_string(char *str)
{
	int	i;
	int	count;

	if (str == NULL)
		return (print_string("(null)"));
	count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		count += print_char(str[i]);
		i++;
	}
	return (count);
}
