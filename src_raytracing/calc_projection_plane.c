/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_projection_plane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:55 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:56 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	calc_projection_plane(void)
{
	t_data		*data;
	double		len;
	double		angle_rad;
	double		angle_ray;

	data = get_data(NULL);
	len = (double)data->player.projection.col / 2.0;
	angle_rad = tan(angle_to_rad((double)data->player.fov / 2));
	data->player.projection.distance = len / angle_rad;
	angle_ray = (double)data->player.fov / data->player.projection.col;
	data->player.projection.angle_betwen_ray = angle_ray;
	return (0);
}
