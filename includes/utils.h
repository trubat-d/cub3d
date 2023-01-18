#ifndef UTILS_H
# define UTILS_H
# include "includes.h"
# include "raycasting.h"

struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
};

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_rec
{
	t_pos	pos;
	int		width;
	int		heigth;
}	t_rec;

int			ft_split(char ***split, char *s, char c);
int			ft_bzero(void *dst, size_t size);
int			ft_memcpy(void *dst, void *src, size_t len);
int			ft_memset(void *dst, int c, size_t n);
int			ft_itoa(char **res, int n);
int			ft_strdup(char **dst, char *src);
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_strdup(char **dst, char *src);
int			ft_strjoin(char **buff, char *a, char *b);
int			ft_readline(int fd, char **current_buff, char **current_line);

size_t		ft_strlcat(char	*dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
size_t		ft_putstr(char *str);
size_t		ft_putstr_fd(int fd, char *str);

char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(char *a, char *b, size_t n);
int			ft_atoi(char *current);
int			size_nbr(int nbr);

void		mlx_put_rec(t_img img, t_rec rec, t_color color);
void		mlx_put_pixel(t_img img, int x, int y, int color);
int			get_color(t_img img, int x, int y);
int			create_color(t_color color);
int			mlx_relative_point(double angle, double distance, t_posd current,
				t_img img);
int			mlx_relative_point_map(double angle, double distance, t_posd current,
				t_color color);
int			mlx_print_point(t_posd current, t_img img, t_color color);
void		draw_texture(double len_line, int current_col);

double		angle_to_rad(double angle);
double		rad_to_angle(double rad);
double		absd(double a);
double		max_angle(double angle);


#endif
