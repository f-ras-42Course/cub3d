
#include "graphics.h"

void	draw_line(t_bigmap *bigmap)
{
	int i = 0;
	// int lsz = 1 * bigmap->unit_size * sqrt(1 + (pow(cos(bigmap->player->direction[X]) / sin(bigmap->player->direction[Y]), 2)));
	int line_size = calculate_line_size(bigmap);


	while (i <= line_size)
	{
		mlx_put_pixel(bigmap->image, \
					(bigmap->player->position[X] * bigmap->unit_size) + i * cos(bigmap->player->direction[X]), \
					(bigmap->player->position[Y] * bigmap->unit_size) + i * sin(bigmap->player->direction[Y]), \
					0xffffffff);
		i++;
	}
	printf("lzs = %d\n\n", line_size);
	usleep (0.1 * 1000000);
}


int	calculate_line_size(t_bigmap *bigmap)
{
	int		increment[2];
	double	shortest[2];
	int		check_pos[2];

	increment[X] = 1;
	increment[Y] = 1;
	check_pos[X] = bigmap->player->position[X];
	check_pos[Y] = bigmap->player->position[Y];

	printf("unit size = %d\n", bigmap->unit_size);
	printf("player pos X[%.2f], player pos Y[%.2f]\n", bigmap->player->position[X], bigmap->player->position[Y]);
	printf ("x::%f | y::%f\n", shortest[X], shortest[Y]);
	printf ("dirX = %f| dirY = %f\n", cos(bigmap->player->direction[X]), sin(bigmap->player->direction[Y]));
	printf ("base-dirX = %.20f| base-dirY = %.20f\n", bigmap->player->direction[X] / M_PI, bigmap->player->direction[Y] / M_PI);
	while (1)
	{
		shortest[X] = increment[X] * sqrt(1 + (pow(sin(bigmap->player->direction[Y]) / cos(bigmap->player->direction[X]), 2)));
		shortest[Y] = increment[Y] * sqrt(1 + (pow(cos(bigmap->player->direction[X]) / sin(bigmap->player->direction[Y]), 2)));
		
		
		
		if (shortest[X] < shortest[Y])
		{
			check_pos[X] += copysign(1, cos(bigmap->player->direction[X]));
			printf ("X-check pos X: %d, check pos Y: %d\n", check_pos[X], check_pos[Y]); printf("shortest[X]:%.2f shortest[Y]:%.2f\n", shortest[X],  shortest[Y]);
			if (wall_is_seen(check_pos[X], check_pos[Y]))
			{
				if (round(cos(bigmap->player->direction[X])) == -1)
					shortest[X]--;
				return (shortest[X] * bigmap->unit_size);
			}
			increment[X]++;
		}
		else
		{
			check_pos[Y] +=  copysign(1, sin(bigmap->player->direction[Y]));
			printf ("Y-check pos X: %d, check pos Y: %d\n", check_pos[X], check_pos[Y]); printf("shortest[X]:%.2f shortest[Y]:%.2f\n", shortest[X],  shortest[Y]);
			if (wall_is_seen(check_pos[X], check_pos[Y]))
			{
				if (round(sin(bigmap->player->direction[Y])) == -1)
					shortest[Y]--;
				return (shortest[Y] * bigmap->unit_size);
			}
			increment[Y]++;
		}
	}
}


bool wall_is_seen(int x, int y)
{
	if (g_temp_test_map[y][x] == '1')
	{
		printf("wall is seen\n");
		return (true);
	}
	return (false);
}
