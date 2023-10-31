NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -I includes/

#HEADER = $(addsuffix .h, $(addprefix includes/, libutils get_next_line ft_printf))

FT = atoi isalnum isdigit itoa memdel nbrlen power putendl_fd \
		putendl putstr_fd putstr skip_space skip_spacenl split strchr \
		strcmp strdup strisnum strjoin strlen strncmp strnstr

SRC = $(addsuffix .c, $(addprefix ft_, $(FT)))

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all clean fclean re norm
