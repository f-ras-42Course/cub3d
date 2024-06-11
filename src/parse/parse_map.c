
#include "cub3d.h"

void	init_map_data(t_map *data)
{
	data->map = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->floor[X] = -1;
	data->floor[Y] = -1;
	data->floor[Z] = -1;
	data->ceiling[X] = -1;
	data->ceiling[Y] = -1;
	data->ceiling[Z] = -1;
	data->index[0] = 0;
	data->index[1] = 0;
}

int	open_file(t_all *data, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1 && errno == ENOENT)
		error(NO_SUCH_FILE, data);
	else if (fd == -1)
		perror("Error: ");
	return (fd);
}

bool	fill_map_data(char **path_to_texture, char *map_s, int *id)
{
	int		len;
	char	*new_path;

	len = 0;
	while (ft_iswhitespace(*map_s))
		map_s++;
	while (map_s[len] && !ft_iswhitespace(map_s[len]))
		len++;
	new_path = ft_substr(map_s, 0, len);
	if (!new_path)
		return (perror("Error: "), true);
	if (*path_to_texture != NULL)
		free(*path_to_texture);
	else
		*id += 1;
	*path_to_texture = new_path;
	return (false);
}

bool	fill_value(int *value, char **line, t_all *data)
{
	while (**line && !ft_isdigit(**line))
		(*line)++;
	if (!ft_isdigit(**line))
		return (error(RGB, data), true);
	*value = ft_atoi(*line);
	while (**line && ft_isdigit(**line))
		(*line)++;
	return (false);
}

bool	fill_rgb(int *rgb, char *line, t_all *data, int *id)
{
	*id += (rgb[X] == -1) * 1;
	return (fill_value(&rgb[X], &line, data) || \
			fill_value(&rgb[Y], &line, data) || \
			fill_value(&rgb[Z], &line, data));
}

bool	validate_identifier(t_all *data, t_map *map, char *line, int *id)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (fill_map_data(&map->north_texture, line + 3, id));
	else if (!ft_strncmp(line, "SO ", 3))
		return (fill_map_data(&map->south_texture, line + 3, id));
	else if (!ft_strncmp(line, "WE ", 3))
		return (fill_map_data(&map->west_texture, line + 3, id));
	else if (!ft_strncmp(line, "EA ", 3))
		return (fill_map_data(&map->east_texture, line + 3, id));
	else if (!ft_strncmp(line, "F ", 2))
		return (fill_rgb(map->floor, line + 2, data, id));
	else if (!ft_strncmp(line, "C ", 2))
		return (fill_rgb(map->ceiling, line + 2, data, id));
	return (false);
}

char	*get_elements(t_all *data, int fd)
{
	char	*line;
	int		id_count;

	id_count = 0;
	line = get_next_line(fd);
	while (line && id_count < 6)
	{
		if (validate_identifier(data, &data->map, line, &id_count))
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	if (id_count != 6)
		error(NOT_ALL_ELEMENTS, data);
	return (line);
}

char	*get_identifiers(t_all *data, char *name)
{
	int		fd;

	fd = open_file(data, name);
	if (fd == -1)
		return (NULL);
	init_map_data(&data->map);
	return (get_elements(data, fd));
}

/*might turn into void function since we can use exit*/
/*if not too complicated let's try to restrain from using exit and return from main instead.
also let's use bool for boolean returns*/
bool	parse_map(t_all *data,  int argc, char *map_name)
{
	char	*first_map_line;
	int		fd;

	if (argc == 1)
		return (error(NO_MAP, data), true);
	else if (ft_strcmp(".cub", ft_strnstr(map_name, ".cub", ft_strlen(map_name))))
		return (error(NO_DOT_CUB, data), true);
	init_map_data(&data->map);
	fd = open_file(data, map_name);
	if (fd == -1)
		return (true);
	first_map_line = get_identifiers(data, map_name);
	printf("[%s]\nNO: %s\nSO: %s\nEA: %s\nWE: %s\nF %d,%d,%d\nC %d,%d,%d\n", first_map_line, \
	data->map.north_texture,data->map.south_texture, data->map.west_texture,data->map.east_texture, \
	data->map.floor[X], data->map.floor[Y], data->map.floor[Z], \
	data->map.ceiling[X], data->map.ceiling[Y], data->map.ceiling[Z]);
	// (void)first_map_line;
	free(first_map_line);
	return (false);
}
