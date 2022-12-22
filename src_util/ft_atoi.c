#include "includes.h"

int	size_nbr(int nbr)
{
	register int	i;

	if (nbr <= 0)
		return (0);
	i = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_atoi(char *current)
{
	int		res;

	res = 0;
	while (*current && ft_isspace((int)*current))
		current++;
	if (*current == '-' || *current == '+')
		return (-1);
	while (*current != '\0' && ft_isdigit((int)*current))
	{
		res *= 10;
		res += *current - 48;
		current++;
	}
	return (res);
}