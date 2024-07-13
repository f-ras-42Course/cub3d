
#include "graphics.h"

bool	init_minimap(t_gfx_data *graphics)
{
	init_minimap_values(&(graphics->minimap));
	graphics->minimap.image = mlx_new_image(graphics->mlx, \
						graphics->minimap.width, graphics->minimap.height);
	if (!graphics->minimap.image)
		return (false);
	return (true);
}

void	init_minimap_values(t_minimap *minimap)
{
	minimap->unit_size = (SCREEN_WIDTH * 0.0078125);
	minimap->width = (SCREEN_WIDTH / 8) - minimap->unit_size;
	minimap->height = (SCREEN_HEIGHT / 6) - minimap->unit_size;
	minimap->frame_thickness = SCREEN_WIDTH * 0.002604167;
	reset_minimap_end_of_map_locator(minimap);
}
