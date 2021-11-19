#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_bzero(void *s, size_t n);
int		contain_return(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr_free(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *s1, char *s2);

#endif