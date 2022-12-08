#include "parser.h"

int	init_map(void)
{
	t_data	*data;

	if (read_file())
	{
		return (1);
	}

	data = get_data(NULL);
	data->mlx.map.row = 8;
	data->mlx.map.col = 6;




	const int	mapsample[COL][ROW] = {{1, 1 ,1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}};
	int	**map;
	if(ft_malloc((void **)&map,sizeof(int *) * (ROW)))
		return (1);
	int	i;
	int	j;
	t_data *data;

	data = get_data(NULL);
	i = 0;
	while (i < ROW)
	{
		//MODIFI TO ADD TO FT_MALLOC
		map[i] = malloc(sizeof(int) * COL);
		j = 0;
		while (j < COL)
		{
			map[i][j] = mapsample[i][j];
			j++;
		}
		i++;
	}
	data->mlx.map.mapping = map;
	return (0);
}