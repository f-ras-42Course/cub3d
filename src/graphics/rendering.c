
#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	reset_minimap_end_of_map_locator(&(graphics->minimap));
	draw_walls_on_minimap(&(graphics->minimap));
	draw_player_on_minimap(&(graphics->minimap));
	draw_walls_on_bigmap(&(graphics->bigmap));
	draw_bigmap_raster((graphics->bigmap));
	draw_line(&(graphics->bigmap));
	draw_player_on_bigmap(&(graphics->bigmap));
}
