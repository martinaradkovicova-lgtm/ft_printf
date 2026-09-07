#include "ft_printf.h"

int	set_param(const char *format, va_list *print_list, int i)
{
	int count;

	count = 0;
	if (format[i + 1] == 'c')
		count += print_char(va_arg(*print_list, int));
	else if(format[i + 1] == 's')
		count += print_string(va_arg(*print_list, char *));
	else if(format[i + 1] == '%')
		count += print_char(format[i]);
	else if(format[i + 1] == 'i' || format[i + 1] == 'd')
		count += print_int_dec(va_arg(*print_list, int));
	else if(format[i + 1] == 'u')
		count += print_base(va_arg(*print_list, unsigned int), "0123456789");
	else if(format[i + 1] == 'X')
		count += print_base(va_arg(*print_list, int), "0123456789ABCDEF");
	else if(format[i + 1] == 'x')
		count += print_base(va_arg(*print_list, int), "0123456789abcdef");
	else if (format[i + 1] == 'p')
		count += print_pointer(va_arg(*print_list, void *));
	else
		count += print_char(format[i+1]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int 	i;
	va_list	print_list;
	int		count;
	
	va_start(print_list, format);
	i = 0;
	count = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += set_param(format, &print_list, i);	
			i += 2;
		}
		else
		{
			count += print_char(format[i]);
			i++;
		}
	}
	va_end(print_list);
	return (count);
}
