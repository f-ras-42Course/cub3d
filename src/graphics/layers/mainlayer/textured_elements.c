
#include "graphics.h"

void	place_object_textured(mlx_image_t *image, t_wall_data *wall, \
					const mlx_texture_t *texture)
{
	if (wall->ray->side == E || wall->ray->side == W)
		wall->step[X] = wall->player->position[Y] + wall->ray_distance \
						* sin(wall->ray->direction);
	else
		wall->step[X] = wall->player->position[X] + wall->ray_distance \
						* cos(wall->ray->direction);
	wall->wall_height = (int)screen_height() / wall->perp_distance;
	if (wall->player->fov == 16)
		wall->wall_height *= 3;
	wall->step[X] -= floor(wall->step[X]);
	wall->tex[X] = wall->step[X] * texture->width;
	if (wall->ray->side == W || wall->ray->side == S)
		wall->tex[X] = texture->width - wall->tex[X] - 1;
	wall->line_height = wall_height_limiter(wall->wall_height);
	wall->start_y = screen_height() / 2 - wall->line_height / 2;
	wall->step[Y] = texture->height / (double)wall->wall_height;
	if (wall->wall_height > screen_height())
		wall->tex[Y] = (wall->wall_height - screen_height()) / 2 * wall->step[Y];
	else
		wall->tex[Y] = 0;
	draw_line_textured(image, wall, texture);
}

int	wall_height_limiter(int wall_height)
{
	if (wall_height > screen_height())
		return (screen_height());
	return (wall_height);
}

// void	test_texture(mlx_image_t *image, const mlx_texture_t *texture)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = texture->width,
// 	[RECT_HEIGHT] = texture->height,
// 	[DRAW_POS_X] = 100,
// 	[DRAW_POS_Y] = 20
// 	};
// }
