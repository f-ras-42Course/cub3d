/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graphics.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 18:13:25 by fras          #+#    #+#                 */
/*   Updated: 2024/11/11 16:09:38 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_graphics(t_all *data)
{
	data->graphics.mlx = mlx_init(screen_width(), \
									screen_height(), "Cub3d", false);
	if (!data->graphics.mlx)
		return (error(MLX_GFX_CRASH, data), false);
	if (!is_within_monitor_limit())
	{
		keep_within_monitor_limit(DEFAULT_RESOLUTION);
		mlx_set_window_size(data->graphics.mlx, \
							screen_width(), screen_height());
		printf("Screen Resolution set to: %d x %d\n", \
							screen_width(), screen_height());
	}
	set_player_pointers(data);
	set_floor_and_ceiling_color(data);
	if (!init_image(&(data->graphics)))
		return (error(MLX_GFX_CRASH, data), false);
	data->graphics.data = data;
	init_fps_images(&(data->graphics));
	bring_window_to_center(&(data->graphics));
	data->graphics.mouse_rotation_enabled = false;
	return (true);
}

void	run_graphics(t_all *data)
{
	mlx_loop(data->graphics.mlx);
	mlx_terminate(data->graphics.mlx);
}
