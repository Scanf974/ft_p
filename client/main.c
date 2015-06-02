#include <client.h>

static void	ft_usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <addr> <port>\n");
	exit(1);
}

static int	ft_create_client(char *addr, int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in		sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		exit(2);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("Error: connect", 2);
		exit(3);
	}
	return (sock);
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;

	if (ac != 3)
		ft_usage(av[0]);
	port = ft_atoi(av[2]);
	sock = ft_create_client(av[1], port);
	write(sock, "Bonjour\n", 8);
	close(sock);
	return (0);
}
