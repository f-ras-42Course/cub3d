
#include "cub3d.h"

static const char	*g_error_msg[] = {
	"Succes",
	// PARSE
	"make sure the map ends with '.cub'",
	"no map supplied",
	// GFX
	"MLX crashed; go into debug mode for more info",
};

/*a function that exits with a custom exit_code and message
will write to standard error and adds a new_line.*/
void	error(int error_code, t_all *data)
{
	data->error_code = error_code;
	if (!DEBUG)
	{
		write(2, "Error: ", 7);
		ft_putendl_fd((char *)g_error_msg[error_code], STDERR_FILENO);
	}
	if (error_code == MLX_CRASH)
		mlx_terminate(data->graphics.mlx);
}
