/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:48:13 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:52:08 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_doorlayer(t_gfx_data *graphics)
{
	graphics->doorlayer.image = \
				mlx_new_image(graphics->mlx, screen_width(), screen_height());
	if (!graphics->doorlayer.image)
		return (false);
	return (true);
}
