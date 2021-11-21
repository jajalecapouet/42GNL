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

char	*get_next_line(int fd)
{
	int				i;
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	static t_file	*p;

	line = ft_fd(&p, fd)->content;
	i = contain_return(line);
	if (line && line[i] == '\n')
		return (ft_return_and_keep(&(ft_fd(&p, fd)->content), line, i));
	i = 0;
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_free(line, buf);
		i = i + (contain_return(&line[i]));
		if (line[i] == '\n')
			return (ft_return_and_keep(&(ft_fd(&p, fd)->content), line, i));
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	ft_fd(&p, fd)->content = NULL;
	if (!line)
		ft_gordon_freeman(&p, fd);
	return (line);
}