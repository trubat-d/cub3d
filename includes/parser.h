#ifndef PARSER_H
# define PARSER_H
# include "includes.h"

int	get_map(int fd, char ***map, char **buf);
int	init_map(void);
int	valid_arg(int argc, char **argv);
int	open_file(int *fd, char *file);
int	open_image(char *buff);

#endif