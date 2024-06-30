
#include "data.h"

void	walking(t_all *data)
{
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_W))
		data->player.position[Y] -= 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_S))
		data->player.position[Y] += 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_A))
		data->player.position[X] -= 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_D))
		data->player.position[X] += 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_LEFT))
	{
		data->player.direction[X] -= 0.05;
		data->player.direction[Y] -= 0.05;
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_RIGHT))
	{
		data->player.direction[X] += 0.05;
		data->player.direction[Y] += 0.05;
	}
}
