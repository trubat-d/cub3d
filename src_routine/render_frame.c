#include "includes.h"

int	render_frame(void *raw)
{
	t_data	*data;

	data = (t_data  *)raw;
	mlx_put_image_to_window(
			data->mlx.mlx,
			data->mlx.win,
			data->mlx.background.img.img,
			0, 0);
	return (1);
}