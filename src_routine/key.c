#include "includes.h"

int	key_destroy(void *raw)
{
	(void)raw;
	free_all();
	free_mlx();
	exit(0);
}

int	key_routine(int keycode, void *raw)
{
	t_data	*data;

	data = (t_data *)raw;
	printf("value of keycode => %d\n", keycode);
	if (keycode == 123)
	{
		data->player.pov += 5;
		if (data->player.pov >= 360)
			data->player.pov -= 360;
	}
	if (keycode == 124)
	{
		data->player.pov -= 5;
		if (data->player.pov < 0)
			data->player.pov += 360;
	}
	//TODO: modify this for the right pos
	if (keycode == 13)
		data->player.current_pos.y -= 1;
	if (keycode == 1)
		data->player.current_pos.y += 1;
	if (keycode == 0)
		data->player.current_pos.x -= 1;
	if (keycode == 2)
		data->player.current_pos.x += 1;
	if (keycode == 65307)
		key_destroy(raw);
	return (1);
}
