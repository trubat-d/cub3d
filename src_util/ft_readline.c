#include "includes.h"
#define BUFFER_SIZE 100

int	ft_read_from_buff(char **current_buff, int fd)
{
	char	*tmp;
	char	*res;
	char	*buff;
	ssize_t	len;

	if (ft_malloc((void **)&buff, sizeof(char) * (BUFFER_SIZE + 1)))
		return (1);
	res = *current_buff;
	while (!ft_strchr(res, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0 || (ft_strlen(res) == 0 && len == 0))
		{
			del_malloc(buff);
			return (1);
		}
		if (len == 0)
			break ;
		buff[len] = '\0';
		if (ft_strjoin(&tmp, res, buff))
			return (1);
		res = tmp;
		del_malloc(*current_buff);
		*current_buff = res;
	}
	del_malloc(buff);
	return (0);
}

int	ft_init_new_buff(char **buff)
{
	char	*end;
	char	*tmp;

	end = ft_strchr(*buff, '\n');
	if (!end)
		return (1);
	if (ft_strjoin(&tmp, end + 1, NULL))
		return (1);
	end = tmp;
	del_malloc(buff);
	*buff = end;
	return (0);
}

char	*ft_get_line(char *buff)
{
	char	*end;
	char	*res;
	size_t	len;

	end = ft_strchr(buff, '\n');
	if (!end)
	{
		end = ft_strchr(buff, '\0');
		return (end);
	}
	len = end - buff + 1;
	res = ft_substr((char const *)buff, 0, len);
	return (res);
}

int	ft_readline(int fd, char **current_buff, char **current_line)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (1);
	if (ft_read_from_buff(current_buff, fd))
		return (1);
	*current_line = ft_get_line(*current_buff);
	if (ft_init_new_buff(current_buff))
		return (1);
	return (0);
}



