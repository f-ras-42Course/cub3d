
#include "graphics.h"

void	minimap(t_minimap *minimap)
{
	reset_minimap_end_of_map_locator(minimap);
	draw_walls_on_minimap(minimap);
	draw_player_on_minimap(minimap);
}

void	draw_walls_on_minimap(t_minimap *minimap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MINIMAP_GRID_HEIGHT)
	{
		while (x < MINIMAP_GRID_WIDTH)
		{
			if (is_minimap_unit_out_of_map_scope(minimap))
				draw_end_of_map(minimap, x, y);
			else if (wall_found(minimap->end_of_map_locator_x, \
						minimap->end_of_map_locator_y))
				fill_minimap_unit(minimap, x, y, 0xffaa00ff);
			else
				fill_minimap_unit(minimap, x, y, 0xffffff4f);
			x++;
			(minimap->end_of_map_locator_x)++;
		}
		minimap->end_of_map_locator_x = \
			(int)minimap->player->position[X] - MINIMAP_GRID_WIDTH / 2;
		x = 0;
		y++;
		(minimap->end_of_map_locator_y)++;
	}
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
