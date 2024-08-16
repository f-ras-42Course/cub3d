
#include "controls.h"

bool	load_hooks(t_all *data)
{
	mlx_key_hook(data->graphics.mlx, key_hooks, data);
	if (!mlx_loop_hook(data->graphics.mlx, loop_hooks, data))
		return(error(MLX_HOOKS_CRASH, data), false);
	mlx_cursor_hook(data->graphics.mlx, cursor_hooks, data);
	return (true);
}

void	loop_hooks(void *ptr_to_data)
{
	t_all	*data;

	data = ptr_to_data;
	update_fps(&(data->fps));
	walking(data);
	update_image(&(data->graphics));
	fps_printer(&(data->fps));
	fps_to_screen(&(data->graphics), &(data->fps));
}

void	key_hooks(mlx_key_data_t keydata, void *ptr_to_data)
{
	t_all	*data;

	data = ptr_to_data;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			mlx_close_window(data->graphics.mlx);
		if (keydata.key == MLX_KEY_F)
		{
			fps_print_ioswitch(&(data->fps));
			fps_screen_ioswitch(&(data->graphics), &(data->fps));
		}
		if (keydata.key == MLX_KEY_V && keydata.key != MLX_KEY_Z)
			change_fov(data);
		if (keydata.key == MLX_KEY_Z)
			zoom_in(data);
		if (keydata.key == MLX_KEY_M)
			bigmap_io_switch(&(data->graphics.bigmap));
		if (keydata.key == MLX_KEY_T)
			testmode_io_switch(&(data->graphics));
		if (keydata.key == MLX_KEY_SPACE)
			open_close_door(&(data->player));
		if (keydata.key == MLX_KEY_MINUS)
			decrease_resolution(&(data->graphics));
		if (keydata.key == MLX_KEY_EQUAL)
			increase_resolution(&(data->graphics));
	}
}

void	open_close_door(t_player *player)
{
	const double	distance_to_wall[2] = {
	[X] = copysign(0.5, cos(player->direction)),
	[Y] = copysign(0.5, sin(player->direction)),
	};

	if (closed_door_found(player->position[X] + distance_to_wall[X], player->position[Y]))
		g_temp_test_map[(int)player->position[Y]][(int)(player->position[X] + distance_to_wall[X])] = 'O';
	else if (closed_door_found(player->position[X], player->position[Y] + distance_to_wall[Y]))
		g_temp_test_map[(int)(player->position[Y] + distance_to_wall[Y])][(int)player->position[X]] = 'O';
	else if (open_door_found(player->position[X] + distance_to_wall[X], player->position[Y]))
		g_temp_test_map[(int)player->position[Y]][(int)(player->position[X] + distance_to_wall[X])] = 'D';
	else if (open_door_found(player->position[X], player->position[Y] + distance_to_wall[Y]))
		g_temp_test_map[(int)(player->position[Y] + distance_to_wall[Y])][(int)player->position[X]] = 'D';
}

void	cursor_hooks(double xpos, double ypos, void *ptr_to_data)
{
	t_all		*data;
	double		rot_speed;
	const int	screen_mid[2] = {
	[X] = screen_width() / 2,
	[Y] = screen_height() / 2
	};

	data = ptr_to_data;
	rot_speed = (data->fps.time - data->fps.old_time) * 0.5;
	if (xpos < screen_mid[X])
	{
		data->player.direction = (data->player.direction / M_PI - (rot_speed \
		* (screen_mid[X] - xpos))) * M_PI;
		if (copysign(1, data->player.direction / M_PI) == -1)
			data->player.direction = 2 * M_PI;
	}
	if (xpos > screen_mid[X])
	{
		data->player.direction = (data->player.direction / M_PI + (rot_speed \
		* (xpos - screen_mid[X]))) * M_PI;
		if ((int)(data->player.direction / M_PI) == 2)
			data->player.direction = 0 * M_PI;
	}
	mlx_set_mouse_pos(data->graphics.mlx, screen_mid[X], screen_mid[Y]);
}
