
#include "data.h"

void	walking(t_all *data)
{
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_W))
	{
		wall_collision(&data->player, sin(data->player.direction) / 40, Y);
		wall_collision(&data->player, cos(data->player.direction) / 40, X);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_S))
	{
		wall_collision(&data->player, -sin(data->player.direction) / 40, Y);
		wall_collision(&data->player, -cos(data->player.direction) / 40, X);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_A))
	{
		wall_collision(&data->player, sin(data->player.direction) / 40, X);
		wall_collision(&data->player, -cos(data->player.direction) / 40, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_D))
	{
		wall_collision(&data->player, -sin(data->player.direction) / 40, X);
		wall_collision(&data->player, +cos(data->player.direction) / 40, Y);
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_RIGHT))
	{
		data->player.direction = (data->player.direction / M_PI + 0.01) * M_PI;
		if ((int)(data->player.direction / M_PI) == 2)
			data->player.direction = 0 * M_PI;
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_LEFT))
	{
		data->player.direction = (data->player.direction / M_PI - 0.01) * M_PI;
		if (copysign(1, data->player.direction / M_PI) == -1)
			data->player.direction = 2 * M_PI;
	}
}

void wall_collision(t_player *player, double increment, int axis)
{
	if (axis == X)
	{
		if (!wall_found(player->position[X] + increment, player->position[Y]))
			player->position[X] += increment;
	}
	else
	{
		if (!wall_found(player->position[X], player->position[Y] + increment))
			player->position[Y] += increment;
	}
}
