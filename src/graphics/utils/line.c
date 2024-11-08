/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:16:52 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:20:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_line_textured(mlx_image_t *image, t_wall_data *wall, \
						const mlx_texture_t *texture)
{
	double		tex_position;
	int			color;
	int			x;
	int			y;

	x = wall->start_x;
	y = wall->start_y;
	tex_position = wall->tex[Y];
	while (y < (wall->line_height + wall->start_y))
	{
		color = get_color_from_pixel_data(\
				wall->tex[X], wall->tex[Y], texture);
		mlx_put_pixel(image, x, y, color);
		tex_position += wall->step[Y];
		wall->tex[Y] = tex_position;
		y++;
	}
}
