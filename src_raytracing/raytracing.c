#include "includes.h"

int	raytracing_plane(void)
{
	t_data	*data;
	int		current_col;
	double	current_angle;
	double	current_len;

	data = get_data(NULL);
	current_col = 0;
	while (current_col < data->player.projection.col)
	{
		current_angle = data->player.projection.angle_betwen_ray * current_col;
		if (current_col <= data->player.projection.col / 2)
			current_angle -= data->player.current_angle;
		else
			current_angle += data->player.current_angle;
		current_len = find_short_len(angle);
		current_col++;
	}
	return (0);
}