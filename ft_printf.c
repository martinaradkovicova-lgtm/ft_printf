#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_putnbr(int nbr)
{
	long nb;
	char c;

	nb = nbr;
	if(nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if(nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void unsigned_putnbr(unsigned int nbr)
{
	char c;
	
	if (nbr <= 9)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		unsigned_putnbr(nbr / 10);
		unsigned_putnbr(nbr % 10);
	}
}

void putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	c;
	long	nb;
	
	nb = nbr;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if(nbr < base_len)
	{
		c = base[nb];
		write(1, &c, 1);
	}
	else
	{
		putnbr_base(nb / base_len, base);
		write(1, &base[nb % base_len], 1);
	}
}

void print_void(void *pointer)
{
	unsigned long p;

	p = (unsigned long)pointer;
	if (pointer == NULL)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		putnbr_base(p, "0123456789abcdef");
	}
}

int	ft_printf(const char *format, ...);

int main ()
{
	int ret;

	//ret = -547;
	//ft_putnbr(ret);
	
	ret = ft_printf("a%c b%%%s %d, %i %u HEX: %X, hex: %x, pouinter %p\n", 'X', "string", 87, 95, -100, 15, 14, (void *)42);
	ret = printf("%p\n", (void *)0);
	printf("%i\n", ret);
	
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int i;
	va_list	print_list;
	
	va_start(print_list, format);
	i = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ft_putchar(va_arg(print_list, int));
			else if(format[i + 1] == 's')
				ft_putstr(va_arg(print_list, char *));
			else if(format[i + 1] == '%')
				ft_putchar(format[i]);
			else if(format[i + 1] == 'i' || format[i + 1] == 'd')
				ft_putnbr(va_arg(print_list, int));
			else if(format[i + 1] == 'u')
				unsigned_putnbr(va_arg(print_list, unsigned int));
			else if(format[i + 1] == 'X')
				putnbr_base(va_arg(print_list, int), "0123456789ABCDEF");
			else if(format[i + 1] == 'x')
				putnbr_base(va_arg(print_list, int), "0123456789abcdef");
			else if (format[i + 1] == 'p')
				print_void(va_arg(print_list, void *));
			else
				ft_putchar(format[i+1]);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(print_list);
	return (5);
}
