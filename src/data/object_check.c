
#include "data.h"

bool	wall_found(int x, int y)
{
	char **map;

	map = map_data(GET);
	return(map[y][x] == '1');
}

bool	closed_door_found(int x, int y)
{
	char **map;

	map = map_data(GET);
	return(map[y][x] == 'D');
}

bool	open_door_found(int x, int y)
{
	char **map;

	map = map_data(GET);
	return(map[y][x] == 'O');
}
