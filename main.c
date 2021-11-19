#include "get_next_line.h"
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
	int		i = 1;
	char	*pouet;
	int		fd;

	(void)ac;
	fd = get_fd(av[1]);
	if (fd == 0)
		write(1, "saisissez votre texte, le bouton entrée signifie \\n, la commande ctrl + d signifie le EOF\n", 92);
	pouet = get_next_line(fd);
	while (i < 10 && pouet)
	{
		ft_putstr_fd("ligne ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" : ", 1);
		ft_putstr_fd(pouet, 1);
		free(pouet);
		pouet = get_next_line(fd);
		i++;
	}
	printf("\n");
	free(pouet);
	close(fd);
	return (0);
}
