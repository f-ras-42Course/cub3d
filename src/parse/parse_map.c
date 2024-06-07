
#include "cub3d.h"

/*might turn into void function since we can use exit*/
/*if not too complicated let's try to restrain from using exit and return from main instead.
also let's use bool for boolean returns*/
bool	parse_map(t_all *data,  int argc, char *map_name)
{
	char	*line;

	if (argc == 1)
		return (error(NO_MAP, data), true);
	else if (ft_strcmp(".cub", ft_strnstr(map_name, ".cub", ft_strlen(map_name))))
		return (error(NO_DOT_CUB, data), true);
	return (false);
}
