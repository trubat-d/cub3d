/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:42:06 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:42:08 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	key_destroy(void *raw)
{
	(void)raw;
	free_all();
	free_mlx();
	exit(0);
}

static	void	check_mov(double angle)
{
	double	new_angle;
	t_data	*data;
	t_posd	pos;
	t_posd	test_pos;

	data = get_data(NULL);
	new_angle = max_angle(data->player.pov + angle);
	pos.x = cos(angle_to_rad(new_angle)) * VELO;
	pos.y = sin(angle_to_rad(new_angle)) * VELO;
	test_pos.x = data->player.current_pos.x - pos.x;
	test_pos.y = data->player.current_pos.y + pos.y;
	if (is_on_grid(test_pos))
	{
		data->player.current_pos.x -= pos.x;
		data->player.current_pos.y += pos.y;
	}
}

static void	moove(int keycode)
{
	if (keycode == 13)
		check_mov(180);
	if (keycode == 1)
		check_mov(0);
	if (keycode == 0)
		check_mov(-90);
	if (keycode == 2)
		check_mov(90);
}

int	key_routine(int keycode, t_data *data)
{
	if (keycode == 12)
		data->player.fov += 1;
	if (keycode == 14)
		data->player.fov -= 1;
	if (keycode == 53)
		key_destroy(data);
	if (keycode == 123)
	{
		data->player.pov += 5;
		if (data->player.pov >= 360)
			data->player.pov -= 360;
	}
	if (keycode == 124)
	{
		data->player.pov -= 5;
		if (data->player.pov < 0)
			data->player.pov += 360;
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		moove(keycode);
	render_frame(data);
	return (1);
}
