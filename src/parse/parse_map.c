
#include "cub3d.h"

/*might turn into void function since we can use exit*/
/*if not too complicated let's try to restrain from using exit and return from main instead.
also let's use bool for boolean returns*/
bool	parse_map(t_all *data, char *map_name)
{
	(void)data;
	if (!map_name)
		return (error(NO_MAP, data), false);
	return (true);
}
