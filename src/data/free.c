/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:28:47 by fras          #+#    #+#                 */
/*   Updated: 2024/11/12 18:11:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_cub_data(t_map *cub)
{
	free_double_pointer(cub->map);
	free(cub->north_texture);
	free(cub->east_texture);
	free(cub->south_texture);
	free(cub->west_texture);
}

void	delete_loaded_textures(t_textures *textures)
{
	if (textures->north_texture)
		mlx_delete_texture(textures->north_texture);
	if (textures->east_texture)
		mlx_delete_texture(textures->east_texture);
	if (textures->south_texture)
		mlx_delete_texture(textures->south_texture);
	if (textures->west_texture)
		mlx_delete_texture(textures->west_texture);
	if (textures->door_open_texture)
		mlx_delete_texture(textures->door_open_texture);
	if (textures->door_closed_texture)
		mlx_delete_texture(textures->door_closed_texture);
}

void	free_data(t_all *data)
{
	free_cub_data(&data->map);
	delete_loaded_textures(&data->graphics.mainlayer.textures);
}
