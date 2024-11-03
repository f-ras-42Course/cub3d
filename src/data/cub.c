
#include "data.h"
#include <stdarg.h>

void	make_cub_data_widely_available(t_map *cub)
{
	map_data(SET, cub->map);
	map_height(SET, cub->size[Y]);
	map_width(SET, cub->size[X]);
}

/**
*		Options:
*		- map_data(GET)
*		- map_data(SET, char **heap_allocated_map_data)
*		- map_data(CHANGE_ELEMENT, int x, int y, char change_to)*/
char	**map_data(t_mapaccess option, ...)
{
	static char	**map;
	int			x;
	int			y;
	char		to;
	va_list		ap;

	if (option == GET)
		return (map);
	if (option == CHANGE_ELEMENT)
	{
		va_start(ap, option);
		x = va_arg(ap, int);
		y = va_arg(ap, int);
		to = va_arg(ap, int);
		va_end(ap);
		map[y][x] = to;
	}
	if (option == SET)
	{
		va_start(ap, option);
		map = va_arg(ap, char**);
		va_end(ap);
	}
	return (0);
}

size_t		map_height(t_mapaccess option, ...)
{
	static size_t 	height;
	va_list			ap;

	if (option == GET)
		return (height);
	if (option == SET)
	{
		va_start(ap, option);
		height = va_arg(ap, size_t);
		va_end(ap);
	}
	return (0);
}

size_t		map_width(t_mapaccess option, ...)
{
	static size_t	width;
	va_list			ap;

	if (option == GET)
		return (width);
	if (option == SET)
	{
		va_start(ap, option);
		width = va_arg(ap, size_t);
		va_end(ap);
	}
	return (0);
}
