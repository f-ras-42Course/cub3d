/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:49:17 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:15:30 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	minimap(t_minimap *minimap)
{
	int	x;
	int	y;

	y = 0;
	reset_minimap_end_of_map_locator(minimap);
	while (y < MINIMAP_GRID_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_GRID_WIDTH)
		{
			draw_minimap(minimap, x, y);
			x++;
			(minimap->end_of_map_locator_x)++;
		}
		minimap->end_of_map_locator_x = \
			(int)minimap->player->position[X] - MINIMAP_GRID_WIDTH / 2;
		y++;
		(minimap->end_of_map_locator_y)++;
	}
	draw_player_on_minimap(minimap);
}

void	draw_minimap(t_minimap *minimap, const int x, const int y)
{
	if (minimap_unit_is_out_of_map_scope(minimap))
		draw_end_of_map(minimap, x, y);
	else if (wall_found(minimap->end_of_map_locator_x, \
				minimap->end_of_map_locator_y))
		fill_minimap_unit(minimap, x, y, 0xffaa00ff);
	else if (closed_door_found(minimap->end_of_map_locator_x, \
				minimap->end_of_map_locator_y))
		fill_minimap_unit(minimap, x, y, 0xffbb00ff);
	else
		fill_minimap_unit(minimap, x, y, 0xffffff4f);
}

void	fill_minimap_unit(t_minimap *minimap, int minimap_pos_x, \
			int minimap_pos_y, int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = minimap->unit_size,
	[RECT_HEIGHT] = minimap->unit_size,
	[DRAW_POS_X] = minimap_pos_x * minimap->unit_size,
	[DRAW_POS_Y] = minimap_pos_y * minimap->unit_size
	};

	draw_rect(minimap->image, measures, color);
}

void	draw_end_of_map(t_minimap *minimap, int raster_x, int raster_y)
{
	static int	color;
	int			x;
	int			y;

	raster_x *= minimap->unit_size;
	raster_y *= minimap->unit_size;
	x = raster_x;
	y = raster_y;
	while (y < (minimap->unit_size + raster_y))
	{
		mlx_put_pixel(minimap->image, x++, y, color += 18000000);
		if (x >= (minimap->unit_size + raster_x))
		{
			x = raster_x;
			y++;
		}
	}
}

void	draw_player_on_minimap(t_minimap *minimap)
{
	const int	measures[3] = {
	[RADIUS] = round(minimap->unit_size * .3),
	[DRAW_POS_CENTER_X] = round(minimap->width * .5),
	[DRAW_POS_CENTER_Y] = round(minimap->height * .5)
	};

	draw_filled_circle(minimap->image, measures, 0xff0000ff);
}
