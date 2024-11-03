
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	data;

	if (!parse_map(&data, argc, argv[1]))
		return (data.error_code);
	if (!set_data(&data))
	{
		free_cub_data(&data.map);
		return (data.error_code);
	}
	if (!init_graphics(&data))
	{
		free_cub_data(&data.map);
		return (data.error_code);
	}
	if (!load_hooks(&data))
	{
		free_cub_data(&data.map);
		return (data.error_code);
	}
	test_print_map(map_data(GET));
	run_graphics(&data);
	free_cub_data(&data.map);
	return (SUCCES);
}
