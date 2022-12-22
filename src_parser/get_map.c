#include "includes.h"

//TODO: GET MAP TO CHAR ** NOT EXECTUE PARSING INI THE FUNCTION
int	get_map(int fd, char ***map, char **buff)
{
	char	*res;

	(void)map;
	while (!ft_readline(fd, buff, &res))
	{
		del_malloc(res);
	}
	return (0);
}