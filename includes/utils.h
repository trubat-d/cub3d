#ifndef UTILS_H
# define UTILS_H
# include "includes.h"

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

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

int	ft_split(char ***split, char *s, char c);
int	ft_bzero(void *dst, size_t size);
int	ft_memcpy(void *dst, void *src, size_t len);
int	ft_memset(void *dst, int c, size_t n);
int	ft_itoa(char **res, int n);
int	ft_strdup(char **dst, char *src);

char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_putstr(char *str);
size_t		ft_putstr_fd(int fd, char *str);
int			ft_strncmp(char *a, char *b, size_t n);

void		mlx_put_rec(t_img img, t_rec rec, t_color color);
void		mlx_put_pixel(t_img img, int x, int y, int color);
int			create_color(t_color color);

#endif
