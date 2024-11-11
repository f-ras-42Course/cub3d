/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 18:17:29 by fras          #+#    #+#                 */
/*   Updated: 2024/11/11 18:21:18 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	walking(t_all *data)
{
	const double	move_speed = (data->fps.time - data->fps.old_time) * 2.0;
	const double	rotate_speed = (data->fps.time - data->fps.old_time) * 0.5;

	move(data, move_speed);
	rotate(data, rotate_speed);
}

void	move(t_all *data, const double speed)
{
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_W))
	{
		no_collide(&data->player, cos(data->player.direction) * speed, X);
		no_collide(&data->player, sin(data->player.direction) * speed, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_S))
	{
		no_collide(&data->player, -sin(data->player.direction) * speed, Y);
		no_collide(&data->player, -cos(data->player.direction) * speed, X);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_A))
	{
		no_collide(&data->player, sin(data->player.direction) * speed, X);
		no_collide(&data->player, -cos(data->player.direction) * speed, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_D))
	{
		no_collide(&data->player, -sin(data->player.direction) * speed, X);
		no_collide(&data->player, +cos(data->player.direction) * speed, Y);
	}
}

void	rotate(t_all *data, const double speed)
{
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_RIGHT))
	{
		data->player.direction = (data->player.direction / M_PI + speed) * M_PI;
		if ((int)(data->player.direction / M_PI) == 2)
			data->player.direction = 0 * M_PI;
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_LEFT))
	{
		data->player.direction = (data->player.direction / M_PI - speed) * M_PI;
		if (copysign(1, data->player.direction / M_PI) == -1)
			data->player.direction = 2 * M_PI;
	}
}

void	no_collide(t_player *player, double increment, t_xyz axis)
{
	const int	wanna_walk[2] = {
	[X] = player->position[X] + increment,
	[Y] = player->position[Y] + increment
	};

	if (axis == X)
	{
		if (!wall_found(wanna_walk[X], player->position[Y]) && \
			!closed_door_found(wanna_walk[X], player->position[Y]))
			player->position[X] += increment;
	}
	else
	{
		if (!wall_found(player->position[X], wanna_walk[Y]) && \
			!closed_door_found(player->position[X], wanna_walk[Y]))
			player->position[Y] += increment;
	}
}

void	mouse_rotate(t_all *data, double xpos)
{
	const double	rot_speed = (data->fps.time - data->fps.old_time) * 0.05;
	const int		screen_mid[2] = {
	[X] = screen_width() / 2,
	[Y] = screen_height() / 2};

	if (xpos < screen_mid[X])
	{
		data->player.direction = (data->player.direction / M_PI - (rot_speed \
		* (screen_mid[X] - xpos))) * M_PI;
		if (copysign(1, data->player.direction / M_PI) == -1)
			data->player.direction = 2 * M_PI;
	}
	if (xpos > screen_mid[X])
	{
		data->player.direction = (data->player.direction / M_PI + (rot_speed \
		* (xpos - screen_mid[X]))) * M_PI;
		if ((int)(data->player.direction / M_PI) == 2)
			data->player.direction = 0 * M_PI;
	}
	mlx_set_mouse_pos(data->graphics.mlx, screen_mid[X], screen_mid[Y]);
}
