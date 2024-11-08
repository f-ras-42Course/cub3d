/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:17:39 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:27:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*will check the validity of a singular cell*/
bool	is_valid_cell(t_all *data, char **map, size_t x, size_t y)
{
	bool	down_left_diagonal;

	if ((x == 0 || y == 0 || x == data->map.size[X] - 1 \
		|| y == data->map.size[Y] - 1) \
		&& isinset(map[y][x], "0NSEWD"))
		return (false);
	if (x == 0)
		down_left_diagonal = true;
	else
		down_left_diagonal = \
			is_valid_neighbour(data, x - 1, y + 1, get_set(map[y][x]));
	if (map[y][x] == 'D')
	{
		return ((map[y + 1][x] == '1' && map[y - 1][x] == '1') || \
				(map[y][x + 1] == '1' && map[y][x - 1] == '1'));
	}
	return (is_valid_neighbour(data, x + 1, y, get_set(map[y][x])) && \
			is_valid_neighbour(data, x, y + 1, get_set(map[y][x])) && \
			is_valid_neighbour(data, x + 1, y + 1, get_set(map[y][x])) && \
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
				return (error(INVALID_MAP, data), false);
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

	if (!is_valid_file(data, map_name, argc))
		return (false);
	else if (!open_file(data, map_name, &fd))
		return (false);
	init_map_data(&data->map);
	return (get_elements(data, fd));
}
