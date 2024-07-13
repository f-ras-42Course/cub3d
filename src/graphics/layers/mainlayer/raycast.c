
#include "graphics.h"

void	raycasting(t_mainlayer *mainlayer, uint32_t ceiling_color, uint32_t floor_color, uint32_t wall_color[4])
{
	t_ray	ray;
	double	perp_distance;
	int		wall_height;
	int		i;

	i = 0;
	ray.direction = mainlayer->player->direction - (FOV / 2) * RD;
	place_full_ceiling_colored(mainlayer->image, ceiling_color);
	place_full_floor_colored(mainlayer->image, floor_color);
	while (i < FOV * (SCREEN_WIDTH / FOV))
	{
		init_ray_variables(mainlayer->player, &ray);
		perp_distance = ray_distance(&ray) \
						* cos(ray.direction - mainlayer->player->direction);
		wall_height = (int)SCREEN_HEIGHT / perp_distance;
		if (wall_height > SCREEN_HEIGHT)
			wall_height = SCREEN_HEIGHT;
		place_wall_colored(mainlayer->image, wall_height, i, wall_color[ray.side]);
		ray.direction += RD / (SCREEN_WIDTH / FOV);
		i++;
	}
}

void	init_ray_variables(t_player *player, t_ray *ray)
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

double	ray_distance(t_ray *ray)
{
	while (1)
	{
		if (ray->shortest[X] < ray->shortest[Y])
		{
			ray->check_pos[X] += copysign(1, cos(ray->direction));
			if (wall_found(ray->check_pos[X], ray->check_pos[Y]))
			{
				set_wall_side(ray, (int)copysign(1, cos(ray->direction)));
				return (ray->shortest[X]);
			}
			ray->shortest[X] += ray->delta[X];
		}
		else
		{
			ray->check_pos[Y] += copysign(1, sin(ray->direction));
			if (wall_found(ray->check_pos[X], ray->check_pos[Y]))
			{
				set_wall_side(ray, (int)copysign(2, sin(ray->direction)));
				return (ray->shortest[Y]);
			}
			ray->shortest[Y] += ray->delta[Y];
		}
	}
}

void	set_wall_side(t_ray *ray, int side_check)
{
		if (side_check == 1)
			ray->side = E;
		if (side_check == -1)
			ray->side = W;
		if(side_check == 2)
			ray->side = S;
		if (side_check == -2)
			ray->side = N;
}
