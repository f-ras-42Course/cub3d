
#include "graphics.h"

bool	init_texture_data(t_all *data)
{
	t_textures *textures;

	textures = &(data->graphics.mainlayer.textures);
	// if (!is_all_png_files(&(data->map)))
	// 	return (error(TEXTURE_NO_PNG, data), false);
	all_textures_to_null(textures);
	if (!set_all_textures(textures, &(data->map)))
		return (error(TEXTURE_LOAD_FAILED, data), false);
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

/*
**	Below the original code - from north_texture onwards:
	textures->north_texture = mlx_load_png(map->north_texture);
	if (!textures->north_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->north_texture, STDERR_FILENO), false);
	textures->south_texture = mlx_load_png(map->south_texture);
	if (!textures->south_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->south_texture, STDERR_FILENO), false);
	textures->east_texture = mlx_load_png(map->east_texture);
	if (!textures->east_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->east_texture, STDERR_FILENO), false);
	textures->west_texture = mlx_load_png(map->west_texture);
	if (!textures->west_texture)
		return ((void)write(STDERR_FILENO, "Couldn't load: ", 16), \
				ft_putendl_fd(map->west_texture, STDERR_FILENO), false);
*/
bool	set_all_textures(t_textures *textures, const t_map *map)
{
	textures->ceiling_texture = mlx_load_png("./textures/pack1/sky.png");
	if (!textures->ceiling_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd("./textures/pack1/sky.png", STDERR_FILENO), false);
	textures->floor_texture = mlx_load_png("./textures/pack1/sand2.png");
	if (!textures->floor_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd("./textures/pack1/sand2.png", STDERR_FILENO), false);
	
	//--- Temporary code until parsing is fixed:
	textures->north_texture = mlx_load_png("./textures/pack2/Dark/texture_01.png");
	if (!textures->north_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd(map->north_texture, STDERR_FILENO), false);
	textures->south_texture = mlx_load_png("./textures/pack2/Green/texture_09.png");
	if (!textures->south_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd(map->south_texture, STDERR_FILENO), false);
	textures->east_texture = mlx_load_png("./textures/pack2/Orange/texture_11.png");
	if (!textures->east_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd(map->east_texture, STDERR_FILENO), false);
	textures->west_texture = mlx_load_png("./textures/pack2/Red/texture_10.png");
	if (!textures->west_texture)
		return ((void)write(STDERR_FILENO, "\nCouldn't load: ", 16), \
				ft_putendl_fd(map->west_texture, STDERR_FILENO), false);
	return (true);
}

bool	ends_with_png(const char *str)
{
	int		i;

	i = ft_strlen(str);
	return(str[i - 4] == '.' \
			&& str[i - 3] == 'p' && str[i - 2] == 'n' && str[i - 1] == 'g' );
}
