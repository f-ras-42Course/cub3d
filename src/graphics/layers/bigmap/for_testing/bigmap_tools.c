
#include "graphics.h"

void		bigmap_single_ray(const t_bigmap *bigmap)
{
	draw_walls_on_bigmap(bigmap);
	bigmap_draw_direction_angle(bigmap, 0xff0000ff);
	draw_player_on_bigmap(bigmap, 0xff00004f);
}

void	bigmap_draw_direction_angle(const t_bigmap *bigmap, int color)
{
	t_ray			ray;
	double			bigmap_position[2];
	const t_player	*player = bigmap->player;

	bigmap_position[X] = player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = player->position[Y] * bigmap->unit_size;
	ray.direction = player->direction;
	init_ray_line_variables(player, &ray);
	draw_single_ray_line(bigmap, &ray, bigmap_position, color);
}

void	draw_bigmap_raster(const t_bigmap *bigmap)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < bigmap->height)
	{
		while (x < bigmap->width)
		{
			if (x % bigmap->unit_size == 0 || y % bigmap->unit_size == 0)
				mlx_put_pixel(bigmap->image, x, y, 0x0000ff4f);
			x++;
		}
		x = 1;
		y++;
	}
}
