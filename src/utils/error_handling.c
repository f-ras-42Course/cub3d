
#include "cub3d.h"

/*a function that exits with a custom exit_code and message
will write to standard error and adds a new_line.*/
void	error(int error_code, t_all *data)
{
	const char	*error_msg[] = {"Succes",
		"invalid map",
		"map too small",
		"no player found",
		"found invalid character while parsing map",
		"this game does not support multiplayer",
		"one or more elements are repeated",
		"not all elements are present",
		"provide correct rgb colors for floor/ceiling (255,255,255)",
		"the file given as argument does not exist",
		"make sure the map ends with '.cub'",
		"no map supplied",
		"texture must be '.png' file",
		"make sure all texture files exist",
		"MLX crashed (GFX); go into debug mode for more info",
		"MLX crashed (HOOKS); go into debug mode for more info"};

	data->error_code = error_code;
	if (!DEBUG)
	{
		write(2, "Error: ", 7);
		ft_putendl_fd((char *)error_msg[error_code], STDERR_FILENO);
	}
	if (error_code >= MLX_GFX_CRASH)
		mlx_terminate(data->graphics.mlx);
}
