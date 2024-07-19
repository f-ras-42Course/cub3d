

#include "graphics.h"

void	test_texture(mlx_image_t *image, const mlx_texture_t* texture)
{
	const int	measures[4] = {
	[RECT_WIDTH] = 1024,
	[RECT_HEIGHT] = 1024,
	[DRAW_POS_X] = 100,
	[DRAW_POS_Y] = 20
	};

	draw_rect_textured(image, measures, texture);
}


void	place_full_ceiling_textured(mlx_image_t *image, const mlx_texture_t* texture)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect_textured(image, measures, texture);
}

void	place_full_floor_textured(mlx_image_t *image, const mlx_texture_t* texture)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
	};

	draw_rect_textured(image, measures, texture);
}

void	place_wall_textured(mlx_image_t *image, int wall_height, int position, \
					const mlx_texture_t* texture)
{
	const int	measures[4] = {
	[RECT_WIDTH] = 1,
	[RECT_HEIGHT] = wall_height,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2 - wall_height / 2
	};

	draw_rect_textured(image, measures, texture);
}
