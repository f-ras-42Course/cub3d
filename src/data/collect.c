
#include "data.h"
#include "test_map.h"

void	set_data(t_all *data)
{
	set_start_position_player(data);
}

void	set_start_position_player(t_all *data)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (y < MAP_HEIGHT && !player_found(g_temp_test_map[y][x]))
	{
		x = 0;
		y++;
		while (x < MAP_WIDTH && !player_found(g_temp_test_map[y][x]))
		{
			x++;
		}
	}
	set_position(x + .5, y + .5, data->player.position);
}

bool	player_found(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}
