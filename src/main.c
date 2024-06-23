
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	data;

	if (parse_map(&data, argc, argv[1]))
		return (data.error_code);
	set_data(&data);
	if (!init_graphics(&data))
		return (data.error_code);
	if (!load_hooks(&data))
		return (data.error_code);
	run_graphics(&data);
	return (SUCCES);
}
