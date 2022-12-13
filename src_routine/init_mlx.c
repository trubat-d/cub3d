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
	rec.pos.x = data->mlx.background.img.height / 2;
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
	color[1] = (t_color){};
	color[2] = (t_color){0, 255, 255, 255};
	rec.width = MAP_SIZE;
	rec.heigth = MAP_SIZE;
	data = get_data(NULL);
	while (y < data->mlx.map.row)
	{
		x = 0;
		while (x < data->mlx.map.col)
		{
			rec.pos.x = x * MAP_SIZE;
			rec.pos.y = y * MAP_SIZE;
			mlx_put_rec(data->mlx.player_pos.img, rec,
				color[data->mlx.map.mapping[x][y] + 1]);
			x++;
		}
		y++;
	}
	return (0);
}

static int	create_map()
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.player_pos.img.height = data->mlx.map.row * MAP_SIZE;
	data->mlx.player_pos.img.width = data->mlx.map.col * MAP_SIZE;
	data->mlx.player_pos.img.img = mlx_new_image(
			data->mlx.mlx,
			data->mlx.player_pos.img.width,
			data->mlx.player_pos.img.height);
	if (!data->mlx.player_pos.img.img)
		return (1);
	data->mlx.player_pos.img.addr = mlx_get_data_addr(
			data->mlx.player_pos.img.img,
			&data->mlx.player_pos.img.bits_per_pixel,
			&data->mlx.player_pos.img.line_length,
			&data->mlx.player_pos.img.endian);
	parse_map()
	return (0);
}

int	init_mlx(void)
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, WEIGHT, HEIGHT, NAME);
	mlx_loop(data->mlx.mlx);
	if (create_background() || create_map())
	{
		free_mlx();
		return (1);
	}
	return (0);
}