
#include "graphics.h"

bool	init_doorlayer(t_gfx_data *graphics)
{
	graphics->doorlayer.image = mlx_new_image(graphics->mlx, screen_width(), screen_height());
	if (!graphics->doorlayer.image)
		return (false);
	return (true);
}
