
#include "graphics.h"

void	bigmap_draw_lines(t_bigmap *bigmap, int color)
{
	t_ray	ray;
	double	bigmap_position[2];

	bigmap_position[X] = bigmap->player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = bigmap->player->position[Y] * bigmap->unit_size;
	ray.direction = bigmap->player->direction - (FOV / 2) * RD;
	for (size_t i = 0; i < FOV * (SCREEN_WIDTH / FOV); i++)
	{
		init_line_variables(bigmap->player, &ray);
		draw_single_line(bigmap, &ray, bigmap_position, color);
		ray.direction += RD / (SCREEN_WIDTH / FOV);
	}
}

void	bigmap_draw_single_line(t_bigmap *bigmap, int color)
{
	t_ray	ray;
	double	bigmap_position[2];

	bigmap_position[X] = bigmap->player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = bigmap->player->position[Y] * bigmap->unit_size;
	ray.direction = bigmap->player->direction;
	init_line_variables(bigmap->player, &ray);
	draw_single_line(bigmap, &ray, bigmap_position, color);
}


void	init_line_variables(t_player *player, t_ray *ray)
{
	ray->delta[X] = \
		sqrt(1 + (pow(sin(ray->direction) \
		/ cos(ray->direction), 2)));
	ray->delta[Y] = \
		sqrt(1 + (pow(cos(ray->direction) \
		/ sin(ray->direction), 2)));
	if (cos(ray->direction) < 0)
		ray->shortest[X] = fmod(player->position[X], 1) * ray->delta[X];
	else
		ray->shortest[X] = (1 - fmod(player->position[X], 1)) * ray->delta[X];
	if (sin(ray->direction) < 0)
		ray->shortest[Y] = fmod(player->position[Y], 1) * ray->delta[Y];
	else
		ray->shortest[Y] = (1 - fmod(player->position[Y], 1)) * ray->delta[Y];
	ray->check_pos[X] = player->position[X];
	ray->check_pos[Y] = player->position[Y];
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
		bigmap_position[X] + i * cos(ray->direction), \
		bigmap_position[Y] + i * sin(ray->direction), \
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
			ray.check_pos[X] += copysign(1, cos(ray.direction));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[X] * bigmap->unit_size);
			ray.shortest[X] += ray.delta[X];
		}
		else
		{
			ray.check_pos[Y] += copysign(1, sin(ray.direction));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[Y] * bigmap->unit_size);
			ray.shortest[Y] += ray.delta[Y];
		}
	}
}
