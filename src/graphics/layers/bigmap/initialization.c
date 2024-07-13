
#include "graphics.h"

bool	init_bigmap(t_gfx_data *graphics)
{
	init_bigmap_values(&(graphics->bigmap));
	graphics->bigmap.image = mlx_new_image(graphics->mlx, \
						graphics->bigmap.width, graphics->bigmap.height);
	if (!graphics->bigmap.image)
		return (false);
	return (true);
}

void	init_bigmap_values(t_bigmap *bigmap)
{
	bigmap->unit_size = (SCREEN_WIDTH * .03125);
	bigmap->width = (SCREEN_WIDTH * 0.75) - bigmap->unit_size;
	bigmap->height = SCREEN_HEIGHT - bigmap->unit_size;
}
