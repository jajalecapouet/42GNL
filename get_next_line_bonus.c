/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:49:27 by njaros            #+#    #+#             */
/*   Updated: 2021/11/21 15:24:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	contain_return(char *s)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
		{
			if (s[i] == '\n')
				return (i);
		}
	}
	return (i);
}

struct s_file	*ft_fdnew(int fd)
{
	struct s_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->content = NULL;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void	ft_gordon_freeman(struct s_file **pouet, int fd)
{
	struct s_file	*temp;
	struct s_file	*begin;

	if (!(*pouet))
		return ;
	temp = *pouet;
	begin = *pouet;
	while ((*pouet)->fd != fd)
	{
		temp = *pouet;
		if (!(*pouet)->next)
			return ;
		*pouet = (*pouet)->next;
	}
	if (temp == (*pouet))
		begin = (*pouet)->next;
	temp->next = (*pouet)->next;
	free(*pouet);
	*pouet = begin;
}

struct s_file	*ft_fd(struct s_file **pouet, int fd)
{
	struct s_file	*mem;
	struct s_file	*good_one;

	if (!(*pouet))
	{
		*pouet = ft_fdnew(fd);
		return (*pouet);
	}
	mem = *pouet;
	while (*pouet)
	{
		good_one = *pouet;
		if ((*pouet)->fd == fd)
		{
			*pouet = mem;
			return (good_one);
		}
		*pouet = (*pouet)->next;
	}
	good_one->next = ft_fdnew(fd);
	good_one = good_one->next;
	if (mem)
		*pouet = mem;
	return (good_one);
}

/*char	*get_next_line(int fd)
{
	int				i;
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	static t_file	*pouet;

	if (BUFFER_SIZE < 1)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	i = 0;
	while (!(contain_return(ft_fd(&pouet, fd)->content))
		&& read(fd, buf, BUFFER_SIZE) > 0)
	{
		ft_fd(&pouet, fd)->content = ft_join(ft_fd(&pouet, fd)->content, buf);
		if (!ft_fd(&pouet, fd)->content)
			return (NULL);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	while (ft_fd(&pouet, fd)->content && ft_fd(&pouet, fd)->content[i]
		&& ft_fd(&pouet, fd)->content[i] != '\n')
		i++;
	line = ft_substr(ft_fd(&pouet, fd)->content, 0, i + 1);
	ft_keep_the_rest(&ft_fd(&pouet, fd)->content, i + 1);
	if (!ft_fd(&pouet, fd)->content)
		ft_gordon_freeman(&pouet, fd);
	return (line);
}*/

char	*get_next_line(int fd)
{
	int				i;
	char			*line;
	char			**need;
	char			buf[BUFFER_SIZE + 1];
	static t_file	*pouet;


	i = contain_return(ft_fd(&pouet, fd));
	if ()
}