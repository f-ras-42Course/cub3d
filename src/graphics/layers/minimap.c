
#include "graphics.h"

bool	init_minimap(t_gfx_data *graphics)
{


	graphics->minimap = mlx_new_image(graphics->mlx, \
						g_minimap_width, g_minimap_height);
	if (!graphics->minimap)
		return (false);
	draw_player_on_minimap(graphics);
	draw_minimap_walls(graphics);
	// draw_minimap_test_frame(graphics->minimap, \
	// 		fill_end_of_map);
	return (true);
}

void	draw_minimap_frame(mlx_image_t *minimap, t_minimap_options option)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g_minimap_height)
	{
		while (x < g_minimap_width)
		{
			if ((option == frame_only || option == raster_plus_frame) \
				&& ((y < g_minimap_frame_thickness \
				|| x < g_minimap_frame_thickness \
				|| x > g_minimap_width - g_minimap_frame_thickness \
				|| y > g_minimap_height - g_minimap_frame_thickness)))
				mlx_put_pixel(minimap, x, y, 0xff0000ff);
			else if ((option == raster_only || option == raster_plus_frame) \
					&& (x % g_minimap_unit_size == 0 || y % g_minimap_unit_size == 0))
					mlx_put_pixel(minimap, x, y, 0x0000ffff);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_minimap_walls(t_gfx_data *graphics)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		while (x < MAP_WIDTH)
		{
			if (g_temp_test_map[y][x] == '1')
				fill_minimap_unit(graphics->minimap, x, y, 0x0000ffff);
			x++;
		}
		x = 0;
		y++;
	}
};

void	fill_minimap_unit(mlx_image_t *minimap, int minimap_pos_x, \
			int minimap_pos_y, int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = g_minimap_unit_size,
	[RECT_HEIGHT] = g_minimap_unit_size,
	[DRAW_POS_X] = minimap_pos_x * g_minimap_unit_size,
	[DRAW_POS_Y] = minimap_pos_y * g_minimap_unit_size
	};

	draw_rect(minimap, measures, color);
}


// void	draw_player_on_minimap(t_gfx_data *graphics)
// {
// 	int	measures[4];
	
// 	measures[RECT_WIDTH] = round(g_minimap_unit_size / 3);
// 	measures[RECT_HEIGHT] = round(g_minimap_unit_size / 3);
// 	measures[DRAW_POS_X] = round((g_minimap_width / 2) - (g_minimap_unit_size / 6));
// 	measures[DRAW_POS_Y] = round((g_minimap_height / 2) - (g_minimap_unit_size / 6));
// 	draw_rect(graphics->minimap, measures, 0xff0000ff);

// 	measures[RECT_WIDTH] = round(g_minimap_unit_size / 5);
// 	measures[RECT_HEIGHT] = round(g_minimap_unit_size / 15);
// 	measures[DRAW_POS_X] = round((g_minimap_width / 2) - (g_minimap_unit_size / 8));
// 	measures[DRAW_POS_Y] = round((g_minimap_height / 2) - (g_minimap_unit_size / 4));
// 	draw_rect(graphics->minimap, measures, 0xff0000ff);
// 	measures[RECT_WIDTH] = round(g_minimap_unit_size / 15);
// 	measures[RECT_HEIGHT] = round(g_minimap_unit_size / 15);
// 	measures[DRAW_POS_X] = round((g_minimap_width / 2) - (g_minimap_unit_size / 16));
// 	measures[DRAW_POS_Y] = round((g_minimap_height / 2) - (g_minimap_unit_size / 3.5));
// 	draw_rect(graphics->minimap, measures, 0xffff00ff);
// 	// #include <stdio.h>
// 	// printf("%d, %d\n", measures[RECT_WIDTH], measures[RECT_HEIGHT]);
// 	// draw_rect(graphics->minimap, measures, 0xff0000ff);
// 	// fill_minimap_unit(graphics->minimap, measures[DRAW_POS_X], measures[DRAW_POS_Y], 0xffff00ff);
// }

void	draw_player_on_minimap(t_gfx_data *graphics)
{
	int	measures[4];
	
	measures[RECT_WIDTH] = round(g_minimap_unit_size * .3333333);
	measures[RECT_HEIGHT] = round(g_minimap_unit_size * .3333333);
	measures[DRAW_POS_X] = round((g_minimap_width * .5) - (g_minimap_unit_size * .16666));
	measures[DRAW_POS_Y] = round((g_minimap_height * .5) - (g_minimap_unit_size * .16666));
	draw_rect(graphics->minimap, measures, 0xff0000ff);

	measures[RECT_WIDTH] = round(g_minimap_unit_size * .2);
	measures[RECT_HEIGHT] = round(g_minimap_unit_size * .066666);
	measures[DRAW_POS_X] = round((g_minimap_width * .5) - (g_minimap_unit_size * .1));
	measures[DRAW_POS_Y] = round((g_minimap_height * .5) - (g_minimap_unit_size * .225));
	draw_rect(graphics->minimap, measures, 0xff0000ff);

	measures[RECT_WIDTH] = round(g_minimap_unit_size * .066666);
	measures[RECT_HEIGHT] = round(g_minimap_unit_size * .066666);
	measures[DRAW_POS_X] = round((g_minimap_width * .5) - (g_minimap_unit_size * .0333));
	measures[DRAW_POS_Y] = round((g_minimap_height * .5) - (g_minimap_unit_size * .2875));
	draw_rect(graphics->minimap, measures, 0xffff00ff);
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


void	draw_minimap_test_frame(mlx_image_t *minimap, \
			t_minimap_options option)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	y = 0;
	color = 0xff0000ff;
	while (y < g_minimap_height)
	{
		while (x < g_minimap_width)
		{
			if (option == fill_end_of_map)
			{
				mlx_put_pixel(minimap, x, y, color += 10);
				if (x % g_minimap_unit_size == 0 || y % g_minimap_unit_size == 0)
					mlx_put_pixel(minimap, x, y, color += 10);
			x++;
			}
		}
		x = 0;
		y++;
	}
}
