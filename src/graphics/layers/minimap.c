
#include "graphics.h"

/* Temporary varriant on the final minimap*/
bool	init_minimap(t_gfx_data *graphics)
{


	graphics->minimap = rect_image(graphics->mlx, \
						g_minimap_width, g_minimap_height);
	if (!graphics->minimap)
		return (false);
	draw_minimap_frame(graphics->minimap, raster_only);
	// draw_minimap_player(graphics->minimap);
	// draw_minimap_walls(graphics);
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
					&& (x % 16 == 0 || y % 16 == 0))
				mlx_put_pixel(minimap, x, y, 0x0000ffff);
			x++;
		}
		x = 0;
		y++;
	}
}

// void	draw_minimap_player(mlx_image_t *minimap)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = 3,
// 	[RECT_HEIGHT] = 3,
// 	[DRAW_POS_X] = 0,
// 	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
// 	};

// 	draw_rect(minimap)
// }

// void	draw_minimap_walls(t_gfx_data *graphics)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = 5,
// 	[RECT_HEIGHT] = 5,
// 	[DRAW_POS_X] = 0,
// 	[DRAW_POS_Y] = 0
// 	};

// }

// void	draw_minimap_floors(void)
// {

// }



// -- Player looks
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
// x x x x x x x x x x x x x x x