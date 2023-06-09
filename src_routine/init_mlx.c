/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:42:12 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:42:13 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	create_background(void)
{
	t_rec	rec;
	t_data	*data;

	rec.pos = (t_pos){};
	data = get_data(NULL);
	data->mlx.background.img.img = mlx_new_image(
			data->mlx.mlx, WIDTH, HEIGHT);
	if (!data->mlx.background.img.img)
		return (1);
	data->mlx.background.img.addr = mlx_get_data_addr(
			data->mlx.background.img.img,
			&data->mlx.background.img.bits_per_pixel,
			&data->mlx.background.img.line_length,
			&data->mlx.background.img.endian);
	data->mlx.background.img.height = HEIGHT;
	data->mlx.background.img.width = WIDTH;
	rec.heigth = data->mlx.background.img.height / 2;
	rec.width = data->mlx.background.img.width;
	mlx_put_rec(data->mlx.background.img, rec, data->mlx.background.ceiling);
	rec.pos.y = rec.heigth;
	mlx_put_rec(data->mlx.background.img, rec, data->mlx.background.floor);
	return (0);
}

static int	parse_map(t_color color[3])
{
	t_data	*data;
	t_rec	rec;
	int		x;
	int		y;

	y = 0;
	rec.width = MAP_SIZE - 2;
	rec.heigth = MAP_SIZE - 2;
	data = get_data(NULL);
	while (y < data->mlx.map.row)
	{
		x = 0;
		while (x < data->mlx.map.col)
		{
			rec.pos.x = x * MAP_SIZE + 1;
			rec.pos.y = y * MAP_SIZE + 1;
			mlx_put_rec(data->mlx.map.map_img, rec,
				color[data->mlx.map.mapping[y][x] + 1]);
			x++;
		}
		y++;
	}
	return (0);
}

static int	create_map(void)
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.map.pos_img.x = 10;
	data->mlx.map.pos_img.y = 10;
	data->mlx.map.map_img.height = data->mlx.map.row * MAP_SIZE;
	data->mlx.map.map_img.width = data->mlx.map.col * MAP_SIZE;
	data->mlx.map.map_img.img = mlx_new_image(
			data->mlx.mlx,
			data->mlx.map.map_img.width,
			data->mlx.map.map_img.height);
	if (!data->mlx.map.map_img.img)
		return (1);
	data->mlx.map.map_img.addr = mlx_get_data_addr(
			data->mlx.map.map_img.img,
			&data->mlx.map.map_img.bits_per_pixel,
			&data->mlx.map.map_img.line_length,
			&data->mlx.map.map_img.endian);
	mlx_put_rec(data->mlx.map.map_img,
		(t_rec){{0, 0}, data->mlx.map.map_img.width,
		data->mlx.map.map_img.height},
		(t_color){0, 200, 200, 200});
	parse_map((t_color[3]){{0, 125, 125, 125},
	{0, 255, 255, 255}, {0, 50, 50, 50}});
	return (0);
}

int	init_mlx(void)
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, NAME);
	mlx_hook(data->mlx.win, 2, 1L << 0, key_routine, data);
	mlx_hook(data->mlx.win, 17, 0, key_destroy, data);
	if (create_background() || create_map())
	{
		free_mlx();
		return (1);
	}
	render_frame(data);
	mlx_loop(data->mlx.mlx);
	return (0);
}
