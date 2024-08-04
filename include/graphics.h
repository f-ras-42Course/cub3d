#ifndef GRAPHICS_H
# define GRAPHICS_H

# ifndef M_PI
#  define M_PI 	3.14159265358979323846
# endif

# define RD		0.01745329251 // = M_PI / 180

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"
# include "test_map.h"
# include "test_graphics.h"
# include <math.h>

// - Graphics 
bool		init_graphics(t_all *data);
void		run_graphics(t_all *data);

// - Images
bool		init_image(t_gfx_data *graphics);
bool		set_all_images_to_window(t_gfx_data *graphics);

// - Layers
bool		init_mainlayer(t_gfx_data *graphics);
bool		init_minimap(t_gfx_data *graphics);
void		init_minimap_values(t_minimap *minimap);
bool		init_bigmap(t_gfx_data *graphics);
void		init_bigmap_values(t_bigmap *bigmap);

// - Raycasting
//-Textured
void		raycasting(t_mainlayer *mainlayer, uint32_t ceiling_color, \
						uint32_t floor_color);
void		place_full_ceiling_textured(mlx_image_t *image, \
										const mlx_texture_t *texture);
void		place_full_floor_textured(mlx_image_t *image, \
									const mlx_texture_t *texture);
void		place_wall_textured(mlx_image_t *image, t_wall_data *wall, \
								const mlx_texture_t *texture);
int			wall_height_limiter(int wall_height);

//-Colored
void		raycasting_colored(t_mainlayer *mainlayer, uint32_t ceiling_color, \
						uint32_t floor_color, uint32_t wall_color[4]);
void		place_full_ceiling_colored(mlx_image_t *image, uint32_t color);
void		place_full_floor_colored(mlx_image_t *image, uint32_t color);
void		place_wall_colored(mlx_image_t *image, int wall_height, \
								int position, uint32_t color);
//-Shared
void		init_ray_variables(const t_player *player, t_ray *ray);
double		ray_distance(t_ray *ray);
void		set_wall_side(t_ray *ray, int side_check);

// - Minimap
void		minimap(t_minimap *minimap);
void		draw_walls_on_minimap(t_minimap *minimap);
void		draw_player_on_minimap(t_minimap *minimap);
void		draw_end_of_map(t_minimap *minimap, int x, int y);
void		fill_minimap_unit(t_minimap *minimap, int minimap_pos_x, \
								int minimap_pos_y, int color);

// - Minimap checks
bool		minimap_unit_is_out_of_map_scope(const t_minimap *minimap);
void		reset_minimap_end_of_map_locator(t_minimap *minimap);

// - Bigmap
void		bigmap(const t_bigmap *bigmap);
void		draw_walls_on_bigmap(const t_bigmap *bigmap);
void		fill_bigmap_unit(const t_bigmap *bigmap, int bigmap_pos_x, \
								int bigmap_pos_y, int color);
bool		is_wall_for_bigmap(const t_bigmap *bigmap);
void		draw_player_on_bigmap(const t_bigmap *bigmap, int color);
void		bigmap_io_switch(t_bigmap *bigmap);

// - Bigmap ray drawing

void		bigmap_draw_ray_lines(const t_bigmap *bigmap, int color);
void		draw_single_ray_line(const t_bigmap *bigmap, t_ray *ray, \
									double bigmap_position[2], int color);
void		init_ray_line_variables(const t_player *player, t_ray *ray);
int			calculate_line_size(const t_bigmap *bigmap, t_ray *ray);
bool		wall_found(int x, int y);

// - Rectangle

mlx_image_t	*rect_image_draw(mlx_t *mlx, \
								const int measures[4], unsigned int color);
void		draw_rect(mlx_image_t *image, \
						const int measures[4], unsigned int color);

// - Circle

void		draw_circle(mlx_image_t *image, \
							const int measures[3], unsigned int color);
void		draw_filled_circle(mlx_image_t *image, \
								const int measures[3], unsigned int color);

// - Line

void		draw_line_textured(mlx_image_t *image, t_wall_data *wall, \
								const mlx_texture_t *texture);

// - RGBA

int			get_rgba(int r, int g, int b, int a);
uint32_t	get_color_from_pixel_data(int x, int y, \
										const mlx_texture_t *texture);

// - Rendering

void		update_image(t_gfx_data *graphics);

#endif