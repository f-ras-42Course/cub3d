
#include "utils.h"

/*a function that exits with a custom exit_code and message
will write to standard error and adds a new_line.*/
void	error(char *error_message, int exit_code)
{
	write(2, "Error: ", 7);
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(exit_code);
}
