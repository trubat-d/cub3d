#include "includes.h"



int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data) {};
	get_data(&data);
	if (valid_arg(argc, argv)
		|| init_map()
		|| init_mlx())
	{
		free_all();
		return (1);
	}
	mlx_loop_hook(data.mlx.mlx, render_frame, (void *) &data);
	mlx_loop(data.mlx.mlx);
	free_all();
	return (0);
}