#include "includes.h"

static int	test_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read(fd, NULL, 0) < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	valid_arg(int argc, char **argv)
{
	t_data	*data;

	data = get_data(NULL);
	if (argc != 2)
	{
		ft_putstr_fd(2, "[ERROR]\tplease submit a correct file map\n");
		return (1);
	}
	if (test_file(argv[1]))
	{
		ft_putstr_fd(2, "[ERROR]\terror to open file\n");
		return (1);
	}
	data->file_map = argv[1];
	return (0);
}