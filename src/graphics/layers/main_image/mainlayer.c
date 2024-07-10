
#include "graphics.h"

bool	init_mainlayer(t_gfx_data *graphics)
{
	graphics->mainlayer.image = mlx_new_image(graphics->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!graphics->mainlayer.image)
		return (false);
	return (true);
}
