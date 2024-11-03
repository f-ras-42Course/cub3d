
#include "data.h"

void	close_door(int x, int y)
{
	map_data(CHANGE_ELEMENT, x, y, 'D');
}

void	open_door(int x, int y)
{
	map_data(CHANGE_ELEMENT, x, y, 'O');
}
