/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:17:07 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:17:08 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	minimap(&(graphics->minimap));
	raycasting(&(graphics->mainlayer));
	raycasting_door(&(graphics->doorlayer));
	if (graphics->bigmap.image->enabled)
		bigmap(&(graphics->bigmap));
}
