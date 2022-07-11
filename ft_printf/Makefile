NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_printf \
		ft_format \
		ft_printchar \
		ft_printstr \
		ft_print_ptr \
		ft_printnbr \
		ft_print_unsigned \
		ft_print_hex \
		ft_print_percent \
		ft_putstr \
		ft_put_ptr \
		ft_ptr_len \
		ft_uitoa \
		ft_num_len \
		ft_put_hex \
		ft_hex_len \
		ft_itoa

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
