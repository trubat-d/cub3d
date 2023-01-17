#include "includes.h"

int	render_frame(void *raw)
{
	t_data	*data;

	data = (t_data *)raw;
	if (calc_new_position()
		|| calc_projection_plane()
		|| raytracing_plane())
		return (1);
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.win, data->mlx.background.img.img,
		0, 0);
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.win, data->mlx.projection.img.img,
		0, 0);
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.win, data->mlx.map.map_img.img,
		data->mlx.map.pos_img.x,
		data->mlx.map.pos_img.y);
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.win, data->mlx.player_pos.img.img,
		data->mlx.map.pos_img.x,
		data->mlx.map.pos_img.y);
	return (0);
}
