
#include "cub3d.h"

/*will check the validity of a singular cell*/
bool	is_valid_cell(t_all *data, char **map, size_t x, size_t y)
{
	bool	down_left_diagonal;

	if (isinset(map[y][x], "0NSEW") && (x == 0 || y == 0 || \
		x + 1 == data->map.size[X] || y + 1 == data->map.size[Y]))
		return (false);
	down_left_diagonal = true;
	if (x != 0)
		down_left_diagonal = \
			isvalidneighbour(data, x - 1, y + 1, get_set(map[y][x]));
	return (isvalidneighbour(data, x + 1, y, get_set(map[y][x])) && \
			isvalidneighbour(data, x, y + 1, get_set(map[y][x])) && \
			isvalidneighbour(data, x + 1, y + 1, get_set(map[y][x])) && \
			down_left_diagonal);
}

/*loops through the entire to map to find invalid cells.
invalid cells will be checked based on their 5 neighbouring cells*/
bool	is_valid_map(t_all *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < data->map.size[Y])
	{
		x = 0;
		while (x < data->map.size[X])
		{
			if (!is_valid_cell(data, data->map.map, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

/*the main function that is called to parse the map given by the user.
will return 0 if everything is parsed correctly and returns 1
for an inclomple/invalid map*/
bool	parse_map(t_all *data, int argc, char *map_name)
{
	int		fd;
	char	*line;

	if (argc == 1)
		return (error(NO_MAP, data), true);
	else if (ft_strcmp(".cub", \
			ft_strnstr(map_name, ".cub", ft_strlen(map_name))))
		return (error(NO_DOT_CUB, data), true);
	else if (open_file(data, map_name, &fd))
		return (true);
	init_map_data(&data->map, &data->player);
	line = get_elements(data, fd);
	if (!line || get_map(data, fd, line))
		return (close(fd), true);
	close(fd);
	if (!is_valid_map(data))
		return (error(INVALID_MAP, data), true);
	return (false);
}
