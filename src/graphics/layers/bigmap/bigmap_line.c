
#include "graphics.h"

void	draw_line(t_bigmap *bigmap, int color)
{
	int	i;
	int	line_size;
	int	bigmap_position[2];

	i = 0;
	line_size = calculate_line_size(bigmap);
	bigmap_position[X] = bigmap->player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = bigmap->player->position[Y] * bigmap->unit_size;
	while (i <= line_size)
	{
		mlx_put_pixel(bigmap->image, \
		bigmap_position[X] + i * cos(bigmap->player->direction[X]), \
		bigmap_position[Y] + i * sin(bigmap->player->direction[Y]), \
		color);
		i++;
	}
}

void	init_line_variables(t_bigmap *bigmap, double delta[2], \
							double increment[2], int check_pos[2])
{
	delta[X] = \
		sqrt(1 + (pow(sin(bigmap->player->direction[Y]) \
		/ cos(bigmap->player->direction[X]), 2)));
	delta[Y] = \
		sqrt(1 + (pow(cos(bigmap->player->direction[X]) \
		/ sin(bigmap->player->direction[Y]), 2)));
	if (cos(bigmap->player->direction[X]) < 0)
		increment[X] = fmod(bigmap->player->position[X], 1);
	if (cos(bigmap->player->direction[X]) >= 0)
		increment[X] = 1 - fmod(bigmap->player->position[X], 1);
	if (sin(bigmap->player->direction[Y]) < 0)
		increment[Y] = fmod(bigmap->player->position[Y], 1);
	if (sin(bigmap->player->direction[Y]) >= 0)
		increment[Y] = 1 - fmod(bigmap->player->position[Y], 1);
	check_pos[X] = bigmap->player->position[X];
	check_pos[Y] = bigmap->player->position[Y];
}

int	calculate_line_size(t_bigmap *bigmap)
{
	double	delta[2];
	double	shortest[2];
	double	increment[2];
	int		check_pos[2];

	init_line_variables(bigmap, delta, increment, check_pos);
	while (1)
	{
		shortest[X] = increment[X] * delta[X];
		shortest[Y] = increment[Y] * delta[Y];
		if (shortest[X] < shortest[Y])
		{
			check_pos[X] += copysign(1, cos(bigmap->player->direction[X]));
			if (wall_found(check_pos[X], check_pos[Y]))
				return (shortest[X] * bigmap->unit_size);
			increment[X]++;
		}
		else
		{
			check_pos[Y] += copysign(1, sin(bigmap->player->direction[Y]));
			if (wall_found(check_pos[X], check_pos[Y]))
				return (shortest[Y] * bigmap->unit_size);
			increment[Y]++;
		}
	}
}
