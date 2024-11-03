
#include "data.h"

bool	set_data(t_all *data)
{
	set_start_position_player(data);
	set_start_direction_player(data);
	set_player_field_of_view(data);
	init_default_resolution();
	data->fps.printing_enabled = false;
	data->fps.on_screen_enabled = false;
	make_cub_data_widely_available(&(data->map));
	return (init_texture_data(data));
}

void	set_start_position_player(t_all *data)
{
	set_position(data->map.player_location[X] + 0.5, \
	data->map.player_location[Y] + 0.5, \
	data->player.position);
}

void	set_start_direction_player(t_all *data)
{
	if (get_player_type(data) == 'E')
	{
		data->player.direction = 0 * M_PI;
	}
	else if (get_player_type(data) == 'S')
	{
		data->player.direction = 0.5 * M_PI;
	}
	else if (get_player_type(data) == 'W')
	{
		data->player.direction = 1 * M_PI;
	}
	else if (get_player_type(data) == 'N')
	{
		data->player.direction = 1.5 * M_PI;
	}
}

bool	player_found(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

char	get_player_type(t_all *data)
{
	return (data->map.map[data->map.player_location[Y]][data->map.player_location[X]]);
}

void 	set_player_field_of_view(t_all *data)
{
	data->player.fov = DEFAULT_FOV;

	cub3d_float_int_printer(STDOUT_FILENO, "Default FOV: %d\n", (int)data->player.fov);
}
