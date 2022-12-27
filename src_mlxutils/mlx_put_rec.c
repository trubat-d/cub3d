#include "includes.h"

void	mlx_put_rec(t_img img, t_rec rec, t_color color)
{
	int	color_value;
	int	w;
	int	h;

	color_value = create_color(color);
	h = 0;
	while (h < rec.heigth)
	{
		w = 0;
		while (w < rec.width)
		{
			mlx_put_pixel(img, w + rec.pos.x, h + rec.pos.y, color_value);
			w++;
		}
		h++;
	}
}