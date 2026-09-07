#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#define CHECK(fmt, ...) \
	do { \
		int c_printf; \
		int my_printf; \
		printf("FORMAT: [%s]\n", fmt); \
		printf("C__PRINTF: ["); \
		fflush(stdout); \
		c_printf = printf(fmt, ##__VA_ARGS__); \
		fflush(stdout); \
		printf("] RET: [%d]\n", c_printf); \
		printf("FT_PRINTF: ["); \
		fflush(stdout); \
		my_printf = ft_printf(fmt, ##__VA_ARGS__); \
		fflush(stdout); \
		printf("] RET: [%d]\n\n", my_printf); \
		assert(c_printf == my_printf); \
	} while (0);

int main()
{
	char *n;
	
	n = NULL;
	CHECK("AHOJ");
	CHECK("%d", 42);
	CHECK("%i", -42);
	CHECK("%s", "HELLO 42");
	CHECK("%c", 'x');
	CHECK("%u", 42);
	CHECK("%%");
	CHECK("%p", (void *)42);
	CHECK("%x", 42);
	CHECK("%X", 42);
	CHECK("n = %s", n);
	CHECK("unsigned -1 = %u", -1);
	CHECK("%s %c %c %c %c %d, %i, %x, %X, %p, %u 100%% OK!", "Realy long", 'L', 'i', 'n', 'e', 42*42, -42, 42, 42, (void *)42, -42);
	CHECK("\"\"\?");
	CHECK("%%%s%% %d", "HELLO", 42);
	CHECK("%p", n);
}
