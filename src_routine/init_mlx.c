#include "includes.h"

int	init_mlx(void)
{
	t_data	*data;

	data = get_data(NULL);
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, WEIGHT, HEIGHT, NAME);
	mlx_loop(data->mlx.mlx);
	return (0);
}