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
void	open_close_door(t_player *player);
void	cursor_hooks(double xpos, double ypos, void* param);

// - Movement
void	walking(t_all *data);
void	wall_collision(t_player *player, double increment, t_xyz axis);

// -- Options
void	change_fov(t_all *data);
void	zoom_in(t_all *data);
void	bigmap_io_switch(t_bigmap *bigmap);
void	testmode_io_switch(t_gfx_data *graphics);
void	fps_print_ioswitch(t_fps *fps);
void	fps_screen_ioswitch(t_gfx_data *graphics, t_fps *fps);

#endif