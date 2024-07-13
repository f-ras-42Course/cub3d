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
void	set_start_direction_player(t_all *data);
bool	player_found(char c);
char	get_player_type(t_all *data);

// -- Utils
void	set_position(double x, double y, double where[2]);

// -- FPS
void	show_fps(bool key_pressed);

// -- FOV
void 	set_player_field_of_view(t_all *data);
void	change_fov(t_all *data);

#endif