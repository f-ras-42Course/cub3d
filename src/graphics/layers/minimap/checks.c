
#include "graphics.h"

bool	minimap_unit_is_out_of_map_scope(const t_minimap *minimap)
{
	char	**map;

	map = map_data(GET);
	return (minimap->end_of_map_locator_x < 0 \
		|| minimap->end_of_map_locator_y < 0 \
		|| minimap->end_of_map_locator_x > map_width(GET) - 1 \
		|| minimap->end_of_map_locator_y > map_height(GET) - 1 \
		|| map[minimap->end_of_map_locator_y] \
							[minimap->end_of_map_locator_x] == ' ');
}

void	reset_minimap_end_of_map_locator(t_minimap *minimap)
{
	minimap->end_of_map_locator_x = \
			(int)minimap->player->position[X] - MINIMAP_GRID_WIDTH / 2;
	minimap->end_of_map_locator_y = \
			(int)minimap->player->position[Y] - MINIMAP_GRID_HEIGHT / 2;
}
