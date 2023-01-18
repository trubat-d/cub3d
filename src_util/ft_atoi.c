/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:42 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:43 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (*current && !ft_isdigit((int)*current))
		current++;
	while (*current != '\0' && ft_isdigit((int)*current))
	{
		res *= 10;
		res += *current - 48;
		current++;
	}
	return (res);
}
