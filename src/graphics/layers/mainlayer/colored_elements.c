

#include "graphics.h"

void	place_full_ceiling_colored(mlx_image_t *image, uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, color);
}

void	place_full_floor_colored(mlx_image_t *image, uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
	};

	draw_rect(image, measures, color);
}

void	place_wall_colored(mlx_image_t *image, int wall_height, int position, \
					uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = 1,
	[RECT_HEIGHT] = wall_height,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2 - wall_height / 2
	};

	draw_rect(image, measures, color);
}
