
#include "cub3d.h"

bool	fill_map_data(char **path_to_texture, char *line, \
			int *identifier, t_all *data)
{
	int		len;
	char	*new_path;

	len = 0;
	if (*path_to_texture != NULL)
		return (error(REPEATING_ELEMENTS, data), true);
	while (ft_iswhitespace(*line))
		line++;
	while (line[len] && !ft_iswhitespace(line[len]))
		len++;
	new_path = ft_substr(line, 0, len);
	if (!new_path)
		return (perror("Error: "), true);
	*path_to_texture = new_path;
	(*identifier)++;
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

bool	fill_rgb(int *value, char *line, t_all *data, int *id)
{
	int	rgb[3];

	if (*value != -1)
		return (error(REPEATING_ELEMENTS, data), true);
	if (fill_value(&rgb[X], &line, data) || \
		fill_value(&rgb[Y], &line, data) || \
		fill_value(&rgb[Z], &line, data))
		return (true);
	*value = get_rgb(rgb[X], rgb[Y], rgb[Z]);
	(*id)++;
	return (false);
}

bool	validate_identifier(t_all *data, t_map *map, char *line, int *id)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (fill_map_data(&map->north_texture, line + 3, id, data));
	else if (!ft_strncmp(line, "SO ", 3))
		return (fill_map_data(&map->south_texture, line + 3, id, data));
	else if (!ft_strncmp(line, "WE ", 3))
		return (fill_map_data(&map->west_texture, line + 3, id, data));
	else if (!ft_strncmp(line, "EA ", 3))
		return (fill_map_data(&map->east_texture, line + 3, id, data));
	else if (!ft_strncmp(line, "F ", 2))
		return (fill_rgb(&map->floor_color, line + 2, data, id));
	else if (!ft_strncmp(line, "C ", 2))
		return (fill_rgb(&map->ceiling_color, line + 2, data, id));
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
	else if (!line)
		error(NO_MAP, data);
	return (line);
}