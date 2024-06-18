
#include "cub3d.h"

/*initializes some variables that can be checked later to see if all identifiers
are found or the player position is confirmed*/
void	init_map_data(t_map *map, t_player *player)
{
	map->map = NULL;
	map->size[X] = 0;
	map->size[Y] = 0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->index[0] = 0;
	map->index[1] = 0;
	player->position[X] = -1;
	player->position[Y] = -1;
}

/*opens file and does some custom error checking*/
bool	open_file(t_all *data, char *map, int *fd)
{
	*fd = open(map, O_RDONLY);
	if (*fd == -1 && errno == ENOENT)
		return (error(NO_SUCH_FILE, data), true);
	else if (*fd == -1)
		return (perror("Error: "), true);
	return (false);
}

/*checks if character in the map at coordinates
x and y are present in the allowed set*/
bool	isvalidneighbour(t_all *data, size_t x, size_t y, char *set)
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
		return ("10WSEN ");
	else if (cell == '0')
		return ("01NSEW");
	return ("01");
}
