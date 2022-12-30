#include "includes.h"

static int	creat_new_image(void)
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.player_pos.img.width = data->mlx.map.map_img.width;
	data->mlx.player_pos.img.height = data->mlx.map.map_img.height;
	if (data->mlx.player_pos.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.player_pos.img.img);
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
	mlx_put_rec(data->mlx.player_pos.img,
		(t_rec){
		.width = data->mlx.player_pos.img.width,
		.heigth = data->mlx.player_pos.img.height},
		(t_color){255, 255, 255, 255});
	return (0);
}

int	calc_new_position(void)
{
	t_data	*data;
	t_rec	rec;

	data = get_data(NULL);
	if (creat_new_image())
		return (1);
	rec = (t_rec){.width = MAP_SIZE / 5, .heigth = MAP_SIZE / 5};
	rec.pos.x = (int)(data->player.current_pos.x - (int)(MAP_SIZE / (5 * 2)));
	rec.pos.y = (int)(data->player.current_pos.y - (int)(MAP_SIZE / (5 * 2)));
	mlx_put_rec(data->mlx.player_pos.img, rec,
		(t_color){0, 255, 0, 0});
	mlx_relative_point(data->player.pov,
		100,
		data->player.current_pos,
		data->mlx.player_pos.img);
	return (0);
}