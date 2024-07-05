
#include "data.h"

void	walking(t_all *data)
{

	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_W))
		data->player.position[Y] -= 0.02;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_S))
		data->player.position[Y] += 0.02;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_A))
		data->player.position[X] -= 0.02;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_D))
		data->player.position[X] += 0.02;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_RIGHT))
	{
		data->player.direction[X] = (data->player.direction[X] / M_PI + 0.05) * M_PI;
		data->player.direction[Y] = (data->player.direction[Y] / M_PI + 0.05) * M_PI;
	}
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_LEFT))
	{
		data->player.direction[X] = (data->player.direction[X] / M_PI - 0.05) * M_PI;
		data->player.direction[Y] = (data->player.direction[Y] / M_PI - 0.05) * M_PI;
	}
}

/*

0x12   0x13
dest < src
ab ccde fh

abc cdef h


ab cdef gh

abc defg h

*/