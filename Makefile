CFLAGS = -Wextra -Wall -Werror
SERVER_NAME = serveur
CLIENT_NAME = client

.PHONY: client serveur all clean fclean re

all: serveur client

serveur:
	@make -C server/

client:
	@make -C client/
