
#include "graphics.h"


void	single_raycasting_textured(t_mainlayer *mainlayer, 
					uint32_t ceiling_color, uint32_t floor_color)
{
	t_ray				ray;
	uint32_t 			wall_height;
	double				perp_distance;
	const t_player		*player = mainlayer->player;
	const mlx_texture_t	*wall_texture[4] = {
	[N] = mainlayer->textures.north_texture,
	[E] = mainlayer->textures.east_texture,
	[S]	= mainlayer->textures.south_texture,
	[W] = mainlayer->textures.west_texture};

	double				wallX;
	int 				tex[2];
	double 				step;

	(void)wall_texture;
	ray.direction = mainlayer->player->direction;
	init_ray_variables(mainlayer->player, &ray);
	perp_distance = ray_distance(&ray) \
					* cos(ray.direction - player->direction);

	if (ray.side == 'S' || ray.side == 'N')
		wallX = player->position[Y] + perp_distance * sin(player->direction);
	else
		wallX = player->position[X] + perp_distance * cos(player->direction);
	
	wallX -= floor(wallX);
	tex[X] = wallX * 1024;
	printf("WallX = %f - texX = %d\n", wallX, tex[X]);
	wall_height = (uint32_t)SCREEN_HEIGHT / perp_distance;
	step = 1024 / (double)wall_height;
	printf("perp: %f, wall_height = %d\n", perp_distance, wall_height);
	// printf("tex[Y]: %d\n", tex[Y]);
	printf("step: %f\n", step);
	printf("JAJA: %d\n", SCREEN_HEIGHT / 2 - wall_height / 2);
	if (wall_height > SCREEN_HEIGHT)
		wall_height = SCREEN_HEIGHT;
	single_place_ceiling(mainlayer->image, wall_height, 0, ceiling_color);
	single_place_wall_texture(mainlayer->image, wall_height, 0, tex, wall_texture[ray.side]);
	single_place_floor(mainlayer->image, wall_height, 0, floor_color);

}

void	single_raycasting(t_mainlayer *mainlayer, \
					uint32_t ceiling_color, uint32_t floor_color)
{
	t_ray			ray;
	uint32_t 		wall_height;
	double			perp_distance;
	const t_player	*player = mainlayer->player;

	ray.direction = mainlayer->player->direction;
	init_ray_variables(mainlayer->player, &ray);
	perp_distance = ray_distance(&ray) \
					* cos(ray.direction - player->direction);
	wall_height = (uint32_t)SCREEN_HEIGHT / perp_distance;
	if (wall_height > SCREEN_HEIGHT)
		wall_height = SCREEN_HEIGHT;
	single_place_ceiling(mainlayer->image, wall_height, 0, ceiling_color);
	single_place_wall(mainlayer->image, wall_height, 0, 0x00ff00ff);
	single_place_floor(mainlayer->image, wall_height, 0, floor_color);
}

void	single_place_ceiling(mlx_image_t *image, int wall_height, int position, \
						uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = 0
	};

	draw_rect(image, measures, color);
}

void	single_place_wall(mlx_image_t *image, int wall_height, int position, \
					uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = wall_height,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] = SCREEN_HEIGHT / 2 - wall_height / 2
	};

	draw_rect(image, measures, color);
}

void	single_place_wall_texture(mlx_image_t *image, int wall_height, int position, int tex[2],\
						const mlx_texture_t* texture)
{
// 	const int	measures[4] = {
// 	[RECT_WIDTH] = SCREEN_WIDTH,
// 	[RECT_HEIGHT] = wall_height,
// 	[DRAW_POS_X] = position,
// 	[DRAW_POS_Y] = SCREEN_HEIGHT / 2 - wall_height / 2
// 	};

// 	draw_line_textured(image, measures, tex[X], tex[Y], texture);
}


void	single_place_floor(mlx_image_t *image, int wall_height, int position, \
					uint32_t color)
{
	const int	measures[4] = {
	[RECT_WIDTH] = SCREEN_WIDTH,
	[RECT_HEIGHT] = SCREEN_HEIGHT / 2 - wall_height / 2,
	[DRAW_POS_X] = position,
	[DRAW_POS_Y] =  SCREEN_HEIGHT - (SCREEN_HEIGHT / 2 - wall_height / 2)
	};

	draw_rect(image, measures, color);
}
