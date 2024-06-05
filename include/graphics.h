#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"


// - Graphics 
bool		init_graphics(t_all *data);
void		run_graphics(t_all *data);


// - Images
bool		init_image(t_gfx_data graphics);
bool		init_background(t_gfx_data graphics);
bool		init_minimap(t_gfx_data graphics);
mlx_image_t	*draw_rect(mlx_t *mlx, int width, int height, unsigned int color);


#endif