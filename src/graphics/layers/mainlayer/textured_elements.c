

#include "graphics.h"

// void	test_texture(mlx_image_t *image, const mlx_texture_t* texture)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = 1024,
// 	[RECT_HEIGHT] = 1024,
// 	[DRAW_POS_X] = 100,
// 	[DRAW_POS_Y] = 20
// 	};

// 	draw_line_textured(image, measures, texture);
// }


// void	place_full_ceiling_textured(mlx_image_t *image, const mlx_texture_t* texture)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = SCREEN_WIDTH,
// 	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
// 	[DRAW_POS_X] = 0,
// 	[DRAW_POS_Y] = 0
// 	};

// 	draw_line_textured(image, measures, texture);
// }

// void	place_full_floor_textured(mlx_image_t *image, const mlx_texture_t* texture)
// {
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = SCREEN_WIDTH,
// 	[RECT_HEIGHT] = SCREEN_HEIGHT / 2,
// 	[DRAW_POS_X] = 0,
// 	[DRAW_POS_Y] = SCREEN_HEIGHT / 2
// 	};

// 	draw_line_textured(image, measures, texture);
// }

void	place_wall_textured(mlx_image_t *image, t_wall_data *wall,\
					const mlx_texture_t* texture)
{
	if (wall->ray->side == 'S' || wall->ray->side == 'N')
		wall->step[X] = wall->player->position[Y] + wall->perp_distance * sin(wall->ray->direction);
	else
		wall->step[X] = wall->player->position[X] + wall->perp_distance * cos(wall->ray->direction);
	wall->wall_height = (int)SCREEN_HEIGHT / wall->perp_distance;
	if (wall->player->fov == 16)
		wall->wall_height *= 3;
	
	wall->step[X] -= floor(wall->step[X]);
	wall->tex[X] = wall->step[X] * texture->width;

	wall->line_height = wall_height_limiter(wall->wall_height);
	wall->start_y = SCREEN_HEIGHT / 2 - wall_height_limiter(wall->wall_height) / 2;
	wall->step[Y] = texture->height / (double)wall->wall_height;
	if (SCREEN_HEIGHT - wall->wall_height < 0)
		wall->tex[Y] = (wall->wall_height - SCREEN_HEIGHT) / 2 * wall->step[Y];
	else
		wall->tex[Y] = 0;
	// if (wall->ray->side == 'S' || wall->ray->side == 'W')
	// 	wall->tex[X] = (int)texture->width - wall->tex[X] - 1;

	printf("perp: %f, wall_height = %d\n", wall->perp_distance, wall->wall_height);
	// printf("WallX = %f - texX = %d\n", wallX, tex[X]);
	printf("JAJA: %d\n", SCREEN_HEIGHT / 2 - wall->wall_height / 2);
	printf("old tex[y]_start %d\n", (wall->wall_height - SCREEN_HEIGHT) / 2);
	printf("NEW tex[y]_start %d\n", wall->tex[Y]);
	printf("old step %f\n", texture->height / (double)wall->wall_height);
	printf("step: %f\n", wall->step[Y]);

	draw_line_textured(image, wall, texture);
}


int		wall_height_limiter(int wall_height)
{
	if (wall_height > SCREEN_HEIGHT)
		return (SCREEN_HEIGHT);
	return (wall_height);
}
