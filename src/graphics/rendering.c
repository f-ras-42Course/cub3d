
#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	minimap(&(graphics->minimap));
	raycasting(&(graphics->mainlayer));
	raycasting_door(&(graphics->doorlayer));
	if (graphics->bigmap.image->enabled)
		bigmap(&(graphics->bigmap));
}
