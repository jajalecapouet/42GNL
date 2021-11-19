#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	static char	*temp;
	
	ft_bzero(buf, BUFFER_SIZE + 1);
	i = 0;
	while (!(contain_return(temp)) && read(fd, buf, BUFFER_SIZE) > 0)
	{
		temp = ft_strjoin_free(temp, buf);
		if (!temp)
			return (NULL);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	while (temp && temp[i] && temp[i] != '\n')
		i++;
	line = ft_substr(temp, 0, i + 1);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	temp = ft_substr_free(temp, ft_strlen(line), ft_strlen(temp));
	return (line);
}
