#include "includes.h"

int	main()
{
	t_data	data;

	data = (t_data){};
	get_data(&data);
	if (init_mlx())
		return (1);
}