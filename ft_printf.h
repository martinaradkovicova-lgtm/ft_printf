#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int	print_char(int c);
int	print_string(char *str);
int	print_int_dec(int num);
int	print_base(unsigned long num, char *base);
int	print_pointer(void *pointer);
int	set_param(const char *format, va_list *list, int i);
int	ft_printf(const char *format, ...);
int ft_strlen(char *str);
#endif
