
#include "data.h"
#include "test_map.h"

void	set_data(t_all *data)
{
	set_start_position_player(data);
	set_start_direction_player(data);
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
	set_position(x, y, data->player.position);
}

void	set_start_direction_player(t_all *data)
{
	if (get_player_type(data) == 'E')
	{
		data->player.direction[X] = 0 * M_PI;
		data->player.direction[Y] = 0 * M_PI;
	}
	else if (get_player_type(data) == 'S')
	{
		data->player.direction[X] = 0.5 * M_PI;
		data->player.direction[Y] = 0.5 * M_PI;
	}
	else if (get_player_type(data) == 'W')
	{
		data->player.direction[X] = 1 * M_PI;
		data->player.direction[Y] = 1 * M_PI;
	}
	else if (get_player_type(data) == 'N')
	{
		data->player.direction[X] = 1.5 * M_PI;
		data->player.direction[Y] = 1.5 * M_PI;
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
