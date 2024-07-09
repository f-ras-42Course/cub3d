
#include "graphics.h"

void	draw_line(t_bigmap *bigmap, int color)
{
	int i = 0;
	int line_size = calculate_line_size(bigmap);

	while (i <= line_size)
	{
		mlx_put_pixel(bigmap->image, \
					(bigmap->player->position[X] * bigmap->unit_size) + i * cos(bigmap->player->direction[X]), \
					(bigmap->player->position[Y] * bigmap->unit_size) + i * sin(bigmap->player->direction[Y]), \
					color);
		i++;
	}
}

void	init_line_variables(t_bigmap *bigmap, double shortest[2], double increment[2], int check_pos[2])
{
	check_pos[X] = bigmap->player->position[X];
	check_pos[Y] = bigmap->player->position[Y];
	if (cos(bigmap->player->direction[X]) < 0)
		increment[X] = fmod(bigmap->player->position[X], 1);
	if (cos(bigmap->player->direction[X]) >= 0)
		increment[X] = 1 - fmod(bigmap->player->position[X], 1);
	if (sin(bigmap->player->direction[Y]) < 0)
		increment[Y] = fmod(bigmap->player->position[Y], 1);
	if (sin(bigmap->player->direction[Y]) >= 0)
		increment[Y] = 1 - fmod(bigmap->player->position[Y], 1);
	shortest[X] = increment[X] * sqrt(1 + (pow(sin(bigmap->player->direction[Y]) / cos(bigmap->player->direction[X]), 2)));
	shortest[Y] = increment[Y] * sqrt(1 + (pow(cos(bigmap->player->direction[X]) / sin(bigmap->player->direction[Y]), 2)));
}

int		calculate_line_size(t_bigmap *bigmap)
{
	double	shortest[2];
	double	increment[2];
	int		check_pos[2];

	init_line_variables(bigmap, shortest, increment, check_pos);
	while (1)
	{
		if (shortest[X] < shortest[Y])
		{
			check_pos[X] += copysign(1, cos(bigmap->player->direction[X]));
			if (wall_is_seen(check_pos[X], check_pos[Y], bigmap->player->direction[X], bigmap->player->direction[Y]))
				return (shortest[X] * bigmap->unit_size);
			increment[X]++;
			shortest[X] = increment[X] * sqrt(1 + (pow(sin(bigmap->player->direction[Y]) / cos(bigmap->player->direction[X]), 2)));
		}
		else
		{
			check_pos[Y] +=  copysign(1, sin(bigmap->player->direction[Y]));
			if (wall_is_seen(check_pos[X], check_pos[Y], bigmap->player->direction[X], bigmap->player->direction[Y]))
				return (shortest[Y] * bigmap->unit_size);
			increment[Y]++;
			shortest[Y] = increment[Y] * sqrt(1 + (pow(cos(bigmap->player->direction[X]) / sin(bigmap->player->direction[Y]), 2)));
		}
	}
}

bool wall_is_seen(int x, int y, int dir_x, int dir_y)
{
	if (g_temp_test_map[y][x] == '1')
		return (true);
	return (false);
}
