
#include "graphics.h"

static void	clean_sheet(mlx_image_t *image)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT,
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, 0x0);
}

void	raycasting_door(t_doorlayer *doorlayer)
{
	const t_player		*player = doorlayer->player;
	t_ray				ray;
	t_wall_data			wall;

	wall.start_x = 0;
	ray.direction = player->direction - (player->fov / 2) * RD;
	wall.ray = &ray;
	wall.player = doorlayer->player;
	clean_sheet(doorlayer->image);
	while (wall.start_x < player->fov * (SCREEN_WIDTH / player->fov))
	{
		init_ray_variables(player, &ray);
		wall.ray_distance = ray_distance_door(&ray);
		wall.perp_distance = wall.ray_distance \
							* cos(ray.direction - player->direction);
		if (ray.is_door_open)
			place_object_textured(doorlayer->image, &wall, \
								doorlayer->textures->door_open_texture);
		else if (ray.is_door_closed)
			place_object_textured(doorlayer->image, &wall, \
								doorlayer->textures->door_closed_texture);
		ray.direction += RD / (SCREEN_WIDTH / player->fov);
		wall.start_x++;
	}
}

double	ray_distance_to_door(t_ray *ray, t_xyz xy)
{
		if (open_door_found(ray->check_pos[X], ray->check_pos[Y]))
			ray->is_door_open = true;
		if (closed_door_found(ray->check_pos[X], ray->check_pos[Y]))
			ray->is_door_closed = true;
		if (xy == X)
		{
			set_wall_side(ray, (int)copysign(1, cos(ray->direction)));
			return (ray->shortest[X]);
		}
		else
		{
			set_wall_side(ray, (int)copysign(2, sin(ray->direction)));
			return (ray->shortest[Y]);
		}
}

double	ray_distance_door(t_ray *ray)
{
	ray->is_door_closed = false;
	ray->is_door_open = false;
	while (1)
	{
		if (ray->shortest[X] < ray->shortest[Y])
		{
			ray->check_pos[X] += copysign(1, cos(ray->direction));
			if (wall_found(ray->check_pos[X], ray->check_pos[Y])
				|| closed_door_found(ray->check_pos[X], ray->check_pos[Y])
				|| open_door_found(ray->check_pos[X], ray->check_pos[Y]))
				return (ray_distance_to_door(ray, X));
			ray->shortest[X] += ray->delta[X];
		}
		else
		{
			ray->check_pos[Y] += copysign(1, sin(ray->direction));
			if (wall_found(ray->check_pos[X], ray->check_pos[Y])
				|| closed_door_found(ray->check_pos[X], ray->check_pos[Y])
				|| open_door_found(ray->check_pos[X], ray->check_pos[Y]))
				return (ray_distance_to_door(ray, Y));
			ray->shortest[Y] += ray->delta[Y];
		}
		// if (wall_found(ray->check_pos[X], ray->check_pos[Y]))
		// 		return (0);
	}
}
