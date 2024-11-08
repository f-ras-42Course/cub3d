/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:16:59 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:20:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

uint32_t	get_color_from_pixel_data(int x, int y, \
									const mlx_texture_t *texture)
{
	uint8_t	*pixel;

	pixel = &texture->pixels[(x * texture->bytes_per_pixel) \
			+ ((y % texture->height) \
			* texture->width * texture->bytes_per_pixel)];
	return (get_rgba(*pixel, *(pixel + 1), *(pixel + 2), *(pixel + 3)));
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
