/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:38 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:39 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	set_addr(void)
{
	t_data	*data;
	t_img	*current;

	data = get_data(NULL);
	current = &data->mlx.map.we_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	current = &data->mlx.map.so_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	current = &data->mlx.map.no_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	current = &data->mlx.map.ea_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	return (0);
}
