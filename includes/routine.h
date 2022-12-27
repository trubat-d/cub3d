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
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	t_img	no_img;
	t_img	so_img;
	t_img	we_img;
	t_img	ea_img;
	int		col;
	int		row;
	t_img	map_img;
	int		**mapping;
}	t_map;

typedef struct s_ppos
{
	t_img	img;
	t_pos	pos_player;
	t_pos	pos_img;
}	t_ppos;

typedef struct s_proj
{
	t_img	img;
}	t_proj;

typedef struct s_bckg
{
	t_color	ceiling;
	t_color	floor;
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
	char		*file_map;
	t_malloc	*garbage;
	t_mlx		mlx;
	t_player	player;
};

int	init_mlx(void);
int	render_frame(void *data);
int	key_destroy(void *raw);
int key_routine(int keycode, void *raw);

#endif
