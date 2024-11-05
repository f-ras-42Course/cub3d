
#include "graphics.h"

/**
*	while (i < screen_width())
*	
*	operates the same as:
*	
*	while (i < player->fov * (screen_width() / player->fov))
*	
*	In other words:

*	It goes exactly through the whole FOV 'x'-times for all the
*	supported resolutions. As long as workable FOVs are used.
*	
*	More info about 'workables' are found at definitions.h -> DEFAULT_FOV.
*/
void	bigmap_draw_ray_lines(const t_bigmap *bigmap, int color)
{
	int				i;
	t_ray			ray;
	double			bigmap_position[2];
	const t_player	*player = bigmap->player;

	i = 0;
	bigmap_position[X] = player->position[X] * bigmap->unit_size;
	bigmap_position[Y] = player->position[Y] * bigmap->unit_size;
	ray.direction = player->direction - (player->fov / 2) * RD;
	while (i < screen_width())
	{
		init_ray_line_variables(player, &ray);
		draw_single_ray_line(bigmap, &ray, bigmap_position, color);
		ray.direction += RD / (screen_width() / player->fov);
		i++;
	}
}

void	init_ray_line_variables(const t_player *player, t_ray *ray)
{
	printf("player pos[x] = %f, player pos[y] = %f\n", player->position[X], player->position[Y]);
	ray->delta[X] = \
		sqrt(1 + (pow(sin(ray->direction) \
		/ cos(ray->direction), 2)));
	ray->delta[Y] = \
		sqrt(1 + (pow(cos(ray->direction) \
		/ sin(ray->direction), 2)));
	printf("delta[x] = %f, delta[y] = %f\n", ray->delta[X], ray->delta[Y]);
	if (cos(ray->direction) < 0)
		ray->shortest[X] = fmod(player->position[X], 1) * ray->delta[X];
	else
		ray->shortest[X] = (1 - fmod(player->position[X], 1)) * ray->delta[X];
	if (sin(ray->direction) < 0)
		ray->shortest[Y] = fmod(player->position[Y], 1) * ray->delta[Y];
	else
		ray->shortest[Y] = (1 - fmod(player->position[Y], 1)) * ray->delta[Y];
	printf("shortest(1)[x] = %f, shortest(1)[y] = %f\n\n\n", ray->shortest[X], ray->shortest[Y]);
	ray->check_pos[X] = player->position[X];
	ray->check_pos[Y] = player->position[Y];
}

void	draw_single_ray_line(const t_bigmap *bigmap, t_ray *ray, \
							double bigmap_position[2], int color)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = calculate_line_size(bigmap, ray);
	while (i <= line_size)
	{
		mlx_put_pixel(bigmap->image, \
		bigmap_position[X] + i * cos(ray->direction), \
		bigmap_position[Y] + i * sin(ray->direction), \
		color);
		i++;
	}
}

int	calculate_line_size(const t_bigmap *bigmap, t_ray *ray)
{
	while (1)
	{
		if (ray->shortest[X] < ray->shortest[Y])
		{
			ray->check_pos[X] += copysign(1, cos(ray->direction));
			if (wall_found(ray->check_pos[X], ray->check_pos[Y])
				|| closed_door_found(ray->check_pos[X], ray->check_pos[Y]))
				return (ray->shortest[X] * bigmap->unit_size);
			ray->shortest[X] += ray->delta[X];
		}
		else
		{
			ray->check_pos[Y] += copysign(1, sin(ray->direction));
			if (wall_found(ray->check_pos[X], ray->check_pos[Y])
				|| closed_door_found(ray->check_pos[X], ray->check_pos[Y]))
				return (ray->shortest[Y] * bigmap->unit_size);
			ray->shortest[Y] += ray->delta[Y];
		}
	}
}
