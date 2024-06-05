
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	data;

	(void)argv;
	(void)argc;
/* 	if (!parse_map(&data, argv[1]))
		return (data.error_code); */
	if (!init_graphics(&data))
		return (data.error_code);
	run_graphics(&data);
	return (SUCCES);
}
