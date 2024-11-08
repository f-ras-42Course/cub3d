/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_door.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:48:20 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:57:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	clean_sheet(mlx_image_t *image);

/**
*	while (wall.start_x < screen_width())
*	
*	operates the same as:
*	
*	while (wall.start_x * (screen_width() / player->fov))
*	
*	In other words:

*	It goes exactly through the whole FOV 'x'-times for all the
*	supported resolutions. As long as workable FOVs are used.
*	
*	More info about 'workables' are found at definitions.h -> DEFAULT_FOV.
*/
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
	while (wall.start_x < screen_width())
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
		ray.direction += RD / (screen_width() / player->fov);
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
	}
}

static void	clean_sheet(mlx_image_t *image)
{
	const int	measures[4] = {
	[RECT_WIDTH] = screen_width(),
	[RECT_HEIGHT] = screen_height(),
	[DRAW_POS_X] = 0,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, 0x0);
}
