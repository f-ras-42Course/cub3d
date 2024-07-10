
#include "graphics.h"

bool	init_bigmap(t_gfx_data *graphics)
{
	init_bigmap_values(&(graphics->bigmap));
	graphics->bigmap.image = mlx_new_image(graphics->mlx, \
						graphics->bigmap.width, graphics->bigmap.height);
	if (!graphics->bigmap.image)
		return (false);
	return (true);
}

void	draw_bigmap_raster(t_bigmap bigmap)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < bigmap.height)
	{
		while (x < bigmap.width)
		{
				if (x % bigmap.unit_size == 0 || y % bigmap.unit_size == 0)
					mlx_put_pixel(bigmap.image, x, y, 0x0000ffff);
			x++;
		}
		x = 1;
		y++;
	}
}

void	init_bigmap_values(t_bigmap *bigmap)
{
	bigmap->unit_size = (SCREEN_WIDTH * .03125);
	bigmap->width = (SCREEN_WIDTH * 0.75) - bigmap->unit_size;
	bigmap->height = SCREEN_HEIGHT - bigmap->unit_size;
}

void	draw_walls_on_bigmap(t_bigmap *bigmap)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <  MAP_HEIGHT)
	{
		while (x < MAP_WIDTH)
		{
			if (wall_found(x, y))
				fill_bigmap_unit(bigmap, x, y, 0xffaa00ff);
			else
				fill_bigmap_unit(bigmap, x, y, 0xffffff4f);
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_bigmap_unit(t_bigmap *bigmap, int bigmap_pos_x, \
			int bigmap_pos_y, int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = bigmap->unit_size,
	[RECT_HEIGHT] = bigmap->unit_size,
	[DRAW_POS_X] = bigmap_pos_x * bigmap->unit_size,
	[DRAW_POS_Y] = bigmap_pos_y * bigmap->unit_size
	};

	draw_rect(bigmap->image, measures, color);
}

void	draw_player_on_bigmap(t_bigmap *bigmap, int color)
{
	const int measures[3] = {
	[RADIUS] = round(bigmap->unit_size * .1),
	[DRAW_POS_CENTER_X] = round(bigmap->player->position[X] * bigmap->unit_size),
	[DRAW_POS_CENTER_Y] = round(bigmap->player->position[Y] * bigmap->unit_size)
	};

	draw_filled_circle(bigmap->image, measures, color);
}
