
#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	uint32_t	wall_color[4];
	uint32_t	ceiling_color;
	uint32_t	floor_color;

	wall_color[N] = 0x00ff00ff;
	wall_color[S] = 0x00ff00ff;
	wall_color[E] = 0x004f00ff;
	wall_color[W] = 0x004f00ff;
	ceiling_color = 0X87CEEBff;
	floor_color = 0xADA587ff;
	reset_minimap_end_of_map_locator(&(graphics->minimap));
	draw_walls_on_minimap(&(graphics->minimap));
	draw_player_on_minimap(&(graphics->minimap));
	raycasting(&(graphics->mainlayer), ceiling_color, floor_color, wall_color);
	bigmap(&(graphics->bigmap));
}
