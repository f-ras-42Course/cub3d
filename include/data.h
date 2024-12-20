/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 18:13:48 by fras          #+#    #+#                 */
/*   Updated: 2024/11/11 19:18:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "MLX42/MLX42.h"
# include "definitions.h"
# include "structures.h"
# include "utils.h"
# include "graphics.h"

// -- Collect
bool			set_data(t_all *data);
void			set_start_position_player(t_all *data);
void			set_start_direction_player(t_all *data);
char			get_player_type(t_all *data);

// -- Free
void			free_data(t_all *data);
void			free_cub_data(t_map *cub);
void			delete_loaded_textures(t_textures *textures);

// -- Cub
void			make_cub_data_widely_available(t_map *cub);
char			**map_data(t_mapaccess option, ...);
size_t			map_height(t_mapaccess option, ...);
size_t			map_width(t_mapaccess option, ...);

// -- Print
void			test_print_map(char **map);

// -- Textures
bool			init_texture_data(t_all *data);
bool			is_all_png_files(const t_map *map);
void			all_textures_to_null(t_textures *textures);
bool			set_all_textures(t_textures *textures, const t_map *map);
bool			ends_with_png(const char *str);

// -- Utils
void			set_position(double x, double y, double where[2]);

// -- FPS
void			fps_printer(t_fps *fps);
void			update_fps(t_fps *fps);

// -- FOV
void			set_player_field_of_view(t_all *data);

// -- Object Collision
bool			wall_found(int x, int y);
bool			closed_door_found(int x, int y);
bool			open_door_found(int x, int y);
void			close_door(int x, int y);
void			open_door(int x, int y);

// -- Screen Resolutions
void			init_default_resolution(void);
int				screen_width(void);
int				screen_height(void);
t_resolutions	set_resolution(t_resolutions set);
void			decrease_resolution(t_gfx_data *graphics);
void			increase_resolution(t_gfx_data *graphics);
bool			is_within_monitor_limit(void);
void			keep_within_monitor_limit(t_resolutions current);

#endif