#ifndef ROUTINE_H
# define ROUTINE_H
# include "includes.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	t_img	map;
	t_img	player_pos;q

	t_img	projection;
	t_img	background;
}	t_mlx;

struct s_data
{
	t_mlx	mlx;
};

int init_mlx(void);

#endif
