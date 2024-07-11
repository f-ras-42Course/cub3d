
#include "graphics.h"

void	single_raycasting(t_mainlayer *mainlayer, int ceiling_color, int floor_color)
{
	t_ray	ray;
	int 	wall_height;

	ray.direction = mainlayer->player->direction;
	init_ray_variables(mainlayer->player, &ray);
	wall_height = (int)SCREEN_HEIGHT / ray_distance(ray);
	if (wall_height > SCREEN_HEIGHT)
		wall_height = SCREEN_HEIGHT;
	single_place_ceiling(mainlayer->image, wall_height, 0, ceiling_color);
	single_place_wall(mainlayer->image, wall_height, 0, 0x00ff00ff);
	single_place_floor(mainlayer->image, wall_height, 0, floor_color);
}

void	single_place_ceiling(mlx_image_t *image, int wall_height, int position, \
						int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, color);
}

void	single_place_wall(mlx_image_t *image, int wall_height, int position, \
					int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = wall_height,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2 - wall_height / 2
	};

	draw_rect(image, measures, color);
}

void	single_place_floor(mlx_image_t *image, int wall_height, int position, \
					int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] =  SCREEN_HEIGHT - (SCREEN_HEIGHT / 2 - wall_height / 2)
	};

	draw_rect(image, measures, color);
}
