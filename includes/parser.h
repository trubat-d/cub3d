#ifndef PARSER_H
# define PARSER_H
# include "includes.h"

int		get_len_map(char **map);
int		get_map(int fd, char ***map, char **buf);
int		init_map(void);
int		valid_arg(int argc, char **argv);
int		open_file(int *fd, char *file);
int		open_image(char *buff);
int		free_map(char **map);
int		parse_current_map(char **map);
int		ft_strlen_map(char *map);
void	fill_map(int *tab, char *current_map, int y);
int		set_addr(void);

#endif