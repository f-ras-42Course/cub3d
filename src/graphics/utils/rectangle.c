
#include "graphics.h"

mlx_image_t	*rect_image_draw(mlx_t *mlx, \
			const int measures[4], unsigned int color)
{
	mlx_image_t	*rectangle;

	rectangle = mlx_new_image(mlx, measures[RECT_WIDTH], measures[RECT_HEIGHT]);
	if (!rectangle)
		return (NULL);
	draw_rect(rectangle, measures, color);
	return (rectangle);
}

void	draw_rect(mlx_image_t *image, \
					const int measures[4], unsigned int color)
{
	int			x;
	int			y;

	x = measures[DRAW_POS_X];
	y = measures[DRAW_POS_Y];
	while (y < (measures[RECT_HEIGHT] + measures[DRAW_POS_Y]))
	{
		mlx_put_pixel(image, x++, y, color);
		if (x >= (measures[RECT_WIDTH] + measures[DRAW_POS_X]))
		{
			x = measures[DRAW_POS_X];
			y++;
		}
	}
}

mlx_image_t	*rect_image(mlx_t *mlx, int width, int height)
{
	mlx_image_t	*rectangle;

	rectangle = mlx_new_image(mlx, width, height);
	return (rectangle);
}
