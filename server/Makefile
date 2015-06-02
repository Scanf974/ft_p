CC = gcc
NAME = serveur
CFLAGS = -Wextra -Wall -Werror

SRC_MAIN = main.c

SRC = $(SRC_MAIN)

HEADER = includes/server.h
DIR_HEADERS = -I includes/ \
			  -I ../libft/includes/

OBJ = $(SRC:%.c=../.obj/%.o)

OBJ_DIR = ../.obj/

LIBFT = -L../libft -lft


.PHONY: all libs clean fclean re

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo "\033[32mReady!\033[0m"

dor:
	@mkdir $(OBJ_DIR) 2> /dev/null || env -i

libs:
	@make -C ../libft/

../.obj/%.o: %.c $(HEADER)
	@echo "\033[33m 	$<"
	@$(CC) $(CFLAGS) -o $@ $(DIR_HEADERS) -c $< -g

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all
