#include "includes.h"

int	ft_strlen_map(char *map)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == 'N' || map[i] == '1' || map[i] == '0')
			res++;
		else if (map[i] == '\t')
			res += 4;
		else
			return (-1);
		i++;
	}
	return (res);
}
