NAME = push_swap

SRC = ft_atoi.c\
	array.c\
	push_stack.c\
	rotate_stack.c\
	swap_stack.c\
	sort.c\
	sort_max.c\
	sort_max_help.c\
	sort_push.c\
	create_list.c\
	push_swap.c

OBJ = $(SRC:.c=.o)

HDRS = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(HDRS) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
