
#include "graphics.h"

/* Temporary varriant on the final minimap*/
bool	init_minimap(t_gfx_data *graphics)
{


	graphics->minimap = rect_image(graphics->mlx, \
						g_minimap_width, g_minimap_height);
	if (!graphics->minimap)
		return (false);
	draw_minimap_frame(graphics->minimap);
	// draw_minimap_player(graphics->minimap);
	// draw_minimap_walls(graphics);
	return (true);
}

void	draw_minimap_frame(mlx_image_t *minimap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g_minimap_height)
	{
		while (x < g_minimap_width)
		{
			if ((y < g_minimap_frame_thickness \
				|| x < g_minimap_frame_thickness \
				|| x > (g_minimap_width - g_minimap_frame_thickness) \
				|| y > (g_minimap_height - g_minimap_frame_thickness)))
				mlx_put_pixel(minimap, x, y, 0xff0000ff);
			if (x % 10 == 0 || y % 10 == 0)
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