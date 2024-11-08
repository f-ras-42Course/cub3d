/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:28:43 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:28:45 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	fps_printer(t_fps *fps)
{
	if (fps->printing_enabled)
		printf("%d FPS\n", (int)(1.0 / (fps->time - fps->old_time)));
}

void	update_fps(t_fps *fps)
{
	fps->old_time = fps->time;
	fps->time = mlx_get_time();
}
