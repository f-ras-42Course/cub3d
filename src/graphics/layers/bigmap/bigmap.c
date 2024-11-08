/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigmap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:47:58 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:48:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

/* Developer helper functions:
**	draw_bigmap_raster(bigmap);
**	bigmap_draw_direction_angle(bigmap, 0xffff004f);*/
void	bigmap(const t_bigmap *bigmap)
{
	draw_walls_on_bigmap(bigmap);
	bigmap_draw_ray_lines(bigmap, 0xff00004f);
	draw_player_on_bigmap(bigmap, 0xff00004f);
}

void	draw_walls_on_bigmap(const t_bigmap *bigmap)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map_height(GET))
	{
		while (x < map_width(GET))
		{
			if (wall_found(x, y))
				fill_bigmap_unit(bigmap, x, y, 0xffaa004f);
			else if (closed_door_found(x, y))
				fill_bigmap_unit(bigmap, x, y, 0xffbb004f);
			else
				fill_bigmap_unit(bigmap, x, y, 0xffffff0f);
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_bigmap_unit(const t_bigmap *bigmap, int bigmap_pos_x, \
			int bigmap_pos_y, int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = bigmap->unit_size,
	[RECT_HEIGHT] = bigmap->unit_size,
	[DRAW_POS_X] = bigmap_pos_x * bigmap->unit_size,
	[DRAW_POS_Y] = bigmap_pos_y * bigmap->unit_size
	};

	draw_rect(bigmap->image, measures, color);
}

void	draw_player_on_bigmap(const t_bigmap *bigmap, int color)
{
	const int	measures[3] = {
	[RADIUS] = round(bigmap->unit_size * .1),
	[DRAW_POS_CENTER_X] = \
						round(bigmap->player->position[X] * bigmap->unit_size),
	[DRAW_POS_CENTER_Y] = \
						round(bigmap->player->position[Y] * bigmap->unit_size)
	};

	draw_filled_circle(bigmap->image, measures, color);
}
