/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:28:47 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:28:49 by fras          ########   odam.nl         */
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
