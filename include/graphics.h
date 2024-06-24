#ifndef GRAPHICS_H
# define GRAPHICS_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"
# include "test_map.h"
# include <math.h>

// #include <stdio.h>


// - Graphics 
bool		init_graphics(t_all *data);
void		run_graphics(t_all *data);

// - Images
bool		init_image(t_gfx_data *graphics);
bool		set_all_images_to_window(t_gfx_data *graphics);

// - Layers
bool		init_background(t_gfx_data *graphics);
void		draw_floor(mlx_image_t *image);
void		draw_sky(mlx_image_t *image);

// - Minimap
bool		init_minimap(t_gfx_data *graphics);
void		init_minimap_values(t_minimap *minimap);
void		draw_minimap_frame(t_minimap minimap, t_minimap_options option);
void		draw_walls_on_minimap(t_minimap *minimap);
void		draw_player_on_minimap(t_minimap *minimap);
void		draw_end_of_map(t_minimap *minimap, int x, int y);
void		fill_minimap_unit(t_minimap *minimap, int minimap_pos_x, \
			int minimap_pos_y, int color);
bool		is_minimap_unit_out_of_map_scope(const t_minimap *minimap);
bool		wall_found(int x, int y);
void		reset_minimap_end_of_map_locator(t_minimap *minimap);


// - Bigmap

bool		init_bigmap(t_gfx_data *graphics);
void		init_bigmap_values(t_bigmap *bigmap);
void		draw_walls_on_bigmap(t_bigmap *bigmap);
void		draw_bigmap_raster(t_bigmap bigmap);
void		fill_bigmap_unit(t_bigmap *bigmap, int bigmap_pos_x, \
			int bigmap_pos_y, int color);
bool		is_wall_for_bigmap(const t_bigmap *bigmap);
void		draw_player_on_bigmap(t_bigmap *bigmap);


// - Rectangle

mlx_image_t	*rect_image_draw(mlx_t *mlx, \
			const int measures[4], unsigned int color);
void		draw_rect(mlx_image_t *image, \
				const int measures[4], unsigned int color);

// - Circle

void	draw_circle(mlx_image_t *image, \
					const int measures[3], unsigned int color);
void	draw_filled_circle(mlx_image_t *image, \
					const int measures[3], unsigned int color);

#endif