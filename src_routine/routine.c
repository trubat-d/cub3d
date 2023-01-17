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
	free_mlx();
	free_all();
	return (0);
}