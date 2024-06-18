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
		i++;;
	}
	line[i] -= line[i];
	new = strnew(line);
	if (!new)
		perror("Error: ");
	return (new);
}

bool	get_size_and_individual_lines(char *line, int fd, \
			t_all *data, t_str **head)
{
	t_str	*current;

	while (line && ft_strcmp(line, "\n"))
	{
		current = validate_characters_in_map(line, data);
		if (current == NULL)
			return (free(line), true);
		straddback(head, current);
		if (current->len > data->map.size[X])
			data->map.size[X] =  current->len;
		data->map.size[Y]++;
		line = get_next_line(fd);
	}
	free(line);
	if (data->player.position[X] == -1)
		return (error(NO_PLAYER, data), true);
	else if (data->map.size[X] < 3 || data->map.size[Y] < 3)
		return (error(MAP_TOO_SMALL, data), true);
	return (false);
}

bool	allocate_map_and_copy(t_str *current, t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	map->map = malloc(map->size[Y] * sizeof(char *));
	if (!map->map)
		return (true);
	while (y < map->size[Y])
	{
		map->map[y] = malloc((map->size[X] + 1) * sizeof(char));
		if (!map->map[y])
		{
			perror("Error: ");
			free_double_pointer(map->map);
			return (true);
		}
		x = ft_strlcpy(map->map[y], current->str, map->size[X] + 1);
		while (x < map->size[X])
			map->map[y][x++] = ' ';
		map->map[y][x] = '\0';
		current = current->next;
		y++;
	}
	return (false);
}

bool	get_map(t_all *data, int fd, char *line)
{
	t_str	*head;

	head = NULL;
	while (!ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (get_size_and_individual_lines(line, fd, data, &head) || \
		allocate_map_and_copy(head, &data->map))
		return (free_str(head), true);
	return (free_str(head), false);
}
