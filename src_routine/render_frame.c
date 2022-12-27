#include "includes.h"

int	render_frame(void *raw)
{
	t_data	*data;

	data = (t_data *)raw;
	if (calc_projection_plane()
		|| raytracing_plane())
		return (1);
	mlx_put_image_to_window(
		data->mlx.mlx,
		data->mlx.win,
		data->mlx.background.img.img,
		0, 0);
	mlx_put_image_to_window(
		data->mlx.mlx,
		data->mlx.win,
		data->mlx.player_pos.img.img,
		data->mlx.player_pos.pos_img.x,
		data->mlx.player_pos.pos_img.y);
	return (0);
}