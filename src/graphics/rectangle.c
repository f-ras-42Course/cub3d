
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

	x = measures[POS_X];
	y = measures[POS_Y];

	while (y < measures[RECT_HEIGHT])
	{
		mlx_put_pixel(image, x++, y, color);
		if (x >= measures[RECT_WIDTH])
		{
			x = 0;
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

/* 
	-- test functions for draw rect --

	 printf("ended (x = %d, y = %d)\n", x, y);
		printf("x = %d, y = %d\n", x, y);
	printf("start: x = %d, y = %d\n", x, y); 
*/