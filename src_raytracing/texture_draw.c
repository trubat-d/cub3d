#include "includes.h"

static void	draw_line(int len, t_img img, int x, int off)
{
	t_data	*data;
	int		y;
	int		color;
	int		y_off;

	y = 0;
	data = get_data(NULL);
	while (y < len)
	{
		color = get_color(img, (int)floor((off * img.height) / (double)MAP_SIZE), (int)floor((y * img.width) / (double)len));
		y_off = (int)(HEIGHT - len) / 2;
		mlx_put_pixel(data->mlx.projection.img, x, y + y_off, color);
		y++;
	}
}

void	draw_texture(double current_line, int current_col)
{
	t_data	*data;
	double	len_line;

	data = get_data(NULL);
	len_line = MAP_SIZE / (double)current_line;
	len_line *= data->player.projection.distance;
	if (data->player.face == NO)
		draw_line((int)len_line,
			data->mlx.map.no_img, current_col, data->player.offset);
	if (data->player.face == SO)
		draw_line((int)len_line,
			data->mlx.map.so_img, current_col, data->player.offset);
	if (data->player.face == EA)
		draw_line((int)len_line,
			data->mlx.map.ea_img, current_col, data->player.offset);
	if (data->player.face == WE)
		draw_line((int)len_line,
			data->mlx.map.we_img, current_col, data->player.offset);
}
