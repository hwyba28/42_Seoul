NAME = libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

SRCS = ft_printf_general.c \
		ft_printf.c \
		ft_itoa.c \
		ft_print_unsigned_int.c \
		ft_print_hex.c \
		ft_putchar_fd.c \
		ft_appendc.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_print_ptr.c
		
OBJS = ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY: all clean fclean re
