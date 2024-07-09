
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

void	init_line_variables(t_bigmap *bigmap, t_ray *ray)
{
	ray->delta[X] = \
		sqrt(1 + (pow(sin(bigmap->player->direction[Y]) \
		/ cos(bigmap->player->direction[X]), 2)));
	ray->delta[Y] = \
		sqrt(1 + (pow(cos(bigmap->player->direction[X]) \
		/ sin(bigmap->player->direction[Y]), 2)));
	if (cos(bigmap->player->direction[X]) < 0)
		ray->increment[X] = fmod(bigmap->player->position[X], 1);
	if (cos(bigmap->player->direction[X]) >= 0)
		ray->increment[X] = 1 - fmod(bigmap->player->position[X], 1);
	if (sin(bigmap->player->direction[Y]) < 0)
		ray->increment[Y] = fmod(bigmap->player->position[Y], 1);
	if (sin(bigmap->player->direction[Y]) >= 0)
		ray->increment[Y] = 1 - fmod(bigmap->player->position[Y], 1);
	ray->shortest[X] = ray->increment[X] * ray->delta[X];
	ray->shortest[Y] = ray->increment[Y] * ray->delta[Y];
	ray->check_pos[X] = bigmap->player->position[X];
	ray->check_pos[Y] = bigmap->player->position[Y];

}

int	calculate_line_size(t_bigmap *bigmap)
{
	t_ray	ray;

	init_line_variables(bigmap, &ray);
	while (1)
	{
		if (ray.shortest[X] < ray.shortest[Y])
		{
			ray.shortest[X] = ray.increment[X] * ray.delta[X];
			ray.check_pos[X] += copysign(1, cos(bigmap->player->direction[X]));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[X] * bigmap->unit_size);
			ray.increment[X]++;
		}
		else
		{
			ray.shortest[Y] = ray.increment[Y] * ray.delta[Y];
			ray.check_pos[Y] += copysign(1, sin(bigmap->player->direction[Y]));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[Y] * bigmap->unit_size);
			ray.increment[Y]++;
		}
	}
}
