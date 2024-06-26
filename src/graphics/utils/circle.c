
#include "graphics.h"

void	draw_circle(mlx_image_t *image, \
					const int measures[3], unsigned int color)
{
	int		i;
	int		x;
	int		y;
	float	rotation;
	float	rotation_step;

	i = 0;
	rotation = (2 * M_PI) / (2 * measures[RADIUS] * M_PI);
	rotation_step = (2 * M_PI) / (2 * measures[RADIUS] * M_PI);
	while (i < measures[RADIUS] * 50)
	{
		x = measures[DRAW_POS_CENTER_X] + measures[RADIUS] * cos(rotation);
		y = measures[DRAW_POS_CENTER_Y] + measures[RADIUS] * sin(rotation);
		mlx_put_pixel(image, x, y, color);
		rotation += rotation_step;
		i++;
	}
}


void	draw_filled_circle(mlx_image_t *image, \
					const int measures[3], unsigned int color)
{
	int		non_const_measures[3];

	non_const_measures[RADIUS] = measures[RADIUS];
	non_const_measures[DRAW_POS_CENTER_X] = measures[DRAW_POS_CENTER_X];
	non_const_measures[DRAW_POS_CENTER_Y] = measures[DRAW_POS_CENTER_Y];
	while (non_const_measures[RADIUS] > 0)
	{
		draw_circle(image, non_const_measures, color);
		non_const_measures[RADIUS]--;
	}
}
