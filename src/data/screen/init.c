
#include "data.h"

void		init_default_resolution(void)
{
	set_resolution(DEFAULT_RESOLUTION);
	cub3d_float_int_printer(STDOUT_FILENO, "Default Screen Resolution: %d x %d"\
							"\n", screen_width(), screen_height());
}
