/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_raycast.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:48:25 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:48:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	single_raycasting_textured(t_mainlayer *mainlayer)
{
	const t_player		*player = mainlayer->player;
	const mlx_texture_t	*wall_texture[4] = {
	[N] = mainlayer->textures.north_texture,
	[E] = mainlayer->textures.east_texture,
	[S] = mainlayer->textures.south_texture,
	[W] = mainlayer->textures.west_texture};
	t_ray				ray;
	t_wall_data			wall;

	ray.direction = player->direction;
	init_ray_variables(mainlayer->player, &ray);
	wall.ray_distance = ray_distance(&ray);
	wall.perp_distance = wall.ray_distance \
						* cos(ray.direction - player->direction);
	if (ray.side == E || ray.side == W)
		wall.step[X] = player->position[Y] + wall.ray_distance \
						* sin(player->direction);
	else
		wall.step[X] = player->position[X] + wall.ray_distance \
						* cos(player->direction);
	wall.step[X] -= floor(wall.step[X]);
	wall.tex[X] = wall.step[X] * wall_texture[ray.side]->width;
	wall.line_height = wall_height_limiter(wall.wall_height);
	wall.start_y = screen_height() / 2 - wall.line_height / 2;
	wall.step[Y] = wall_texture[ray.side]->width / (double)wall.wall_height;
}

void	single_raycasting(t_mainlayer *mainlayer, \
					uint32_t ceiling_color, uint32_t floor_color)
{
	t_ray			ray;
	uint32_t		wall_height;
	double			perp_distance;
	const t_player	*player = mainlayer->player;

	ray.direction = mainlayer->player->direction;
	init_ray_variables(mainlayer->player, &ray);
	perp_distance = ray_distance(&ray) \
					* cos(ray.direction - player->direction);
	wall_height = (uint32_t)screen_height() / perp_distance;
	if (wall_height > (uint32_t)screen_height())
		wall_height = screen_height();
	single_place_ceiling(mainlayer->image, wall_height, 0, ceiling_color);
	single_place_wall(mainlayer->image, wall_height, 0, 0x00ff00ff);
	single_place_floor(mainlayer->image, wall_height, 0, floor_color);
}

void	single_place_ceiling(mlx_image_t *image, int wall_height, int position, \
						uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = screen_width(),
	[RECT_HEIGHT] = screen_height() / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, color);
}

void	single_place_wall(mlx_image_t *image, int wall_height, int position, \
					uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = screen_width(),
	[RECT_HEIGHT] = wall_height,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = screen_height() / 2 - wall_height / 2
	};

	draw_rect(image, measures, color);
}

void	single_place_floor(mlx_image_t *image, int wall_height, int position, \
					uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = screen_width(),
	[RECT_HEIGHT] = screen_height() / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = screen_height() - (screen_height() / 2 - wall_height / 2)
	};

	draw_rect(image, measures, color);
}
