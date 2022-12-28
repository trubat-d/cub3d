#include "includes.h"

static double correct_fisheye(double current_angle)
{
	t_data	*data;
	double	fisheye;

	data = get_data(NULL);
	if (current_angle <= data->player.fov)
		fisheye = current_angle;
	else
		fisheye = current_angle - ((double)data->player.fov / 2);
	return (cos(angle_to_rad(fisheye)));
}

int	raytracing_plane(void)
{
	t_data	*data;
	int		current_col;
	double	current_angle;
	double	fisheye;
	double	current_len;

	current_col = 0;
	data = get_data(NULL);
	while (current_col < data->player.projection.col)
	{
		current_angle = data->player.projection.angle_betwen_ray * current_col;
		fisheye = correct_fisheye(current_angle);
		current_angle = data->player.pov - (data->player.fov / 2) + current_angle;
		current_len = find_short_len(current_angle);
		current_len *= fisheye;
		current_col++;
	}
	return (0);
}