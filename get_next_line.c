#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*GNL;
	char	buf[BUFFER_SIZE];
	size_t	i;

	if (BUFFER_SIZE == 0)
		return (NULL);
	i = 0;
	if (read(fd, &buf[i], 1) <= 0)
		return (NULL);
	i++;
	while (read(fd, &buf[i], 1) && buf[i] != '\n')
	{
		i++;
		if (i == BUFFER_SIZE)
			return (0);
	}
	if (buf[i] == '\n')
	{
		buf[i + 1] = '\0';
		GNL = malloc(i + 2);
	}
	else
	{
		buf[i] = '\0';
		GNL = malloc(i + 1);
	}
	if (!GNL)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		GNL[i] = buf[i];
		i++;
	}
	GNL[i] = '\0';
	return (GNL);
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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
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
	char	*pouet;
	int	fd;

	(void)ac;
	fd = get_fd(av[1]);
	if (fd == 0)
		write(1, "saisissez votre texte, le bouton entrée signifie \\n, la commande ctrl + d signifie le EOF\n", 92);
	pouet = get_next_line(fd);
	while (pouet)
	{
		write(1, pouet, ft_strlen(pouet));
		free(pouet);
		pouet = get_next_line(fd);
	}
	write(1, "fermeture du fichier\n", 21);
	close(fd);
	return (0);
}
