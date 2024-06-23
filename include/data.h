#ifndef DATA_H
# define DATA_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"
# include "graphics.h"


// -- Collect
void	set_data(t_all *data);
void	set_start_position_player(t_all *data);
bool	player_found(char c);

// -- Utils
void	set_position(double x, double y, double where[2]);

// -- Movement

bool	load_hooks(t_all *data);
void	loop_hooks(void *ptr_to_data);
void	walking(t_all *data);

#endif