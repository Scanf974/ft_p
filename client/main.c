#include <client.h>

static void	ft_usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <port>\n");
	exit(1);
}

static int	ft_create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("Error: bind", 2);
		exit(3);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	int					ret;
	char				buf[1025];

	if (ac != 2)
		ft_usage(av[0]);
	port = ft_atoi(av[1]);
	sock = ft_create_server(port);
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	while ((ret = read(cs, buf, 1024)) > 0)
	{
		buf[ret] = 0;
		ft_putstr(buf);
	}
	close(cs);
	close(sock);
	return (0);
}
