#include "includes.h"

t_data	*get_data(t_data *new)
{
	static t_data	*data;

	if (new)
		data = new;
	return (data);
}
