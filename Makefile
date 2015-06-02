CFLAGS = -Wextra -Wall -Werror
SERVER_NAME = serveur
CLIENT_NAME = client

.PHONY: client serveur all clean fclean re

all: serveur

serveur:
	make -C server/
