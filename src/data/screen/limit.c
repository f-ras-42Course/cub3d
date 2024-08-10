
#include "data.h"

bool	is_within_monitor_limit(void)
{
	int	monitor[2];

	mlx_get_monitor_size(0, &monitor[X], &monitor[Y]);
	return (screen_width() < monitor[X] || screen_height() < monitor[X]);
}

void	keep_within_monitor_limit(t_resolutions current)
{
	int	monitor[2];

	mlx_get_monitor_size(0, &monitor[X], &monitor[Y]);
	if (screen_width() > monitor[X] || screen_height() > monitor[X])
	{
		cub3d_float_int_printer(STDOUT_FILENO, "Set Screen Resolution '%d x %d"\
			"' is larger than monitor support (%d x %d)\n", screen_width(),\
			screen_height(), monitor[X], monitor[Y]);
		while (set_resolution(--current) != 0 &&
				(screen_width() > monitor[X] || screen_height() > monitor[X]));
	}
}
