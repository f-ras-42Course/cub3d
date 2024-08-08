
#include "data.h"
#include "test_map.h"

bool	set_data(t_all *data)
{
	set_start_position_player(data);
	set_start_direction_player(data);
	set_player_field_of_view(data);
	set_resolution(DEFAULT_RESOLUTION);
	return (init_texture_data(data));
}

void	set_start_position_player(t_all *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MAP_HEIGHT && !player_found(g_temp_test_map[y][x]))
	{
		while (x < MAP_WIDTH && !player_found(g_temp_test_map[y][x]))
		{
			x++;
		}
		if (player_found(g_temp_test_map[y][x]))
			break ;
		x = 0;
		y++;
	}
	set_position(x + 0.5, y + 0.5, data->player.position);
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
	return (g_temp_test_map[(int)data->player.position[Y]][(int)data->player.position[X]]);
}

void 	set_player_field_of_view(t_all *data)
{
	data->player.fov = DEFAULT_FOV;

	cub3d_float_int_printer(STDOUT_FILENO, "Default FOV: %d\n", (int)data->player.fov);
}
