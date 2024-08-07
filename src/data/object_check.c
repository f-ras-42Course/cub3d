#include "data.h"

bool	wall_found(int x, int y)
{
	return(g_temp_test_map[y][x] == '1');
}

bool	closed_door_found(int x, int y)
{
	return(g_temp_test_map[y][x] == 'D');
}

bool	open_door_found(int x, int y)
{
	return(g_temp_test_map[y][x] == 'O');
}
