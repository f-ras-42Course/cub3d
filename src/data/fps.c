
#include "data.h"

void	show_fps(bool key_pressed)
{
	static int	second;
	static int	frames;
	static bool	fps_on;

	if (key_pressed && !fps_on)
		fps_on = true;
	else if (key_pressed && fps_on)
		fps_on = false;
	else
		frames++;
	if (mlx_get_time() > second)
	{
		if (fps_on)
			cub3d_float_int_printer(STDOUT_FILENO, "%d FPS\n", frames);
		second++;
		frames = 0;
	}
}
