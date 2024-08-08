
#include "graphics.h"

bool	init_mainlayer(t_gfx_data *graphics)
{
	graphics->mainlayer.image = mlx_new_image(graphics->mlx, screen_width(), screen_height());
	if (!graphics->mainlayer.image)
		return (false);
	return (true);
}
