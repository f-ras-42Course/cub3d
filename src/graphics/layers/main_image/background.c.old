
#include "graphics.h"

bool	init_background(t_gfx_data *graphics)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	graphics->background = rect_image_draw(graphics->mlx, \
									measures, 0x00FF00ff);
	if (!graphics->background)
		return (false);
	draw_floor(graphics->background);
	draw_sky(graphics->background);
	return (true);
}

void	draw_floor(mlx_image_t *image)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
	};

	draw_rect(image, measures, 0xADA587ff);
}

void	draw_sky(mlx_image_t *image)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, 0X87CEEBff);
}
