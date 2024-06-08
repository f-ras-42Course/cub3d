
#include "graphics.h"

bool	init_minimap(t_gfx_data *graphics)
{
	const int	measures[4] = {
	[RECT_WIDTH] = (SCREEN_WIDTH / 8),
	[RECT_HEIGHT] = (SCREEN_HEIGHT / 6),
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	graphics->minimap = rect_image_draw(graphics->mlx, \
							measures, 0xFF0000ff);
	if (!graphics->minimap)
		return (false);
	return (true);
}
