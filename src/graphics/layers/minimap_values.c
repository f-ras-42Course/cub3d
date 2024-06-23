#include "graphics.h"
#include "definitions.h"

void		init_minimap_values(t_minimap *minimap)
{
	minimap->unit_size = (SCREEN_WIDTH * 0.0078125);
	minimap->width = (SCREEN_WIDTH / 8) - minimap->unit_size;
	minimap->height = (SCREEN_HEIGHT / 6) - minimap->unit_size;
	minimap->frame_thickness = SCREEN_WIDTH * 0.002604167;
	minimap->end_of_map_locator_x = \
			minimap->player->position[X] - MINIMAP_GRID_WIDTH / 2;
	minimap->end_of_map_locator_y = \
			minimap->player->position[Y] - MINIMAP_GRID_HEIGHT / 2;
}

bool	is_minimap_unit_out_of_map_scope(const t_minimap *minimap)
{
	return(minimap->end_of_map_locator_x < 0 \
		|| minimap->end_of_map_locator_y < 0 \
		|| minimap->end_of_map_locator_x > MAP_WIDTH - 1 \
		|| minimap->end_of_map_locator_y > MAP_HEIGHT - 1 \
		|| g_temp_test_map[minimap->end_of_map_locator_y] \
							[minimap->end_of_map_locator_x] == ' ');
}

bool	wall_found(const t_minimap *minimap)
{
	return(g_temp_test_map[minimap->end_of_map_locator_y][minimap->end_of_map_locator_x] == '1');
}
