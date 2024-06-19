#ifndef DATA_H
# define DATA_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"


// -- Collect
void	set_data(t_all *data);
void	set_start_position_player(t_all *data);
bool	player_found(char c);

// -- Utils
void	set_position(int x, int y, double where[2]);

#endif