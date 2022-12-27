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
	printf("value of keycode => %d\n", keycode);
	if (keycode == 65307)
		key_destroy(raw);
	return (1);
}
