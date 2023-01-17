#include "includes.h"

size_t	ft_putstr_fd(int fd, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	return (write(fd, str, len));
}

size_t	ft_putstr(char *str)
{
	return (ft_putstr_fd(1, str));
}
