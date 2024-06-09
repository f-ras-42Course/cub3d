
#include "graphics.h"

// bool	init_minimap(t_gfx_data *graphics)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = (SCREEN_WIDTH / 8),
// 	[RECT_HEIGHT] = (SCREEN_HEIGHT / 6),
// 	[DRAW_POS_X] = 0,
// 	[DRAW_POS_Y] = 0
// 	};

// 	graphics->minimap = rect_image_draw(graphics->mlx,
// 							measures, 0xFF0000ff);
// 	if (!graphics->minimap)
// 		return (false);
// 	return (true);
// }

/* Temporary varriant on the final minimap*/
bool	init_minimap(t_gfx_data *graphics)
{
	const int	minimap_width = (SCREEN_WIDTH / 8);
	const int	minimap_height = (SCREEN_HEIGHT / 6);

	graphics->minimap = rect_image(graphics->mlx, \
						minimap_width, minimap_height);
	if (!graphics->minimap)
		return (false);
	draw_minimap_frame(graphics->minimap);
	// draw_minimap_walls(graphics);
	return (true);
}

void	draw_minimap_frame(mlx_image_t *minimap)
{
	const int	minimap_width = (SCREEN_WIDTH / 8);
	const int	minimap_height = (SCREEN_HEIGHT / 6);
	const int	minimap_frame_thickness = 5;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < minimap_height)
	{
		while ((x < minimap_width && y < minimap_frame_thickness) \
				|| x < minimap_frame_thickness)
		{
			mlx_put_pixel(minimap, x++, y, 0xff0000ff);
		}
		x = 0;
		y++;
	}
}

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