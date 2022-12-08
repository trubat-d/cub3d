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

typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		col;
	int		row;
	t_img	img;
	int		**mapping;
}	t_map;

typedef struct s_ppos
{
	t_img	img;
}	t_ppos;

typedef struct s_proj
{
	t_img	img;
}	t_proj;

typedef struct s_bckg
{
	t_img	img;
}	t_bckg;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_ppos	player_pos;
	t_proj	projection;
	t_bckg	background;
}	t_mlx;

struct s_data
{
	t_malloc	*garbage;
	t_mlx		mlx;
};

int	init_mlx(void);
int	render_frame(void *data);

#endif
