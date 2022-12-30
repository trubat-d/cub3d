#include "includes.h"

static double	correct_fisheye(double current_angle)
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

static void	draw_line(double current_line, int current_col)
{
	double	len_line;
	t_data	*data;
	t_rec	rec;

	return ;
	data = get_data(NULL);
	len_line = MAP_SIZE / current_line;
	len_line *= data->player.projection.distance;
	rec.width = 1;
	rec.heigth = (int)len_line / 100;
	//TODO: WHAT THE FUCK WHY IS NOT WORKING ??
	//TODO: WHY IS SPLIT ON THE CENTER ?
	//rec.heigth = MAP_SIZE * 10;
	rec.pos.x = current_col;
	rec.pos.y = (int)((HEIGHT - current_line) / 2);
	//mlx_put_rec(data->mlx.projection.img, rec, (t_color){0, 20, 20, 20});
}

static int	create_new_image(void)
{
	t_data	*data;

	data = get_data(NULL);
	if (data->mlx.projection.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.projection.img.img);
	data->mlx.projection.img.img = mlx_new_image(
			data->mlx.mlx, WEIGHT, HEIGHT);
	if (!data->mlx.projection.img.img)
		return (1);
	data->mlx.projection.img.addr = mlx_get_data_addr(
			data->mlx.projection.img.img,
			&data->mlx.projection.img.bits_per_pixel,
			&data->mlx.projection.img.line_length,
			&data->mlx.projection.img.endian);
	data->mlx.projection.img.width = WEIGHT;
	data->mlx.projection.img.height = HEIGHT;
	mlx_put_rec(data->mlx.projection.img,
		(t_rec){.width = WEIGHT, .heigth = HEIGHT},
		(t_color){255, 255, 255, 255});
	return (0);
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
	if (create_new_image())
		return (1);

	int i;

	i = 267;
	while (i <= 360)
	{
		find_short_len(i);
		i++;
	}
	return (0);

	while (current_col < data->player.projection.col)
	{
		current_angle = data->player.projection.angle_betwen_ray * current_col;
		fisheye = correct_fisheye(current_angle);
		current_angle = (double)data->player.pov - ((double)data->player.fov / 2) + current_angle;
		if (current_angle < 0)
			current_angle *= -1;
		else
			current_angle = 360 - current_angle;
		current_len = find_short_len(current_angle);
		current_len *= fisheye;
		draw_line(current_len, current_col);
		current_col++;
	}
	return (0);
}