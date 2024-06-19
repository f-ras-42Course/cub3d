
#include "cub3d.h"

t_str	*validate_characters_in_map(char *line, t_all *data)
{
	static bool	player_found;
	t_str		*new;
	int			i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (isinset(line[i], "NSEW"))
		{
			if (player_found == true)
				return (error(MULTIPLE_PLAYERS, data), NULL);
			data->player.position[X] = i;
			data->player.position[Y] = data->map.size[Y];
			// also can determine direction!
			player_found = true;
		}
		else if (!isinset(line[i], " 01"))
			return (error(INVALID_CHARACTER, data), NULL);
		i++;
	}
	line[i] -= line[i];
	new = str_new(line);
	if (!new)
		perror("Error: ");
	return (new);
}

bool	is_valid_player_and_map_size(t_all *data)
{
	if (data->player.position[X] == -1)
		return (error(NO_PLAYER, data), false);
	else if (data->map.size[X] < 3 || data->map.size[Y] < 3)
		return (error(MAP_TOO_SMALL, data), false);
	return (true);
}

/*will read all lines that have potential map elements.
it will find invalid characters and check if 1 or more players are found*/
bool	get_size_and_individual_lines(char *line, int fd, \
			t_all *data, t_str **head)
{
	t_str	*current;

	while (line && ft_strcmp(line, "\n"))
	{
		current = validate_characters_in_map(line, data);
		if (current == NULL)
		{
			close(fd);
			return (free(line), false);
		}
		str_add_back(head, current);
		if (current->len > data->map.size[X])
			data->map.size[X] = current->len;
		data->map.size[Y]++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (is_valid_player_and_map_size(data));
}

/*this function is responsible for allocating and copying the map.
it will also fill empty spaces in the map with the caracter SPACE*/
bool	allocate_map_and_copy(t_str *current, t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	map->map = malloc(map->size[Y] * sizeof(char *));
	if (!map->map)
		return (false);
	while (y < map->size[Y])
	{
		map->map[y] = malloc((map->size[X] + 1) * sizeof(char));
		if (!map->map[y])
		{
			free_double_pointer(map->map);
			return (perror("Error: "), false);
		}
		x = ft_strlcpy(map->map[y], current->str, map->size[X] + 1);
		while (x < map->size[X])
			map->map[y][x++] = ' ';
		map->map[y][x] = '\0';
		current = current->next;
		y++;
	}
	return (true);
}

/*opens file and does some custom error checking*/
bool	get_map(t_all *data, int fd, char *line)
{
	t_str	*head;

	head = NULL;
	while (!ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!get_size_and_individual_lines(line, fd, data, &head) || \
		!allocate_map_and_copy(head, &data->map))
		return (free_str(head), true);
	return (free_str(head), false);
}
