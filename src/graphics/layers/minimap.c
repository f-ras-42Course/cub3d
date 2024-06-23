
#include "graphics.h"

bool	init_minimap(t_gfx_data *graphics)
{
	init_minimap_values(&(graphics->minimap));
	graphics->minimap.image = mlx_new_image(graphics->mlx, \
						graphics->minimap.width, graphics->minimap.height);
	if (!graphics->minimap.image)
		return (false);
	draw_minimap_frame(graphics->minimap, raster_only);
	draw_player_on_minimap(&(graphics->minimap));
	draw_walls_on_minimap(&(graphics->minimap));
	// draw_minimap_test_frame(graphics->minimap, \
	// 		fill_end_of_map);
	return (true);
}

void	draw_minimap_frame(t_minimap minimap, t_minimap_options option)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < minimap.height)
	{
		while (x < minimap.width)
		{
			if ((option == frame_only || option == raster_plus_frame) \
				&& ((y < minimap.frame_thickness \
				|| x < minimap.frame_thickness \
				|| x > minimap.width - minimap.frame_thickness \
				|| y > minimap.height - minimap.frame_thickness)))
				mlx_put_pixel(minimap.image, x, y, 0xff0000ff);
			else if ((option == raster_only || option == raster_plus_frame) \
					&& (x % minimap.unit_size == 0 || y % minimap.unit_size == 0))
					mlx_put_pixel(minimap.image, x, y, 0x0000ffff);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_walls_on_minimap(t_minimap *minimap)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <  MINIMAP_GRID_HEIGHT)
	{
		while (x < MINIMAP_GRID_WIDTH)
		{
			if (is_minimap_unit_out_of_map_scope(minimap))
				draw_end_of_map(minimap, x, y);
			else if (wall_found(minimap))
				fill_minimap_unit(minimap, x, y, 0xff00ffff);
			x++;
			(minimap->end_of_map_locator_x)++;
		}
		minimap->end_of_map_locator_x = \
			minimap->player->position[X] - MINIMAP_GRID_WIDTH / 2;
		x = 0;
		y++;
		(minimap->end_of_map_locator_y)++;
	}
};

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
	static int		color;
	int x;
	int y;

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

// void	draw_player_on_minimap(t_gfx_data *graphics)
// {
// 	int	measures[4];
	
// 	measures[RECT_WIDTH] = round(minimap->unit_size / 3);
// 	measures[RECT_HEIGHT] = round(minimap->unit_size / 3);
// 	measures[DRAW_POS_X] = round((minimap->width / 2) - (minimap->unit_size / 6));
// 	measures[DRAW_POS_Y] = round((minimap->height / 2) - (minimap->unit_size / 6));
// 	draw_rect(graphics->minimap, measures, 0xff0000ff);

// 	measures[RECT_WIDTH] = round(minimap->unit_size / 5);
// 	measures[RECT_HEIGHT] = round(minimap->unit_size / 15);
// 	measures[DRAW_POS_X] = round((minimap->width / 2) - (minimap->unit_size / 8));
// 	measures[DRAW_POS_Y] = round((minimap->height / 2) - (minimap->unit_size / 4));
// 	draw_rect(graphics->minimap, measures, 0xff0000ff);
// 	measures[RECT_WIDTH] = round(minimap->unit_size / 15);
// 	measures[RECT_HEIGHT] = round(minimap->unit_size / 15);
// 	measures[DRAW_POS_X] = round((minimap->width / 2) - (minimap->unit_size / 16));
// 	measures[DRAW_POS_Y] = round((minimap->height / 2) - (minimap->unit_size / 3.5));
// 	draw_rect(graphics->minimap, measures, 0xffff00ff);
// 	// #include <stdio.h>
// 	// printf("%d, %d\n", measures[RECT_WIDTH], measures[RECT_HEIGHT]);
// 	// draw_rect(graphics->minimap, measures, 0xff0000ff);
// 	// fill_minimap_unit(graphics->minimap, measures[DRAW_POS_X], measures[DRAW_POS_Y], 0xffff00ff);
// }

// void	draw_player_on_minimap(t_minimap *minimap)
// {
// 	int	measures[4];
	
// 	measures[RECT_WIDTH] = round(minimap->unit_size * .3333333);
// 	measures[RECT_HEIGHT] = round(minimap->unit_size * .3333333);
// 	measures[DRAW_POS_X] = round((minimap->width * .5) - (minimap->unit_size * .16666));
// 	measures[DRAW_POS_Y] = round((minimap->height * .5) - (minimap->unit_size * .16666));
// 	draw_rect(minimap->image, measures, 0xff0000ff);

// 	measures[RECT_WIDTH] = round(minimap->unit_size * .2);
// 	measures[RECT_HEIGHT] = round(minimap->unit_size * .066666);
// 	measures[DRAW_POS_X] = round((minimap->width * .5) - (minimap->unit_size * .1));
// 	measures[DRAW_POS_Y] = round((minimap->height * .5) - (minimap->unit_size * .225));
// 	draw_rect(minimap->image, measures, 0xff0000ff);

// 	measures[RECT_WIDTH] = round(minimap->unit_size * .066666);
// 	measures[RECT_HEIGHT] = round(minimap->unit_size * .066666);
// 	measures[DRAW_POS_X] = round((minimap->width * .5) - (minimap->unit_size * .0333));
// 	measures[DRAW_POS_Y] = round((minimap->height * .5) - (minimap->unit_size * .2875));
// 	draw_rect(minimap->image, measures, 0xffff00ff);
// }

void	draw_player_on_minimap(t_minimap *minimap)
{
	const int measures[3] = {
	[RADIUS] = round(minimap->unit_size * .2),
	[DRAW_POS_CENTER_X] = round(minimap->width * .5),
	[DRAW_POS_CENTER_Y] = round(minimap->height * .5)
	};

	draw_filled_circle(minimap->image, measures, 0xff0000ff);
}


// 	draw_rect(minimap)
// }


// }

// void	draw_minimap_floors(void)
// {

// }


// -- Player looks
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o O O O o o o o o o x x x x x x x x
// x x x x x x x o o o o o o O O O o o o o o o x x x x x x x x
// x x x x x x x o o o o o o O O O o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x o o o o o o o o o o o o o o o x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x


// -- Player looks
// x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x
// x x x x x x x o x x x x x x x
// x x x x x x o o o x x x x x x
// x x x x x o o o o o x x x x x
// x x x x x o o o o o x x x x x
// x x x x x o o O o o x x x x x
// x x x x x o o o o o x x x x x
// x x x x x o o o o o x x x x x
// x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x
// x x x x x x x x x x x x x x x


// -- Player looks 640x360
// x x x x x
// x x x o x
// x x o o x
// x x o o x
// x x x x x
