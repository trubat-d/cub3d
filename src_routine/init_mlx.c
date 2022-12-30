#include "includes.h"

static int	create_background(void)
{
	t_rec	rec;
	t_data	*data;

	rec.pos = (t_pos){};
	data = get_data(NULL);
	data->mlx.background.img.img = mlx_new_image(
			data->mlx.mlx, WEIGHT, HEIGHT);
	if (!data->mlx.background.img.img)
		return (1);
	data->mlx.background.img.addr = mlx_get_data_addr(
			data->mlx.background.img.img,
			&data->mlx.background.img.bits_per_pixel,
			&data->mlx.background.img.line_length,
			&data->mlx.background.img.endian);
	data->mlx.background.img.height = HEIGHT;
	data->mlx.background.img.width = WEIGHT;
	rec.heigth = data->mlx.background.img.height / 2;
	rec.width = data->mlx.background.img.width;
	mlx_put_rec(data->mlx.background.img, rec, data->mlx.background.ceiling);
	rec.pos.y = rec.heigth;
	mlx_put_rec(data->mlx.background.img, rec, data->mlx.background.floor);
	return (0);
}

static int	parse_map(void)
{
	t_color	color[3];
	t_data	*data;
	t_rec	rec;
	int		x;
	int		y;

	y = 0;
	color[0] = (t_color){0, 125, 125, 125};
	color[1] = (t_color){0, 255, 255, 255};
	color[2] = (t_color){0, 50, 50, 50};
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
	parse_map();
	return (0);
}

int	init_mlx(void)
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.win = mlx_new_window(data->mlx.mlx, WEIGHT, HEIGHT, NAME);
	mlx_hook(data->mlx.win, 2, 1L << 0, key_routine, &data);
	mlx_hook(data->mlx.win, 17, 0, key_destroy, &data);
	if (create_background() || create_map())
	{
		free_mlx();
		return (1);
	}
	mlx_loop_hook(data->mlx.mlx, render_frame, (void *)data);
	mlx_loop(data->mlx.mlx);
	return (0);
}