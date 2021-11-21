/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:17:52 by njaros            #+#    #+#             */
/*   Updated: 2021/11/20 17:16:57 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_file
{
	char			*content;
	int				fd;
	struct s_file	*next;
}	t_file;

void			ft_keep_the_rest(char **content, size_t start);
void			ft_gordon_freeman(struct s_file **pouet, int fd);
struct s_file	*ft_fd(struct s_file **pouet, int fd);
void			ft_bzero(void *s, size_t n);
int				contain_return(char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
char			*ft_join(char *s1, char *s2);

#endif