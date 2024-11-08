/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:49:11 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:49:12 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_minimap(t_gfx_data *graphics)
{
	init_minimap_values(&(graphics->minimap));
	graphics->minimap.image = mlx_new_image(graphics->mlx, \
						graphics->minimap.width, graphics->minimap.height);
	if (!graphics->minimap.image)
		return (false);
	return (true);
}

void	init_minimap_values(t_minimap *minimap)
{
	minimap->unit_size = (screen_width() * 0.0078125);
	minimap->width = (screen_width() / 8) - minimap->unit_size;
	minimap->height = (screen_height() / 6) - minimap->unit_size;
	minimap->frame_thickness = screen_width() * 0.002604167;
	reset_minimap_end_of_map_locator(minimap);
}
