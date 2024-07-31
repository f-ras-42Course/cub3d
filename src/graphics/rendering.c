
#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	minimap(&(graphics->minimap));
	if (graphics->testmode)
	{
		single_raycasting_textured(&(graphics->mainlayer), 0X87CEEBff, 0xADA587ff);
		if (graphics->bigmap.image->enabled)
			bigmap_single_ray(&(graphics->bigmap));
	}
	else
	{
		raycasting(&(graphics->mainlayer), 0X87CEEBff, 0xADA587ff);
		if (graphics->bigmap.image->enabled)
			bigmap(&(graphics->bigmap));
	}
}

