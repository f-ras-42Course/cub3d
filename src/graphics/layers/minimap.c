
#include "graphics.h"

/* Temporary varriant on the final minimap*/

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

bool	init_minimap(t_gfx_data *graphics)
{


	graphics->minimap = rect_image(graphics->mlx, \
						g_minimap_width, g_minimap_height);
	if (!graphics->minimap)
		return (false);
	// draw_minimap_frame(graphics->minimap, frame_only);
	// draw_minimap_player(graphics->minimap);
	draw_minimap_walls(graphics);
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


// void	draw_minimap_player(mlx_image_t *minimap)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = 3,
// 	[RECT_HEIGHT] = 3,
// 	[DRAW_POS_X] = 0,
// 	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
// 	};
// }

// 	draw_rect(minimap)
// }


// }

// void	draw_minimap_floors(void)
// {

// }



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


// void	draw_minimap_test_frame(mlx_image_t *minimap, \
// 			t_minimap_options option)
// {
// 	int		x;
// 	int		y;
// 	int		color;

// 	x = 0;
// 	y = 0;
// 	color = 0xff0000ff;
// 	while (y < g_minimap_height)
// 	{
// 		while (x < g_minimap_width)
// 		{
// 			if (option == fill_end_of_map)
// 			{
// 				mlx_put_pixel(minimap, x, y, color += 10);
// 				if (x % g_minimap_unit_size == 0 || y % g_minimap_unit_size == 0)
// 					mlx_put_pixel(minimap, x, y, color += 10);
// 			x++;
// 			}
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
