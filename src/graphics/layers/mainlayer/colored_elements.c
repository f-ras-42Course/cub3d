/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colored_elements.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:48:29 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:48:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	place_full_ceiling_colored(mlx_image_t *image, uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = screen_width(),
	[RECT_HEIGHT] = screen_height() / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, color);
}

void	place_full_floor_colored(mlx_image_t *image, uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = screen_width(),
	[RECT_HEIGHT] = screen_height() / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = screen_height() / 2
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
	[DRAW_POS_Y] = screen_height() / 2 - wall_height / 2
	};

	draw_rect(image, measures, color);
}
