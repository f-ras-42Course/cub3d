
#include "graphics.h"

bool	init_bigmap(t_gfx_data *graphics)
{
	init_bigmap_values(&(graphics->bigmap));
	graphics->bigmap.image = mlx_new_image(graphics->mlx, \
						graphics->bigmap.width, graphics->bigmap.height);
	if (!graphics->bigmap.image)
		return (false);
	graphics->bigmap.image->enabled = false;
	return (true);
}

void	init_bigmap_values(t_bigmap *bigmap)
{
	if (map_width(GET) <= 13 && map_height(GET) <= 8)
		bigmap->unit_size = (screen_width() * .06250);
	else if (map_width(GET) * .66667 > map_height(GET))
		bigmap->unit_size = screen_width() * .03125 / (1 << (int)log2((map_width(GET) - 1) / 13));
	else
		bigmap->unit_size = screen_width() * .03125 / (1 << (int)log2(map_height(GET) / 9));
	bigmap->width = (screen_width() * 0.8125);
	bigmap->height = screen_height() - bigmap->unit_size;
}
