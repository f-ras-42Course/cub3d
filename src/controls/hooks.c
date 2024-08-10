
#include "controls.h"

bool	load_hooks(t_all *data)
{
	mlx_key_hook(data->graphics.mlx, key_hooks, data);
	if (!mlx_loop_hook(data->graphics.mlx, loop_hooks, data))
		return(error(MLX_HOOKS_CRASH, data), false);
	return (true);
}

void	loop_hooks(void *ptr_to_data)
{
	t_all	*data;

	data = ptr_to_data;
	walking(data);
	update_image(&(data->graphics));
	show_fps(0);
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
			show_fps(true);
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
