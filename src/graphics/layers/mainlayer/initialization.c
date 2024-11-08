/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:48:39 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:58:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_mainlayer(t_gfx_data *graphics)
{
	graphics->mainlayer.image = \
				mlx_new_image(graphics->mlx, screen_width(), screen_height());
	if (!graphics->mainlayer.image)
		return (false);
	return (true);
}
