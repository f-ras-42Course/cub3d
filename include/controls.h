#ifndef CONTROLS_H
# define CONTROLS_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"
# include "graphics.h"

// -- Hooks

bool	load_hooks(t_all *data);
void	loop_hooks(void *ptr_to_data);
void	key_hooks(mlx_key_data_t keydata, void *ptr_to_data);

// - Movement
void	walking(t_all *data);

#endif