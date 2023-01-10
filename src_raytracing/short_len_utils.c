#include "includes.h"

int	is_on_grid(t_posd pos, int n)
{
	t_color	color;
	t_pos	map_pos;
	t_data	*data;
	int		**map;

	data = get_data(NULL);
	color = (t_color){0, 0, 0, 0};
	if (n == 1)
		color.r = 255;
	else if (n == 2)
		color.b = 255;
	map = data->mlx.map.mapping;
	map_pos.x = (int)floor(pos.x / (double)MAP_SIZE);
	map_pos.y = (int)floor(pos.y / (double)MAP_SIZE);
	if (map_pos.y >= data->mlx.map.row
		|| map_pos.x >= data->mlx.map.col
		|| map_pos.y < 0
		|| map_pos.x < 0)
		return (0);
	if (map[map_pos.y][map_pos.x] != 0)
		color.g = 255;
	mlx_print_point((t_posd){pos.x, pos.y},
		get_data(NULL)->mlx.player_pos.img,
		color);
	return (map[map_pos.y][map_pos.x] == 0);
}

double	get_len_pos(t_posd pos)
{
	t_posd	player_pos;
	t_posd	calc;

	player_pos = get_data(NULL)->player.current_pos;
	calc.x = pow(player_pos.x - pos.x, 2);
	calc.y = pow(player_pos.y - pos.y, 2);
	return (sqrt(calc.x + calc.y));
}

void	get_first_horizontal(t_posd *pos, double angle)
{
	t_data	*data;

	data = get_data(NULL);
	pos->y = data->player.current_pos.y / (double)MAP_SIZE;
	pos->y *= MAP_SIZE;
	if (angle < 180 && angle > 0)
		pos->y -= 1;
	else
		pos->y += MAP_SIZE;
	pos->x = data->player.current_pos.y - pos->y;
	pos->x = pos->x / tan(angle_to_rad(angle));
	pos->x = data->player.current_pos.x + pos->x;
}

void	get_first_vertical(t_posd *pos, double angle)
{
	t_data	*data;

	data = get_data(NULL);
	pos->x = floor(data->player.current_pos.x / MAP_SIZE);
	pos->x *= MAP_SIZE;
	if (angle > 90 && angle < 270)
		pos->x -= 1;
	else
		pos->x += MAP_SIZE;
	pos->y = data->player.current_pos.x - pos->x;
	pos->y = floor(pos->y * tan(angle_to_rad(angle)));
	pos->y += data->player.current_pos.y;
}
