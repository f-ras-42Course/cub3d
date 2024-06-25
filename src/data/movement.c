
#include "data.h"

bool	load_hooks(t_all *data)
{
	if (!mlx_loop_hook(data->graphics.mlx, loop_hooks, data))
		return(error(MLX_HOOKS_CRASH, data), false);
	return (true);
}

void	loop_hooks(void *ptr_to_data)
{
	t_all	*data;

	data = ptr_to_data;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_ESCAPE) \
		|| mlx_is_key_down(data->graphics.mlx, MLX_KEY_Q))
		mlx_close_window(data->graphics.mlx);
	walking(data);
	update_image(&(data->graphics));
}

void	walking(t_all *data)
{
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_W))
		data->player.position[Y] -= 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_S))
		data->player.position[Y] += 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_A))
		data->player.position[X] -= 0.03;
	if (mlx_is_key_down(data->graphics.mlx, MLX_KEY_D))
		data->player.position[X] += 0.03;
}

void	update_image(t_gfx_data *graphics)
{
	reset_minimap_end_of_map_locator(&(graphics->minimap));
	draw_walls_on_minimap(&(graphics->minimap));
	draw_player_on_minimap(&(graphics->minimap));
	draw_walls_on_bigmap(&(graphics->bigmap));
	draw_bigmap_raster((graphics->bigmap));
	draw_player_on_bigmap(&(graphics->bigmap));
	draw_line(&(graphics->bigmap));
}
