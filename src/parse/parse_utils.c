/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:17:48 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:17:49 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*initializes some variables that can be checked later to see if all identifiers
are found or the player position is confirmed*/
void	init_map_data(t_map *map)
{
	map->map = NULL;
	map->size[X] = 0;
	map->size[Y] = 0;
	map->east_texture = NULL;
	map->north_texture = NULL;
	map->west_texture = NULL;
	map->south_texture = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->player_location[0] = 0;
	map->player_location[1] = 0;
}

/*opens file and does some custom error checking*/
bool	open_file(t_all *data, char *map, int *fd)
{
	*fd = open(map, O_RDONLY);
	if (*fd == -1 && errno == ENOENT)
	{
		if (errno == ENOENT)
			return (error(NO_SUCH_FILE, data), false);
		return (perror("Error: "), false);
	}
	return (true);
}

bool	is_valid_file(t_all *data, char *map_name, int argc)
{
	if (argc == 1)
		return (error(NO_MAP, data), false);
	while (*map_name && *map_name != '.')
		map_name++;
	if (ft_strcmp(map_name, ".cub"))
		return (error(NO_DOT_CUB, data), false);
	return (true);
}

/*checks if character in the map at coordinates
x and y are present in the allowed set*/
bool	is_valid_neighbour(t_all *data, size_t x, size_t y, char *set)
{
	if (x == data->map.size[X] || y == data->map.size[Y])
		return (true);
	return (isinset(data->map.map[y][x], set));
}

/*matches the character 'cell' with a set of allowed adjacent characters*/
char	*get_set(char cell)
{
	if (cell == ' ')
		return ("1 ");
	else if (cell == '1')
		return ("10WSEND ");
	else if (cell == '0')
		return ("01NSEWD");
	return ("01D");
}
