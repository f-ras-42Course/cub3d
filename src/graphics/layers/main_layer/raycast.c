
#include "graphics.h"

void	raycasting(t_mainlayer *mainlayer, int ceiling_color, int floor_color)
{
	t_ray	ray;
	int 	wall_height;

	ray.direction[X] = mainlayer->player->direction[X] - 33.10344827585 * RD;
	ray.direction[Y] = mainlayer->player->direction[Y] - 33.10344827585 * RD;
	for (size_t i = 0; i < 66.2068965517 * (SCREEN_WIDTH / 66.2068965517); i++)
	{
		init_ray_variables(mainlayer->player, &ray);
		wall_height = (int)SCREEN_HEIGHT / ray_distance(ray);
		if (wall_height > SCREEN_HEIGHT)
			wall_height = SCREEN_HEIGHT;
		// printf("wall_height: %d\n", wall_height);
		place_ceiling(mainlayer->image, wall_height, i, ceiling_color);
		place_wall(mainlayer->image, wall_height, i, 0x00ff00ff);
		place_floor(mainlayer->image, wall_height, i, floor_color);
		ray.direction[X] += RD / (SCREEN_WIDTH / 66.2068965517);
		ray.direction[Y] += RD / (SCREEN_WIDTH / 66.2068965517);
	}
}

void	place_ceiling(mlx_image_t *image, int wall_height, int position, \
						int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = 1,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = 0
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

void	place_floor(mlx_image_t *image, int wall_height, int position, \
					int color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = 1,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] =  SCREEN_HEIGHT - (SCREEN_HEIGHT / 2 - wall_height / 2)
	};

	draw_rect(image, measures, color);
}

void	init_ray_variables(t_player *player, t_ray *ray)
{
	ray->delta[X] = \
		sqrt(1 + (pow(sin(ray->direction[Y]) \
		/ cos(ray->direction[X]), 2)));
	ray->delta[Y] = \
		sqrt(1 + (pow(cos(ray->direction[X]) \
		/ sin(ray->direction[Y]), 2)));
	if (cos(ray->direction[X]) < 0)
		ray->increment[X] = fmod(player->position[X], 1);
	if (cos(ray->direction[X]) >= 0)
		ray->increment[X] = 1 - fmod(player->position[X], 1);
	if (sin(ray->direction[Y]) < 0)
		ray->increment[Y] = fmod(player->position[Y], 1);
	if (sin(ray->direction[Y]) >= 0)
		ray->increment[Y] = 1 - fmod(player->position[Y], 1);
	ray->shortest[X] = ray->increment[X] * ray->delta[X];
	ray->shortest[Y] = ray->increment[Y] * ray->delta[Y];
	ray->check_pos[X] = player->position[X];
	ray->check_pos[Y] = player->position[Y];
}

double		ray_distance(t_ray ray)
{
	while (1)
	{
		if (ray.shortest[X] < ray.shortest[Y])
		{
			ray.check_pos[X] += copysign(1, cos(ray.direction[X]));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[X]);
			ray.increment[X]++;
			ray.shortest[X] = ray.increment[X] * ray.delta[X];
		}
		else
		{
			ray.check_pos[Y] += copysign(1, sin(ray.direction[Y]));
			if (wall_found(ray.check_pos[X], ray.check_pos[Y]))
				return (ray.shortest[Y]);
			ray.increment[Y]++;
			ray.shortest[Y] = ray.increment[Y] * ray.delta[Y];
		}
	}
}
