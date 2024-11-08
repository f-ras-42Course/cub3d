/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 20:17:27 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 20:17:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	set_player_pointers(t_all *data)
{
	data->graphics.minimap.player = &(data->player);
	data->graphics.bigmap.player = &(data->player);
	data->graphics.mainlayer.player = &(data->player);
	data->graphics.doorlayer.player = &(data->player);
}

void	set_floor_and_ceiling_color(t_all *data)
{
	data->graphics.mainlayer.floor_color = data->map.floor_color;
	data->graphics.mainlayer.ceiling_color = data->map.ceiling_color;
}
