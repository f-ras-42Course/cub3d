
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
		if (keydata.key == MLX_KEY_V)
			change_fov(data);
	}
}
