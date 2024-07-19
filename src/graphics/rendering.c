
#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	minimap(&(graphics->minimap));
	raycasting(&(graphics->mainlayer));
	if (graphics->bigmap.image->enabled)
		bigmap(&(graphics->bigmap));
}
