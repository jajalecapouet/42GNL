#include "get_next_line_bonus.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
void	ft_recuputnbr_fd(long n, int fd)
{
	if (n / 10 > 0)
	{
		ft_recuputnbr_fd((n / 10), fd);
		ft_recuputnbr_fd((n % 10), fd);
	}
	if (n / 10 == 0)
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	k;

	k = (long) n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		k = -k;
	}
	ft_recuputnbr_fd(k, fd);
}

int ft_atoi(const char *nptr)
{
    int i;
    int r;
    int sign;

    r = 0;
    sign = 1;
    i = 0;
    while ((nptr[i] == '\t') || (nptr[i] == '\n') || (nptr[i] == '\v')
        || (nptr[i] == '\f') || (nptr[i] == '\r') || (nptr[i] == ' '))
        i++;
    if ((nptr[i] == '-') || (nptr[i] == '+'))
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while ((nptr[i] >= '0') && (nptr[i] <= '9'))
    {
        r = 10 * r;
        r = r + (nptr[i] - '0');
        i++;
    }
    return (sign * r);
}

int	get_fd(char *entry)
{
	int	i;

	i = 0;
	while (entry[i])
	{
		if (entry[i] <= '9' && entry[i] >= '0')
			i++;
		else
			break;
	}
	if (entry[i] == 0)
		return (ft_atoi(entry));
	else
		return (open(entry, O_RDONLY));
}

int	main(int ac, char **av)
{
	int		i = 0;
	char	*pouet, *pouet2, *pouet3, *pouet4;
	int		fd;
	int		fd2;
	int 	fd3;
	int		fd4;

	(void)ac;
	fd4 = get_fd(av[4]);
	fd3 = get_fd(av[3]);
	fd2 = get_fd(av[2]);
	fd = get_fd(av[1]);
	pouet = get_next_line(fd);
	pouet2 = get_next_line(fd2);
	pouet3 = get_next_line(fd3);
	pouet4 = get_next_line(fd4);
	while (pouet || pouet2 || pouet3 || pouet4)
	{
		printf("%s%s%s%s", pouet, pouet2, pouet3, pouet4);
		free(pouet);
		free(pouet2);
		free(pouet3);
		free(pouet4);
		pouet = get_next_line(fd);
		pouet2 = get_next_line(fd2);
		pouet3 = get_next_line(fd3);
		pouet4 = get_next_line(fd4);
	}
	free(pouet);
	free(pouet2);
	free(pouet3);
	free(pouet4);
	close(fd);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
