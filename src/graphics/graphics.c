
#include "graphics.h"

bool	init_graphics(t_all *data)
{
	data->graphics.mlx = mlx_init(screen_width(), screen_height(), "Cub3d", false);
	if (!data->graphics.mlx)
		return (error(MLX_GFX_CRASH, data), false);
	if (!is_within_monitor_limit())
	{
		keep_within_monitor_limit(DEFAULT_RESOLUTION);
		mlx_set_window_size(data->graphics.mlx, screen_width(), screen_height());
		cub3d_float_int_printer(STDOUT_FILENO, "Screen Resolution set to: %d x %d"\
							"\n", screen_width(), screen_height());
	}
	data->graphics.minimap.player = &(data->player);
	data->graphics.bigmap.player = &(data->player);
	data->graphics.mainlayer.player = &(data->player);
	data->graphics.doorlayer.player = &(data->player);
	if (!init_image(&data->graphics))
		return (error(MLX_GFX_CRASH, data), false);
	data->graphics.data = data;
	return (true);
}

void	run_graphics(t_all *data)
{
	mlx_loop(data->graphics.mlx);
}
