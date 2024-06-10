#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"

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
// Minimap
bool		init_minimap(t_gfx_data *graphics);
void		draw_minimap_frame(mlx_image_t *minimap, t_minimap_options option);
void		draw_minimap_player(mlx_image_t *minimap);
void		draw_minimap_test_frame(mlx_image_t *minimap, \
				t_minimap_options option);
void		fill_minimap_unit(mlx_image_t *minimap, int minimap_pos_x, int minimap_pos_y);


// - Rectangle

mlx_image_t	*rect_image_draw(mlx_t *mlx, \
			const int measures[4], unsigned int color);
void		draw_rect(mlx_image_t *image, \
			const int measures[4], unsigned int color);
mlx_image_t	*rect_image(mlx_t *mlx, int width, int height);

#endif