
#include "graphics.h"

bool	init_image(t_gfx_data graphics)
{
	if (!init_background(graphics))
		return (false);
	if (!init_minimap(graphics))
		return (false);
	return (true);
}

bool	init_background(t_gfx_data graphics)
{
	int x;
	int y;

	x = 0;
	y = 0;
	graphics.background = draw_rect(graphics.mlx, \
									SCREEN_WIDTH, SCREEN_HEIGHT / 2, 0Xffffffff);
	if (!graphics.background)
		return (false);
	if (mlx_image_to_window(graphics.mlx, graphics.background, 0, 0) == -1)
		return (false);
	return (true);
}

bool	init_minimap(t_gfx_data graphics)
{
	graphics.minimap = mlx_new_image(graphics.mlx, \
						SCREEN_WIDTH / 10, SCREEN_HEIGHT / 10);
	if (!graphics.minimap)
		return (false);
	if (mlx_image_to_window(graphics.mlx, graphics.minimap, \
		SCREEN_WIDTH - 30, SCREEN_HEIGHT - 30) == -1)
		return (false);
	return (true);
}

// #include <stdio.h>

mlx_image_t	*draw_rect(mlx_t *mlx, int width, int height, unsigned int color)
{
	mlx_image_t	*rectangle;
	int			x;
	int			y;

	x = 0;
	y = 0;
	rectangle = mlx_new_image(mlx, width, height);
	if (!rectangle)
		return (NULL);
	while (y < height)
	{
		// printf("x = %d, y = %d\n", x, y);
		mlx_put_pixel(rectangle, x++, y, color);
		if (x >= width)
		{
			x = 0;
			y++;
		}
	}
	// printf("x = %d, y = %d\n", x, y);
	return (rectangle);
}