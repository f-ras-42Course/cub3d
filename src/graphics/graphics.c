
#include "graphics.h"

bool	init_graphics(t_all *data)
{
	data->graphics.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d", true);
	if (!data->graphics.mlx)
		return (error(MLX_GFX_CRASH, data), false);
	if (!init_image(&data->graphics))
		return (error(MLX_GFX_CRASH, data), false);
	data->graphics.data = data;
	data->graphics.minimap.player = &(data->player);
	data->graphics.bigmap.player = &(data->player);
	data->graphics.mainlayer.player = &(data->player);
	return (true);
}

void	run_graphics(t_all *data)
{
	mlx_loop(data->graphics.mlx);
}
