NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I SRC

SRCS = ft_printf.c \
SRC/ft_strlen.c \
SRC/print_base.c \
SRC/print_char.c \
SRC/print_int_dec.c \
SRC/print_pointer.c \
SRC/print_string.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
