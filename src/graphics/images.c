/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:23:12 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:25:52 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_image(t_gfx_data *graphics)
{
	if (!init_mainlayer(graphics))
		return (false);
	if (!init_doorlayer(graphics))
		return (false);
	if (!init_minimap(graphics))
		return (false);
	if (!init_bigmap(graphics))
		return (false);
	if (!set_all_images_to_window(graphics))
		return (false);
	return (true);
}

bool	set_all_images_to_window(t_gfx_data *graphics)
{
	const int	minimap_pos_x = (screen_width() * 0.865);
	const int	minimap_pos_y = (screen_height() * 0.015);

	if (mlx_image_to_window(graphics->mlx, \
						graphics->mainlayer.image, 0, 0) == -1)
		return (false);
	if (mlx_image_to_window(graphics->mlx, \
						graphics->doorlayer.image, 0, 0) == -1)
		return (false);
	if (mlx_image_to_window(graphics->mlx, graphics->minimap.image, \
						minimap_pos_x, minimap_pos_y) == -1)
		return (false);
	if (mlx_image_to_window(graphics->mlx, graphics->bigmap.image, \
			graphics->bigmap.unit_size, graphics->bigmap.unit_size * .5) == -1)
		return (false);
	return (true);
}
