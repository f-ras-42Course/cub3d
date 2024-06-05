
#include "graphics.h"

bool	init_graphics(t_all *data)
{
	data->graphics.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d", true);
	if (!data->graphics.mlx)
		return (error(MLX_CRASH, data), false);
	return (true);
}

void	run_graphics(t_all *data)
{
	mlx_loop(data->graphics.mlx);
}
