/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:52 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:53 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_strjoin(char **buff, char *a, char *b)
{
	size_t	len_max;

	len_max = ft_strlen(a) + ft_strlen(b) + 1;
	if (ft_calloc((void **)buff, len_max, sizeof(char)))
		return (1);
	if (ft_strlcat(*buff, a, len_max) > len_max
		|| ft_strlcat(*buff, b, len_max + 1) > len_max)
		return (1);
	return (0);
}
