
#include "graphics.h"

bool	init_mainimage(t_gfx_data *graphics)
{
	graphics->main_image = mlx_new_image(graphics->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!graphics->main_image)
		return (false);
	return (true);
}
