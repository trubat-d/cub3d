/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:18 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:19 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_strlen_map(char *map)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		if (map[i] == ' '
			|| map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E'
			|| map[i] == '1' || map[i] == '0')
			res++;
		else if (map[i] == '\t')
			res += 4;
		else
			return (-1);
		i++;
	}
	return (res);
}
