
#include "graphics.h"

void	draw_line(t_bigmap *bigmap)
{
	int i = 0;
	int lsz = 1 * bigmap->unit_size /** sqrt(1 + (pow(cos(bigmap->player->direction[X]) / sin(bigmap->player->direction[Y]), 2)))*/;

	while (i <= lsz)
	{
		mlx_put_pixel(bigmap->image, \
					(bigmap->player->position[X] * bigmap->unit_size) + i * cos(bigmap->player->direction[X]), \
					(bigmap->player->position[Y] * bigmap->unit_size) + i * sin(bigmap->player->direction[Y]), \
					0xffffffff);
		i++;
	}
}


// void	calc_line(t_bigmap *bigmap)
// {
// 	int measures[3] = {
// 	[RADIUS] = bigmap->unit_size * .05,
// 	[DRAW_POS_CENTER_X] = 9 * bigmap->unit_size,
// 	[DRAW_POS_CENTER_Y] = 4 * bigmap->unit_size
// 	};
// 	draw_circle(bigmap->image, measures, 0x000000ff);

// 	int i = 0;
// 	double cinp = 1.75 * M_PI;
// 	double sinp = 1.75 * M_PI;
// 	int sy = i * bigmap->unit_size * sqrt(1 + (pow(cos(cinp) / sin(sinp), 2)));
// 	int sx = i * bigmap->unit_size * sqrt(1 + (pow(sin(sinp) / cos(cinp) , 2)));


// 	// int		i;
// 	// int		x;
// 	// int		y;
// 	// float	rotation;
// 	// float	rotation_step;

// 	// i = 0;
// 	// rotation = 0;
// 	// rotation_step = (2 * M_PI) / (2 * measures[RADIUS] * M_PI);
// 	// while (i < 100)
// 	// {
// 	// 	x = measures[DRAW_POS_CENTER_X] + measures[RADIUS] * cos(rotation);
// 	// 	y = measures[DRAW_POS_CENTER_Y] + measures[RADIUS] * sin(rotation);
// 	// 	mlx_put_pixel(image, x, y, color);
// 	// 	rotation += rotation_step;
// 	// 	i++;
// 	// }
// }
