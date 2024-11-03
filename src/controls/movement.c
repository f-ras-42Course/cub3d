
#include "data.h"

void	walking(t_all *data)
{
	const double	mov_speed = (data->fps.time - data->fps.old_time) * 2.0;
	const double	rot_speed = (data->fps.time - data->fps.old_time) * 0.5;
	
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_W))
	{
		wall_collision(&data->player, cos(data->player.direction) * mov_speed, X);
		wall_collision(&data->player, sin(data->player.direction) * mov_speed, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_S))
	{
		wall_collision(&data->player, -sin(data->player.direction) * mov_speed, Y);
		wall_collision(&data->player, -cos(data->player.direction) * mov_speed, X);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_A))
	{
		wall_collision(&data->player, sin(data->player.direction) * mov_speed, X);
		wall_collision(&data->player, -cos(data->player.direction) * mov_speed, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_D))
	{
		wall_collision(&data->player, -sin(data->player.direction) * mov_speed, X);
		wall_collision(&data->player, +cos(data->player.direction) * mov_speed, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_RIGHT))
	{
		data->player.direction = (data->player.direction / M_PI + rot_speed) * M_PI;
		if ((int)(data->player.direction / M_PI) == 2)
			data->player.direction = 0 * M_PI;
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_LEFT))
	{
		data->player.direction = (data->player.direction / M_PI - rot_speed) * M_PI;
		if (copysign(1, data->player.direction / M_PI) == -1)
			data->player.direction = 2 * M_PI;
	}
}

void wall_collision(t_player *player, double increment, t_xyz axis)
{
	if (axis == X)
	{
		if (!wall_found(player->position[X] + increment, player->position[Y]) &&
			!closed_door_found(player->position[X] + increment, player->position[Y]))
			player->position[X] += increment;
	}
	else
	{
		if (!wall_found(player->position[X], player->position[Y] + increment) &&
			!closed_door_found(player->position[X], player->position[Y] + increment))
			player->position[Y] += increment;
	}
}
