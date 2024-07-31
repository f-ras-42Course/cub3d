
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

void draw_line_textured(mlx_image_t *image, t_wall_data *wall, \
						const mlx_texture_t *texture)
{
	double		tex_position;
	int			color;
	int			x;
	int			y;

	x = wall->start_x;
	y = wall->start_y;
	// printf("Y: %d\n", y);
	tex_position = wall->tex[Y];
	printf("test: %d\n", wall->tex[Y]);
	while (y < (wall->line_height + wall->start_y))
	{
		color = get_color_from_pixel_data(\
				wall->tex[X], wall->tex[Y], texture);
		mlx_put_pixel(image, x, y, color);
		tex_position += wall->step[Y];
		wall->tex[Y] = tex_position;
		y++;
	}
	// printf("end tex[Y]: %d\n", wall->tex[Y]);
}



// void	draw_rect_textured(mlx_image_t *image, \
// 					const int measures[4], int texX, int texY, const mlx_texture_t *texture)
// {
// 	int			color;
// 	int			x;
// 	int			y;

// 	x = measures[DRAW_POS_X];
// 	y = measures[DRAW_POS_Y];
// 	// printf("Y: %d\n", y);
// 	while (y < (measures[RECT_HEIGHT] + measures[DRAW_POS_Y]))
// 	{
// 		color = get_color_from_pixel_data(\
// 				texX, y, texture);
// 		mlx_put_pixel(image, x, y, color);
// 		x++;
// 		if (x >= (measures[RECT_WIDTH] + measures[DRAW_POS_X]))
// 		{
// 			x = measures[DRAW_POS_X];
// 			y++;
// 		}
// 	}
// }
