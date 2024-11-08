/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_tools.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:49:00 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:49:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_minimap_frame(const t_minimap *minimap, t_minimap_options option)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < minimap->height)
	{
		while (x < minimap->width)
		{
			if ((option == frame_only || option == raster_plus_frame) \
				&& ((y < minimap->frame_thickness \
				|| x < minimap->frame_thickness \
				|| x > minimap->width - minimap->frame_thickness \
				|| y > minimap->height - minimap->frame_thickness)))
				mlx_put_pixel(minimap->image, x, y, 0xff0000ff);
			else if ((option == raster_only || option == raster_plus_frame) \
				&& (x % minimap->unit_size == 0 || y % minimap->unit_size == 0))
				mlx_put_pixel(minimap->image, x, y, 0x0000ffff);
			x++;
		}
		x = 0;
		y++;
	}
}
