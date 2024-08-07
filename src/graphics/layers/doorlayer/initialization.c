
#include "graphics.h"

bool	init_doorlayer(t_gfx_data *graphics)
{
	graphics->doorlayer.image = mlx_new_image(graphics->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!graphics->doorlayer.image)
		return (false);
	return (true);
}
