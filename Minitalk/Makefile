all:
	@cd utils && make all
	@gcc -Wall -Wextra -Werror src/server.c utils/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror src/client.c utils/libftprintf.a -o client

clean:
	@cd utils && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd utils && make fclean

re: fclean all
