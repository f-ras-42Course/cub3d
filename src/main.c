
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	if (parse_map(&data, argc, argv[1]))
		return (data.error_code);
	return (SUCCES);
}
