
#include "cub3d.h"

int	main(int ac, char **argv)
{
	t_data	data;
	(void)ac;
	parse_map(&data, argv[1]);
	return (0);
}
