
#include "cub3d.h"

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

bool	open_file(t_all *data, char *map, int *fd)
{
	*fd = open(map, O_RDONLY);
	if (*fd == -1 && errno == ENOENT)
		return (error(NO_SUCH_FILE, data), true);
	else if (*fd == -1)
		return (perror("Error: "), true);
	return (false);
}

// bool	trivial(t_all *data, char current, char **map, int *c)

// need a function that checks its right and below and diagonal neigbour
// then it needs to validate the neighbours value and return thumbs up

bool	isvalidneighbour(t_all *data, size_t x, size_t y, char *set)
{
	if (x == data->map.size[X] || y == data->map.size[Y])
		return (true);
	return (isinset(data->map.map[y][x], set));
}

bool	is_valid_cell(t_all *data, size_t x, size_t y)
{
	//y x = cell to check
	//y + 1, x
	//y, x + 1
	// y + 1, x + 1 = cells that must confirm (y,x)
	if (data->map.map[y][x] == ' ')
	{
		return (isvalidneighbour(data, x + 1, y, "1 ") && \
				isvalidneighbour(data, x, y + 1, "1 ") && \
				isvalidneighbour(data, x + 1, y + 1, "1 "));
	}
	else if (data->map.map[y][x] == '0')
	{
		if (!y || !x || y + 1 == data->map.size[Y] || \
			X + 1 == data->map.size[X])
		{
			printf("activated\n");
			return (false);
		}
		return (isvalidneighbour(data, x + 1, y, "10NESW") && \
				isvalidneighbour(data, x, y + 1, "10NESW") && \
				isvalidneighbour(data, x + 1, y + 1, "10NESW"));
	}
	else if (data->map.map[y][x] == '1')
	{
		return (true);
		// can be adjacent to anything but needs to be adjacent to atleast 1 wall
	}
	if (!y || !x || y + 1 == data->map.size[Y] || \
		X + 1 == data->map.size[X])
		return (false);
	return (isvalidneighbour(data, x + 1, y, "10") && \
			isvalidneighbour(data, x, y + 1, "10") && \
			isvalidneighbour(data, x + 1, y + 1, "10"));
}

bool	recursive_validation(t_all *data, size_t x, size_t y)
{
	if (!is_valid_cell(data, x, y))
	{
		printf("x[%ld]y[%ld]found invalid cell : x: %ld, y: %ld\ncell: [%c]\n",data->map.size[X], data->map.size[Y], x, y, data->map.map[y][x]);
		return (true);
	}
	int	right = 0;
	int down = 0;
	int diagonal = 0;
	if (x + 1 < data->map.size[X] && y + 1 < data->map.size[Y])
		diagonal = recursive_validation(data, x + 1, y + 1);
	if (!diagonal && x + 1 < data->map.size[X])
		right = recursive_validation(data, x + 1, y);
	if (!diagonal && !right && y + 1 < data->map.size[Y])
		down = recursive_validation(data, x, y + 1);
	return (diagonal && right && down);
	// return (recursive_validation(data, x + 1, y) || 
	// 		recursive_validation(data, x, y + 1) || 
	// 		recursive_validation(data, x + 1, y + 1));
}

bool	is_valid_map(t_all *data, size_t y)
{
	size_t	y;
	size_t	x;

	if (y == data->map.size[Y])
		return (true); // we got to the end !
	while (y < data->map.size[Y])
	{

	}
		x = 0;
		while (x < data->map.size[X])
		{
		
			x++;
		}
		return (is_valid_map(data, y + 1));
}

/*might turn into void function since we can use exit*/
/*if not too complicated let's try to restrain from using exit and return from main instead.
also let's use bool for boolean returns*/
bool	parse_map(t_all *data,  int argc, char *map_name)
{
	int		fd;
	char	*line;

	if (argc == 1)
		return (error(NO_MAP, data), true);
	else if (ft_strcmp(".cub", ft_strnstr(map_name, ".cub", ft_strlen(map_name))))
		return (error(NO_DOT_CUB, data), true);
	else if (open_file(data, map_name, &fd))
		return (true);
	init_map_data(&data->map, &data->player);
	line = get_elements(data, fd);
	if (!line || get_map(data, fd, line))
		return (close(fd), true);
	close(fd);
	if (!is_valid_map(data, 0))
		return (error(1, data),true);
	return (false);
}
	// printf("[%s]\nNO: %s\nSO: %s\nEA: %s\nWE: %s\nF %d\nC %d\n", line, 
	// data->map.north_texture,data->map.south_texture, data->map.west_texture,data->map.east_texture, 
	// data->map.floor[X], data->map.floor[Y], data->map.floor[Z], 
	// data->map.ceiling[X], data->map.ceiling[Y], data->map.ceiling[Z]);
