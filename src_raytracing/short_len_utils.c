#include "includes.h"

int	is_on_grid(t_posd pos)
{
	t_pos	map_pos;
	t_data	*data;
	int		**map;

	data = get_data(NULL);
	map = data->mlx.map.mapping;
	map_pos.y = (int)floor(pos.y / (double)MAP_SIZE);
	map_pos.x = (int)floor(pos.x / (double)MAP_SIZE);
	if (map_pos.y >= data->mlx.map.row
		|| map_pos.x >= data->mlx.map.col
		|| map_pos.y < 0
		|| map_pos.x < 0)
		return (0);
	return (map[map_pos.y][map_pos.x] == 0);
}

double	get_len_pos(t_posd pos)
{
	t_posd	player_pos;
	t_posd	calc;

	player_pos = get_data(NULL)->player.current_pos;
	calc.x = pow(absd(player_pos.x - pos.x), 2);
	calc.y = pow(absd(player_pos.y - pos.y), 2);
	return (sqrt(calc.x + calc.y));
}

void	get_first_horizontal(t_posd *pos, double angle)
{
	t_data	*data;

	data = get_data(NULL);
	pos->y = floor(data->player.current_pos.y / (double)MAP_SIZE);
	pos->y *= MAP_SIZE;
	if (angle < 180 && angle > 0)
		pos->y -= 0.001;
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
	pos->x = floor(data->player.current_pos.x / (double)MAP_SIZE);
	pos->x *= MAP_SIZE;
	if (angle > 90 && angle < 270)
		pos->x -= 0.001;
	else
		pos->x += MAP_SIZE;
	pos->y = data->player.current_pos.x - pos->x;
	pos->y = pos->y * tan(angle_to_rad(angle));
	pos->y = data->player.current_pos.y + pos->y;
}
