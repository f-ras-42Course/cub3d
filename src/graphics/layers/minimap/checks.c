
#include "graphics.h"

bool	is_minimap_unit_out_of_map_scope(const t_minimap *minimap)
{
	return (minimap->end_of_map_locator_x < 0 \
		|| minimap->end_of_map_locator_y < 0 \
		|| minimap->end_of_map_locator_x > MAP_WIDTH - 1 \
		|| minimap->end_of_map_locator_y > MAP_HEIGHT - 1 \
		|| g_temp_test_map[minimap->end_of_map_locator_y] \
							[minimap->end_of_map_locator_x] == ' ');
}

void	reset_minimap_end_of_map_locator(t_minimap *minimap)
{
	minimap->end_of_map_locator_x = \
			(int)minimap->player->position[X] - MINIMAP_GRID_WIDTH / 2;
	minimap->end_of_map_locator_y = \
			(int)minimap->player->position[Y] - MINIMAP_GRID_HEIGHT / 2;
}
