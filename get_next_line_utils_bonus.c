/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:49:01 by njaros            #+#    #+#             */
/*   Updated: 2021/11/20 17:15:34 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*fill;

	i = 0;
	fill = s;
	while (i < n)
	{
		fill[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	secure;
	size_t	i;

	i = 0;
	secure = 1;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * secure * len + 1);
	if (!sub)
		return (NULL);
	while ((i < len) && (s[start + i]))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_return_and_keep(char **temp, char *line, int n)
{
	char	*str;

	str = ft_substr(line, 0, n + 1);
	*temp = ft_substr(line, n + 1, ft_strlen(&line[n + 1]));
	free(line);
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;
	char	*join;

	if (s2 == NULL)
		return (s1);
	i = -1;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (l1 + l2) + 1);
	if (!join)
		return (NULL);
	while (++i < l1)
		join[i] = s1[i];
	while (i < l1 + l2)
	{
		join[i] = s2[i - l1];
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}
