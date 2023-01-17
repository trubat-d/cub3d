#include "includes.h"

void	mlx_put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr;
	if (!dst)
		return ;
	if (x < 0 || y < 0)
		return ;
	if (x >= img.width || y >= img.height)
		return ;
	dst += y * img.line_length + x * (img.bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

int	create_color(t_color color)
{
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}
