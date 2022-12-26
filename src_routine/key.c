#include "includes.h"

int	key_destroy(void *raw)
{
	(void)raw;
	free_all();
	free_mlx();
	exit(0);
}

int key_routine(int keycode, void *raw)
{
	t_data 	*data;

	data = raw;
	printf("value of keycode => %d\n", keycode);
	(void)data;
	(void)keycode;
	return (1);
}
