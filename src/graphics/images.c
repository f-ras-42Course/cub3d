
#include "graphics.h"

bool	init_image(t_gfx_data *graphics)
{
	if (!init_background(graphics))
		return (false);
	draw_floor(graphics->background);
	// draw_sky(graphics->background);
	// if (!init_minimap(graphics))
	// 	return (false);
	if (mlx_image_to_window(graphics->mlx, graphics->background, 0, 0) == -1)
		return (false);
	return (true);
}

bool	init_background(t_gfx_data *graphics)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT,
	[POS_X] = 0,
	[POS_Y] = 0
	};

	graphics->background = rect_image_draw(graphics->mlx, \
									measures, 0x00FF00ff);
	if (!graphics->background)
		return (false);
	return (true);
}

void	draw_floor(mlx_image_t *image)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[POS_X] = 0,
	[POS_Y] = 0
	};

	draw_rect(image, measures, 0xADA587ff);
}

void	draw_sky(mlx_image_t *image)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT,
	[POS_X] = 0,
	[POS_Y] = 0
	};

	draw_rect(image, measures, 0X87CEEBff);
}


// bool	init_minimap(t_gfx_data *graphics)
// {
// 	graphics->minimap = rect_image_draw(graphics->mlx, \
// 							SCREEN_WIDTH/10, SCREEN_HEIGHT/10, 0xFF0000ff);
// 	if (!graphics->minimap)
// 		return (false);
// 	if (mlx_image_to_window(graphics->mlx, graphics->minimap, \
// 		(SCREEN_WIDTH - 200), 50) == -1)
// 		return (false);
// 	return (true);
// 	return (1);
// }
