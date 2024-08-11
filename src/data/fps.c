
#include "data.h"

void	frames_per_second(t_fps *fps)
{
	fps->frames++;
	if (mlx_get_time() > fps->full_second_passed)
	{
		if (fps->enabled)
			cub3d_float_int_printer(STDOUT_FILENO, "%d FPS\n", fps->frames);
		fps->full_second_passed++;
		fps->frames = 0;
	}
}

void	init_fps(t_fps *fps)
{
	fps->enabled = false;
	fps->frames = 0;
	fps->full_second_passed = 0;
}
