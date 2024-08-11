
#include "data.h"

void	fps_printer(t_fps *fps)
{
	if (fps->printing_enabled)
		cub3d_float_int_printer(STDOUT_FILENO, "%d FPS\n", (int)(1.0 / (fps->time - fps->old_time)));
}

void	update_fps(t_fps *fps)
{
	fps->old_time = fps->time;
	fps->time = mlx_get_time();
}
