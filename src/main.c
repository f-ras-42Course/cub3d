
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	data;

	(void)argv;
	(void)argc;
/* 	if (!parse_map(&data, argv[1]))
		return (data.error_code); */
	data.graphics.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d", true);
	if (!data.graphics.mlx)
		return (data.error_code);
	return (SUCCES);
}
