/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:48:44 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:48:45 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

/**
*	while (wall.start_x < screen_width())
*	
*	operates the same as:
*	
*	while (wall.start_x < player->fov * (screen_width() / player->fov))
*	
*	In other words:

*	It goes exactly through the whole FOV 'x'-times for all the
*	supported resolutions. As long as workable FOVs are used.
*	
*	More info about 'workables' are found at definitions.h -> DEFAULT_FOV.
*/
void	raycasting(t_mainlayer *mainlayer)
{
	const t_player		*player = mainlayer->player;
	const mlx_texture_t	*wall_texture[4] = {
	[N] = mainlayer->textures.north_texture,
	[E] = mainlayer->textures.east_texture,
	[S] = mainlayer->textures.south_texture,
	[W] = mainlayer->textures.west_texture};
	t_ray				ray;
	t_wall_data			wall;

	wall.start_x = 0;
	ray.direction = player->direction - (player->fov / 2) * RD;
	place_full_ceiling_colored(mainlayer->image, mainlayer->ceiling_color);
	place_full_floor_colored(mainlayer->image, mainlayer->floor_color);
	wall.ray = &ray;
	wall.player = mainlayer->player;
	while (wall.start_x < screen_width())
	{
		init_ray_variables(player, &ray);
		wall.ray_distance = ray_distance(&ray);
		wall.perp_distance = wall.ray_distance \
							* cos(ray.direction - player->direction);
		place_object_textured(mainlayer->image, &wall, wall_texture[ray.side]);
		ray.direction += RD / (screen_width() / player->fov);
		wall.start_x++;
	}
}

void	raycasting_colored(t_mainlayer *mainlayer, uint32_t ceiling_color, \
					uint32_t floor_color, uint32_t wall_color[4])
{
	t_ray			ray;
	double			perp_distance;
	int				wall_height;
	int				i;
	const t_player	*player = mainlayer->player;

	i = 0;
	ray.direction = player->direction - (player->fov / 2) * RD;
	place_full_ceiling_colored(mainlayer->image, ceiling_color);
	place_full_floor_colored(mainlayer->image, floor_color);
	while (i < player->fov * (screen_width() / player->fov))
	{
		init_ray_variables(player, &ray);
		perp_distance = ray_distance(&ray) \
						* cos(ray.direction - player->direction);
		wall_height = (int)screen_height() / perp_distance;
		if (player->fov == 16)
			wall_height *= 3;
		if (wall_height > screen_height())
			wall_height = screen_height();
		place_wall_colored(mainlayer->image, wall_height, i, \
							wall_color[ray.side]);
		ray.direction += RD / (screen_width() / player->fov);
		i++;
	}
}

void	init_ray_variables(const t_player *player, t_ray *ray)
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
	if (side_check == 2)
		ray->side = S;
	if (side_check == -2)
		ray->side = N;
}
