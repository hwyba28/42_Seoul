NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/includes/ -I$(shell brew --prefix readline)/include

LIBFT = -L libft -lft

HEADER = minishell.h

BUILTINS = cd echo env exit export_plus export pwd unset

ENV = env get_env sort_env shlvl

EXEC = bin_plus bin builtin exec

MAIN = minishell redir signal heredoc

PARSING = line tokens_plus tokens expansions

TOOLS = fd free token type expansions parsing

SRC = $(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS))) \
	  $(addsuffix .c, $(addprefix srcs/env/, $(ENV))) \
	  $(addsuffix .c, $(addprefix srcs/exec/, $(EXEC))) \
	  $(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
	  $(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
	  $(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS))) \

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline -L$(shell brew --prefix readline)/lib

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean:
	make fclean -C libft/
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

test: all
	./minishell

norm:
	norminette $(SRC) includes/$(HEADER)

.PHONY: clean fclean re test norm
