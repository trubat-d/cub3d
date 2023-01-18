/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:19 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:20 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
