
#include "graphics.h"

void	bigmap_draw_lines(t_bigmap *bigmap, int color)
{
	t_ray	ray;
	double	bigmap_position[2];

	bigmap_position[X] = bigmap->player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = bigmap->player->position[Y] * bigmap->unit_size;
	ray.direction[X] = bigmap->player->direction[X] - 33.10344827585 * RD;
	ray.direction[Y] = bigmap->player->direction[Y] - 33.10344827585 * RD;
	for (size_t i = 0; i < 66.2068965517 * (SCREEN_WIDTH / 66.2068965517); i++)
	{
		init_line_variables(bigmap, &ray);
		draw_single_line(bigmap, &ray, bigmap_position, color);
		ray.direction[X] += RD / (SCREEN_WIDTH / 66.2068965517);
		ray.direction[Y] += RD / (SCREEN_WIDTH / 66.2068965517);
	}
}

void	bigmap_draw_single_line(t_bigmap *bigmap, int color)
{
	t_ray	ray;
	double	bigmap_position[2];

	bigmap_position[X] = bigmap->player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = bigmap->player->position[Y] * bigmap->unit_size;
	ray.direction[X] = bigmap->player->direction[X];
	ray.direction[Y] = bigmap->player->direction[Y];
	init_line_variables(bigmap, &ray);
	draw_single_line(bigmap, &ray, bigmap_position, color);
}

void	init_line_variables(t_bigmap *bigmap, t_ray *ray)
{
	ray->delta[X] = \
		sqrt(1 + (pow(sin(ray->direction[Y]) \
		/ cos(ray->direction[X]), 2)));
	ray->delta[Y] = \
		sqrt(1 + (pow(cos(ray->direction[X]) \
		/ sin(ray->direction[Y]), 2)));
	if (cos(ray->direction[X]) < 0)
		ray->increment[X] = fmod(bigmap->player->position[X], 1);
	if (cos(ray->direction[X]) >= 0)
		ray->increment[X] = 1 - fmod(bigmap->player->position[X], 1);
	if (sin(ray->direction[Y]) < 0)
		ray->increment[Y] = fmod(bigmap->player->position[Y], 1);
	if (sin(ray->direction[Y]) >= 0)
		ray->increment[Y] = 1 - fmod(bigmap->player->position[Y], 1);
	ray->shortest[X] = ray->increment[X] * ray->delta[X];
	ray->shortest[Y] = ray->increment[Y] * ray->delta[Y];
	ray->check_pos[X] = bigmap->player->position[X];
	ray->check_pos[Y] = bigmap->player->position[Y];
}


void	draw_single_line(t_bigmap *bigmap, t_ray *ray, double bigmap_position[2], int color)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = calculate_line_size(bigmap, *ray);
	while (i <= line_size)
	{
		mlx_put_pixel(bigmap->image, \
		bigmap_position[X] + i * cos(ray->direction[X]), \
		bigmap_position[Y] + i * sin(ray->direction[Y]), \
		color);
		i++;
	}
}

int	calculate_line_size(t_bigmap *bigmap, t_ray ray)
{
	while (1)
	{
		if (ray.shortest[X] < ray.shortest[Y])
		{
			ray.check_pos[X] += copysign(1, cos(ray.direction[X]));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[X] * bigmap->unit_size);
			ray.increment[X]++;
			ray.shortest[X] = ray.increment[X] * ray.delta[X];
		}
		else
		{
			ray.check_pos[Y] += copysign(1, sin(ray.direction[Y]));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[Y] * bigmap->unit_size);
			ray.increment[Y]++;
			ray.shortest[Y] = ray.increment[Y] * ray.delta[Y];
		}
	}
}
