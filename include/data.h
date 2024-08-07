#ifndef DATA_H
# define DATA_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"
# include "graphics.h"


// -- Collect
bool	set_data(t_all *data);
void	set_start_position_player(t_all *data);
void	set_start_direction_player(t_all *data);
bool	player_found(char c);
char	get_player_type(t_all *data);

// -- Textures

bool	init_texture_data(t_all *data);
bool	is_all_png_files(const t_map *map);
void	all_textures_to_null(t_textures *textures);
bool	set_all_textures(t_textures *textures, const t_map *map);
bool	ends_with_png(const char *str);

// -- Utils
void	set_position(double x, double y, double where[2]);

// -- FPS
void	show_fps(bool key_pressed);

// -- FOV
void 	set_player_field_of_view(t_all *data);

// -- Object Collision
bool	wall_found(int x, int y);
bool	closed_door_found(int x, int y);
bool	open_door_found(int x, int y);

#endif