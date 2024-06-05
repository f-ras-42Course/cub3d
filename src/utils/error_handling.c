
#include "cub3d.h"

static const char	*g_error_msg[] = {
	"Succes",
	// PARSE
	"make sure the map ends with '.cub'",
	"no map supplied",
	// GFX
};

/*a function that exits with a custom exit_code and message
will write to standard error and adds a new_line.*/
void	error(int error_code, t_data *all)
{
	all->error_code = error_code;
	write(2, "Error: ", 7);
	ft_putendl_fd((char *)g_error_msg[error_code], STDERR_FILENO);
}
