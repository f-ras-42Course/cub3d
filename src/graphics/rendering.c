
#include "graphics.h"

void	update_image(t_gfx_data *graphics)
{
	int	wall_color[4];
	int	ceiling_color;
	int	floor_color;

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
	// draw_walls_on_bigmap(&(graphics->bigmap));
	// draw_bigmap_raster((graphics->bigmap));
	// bigmap_draw_single_line(&(graphics->bigmap), 0xff00004f);
	// bigmap_draw_lines(&(graphics->bigmap), 0xff00004f);
	// draw_player_on_bigmap(&(graphics->bigmap), 0xff00004f);
}
