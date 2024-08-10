
#include "graphics.h"

void	resize_all(t_gfx_data *graphics)
{
	mlx_set_window_size(graphics->mlx, screen_width(), screen_height());
	init_minimap_values(&(graphics->minimap));
	init_bigmap_values(&(graphics->bigmap));
	resize_images(graphics);
}

void 	resize_images(t_gfx_data *graphics)
{
	mlx_resize_image(graphics->mainlayer.image, screen_width(), \
					screen_height());
	mlx_resize_image(graphics->doorlayer.image, screen_width(), \
					screen_height());
	mlx_resize_image(graphics->minimap.image, graphics->minimap.width, \
					graphics->minimap.height);
	mlx_resize_image(graphics->bigmap.image, graphics->bigmap.width, \
					graphics->bigmap.height);
	graphics->minimap.image->instances->x = screen_width() * 0.865;
	graphics->minimap.image->instances->y = screen_height() * 0.015;
	graphics->bigmap.image->instances->x = graphics->bigmap.unit_size;
	graphics->bigmap.image->instances->y = graphics->bigmap.unit_size * .5;
}
