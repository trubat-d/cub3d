#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "includes.h"

typedef struct s_posd
{
	double	x;
	double	y;
}	t_posd;

typedef struct s_plane
{
	double	angle_betwen_ray;
	double	distance;
	int		col;
	int		row;
}	t_plane;

typedef struct	s_player
{
	t_posd	current_pos;
	t_plane	projection;
	double	current_angle;
	int		pov;
	int		fov;
}
t_player;

float	find_short_len(double angle);
int		calc_projection_plane(void);
int		raytracing_plane(void);

#endif