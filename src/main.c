
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	data;

	if (!parse_map(&data, argc, argv[1]))
		return (data.error_code);
	free_double_pointer(data.map.map);
	// if (!set_data(&data))
	// {
	// 	free_cub_data(&data.map);
	// 	return (data.error_code);
	// }
	// if (!init_graphics(&data))
	// {
	// 	free_cub_data(&data.map);
	// 	return (data.error_code);
	// }
	// if (!load_hooks(&data))
	// {
	// 	free_cub_data(&data.map);
	// 	return (data.error_code);
	// }
	// run_graphics(&data);
	// free_cub_data(&data.map);
	return (SUCCES);
}
