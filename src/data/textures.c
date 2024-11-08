/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:29:04 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:47:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_texture_data(t_all *data)
{
	t_textures	*textures;

	textures = &(data->graphics.mainlayer.textures);
	if (!is_all_png_files(&(data->map)))
		return (error(TEXTURE_NO_PNG, data), false);
	all_textures_to_null(textures);
	if (!set_all_textures(textures, &(data->map)))
		return (error(TEXTURE_LOAD_FAILED, data), false);
	data->graphics.doorlayer.textures = textures;
	return (true);
}

void	all_textures_to_null(t_textures *textures)
{
	textures->ceiling_texture = NULL;
	textures->floor_texture = NULL;
	textures->north_texture = NULL;
	textures->south_texture = NULL;
	textures->east_texture = NULL;
	textures->west_texture = NULL;
}

bool	is_all_png_files(const t_map *map)
{
	if (!ends_with_png(map->north_texture))
		return (false);
	if (!ends_with_png(map->south_texture))
		return (false);
	if (!ends_with_png(map->east_texture))
		return (false);
	if (!ends_with_png(map->west_texture))
		return (false);
	return (true);
}

bool	set_all_textures(t_textures *textures, const t_map *map)
{
	textures->north_texture = mlx_load_png(map->north_texture);
	if (!textures->north_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->north_texture, STDERR_FILENO), false);
	textures->south_texture = mlx_load_png(map->south_texture);
	if (!textures->south_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->south_texture, STDERR_FILENO), false);
	textures->west_texture = mlx_load_png(map->west_texture);
	if (!textures->west_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->west_texture, STDERR_FILENO), false);
	textures->east_texture = mlx_load_png(map->east_texture);
	if (!textures->east_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->east_texture, STDERR_FILENO), false);
	textures->door_closed_texture = mlx_load_png(DOOR_TEXTURE_CLOSED);
	if (!textures->door_closed_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd(DOOR_TEXTURE_CLOSED, STDERR_FILENO), false);
	textures->door_open_texture = mlx_load_png(DOOR_TEXTURE_OPEN);
	if (!textures->door_open_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd(DOOR_TEXTURE_OPEN, STDERR_FILENO), false);
	return (true);
}

bool	ends_with_png(const char *str)
{
	int		i;

	i = ft_strlen(str);
	return (str[i - 4] == '.' \
			&& str[i - 3] == 'p' && str[i - 2] == 'n' && str[i - 1] == 'g' );
}
