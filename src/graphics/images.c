
#include "graphics.h"

bool	init_image(t_gfx_data *graphics)
{
	if (!init_background(graphics))
		return (false);
	if (!init_minimap(graphics))
		return (false);
	if (!init_bigmap(graphics))
		return (false);
	if (!set_all_images_to_window(graphics))
		return (false);
	return (true);
}

bool	set_all_images_to_window(t_gfx_data *graphics)
{
	const int	minimap_pos_x = (SCREEN_WIDTH * 0.865);
	const int	minimap_pos_y = (SCREEN_HEIGHT * 0.015);

	if (mlx_image_to_window(graphics->mlx, graphics->background, 0, 0) == -1)
		return (false);
	if (mlx_image_to_window(graphics->mlx, graphics->minimap.image, minimap_pos_x, \
			minimap_pos_y) == -1)
		return (false);
	return (true);
}
