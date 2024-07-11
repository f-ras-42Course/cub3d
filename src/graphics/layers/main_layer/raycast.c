
#include "graphics.h"

void	raycasting(t_mainlayer *mainlayer, int ceiling_color, int floor_color)
{
	t_ray	ray;
	double	perp_distance;
	int		wall_height;
	int		i;

	i = 0;
	ray.direction = mainlayer->player->direction - 33.10344827585 * RD;
	place_full_ceiling(mainlayer->image, ceiling_color);
	place_full_floor(mainlayer->image, floor_color);
	while (i < 66.2068965517 * (SCREEN_WIDTH / 66.2068965517))
	{
		init_ray_variables(mainlayer->player, &ray);
		perp_distance = ray_distance(ray) \
						* cos(ray.direction - mainlayer->player->direction);
		wall_height = (int)SCREEN_HEIGHT / perp_distance;
		if (wall_height > SCREEN_HEIGHT)
			wall_height = SCREEN_HEIGHT;
		place_wall(mainlayer->image, wall_height, i, 0x00ff00ff);
		ray.direction += RD / (SCREEN_WIDTH / 66.2068965517);
		i++;
	}
}

void	place_full_ceiling(mlx_image_t *image, int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, color);
}

void	place_full_floor(mlx_image_t *image, int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
	};

	draw_rect(image, measures, color);
}

void	place_wall(mlx_image_t *image, int wall_height, int position, \
					int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = 1,
	[RECT_HEIGHT] = wall_height,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2 - wall_height / 2
	};

	draw_rect(image, measures, color);
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

double	ray_distance(t_ray ray)
{
	while (1)
	{
		if (ray.shortest[X] < ray.shortest[Y])
		{
			ray.check_pos[X] += copysign(1, cos(ray.direction));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[X]);
			ray.shortest[X] += ray.delta[X];
		}
		else
		{
			ray.check_pos[Y] += copysign(1, sin(ray.direction));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[Y]);
			ray.shortest[Y] += ray.delta[Y];
		}
	}
}
