
#include "cub3d.h"

int	main(int ac, char **argv)
{
	t_data	data;
	(void)ac;
	if (!parse_map(&data, argv[1]))
		return (data.error_code);
	return (SUCCES);
}
