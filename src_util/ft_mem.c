/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:26 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:27 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*current;

	current = (unsigned char *)dst;
	while (n--)
		current[n] = c;
	return (0);
}

int	ft_memcpy(void *dst, void *src, size_t len)
{
	while (len--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (0);
}

int	ft_bzero(void *dst, size_t size)
{
	return (ft_memset(dst, 0, size));
}
