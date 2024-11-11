/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:22:09 by fras          #+#    #+#                 */
/*   Updated: 2024/11/11 18:20:59 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

bool	load_hooks(t_all *data)
{
	mlx_key_hook(data->graphics.mlx, key_hooks, data);
	mlx_cursor_hook(data->graphics.mlx, cursor_hooks, data);
	if (!mlx_loop_hook(data->graphics.mlx, loop_hooks, data))
		return (error(MLX_HOOKS_CRASH, data), false);
	return (true);
}

void	loop_hooks(void *ptr_to_data)
{
	t_all	*data;

	data = ptr_to_data;
	update_fps(&(data->fps));
	walking(data);
	update_image(&(data->graphics));
	fps_printer(&(data->fps));
	fps_to_screen(&(data->graphics), &(data->fps));
}

void	key_hooks(mlx_key_data_t keydata, void *ptr_to_data)
{
	t_all	*data;

	data = ptr_to_data;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			mlx_close_window(data->graphics.mlx);
		if (keydata.key == MLX_KEY_F)
			fps_ioswitch(&(data->graphics), &(data->fps));
		if (keydata.key == MLX_KEY_V && keydata.key != MLX_KEY_Z)
			change_fov(data);
		if (keydata.key == MLX_KEY_Z)
			zoom_in(data);
		if (keydata.key == MLX_KEY_M)
			bigmap_io_switch(&(data->graphics.bigmap));
		if (keydata.key == MLX_KEY_SPACE)
			open_close_door(&(data->player));
		if (keydata.key == MLX_KEY_MINUS)
			decrease_resolution(&(data->graphics));
		if (keydata.key == MLX_KEY_EQUAL)
			increase_resolution(&(data->graphics));
		if (keydata.key == MLX_KEY_LEFT_SHIFT)
			mouse_rotation_ioswitch(&(data->graphics));
	}
}

void	open_close_door(t_player *player)
{
	const double	distance_to_wall[2] = {
	[X] = copysign(0.5, cos(player->direction)),
	[Y] = copysign(0.5, sin(player->direction))
	};
	const int		check_here[2] = {
	[X] = (int)(player->position[X] + distance_to_wall[X]),
	[Y] = (int)(player->position[Y] + distance_to_wall[Y])
	};

	if (closed_door_found(check_here[X], player->position[Y]))
		open_door(check_here[X], player->position[Y]);
	else if (closed_door_found(player->position[X], check_here[Y]))
		open_door(player->position[X], check_here[Y]);
	else if (open_door_found(check_here[X], player->position[Y]))
		close_door(check_here[X], player->position[Y]);
	else if (open_door_found(player->position[X], check_here[Y]))
		close_door(player->position[X], check_here[Y]);
}

void	cursor_hooks(double xpos, double ypos, void *ptr_to_data)
{
	t_all		*data;

	(void)ypos;
	data = ptr_to_data;
	if (!data->graphics.mouse_rotation_enabled)
		return ;
	mouse_rotate(data, xpos);
}
